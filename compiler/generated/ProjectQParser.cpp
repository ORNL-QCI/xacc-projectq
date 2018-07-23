
// Generated from ProjectQ.g4 by ANTLR 4.7.1


#include "ProjectQListener.h"

#include "ProjectQParser.h"


using namespace antlrcpp;
using namespace projectq;
using namespace antlr4;

ProjectQParser::ProjectQParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ProjectQParser::~ProjectQParser() {
  delete _interpreter;
}

std::string ProjectQParser::getGrammarFileName() const {
  return "ProjectQ.g4";
}

const std::vector<std::string>& ProjectQParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ProjectQParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- XaccsrcContext ------------------------------------------------------------------

ProjectQParser::XaccsrcContext::XaccsrcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProjectQParser::XacckernelContext *> ProjectQParser::XaccsrcContext::xacckernel() {
  return getRuleContexts<ProjectQParser::XacckernelContext>();
}

ProjectQParser::XacckernelContext* ProjectQParser::XaccsrcContext::xacckernel(size_t i) {
  return getRuleContext<ProjectQParser::XacckernelContext>(i);
}

std::vector<tree::TerminalNode *> ProjectQParser::XaccsrcContext::NEWLINE() {
  return getTokens(ProjectQParser::NEWLINE);
}

tree::TerminalNode* ProjectQParser::XaccsrcContext::NEWLINE(size_t i) {
  return getToken(ProjectQParser::NEWLINE, i);
}


size_t ProjectQParser::XaccsrcContext::getRuleIndex() const {
  return ProjectQParser::RuleXaccsrc;
}

void ProjectQParser::XaccsrcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXaccsrc(this);
}

void ProjectQParser::XaccsrcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXaccsrc(this);
}

ProjectQParser::XaccsrcContext* ProjectQParser::xaccsrc() {
  XaccsrcContext *_localctx = _tracker.createInstance<XaccsrcContext>(_ctx, getState());
  enterRule(_localctx, 0, ProjectQParser::RuleXaccsrc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProjectQParser::T__0

    || _la == ProjectQParser::NEWLINE) {
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ProjectQParser::NEWLINE) {
        setState(34);
        match(ProjectQParser::NEWLINE);
        setState(39);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(40);
      xacckernel();
      setState(44);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(41);
          match(ProjectQParser::NEWLINE); 
        }
        setState(46);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XacckernelContext ------------------------------------------------------------------

ProjectQParser::XacckernelContext::XacckernelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProjectQParser::ProjectqprogContext* ProjectQParser::XacckernelContext::projectqprog() {
  return getRuleContext<ProjectQParser::ProjectqprogContext>(0);
}

std::vector<tree::TerminalNode *> ProjectQParser::XacckernelContext::IDENTIFIER() {
  return getTokens(ProjectQParser::IDENTIFIER);
}

tree::TerminalNode* ProjectQParser::XacckernelContext::IDENTIFIER(size_t i) {
  return getToken(ProjectQParser::IDENTIFIER, i);
}

std::vector<ProjectQParser::TypedparamContext *> ProjectQParser::XacckernelContext::typedparam() {
  return getRuleContexts<ProjectQParser::TypedparamContext>();
}

ProjectQParser::TypedparamContext* ProjectQParser::XacckernelContext::typedparam(size_t i) {
  return getRuleContext<ProjectQParser::TypedparamContext>(i);
}


size_t ProjectQParser::XacckernelContext::getRuleIndex() const {
  return ProjectQParser::RuleXacckernel;
}

void ProjectQParser::XacckernelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXacckernel(this);
}

void ProjectQParser::XacckernelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXacckernel(this);
}

