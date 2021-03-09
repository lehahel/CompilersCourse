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
#line 30 "parser.y"

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

#line 78 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"


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
#line 172 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"


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
      case 49: // assignment
        value.YY_MOVE_OR_COPY< Assignment* > (YY_MOVE (that.value));
        break;

      case 50: // assignments
        value.YY_MOVE_OR_COPY< AssignmentList* > (YY_MOVE (that.value));
        break;

      case 48: // exp
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case 51: // unit
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
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
      case 49: // assignment
        value.move< Assignment* > (YY_MOVE (that.value));
        break;

      case 50: // assignments
        value.move< AssignmentList* > (YY_MOVE (that.value));
        break;

      case 48: // exp
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case 51: // unit
        value.move< Program* > (YY_MOVE (that.value));
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
      case 49: // assignment
        value.move< Assignment* > (that.value);
        break;

      case 50: // assignments
        value.move< AssignmentList* > (that.value);
        break;

      case 48: // exp
        value.move< Expression* > (that.value);
        break;

      case 51: // unit
        value.move< Program* > (that.value);
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
      case 49: // assignment
        yylhs.value.emplace< Assignment* > ();
        break;

      case 50: // assignments
        yylhs.value.emplace< AssignmentList* > ();
        break;

      case 48: // exp
        yylhs.value.emplace< Expression* > ();
        break;

      case 51: // unit
        yylhs.value.emplace< Program* > ();
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
#line 133 "parser.y"
    { /* TODO */ }
#line 680 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 3:
#line 134 "parser.y"
    { /* TODO */ }
#line 686 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 5:
#line 140 "parser.y"
    { /* TODO */ }
#line 692 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 6:
#line 143 "parser.y"
    { /* TODO */ }
#line 698 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 7:
#line 144 "parser.y"
    { /* TODO */ }
#line 704 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 8:
#line 147 "parser.y"
    { /* TODO */ }
#line 710 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 9:
#line 148 "parser.y"
    { /* TODO */ }
#line 716 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 10:
#line 151 "parser.y"
    { /* TODO */ }
#line 722 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 11:
#line 152 "parser.y"
    { /* TODO */ }
#line 728 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 12:
#line 155 "parser.y"
    { /* TODO */ }
#line 734 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 13:
#line 158 "parser.y"
    { /* TODO */ }
#line 740 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 14:
#line 161 "parser.y"
    { /* TODO */ }
#line 746 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 15:
#line 162 "parser.y"
    { /* TODO */ }
#line 752 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 16:
#line 165 "parser.y"
    { /* TODO */ }
#line 758 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 17:
#line 166 "parser.y"
    { /* TODO */ }
#line 764 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 18:
#line 167 "parser.y"
    { /* TODO */ }
#line 770 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 19:
#line 168 "parser.y"
    { /* TODO */ }
#line 776 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 20:
#line 169 "parser.y"
    { /* TODO */ }
#line 782 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 21:
#line 170 "parser.y"
    { /* TODO */ }
#line 788 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 22:
#line 171 "parser.y"
    { /* TODO */ }
#line 794 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 23:
#line 172 "parser.y"
    { /* TODO */ }
#line 800 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 24:
#line 173 "parser.y"
    { /* TODO */ }
#line 806 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 25:
#line 174 "parser.y"
    { /* TODO */ }
#line 812 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 26:
#line 177 "parser.y"
    { /* TODO */ }
#line 818 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 27:
#line 178 "parser.y"
    { /* TODO */ }
#line 824 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 28:
#line 182 "parser.y"
    { /* TODO */ }
#line 830 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 29:
#line 185 "parser.y"
    { /* TODO */ }
#line 836 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 30:
#line 186 "parser.y"
    { /* TODO */ }
#line 842 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 31:
#line 189 "parser.y"
    { /* TODO */ }
#line 848 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 32:
#line 190 "parser.y"
    { /* TODO */ }
#line 854 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 33:
#line 193 "parser.y"
    { /* TODO */ }
#line 860 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 34:
#line 194 "parser.y"
    { /* TODO */ }
#line 866 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 35:
#line 197 "parser.y"
    { /* TODO */ }
#line 872 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 36:
#line 198 "parser.y"
    { /* TODO */ }
#line 878 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 37:
#line 199 "parser.y"
    { /* TODO */ }
