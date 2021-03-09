%skeleton "lalr1.cc"
%require "3.4"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
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
    #include "driver.hh"
    #include "location.hh"

    #include "expressions/NumberExpression.h"
    #include "expressions/AddExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/IdentExpression.h"
    #include "assignments/Assignment.h"
    #include "assignments/AssignmentList.h"

    // #include "assignments_default/assignment.h"
    // #include "assignments_default/assignment_list.h"
    // #include "expression_default/addexpression.h"
    // #include "expression_default/divexpression.h"
    // #include "expression_default/expression.h"
    // #include "expression_default/mulexpression.h"
    // #include "expression_default/subexpression.h"
    // #include "expression_template/addexpression.h"
    // #include "expression_template/divexpression.h"
    // #include "expression_template/expression.h"
    // #include "expression_template/mulexpression.h"
    // #include "expression_template/subexpression.h"

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
%nterm <Expression*> exp
%nterm <Assignment*> assignment
%nterm <AssignmentList*> assignments
%nterm <Program*> unit

// %printer { yyo << $$; } <*>;

%%
%start program;

program:
    main              { /* TODO */ }
  | program classdecl { /* TODO */ };

main: 
    "FROG" "identifier" "{" "BUBLIC" "STATEC" "VOEDA" "SWAMP" "(" ")" "{" statements "}" "}";

classdecl:
    "FROG" "identifier" "{" declarations "}" { /* TODO */ };

declaration:  
    vardecl    { /* TODO */ } 
  | methoddecl { /* TODO */ };

declarations:
    %empty                   { /* TODO */ }
  | declarations declaration { /* TODO */ };

methoddecl:
    "BUBLIC" type "identifier" "(" ")" "{" statements "}"         { /* TODO */ }
  | "BUBLIC" type "identifier" "(" formals ")" "{" statements "}" { /* TODO */ };

vardecl:
    type "identifier" ";" { /* TODO */ };

formal:
    type "identifier" { /* TODO */ };

formals:  
    formal                { /* TODO */ }
  | formals formal        { /* TODO */ };

statement:  
    "OSETR" "(" exp ")" ";"                        { /* TODO */ }
  | locvardecl ";"                                 { /* TODO */ }
  | "{" statements "}" ";"                         { /* TODO */ }
  | "IFF" "(" exp ")" statement ";"                { /* TODO */ }
  | "IFF" "(" exp ")" statement "ELS" statement ";"{ /* TODO */ }
  | "LOOPA" "(" exp ")" statement ";"              { /* TODO */ }
  | "CROAK" "(" exp ")" ";"                        { /* TODO */ }
  | lvalue "ASS" exp ";"                           { /* TODO */ }
  | "BURP" exp ";"                                 { /* TODO */ }
  | methinvokation ";"                             { /* TODO */ }
  | exp ";"                                        { /* TODO */ };

statements:
    %empty                { /* TODO */ }
  | statements statement  { /* TODO */ };


locvardecl:
    vardecl { /* TODO */ };

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
    "identifier"              { /* TODO */ }
  | "identifier" "[" exp "]"  { /* TODO */ }
  | fieldinvokation           { /* TODO */ };

type:
    simpletype { /* TODO */ }
  | arraytype  { /* TODO */ };

typeid:
    "identifier" { /* TODO */ }

simpletype: 
    "NUMBA"  { /* TODO */ }
  | "DUMBA"  { /* TODO */ }
  | "TEXTA"  { /* TODO */ }
  | "BOOLA"  { /* TODO */ }
  | "VOEDA"  { /* TODO */ }
  | typeid   { /* TODO */ };

arraytype:
    simpletype "[" "]" { /* TODO */ };

unit: 
    assignments exp { $$ = new Program($1, $2); driver.program = $$; };

assignments:
    %empty { $$ = new AssignmentList(); /* A -> eps */}
    | assignments assignment SEMICOLON {
        $1->AddAssignment($2); $$ = $1;
    };

assignment:
    "identifier" "ASS" exp {
        $$ = new Assignment($1, $3);
        driver.variables[$1] = $3->eval(driver);
    };

%left "PLUBS" "MENUS";
%left "MUTLI" "DEVID";

exp:
    "number"         { $$ = new NumberExpression($1);}
  | "identifier"     { $$ = new IdentExpression($1); }
  | exp "[" exp "]"  { /* TODO */ }
  | exp "." "LENA"   { /* TODO */ }
  | "YES"            { /* TODO */ }
  | "NO"             { /* TODO */ }
  | "NOT" exp        { /* TODO */ }
  | "POLLIWOG" simpletype "[" exp "]" { /* TODO */ }
  | "POLLIWOG" typeid "(" ")"         { /* TODO */ }
  | exp "PLUBS" exp  { $$ = new AddExpression($1, $3); }
  | exp "MENUS" exp  { $$ = new SubstractExpression($1, $3); }
  | exp "MUTLI" exp  { $$ = new MulExpression($1, $3); }
  | exp "DEVID" exp  { $$ = new DivExpression($1, $3); }
  | exp "EKWAL" exp  { /* TODO */ }
  | exp "NEKWAL" exp { /* TODO */ }
  | exp "LES"    exp { /* TODO */ }
  | exp "BIGA"   exp { /* TODO */ }
  | exp "LESOEK" exp { /* TODO */ }
  | exp "BIGOEK" exp { /* TODO */ }
  | "(" exp ")"      { $$ = $2; };


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
