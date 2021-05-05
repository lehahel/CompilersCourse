%skeleton "lalr1.cc"
%require "3.4"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <ForwardDeclarations.h>
    class Scanner;
    class Driver;
    class Expression;
    class NumberExpression;
    class AddExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class Assignment;
    class AssignmentList;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "ForwardDeclarations.h"

    #include "driver.hh"
    #include "location.hh"

    #include "expression/Expression.h"
    #include "expression/IdentExpression.h"
    #include "expression/BinaryOpExpression.h"
    #include "expression/UnaryOpExpression.h"
    #include "expression/IntExpression.h"
    #include "expression/BoolExpression.h"
    #include "expression/StringExpression.h"
    #include "expression/DoubleExpression.h"

    #include "statement/Statement.h"
    #include "statement/ExprStatement.h"
    #include "statement/LocVarDeclStatement.h"
    #include "statement/StatementList.h"
    #include "statement/AssStatement.h"

    #include "type/Type.h"
    #include "type/Bool.hpp"
    #include "type/Custom.hpp"
    #include "type/Double.hpp"
    #include "type/Int.hpp"
    #include "type/String.hpp"

    #include "declaration/Declaration.h"
    #include "declaration/VarDeclaration.h"

    #include "lvalue/Lvalue.h"
    #include "lvalue/IdentLvalue.h"

    #include "MainClass.h"
    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param   { Scanner &scanner }