#line 884 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 38:
#line 202 "parser.y"
    { /* TODO */ }
#line 890 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 39:
#line 203 "parser.y"
    { /* TODO */ }
#line 896 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 40:
#line 206 "parser.y"
    { /* TODO */ }
#line 902 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 41:
#line 209 "parser.y"
    { /* TODO */ }
#line 908 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 42:
#line 210 "parser.y"
    { /* TODO */ }
#line 914 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 43:
#line 211 "parser.y"
    { /* TODO */ }
#line 920 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 44:
#line 212 "parser.y"
    { /* TODO */ }
#line 926 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 45:
#line 213 "parser.y"
    { /* TODO */ }
#line 932 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 46:
#line 214 "parser.y"
    { /* TODO */ }
#line 938 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 47:
#line 217 "parser.y"
    { /* TODO */ }
#line 944 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 48:
#line 219 "parser.y"
    { yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < AssignmentList* > (), yystack_[0].value.as < Expression* > ()); driver.program = yylhs.value.as < Program* > (); }
#line 950 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 49:
#line 222 "parser.y"
    { yylhs.value.as < AssignmentList* > () = new AssignmentList(); /* A -> eps */}
#line 956 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 50:
#line 223 "parser.y"
    {
        yystack_[2].value.as < AssignmentList* > ()->AddAssignment(yystack_[1].value.as < Assignment* > ()); yylhs.value.as < AssignmentList* > () = yystack_[2].value.as < AssignmentList* > ();
    }
#line 964 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 51:
#line 228 "parser.y"
    {
        yylhs.value.as < Assignment* > () = new Assignment(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Expression* > ());
        driver.variables[yystack_[2].value.as < std::string > ()] = yystack_[0].value.as < Expression* > ()->eval(driver);
    }
#line 973 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 52:
#line 237 "parser.y"
    { yylhs.value.as < Expression* > () = new NumberExpression(yystack_[0].value.as < int > ());}
#line 979 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 53:
#line 238 "parser.y"
    { yylhs.value.as < Expression* > () = new IdentExpression(yystack_[0].value.as < std::string > ()); }
#line 985 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 54:
#line 239 "parser.y"
    { /* TODO */ }
#line 991 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 55:
#line 240 "parser.y"
    { /* TODO */ }
#line 997 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 56:
#line 241 "parser.y"
    { /* TODO */ }
#line 1003 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 57:
#line 242 "parser.y"
    { /* TODO */ }
#line 1009 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 58:
#line 243 "parser.y"
    { /* TODO */ }
#line 1015 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 59:
#line 244 "parser.y"
    { /* TODO */ }
#line 1021 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 60:
#line 245 "parser.y"
    { /* TODO */ }
