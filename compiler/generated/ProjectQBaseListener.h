
// Generated from ProjectQ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ProjectQListener.h"


namespace projectq {

/**
 * This class provides an empty implementation of ProjectQListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ProjectQBaseListener : public ProjectQListener {
public:

  virtual void enterXaccsrc(ProjectQParser::XaccsrcContext * /*ctx*/) override { }
  virtual void exitXaccsrc(ProjectQParser::XaccsrcContext * /*ctx*/) override { }

  virtual void enterXacckernel(ProjectQParser::XacckernelContext * /*ctx*/) override { }
  virtual void exitXacckernel(ProjectQParser::XacckernelContext * /*ctx*/) override { }

  virtual void enterKernelcall(ProjectQParser::KernelcallContext * /*ctx*/) override { }
  virtual void exitKernelcall(ProjectQParser::KernelcallContext * /*ctx*/) override { }

  virtual void enterTypedparam(ProjectQParser::TypedparamContext * /*ctx*/) override { }
  virtual void exitTypedparam(ProjectQParser::TypedparamContext * /*ctx*/) override { }

  virtual void enterProjectqprog(ProjectQParser::ProjectqprogContext * /*ctx*/) override { }
  virtual void exitProjectqprog(ProjectQParser::ProjectqprogContext * /*ctx*/) override { }

  virtual void enterInstr(ProjectQParser::InstrContext * /*ctx*/) override { }
  virtual void exitInstr(ProjectQParser::InstrContext * /*ctx*/) override { }

  virtual void enterGate(ProjectQParser::GateContext * /*ctx*/) override { }
  virtual void exitGate(ProjectQParser::GateContext * /*ctx*/) override { }

  virtual void enterGatename(ProjectQParser::GatenameContext * /*ctx*/) override { }
  virtual void exitGatename(ProjectQParser::GatenameContext * /*ctx*/) override { }

  virtual void enterAllocate(ProjectQParser::AllocateContext * /*ctx*/) override { }
  virtual void exitAllocate(ProjectQParser::AllocateContext * /*ctx*/) override { }

  virtual void enterMeasure(ProjectQParser::MeasureContext * /*ctx*/) override { }
  virtual void exitMeasure(ProjectQParser::MeasureContext * /*ctx*/) override { }

  virtual void enterParamlist(ProjectQParser::ParamlistContext * /*ctx*/) override { }
  virtual void exitParamlist(ProjectQParser::ParamlistContext * /*ctx*/) override { }

  virtual void enterParam(ProjectQParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(ProjectQParser::ParamContext * /*ctx*/) override { }

  virtual void enterQbitarglist(ProjectQParser::QbitarglistContext * /*ctx*/) override { }
  virtual void exitQbitarglist(ProjectQParser::QbitarglistContext * /*ctx*/) override { }

  virtual void enterQbit(ProjectQParser::QbitContext * /*ctx*/) override { }
  virtual void exitQbit(ProjectQParser::QbitContext * /*ctx*/) override { }

  virtual void enterQreg(ProjectQParser::QregContext * /*ctx*/) override { }
  virtual void exitQreg(ProjectQParser::QregContext * /*ctx*/) override { }

  virtual void enterExpr(ProjectQParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ProjectQParser::ExprContext * /*ctx*/) override { }

  virtual void enterReal(ProjectQParser::RealContext * /*ctx*/) override { }
  virtual void exitReal(ProjectQParser::RealContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace projectq
