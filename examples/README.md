# Simple Demonstration of comparing ProjectQ Simulator with XACC TNQVM

Here we provide a simple demonstration of a python code that integrates ProjectQ and XACC, 
in an effort to compare the simulator from ProjectQ with the tensor network simulator 
from TNQVM and XACC. 

In order to build and try this out, you will need to install XACC. To do so, check out 
[XACC Install](http://xacc.readthedocs.io/en/latest/install.html). 

Following the directions in this install link should give you an ``xacc-install-plugins.py`` 
that is now in your path. Run the following to install ProjectQ, TNQVM, xacc-python, and xacc-projectq (note that 
for TNQVM you must have blas-devel and lapack-devel installed on your system, see 
[TNQVM Install](http://xacc.readthedocs.io/en/latest/tnqvm.html)):

```bash
$ python -m pip install --user projectq
$ xacc-install-plugins.py -p xacc-python tnqvm xacc-projectq
```

Now you have the XACC Python bindings, the TNQVM Accelerator, and the XACC ProjectQ Qasm Compiler. 

Now just run the example

```bash
$ python h2_exp_vals.py
```
This should produce a projectq_out.csv file containing expectation values 
for the Z0 operator of the H2 hamiltonian (see https://arxiv.org/pdf/1512.06860.pdf) for both the 
ProjectQ simulator and TNQVM at theta between -pi and pi.