#line 1027 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 61:
#line 246 "parser.y"
    { yylhs.value.as < Expression* > () = new AddExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1033 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 62:
#line 247 "parser.y"
    { yylhs.value.as < Expression* > () = new SubstractExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1039 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 63:
#line 248 "parser.y"
    { yylhs.value.as < Expression* > () = new MulExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1045 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 64:
#line 249 "parser.y"
    { yylhs.value.as < Expression* > () = new DivExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > ()); }
#line 1051 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 65:
#line 250 "parser.y"
    { /* TODO */ }
#line 1057 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 66:
#line 251 "parser.y"
    { /* TODO */ }
#line 1063 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 67:
#line 252 "parser.y"
    { /* TODO */ }
#line 1069 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 68:
#line 253 "parser.y"
    { /* TODO */ }
#line 1075 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 69:
#line 254 "parser.y"
    { /* TODO */ }
#line 1081 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 70:
#line 255 "parser.y"
    { /* TODO */ }
#line 1087 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;

  case 71:
#line 256 "parser.y"
    { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1093 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"
    break;


#line 1097 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"

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


  const short parser::yypact_ninf_ = -144;

  const signed char parser::yytable_ninf_ = -41;

  const short
  parser::yypact_[] =
  {
     -24,   -40,     9,  -144,   -10,  -144,   -33,  -144,   -11,     3,
      15,  -144,    11,   221,    19,  -144,   467,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,     4,  -144,    31,  -144,
      36,     8,    51,    35,    38,    43,  -144,  -144,    42,   197,
    -144,    44,  -144,   204,    16,    34,    45,  -144,    48,  -144,
    -144,    49,    49,   467,  -144,  -144,    65,  -144,   455,    69,
      58,    80,  -144,  -144,   455,   293,    66,    64,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      52,  -144,  -144,  -144,  -144,    68,    72,    75,    76,    77,
      49,    -3,   473,  -144,  -144,  -144,    97,  -144,    98,   113,
    -144,    84,    49,   455,   494,   494,   507,   507,   455,   455,
     455,   455,   455,   455,   311,  -144,   146,    59,    49,    49,
      49,    49,   257,    49,   -25,  -144,    49,  -144,  -144,   329,
    -144,  -144,    85,   347,   365,   383,   401,  -144,   419,    90,
     275,  -144,    49,  -144,   104,   179,   179,  -144,     2,  -144,
     437,  -144,    86,  -144,  -144,   455,    -1,  -144,   179,  -144,
      49,  -144,   455
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     3,     0,     0,
       0,     8,     0,     0,     0,     5,     0,    41,    42,    44,
      43,    45,    40,     9,     7,     6,     0,    46,    38,    39,
       0,     0,     0,     0,     0,     0,    12,    47,     0,     0,
      49,     0,    14,     0,     0,     0,     0,    26,     0,    15,
      13,     0,     0,     0,    56,    57,    53,    52,    48,     0,
       0,     0,    26,    53,    58,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     4,    26,    10,     0,     0,     0,     0,     0,
       0,    53,     0,    28,    27,    17,     0,    37,     0,     0,
      71,     0,     0,    51,    62,    61,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,    11,    60,     0,
      54,    18,    33,     0,     0,     0,     0,    24,     0,     0,
       0,    59,     0,    16,     0,     0,     0,    36,     0,    23,
       0,    22,    19,    21,    31,    29,     0,    34,     0,    32,
       0,    20,    30
  };

  const short
  parser::yypgoto_[] =
  {
    -144,   -45,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,    95,    87,  -144,  -143,   -48,  -144,  -144,  -144,  -144,
    -144,    24,    74,    81,  -144
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    92,    59,    45,    46,     2,     3,     7,    23,    13,
      24,    93,    42,    43,    94,    61,    95,   156,    96,    97,
      98,    26,    27,    28,    29
  };

  const short
  parser::yytable_[] =
  {
      58,   -35,   152,   153,     1,     4,    64,    65,     8,     5,
     115,    51,     9,    10,    99,   161,   159,   123,    52,   154,
     139,    11,   160,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,    53,     6,    54,    55,
      31,    12,   -40,    51,    14,   122,    30,    63,    57,    32,
      52,    33,    34,    35,    36,    38,    37,   129,    51,    39,
      40,    50,    47,    44,    60,    52,    62,    44,    53,    68,
      54,    55,    81,   133,   134,   135,   136,    82,   138,    56,
      57,   140,   101,    53,   102,    54,    55,   115,   118,    51,
     117,   119,   120,   121,    63,    57,    52,   150,    83,    84,
     125,   128,   126,   155,   132,   142,   148,   151,    25,    17,
      18,    19,    20,    21,    53,   162,    54,    55,    85,    86,
      87,    88,    51,    89,    90,    91,    57,    66,   158,    52,
      49,    83,   127,     0,    67,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    53,     0,    54,
      55,    85,    86,    87,    88,    51,    89,    90,    91,    57,
       0,     0,    52,     0,    83,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      53,     0,    54,    55,    85,    86,    87,    88,    51,    89,
      90,    91,    57,     0,     0,    52,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    53,    41,    54,    55,    85,    86,    87,
      88,    48,    89,    90,    91,    57,    17,    18,    19,    20,
      21,     0,     0,    17,    18,    19,    20,    21,     0,     0,
      15,     0,    22,     0,     0,    16,     0,     0,     0,    22,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
     137,     0,    69,    70,    71,    72,    22,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,    79,   149,    80,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,    79,     0,    80,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,     0,
     100,     0,     0,    79,     0,    80,    69,    70,    71,    72,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,    79,   130,    80,    69,    70,    71,    72,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,    79,
     141,    80,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,   143,     0,     0,    79,     0,    80,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,     0,   144,     0,     0,    79,     0,    80,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,     0,
     145,     0,     0,    79,     0,    80,    69,    70,    71,    72,
       0,    73,    74,    75,    76,    77,    78,     0,   146,     0,
       0,    79,     0,    80,    69,    70,    71,    72,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,    79,
     147,    80,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,    79,   157,    80,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,    79,     0,    80,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    79,     0,   124,    17,    18,    19,    20,
      21,    71,    72,     0,    73,    74,    75,    76,    77,    78,
       0,     0,    22,     0,    79,     0,    80,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,    79,     0,    80
  };

  const short
  parser::yycheck_[] =
  {
      45,     4,   145,   146,    28,    45,    51,    52,    18,     0,
      35,     9,    45,    24,    62,   158,    17,    20,    16,    17,
      45,    18,    23,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    83,    34,    28,    36,    37,
      16,    26,    45,     9,    33,    90,    27,    45,    46,    45,
      16,    20,    16,    45,     3,    17,    21,   102,     9,    16,
      18,    45,    18,    39,    19,    16,    18,    43,    34,     4,
      36,    37,     3,   118,   119,   120,   121,    19,   123,    45,
      46,   126,    16,    34,    20,    36,    37,    35,    16,     9,
      22,    16,    16,    16,    45,    46,    16,   142,    18,    19,
       3,    17,     4,   148,    45,    20,    16,     3,    13,    29,
      30,    31,    32,    33,    34,   160,    36,    37,    38,    39,
      40,    41,     9,    43,    44,    45,    46,    53,    42,    16,
      43,    18,    19,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,     9,    43,    44,    45,    46,
      -1,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,     9,    43,
      44,    45,    46,    -1,    -1,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    17,    36,    37,    38,    39,    40,
      41,    17,    43,    44,    45,    46,    29,    30,    31,    32,
      33,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      19,    -1,    45,    -1,    -1,    24,    -1,    -1,    -1,    45,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,    45,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,     3,    22,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    -1,    22,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    -1,    22,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    -1,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    -1,    22,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    -1,    22,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    22,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    22,    29,    30,    31,    32,
      33,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    45,    -1,    20,    -1,    22,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    22
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    28,    52,    53,    45,     0,    28,    54,    18,    45,
      24,    18,    26,    56,    33,    19,    24,    29,    30,    31,
      32,    33,    45,    55,    57,    58,    68,    69,    70,    71,
      27,    68,    45,    20,    16,    45,     3,    21,    17,    16,
      18,    17,    59,    60,    68,    50,    51,    18,    17,    59,
      45,     9,    16,    34,    36,    37,    45,    46,    48,    49,
      19,    62,    18,    45,    48,    48,    69,    70,     4,     5,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    20,
      22,     3,    19,    18,    19,    38,    39,    40,    41,    43,
      44,    45,    48,    58,    61,    63,    65,    66,    67,    62,
      17,    16,    20,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    35,    62,    22,    16,    16,
      16,    16,    48,    20,    22,     3,     4,    19,    17,    48,
      21,    19,    45,    48,    48,    48,    48,     3,    48,    45,
      48,    21,    20,    17,    17,    17,    17,    21,    16,     3,
      48,     3,    61,    61,    17,    48,    64,    21,    42,    17,
      23,    61,    48
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    47,    52,    52,    53,    54,    55,    55,    56,    56,
      57,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    70,    70,    71,    51,    50,
      50,    49,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,    13,     5,     1,     1,     0,     2,
       8,     9,     3,     2,     1,     2,     4,     1,     3,     5,
       7,     5,     5,     4,     3,     2,     0,     2,     1,     1,
       3,     5,     6,     3,     6,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     0,
       3,     3,     1,     1,     4,     3,     1,     1,     2,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
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
  "\"identifier\"", "\"number\"", "$accept", "exp", "assignment",
  "assignments", "unit", "program", "main", "classdecl", "declaration",
  "declarations", "methoddecl", "vardecl", "formal", "formals",
  "statement", "statements", "locvardecl", "exprargs", "methinvokation",
  "fieldinvokation", "lvalue", "type", "typeid", "simpletype", "arraytype", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   133,   133,   134,   137,   140,   143,   144,   147,   148,
     151,   152,   155,   158,   161,   162,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   177,   178,   182,   185,
     186,   189,   190,   193,   194,   197,   198,   199,   202,   203,
     206,   209,   210,   211,   212,   213,   214,   217,   219,   222,
     223,   228,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256
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
#line 1663 "/home/lehahel/CompilersCourse/03-parsers-with-ast/parser.cpp"

#line 259 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
