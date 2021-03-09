// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 30 "parser.y"

    #include "driver.hh"
    #include "location.hh"

    // #include "expressions/NumberExpression.h"
    // #include "expressions/AddExpression.h"
    // #include "expressions/MulExpression.h"
    // #include "expressions/DivExpression.h"
    // #include "expressions/SubstractExpression.h"
    // #include "expressions/IdentExpression.h"
    // #include "assignments/Assignment.h"
    // #include "assignments/AssignmentList.h"

    #include "Base.h"
    #include "visitor/Visitor.h"
    #include "expression/Expression.h"
    #include "expression/BinaryOpExpression.h"
    #include "expression/UnaryOpExpression.h"
    #include "expression/NumberExpression.h"
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

#line 85 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 177 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"

  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
        value.copy< Expression* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
        value.move< Expression* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< Expression* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: main
#line 139 "parser.y"
                      { /* TODO */ }
#line 632 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 3: // program: program classdecl
#line 140 "parser.y"
                      { /* TODO */ }
#line 638 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 5: // classdecl: "FROG" "identifier" "{" declarations "}"
#line 146 "parser.y"
                                             { /* TODO */ }
#line 644 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 6: // declaration: vardecl
#line 149 "parser.y"
               { /* TODO */ }
#line 650 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 7: // declaration: methoddecl
#line 150 "parser.y"
               { /* TODO */ }
#line 656 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 8: // declarations: %empty
#line 153 "parser.y"
                             { /* TODO */ }
#line 662 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 9: // declarations: declarations declaration
#line 154 "parser.y"
                             { /* TODO */ }
#line 668 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 10: // methoddecl: "BUBLIC" type "identifier" "(" ")" "{" statements "}"
#line 157 "parser.y"
                                                                  { /* TODO */ }
#line 674 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 11: // methoddecl: "BUBLIC" type "identifier" "(" formals ")" "{" statements "}"
#line 158 "parser.y"
                                                                  { /* TODO */ }
#line 680 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 12: // vardecl: type "identifier" ";"
#line 161 "parser.y"
                          { /* TODO */ }
#line 686 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 13: // formal: type "identifier"
#line 164 "parser.y"
                      { /* TODO */ }
#line 692 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 14: // formals: formal
#line 167 "parser.y"
                          { /* TODO */ }
#line 698 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 15: // formals: formals formal
#line 168 "parser.y"
                          { /* TODO */ }
#line 704 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 16: // statement: "OSETR" "(" exp ")" ";"
#line 171 "parser.y"
                                                   { /* TODO */ }
#line 710 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 17: // statement: locvardecl ";"
#line 172 "parser.y"
                                                   { /* TODO */ }
#line 716 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 18: // statement: "{" statements "}" ";"
#line 173 "parser.y"
                                                   { /* TODO */ }
#line 722 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 19: // statement: "IFF" "(" exp ")" statement ";"
#line 174 "parser.y"
                                                   { /* TODO */ }
#line 728 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 20: // statement: "IFF" "(" exp ")" statement "ELS" statement ";"
#line 175 "parser.y"
                                                   { /* TODO */ }
#line 734 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 21: // statement: "LOOPA" "(" exp ")" statement ";"
#line 176 "parser.y"
                                                   { /* TODO */ }
#line 740 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 22: // statement: "CROAK" "(" exp ")" ";"
#line 177 "parser.y"
                                                   { /* TODO */ }
#line 746 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 23: // statement: lvalue "ASS" exp ";"
#line 178 "parser.y"
                                                   { /* TODO */ }
#line 752 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 24: // statement: "BURP" exp ";"
#line 179 "parser.y"
                                                   { /* TODO */ }
#line 758 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 25: // statement: methinvokation ";"
#line 180 "parser.y"
                                                   { /* TODO */ }
#line 764 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 26: // statement: exp ";"
#line 181 "parser.y"
                                                   { /* TODO */ }
#line 770 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 27: // statements: %empty
#line 184 "parser.y"
                          { /* TODO */ }
#line 776 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 28: // statements: statements statement
#line 185 "parser.y"
                          { /* TODO */ }
