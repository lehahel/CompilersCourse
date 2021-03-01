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

    #include "ast.h"

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

    PUBLIC      "BUBLIC"
    PRIVATE     "SECOOR"
    STATIC      "STATEC"
    MAIN        "TOAD"
    CLASS       "FROG"
    ASSIGN      "ASS"

    // Types
    INT         "NUMBA"
    DOUBLE      "DUMBA"
    BOOL        "BOOLA"
    STRING      "TEXTA"
    VOID        "VOEDA"

    // Control structures and cycles
    ASSERT      "OSETR"
    PRINT       "VRIET"
    IF          "IFF"
    ELSE        "ELS"
    WHILE       "LOOPA"
    RETURN      "BURP"

    TRUE        "RLY"
    FALSE       "NOPE"

    // Logical operations
    AND         "&&"
    OR          "||"

    // Comparison
    EQUAL       "=="
    NEQ         "!="
    LESS        "<"
    LEQ         "<="
    GREATER     ">"
    GEQ         ">="

    // Brackets & marks
    SEMICOLON   ";"
    LPAREN      "("
    RPAREN      ")"
    LBLOCKPAR   "{"
    RBLOCKPAR   "}"
    LARRAYPAR   "["
    RARRAYPAR   "]"
    DOT         "."
    COMMA       ","
    EXCLAM      "!"

    // Arithmetic operations
    MINUS       "MENUS"
    PLUS        "PLUBS"
    STAR        "MULTI"
    SLASH       "DEVID"
    PERC        "MODI"

    END 0       "end of file"

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
    "FROG" "identifier" "{" "BUBLIC" "STATEC" "VOEDA" "TOAD" "(" ")" "{" unit "}" "}";

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

statement:  "OSETR" "(" exp ")"                         { /* TODO */ }
          | locvardecl                                   { /* TODO */ }
          | "{" statements "}"                           { /* TODO */ }
          | "IFF" "(" exp ")" statement                 { /* TODO */ }
          | "IFF" "(" exp ")" statement "ELS" statement { /* TODO */ }
          | "LOOPA" "(" exp ")" statement               { /* TODO */ }
          | "VRIET" "(" exp ")" ";"                     { /* TODO */ }
          | lvalue "ASS" exp ";"                        { /* TODO */ }
          | "BURP" exp ";"                              { /* TODO */ }
          | methinvokation ";"                           { /* TODO */ };


locvardecl:
    vardecl { /* TODO */ };

exprargs:
    exp            { /* TODO */ }
  | exprargs, exp  { /* TODO */ };

methinvokation:
    exp "." "identifier" "(" ")"           { /* TODO */ }
  | exp "." "identifier" "(" exprargs ")"  { /* TODO */ };

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

unit: assignments exp { $$ = new Program($1, $2); driver.program = $$; };

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
%left "MULTI" "DEVID";

exp:
    "number"           { $$ = new NumberExpression($1); }
    | "identifier"     { $$ = new IdentExpression($1); }
    | exp "PLUBS" exp  { $$ = new AddExpression($1, $3); }
    | exp "MENUS" exp  { $$ = new SubstractExpression($1, $3); }
    | exp "MULTI" exp  { $$ = new MulExpression($1, $3); }
    | exp "DEVID" exp  { $$ = new DivExpression($1, $3); }
    | "(" exp ")"      { $$ = $2; };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
