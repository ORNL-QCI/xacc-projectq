/***********************************************************************************
 * Copyright (c) 2017, UT-Battelle
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
#include "GateQIR.hpp"
#include <boost/tokenizer.hpp>
#include "ProjectQCompiler.hpp"

namespace xacc {

namespace quantum {

ProjectQCompiler::ProjectQCompiler() {
}

std::shared_ptr<IR> ProjectQCompiler::compile(const std::string& src,
		std::shared_ptr<Accelerator> acc) {
	accelerator = acc;
	return compile(src);
}

std::shared_ptr<IR> ProjectQCompiler::compile(const std::string& src) {

	// Need to analyze string for function calls
	// FIXME for now just assume one function

	auto ir = std::make_shared<GateQIR>();
	std::shared_ptr<GateFunction> function;
	auto gateRegistry = GateInstructionRegistry::instance();
	std::map<std::string, std::string> projectQGatesToXACC { { "X", "X" }, {
			"CX", "CNOT" }, { "H", "H" }, { "Rx", "Rx" }, { "Ry", "Ry" }, {
			"Rz", "Rz" } };

	// find first occurrence of Allocate
	auto srcBegin = src.begin();
	auto endLine = src.begin();
	auto location = src.find_first_of("\n");
	auto secondlocation = src.find_first_of("\n", location+1);
	std::advance(srcBegin, location+1);
	std::advance(endLine, secondlocation);
	std::string allocateLine(srcBegin, endLine);
	boost::char_separator<char> allocatesep(" | ");
	boost::tokenizer<boost::char_separator<char> > allocateTokens(allocateLine, allocatesep);
	std::vector<std::string> allocateSplit;
	std::copy(allocateTokens.begin(), allocateTokens.end(),
			std::back_inserter<std::vector<std::string> >(allocateSplit));
	auto qubitVarName = allocateSplit[1].substr(0, allocateSplit[1].find_first_of("["));


	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char> > tokens(src, sep);
	for (auto t : tokens) {
		boost::trim(t);
		if (t != "}" && !boost::contains(t, "Allocate")) {
			boost::char_separator<char> subsep(" | ");
			boost::tokenizer<boost::char_separator<char> > subtokens(t, subsep);

			std::vector<std::string> lineStrs;
			std::copy(subtokens.begin(), subtokens.end(),
					std::back_inserter<std::vector<std::string> >(lineStrs));

			if (lineStrs[0] == "__qpu__") {
				auto functionName = lineStrs[1];
				functionName = functionName.substr(0, functionName.find_first_of("("));
				function = std::make_shared<GateFunction>(functionName);
			} else if (lineStrs[0] == "Allocate") {


			} else if (boost::contains(lineStrs[0], "(")) {

				// This gate is parameterized
				auto firstParen = lineStrs[0].find_first_of("(");
				auto secondParen = lineStrs[0].find_first_of(")");
				auto pqGate = lineStrs[0].substr(0, firstParen);
				auto paramStr = lineStrs[0].substr(firstParen + 1,
						secondParen - firstParen - 1);

				std::vector<InstructionParameter> params;
				std::vector<std::string> splitOnComma;
				boost::split(splitOnComma, paramStr, boost::is_any_of(","));
				for (auto s : splitOnComma) {
					std::stringstream ss;
					ss << std::setprecision(10) << std::fixed << s;
					double d;
					ss >> d;
					params.push_back(InstructionParameter(d)); //std::stod(s)));
				}

				std::vector<int> qubitIds;
				for (int i = 1; i < lineStrs.size(); i++) {
					if (boost::contains(lineStrs[i], qubitVarName)) {
						auto temp = lineStrs[i];
						boost::replace_all(temp, qubitVarName, "");
						boost::replace_all(temp, "[", "");
						boost::replace_all(temp, "]", "");

						qubitIds.push_back(std::stoi(temp));
					}
				}

				auto inst = gateRegistry->create(pqGate, qubitIds);
				int i = 0;
				for(auto p : params) {
					inst->setParameter(i, p);
					i++;
				}

				function->addInstruction(inst);

			} else {
				auto gate = lineStrs[0];
				if (lineStrs[0] == "CX") {
					gate = "CNOT";
				}

				std::vector<int> qubitIds;
				for (int i = 1; i < lineStrs.size(); i++) {
					if (boost::contains(lineStrs[i], qubitVarName)) {
						auto temp = lineStrs[i];
						boost::replace_all(temp, qubitVarName, "");
						boost::replace_all(temp, "[", "");
						boost::replace_all(temp, "]", "");

						qubitIds.push_back(std::stoi(temp));
					}
				}
				auto inst = gateRegistry->create(gate, qubitIds);

				function->addInstruction(inst);

			}
		}
	}

	ir->addKernel(function);

	return ir;
}

const std::string ProjectQCompiler::translate(const std::string& bufferVariable,
		std::shared_ptr<Function> function) {
//	auto visitor = std::make_shared<ProjectQVisitor>();
//	InstructionIterator it(function);
//	while (it.hasNext()) {
//		// Get the next node in the tree
//		auto nextInst = it.next();
//		if (nextInst->isEnabled()) {
//			nextInst->accept(visitor);
//		}
//	}
//
//	return visitor->getQuilString();
}

}

}
