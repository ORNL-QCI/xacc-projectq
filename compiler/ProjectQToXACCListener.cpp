/***********************************************************************************
 * Copyright (c) 2018, UT-Battelle
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
 *   Initial implementation - H. Charles Zhao
 *
 **********************************************************************************/

#include <boost/math/constants/constants.hpp>
#include "ProjectQBaseListener.h"
#include "exprtk.hpp"
#include "XACC.hpp"
#include "IRProvider.hpp"
#include "IR.hpp"
#include "ProjectQToXACCListener.hpp"

using namespace projectq;

using symbol_table_t = exprtk::symbol_table<double>;
using expression_t = exprtk::expression<double>;
using parser_t = exprtk::parser<double>;

namespace xacc {
    namespace quantum {
        constexpr static double pi = boost::math::constants::pi<double>();

        ProjectQToXACCListener::ProjectQToXACCListener(std::shared_ptr<xacc::IR> ir) : ir(ir) {
            gateRegistry = xacc::getService<IRProvider>("gate");
        }

        double evalMathExpression(const std::string &expression) {
            symbol_table_t symbol_table;
            symbol_table.add_constant("pi", pi);
            expression_t expr;
            expr.register_symbol_table(symbol_table);
            parser_t parser;
            parser.compile(expression, expr);
            return expr.value();
        }

        InstructionParameter strToParam(const std::string &str) {
            double num = evalMathExpression(str);
            if (std::isnan(num)) {
                return InstructionParameter(str);
            } else {
                return InstructionParameter(num);
            }
        }

        void ProjectQToXACCListener::enterXacckernel(projectq::ProjectQParser::XacckernelContext *ctx) {
            std::vector<InstructionParameter> params;
            for (int i = 0; i < ctx->typedparam().size(); i++) {
                params.push_back(InstructionParameter(ctx->typedparam(static_cast<size_t>(i))->IDENTIFIER()->getText()));
            }
            curFunc = gateRegistry->createFunction(ctx->kernelname->getText(), {}, params);
            functions.insert({curFunc->name(), curFunc});
        }

        void ProjectQToXACCListener::exitXacckernel(projectq::ProjectQParser::XacckernelContext *ctx) {
            ir->addKernel(curFunc);
        }

        void ProjectQToXACCListener::exitKernelcall(projectq::ProjectQParser::KernelcallContext *ctx) {
            std::string gateName = ctx->kernelname->getText();
            if (functions.count(gateName)) {
                curFunc->addInstruction(functions[gateName]);
            } else {
                xacc::error("Tried calling an undefined kernel.");
            }
        }

        void ProjectQToXACCListener::exitGate(projectq::ProjectQParser::GateContext *ctx) {
            std::string gateName = ctx->gatename()->getText();
            if (gateName == "CX") gateName = "CNOT";

            std::vector<int> qubits;
            for (int i = 0; i < ctx->qbitarglist()->qbit().size(); i++) {
                qubits.push_back(std::stoi(ctx->qbitarglist()->qbit(static_cast<size_t>(i))->INT()->getText()));
            }

            std::shared_ptr<xacc::Instruction> instruction(gateRegistry->createInstruction(gateName, qubits));

            if (ctx->paramlist() != nullptr) {
                InstructionParameter param;
                for (int i = 0; i < ctx->paramlist()->param().size(); i++) {
                    param = strToParam(ctx->paramlist()->param(i)->getText());
                    instruction->setParameter(i, param);
                }
            }

            curFunc->addInstruction(instruction);
        }

        void ProjectQToXACCListener::exitMeasure(projectq::ProjectQParser::MeasureContext *ctx) {
            std::vector<int> qubits;
            qubits.push_back(std::stoi(ctx->qbit()->INT()->getText()));

            std::shared_ptr<xacc::Instruction> instruction(gateRegistry->createInstruction("Measure", qubits));
            InstructionParameter param(qubits[0]);
            instruction->setParameter(0, param);

            curFunc->addInstruction(instruction);
        }
    }
}