#line 782 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 29: // locvardecl: vardecl
#line 189 "parser.y"
            { /* TODO */ }
#line 788 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 30: // exprargs: exp
#line 192 "parser.y"
                      { /* TODO */ }
#line 794 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 31: // exprargs: exprargs "," exp
#line 193 "parser.y"
                      { /* TODO */ }
#line 800 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 32: // methinvokation: exp "." "identifier" "(" ")"
#line 196 "parser.y"
                                           { /* TODO */ }
#line 806 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 33: // methinvokation: exp "." "identifier" "(" exprargs ")"
#line 197 "parser.y"
                                           { /* TODO */ }
#line 812 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 34: // fieldinvokation: "DIS" "." "identifier"
#line 200 "parser.y"
                                        { /* TODO */ }
#line 818 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 35: // fieldinvokation: "DIS" "." "identifier" "[" exp "]"
#line 201 "parser.y"
                                        { /* TODO */ }
#line 824 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 36: // lvalue: "identifier"
#line 204 "parser.y"
                              { /* TODO */ }
#line 830 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 37: // lvalue: "identifier" "[" exp "]"
#line 205 "parser.y"
                              { /* TODO */ }
#line 836 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 38: // lvalue: fieldinvokation
#line 206 "parser.y"
                              { /* TODO */ }
#line 842 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 39: // type: simpletype
#line 209 "parser.y"
               { /* TODO */ }
#line 848 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 40: // type: arraytype
#line 210 "parser.y"
               { /* TODO */ }
#line 854 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 41: // typeid: "identifier"
#line 213 "parser.y"
                 { /* TODO */ }
#line 860 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 42: // simpletype: "NUMBA"
#line 216 "parser.y"
             { /* TODO */ }
#line 866 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 43: // simpletype: "DUMBA"
#line 217 "parser.y"
             { /* TODO */ }
#line 872 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 44: // simpletype: "TEXTA"
#line 218 "parser.y"
             { /* TODO */ }
#line 878 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 45: // simpletype: "BOOLA"
#line 219 "parser.y"
             { /* TODO */ }
#line 884 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 46: // simpletype: "VOEDA"
#line 220 "parser.y"
             { /* TODO */ }
#line 890 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 47: // simpletype: typeid
#line 221 "parser.y"
             { /* TODO */ }
#line 896 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 48: // arraytype: simpletype "[" "]"
#line 224 "parser.y"
                       { /* TODO */ }
#line 902 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 49: // exp: "number"
#line 245 "parser.y"
                     { yylhs.value.as < Expression* > () = new Expr::CNumber(yystack_[0].value.as < int > ());}
#line 908 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 50: // exp: "identifier"
#line 246 "parser.y"
                     { /*$$ = new IdentExpression($1);*/ }
#line 914 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 51: // exp: exp "[" exp "]"
#line 247 "parser.y"
                     { /* TODO */ }
#line 920 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 52: // exp: exp "." "LENA"
#line 248 "parser.y"
                     { /* TODO */ }
#line 926 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 53: // exp: "YES"
#line 249 "parser.y"
                     { /* TODO */ }
#line 932 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 54: // exp: "NO"
#line 250 "parser.y"
                     { /* TODO */ }
#line 938 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 55: // exp: "NOT" exp
#line 251 "parser.y"
                     { /* TODO */ }
#line 944 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 56: // exp: "POLLIWOG" simpletype "[" exp "]"
#line 252 "parser.y"
                                      { /* TODO */ }
#line 950 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 57: // exp: "POLLIWOG" typeid "(" ")"
#line 253 "parser.y"
                                      { /* TODO */ }