%lex-param   { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0       "end of file"
    SEMICOLON   ";"
    ASSIGN      "ASS"
    MINUS       "MENUS"
    PLUS        "PLUBS"
    STAR        "MUTLI"
    SLASH       "DEVID"
    NOT         "NOT"
    EQUAL       "EKWAL"
    NEQUAL      "NEKWAL"
    LESS        "LES"
    BIGGER      "BIGA"
    LEQUAL      "LESOEK"
    BEQUAL      "BIGOEK"
    LPAREN      "("
    RPAREN      ")"
    LBLOCKPAR   "{"
    RBLOCKPAR   "}"
    LARRAYPAR   "["
    RARRAYPAR   "]"
    DOT         "."
    COMMA       ","
    PUBLIC      "BUBLIC"
    PRIVATE     "SECOOR"
    STATIC      "STATEC"
    MAIN        "SWAMP"
    CLASS       "FROG"
    INT         "NUMBA"
    DOUBLE      "DUMBA"
    BOOL        "BOOLA"
    STRING      "TEXTA"
    VOID        "VOEDA"
    NEW         "POLLIWOG"
    LENGTH      "LENA"
    TRUE        "YES"
    FALSE       "NO"
    THIS        "DIS"
    ASSERT      "OSETR"
    PRINT       "CROAK"
    IF          "IFF"
    ELSE        "ELS"
    WHILE       "LOOPA"
    RETURN      "BURP"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

// non-terminal types
%nterm <Expr::CBase*> exp
%nterm <AssignmentList*> assignments
%nterm <Program*> unit
%nterm <Statement::CBase*> statement
%nterm <Statement::CList*> statements
%nterm <CMain*> main;
%nterm <CAssignment*> assignment
%nterm <Lvalue::CBase*> lvalue
%nterm <Type::CBase*> type
%nterm <Type::CBase*> simpletype
%nterm <Type::CBase*> arraytype
%nterm <Declaration::CBase*> declaration
%nterm <Declaration::CVarDecl*> vardecl
%nterm <Declaration::CVarDecl*> locvardecl

// %printer { yyo << $$; } <*>;

%%
%start program;

program:
    main              { driver.program = new Program($1); }
  | program classdecl { /* TODO */ };

main: 
    "FROG" "identifier" "{" "BUBLIC" "STATEC" "VOEDA" "SWAMP" "(" ")" "{" statements "}" "}" ";" { 
        $$ = new CMain($11);
     };

classdecl:
    "FROG" "identifier" "{" declarations "}" { /* TODO */ };

declaration:  
    vardecl    { $$ = $1; } 
  | methoddecl { /* TODO */ };

declarations:
    %empty                   { /* TODO */ }
  | declarations declaration { /* TODO */ };

methoddecl:
    "BUBLIC" type "identifier" "(" ")" "{" statements "}"         { /* TODO */ }
  | "BUBLIC" type "identifier" "(" formals ")" "{" statements "}" { /* TODO */ };

vardecl:
    type "identifier" ";" { $$ = new Declaration::CVarDecl($1, $2); };

formal:
    type "identifier" { /* TODO */ };

formals:  
    formal                { /* TODO */ }
  | formals formal        { /* TODO */ };

statement:  
    "OSETR" "(" exp ")" ";"                        { /* TODO */ }
  | locvardecl                                     { $$ = new Statement::CLocVarDecl($1); std::cout << "here\n"; }
  | "{" statements "}" ";"                         { /* TODO */ }
  | "IFF" "(" exp ")" statement ";"                { /* TODO */ }
  | "IFF" "(" exp ")" statement "ELS" statement ";"{ /* TODO */ }
  | "LOOPA" "(" exp ")" statement ";"              { /* TODO */ }
  | "CROAK" "(" exp ")" ";"                        { /* TODO */ }
  | lvalue "ASS" exp ";"                           { $$ = new Statement::CAssignment($1, $3); }
  | "BURP" exp ";"                                 { /* TODO */ }
  | methinvokation ";"                             { /* TODO */ }
  | exp ";"                                        { $$ = new Statement::CExpr($1); };

statements:
    %empty                { $$ = new Statement::CList(); }
  | statements statement  { $1->Append($2); $$ = $1; };


locvardecl:
    vardecl { $$ = $1; };

exprargs:
    exp               { /* TODO */ }
  | exprargs "," exp  { /* TODO */ };

methinvokation:
    exp "." "identifier" "(" ")"           { /* TODO */ }
  | exp "." "identifier" "(" exprargs ")"  { /* TODO */ };

fieldinvokation:
    "DIS" "." "identifier"              { /* TODO */ }
  | "DIS" "." "identifier" "[" exp "]"  { /* TODO */ };

lvalue:
    "identifier"              { $$ = new Lvalue::CIdentifier($1); }
  | "identifier" "[" exp "]"  { /* TODO */ }
  | fieldinvokation           { /* TODO */ };

type:
    simpletype { $$ = $1; }
  | arraytype  { /* TODO */ };

typeid:
    "identifier" { /* TODO */ }

simpletype: 
    "NUMBA"  { $$ = new Type::CInt(); }
  | "DUMBA"  { $$ = new Type::CDouble(); }
  | "TEXTA"  { $$ = new Type::CString(); }
  | "BOOLA"  { $$ = new Type::CBool(); }
  | "VOEDA"  { /* TODO */ }
  | typeid   { /* TODO */ };

arraytype:
    simpletype "[" "]" { /* TODO */ };

unit: 
    assignments exp { $$ = new Program($1, $2); driver.program = $$; };

// assignments:
//    %empty { $$ = new AssignmentList(); /* A -> eps */}
//    | assignments assignment SEMICOLON {
//        $1->AddAssignment($2); $$ = $1;
//    };

// assignment:
//     "identifier" "ASS" exp {
        // $$ = new CAssignment($1, $3);
        // $$ = new Assignment($1, $3);
        // driver.variables[$1] = $3->eval(driver); };

%left "PLUBS" "MENUS";
%left "MUTLI" "DEVID";

exp:
    "number"         { $$ = new Expr::CIntExpr($1); /* $$ = new NumberExpression($1); */}
  | "identifier"     { $$ = new Expr::CIdent($1); }
  | exp "[" exp "]"  { /* TODO */ }
  | exp "." "LENA"   { /* TODO */ }
  | "YES"            { $$ = new Expr::CBoolExpr(true); }
  | "NO"             { $$ = new Expr::CBoolExpr(false); }
  | "NOT" exp        { $$ = Expr::CUnaryOperation::CreateMinus($2); }
  | "POLLIWOG" simpletype "[" exp "]" { /* TODO */ }
  | "POLLIWOG" typeid "(" ")"         { /* TODO */ }
  | exp "PLUBS"  exp { $$ = Expr::CBinaryOperation::CreateAdd    ($1, $3); }
  | exp "MENUS"  exp { $$ = Expr::CBinaryOperation::CreateSub    ($1, $3); }
  | exp "MUTLI"  exp { $$ = Expr::CBinaryOperation::CreateMul    ($1, $3); }
  | exp "DEVID"  exp { $$ = Expr::CBinaryOperation::CreateDiv    ($1, $3); }
  | exp "EKWAL"  exp { $$ = Expr::CBinaryOperation::CreateEqual  ($1, $3); }
  | exp "NEKWAL" exp { $$ = Expr::CBinaryOperation::CreateNequal ($1, $3); }
  | exp "LES"    exp { $$ = Expr::CBinaryOperation::CreateLess   ($1, $3); }
  | exp "BIGA"   exp { $$ = Expr::CBinaryOperation::CreateBigger ($1, $3); }
  | exp "LESOEK" exp { $$ = Expr::CBinaryOperation::CreateLequal ($1, $3); }
  | exp "BIGOEK" exp { $$ = Expr::CBinaryOperation::CreateBequal ($1, $3); }
  | "(" exp ")"      { $$ = $2; };


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
