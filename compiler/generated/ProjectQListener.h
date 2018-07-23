
// Generated from ProjectQ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "ProjectQParser.h"


namespace projectq {

/**
 * This interface defines an abstract listener for a parse tree produced by ProjectQParser.
 */
class  ProjectQListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterXaccsrc(ProjectQParser::XaccsrcContext *ctx) = 0;
  virtual void exitXaccsrc(ProjectQParser::XaccsrcContext *ctx) = 0;

  virtual void enterXacckernel(ProjectQParser::XacckernelContext *ctx) = 0;
  virtual void exitXacckernel(ProjectQParser::XacckernelContext *ctx) = 0;

  virtual void enterKernelcall(ProjectQParser::KernelcallContext *ctx) = 0;
  virtual void exitKernelcall(ProjectQParser::KernelcallContext *ctx) = 0;

  virtual void enterTypedparam(ProjectQParser::TypedparamContext *ctx) = 0;
  virtual void exitTypedparam(ProjectQParser::TypedparamContext *ctx) = 0;

  virtual void enterProjectqprog(ProjectQParser::ProjectqprogContext *ctx) = 0;
  virtual void exitProjectqprog(ProjectQParser::ProjectqprogContext *ctx) = 0;

  virtual void enterInstr(ProjectQParser::InstrContext *ctx) = 0;
  virtual void exitInstr(ProjectQParser::InstrContext *ctx) = 0;

  virtual void enterGate(ProjectQParser::GateContext *ctx) = 0;
  virtual void exitGate(ProjectQParser::GateContext *ctx) = 0;

  virtual void enterGatename(ProjectQParser::GatenameContext *ctx) = 0;
  virtual void exitGatename(ProjectQParser::GatenameContext *ctx) = 0;

  virtual void enterAllocate(ProjectQParser::AllocateContext *ctx) = 0;
  virtual void exitAllocate(ProjectQParser::AllocateContext *ctx) = 0;

  virtual void enterMeasure(ProjectQParser::MeasureContext *ctx) = 0;
  virtual void exitMeasure(ProjectQParser::MeasureContext *ctx) = 0;

  virtual void enterParamlist(ProjectQParser::ParamlistContext *ctx) = 0;
  virtual void exitParamlist(ProjectQParser::ParamlistContext *ctx) = 0;

  virtual void enterParam(ProjectQParser::ParamContext *ctx) = 0;
  virtual void exitParam(ProjectQParser::ParamContext *ctx) = 0;

  virtual void enterQbitarglist(ProjectQParser::QbitarglistContext *ctx) = 0;
  virtual void exitQbitarglist(ProjectQParser::QbitarglistContext *ctx) = 0;

  virtual void enterQbit(ProjectQParser::QbitContext *ctx) = 0;
  virtual void exitQbit(ProjectQParser::QbitContext *ctx) = 0;

  virtual void enterQreg(ProjectQParser::QregContext *ctx) = 0;
  virtual void exitQreg(ProjectQParser::QregContext *ctx) = 0;

  virtual void enterExpr(ProjectQParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ProjectQParser::ExprContext *ctx) = 0;

  virtual void enterReal(ProjectQParser::RealContext *ctx) = 0;
  virtual void exitReal(ProjectQParser::RealContext *ctx) = 0;


};

}  // namespace projectq
