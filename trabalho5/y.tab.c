/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "minijs.y" /* yacc.c:339  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int linha = 1, coluna = 0;

struct Atributos {
  vector<string> c; // Código

  // Só para argumentos e parâmetros
  int contador = 0;     
  int remove_pilha = 1;
  // Só para valor default de argumento        
  vector<string> valor_default; 

  int linha = 0, coluna = 0;
  void clear() {
    c.clear();
    valor_default.clear();
    linha = 0;
    coluna = 0;
    contador = 0;
    remove_pilha = 1;
  }
};
#define YYSTYPE Atributos

enum TipoDecl { Let = 1, Const, Var };
map< int, string > nomeTipoDecl = { 
  { Let, "let" }, 
  { Const, "const" }, 
  { Var, "var" }
};

struct Simbolo {
  TipoDecl tipo;
  int linha;
  int coluna;
};

int in_func = 0;

// Tabela de símbolos - agora é uma pilha
vector< map< string, Simbolo > > ts = { map< string, Simbolo >{} }; 
vector<string> funcoes;

extern "C" int yylex();
int yyparse();
void yyerror(const char *);
int is_function_scope = 0;
bool operator!=(vector<string> a, vector<string> b);
vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );
vector<string> resolve_enderecos( vector<string> entrada );
string gera_label( string prefixo );
void print( vector<string> codigo );
vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna );
void checa_simbolo( string nome, bool modificavel );
void checa_return(int is_function_scope);
string trim(string str, string charsToRemove);
vector<string> tokeniza(string asmLine);


#line 138 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    LET = 262,
    CONST = 263,
    VAR = 264,
    FUNCTION = 265,
    ASM = 266,
    RETURN = 267,
    ID = 268,
    CDOUBLE = 269,
    CSTRING = 270,
    CINT = 271,
    BOOL = 272,
    SETA = 273,
    PARENTESIS_FUNCAO = 274,
    EMPTY_BLOCK = 275,
    AND = 276,
    OR = 277,
    ME_IG = 278,
    MA_IG = 279,
    DIF = 280,
    IGUAL = 281,
    SETA_OBJ = 282,
    MAIS_IGUAL = 283,
    MAIS_MAIS = 284
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define LET 262
#define CONST 263
#define VAR 264
#define FUNCTION 265
#define ASM 266
#define RETURN 267
#define ID 268
#define CDOUBLE 269
#define CSTRING 270
#define CINT 271
#define BOOL 272
#define SETA 273
#define PARENTESIS_FUNCAO 274
#define EMPTY_BLOCK 275
#define AND 276
#define OR 277
#define ME_IG 278
#define MA_IG 279
#define DIF 280
#define IGUAL 281
#define SETA_OBJ 282
#define MAIS_IGUAL 283
#define MAIS_MAIS 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      39,    44,    35,    33,    45,    34,    41,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    42,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    92,    93,    96,    97,    98,    99,   100,
     101,   102,   103,   106,   109,   111,   114,   116,   118,   122,
     125,   126,   125,   140,   141,   145,   165,   187,   192,   200,
     216,   217,   218,   219,   223,   235,   250,   265,   268,   269,
     272,   274,   278,   283,   286,   287,   290,   292,   295,   300,
     303,   304,   307,   310,   316,   318,   320,   322,   324,   326,
     328,   330,   332,   334,   336,   338,   340,   342,   344,   346,
     348,   350,   352,   356,   358,   359,   360,   361,   362,   364,
     366,   368,   370,   384,   394,   406,   407,   410,   413,   413,
     427,   431,   434,   439,   440,   443,   444,   448,   450,   453,
     455,   459,   460,   463,   466,   471,   472,   475,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "LET",
  "CONST", "VAR", "FUNCTION", "ASM", "RETURN", "ID", "CDOUBLE", "CSTRING",
  "CINT", "BOOL", "SETA", "PARENTESIS_FUNCAO", "EMPTY_BLOCK", "AND", "OR",
  "ME_IG", "MA_IG", "DIF", "IGUAL", "SETA_OBJ", "MAIS_IGUAL", "MAIS_MAIS",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "'('",
  "'{'", "'.'", "';'", "'}'", "')'", "','", "']'", "':'", "$accept", "S",
  "CMDs", "CMD", "EMPILHA_TS", "CMD_FUNC", "$@1", "$@2", "LISTA_PARAMs",
  "PARAMs", "PARAM", "CMD_FOR", "PRIM_E", "CMD_IF", "CMD_WHILE", "CMD_LET",
  "LET_VARs", "LET_VAR", "CMD_VAR", "VAR_VARs", "VAR_VAR", "CMD_CONST",
  "CONST_VARs", "CONST_VAR", "E", "ID_SETA", "FUNC_ANON", "$@3", "ARRAY",
  "ARRAY_ARGs", "ARRAY_ARG", "OBJ", "CAMPOs", "CAMPO", "LISTA_ARGs",
  "ARGs", "ARG", "LVALUEPROP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,    60,    62,    43,    45,    42,    47,    37,    91,    40,
     123,    46,    59,   125,    41,    44,    93,    58
};
# endif

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -55

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-55)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    13,   247,  -147,   -19,     0,     9,    36,    40,    41,
      -2,    87,    33,  -147,  -147,  -147,  -147,  -147,     2,    18,
     330,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    17,    37,
      39,   300,   -13,  -147,  -147,    15,     2,   283,     2,    25,
    -147,    44,    68,  -147,    54,    75,  -147,    61,  -147,    96,
      73,  -147,   100,   477,    72,     2,  -147,    87,  -147,    49,
    -147,   517,   -16,  -147,  -147,   285,    98,    70,  -147,   367,
      74,  -147,  -147,  -147,  -147,    77,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,   107,
    -147,     2,  -147,     2,     2,   389,    81,  -147,  -147,  -147,
     517,   411,    87,    36,    87,    40,    87,    41,    85,    99,
      86,    84,    90,   102,  -147,  -147,   536,   517,  -147,    87,
    -147,    87,   130,    96,  -147,  -147,   129,  -147,   536,   536,
     536,   536,   320,   320,    49,    49,   -17,   -17,   -17,   348,
     517,  -147,   106,   108,  -147,  -147,   517,   174,   536,   517,
     247,     2,   247,   517,  -147,  -147,   517,  -147,  -147,   517,
    -147,  -147,    96,     2,   111,    87,  -147,   100,  -147,   433,
       2,  -147,  -147,  -147,  -147,    87,  -147,   152,   497,  -147,
     113,   517,  -147,   517,  -147,  -147,   517,  -147,   247,     2,
     118,  -147,  -147,   455,  -147,   190,   247,  -147,  -147,  -147,
     231,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    74,    76,    75,    77,    18,     0,     0,
      24,    19,    17,     3,    11,     8,     9,    10,     0,     0,
       0,     0,     0,    86,    85,    79,     0,     0,     0,    40,
      37,    39,     0,    49,    51,    46,    43,    45,    20,    24,
       0,    95,     0,     0,     0,     0,    56,     0,    87,    71,
      73,    93,     0,    92,    94,    78,     0,    23,    26,     0,
       0,     4,     5,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
      16,     0,     4,     0,     0,     0,     0,    30,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    98,    12,    13,    57,    54,    55,     0,
      90,     0,     0,     0,    80,    81,     0,    14,    60,    61,
      63,    62,    64,    65,    66,    67,    68,    69,    70,     0,
     105,   106,     0,   101,   104,   108,    82,     0,    59,    58,
       0,     0,     0,    42,    41,    38,    53,    52,    50,    48,
      47,    44,    24,     0,     0,     0,    96,     0,    91,    28,
       0,    25,    15,   107,    72,     0,    84,    34,     0,    36,
       0,    28,    88,    99,   100,    97,    83,   103,     0,     0,
       0,     4,    35,     0,    21,     0,     0,     4,    89,    29,
       0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -69,  -146,   139,  -147,  -147,  -147,   -46,  -147,
      38,  -147,  -147,  -147,  -147,   125,    63,  -147,   133,    66,
    -147,   137,    71,  -147,   -11,  -147,  -147,  -147,  -147,  -147,
      56,   -10,    34,  -147,  -147,  -147,    10,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    23,    58,    24,   108,   197,    66,    67,
      68,    25,    96,    26,    27,    28,    40,    41,    29,    46,
      47,    30,    43,    44,    31,    32,    33,   191,    34,    62,
      63,    64,   112,   113,   142,   143,   144,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    54,   126,   110,   177,    91,   179,    59,    61,    69,
      70,    48,    50,     3,    92,    12,    13,    14,    15,    16,
      36,    87,    88,   147,    89,    95,   100,   101,    50,   119,
     120,    12,    13,    14,    15,    16,    18,    49,    51,    37,
      19,    20,   192,    93,   116,    94,   117,   118,    38,    39,
     199,   -19,    18,    42,    45,   102,    19,    20,    52,    72,
     -19,    55,    56,    57,    60,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    73,
     146,    74,   148,   149,    84,    85,    86,    87,    88,   103,
      89,   153,   154,   156,   157,   159,   160,    50,   104,   105,
      12,    13,    14,    15,    16,   106,   107,    51,    61,   109,
     169,   118,    49,   111,   115,   123,   180,   122,   125,   127,
     145,    18,   195,   151,   162,    19,    20,    52,   200,   163,
     164,   165,     4,   166,     5,     6,     7,     8,     9,    10,
     178,    11,    12,    13,    14,    15,    16,   167,   170,    17,
     174,   182,   181,   175,   183,   184,   188,   190,   194,   186,
      71,   171,    97,    18,   140,   141,   155,    19,    20,    21,
      98,    22,   172,   161,    99,   168,   158,     4,   193,     5,
       6,     7,     8,     9,    10,   187,    11,    12,    13,    14,
      15,    16,     0,     4,    17,     5,     6,     7,     8,     9,
      10,   185,    11,    12,    13,    14,    15,    16,    18,     0,
      17,     0,    19,    20,    21,     0,    22,   176,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,    19,    20,
      21,     0,    22,   198,     4,     0,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,     0,
       4,    17,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    18,     0,    17,     0,    19,
      20,    21,     0,    22,   201,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    19,    20,    21,     0,    22,
       7,     8,     9,    50,     0,     0,    12,    13,    14,    15,
      16,     0,     0,   -19,   -27,     0,     0,     0,     0,     0,
       0,    75,   -19,    55,    56,   121,     0,    18,     0,     0,
       0,    19,    20,    76,    77,    78,    79,     0,     0,     0,
     -27,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      50,    89,    90,    65,    13,    14,    15,    16,     0,     0,
      51,   -55,   -55,    82,    83,    84,    85,    86,    87,    88,
       0,    89,     0,     0,    18,     0,     0,     0,    19,    20,
      52,    76,    77,    78,    79,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    89,
      76,    77,    78,    79,   173,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,     0,
       0,   124,    76,    77,    78,    79,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
      89,     0,     0,   150,    76,    77,    78,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    89,     0,     0,   152,    76,    77,    78,    79,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    89,     0,     0,   -54,    76,    77,
      78,    79,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,    89,     0,     0,   196,
      76,    77,    78,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,   114,
      76,    77,    78,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,   189,
      76,    77,    78,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,   -55,
     -55,   -55,   -55,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,    89
};

static const yytype_int16 yycheck[] =
{
      11,    11,    71,    49,   150,    18,   152,    18,    19,    20,
      20,    13,    10,     0,    27,    13,    14,    15,    16,    17,
      39,    38,    39,    92,    41,    36,    37,    38,    10,    45,
      46,    13,    14,    15,    16,    17,    34,    39,    20,    39,
      38,    39,   188,    28,    55,    30,    57,    57,    39,    13,
     196,    18,    34,    13,    13,    30,    38,    39,    40,    42,
      27,    28,    29,    30,    46,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    88,    42,
      91,    42,    93,    94,    35,    36,    37,    38,    39,    45,
      41,   102,   102,   104,   104,   106,   106,    10,    30,    45,
      13,    14,    15,    16,    17,    30,    45,    20,   119,    13,
     121,   121,    39,    13,    42,    45,   162,    19,    44,    42,
      13,    34,   191,    42,    39,    38,    39,    40,   197,    30,
      44,    47,     3,    43,     5,     6,     7,     8,     9,    10,
     151,    12,    13,    14,    15,    16,    17,    45,    18,    20,
      44,    40,   163,    45,   165,   165,     4,    44,    40,   170,
      21,   123,    37,    34,   175,   175,   103,    38,    39,    40,
      37,    42,    43,   107,    37,   119,   105,     3,   189,     5,
       6,     7,     8,     9,    10,   175,    12,    13,    14,    15,
      16,    17,    -1,     3,    20,     5,     6,     7,     8,     9,
      10,   167,    12,    13,    14,    15,    16,    17,    34,    -1,
      20,    -1,    38,    39,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    42,    43,     3,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
       3,    20,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    34,    -1,    20,    -1,    38,
      39,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
       7,     8,     9,    10,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    27,    28,    29,    30,    -1,    34,    -1,    -1,
      -1,    38,    39,    23,    24,    25,    26,    -1,    -1,    -1,
      45,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      10,    41,    42,    13,    14,    15,    16,    17,    -1,    -1,
      20,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      23,    24,    25,    26,    46,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    44,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    -1,    -1,    44,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    44,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    44,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,    44,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     3,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    16,    17,    20,    34,    38,
      39,    40,    42,    51,    53,    59,    61,    62,    63,    66,
      69,    72,    73,    74,    76,    85,    39,    39,    39,    13,
      64,    65,    13,    70,    71,    13,    67,    68,    13,    39,
      10,    20,    40,    72,    79,    28,    29,    30,    52,    72,
      46,    72,    77,    78,    79,    13,    56,    57,    58,    72,
      79,    52,    42,    42,    42,    11,    23,    24,    25,    26,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    41,
      42,    18,    27,    28,    30,    72,    60,    63,    66,    69,
      72,    72,    30,    45,    30,    45,    30,    45,    54,    13,
      56,    13,    80,    81,    42,    42,    72,    72,    79,    45,
      46,    30,    19,    45,    44,    44,    50,    42,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    79,    82,    83,    84,    13,    72,    50,    72,    72,
      44,    42,    44,    72,    79,    64,    72,    79,    70,    72,
      79,    67,    39,    30,    44,    47,    43,    45,    78,    72,
      18,    58,    43,    46,    44,    45,    43,    51,    72,    51,
      56,    72,    40,    72,    79,    80,    72,    84,     4,    42,
      44,    75,    51,    72,    40,    50,    44,    55,    43,    51,
      50,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      54,    55,    53,    56,    56,    57,    57,    58,    58,    59,
      60,    60,    60,    60,    61,    61,    62,    63,    64,    64,
      65,    65,    65,    66,    67,    67,    68,    68,    68,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    75,    74,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     1,
       1,     1,     3,     3,     3,     4,     2,     1,     1,     0,
       0,     0,    10,     1,     0,     3,     1,     1,     3,     9,
       1,     1,     1,     1,     5,     7,     5,     2,     3,     1,
       1,     3,     3,     2,     3,     1,     1,     3,     3,     2,
       3,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     5,     4,     1,     1,     2,     0,     8,
       3,     3,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     1,     0,     3,     1,     1,     1,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "minijs.y" /* yacc.c:1646  */
    { print( resolve_enderecos( (yyvsp[0]).c  + "." + funcoes) ); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "minijs.y" /* yacc.c:1646  */
    {(yyval).clear();}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "minijs.y" /* yacc.c:1646  */
    { checa_return(is_function_scope);
        (yyval).c = (yyvsp[-1]).c + "'&retorno'" + "@" + "~"; }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "minijs.y" /* yacc.c:1646  */
    { checa_return(is_function_scope);
        (yyval).c = (yyvsp[-1]).c + "'&retorno'" + "@" + "~"; }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[-1]).c + "^"; }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "minijs.y" /* yacc.c:1646  */
    { ts.pop_back();
        (yyval).c = vector<string>{"<{"} + (yyvsp[-1]).c + vector<string>{"}>"}; }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "minijs.y" /* yacc.c:1646  */
    { (yyvsp[-1]).remove_pilha ? (yyval).c = (yyvsp[-1]).c + "^" : (yyval).c = (yyvsp[-1]).c;}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "minijs.y" /* yacc.c:1646  */
    { (yyval).clear(); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "minijs.y" /* yacc.c:1646  */
    { (yyval).clear(); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "minijs.y" /* yacc.c:1646  */
    { ts.push_back( map< string, Simbolo >{} ); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "minijs.y" /* yacc.c:1646  */
    { declara_var( Var, (yyvsp[0]).c[0], (yyvsp[0]).linha, (yyvsp[0]).coluna ); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "minijs.y" /* yacc.c:1646  */
    {is_function_scope++;}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "minijs.y" /* yacc.c:1646  */
    { 
             string lbl_endereco_funcao = gera_label( "func_" + (yyvsp[-8]).c[0] );
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             (yyval).c = (yyvsp[-8]).c + "&" + (yyvsp[-8]).c + "{}"  + "=" + "'&funcao'" +
                    lbl_endereco_funcao + "[=]" + "^";
             funcoes = funcoes + definicao_lbl_endereco_funcao + (yyvsp[-5]).c + (yyvsp[-1]).c +
                       "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back();
             is_function_scope--; 
           }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 141 "minijs.y" /* yacc.c:1646  */
    { ts.push_back( map< string, Simbolo >{}); 
                 (yyval).c.clear(); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "minijs.y" /* yacc.c:1646  */
    { // a & a arguments @ 0 [@] = ^ 
         declara_var( Let, (yyvsp[0]).c[0], (yyvsp[0]).linha, (yyvsp[0]).coluna ); 
         (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "&" + (yyvsp[0]).c + "arguments" + "@" + to_string( (yyvsp[-2]).contador )
                + "[@]" + "=" + "^"; 
         if( (yyvsp[0]).valor_default.size() > 0 ) {
           string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
           (yyval).c = (yyval).c + 
                 (yyvsp[0]).c + "@" + "undefined" + "@" + "!=" +
                 lbl_true + "?" + (yyvsp[0]).c + (yyvsp[0]).valor_default + "=" + "^" +
                 lbl_fim_if + "#" +
                 definicao_lbl_true + 
                 definicao_lbl_fim_if
                 ;
         }
         (yyval).contador = (yyvsp[-2]).contador + (yyvsp[0]).contador; 
       }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "minijs.y" /* yacc.c:1646  */
    { // a & a arguments @ 0 [@] = ^ 
         ts.push_back( map< string, Simbolo >{});
         declara_var( Let, (yyvsp[0]).c[0], (yyvsp[0]).linha, (yyvsp[0]).coluna ); 
         (yyval).c = (yyvsp[0]).c + "&" + (yyvsp[0]).c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; 
         if( (yyvsp[0]).valor_default.size() > 0 ) {
           string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;
           (yyval).c = (yyval).c + 
                 (yyvsp[0]).c + "@" + "undefined" + "@" + "!=" +
                 lbl_true + "?" + (yyvsp[0]).c + (yyvsp[0]).valor_default + "=" + "^" +
                 lbl_fim_if + "#" +
                 definicao_lbl_true + 
                 definicao_lbl_fim_if
                 ;
         }
         (yyval).contador = (yyvsp[0]).contador; 
       }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 188 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;      
        (yyval).contador = 1;
        (yyval).valor_default.clear();
      }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 193 "minijs.y" /* yacc.c:1646  */
    { // Código do IF
        (yyval).c = (yyvsp[-2]).c;
        (yyval).contador = 1;
        (yyval).valor_default = (yyvsp[0]).c;         
      }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 201 "minijs.y" /* yacc.c:1646  */
    { string lbl_fim_for = gera_label( "fim_for" );
          string lbl_condicao_for = gera_label( "condicao_for" );
          string lbl_comando_for = gera_label( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;

          (yyval).c = (yyvsp[-6]).c + definicao_lbl_condicao_for +
                 (yyvsp[-4]).c + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + (yyvsp[0]).c +
                 (yyvsp[-2]).c + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c + "^"; }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 224 "minijs.y" /* yacc.c:1646  */
    { string lbl_true = gera_label( "lbl_true" );
          string lbl_fim_if = gera_label( "lbl_fim_if" );
          string definicao_lbl_true = ":" + lbl_true;
          string definicao_lbl_fim_if = ":" + lbl_fim_if;
          (yyval).c = (yyvsp[-2]).c +
                 lbl_true + "?" +
                 lbl_fim_if + "#" +
                 definicao_lbl_true + (yyvsp[0]).c +
                 definicao_lbl_fim_if
                 ;
        }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 236 "minijs.y" /* yacc.c:1646  */
    {  string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;

            (yyval).c = (yyvsp[-4]).c +                       // Codigo da expressão
                   lbl_true + "?" +             // Código do IF
                   (yyvsp[0]).c + lbl_fim_if + "#" +    // Código do False
                   definicao_lbl_true + (yyvsp[-2]).c +  // Código do True
                   definicao_lbl_fim_if         // Fim do IF
                   ;
         }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 250 "minijs.y" /* yacc.c:1646  */
    {
    string lbl_fim_while = gera_label( "fim_while" );
    string lbl_condicao_while = gera_label( "condicao_while" );
    string lbl_comando_while = gera_label( "comando_while" );
    string definicao_lbl_fim_while = ":" + lbl_fim_while;
    string definicao_lbl_condicao_while = ":" + lbl_condicao_while;
    string definicao_lbl_comando_while = ":" + lbl_comando_while;
    
    (yyval).c =  definicao_lbl_condicao_while +
            (yyvsp[-2]).c + lbl_comando_while + "?" + lbl_fim_while + "#" +
            definicao_lbl_comando_while + (yyvsp[0]).c + lbl_condicao_while + "#" +
            definicao_lbl_fim_while;
            }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 268 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 273 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Let, (yyvsp[0]).c[0], (yyvsp[0]).linha, (yyvsp[0]).coluna ); }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "minijs.y" /* yacc.c:1646  */
    { 
            (yyval).c = declara_var( Let, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                   (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 279 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Let, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                    (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 291 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Var, (yyvsp[0]).c[0], (yyvsp[0]).linha, (yyvsp[0]).coluna ); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 293 "minijs.y" /* yacc.c:1646  */
    {  (yyval).c = declara_var( Var, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                    (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 296 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Var, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                    (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 300 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 303 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 308 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Const, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                     (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 311 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = declara_var( Const, (yyvsp[-2]).c[0], (yyvsp[-2]).linha, (yyvsp[-2]).coluna ) + 
                     (yyvsp[-2]).c + (yyvsp[0]).c + "=" + "^"; }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 317 "minijs.y" /* yacc.c:1646  */
    {if(is_function_scope == 0) checa_simbolo( (yyvsp[-2]).c[0], true ); (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "="; }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 319 "minijs.y" /* yacc.c:1646  */
    {if(is_function_scope == 0) checa_simbolo( (yyvsp[-2]).c[0], true ); (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "="; }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 321 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + "@" +  (yyvsp[-1]).c + (yyvsp[-1]).c + "@" + "1" + "+" + "=" + "^"; }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 323 "minijs.y" /* yacc.c:1646  */
    {if(is_function_scope == 0) checa_simbolo( (yyvsp[-2]).c[0], true ); (yyval).c = (yyvsp[-2]).c + (yyvsp[-2]).c + "@" + (yyvsp[0]).c + "+" + "="; }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 325 "minijs.y" /* yacc.c:1646  */
    {if(is_function_scope == 0) checa_simbolo( (yyvsp[-2]).c[0], true ); (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "[=]"; }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 327 "minijs.y" /* yacc.c:1646  */
    {if(is_function_scope == 0) checa_simbolo( (yyvsp[-2]).c[0], true ); (yyval).c = (yyvsp[-2]).c + (yyvsp[-2]).c + "[@]" + (yyvsp[0]).c + "+" + "[=]"; }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 329 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "<="; }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 331 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + ">="; }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 333 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "=="; }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 335 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "!="; }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 337 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "<"; }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 339 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + ">"; }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 341 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "+"; }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 343 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "-"; }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 345 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "*"; }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 347 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "/"; }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 349 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "%"; }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 351 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = "0" + (yyvsp[0]).c + (yyvsp[-1]).c;}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 353 "minijs.y" /* yacc.c:1646  */
    {
      (yyval).c = (yyvsp[-1]).c + to_string( (yyvsp[-1]).contador ) + (yyvsp[-3]).c + "$";
    }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 357 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = vector<string>{"[]"};}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 363 "minijs.y" /* yacc.c:1646  */
    { if(is_function_scope == 0) checa_simbolo( (yyvsp[0]).c[0], false ); (yyval).c = (yyvsp[0]).c + "@";}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 365 "minijs.y" /* yacc.c:1646  */
    { if(is_function_scope == 0) checa_simbolo( (yyvsp[0]).c[0], false ); (yyval).c = (yyvsp[0]).c + "[@]"; }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 367 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; (yyval).remove_pilha = 0; }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 369 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c; (yyval).remove_pilha = 0; }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 371 "minijs.y" /* yacc.c:1646  */
    { 
      string lbl_endereco_funcao = gera_label( "func_" + (yyvsp[-2]).c[0] );
      string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
      
      (yyval).c = vector<string>{"{}"} + vector<string>{"'&funcao'"} +
            lbl_endereco_funcao + "[<=]";
      (yyval).remove_pilha = 0;
      funcoes = funcoes + definicao_lbl_endereco_funcao + (yyvsp[-2]).c + "&" + (yyvsp[-2]).c + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" + (yyvsp[0]).c +
                "'&retorno'" + "@"+ "~";
      is_function_scope--;
      ts.pop_back(); 
    }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 385 "minijs.y" /* yacc.c:1646  */
    { string lbl_endereco_funcao = gera_label( "func_");
      string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
      
      (yyval).c = vector<string>{"{}"} + vector<string>{"'&funcao'"} +
            lbl_endereco_funcao + "[<=]";
      (yyval).remove_pilha = 0;
      funcoes = funcoes + definicao_lbl_endereco_funcao + (yyvsp[-3]).c + (yyvsp[0]).c + 
                "'&retorno'" + "@"+ "~";
      ts.pop_back(); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 395 "minijs.y" /* yacc.c:1646  */
    { string lbl_endereco_funcao = gera_label( "func_" + (yyvsp[-3]).c[0] );
      string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
      
      (yyval).c = vector<string>{"{}"} + vector<string>{"'&funcao'"} +
            lbl_endereco_funcao + "[<=]";
      funcoes = funcoes + definicao_lbl_endereco_funcao + (yyvsp[-3]).c + "&" + (yyvsp[-3]).c + 
                "arguments" + "@" + "0" + "[@]" + "=" + "^" + (yyvsp[-1]).c +
                "'&retorno'" + "@"+ "~";
      is_function_scope--;
      ts.pop_back(); 
    }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 410 "minijs.y" /* yacc.c:1646  */
    { declara_var( Let, (yyvsp[-1]).c[0], (yyvsp[-1]).linha, (yyvsp[-1]).coluna ); is_function_scope++;}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 413 "minijs.y" /* yacc.c:1646  */
    {is_function_scope++;}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 414 "minijs.y" /* yacc.c:1646  */
    { 
             string lbl_endereco_funcao = gera_label( "func_");
             string definicao_lbl_endereco_funcao = ":" + lbl_endereco_funcao;
             
             (yyval).c = vector<string>{"{}"} + vector<string>{"'&funcao'"} +
                    lbl_endereco_funcao + "[<=]";
            funcoes = funcoes + definicao_lbl_endereco_funcao + (yyvsp[-5]).c + (yyvsp[-1]).c +
                      "undefined" + "@" + "'&retorno'" + "@"+ "~";
             ts.pop_back(); 
             is_function_scope--; 
           }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 428 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = "[]" + (yyvsp[-1]).c;}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 432 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + to_string( (yyvsp[-2]).contador ) + (yyvsp[0]).c + "[<=]";
                (yyval).contador++; }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 435 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = to_string( (yyvsp[0]).contador ) + (yyvsp[0]).c + "[<=]";
                (yyval).contador++; }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 445 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = "{}" + (yyvsp[-1]).c;}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 449 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 454 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "[<=]";}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 456 "minijs.y" /* yacc.c:1646  */
    {(yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c + "[<=]";}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 460 "minijs.y" /* yacc.c:1646  */
    { (yyval).clear(); }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 464 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;
         (yyval).contador++; }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 467 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c;
         (yyval).contador++; }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 475 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-3]).c + (yyvsp[-1]).c;}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 476 "minijs.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c;}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2169 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 480 "minijs.y" /* yacc.c:1906  */