ProjectQParser::XacckernelContext* ProjectQParser::xacckernel() {
  XacckernelContext *_localctx = _tracker.createInstance<XacckernelContext>(_ctx, getState());
  enterRule(_localctx, 2, ProjectQParser::RuleXacckernel);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(ProjectQParser::T__0);
    setState(53);
    dynamic_cast<XacckernelContext *>(_localctx)->kernelname = match(ProjectQParser::IDENTIFIER);
    setState(54);
    match(ProjectQParser::T__1);
    setState(55);
    match(ProjectQParser::T__2);
    setState(56);
    dynamic_cast<XacckernelContext *>(_localctx)->acceleratorbuffer = match(ProjectQParser::IDENTIFIER);
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProjectQParser::T__3) {
      setState(57);
      match(ProjectQParser::T__3);
      setState(58);
      typedparam();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(ProjectQParser::T__4);
    setState(65);
    match(ProjectQParser::T__5);
    setState(66);
    projectqprog();
    setState(67);
    match(ProjectQParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KernelcallContext ------------------------------------------------------------------

ProjectQParser::KernelcallContext::KernelcallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProjectQParser::KernelcallContext::IDENTIFIER() {
  return getTokens(ProjectQParser::IDENTIFIER);
}

tree::TerminalNode* ProjectQParser::KernelcallContext::IDENTIFIER(size_t i) {
  return getToken(ProjectQParser::IDENTIFIER, i);
}


size_t ProjectQParser::KernelcallContext::getRuleIndex() const {
  return ProjectQParser::RuleKernelcall;
}

void ProjectQParser::KernelcallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKernelcall(this);
}

void ProjectQParser::KernelcallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKernelcall(this);
}

ProjectQParser::KernelcallContext* ProjectQParser::kernelcall() {
  KernelcallContext *_localctx = _tracker.createInstance<KernelcallContext>(_ctx, getState());
  enterRule(_localctx, 4, ProjectQParser::RuleKernelcall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    dynamic_cast<KernelcallContext *>(_localctx)->kernelname = match(ProjectQParser::IDENTIFIER);
    setState(70);
    match(ProjectQParser::T__1);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ProjectQParser::IDENTIFIER) {
      setState(71);
      match(ProjectQParser::IDENTIFIER);
    }
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProjectQParser::T__3) {
      setState(74);
      match(ProjectQParser::T__3);
      setState(75);
      match(ProjectQParser::IDENTIFIER);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(ProjectQParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedparamContext ------------------------------------------------------------------

ProjectQParser::TypedparamContext::TypedparamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::TypedparamContext::TYPE() {
  return getToken(ProjectQParser::TYPE, 0);
}

tree::TerminalNode* ProjectQParser::TypedparamContext::IDENTIFIER() {
  return getToken(ProjectQParser::IDENTIFIER, 0);
}


size_t ProjectQParser::TypedparamContext::getRuleIndex() const {
  return ProjectQParser::RuleTypedparam;
}

void ProjectQParser::TypedparamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedparam(this);
}

void ProjectQParser::TypedparamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedparam(this);
}

ProjectQParser::TypedparamContext* ProjectQParser::typedparam() {
  TypedparamContext *_localctx = _tracker.createInstance<TypedparamContext>(_ctx, getState());
  enterRule(_localctx, 6, ProjectQParser::RuleTypedparam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(ProjectQParser::TYPE);
    setState(84);
    match(ProjectQParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProjectqprogContext ------------------------------------------------------------------

ProjectQParser::ProjectqprogContext::ProjectqprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProjectQParser::InstrContext *> ProjectQParser::ProjectqprogContext::instr() {
  return getRuleContexts<ProjectQParser::InstrContext>();
}

ProjectQParser::InstrContext* ProjectQParser::ProjectqprogContext::instr(size_t i) {
  return getRuleContext<ProjectQParser::InstrContext>(i);
}

std::vector<tree::TerminalNode *> ProjectQParser::ProjectqprogContext::NEWLINE() {
  return getTokens(ProjectQParser::NEWLINE);
}

tree::TerminalNode* ProjectQParser::ProjectqprogContext::NEWLINE(size_t i) {
  return getToken(ProjectQParser::NEWLINE, i);
}


size_t ProjectQParser::ProjectqprogContext::getRuleIndex() const {
  return ProjectQParser::RuleProjectqprog;
}

void ProjectQParser::ProjectqprogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProjectqprog(this);
}

void ProjectQParser::ProjectqprogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProjectqprog(this);
}

ProjectQParser::ProjectqprogContext* ProjectQParser::projectqprog() {
  ProjectqprogContext *_localctx = _tracker.createInstance<ProjectqprogContext>(_ctx, getState());
  enterRule(_localctx, 8, ProjectQParser::RuleProjectqprog);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(87);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProjectQParser::ALLOCATE)
      | (1ULL << ProjectQParser::MEASURE)
      | (1ULL << ProjectQParser::IDENTIFIER))) != 0)) {
      setState(86);
      instr();
    }
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(90); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(89);
          match(ProjectQParser::NEWLINE);
          setState(92); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == ProjectQParser::NEWLINE);
        setState(94);
        instr(); 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProjectQParser::NEWLINE) {
      setState(100);
      match(ProjectQParser::NEWLINE);
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstrContext ------------------------------------------------------------------

ProjectQParser::InstrContext::InstrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProjectQParser::GateContext* ProjectQParser::InstrContext::gate() {
  return getRuleContext<ProjectQParser::GateContext>(0);
}

ProjectQParser::AllocateContext* ProjectQParser::InstrContext::allocate() {
  return getRuleContext<ProjectQParser::AllocateContext>(0);
}

ProjectQParser::MeasureContext* ProjectQParser::InstrContext::measure() {
  return getRuleContext<ProjectQParser::MeasureContext>(0);
}


size_t ProjectQParser::InstrContext::getRuleIndex() const {
  return ProjectQParser::RuleInstr;
}

void ProjectQParser::InstrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstr(this);
}

