// A Bison parser, made by GNU Bison 3.8.2.

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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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





#include "parser.hpp"


// Unqualified %code blocks.
#line 26 "grammar/parser.ypp"

#include "driver.hpp"

#line 50 "src/parser.cpp"


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
#line 142 "src/parser.cpp"

  /// Build a parser object.
  parser::parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



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
      case symbol_kind::S_decl: // decl
        value.YY_MOVE_OR_COPY< Decl * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param: // param
        value.YY_MOVE_OR_COPY< Param * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< Stmt * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< Type * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<Expr *> * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
        value.YY_MOVE_OR_COPY< std::vector<Param *> * > (YY_MOVE (that.value));
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
      case symbol_kind::S_decl: // decl
        value.move< Decl * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expr * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param: // param
        value.move< Param * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
        value.move< Stmt * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< Type * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<Expr *> * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
        value.move< std::vector<Param *> * > (YY_MOVE (that.value));
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
      case symbol_kind::S_decl: // decl
        value.copy< Decl * > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.copy< Expr * > (that.value);
        break;

      case symbol_kind::S_param: // param
        value.copy< Param * > (that.value);
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
        value.copy< Stmt * > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< Type * > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.copy< std::vector<Expr *> * > (that.value);
        break;

      case symbol_kind::S_params: // params
        value.copy< std::vector<Param *> * > (that.value);
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
      case symbol_kind::S_decl: // decl
        value.move< Decl * > (that.value);
        break;

      case symbol_kind::S_expr: // expr
        value.move< Expr * > (that.value);
        break;

      case symbol_kind::S_param: // param
        value.move< Param * > (that.value);
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
        value.move< Stmt * > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< Type * > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<Expr *> * > (that.value);
        break;

      case symbol_kind::S_params: // params
        value.move< std::vector<Param *> * > (that.value);
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
        switch (yykind)
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < std::string > (); }
#line 466 "src/parser.cpp"
        break;

      case symbol_kind::S_STRING: // "string"
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < std::string > (); }
#line 472 "src/parser.cpp"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < int > (); }
#line 478 "src/parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // "float"
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < float > (); }
#line 484 "src/parser.cpp"
        break;

      case symbol_kind::S_decl: // decl
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Decl * > (); }
#line 490 "src/parser.cpp"
        break;

      case symbol_kind::S_params: // params
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < std::vector<Param *> * > (); }
#line 496 "src/parser.cpp"
        break;

      case symbol_kind::S_param: // param
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Param * > (); }
#line 502 "src/parser.cpp"
        break;

      case symbol_kind::S_type: // type
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Type * > (); }
#line 508 "src/parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Expr * > (); }
#line 514 "src/parser.cpp"
        break;

      case symbol_kind::S_args: // args
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < std::vector<Expr *> * > (); }
#line 520 "src/parser.cpp"
        break;

      case symbol_kind::S_block: // block
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Stmt * > (); }
#line 526 "src/parser.cpp"
        break;

      case symbol_kind::S_stmts: // stmts
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Stmt * > (); }
#line 532 "src/parser.cpp"
        break;

      case symbol_kind::S_stmt: // stmt
#line 90 "grammar/parser.ypp"
                 { yyo << yysym.value.template as < Stmt * > (); }
#line 538 "src/parser.cpp"
        break;

      default:
        break;
    }
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (drv));
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      case symbol_kind::S_decl: // decl
        yylhs.value.emplace< Decl * > ();
        break;

      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Expr * > ();
        break;

      case symbol_kind::S_param: // param
        yylhs.value.emplace< Param * > ();
        break;

      case symbol_kind::S_block: // block
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< Stmt * > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< Type * > ();
        break;

      case symbol_kind::S_FLOAT: // "float"
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRING: // "string"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<Expr *> * > ();
        break;

      case symbol_kind::S_params: // params
        yylhs.value.emplace< std::vector<Param *> * > ();
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
  case 2: // decls: %empty
#line 95 "grammar/parser.ypp"
             {}
#line 844 "src/parser.cpp"
    break;

  case 3: // decls: decls decl
#line 96 "grammar/parser.ypp"
             { drv.ast.push_back(yystack_[0].value.as < Decl * > ()); }
#line 850 "src/parser.cpp"
    break;

  case 4: // decl: "fn" "identifier" "(" params ")" block
#line 99 "grammar/parser.ypp"
                                              { yylhs.value.as < Decl * > () = Decl::newFn(yystack_[4].value.as < std::string > (), yystack_[0].value.as < Stmt * > (), Type::newComplex(TypeKind::FUNC, Type::newAtomic(TypeKind::NIL), yystack_[2].value.as < std::vector<Param *> * > ())); }