#line 956 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 58: // exp: exp "MENUS" exp
#line 254 "parser.y"
                     { yylhs.value.as < Expression* > () = new Expr::CBinaryOperation::CreateSub(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 962 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 59: // exp: exp "PLUBS" exp
#line 255 "parser.y"
                     { yylhs.value.as < Expression* > () = new Expr::CBinaryOperation::CreateAdd(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 968 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 60: // exp: exp "MUTLI" exp
#line 256 "parser.y"
                     { yylhs.value.as < Expression* > () = new Expr::CBinaryOperation::CreateMul(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 974 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 61: // exp: exp "DEVID" exp
#line 257 "parser.y"
                     { yylhs.value.as < Expression* > () = new Expr::CBinaryOperation::CreateDiv(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 980 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 62: // exp: exp "EKWAL" exp
#line 258 "parser.y"
                     { /* TODO */ }
#line 986 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 63: // exp: exp "NEKWAL" exp
#line 259 "parser.y"
                     { /* TODO */ }
#line 992 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 64: // exp: exp "LES" exp
#line 260 "parser.y"
                     { /* TODO */ }
#line 998 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 65: // exp: exp "BIGA" exp
#line 261 "parser.y"
                     { /* TODO */ }
#line 1004 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 66: // exp: exp "LESOEK" exp
#line 262 "parser.y"
                     { /* TODO */ }
#line 1010 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 67: // exp: exp "BIGOEK" exp
#line 263 "parser.y"
                     { /* TODO */ }
#line 1016 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 68: // exp: "(" exp ")"
#line 264 "parser.y"
                     { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1022 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;


#line 1026 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -85;

  const signed char parser::yytable_ninf_ = -42;

  const short
  parser::yypact_[] =
  {
     -22,   -38,    10,   -85,     8,   -85,   -36,   -85,     1,    12,
       2,   -85,    -6,   219,    30,   -85,   478,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,    13,   -85,    41,   -85,
      47,    19,    62,    46,    52,    54,   -85,   -85,    53,   -14,
     -85,    55,   -85,    -9,    29,    59,   -85,    58,   -85,   -85,
     210,   210,   -85,    60,   478,   -85,   -85,    61,    65,    66,
      68,    69,   210,     9,   -85,   -85,   -85,    84,   103,   -85,
     108,   268,    92,   -85,   -85,   484,   322,   125,   -85,    91,
      93,    70,   210,   210,   210,   210,   286,   210,   -85,   -85,
     210,   -85,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   -31,   -85,   158,    79,   -85,   113,   100,
     210,    98,   340,   358,   376,   394,   -85,   412,   304,   505,
     505,   518,   518,   484,   484,   484,   484,   484,   484,   430,
     -85,   104,   -85,   -85,   -85,   448,   210,   116,   124,   191,
     191,   -85,   -85,   -85,   224,   -85,   466,   -85,   -85,    -1,
     136,   -85,   -12,   484,   -85,   -85,   191,   -85,   -85,   210,
     137,   484,   -85
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     3,     0,     0,
       0,     8,     0,     0,     0,     5,     0,    42,    43,    45,
      44,    46,    41,     9,     7,     6,     0,    47,    39,    40,
       0,     0,     0,     0,     0,     0,    12,    48,     0,     0,
      27,     0,    14,     0,     0,     0,    27,     0,    15,    13,
       0,     0,    27,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,    50,    49,    29,    28,     0,     0,    38,
       0,     0,     0,    27,    50,    55,     0,     0,     4,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    25,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,    68,     0,     0,
       0,    34,     0,     0,     0,     0,    24,     0,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      52,     0,    11,    18,    57,     0,     0,     0,     0,     0,
       0,    37,    23,    51,     0,    56,     0,    16,    22,     0,
       0,    32,     0,    30,    35,    19,     0,    21,    33,     0,
       0,    31,    20
  };

  const short
  parser::yypgoto_[] =
  {
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   129,   102,   -85,
     -84,     7,   -85,   -85,   -85,   -85,   -85,    23,    94,    95,
     -85,   -50
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     7,    23,    13,    24,    65,    42,    43,
      66,    45,    67,   152,    68,    69,    70,    26,    27,    28,
      29,    71
  };

  const short
  parser::yytable_[] =
  {
      75,    76,   155,    41,   130,   158,     1,     4,    47,     9,
       5,   159,    86,   -36,   131,    17,    18,    19,    20,    21,
      17,    18,    19,    20,    21,    10,     8,    14,    12,    87,
      11,    22,   112,   113,   114,   115,    22,   117,     6,    31,
     118,   156,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    72,   -41,   149,   150,    30,    32,    77,
     135,    33,    44,    34,    35,    36,    44,    37,    50,    38,
      39,    40,   160,    46,    49,    51,    73,    52,    53,    78,
     105,    82,    83,    81,    84,    85,   146,    88,    17,    18,
      19,    20,    21,    54,   153,    55,    56,    57,    58,    59,
      60,    50,    61,    62,    63,    64,    89,   109,    51,   161,
      52,   104,    90,   110,   130,   111,   133,   134,   136,   147,
     144,    17,    18,    19,    20,    21,    54,   148,    55,    56,
      57,    58,    59,    60,    50,    61,    62,    63,    64,   157,
     162,    51,    25,    52,   108,    48,     0,     0,    79,    80,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    54,
       0,    55,    56,    57,    58,    59,    60,    50,    61,    62,
      63,    64,     0,     0,    51,     0,    52,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,    54,     0,    55,    56,    57,    58,    59,    60,
      50,    61,    62,    63,    64,     0,     0,    51,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      17,    18,    19,    20,    21,    54,    51,    55,    56,    57,
      58,    59,    60,    50,    61,    62,    63,    64,    15,     0,
      51,   151,     0,    16,    54,     0,    55,    56,    17,    18,
      19,    20,    21,     0,     0,    74,    64,     0,    54,     0,
      55,    56,     0,     0,    22,     0,     0,     0,     0,    74,
      64,    91,     0,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,   102,   116,
     103,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,   102,   142,   106,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,   102,     0,   106,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,   107,
       0,     0,   102,     0,   106,    92,    93,    94,    95,     0,
      96,    97,    98,    99,   100,   101,     0,   137,     0,     0,
     102,     0,   106,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,   138,     0,     0,   102,     0,
     106,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,   139,     0,     0,   102,     0,   106,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
       0,   140,     0,     0,   102,     0,   106,    92,    93,    94,
      95,     0,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,   102,   141,   106,    92,    93,    94,    95,     0,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
     102,   143,   106,    92,    93,    94,    95,     0,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,   102,   145,
     106,    92,    93,    94,    95,     0,    96,    97,    98,    99,
     100,   101,     0,     0,     0,     0,   102,   154,   106,    92,
      93,    94,    95,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,   102,     0,   106,    17,    18,    19,
      20,    21,    94,    95,     0,    96,    97,    98,    99,   100,
     101,     0,     0,    22,     0,   102,     0,   106,    96,    97,
      98,    99,   100,   101,     0,     0,     0,     0,   102,     0,
     106
  };

  const short
  parser::yycheck_[] =
  {
      50,    51,     3,    17,    35,    17,    28,    45,    17,    45,
       0,    23,    62,     4,    45,    29,    30,    31,    32,    33,
      29,    30,    31,    32,    33,    24,    18,    33,    26,    20,
      18,    45,    82,    83,    84,    85,    45,    87,    28,    16,
      90,    42,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    46,    45,   139,   140,    27,    45,    52,
     110,    20,    39,    16,    45,     3,    43,    21,     9,    17,
      16,    18,   156,    18,    45,    16,    18,    18,    19,    19,
      73,    16,    16,    22,    16,    16,   136,     3,    29,    30,
      31,    32,    33,    34,   144,    36,    37,    38,    39,    40,
      41,     9,    43,    44,    45,    46,     3,    16,    16,   159,
      18,    19,     4,    20,    35,    45,     3,    17,    20,     3,
      16,    29,    30,    31,    32,    33,    34,     3,    36,    37,
      38,    39,    40,    41,     9,    43,    44,    45,    46,     3,
       3,    16,    13,    18,    19,    43,    -1,    -1,    54,    54,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,     9,    43,    44,
      45,    46,    -1,    -1,    16,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
       9,    43,    44,    45,    46,    -1,    -1,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      29,    30,    31,    32,    33,    34,    16,    36,    37,    38,
      39,    40,    41,     9,    43,    44,    45,    46,    19,    -1,
      16,    17,    -1,    24,    34,    -1,    36,    37,    29,    30,
      31,    32,    33,    -1,    -1,    45,    46,    -1,    34,    -1,
      36,    37,    -1,    -1,    45,    -1,    -1,    -1,    -1,    45,
      46,     3,    -1,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,     3,
      22,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,     3,    22,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    22,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    20,    -1,    22,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      20,    -1,    22,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    20,    -1,
      22,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    -1,    20,    -1,    22,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    20,    -1,    22,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    21,    22,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,
      22,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    21,    22,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    22,    29,    30,    31,
      32,    33,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    45,    -1,    20,    -1,    22,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      22
  };

  const signed char
  parser::yystos_[] =
  {
       0,    28,    48,    49,    45,     0,    28,    50,    18,    45,
      24,    18,    26,    52,    33,    19,    24,    29,    30,    31,
      32,    33,    45,    51,    53,    54,    64,    65,    66,    67,
      27,    64,    45,    20,    16,    45,     3,    21,    17,    16,
      18,    17,    55,    56,    64,    58,    18,    17,    55,    45,
       9,    16,    18,    19,    34,    36,    37,    38,    39,    40,
      41,    43,    44,    45,    46,    54,    57,    59,    61,    62,
      63,    68,    58,    18,    45,    68,    68,    58,    19,    65,
      66,    22,    16,    16,    16,    16,    68,    20,     3,     3,
       4,     3,     5,     6,     7,     8,    10,    11,    12,    13,
      14,    15,    20,    22,    19,    58,    22,    17,    19,    16,
      20,    45,    68,    68,    68,    68,     3,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      35,    45,    19,     3,    17,    68,    20,    17,    17,    17,
      17,    21,     3,    21,    16,    21,    68,     3,     3,    57,
      57,    17,    60,    68,    21,     3,    42,     3,    17,    23,
      57,    68,     3
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    48,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    66,    66,    66,    66,    66,    66,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,    13,     5,     1,     1,     0,     2,
       8,     9,     3,     2,     1,     2,     5,     2,     4,     6,
       8,     6,     5,     4,     3,     2,     2,     0,     2,     1,
       1,     3,     5,     6,     3,     6,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     3,     1,     1,     2,     5,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\";\"", "\"ASS\"",
  "\"MENUS\"", "\"PLUBS\"", "\"MUTLI\"", "\"DEVID\"", "\"NOT\"",
  "\"EKWAL\"", "\"NEKWAL\"", "\"LES\"", "\"BIGA\"", "\"LESOEK\"",
  "\"BIGOEK\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\".\"", "\",\"", "\"BUBLIC\"", "\"SECOOR\"", "\"STATEC\"", "\"SWAMP\"",
  "\"FROG\"", "\"NUMBA\"", "\"DUMBA\"", "\"BOOLA\"", "\"TEXTA\"",
  "\"VOEDA\"", "\"POLLIWOG\"", "\"LENA\"", "\"YES\"", "\"NO\"", "\"DIS\"",
  "\"OSETR\"", "\"CROAK\"", "\"IFF\"", "\"ELS\"", "\"LOOPA\"", "\"BURP\"",
  "\"identifier\"", "\"number\"", "$accept", "program", "main",
  "classdecl", "declaration", "declarations", "methoddecl", "vardecl",
  "formal", "formals", "statement", "statements", "locvardecl", "exprargs",
  "methinvokation", "fieldinvokation", "lvalue", "type", "typeid",
  "simpletype", "arraytype", "exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   139,   139,   140,   143,   146,   149,   150,   153,   154,
     157,   158,   161,   164,   167,   168,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   184,   185,   189,
     192,   193,   196,   197,   200,   201,   204,   205,   206,   209,
     210,   213,   216,   217,   218,   219,   220,   221,   224,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1671 "/Users/destitutiones/Desktop/Studies/CompilersCourse/CompilersCourse/03-parsers-with-ast/parser.cpp"

#line 267 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