void ProjectQParser::InstrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstr(this);
}

ProjectQParser::InstrContext* ProjectQParser::instr() {
  InstrContext *_localctx = _tracker.createInstance<InstrContext>(_ctx, getState());
  enterRule(_localctx, 10, ProjectQParser::RuleInstr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProjectQParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        gate();
        break;
      }

      case ProjectQParser::ALLOCATE: {
        enterOuterAlt(_localctx, 2);
        setState(107);
        allocate();
        break;
      }

      case ProjectQParser::MEASURE: {
        enterOuterAlt(_localctx, 3);
        setState(108);
        measure();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateContext ------------------------------------------------------------------

ProjectQParser::GateContext::GateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProjectQParser::GatenameContext* ProjectQParser::GateContext::gatename() {
  return getRuleContext<ProjectQParser::GatenameContext>(0);
}

ProjectQParser::QbitarglistContext* ProjectQParser::GateContext::qbitarglist() {
  return getRuleContext<ProjectQParser::QbitarglistContext>(0);
}

ProjectQParser::ParamlistContext* ProjectQParser::GateContext::paramlist() {
  return getRuleContext<ProjectQParser::ParamlistContext>(0);
}


size_t ProjectQParser::GateContext::getRuleIndex() const {
  return ProjectQParser::RuleGate;
}

void ProjectQParser::GateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGate(this);
}

void ProjectQParser::GateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGate(this);
}

ProjectQParser::GateContext* ProjectQParser::gate() {
  GateContext *_localctx = _tracker.createInstance<GateContext>(_ctx, getState());
  enterRule(_localctx, 12, ProjectQParser::RuleGate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    gatename();
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ProjectQParser::T__1) {
      setState(112);
      paramlist();
    }
    setState(115);
    match(ProjectQParser::T__7);
    setState(116);
    qbitarglist();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatenameContext ------------------------------------------------------------------

ProjectQParser::GatenameContext::GatenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::GatenameContext::IDENTIFIER() {
  return getToken(ProjectQParser::IDENTIFIER, 0);
}


size_t ProjectQParser::GatenameContext::getRuleIndex() const {
  return ProjectQParser::RuleGatename;
}

void ProjectQParser::GatenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatename(this);
}

void ProjectQParser::GatenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatename(this);
}

ProjectQParser::GatenameContext* ProjectQParser::gatename() {
  GatenameContext *_localctx = _tracker.createInstance<GatenameContext>(_ctx, getState());
  enterRule(_localctx, 14, ProjectQParser::RuleGatename);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(ProjectQParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllocateContext ------------------------------------------------------------------

ProjectQParser::AllocateContext::AllocateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::AllocateContext::ALLOCATE() {
  return getToken(ProjectQParser::ALLOCATE, 0);
}

ProjectQParser::QbitContext* ProjectQParser::AllocateContext::qbit() {
  return getRuleContext<ProjectQParser::QbitContext>(0);
}


size_t ProjectQParser::AllocateContext::getRuleIndex() const {
  return ProjectQParser::RuleAllocate;
}

void ProjectQParser::AllocateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAllocate(this);
}

void ProjectQParser::AllocateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAllocate(this);
}

