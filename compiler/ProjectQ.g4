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
 * Originally developed by:
 * H. Charles Zhao, Oak Ridge National Laboratory, July 2018
 *
 **********************************************************************************/

grammar ProjectQ;

/* This part of the grammar is particular to XACC */
/**********************************************************************************/
xaccsrc             : (NEWLINE* xacckernel NEWLINE*)* ;

xacckernel          : '__qpu__' kernelname=IDENTIFIER '(' 'AcceleratorBuffer' acceleratorbuffer=IDENTIFIER (',' typedparam)* ')' '{' projectqprog '}' ;

kernelcall          : kernelname=IDENTIFIER '(' IDENTIFIER? (',' IDENTIFIER)* ')' ;

typedparam          : TYPE IDENTIFIER ;

TYPE                : INTTYPE | DOUBLETYPE | FLOATTYPE ;

fragment INTTYPE    : 'int' ;
fragment DOUBLETYPE : 'double';
fragment FLOATTYPE  : 'float' ;
/**********************************************************************************/


/********************
 * Parser           *
 *******************/
projectqprog        : instr? (NEWLINE+ instr)* NEWLINE* ;

instr               : gate
                    | allocate
                    | measure
                    ;

gate                : gatename paramlist? '|' qbitarglist ;

gatename            : IDENTIFIER ;

allocate            : ALLOCATE '|' qbit ;

measure             : MEASURE '|' qbit ;

paramlist           : '(' param (',' param)* ')' ;

param               : expr ;

qbitarglist         : qbit
                    | '(' qbit (',' qbit)* ')'
                    ;

qbit                : qreg '[' INT ('-' INT)? ']' ;

qreg                : QREG ;

expr                : '(' expr ')'
                    | '-' expr
                    | expr POWER expr
                    | expr (TIMES | DIVIDE) expr
                    | expr (PLUS | MINUS) expr
                    | real
                    | IDENTIFIER
                    ;

real                : INT
                    | FLOAT
                    ;


/********************
 * Lexer            *
 *******************/
QREG                : 'Qureg' ;
ALLOCATE            : 'Allocate' ;
MEASURE             : 'Measure' ;

IDENTIFIER          : [A-Za-z_] [A-Za-z0-9_]* ;

INT           : DIGIT+ ;
FLOAT               : INT EXPONENT
                    | DIGIT* '.' DIGIT+ EXPONENT?
                    ;

PLUS                : '+' ;
MINUS               : '-' ;
TIMES               : '*' ;
DIVIDE              : '/' ;
POWER               : '^' ;

NEWLINE             : ('\r'? '\n') ;
SPACE               : ' ' -> skip ;
TAB                 : '\t' -> skip ;

fragment SIGN       : '+' | '-' ;
fragment DIGIT      : [0-9]+ ;
fragment EXPONENT   : ('e' | 'E') SIGN? [0-9]+ ;
