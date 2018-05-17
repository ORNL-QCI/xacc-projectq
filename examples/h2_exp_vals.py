import numpy as np
import pyxacc as xacc
import StringIO, sys
from projectq import MainEngine
from projectq.backends import CommandPrinter, Simulator
from projectq.ops import (H,
                          X,
                          Y,
                          Z,
                          Rx,
                          Ry,
                          Rz,
                          Measure,
                          CNOT, 
                          QubitOperator)

""" I wasn't too sure how to make the CommandPrinter 
    print to a string by default, so here I'm making 
    my own to override the __print_cmd method.
"""
class XaccCommandPrinter(CommandPrinter):
    def __init__(self, outStrIO, accept_input=True, default_measure=False,
                 in_place=False):
        CommandPrinter.__init__(self)
        self.outStrIO = outStrIO

    def _print_cmd(self, cmd):
        if self.is_last_engine and cmd.gate == Measure:
            assert(get_control_count(cmd) == 0)
            self.outStrIO.write(str(cmd)+'\n') #print(cmd)
            for qureg in cmd.qubits:
                for qubit in qureg:
                    if self._accept_input:
                        m = None
                        while m != '0' and m != '1' and m != 1 and m != 0:
                            prompt = ("Input measurement result (0 or 1) for"
                                      " qubit " + str(qubit) + ": ")
                            m = input(prompt)
                    else:
                        m = self._default_measure
                    m = int(m)
                    self.main_engine.set_measurement_result(qubit, m)
        else:
            if self._in_place:
                self.outStrIO.write("\0\r\t\x1b[K" + str(cmd) + "\r\n")
            else:
                self.outStrIO.write(str(cmd)+'\n') #print(cmd)

""" Convenience function for taking ProjectQ QASM
    and generating an XACC kernel for the 
    TNQVM Accelerator
"""
def getXACCKernel(projectq_qasm, tnqvm):
   qasmKernel = '__qpu__ foo() {\n' + projectq_qasm + '\n}'
   program = xacc.Program(tnqvm, qasmKernel)
   program.build()
   return program.getKernel('foo')

""" State Preparation circuit from 'Scalable Quantum 
    Simulation of Molecular Energies' arxiv 1512.06860
"""
def initializeState(qreg, theta):
   Rx(np.pi) | qreg[0]
   Ry(np.pi / 2.0) | qreg[1]
   Rx(2.5*np.pi) | qreg[0]
   CNOT | (qreg[1], qreg[0])
   Rz(theta) | qreg[0]
   CNOT | (qreg[1], qreg[0])
   Ry(2.5*np.pi) | qreg[1]
   Rx(np.pi/2) | qreg[0]

""" Circuit generation for Z0 term of H2 Hamiltonian
"""
def Z0Term(qreg, theta):
   initializeState(qreg, theta)
   return QubitOperator('Z0')

""" Main - the goal here is to use ProjectQ C++ simulator to 
    compute the expectation value for the Z0 term of the H2 
    Hamiltonian, and compare it with our tensor network 
    simulator, TNQVM 
"""
def main(argv=None):

   # Store results to this CSV file
   file = open('projectq_out.csv', 'w')
   file.write('theta, Z0_pq, Z0_tnqvm\n') #, Z1, Z0Z1\n')

   # Initialize XACC
   xacc.Initialize()
   
   # Indicate that we want to use the ProjectQ QASM 
   # Compiler/Transpiler
   xacc.setOption('compiler', 'projectq-qasm')
   
   # Get reference to the TNQVM Accelerator
   tnqvm = xacc.getAccelerator('tnqvm')
   
   # Allocate and AcceleratorBuffer
   xacc_qbits = tnqvm.createBuffer('qreg', 2)

   # Loop over H2 state prep variational parameters
   for theta in np.linspace(-np.pi, np.pi, 100):

      # Create a ProjectQ Engine with our CommandPrinter
      output = StringIO.StringIO()
      eng = MainEngine(Simulator(), [XaccCommandPrinter(output)])

      # Allocate some ProjectQ qubits
      qreg = eng.allocate_qureg(2)

      # Run Init State Circuit and Generate the Z0 QubitOperator
      op = Z0Term(qreg, theta)
      eng.flush()
      
      # Get Expectation Value of Z0 operator
      e_pq = eng.backend.get_expectation_value(op, qreg)
      Measure | qreg[0]

      # Get the ProjectQ QASM
      qasm = output.getvalue()
      
      # Generate an XACC Kernel
      xaccKernel = getXACCKernel(qasm, tnqvm)
   
      # Execute, no params since theta has
      # already been input to Z0Term function
      xaccKernel.execute(xacc_qbits, [])
      
      # Get the expectation value
      e_tnqvm = xacc_qbits.getExpectationValueZ()
      
      # Reset the qubits for the next iteration
      xacc_qbits.resetBuffer()
    
      # Store the results to a CSV file
      file.write(str(theta) + ', ' + str(e_pq) + ', ' + str(e_tnqvm) + '\n')
      file.flush()
   
   file.close()

   # Finalize the framework
   xacc.Finalize()

if __name__ == "__main__":
   sys.exit(main())   