#line 856 "src/parser.cpp"
    break;

  case 5: // decl: "fn" "identifier" "(" params ")" type block
#line 100 "grammar/parser.ypp"
                                              { yylhs.value.as < Decl * > () = Decl::newFn(yystack_[5].value.as < std::string > (), yystack_[0].value.as < Stmt * > (), Type::newComplex(TypeKind::FUNC, yystack_[1].value.as < Type * > (), yystack_[3].value.as < std::vector<Param *> * > ())); }
#line 862 "src/parser.cpp"
    break;

  case 6: // decl: type "identifier" "=" expr ";"
#line 101 "grammar/parser.ypp"
                                              { yylhs.value.as < Decl * > () = Decl::newVar(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expr * > (), yystack_[4].value.as < Type * > ()); }
#line 868 "src/parser.cpp"
    break;

  case 7: // decl: type "identifier" ";"
#line 102 "grammar/parser.ypp"
                                              { yylhs.value.as < Decl * > () = Decl::newVar(yystack_[1].value.as < std::string > (), 0, yystack_[2].value.as < Type * > ()); }
#line 874 "src/parser.cpp"
    break;

  case 8: // params: %empty
#line 105 "grammar/parser.ypp"
                   { yylhs.value.as < std::vector<Param *> * > () = new std::vector<Param *>(); }
#line 880 "src/parser.cpp"
    break;

  case 9: // params: param
#line 106 "grammar/parser.ypp"
                   { yylhs.value.as < std::vector<Param *> * > () = new std::vector<Param *>(); yylhs.value.as < std::vector<Param *> * > ()->push_back(yystack_[0].value.as < Param * > ()); }
#line 886 "src/parser.cpp"
    break;

  case 10: // params: params "," param
#line 107 "grammar/parser.ypp"
                   { yylhs.value.as < std::vector<Param *> * > () = yystack_[2].value.as < std::vector<Param *> * > (); yystack_[2].value.as < std::vector<Param *> * > ()->push_back(yystack_[0].value.as < Param * > ()); }
#line 892 "src/parser.cpp"
    break;

  case 11: // param: type "identifier"
#line 110 "grammar/parser.ypp"
                    { yylhs.value.as < Param * > () = Param::newParam(yystack_[0].value.as < std::string > (), yystack_[1].value.as < Type * > ()); }
#line 898 "src/parser.cpp"
    break;

  case 12: // type: type "[" "]"
#line 113 "grammar/parser.ypp"
               { yylhs.value.as < Type * > () = Type::newArray(yystack_[2].value.as < Type * > ()); }
#line 904 "src/parser.cpp"
    break;

  case 13: // type: "int"
#line 114 "grammar/parser.ypp"
        { yylhs.value.as < Type * > () = Type::newAtomic(TypeKind::INT); }
#line 910 "src/parser.cpp"
    break;

  case 14: // type: "str"
#line 115 "grammar/parser.ypp"
        { yylhs.value.as < Type * > () = Type::newAtomic(TypeKind::STR); }
#line 916 "src/parser.cpp"
    break;

  case 15: // expr: "integer"
#line 120 "grammar/parser.ypp"
            { yylhs.value.as < Expr * > () = Expr::newConst(yystack_[0].value.as < int > ()); }
#line 922 "src/parser.cpp"
    break;

  case 16: // expr: "string"
#line 121 "grammar/parser.ypp"
            { yylhs.value.as < Expr * > () = Expr::newConst(yystack_[0].value.as < std::string > ()); }
#line 928 "src/parser.cpp"
    break;

  case 17: // expr: "identifier" "=" expr
#line 123 "grammar/parser.ypp"
                        { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::ASSIGN, Expr::newIdent(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < Expr * > ()); }
#line 934 "src/parser.cpp"
    break;

  case 18: // expr: "not" expr
#line 125 "grammar/parser.ypp"
                  { yylhs.value.as < Expr * > () = Expr::newUnary(ExprKind::LNOT, yystack_[0].value.as < Expr * > ()); }
#line 940 "src/parser.cpp"
    break;

  case 19: // expr: expr "and" expr
