// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 31 "parser.y"

    #include "ForwardDeclarations.h"

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

    #include "expression/Expression.h"
    #include "expression/BinaryOpExpression.h"
    #include "expression/UnaryOpExpression.h"
    #include "expression/IntExpression.h"
    #include "expression/BoolExpression.h"
    #include "expression/StringExpression.h"
    #include "expression/DoubleExpression.h"

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

#line 88 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"


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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 182 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"


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


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 48: // exp
        value.YY_MOVE_OR_COPY< Expr::CBase* > (YY_MOVE (that.value));
        break;

      case 46: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 45: // "identifier"
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
    switch (that.type_get ())
    {
      case 48: // exp
        value.move< Expr::CBase* > (YY_MOVE (that.value));
        break;

      case 46: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 45: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 48: // exp
        value.move< Expr::CBase* > (that.value);
        break;

      case 46: // "number"
        value.move< int > (that.value);
        break;

      case 45: // "identifier"
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
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
    // State.
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
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
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
      case 48: // exp
        yylhs.value.emplace< Expr::CBase* > ();
        break;

      case 46: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 45: // "identifier"
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
  case 2:
#line 144 "parser.y"
    { /* TODO */ }
#line 642 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 3:
#line 145 "parser.y"
    { /* TODO */ }
#line 648 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 5:
#line 151 "parser.y"
    { /* TODO */ }
#line 654 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 6:
#line 154 "parser.y"
    { /* TODO */ }
#line 660 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 7:
#line 155 "parser.y"
    { /* TODO */ }
#line 666 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 8:
#line 158 "parser.y"
    { /* TODO */ }
#line 672 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 9:
#line 159 "parser.y"
    { /* TODO */ }
#line 678 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 10:
#line 162 "parser.y"
    { /* TODO */ }
#line 684 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 11:
#line 163 "parser.y"
    { /* TODO */ }
#line 690 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 12:
#line 166 "parser.y"
    { /* TODO */ }
#line 696 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 13:
#line 169 "parser.y"
    { /* TODO */ }
#line 702 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 14:
#line 172 "parser.y"
    { /* TODO */ }
#line 708 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 15:
#line 173 "parser.y"
    { /* TODO */ }
#line 714 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 16:
#line 176 "parser.y"
    { /* TODO */ }
#line 720 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 17:
#line 177 "parser.y"
    { /* TODO */ }
#line 726 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 18:
#line 178 "parser.y"
    { /* TODO */ }
#line 732 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 19:
#line 179 "parser.y"
    { /* TODO */ }
#line 738 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 20:
#line 180 "parser.y"
    { /* TODO */ }
#line 744 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 21:
#line 181 "parser.y"
    { /* TODO */ }
#line 750 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 22:
#line 182 "parser.y"
    { /* TODO */ }
#line 756 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 23:
#line 183 "parser.y"
    { /* TODO */ }
#line 762 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 24:
#line 184 "parser.y"
    { /* TODO */ }
#line 768 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 25:
#line 185 "parser.y"
    { /* TODO */ }
#line 774 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 26:
#line 186 "parser.y"
    { /* TODO */ }
#line 780 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 27:
#line 189 "parser.y"
    { /* TODO */ }
#line 786 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 28:
#line 190 "parser.y"
    { /* TODO */ }
#line 792 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 29:
#line 194 "parser.y"
    { /* TODO */ }
#line 798 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 30:
#line 197 "parser.y"
    { /* TODO */ }
#line 804 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 31:
#line 198 "parser.y"
    { /* TODO */ }
#line 810 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 32:
#line 201 "parser.y"
    { /* TODO */ }
#line 816 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 33:
#line 202 "parser.y"
    { /* TODO */ }
#line 822 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 34:
#line 205 "parser.y"
    { /* TODO */ }
#line 828 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 35:
#line 206 "parser.y"
    { /* TODO */ }
#line 834 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 36:
#line 209 "parser.y"
    { /* TODO */ }
#line 840 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 37:
#line 210 "parser.y"
    { /* TODO */ }
#line 846 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 38:
#line 211 "parser.y"
    { /* TODO */ }
#line 852 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 39:
#line 214 "parser.y"
    { /* TODO */ }
#line 858 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 40:
#line 215 "parser.y"
    { /* TODO */ }
#line 864 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 41:
#line 218 "parser.y"
    { /* TODO */ }
#line 870 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 42:
#line 221 "parser.y"
    { /* TODO */ }
#line 876 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 43:
#line 222 "parser.y"
    { /* TODO */ }
#line 882 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 44:
#line 223 "parser.y"
    { /* TODO */ }
#line 888 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 45:
#line 224 "parser.y"
    { /* TODO */ }
#line 894 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 46:
#line 225 "parser.y"
    { /* TODO */ }
#line 900 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 47:
#line 226 "parser.y"
    { /* TODO */ }
#line 906 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 48:
#line 229 "parser.y"
    { /* TODO */ }
#line 912 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 49:
#line 250 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = new Expr::CIntExpr(yystack_[0].value.as < int > ()); /* $$ = new NumberExpression($1); */}
#line 918 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 50:
#line 251 "parser.y"
    { /* $$ = new IdentExpression($1); */ }
#line 924 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 51:
#line 252 "parser.y"
    { /* TODO */ }
#line 930 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 52:
#line 253 "parser.y"
    { /* TODO */ }
#line 936 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 53:
#line 254 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = new Expr::CBoolExpr(true); }
#line 942 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 54:
#line 255 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = new Expr::CBoolExpr(false); }
#line 948 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 55:
#line 256 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = Expr::CUnaryOperation::CreateMinus(yystack_[0].value.as < Expr::CBase* > ()); }
#line 954 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 56:
#line 257 "parser.y"
    { /* TODO */ }
#line 960 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 57:
#line 258 "parser.y"
    { /* TODO */ }
#line 966 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 58:
#line 259 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = Expr::CBinaryOperation::CreateAdd(yystack_[2].value.as < Expr::CBase* > (), yystack_[0].value.as < Expr::CBase* > ()); /* $$ = new AddExpression($1, $3); */ }
#line 972 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 59:
#line 260 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = Expr::CBinaryOperation::CreateSub(yystack_[2].value.as < Expr::CBase* > (), yystack_[0].value.as < Expr::CBase* > ()); /* $$ = new SubstractExpression($1, $3); */ }
#line 978 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 60:
#line 261 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = Expr::CBinaryOperation::CreateMul(yystack_[2].value.as < Expr::CBase* > (), yystack_[0].value.as < Expr::CBase* > ()); /* $$ = new MulExpression($1, $3); */}
#line 984 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 61:
#line 262 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = Expr::CBinaryOperation::CreateDiv(yystack_[2].value.as < Expr::CBase* > (), yystack_[0].value.as < Expr::CBase* > ()); /* $$ = new DivExpression($1, $3); */ }
#line 990 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 62:
#line 263 "parser.y"
    { /* TODO */ }
#line 996 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 63:
#line 264 "parser.y"
    { /* TODO */ }
#line 1002 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 64:
#line 265 "parser.y"
    { /* TODO */ }
#line 1008 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 65:
#line 266 "parser.y"
    { /* TODO */ }
#line 1014 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 66:
#line 267 "parser.y"
    { /* TODO */ }
#line 1020 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 67:
#line 268 "parser.y"
    { /* TODO */ }
#line 1026 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 68:
#line 269 "parser.y"
    { yylhs.value.as < Expr::CBase* > () = yystack_[1].value.as < Expr::CBase* > (); }
#line 1032 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;


#line 1036 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -136;

  const signed char parser::yytable_ninf_ = -42;

  const short
  parser::yypact_[] =
  {
     -22,   -38,     3,  -136,   -10,  -136,   -34,  -136,    -5,     4,
      -3,  -136,    -9,   247,    -1,  -136,    39,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   -18,  -136,     8,  -136,
      22,     6,    59,    38,    46,    48,  -136,  -136,    57,   -15,
    -136,    60,  -136,   225,    35,    58,  -136,    65,  -136,  -136,
      20,    20,  -136,    81,    39,  -136,  -136,    84,    91,    92,
      94,    95,    20,     5,  -136,   283,  -136,  -136,   110,   113,
    -136,   114,    96,  -136,  -136,   499,   337,   129,  -136,   101,
      99,    75,    20,    20,    20,    20,   301,    20,  -136,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
     -25,  -136,  -136,    20,  -136,   162,    86,  -136,   119,   106,
      20,   104,   355,   373,   391,   409,  -136,   427,   515,   515,
     528,   528,   499,   499,   499,   499,   499,   499,   445,  -136,
     115,   319,  -136,  -136,  -136,   463,    20,   140,   141,   195,
     195,  -136,  -136,   228,  -136,  -136,   481,  -136,  -136,    10,
     143,  -136,   499,    56,  -136,  -136,   195,  -136,  -136,    20,
     146,   499,  -136
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     3,     0,     0,
       0,     8,     0,     0,     0,     5,     0,    42,    43,    45,
      44,    46,    41,     9,     7,     6,     0,    47,    39,    40,
       0,     0,     0,     0,     0,     0,    12,    48,     0,     0,
      27,     0,    14,     0,     0,     0,    27,     0,    15,    13,
       0,     0,    27,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,    50,    49,     0,    29,    28,     0,     0,
      38,     0,     0,    27,    50,    55,     0,     0,     4,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    25,     0,    10,     0,     0,    68,     0,     0,
       0,    34,     0,     0,     0,     0,    24,     0,    59,    58,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    52,
       0,     0,    11,    18,    57,     0,     0,     0,     0,     0,
       0,    37,    51,     0,    23,    56,     0,    16,    22,     0,
       0,    32,    30,     0,    35,    19,     0,    21,    33,     0,
       0,    31,    20
  };

  const short
  parser::yypgoto_[] =
  {
    -136,   -50,  -136,  -136,  -136,  -136,  -136,  -136,   137,   108,
    -136,  -135,     9,  -136,  -136,  -136,  -136,  -136,    42,    98,
     100,  -136
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    65,     2,     3,     7,    23,    13,    24,    66,    42,
      43,    67,    45,    68,   153,    69,    70,    71,    26,    27,
      28,    29
  };

  const short
  parser::yytable_[] =
  {
      75,    76,    41,     5,   149,   150,     1,     4,     8,   -36,
     129,     9,    86,   155,    17,    18,    19,    20,    21,    10,
     130,   160,    11,    12,    14,    87,    30,    32,    33,    50,
      22,     6,   112,   113,   114,   115,    51,   117,    34,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     -41,    35,   156,   131,    54,    72,    55,    56,    31,    37,
     135,    77,    36,    38,    39,    74,    64,    50,    17,    18,
      19,    20,    21,   158,    51,    40,    52,    53,    46,   159,
      49,    44,   105,    73,    22,    44,   146,    17,    18,    19,
      20,    21,    54,   152,    55,    56,    57,    58,    59,    60,
      78,    61,    62,    63,    64,    50,    81,    82,    83,   161,
      84,    85,    51,   101,    52,   104,   102,   109,   103,   110,
     111,   129,   133,   134,   136,    17,    18,    19,    20,    21,
      54,   143,    55,    56,    57,    58,    59,    60,    50,    61,
      62,    63,    64,   147,   148,    51,   157,    52,   108,   162,
      25,    48,    79,     0,    80,     0,     0,     0,    17,    18,
      19,    20,    21,    54,     0,    55,    56,    57,    58,    59,
      60,    50,    61,    62,    63,    64,     0,     0,    51,     0,
      52,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    54,     0,    55,    56,
      57,    58,    59,    60,    50,    61,    62,    63,    64,     0,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    54,
       0,    55,    56,    57,    58,    59,    60,    50,    61,    62,
      63,    64,    47,     0,    51,   151,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
       0,     0,    54,     0,    55,    56,    15,     0,     0,     0,
      22,    16,     0,    74,    64,     0,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,    22,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,    99,   116,   100,    89,    90,    91,    92,
       0,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,    99,   144,   106,    89,    90,    91,    92,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,    99,
       0,   106,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,     0,   107,     0,     0,    99,     0,   106,
      89,    90,    91,    92,     0,    93,    94,    95,    96,    97,
      98,     0,   137,     0,     0,    99,     0,   106,    89,    90,
      91,    92,     0,    93,    94,    95,    96,    97,    98,     0,
     138,     0,     0,    99,     0,   106,    89,    90,    91,    92,
       0,    93,    94,    95,    96,    97,    98,     0,   139,     0,
       0,    99,     0,   106,    89,    90,    91,    92,     0,    93,
      94,    95,    96,    97,    98,     0,   140,     0,     0,    99,
       0,   106,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,    99,   141,   106,
      89,    90,    91,    92,     0,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,   142,   106,    89,    90,
      91,    92,     0,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,    99,   145,   106,    89,    90,    91,    92,
       0,    93,    94,    95,    96,    97,    98,     0,     0,     0,
       0,    99,   154,   106,    89,    90,    91,    92,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,    99,
       0,   106,    91,    92,     0,    93,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,     0,   106,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,    99,     0,
     106
  };

  const short
  parser::yycheck_[] =
  {
      50,    51,    17,     0,   139,   140,    28,    45,    18,     4,
      35,    45,    62,     3,    29,    30,    31,    32,    33,    24,
      45,   156,    18,    26,    33,    20,    27,    45,    20,     9,
      45,    28,    82,    83,    84,    85,    16,    87,    16,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      45,    45,    42,   103,    34,    46,    36,    37,    16,    21,
     110,    52,     3,    17,    16,    45,    46,     9,    29,    30,
      31,    32,    33,    17,    16,    18,    18,    19,    18,    23,
      45,    39,    73,    18,    45,    43,   136,    29,    30,    31,
      32,    33,    34,   143,    36,    37,    38,    39,    40,    41,
      19,    43,    44,    45,    46,     9,    22,    16,    16,   159,
      16,    16,    16,     3,    18,    19,     3,    16,     4,    20,
      45,    35,     3,    17,    20,    29,    30,    31,    32,    33,
      34,    16,    36,    37,    38,    39,    40,    41,     9,    43,
      44,    45,    46,     3,     3,    16,     3,    18,    19,     3,
      13,    43,    54,    -1,    54,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,     9,    43,    44,    45,    46,    -1,    -1,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,     9,    43,    44,    45,    46,    -1,
      -1,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,     9,    43,    44,
      45,    46,    17,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    34,    -1,    36,    37,    19,    -1,    -1,    -1,
      45,    24,    -1,    45,    46,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,    45,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,     3,    22,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,     3,    22,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      -1,    22,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    -1,    22,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    -1,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    -1,    22,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    -1,    22,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    20,
      -1,    22,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    21,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      -1,    22,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    22,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      22
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    28,    49,    50,    45,     0,    28,    51,    18,    45,
      24,    18,    26,    53,    33,    19,    24,    29,    30,    31,
      32,    33,    45,    52,    54,    55,    65,    66,    67,    68,
      27,    65,    45,    20,    16,    45,     3,    21,    17,    16,
      18,    17,    56,    57,    65,    59,    18,    17,    56,    45,
       9,    16,    18,    19,    34,    36,    37,    38,    39,    40,
      41,    43,    44,    45,    46,    48,    55,    58,    60,    62,
      63,    64,    59,    18,    45,    48,    48,    59,    19,    66,
      67,    22,    16,    16,    16,    16,    48,    20,     3,     5,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    20,
      22,     3,     3,     4,    19,    59,    22,    17,    19,    16,
      20,    45,    48,    48,    48,    48,     3,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    35,
      45,    48,    19,     3,    17,    48,    20,    17,    17,    17,
      17,    21,    21,    16,     3,    21,    48,     3,     3,    58,
      58,    17,    48,    61,    21,     3,    42,     3,    17,    23,
      58,    48,     3
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    47,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    66,    67,    67,    67,    67,    67,    67,    68,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48
  };

  const unsigned char
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



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\";\"", "\"ASS\"",
  "\"MENUS\"", "\"PLUBS\"", "\"MUTLI\"", "\"DEVID\"", "\"NOT\"",
  "\"EKWAL\"", "\"NEKWAL\"", "\"LES\"", "\"BIGA\"", "\"LESOEK\"",
  "\"BIGOEK\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\".\"", "\",\"", "\"BUBLIC\"", "\"SECOOR\"", "\"STATEC\"", "\"SWAMP\"",
  "\"FROG\"", "\"NUMBA\"", "\"DUMBA\"", "\"BOOLA\"", "\"TEXTA\"",
  "\"VOEDA\"", "\"POLLIWOG\"", "\"LENA\"", "\"YES\"", "\"NO\"", "\"DIS\"",
  "\"OSETR\"", "\"CROAK\"", "\"IFF\"", "\"ELS\"", "\"LOOPA\"", "\"BURP\"",
  "\"identifier\"", "\"number\"", "$accept", "exp", "program", "main",
  "classdecl", "declaration", "declarations", "methoddecl", "vardecl",
  "formal", "formals", "statement", "statements", "locvardecl", "exprargs",
  "methinvokation", "fieldinvokation", "lvalue", "type", "typeid",
  "simpletype", "arraytype", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   144,   144,   145,   148,   151,   154,   155,   158,   159,
     162,   163,   166,   169,   172,   173,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   189,   190,   194,
     197,   198,   201,   202,   205,   206,   209,   210,   211,   214,
     215,   218,   221,   222,   223,   224,   225,   226,   229,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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
#line 1605 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"

#line 272 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
