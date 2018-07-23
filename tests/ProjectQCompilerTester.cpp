/***********************************************************************************
 * Copyright (c) 2016, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include <gtest/gtest.h>
#include "ProjectQCompiler.hpp"
#include "GateIR.hpp"
#include "CountGatesOfTypeVisitor.hpp"

using namespace xacc;

using namespace xacc::quantum;

TEST(ProjectQCompilerTester, checkTeleportProjectQ) {

	const std::string src = R"src(__qpu__ testF(AcceleratorBuffer ab) {
Allocate | Qureg[0]
Allocate | Qureg[1]
Allocate | Qureg[2]
Allocate | Qureg[3]
X | Qureg[0]
X | Qureg[1]
Rx(1.57079632679) | Qureg[1]
H | Qureg[3]
CX | ( Qureg[1], Qureg[2] )
CX | ( Qureg[2], Qureg[3] )
Rz(12.5663706063) | Qureg[3]
CX | ( Qureg[2], Qureg[3] )
CX | ( Qureg[1], Qureg[2] )
H | Qureg[3]
Rx(10.9955742876) | Qureg[1]
Rx(1.57079632679) | Qureg[0]
H | Qureg[1]
Rx(1.57079632679) | Qureg[2]
Rx(1.57079632679) | Qureg[3]
CX | ( Qureg[0], Qureg[1] )
CX | ( Qureg[1], Qureg[2] )
CX | ( Qureg[2], Qureg[3] )
Rz(12.5381035855) | Qureg[3]
CX | ( Qureg[2], Qureg[3] )
CX | ( Qureg[1], Qureg[2] )
CX | ( Qureg[0], Qureg[1] )
Rx(10.9955742876) | Qureg[3]
Rx(10.9955742876) | Qureg[2]
H | Qureg[1]
Rx(10.9955742876) | Qureg[0]
H | Qureg[0]
H | Qureg[1]
Rx(1.57079632679) | Qureg[2]
})src";
	// Measure | Qureg[0-3]


	auto compiler = std::make_shared<ProjectQCompiler>();
	auto ir = compiler->compile(src);
	auto qir = std::dynamic_pointer_cast<GateIR>(ir);

	std::cout << qir->getKernels()[0]->toString("qreg") << "\n";

	const std::string expected = R"expected(X qreg0
X qreg1
Rx(1.5708) qreg1
H qreg3
CNOT qreg1,qreg2
CNOT qreg2,qreg3
Rz(12.5664) qreg3
CNOT qreg2,qreg3
CNOT qreg1,qreg2
H qreg3
Rx(10.9956) qreg1
Rx(1.5708) qreg0
H qreg1
Rx(1.5708) qreg2
Rx(1.5708) qreg3
CNOT qreg0,qreg1
CNOT qreg1,qreg2
CNOT qreg2,qreg3
Rz(12.5381) qreg3
CNOT qreg2,qreg3
CNOT qreg1,qreg2
CNOT qreg0,qreg1
Rx(10.9956) qreg3
Rx(10.9956) qreg2
H qreg1
Rx(10.9956) qreg0
H qreg0
H qreg1
Rx(1.5708) qreg2
)expected";
	// Measure qreg0
	// Measure qreg1
	// Measure qreg2
	// Measure qreg3

	EXPECT_TRUE(expected == qir->getKernels()[0]->toString("qreg"));
}
int main(int argc, char** argv) {
	xacc::Initialize();
   ::testing::InitGoogleTest(&argc, argv);
   auto ret = RUN_ALL_TESTS();
   xacc::Finalize();
   return ret;
}
