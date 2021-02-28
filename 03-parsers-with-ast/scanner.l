%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"
%option yylineno      

%option debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();
%}

"FROG"     { return yy::parser::make_CLASS     (loc); }
"BUBLIC"   { return yy::parser::make_PUBLIC    (loc); }
"SECOOR"   { return yy::parser::make_PRIVATE   (loc); }
"STATEC"   { return yy::parser::make_STATIC    (loc); }
"TOAD"     { return yy::parser::make_MAIN      (loc); }

"NUMBA"    { return yy::parser::make_INT       (loc); }
"DUMBA"    { return yy::parser::make_DOUBLE    (loc); }
"BOOLA"    { return yy::parser::make_BOOL      (loc); }
"TEXTA"    { return yy::parser::make_STRING    (loc); }
"VOEDA"    { return yy::parser::make_VOID      (loc); }

"OSETR"    { return yy::parser::make_ASSERT    (loc); }
"VRIET"    { return yy::parser::make_PRINT     (loc); }
"IFF"      { return yy::parser::make_IF        (loc); }
"ELS"      { return yy::parser::make_ELSE      (loc); }
"LOOPA"    { return yy::parser::make_WHILE     (loc); }
"BURP"     { return yy::parser::make_RETURN    (loc); }

";"        { return yy::parser::make_SEMICOLON (loc); }
"{"        { return yy::parser::make_LBLOCKPAR (loc); }
"}"        { return yy::parser::make_RBLOCKPAR (loc); }
"["        { return yy::parser::make_LARRAYPAR (loc); }
"]"        { return yy::parser::make_RARRAYPAR (loc); }
"."        { return yy::parser::make_DOT       (loc); }

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"MENUS"    {
              std::cout << loc.begin.line << " " << loc.end.line << std::endl;
              return yy::parser::make_MINUS  (loc);
           }
"PLUBS"    return yy::parser::make_PLUS   (loc);
"MUTLI"    return yy::parser::make_STAR   (loc);
"DEVID"    return yy::parser::make_SLASH  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
"ASS"      return yy::parser::make_ASSIGN (loc);

{int}      return make_NUMBER(yytext, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}