ProjectQParser::AllocateContext* ProjectQParser::allocate() {
  AllocateContext *_localctx = _tracker.createInstance<AllocateContext>(_ctx, getState());
  enterRule(_localctx, 16, ProjectQParser::RuleAllocate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(ProjectQParser::ALLOCATE);
    setState(121);
    match(ProjectQParser::T__7);
    setState(122);
    qbit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureContext ------------------------------------------------------------------

ProjectQParser::MeasureContext::MeasureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::MeasureContext::MEASURE() {
  return getToken(ProjectQParser::MEASURE, 0);
}

ProjectQParser::QbitContext* ProjectQParser::MeasureContext::qbit() {
  return getRuleContext<ProjectQParser::QbitContext>(0);
}


size_t ProjectQParser::MeasureContext::getRuleIndex() const {
  return ProjectQParser::RuleMeasure;
}

void ProjectQParser::MeasureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMeasure(this);
}

void ProjectQParser::MeasureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMeasure(this);
}

ProjectQParser::MeasureContext* ProjectQParser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 18, ProjectQParser::RuleMeasure);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(ProjectQParser::MEASURE);
    setState(125);
    match(ProjectQParser::T__7);
    setState(126);
    qbit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamlistContext ------------------------------------------------------------------

ProjectQParser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProjectQParser::ParamContext *> ProjectQParser::ParamlistContext::param() {
  return getRuleContexts<ProjectQParser::ParamContext>();
}

ProjectQParser::ParamContext* ProjectQParser::ParamlistContext::param(size_t i) {
  return getRuleContext<ProjectQParser::ParamContext>(i);
}


size_t ProjectQParser::ParamlistContext::getRuleIndex() const {
  return ProjectQParser::RuleParamlist;
}

void ProjectQParser::ParamlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamlist(this);
}

void ProjectQParser::ParamlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamlist(this);
}

ProjectQParser::ParamlistContext* ProjectQParser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 20, ProjectQParser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(ProjectQParser::T__1);
    setState(129);
    param();
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProjectQParser::T__3) {
      setState(130);
      match(ProjectQParser::T__3);
      setState(131);
      param();
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(ProjectQParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

ProjectQParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProjectQParser::ExprContext* ProjectQParser::ParamContext::expr() {
  return getRuleContext<ProjectQParser::ExprContext>(0);
}


size_t ProjectQParser::ParamContext::getRuleIndex() const {
  return ProjectQParser::RuleParam;
}

void ProjectQParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void ProjectQParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

ProjectQParser::ParamContext* ProjectQParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 22, ProjectQParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QbitarglistContext ------------------------------------------------------------------

ProjectQParser::QbitarglistContext::QbitarglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProjectQParser::QbitContext *> ProjectQParser::QbitarglistContext::qbit() {
  return getRuleContexts<ProjectQParser::QbitContext>();
}

ProjectQParser::QbitContext* ProjectQParser::QbitarglistContext::qbit(size_t i) {
  return getRuleContext<ProjectQParser::QbitContext>(i);
}


size_t ProjectQParser::QbitarglistContext::getRuleIndex() const {
  return ProjectQParser::RuleQbitarglist;
}

void ProjectQParser::QbitarglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQbitarglist(this);
}

void ProjectQParser::QbitarglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQbitarglist(this);
}