#include "lex.yy.c"

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  return vector<string>{ a } + b;
}

bool operator!=(vector<string> a, vector<string> b) {
  return a != b;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ )
    if( entrada[i][0] == ':' )
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );

  for( int i = 0; i < saida.size(); i++ )
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);

  return saida;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void print( vector<string> codigo ) {
  for( string s : codigo )
    cout << s << " ";

  cout << endl;
}

string trim(string str, string charsToRemove){
	for(auto c : charsToRemove){
		str.erase(remove(str.begin(), str.end(), c), str.end());
	}
	return str;
}

vector<string> tokeniza(string asmLine){
	vector<string> instructions;
	string word = "";
	for(auto c : asmLine){
		if(c != ' ')
			word = word + c;
		else {
			instructions.push_back(word);
			word = "";
		}
	}
	instructions.push_back(word);
	return instructions;
}

vector<string> declara_var( TipoDecl tipo, string nome, int linha, int coluna ) {
//  cerr << "insere_simbolo( " << tipo << ", " << nome 
//       << ", " << linha << ", " << coluna << ")" << endl;
       
  auto& topo = ts.back();    
       
  if( topo.count( nome ) == 0 ) {
    topo[nome] = Simbolo{ tipo, linha, coluna };
    return vector<string>{ nome, "&" };
  }
  else if( tipo == Var && topo[nome].tipo == Var ) {
    topo[nome] = Simbolo{ tipo, linha, coluna };
    return vector<string>{};
  } 
  else {
    cerr << "Erro: a variável '" << nome << "' já foi declarada na linha " << topo[nome].linha << "." <<endl;
    exit( 1 );     
  }
}

void checa_simbolo( string nome, bool modificavel ) {
  for( int i = ts.size() - 1; i >= 0; i-- ) {  
    auto& atual = ts[i];

    if( atual.count( nome ) > 0 ) {
      if( modificavel && atual[nome].tipo == Const ) {
        cerr << "Variavel '" << nome << "' não pode ser modificada." << endl;
        exit( 1 );     
      }
      else {
        return;
      }
    }
  }

  cerr << "Variavel '" << nome << "' não declarada." << endl;
  exit( 1 );     
}

void checa_return(int is_function_scope) {
  if (is_function_scope == 0) {
    cerr << "Erro: Não é permitido 'return' fora de funções." << endl;
    exit( 1 ); 
  }
  else {
    return;
  }
}

void yyerror( const char* st ) {
   puts( st );
   printf( "Proximo a: %s\n", yytext );
   exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();

  return 0;
}