#line 126 "grammar/parser.ypp"
                  { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::LAND, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 946 "src/parser.cpp"
    break;

  case 20: // expr: expr "or" expr
#line 127 "grammar/parser.ypp"
                  { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::LOR, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 952 "src/parser.cpp"
    break;

  case 21: // expr: expr "==" expr
#line 129 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::EQ, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 958 "src/parser.cpp"
    break;

  case 22: // expr: expr "!=" expr
#line 130 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::NE, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 964 "src/parser.cpp"
    break;

  case 23: // expr: expr "<=" expr
#line 131 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::LTEQ, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 970 "src/parser.cpp"
    break;

  case 24: // expr: expr ">=" expr
#line 132 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::GTEQ, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 976 "src/parser.cpp"
    break;

  case 25: // expr: expr "<" expr
#line 133 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::LT, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 982 "src/parser.cpp"
    break;

  case 26: // expr: expr ">" expr
#line 134 "grammar/parser.ypp"
                 { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::GT, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 988 "src/parser.cpp"
    break;

  case 27: // expr: expr "&" expr
#line 136 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::AND, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 994 "src/parser.cpp"
    break;

  case 28: // expr: expr "|" expr
#line 137 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::OR, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1000 "src/parser.cpp"
    break;

  case 29: // expr: expr "^" expr
#line 138 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::XOR, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1006 "src/parser.cpp"
    break;

  case 30: // expr: expr "+" expr
#line 139 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::ADD, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1012 "src/parser.cpp"
    break;

  case 31: // expr: expr "-" expr
#line 140 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::SUB, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1018 "src/parser.cpp"
    break;

  case 32: // expr: expr "*" expr
#line 141 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::MUL, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1024 "src/parser.cpp"
    break;

  case 33: // expr: expr "/" expr
#line 142 "grammar/parser.ypp"
                { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::DIV, yystack_[2].value.as < Expr * > (), yystack_[0].value.as < Expr * > ()); }
#line 1030 "src/parser.cpp"
    break;

  case 34: // expr: "~" expr
#line 144 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newUnary(ExprKind::NOT, yystack_[0].value.as < Expr * > ()); }
#line 1036 "src/parser.cpp"
    break;

  case 35: // expr: "identifier" "++"
#line 145 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newUnary(ExprKind::INC, Expr::newIdent(yystack_[1].value.as < std::string > ())); }
#line 1042 "src/parser.cpp"
    break;

  case 36: // expr: "identifier" "--"
#line 146 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newUnary(ExprKind::DEC, Expr::newIdent(yystack_[1].value.as < std::string > ())); }
#line 1048 "src/parser.cpp"
    break;

  case 37: // expr: "(" expr ")"
#line 147 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = yystack_[1].value.as < Expr * > (); }
#line 1054 "src/parser.cpp"
    break;

  case 38: // expr: "identifier" "[" expr "]"
#line 148 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::INDEX, Expr::newIdent(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < Expr * > ()); }
#line 1060 "src/parser.cpp"
    break;

  case 39: // expr: "identifier" "(" args ")"
#line 149 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newBinary(ExprKind::CALL, Expr::newIdent(yystack_[3].value.as < std::string > ()), Expr::newArgs(yystack_[1].value.as < std::vector<Expr *> * > ())); }
#line 1066 "src/parser.cpp"
    break;

  case 40: // expr: "identifier"
#line 150 "grammar/parser.ypp"
                            { yylhs.value.as < Expr * > () = Expr::newIdent(yystack_[0].value.as < std::string > ()); }
#line 1072 "src/parser.cpp"
    break;

  case 41: // args: %empty
#line 153 "grammar/parser.ypp"
                { yylhs.value.as < std::vector<Expr *> * > () = new std::vector<Expr *>(); }
#line 1078 "src/parser.cpp"
    break;

  case 42: // args: expr
#line 154 "grammar/parser.ypp"
                { yylhs.value.as < std::vector<Expr *> * > () = new std::vector<Expr *>(); yylhs.value.as < std::vector<Expr *> * > ()->push_back(yystack_[0].value.as < Expr * > ()); }
#line 1084 "src/parser.cpp"
    break;

  case 43: // args: args "," expr
#line 155 "grammar/parser.ypp"
                { yylhs.value.as < std::vector<Expr *> * > () = yystack_[2].value.as < std::vector<Expr *> * > (); yystack_[2].value.as < std::vector<Expr *> * > ()->push_back(yystack_[0].value.as < Expr * > ()); }
#line 1090 "src/parser.cpp"
    break;

  case 44: // block: "{" stmts "}"
#line 158 "grammar/parser.ypp"
                { yylhs.value.as < Stmt * > () = yystack_[1].value.as < Stmt * > (); }
#line 1096 "src/parser.cpp"
    break;

  case 45: // stmts: %empty
#line 161 "grammar/parser.ypp"
             { yylhs.value.as < Stmt * > () = Stmt::newBlock(); }
#line 1102 "src/parser.cpp"
    break;

  case 46: // stmts: stmts stmt
#line 162 "grammar/parser.ypp"
             { yylhs.value.as < Stmt * > () = yystack_[1].value.as < Stmt * > (); yylhs.value.as < Stmt * > ()->addChild(yystack_[0].value.as < Stmt * > ()); }
#line 1108 "src/parser.cpp"
    break;

  case 47: // stmt: decl
#line 165 "grammar/parser.ypp"
           { yylhs.value.as < Stmt * > () = Stmt::newDecl(yystack_[0].value.as < Decl * > ()); }
#line 1114 "src/parser.cpp"
    break;

  case 48: // stmt: expr ";"
#line 166 "grammar/parser.ypp"
           { yylhs.value.as < Stmt * > () = Stmt::newExpr(yystack_[1].value.as < Expr * > ()); }
#line 1120 "src/parser.cpp"
    break;

  case 49: // stmt: "return" expr ";"
#line 168 "grammar/parser.ypp"
                    { yylhs.value.as < Stmt * > () = Stmt::newReturn(yystack_[1].value.as < Expr * > ()); }
#line 1126 "src/parser.cpp"
    break;

  case 50: // stmt: "if" expr block
#line 170 "grammar/parser.ypp"
                               { yylhs.value.as < Stmt * > () = Stmt::newIf(yystack_[1].value.as < Expr * > (), yystack_[0].value.as < Stmt * > (), 0); }
#line 1132 "src/parser.cpp"
    break;

  case 51: // stmt: "if" expr block "else" block
#line 171 "grammar/parser.ypp"
                               { yylhs.value.as < Stmt * > () = Stmt::newIf(yystack_[3].value.as < Expr * > (), yystack_[2].value.as < Stmt * > (), yystack_[0].value.as < Stmt * > ()); }
#line 1138 "src/parser.cpp"
    break;

  case 52: // stmt: "while" expr block
#line 173 "grammar/parser.ypp"
                     { yylhs.value.as < Stmt * > () = Stmt::newWhile(yystack_[1].value.as < Expr * > (), yystack_[0].value.as < Stmt * > ()); }
#line 1144 "src/parser.cpp"
    break;

  case 53: // stmt: "for" expr ";" expr ";" expr block
#line 175 "grammar/parser.ypp"
                                     { yylhs.value.as < Stmt * > () = Stmt::newFor(yystack_[5].value.as < Expr * > (), yystack_[3].value.as < Expr * > (), yystack_[1].value.as < Expr * > (), yystack_[0].value.as < Stmt * > ()); }
#line 1150 "src/parser.cpp"
    break;


#line 1154 "src/parser.cpp"

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
      yy_lac_discard_ ("error recovery");
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

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "fn", "int", "str", "if",
  "else", "while", "for", "return", "=", "&", "|", "^", "~", "-", "+", "*",
  "/", "(", ")", ",", ".", "{", "}", "[", "]", ";", "++", "--", "<", ">",
  "<=", ">=", "==", "!=", "and", "or", "not", "identifier", "string",
  "integer", "float", "$accept", "decls", "decl", "params", "param",
  "type", "expr", "args", "block", "stmts", "stmt", YY_NULLPTR
    };
    return yy_sname[yysymbol];
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

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
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
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
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


  const signed char parser::yypact_ninf_ = -51;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -51,     4,   -51,    -1,   -51,   -51,   -51,    19,    32,    27,
       6,    39,   -51,    -4,   -51,    26,   -51,    20,    -4,    -4,
      -4,   305,   -51,   -51,    80,     1,    39,   -51,   277,   107,
     277,    -4,    -4,    -4,   -51,   -51,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   -51,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,   -51,   -14,   -51,   -51,   -51,   277,   277,    29,
     134,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    65,   -51,   -51,    -4,
     -51,    -4,    -4,    -4,    -4,   -51,   -51,   161,   -51,   277,
     188,   188,   215,   242,   -51,    48,   -51,    -4,   -51,    38,
     269,   -51,    -4,   188,   -51
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,    13,    14,     3,     0,     0,     0,
       0,     8,    12,     0,     7,     0,     9,     0,     0,     0,
       0,    40,    16,    15,     0,     0,     0,    11,    34,     0,
      18,     0,    41,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     4,    10,    37,    17,    42,     0,
       0,    27,    28,    29,    31,    30,    32,    33,    25,    26,
      23,    24,    21,    22,    19,    20,     0,     5,    39,     0,
      38,     0,     0,     0,     0,    44,    47,     0,    46,    43,
       0,     0,     0,     0,    48,    50,    52,     0,    49,     0,
       0,    51,     0,     0,    53
  };

  const signed char
  parser::yypgoto_[] =
  {
     -51,   -51,    -9,   -51,    46,    31,   -18,   -51,   -50,   -51,
     -51
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     6,    15,    16,     7,    24,    59,    54,    76,
      88
  };

  const signed char
  parser::yytable_[] =
  {
      28,    29,    30,    77,     2,     4,     5,     3,     4,     5,
      52,    18,     9,    57,    58,    60,    19,    13,    61,    62,
      63,    64,    65,    66,    67,    52,    68,    69,    70,    71,
      72,    73,    74,    75,    14,    20,    21,    22,    23,     8,
      95,    96,    17,     4,     5,     9,     9,    25,    26,   101,
      78,    79,    11,   104,    12,    99,    53,    17,    87,    10,
      27,    89,    52,    90,    91,    92,    93,    86,     3,     4,
       5,    81,    55,    82,    83,    84,     0,     0,     0,   100,
      18,     0,     0,     0,   103,    19,     0,     0,     0,     0,
      85,     0,    36,    37,    38,     0,    39,    40,    41,    42,
       0,     0,     0,     0,    20,    21,    22,    23,    43,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    36,
      37,    38,     0,    39,    40,    41,    42,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    36,    37,    38,     0,
      39,    40,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    36,    37,    38,     0,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      36,    37,    38,     0,    39,    40,    41,    42,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    36,    37,    38,
       0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    36,    37,    38,     0,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    36,    37,    38,     0,    39,    40,    41,    42,    36,
      37,    38,     0,    39,    40,    41,    42,   102,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    44,    45,
      46,    47,    48,    49,    50,    51,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
       0,    33,     0,     0,    34,    35
  };

  const signed char
  parser::yycheck_[] =
  {
      18,    19,    20,    53,     0,     4,     5,     3,     4,     5,
      24,    15,    26,    31,    32,    33,    20,    11,    36,    37,
      38,    39,    40,    41,    42,    24,    44,    45,    46,    47,
      48,    49,    50,    51,    28,    39,    40,    41,    42,    40,
      90,    91,    11,     4,     5,    26,    26,    21,    22,    99,
      21,    22,    20,   103,    27,     7,    25,    26,    76,    40,
      40,    79,    24,    81,    82,    83,    84,    76,     3,     4,
       5,     6,    26,     8,     9,    10,    -1,    -1,    -1,    97,
      15,    -1,    -1,    -1,   102,    20,    -1,    -1,    -1,    -1,
      25,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    12,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    12,    13,    14,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      12,    13,    14,    -1,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    12,    13,    14,
      -1,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    12,    13,    14,    -1,    16,    17,    18,    19,    12,
      13,    14,    -1,    16,    17,    18,    19,    28,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    31,    32,
      33,    34,    35,    36,    37,    38,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    30
  };

  const signed char
  parser::yystos_[] =
  {
       0,    45,     0,     3,     4,     5,    46,    49,    40,    26,
      40,    20,    27,    11,    28,    47,    48,    49,    15,    20,
      39,    40,    41,    42,    50,    21,    22,    40,    50,    50,
      50,    11,    20,    26,    29,    30,    12,    13,    14,    16,
      17,    18,    19,    28,    31,    32,    33,    34,    35,    36,
      37,    38,    24,    49,    52,    48,    21,    50,    50,    51,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    53,    52,    21,    22,
      27,     6,     8,     9,    10,    25,    46,    50,    54,    50,
      50,    50,    50,    50,    28,    52,    52,    28,    28,     7,
      50,    52,    28,    50,    52
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    45,    46,    46,    46,    46,    47,    47,
      47,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     6,     7,     5,     3,     0,     1,
       3,     2,     3,     1,     1,     1,     1,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     4,     4,
       1,     0,     1,     3,     3,     0,     2,     1,     2,     3,
       3,     5,     3,     7
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    95,    95,    96,    99,   100,   101,   102,   105,   106,
     107,   110,   113,   114,   115,   120,   121,   123,   125,   126,
     127,   129,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,   144,   145,   146,   147,   148,   149,
     150,   153,   154,   155,   158,   161,   162,   165,   166,   168,
     170,   171,   173,   175
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
#line 1822 "src/parser.cpp"

#line 176 "grammar/parser.ypp"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
