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
#ifndef XACC_PROJECTQ_PROJECTQTOXACCLISTENER_H
#define XACC_PROJECTQ_PROJECTQTOXACCLISTENER_H

#include "ProjectQBaseListener.h"
#include "IR.hpp"
#include "IRProvider.hpp"

using namespace projectq;

namespace xacc {
    namespace quantum {
        class ProjectQToXACCListener : public ProjectQBaseListener {
            std::shared_ptr<IR> ir;
            std::shared_ptr<IRProvider> gateRegistry;
            std::map<std::string, std::shared_ptr<Function>> functions;
            std::shared_ptr<Function> curFunc;
        public:
            explicit ProjectQToXACCListener(std::shared_ptr<IR>);

            void enterXacckernel(ProjectQParser::XacckernelContext *ctx);

            void exitXacckernel(ProjectQParser::XacckernelContext *ctx);

            void exitKernelcall(ProjectQParser::KernelcallContext *ctx);

            void exitGate(ProjectQParser::GateContext *ctx);

            void exitMeasure(ProjectQParser::MeasureContext *ctx);
        };
    }
}

#endif //XACC_PROJECTQ_PROJECTQTOXACCLISTENER_H