ProjectQParser::QbitarglistContext* ProjectQParser::qbitarglist() {
  QbitarglistContext *_localctx = _tracker.createInstance<QbitarglistContext>(_ctx, getState());
  enterRule(_localctx, 24, ProjectQParser::RuleQbitarglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProjectQParser::QREG: {
        enterOuterAlt(_localctx, 1);
        setState(141);
        qbit();
        break;
      }

      case ProjectQParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(142);
        match(ProjectQParser::T__1);
        setState(143);
        qbit();
        setState(148);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ProjectQParser::T__3) {
          setState(144);
          match(ProjectQParser::T__3);
          setState(145);
          qbit();
          setState(150);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(151);
        match(ProjectQParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QbitContext ------------------------------------------------------------------

ProjectQParser::QbitContext::QbitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProjectQParser::QregContext* ProjectQParser::QbitContext::qreg() {
  return getRuleContext<ProjectQParser::QregContext>(0);
}

tree::TerminalNode* ProjectQParser::QbitContext::INT() {
  return getToken(ProjectQParser::INT, 0);
}


size_t ProjectQParser::QbitContext::getRuleIndex() const {
  return ProjectQParser::RuleQbit;
}

void ProjectQParser::QbitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQbit(this);
}

void ProjectQParser::QbitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQbit(this);
}

ProjectQParser::QbitContext* ProjectQParser::qbit() {
  QbitContext *_localctx = _tracker.createInstance<QbitContext>(_ctx, getState());
  enterRule(_localctx, 26, ProjectQParser::RuleQbit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    qreg();
    setState(156);
    match(ProjectQParser::T__8);
    setState(157);
    match(ProjectQParser::INT);
    setState(158);
    match(ProjectQParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QregContext ------------------------------------------------------------------

ProjectQParser::QregContext::QregContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::QregContext::QREG() {
  return getToken(ProjectQParser::QREG, 0);
}


size_t ProjectQParser::QregContext::getRuleIndex() const {
  return ProjectQParser::RuleQreg;
}

void ProjectQParser::QregContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQreg(this);
}

void ProjectQParser::QregContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQreg(this);
}

ProjectQParser::QregContext* ProjectQParser::qreg() {
  QregContext *_localctx = _tracker.createInstance<QregContext>(_ctx, getState());
  enterRule(_localctx, 28, ProjectQParser::RuleQreg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(ProjectQParser::QREG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ProjectQParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProjectQParser::ExprContext *> ProjectQParser::ExprContext::expr() {
  return getRuleContexts<ProjectQParser::ExprContext>();
}

ProjectQParser::ExprContext* ProjectQParser::ExprContext::expr(size_t i) {
  return getRuleContext<ProjectQParser::ExprContext>(i);
}

ProjectQParser::RealContext* ProjectQParser::ExprContext::real() {
  return getRuleContext<ProjectQParser::RealContext>(0);
}

tree::TerminalNode* ProjectQParser::ExprContext::IDENTIFIER() {
  return getToken(ProjectQParser::IDENTIFIER, 0);
}

tree::TerminalNode* ProjectQParser::ExprContext::POWER() {
  return getToken(ProjectQParser::POWER, 0);
}

tree::TerminalNode* ProjectQParser::ExprContext::TIMES() {
  return getToken(ProjectQParser::TIMES, 0);
}

tree::TerminalNode* ProjectQParser::ExprContext::DIVIDE() {
  return getToken(ProjectQParser::DIVIDE, 0);
}

tree::TerminalNode* ProjectQParser::ExprContext::PLUS() {
  return getToken(ProjectQParser::PLUS, 0);
}

tree::TerminalNode* ProjectQParser::ExprContext::MINUS() {
  return getToken(ProjectQParser::MINUS, 0);
}


size_t ProjectQParser::ExprContext::getRuleIndex() const {
  return ProjectQParser::RuleExpr;
}

void ProjectQParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ProjectQParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ProjectQParser::ExprContext* ProjectQParser::expr() {
   return expr(0);
}

ProjectQParser::ExprContext* ProjectQParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ProjectQParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ProjectQParser::ExprContext *previousContext = _localctx;
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, ProjectQParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProjectQParser::T__1: {
        setState(163);
        match(ProjectQParser::T__1);
        setState(164);
        expr(0);
        setState(165);
        match(ProjectQParser::T__4);
        break;
      }

      case ProjectQParser::INT:
      case ProjectQParser::FLOAT: {
        setState(167);
        real();
        break;
      }

      case ProjectQParser::IDENTIFIER: {
        setState(168);
        match(ProjectQParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(182);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(180);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(171);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(172);
          match(ProjectQParser::POWER);
          setState(173);
          expr(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(174);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(175);
          _la = _input->LA(1);
          if (!(_la == ProjectQParser::TIMES

          || _la == ProjectQParser::DIVIDE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(176);
          expr(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(177);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(178);
          _la = _input->LA(1);
          if (!(_la == ProjectQParser::PLUS

          || _la == ProjectQParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(179);
          expr(4);
          break;
        }

        } 
      }
      setState(184);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RealContext ------------------------------------------------------------------

ProjectQParser::RealContext::RealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProjectQParser::RealContext::INT() {
  return getToken(ProjectQParser::INT, 0);
}

tree::TerminalNode* ProjectQParser::RealContext::FLOAT() {
  return getToken(ProjectQParser::FLOAT, 0);
}


size_t ProjectQParser::RealContext::getRuleIndex() const {
  return ProjectQParser::RuleReal;
}

void ProjectQParser::RealContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal(this);
}

void ProjectQParser::RealContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ProjectQListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal(this);
}

ProjectQParser::RealContext* ProjectQParser::real() {
  RealContext *_localctx = _tracker.createInstance<RealContext>(_ctx, getState());
  enterRule(_localctx, 32, ProjectQParser::RuleReal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    _la = _input->LA(1);
    if (!(_la == ProjectQParser::INT

    || _la == ProjectQParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ProjectQParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ProjectQParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ProjectQParser::_decisionToDFA;
atn::PredictionContextCache ProjectQParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ProjectQParser::_atn;
std::vector<uint16_t> ProjectQParser::_serializedATN;

std::vector<std::string> ProjectQParser::_ruleNames = {
  "xaccsrc", "xacckernel", "kernelcall", "typedparam", "projectqprog", "instr", 
  "gate", "gatename", "allocate", "measure", "paramlist", "param", "qbitarglist", 
  "qbit", "qreg", "expr", "real"
};

std::vector<std::string> ProjectQParser::_literalNames = {
  "", "'__qpu__'", "'('", "'AcceleratorBuffer'", "','", "')'", "'{'", "'}'", 
  "'|'", "'['", "']'", "", "'Qureg'", "'Allocate'", "'Measure'", "", "", 
  "", "'+'", "'-'", "'*'", "'/'", "'^'", "", "' '", "'\t'"
};

std::vector<std::string> ProjectQParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "TYPE", "QREG", "ALLOCATE", 
  "MEASURE", "IDENTIFIER", "INT", "FLOAT", "PLUS", "MINUS", "TIMES", "DIVIDE", 
  "POWER", "NEWLINE", "SPACE", "TAB"
};

dfa::Vocabulary ProjectQParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ProjectQParser::_tokenNames;

ProjectQParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1b, 0xbe, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x7, 0x2, 0x26, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x29, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x2d, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x30, 0xb, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x3e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x4b, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4f, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x52, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x5, 0x6, 0x5a, 0xa, 0x6, 0x3, 0x6, 
    0x6, 0x6, 0x5d, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x5e, 0x3, 0x6, 0x7, 0x6, 
    0x62, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x65, 0xb, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x68, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x6b, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x70, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x74, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x87, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x8a, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x95, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0x98, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x9c, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xac, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x7, 0x11, 0xb7, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xba, 0xb, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x3, 0x20, 0x13, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x2, 0x5, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x14, 0x15, 0x3, 
    0x2, 0x12, 0x13, 0x2, 0xc1, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x47, 0x3, 0x2, 0x2, 0x2, 0x8, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x59, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x71, 0x3, 0x2, 0x2, 0x2, 0x10, 0x78, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa2, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xab, 0x3, 0x2, 0x2, 0x2, 0x22, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x26, 0x7, 0x19, 0x2, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2e, 0x5, 0x4, 0x3, 0x2, 0x2b, 0x2d, 0x7, 
    0x19, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x27, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x3, 0x2, 0x2, 0x37, 0x38, 0x7, 0x11, 0x2, 0x2, 0x38, 0x39, 0x7, 0x4, 
    0x2, 0x2, 0x39, 0x3a, 0x7, 0x5, 0x2, 0x2, 0x3a, 0x3f, 0x7, 0x11, 0x2, 
    0x2, 0x3b, 0x3c, 0x7, 0x6, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x8, 0x5, 0x2, 
    0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 
    0x7, 0x2, 0x2, 0x43, 0x44, 0x7, 0x8, 0x2, 0x2, 0x44, 0x45, 0x5, 0xa, 
    0x6, 0x2, 0x45, 0x46, 0x7, 0x9, 0x2, 0x2, 0x46, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x11, 0x2, 0x2, 0x48, 0x4a, 0x7, 0x4, 0x2, 0x2, 
    0x49, 0x4b, 0x7, 0x11, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 
    0x7, 0x6, 0x2, 0x2, 0x4d, 0x4f, 0x7, 0x11, 0x2, 0x2, 0x4e, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x7, 0x2, 0x2, 
    0x54, 0x7, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0xd, 0x2, 0x2, 0x56, 
    0x57, 0x7, 0x11, 0x2, 0x2, 0x57, 0x9, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 
    0x5, 0xc, 0x7, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x7, 0x19, 
    0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 0x5, 0xc, 0x7, 0x2, 0x61, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x7, 0x19, 
    0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x70, 0x5, 0xe, 0x8, 0x2, 0x6d, 0x70, 0x5, 0x12, 0xa, 0x2, 0x6e, 0x70, 
    0x5, 0x14, 0xb, 0x2, 0x6f, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x73, 0x5, 0x10, 0x9, 0x2, 0x72, 0x74, 0x5, 0x16, 0xc, 
    0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0xa, 0x2, 0x2, 0x76, 
    0x77, 0x5, 0x1a, 0xe, 0x2, 0x77, 0xf, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0x11, 0x2, 0x2, 0x79, 0x11, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 
    0xf, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0xa, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x1c, 
    0xf, 0x2, 0x7d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x10, 0x2, 
    0x2, 0x7f, 0x80, 0x7, 0xa, 0x2, 0x2, 0x80, 0x81, 0x5, 0x1c, 0xf, 0x2, 
    0x81, 0x15, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x4, 0x2, 0x2, 0x83, 
    0x88, 0x5, 0x18, 0xd, 0x2, 0x84, 0x85, 0x7, 0x6, 0x2, 0x2, 0x85, 0x87, 
    0x5, 0x18, 0xd, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x8c, 0x7, 0x7, 0x2, 0x2, 0x8c, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8e, 0x5, 0x20, 0x11, 0x2, 0x8e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x9c, 0x5, 0x1c, 0xf, 0x2, 0x90, 0x91, 0x7, 0x4, 0x2, 0x2, 0x91, 0x96, 
    0x5, 0x1c, 0xf, 0x2, 0x92, 0x93, 0x7, 0x6, 0x2, 0x2, 0x93, 0x95, 0x5, 
    0x1c, 0xf, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x7, 0x7, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x90, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x5, 0x1e, 0x10, 0x2, 0x9e, 0x9f, 0x7, 
    0xb, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x12, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0xc, 
    0x2, 0x2, 0xa1, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0xe, 0x2, 
    0x2, 0xa3, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x8, 0x11, 0x1, 0x2, 
    0xa5, 0xa6, 0x7, 0x4, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x20, 0x11, 0x2, 0xa7, 
    0xa8, 0x7, 0x7, 0x2, 0x2, 0xa8, 0xac, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 
    0x5, 0x22, 0x12, 0x2, 0xaa, 0xac, 0x7, 0x11, 0x2, 0x2, 0xab, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0xc, 0x7, 0x2, 
    0x2, 0xae, 0xaf, 0x7, 0x18, 0x2, 0x2, 0xaf, 0xb7, 0x5, 0x20, 0x11, 0x8, 
    0xb0, 0xb1, 0xc, 0x6, 0x2, 0x2, 0xb1, 0xb2, 0x9, 0x2, 0x2, 0x2, 0xb2, 
    0xb7, 0x5, 0x20, 0x11, 0x7, 0xb3, 0xb4, 0xc, 0x5, 0x2, 0x2, 0xb4, 0xb5, 
    0x9, 0x3, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x20, 0x11, 0x6, 0xb6, 0xad, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x9, 0x4, 0x2, 0x2, 0xbc, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x14, 0x27, 0x2e, 0x33, 0x3f, 0x4a, 0x50, 
    0x59, 0x5e, 0x63, 0x69, 0x6f, 0x73, 0x88, 0x96, 0x9b, 0xab, 0xb6, 0xb8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ProjectQParser::Initializer ProjectQParser::_init;
