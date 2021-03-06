
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "../src/tpIntegrador.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "tablaDeSimbolos.c"

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    extern int yylineno;

    char* tipoAuxiliar  = "";
    char* tipoAuxiliar1 = "";
    char* tipoAuxiliar2 = "";
    char* identificadorAuxiliar = ""; 
    int validacionBinaria = 0;



/* Line 189 of yacc.c  */
#line 96 "tpIntegrador.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     TIPO_DATO = 259,
     SIZEOF = 260,
     CTE_DECIMAL = 261,
     CTE_OCTAL = 262,
     CTE_HEXADECIMAL = 263,
     CTE_REAL = 264,
     OP_O_LOGICO = 265,
     OP_Y_LOGICO = 266,
     OP_O_INCLUSIVO = 267,
     OP_ASIGNACION = 268,
     OP_IGUALDAD = 269,
     OP_DESIGUALDAD = 270,
     OP_RELACIONAL = 271,
     OP_DIVISION = 272,
     OP_PORCENTAJE = 273,
     OP_INCREMENTO = 274,
     OP_DECREMENTO = 275,
     DO = 276,
     WHILE = 277,
     IF = 278,
     ELSE = 279,
     SWITCH = 280,
     CASE = 281,
     DEFAULT = 282,
     BREAK = 283,
     CONTINUE = 284,
     FOR = 285,
     RETURN = 286,
     CTE_CADENA = 287,
     CTE_CARACTER = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "../src/tpIntegrador.y"

    char* cadena;
    int entero;
    float real;



/* Line 214 of yacc.c  */
#line 173 "tpIntegrador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 185 "tpIntegrador.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,     2,    40,     2,
      44,    45,    43,    41,    36,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    35,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    21,
      25,    27,    31,    35,    37,    43,    45,    49,    51,    55,
      57,    61,    63,    67,    69,    73,    77,    79,    83,    85,
      89,    93,    95,    99,   103,   107,   109,   114,   116,   119,
     122,   125,   128,   133,   135,   137,   139,   141,   143,   145,
     150,   155,   158,   160,   164,   166,   168,   170,   174,   176,
     178,   180,   182,   184,   186,   188,   190,   194,   196,   200,
     204,   206,   210,   216,   218,   222,   229,   236,   238,   242,
     245,   247,   249,   254,   256,   258,   260,   262,   264,   266,
     269,   270,   272,   277,   279,   282,   284,   287,   293,   301,
     307,   313,   321,   331,   336,   340,   343,   346,   350,   351,
     353,   354,   356,   357,   359,   360,   362,   363,   365,   366
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,    52,    53,    -1,    73,    34,    -1,
      83,    34,    -1,     1,    34,    -1,     1,    35,    -1,    55,
      -1,    54,    36,    55,    -1,    56,    -1,    66,    37,    55,
      -1,    66,    13,    55,    -1,    57,    -1,    57,    38,    54,
      39,    56,    -1,    58,    -1,    57,    10,    58,    -1,    59,
      -1,    58,    11,    59,    -1,    60,    -1,    59,    12,    60,
      -1,    61,    -1,    60,    40,    61,    -1,    62,    -1,    61,
      14,    62,    -1,    61,    15,    62,    -1,    63,    -1,    62,
      16,    63,    -1,    64,    -1,    63,    41,    64,    -1,    63,
      42,    64,    -1,    65,    -1,    64,    43,    65,    -1,    64,
      17,    65,    -1,    64,    18,    65,    -1,    66,    -1,    44,
       4,    45,    65,    -1,    68,    -1,    19,    66,    -1,    20,
      66,    -1,    67,    65,    -1,     5,    66,    -1,     5,    44,
       4,    45,    -1,    40,    -1,    43,    -1,    41,    -1,    42,
      -1,    46,    -1,    70,    -1,    68,    47,    54,    48,    -1,
      68,    44,    93,    45,    -1,    68,    19,    -1,    55,    -1,
      69,    36,    55,    -1,     3,    -1,    72,    -1,    32,    -1,
      44,    54,    45,    -1,    56,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    33,    -1,    74,    -1,    78,    -1,
       4,    75,    35,    -1,    81,    -1,    81,    37,    76,    -1,
      81,    36,    75,    -1,    55,    -1,    49,    77,    50,    -1,
      49,    77,    36,    77,    50,    -1,    76,    -1,    77,    36,
      76,    -1,     4,     3,    44,    95,    45,    35,    -1,     4,
       3,    44,    95,    45,    86,    -1,    80,    -1,    79,    36,
      80,    -1,     4,    81,    -1,    82,    -1,     3,    -1,    82,
      47,    94,    48,    -1,    84,    -1,    86,    -1,    89,    -1,
      90,    -1,    91,    -1,    92,    -1,    85,    35,    -1,    -1,
      54,    -1,    49,    97,    98,    50,    -1,    73,    -1,    87,
      73,    -1,    83,    -1,    88,    83,    -1,    23,    44,    54,
      45,    83,    -1,    23,    44,    54,    45,    83,    24,    83,
      -1,    25,    44,    54,    45,    83,    -1,    22,    44,    54,
      45,    83,    -1,    21,    83,    22,    44,    54,    45,    35,
      -1,    30,    44,    96,    35,    96,    35,    96,    45,    83,
      -1,    26,    71,    39,    83,    -1,    27,    39,    83,    -1,
      29,    35,    -1,    28,    35,    -1,    31,    96,    35,    -1,
      -1,    69,    -1,    -1,    71,    -1,    -1,    79,    -1,    -1,
      54,    -1,    -1,    87,    -1,    -1,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    96,    97,    98,    99,   104,   105,
     108,   109,   110,   113,   114,   117,   118,   121,   122,   125,
     126,   129,   130,   133,   134,   135,   138,   139,   142,   143,
     144,   147,   148,   149,   150,   153,   154,   157,   158,   159,
     160,   161,   162,   165,   166,   167,   168,   169,   172,   173,
     174,   175,   178,   179,   182,   183,   184,   185,   188,   191,
     192,   193,   194,   195,   200,   201,   206,   209,   210,   211,
     214,   215,   216,   219,   220,   226,   227,   230,   231,   234,
     237,   240,   241,   244,   245,   246,   247,   248,   249,   252,
     255,   256,   259,   262,   263,   266,   267,   270,   271,   272,
     275,   276,   277,   280,   281,   284,   285,   286,   291,   292,
     297,   298,   301,   302,   306,   307,   310,   311,   314,   315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "TIPO_DATO", "SIZEOF",
  "CTE_DECIMAL", "CTE_OCTAL", "CTE_HEXADECIMAL", "CTE_REAL", "OP_O_LOGICO",
  "OP_Y_LOGICO", "OP_O_INCLUSIVO", "OP_ASIGNACION", "OP_IGUALDAD",
  "OP_DESIGUALDAD", "OP_RELACIONAL", "OP_DIVISION", "OP_PORCENTAJE",
  "OP_INCREMENTO", "OP_DECREMENTO", "DO", "WHILE", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "FOR", "RETURN", "CTE_CADENA",
  "CTE_CARACTER", "'\\n'", "';'", "','", "'='", "'?'", "':'", "'&'", "'+'",
  "'-'", "'*'", "'('", "')'", "'!'", "'['", "']'", "'{'", "'}'", "$accept",
  "input", "line", "expresion", "expresionAsignacion",
  "expresionCondicional", "expresionOLogico", "expresionYLogico",
  "expresionOInclusivo", "expresionY", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionConversion", "expresionUnaria", "operadorUnario",
  "expresionSufijo", "listaArgumentos", "expresionPrimaria",
  "expresionConstante", "constante", "declaracion", "declaracionVariable",
  "declarador", "inicializador", "listaInicializadores",
  "declaracionFuncion", "listaDeParametros", "parametro", "unaDeclaracion",
  "declaradorDirecto", "sentencia", "sentenciaExpresion", "expresion_s",
  "sentenciaCompuesta", "listaDeDeclaraciones", "listaDeSentencias",
  "sentenciaSeleccion", "sentenciaIteracion", "sentenciaEtiquetada",
  "sentenciaSalto", "listaArgumentos_", "expresionConstante_",
  "listaParametros_", "expresion_", "listaDeclaraciones_",
  "listaSentencias_", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    10,    59,    44,    61,    63,    58,
      38,    43,    45,    42,    40,    41,    33,    91,    93,   123,
     125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    71,    72,
      72,    72,    72,    72,    73,    73,    74,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      85,    85,    86,    87,    87,    88,    88,    89,    89,    89,
      90,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     4,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     4,
       4,     2,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     5,     1,     3,     6,     6,     1,     3,     2,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     4,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     9,     4,     3,     2,     2,     3,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    54,     0,     0,    59,    60,    61,
      62,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,   114,    56,    63,    43,    45,    46,    44,     0,
      47,   116,     3,    91,     8,    10,    13,    15,    17,    19,
      21,    23,    26,    28,    31,    35,     0,    37,    48,    55,
       0,    64,    65,     0,    83,     0,    84,    85,    86,    87,
      88,     6,     7,    81,     0,    67,    80,     0,    41,     0,
      38,    39,     0,     0,     0,     0,    58,    35,     0,    90,
     106,   105,   114,   115,     0,     0,     0,    93,   117,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    51,   108,     0,
       4,     5,    89,   112,    66,     0,     0,   110,     0,     0,
       0,     0,     0,    90,   104,     0,   107,     0,    57,    94,
      95,    90,     0,     9,    16,     0,    18,    20,    22,    24,
      25,    27,    29,    30,    33,    34,    32,    12,    11,    52,
     109,     0,     0,     0,   113,    77,     0,    81,    69,     0,
      70,    68,   111,     0,    42,     0,    90,    90,    90,   103,
     114,    36,    96,    92,     0,     0,    50,    49,    79,     0,
       0,    73,     0,    82,     0,   100,    97,    99,     0,    14,
      53,    78,    75,    76,     0,    71,     0,    90,   114,    73,
       0,   101,    98,     0,     0,    72,    90,    74,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   150,    48,
      78,    49,    50,    51,    64,   161,   182,    52,   154,   155,
      65,    66,    53,    54,    55,    56,    88,   131,    57,    58,
      59,    60,   151,   163,   156,    84,    89,   132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
    -148,   182,  -148,    34,  -148,    11,   448,  -148,  -148,  -148,
    -148,   490,   490,   323,   -20,   -16,     7,   508,    -9,    -1,
      14,    18,   508,  -148,  -148,  -148,  -148,  -148,  -148,   386,
    -148,    71,  -148,    47,  -148,  -148,     1,    74,    75,    46,
      58,    87,    36,     0,  -148,     8,   508,   -12,  -148,  -148,
      73,  -148,  -148,    77,  -148,    78,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,    64,    79,    43,    65,   430,  -148,   508,
    -148,  -148,    94,   508,   508,   508,  -148,  -148,    81,   323,
    -148,  -148,   508,    47,    82,    76,    -7,  -148,    71,   227,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,  -148,  -148,   508,   508,
    -148,  -148,  -148,   118,  -148,   120,   368,   508,    83,    80,
      -3,     5,    19,   323,  -148,    91,  -148,   508,  -148,  -148,
    -148,   275,    84,  -148,    74,    31,    75,    46,    58,    87,
      87,    36,     0,     0,  -148,  -148,  -148,  -148,  -148,  -148,
      93,    85,   -11,   120,    95,  -148,    88,  -148,  -148,   368,
    -148,  -148,  -148,    89,  -148,   508,   323,   323,   323,  -148,
     508,  -148,  -148,  -148,   508,   508,  -148,  -148,  -148,   118,
     -22,  -148,   -14,  -148,    20,  -148,   103,  -148,   100,  -148,
    -148,  -148,  -148,  -148,   368,  -148,   101,   323,   508,  -148,
     -10,  -148,  -148,    96,   368,  -148,   323,  -148,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,   -21,   -85,   -15,  -148,    48,    45,    49,
      50,     9,    42,   -18,   -43,    -2,  -148,  -148,  -148,  -148,
      25,  -148,   -25,  -148,    32,  -147,   -48,  -148,  -148,   -31,
       3,  -148,   -13,  -148,  -148,   -30,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   -66,  -148,  -148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const yytype_int16 yytable[] =
{
      72,    83,    76,   106,    68,   133,    87,   107,    86,    70,
      71,    91,   181,   192,    63,    77,   125,   101,   102,   147,
     148,   104,   194,   149,    73,    90,   204,    31,    74,    90,
      79,   160,   108,    90,    80,   109,   195,   177,   128,    92,
     205,    90,   166,   103,    77,   105,    86,   199,    86,    81,
     167,    75,   120,   121,   122,    90,    90,   207,   144,   145,
     146,    83,    82,   129,   168,   196,   124,    90,    61,    62,
     174,   135,    96,    97,   160,     5,   130,    99,   100,   115,
     116,   142,   143,    90,   171,    93,    95,    94,   152,    77,
     190,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    76,    98,   188,   139,   140,   110,   113,   160,
     169,   111,   117,   112,   114,    77,   119,   126,   172,   160,
     123,   127,   153,   157,   165,    77,   170,   197,   164,   175,
     176,   179,   203,   180,   173,   198,   201,   183,   136,   134,
     141,   206,   162,   137,   184,   138,   200,   158,   191,    83,
     193,     0,     0,   185,   186,   187,   178,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     2,     3,   202,     4,     5,     6,     7,     8,
       9,    10,     0,   208,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,   -90,     0,     0,
       0,     0,    25,    26,    27,    28,    29,     0,    30,     0,
       4,    31,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,     0,    30,     0,     0,    31,  -118,     4,     0,
       6,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,    29,
       0,    30,     0,     0,    31,  -119,     4,     0,     6,     7,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,    29,     0,    30,
       0,     4,    31,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     4,
      85,     6,     7,     8,     9,    10,     0,     0,     0,     0,
      23,    24,     0,     0,     0,    11,    12,     0,    25,    26,
      27,    28,    29,     0,    30,     0,     0,   159,    23,    24,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,     0,    30,     4,   118,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     4,     0,     6,     7,     8,     9,    10,     0,     0,
       0,     0,    23,    24,     0,     0,     0,    11,    12,     0,
      25,    26,    27,    28,    29,     0,    30,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    67,     4,    30,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     4,     0,     6,     7,     8,     9,    10,     0,     0,
       0,     0,    23,    24,     0,     0,     0,    11,    12,     0,
      25,    26,    27,    28,    69,     0,    30,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,     0,    30
};

static const yytype_int16 yycheck[] =
{
      13,    22,    17,    46,     6,    90,    31,    19,    29,    11,
      12,    10,   159,    35,     3,    17,    82,    17,    18,   104,
     105,    13,    36,   108,    44,    36,    36,    49,    44,    36,
      39,   116,    44,    36,    35,    47,    50,    48,    45,    38,
      50,    36,    45,    43,    46,    37,    67,   194,    69,    35,
      45,    44,    73,    74,    75,    36,    36,   204,   101,   102,
     103,    82,    44,    88,    45,    45,    79,    36,    34,    35,
      39,    92,    14,    15,   159,     4,    89,    41,    42,    36,
      37,    99,   100,    36,   127,    11,    40,    12,   109,    91,
     175,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   117,    16,   170,    96,    97,    34,    44,   194,
     123,    34,    47,    35,    35,   117,    22,    35,   131,   204,
      39,    45,     4,     3,    44,   127,    35,    24,    45,    36,
      45,    36,   198,    45,    50,    35,    35,    48,    93,    91,
      98,    45,   117,    94,   165,    95,   194,   115,   179,   170,
     180,    -1,    -1,   166,   167,   168,   153,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,     0,     1,   197,     3,     4,     5,     6,     7,
       8,     9,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    46,    -1,
       3,    49,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    -1,    46,    -1,    -1,    49,    50,     3,    -1,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      -1,    46,    -1,    -1,    49,    50,     3,    -1,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    -1,    46,
      -1,     3,    49,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    19,    20,    -1,    40,    41,
      42,    43,    44,    -1,    46,    -1,    -1,    49,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    -1,    46,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,     3,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    19,    20,    -1,
      40,    41,    42,    43,    44,    -1,    46,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,     3,    46,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,     3,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    19,    20,    -1,
      40,    41,    42,    43,    44,    -1,    46,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    40,    41,    42,    43,    44,
      46,    49,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    70,    72,
      73,    74,    78,    83,    84,    85,    86,    89,    90,    91,
      92,    34,    35,     3,    75,    81,    82,    44,    66,    44,
      66,    66,    83,    44,    44,    44,    56,    66,    71,    39,
      35,    35,    44,    54,    96,     4,    54,    73,    87,    97,
      36,    10,    38,    11,    12,    40,    14,    15,    16,    41,
      42,    17,    18,    43,    13,    37,    65,    19,    44,    47,
      34,    34,    35,    44,    35,    36,    37,    47,     4,    22,
      54,    54,    54,    39,    83,    96,    35,    45,    45,    73,
      83,    88,    98,    55,    58,    54,    59,    60,    61,    62,
      62,    63,    64,    64,    65,    65,    65,    55,    55,    55,
      69,    93,    54,     4,    79,    80,    95,     3,    75,    49,
      55,    76,    71,    94,    45,    44,    45,    45,    45,    83,
      35,    65,    83,    50,    39,    36,    45,    48,    81,    36,
      45,    76,    77,    48,    54,    83,    83,    83,    96,    56,
      55,    80,    35,    86,    36,    50,    45,    24,    35,    76,
      77,    35,    83,    96,    36,    50,    45,    76,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 98 "../src/tpIntegrador.y"
    { printf("\nError sintactico en la linea %i: %s", yylineno, (yyvsp[(1) - (2)].cadena));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 99 "../src/tpIntegrador.y"
    { printf("\nError sintactico en la linea %i: %s", yylineno, (yyvsp[(1) - (2)].cadena)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 143 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 144 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 148 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 149 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 150 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; validacionTipos(tipoAuxiliar1, tipoAuxiliar2); validacionBinaria = 0;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 174 "../src/tpIntegrador.y"
    { numeroDeLinea = yylineno; agregarSimbolo(&tablaAuxiliar, (yyvsp[(1) - (4)].cadena), "-", 1);  tablaAuxiliar->tipoDeParametros = tablaDeParametros; controlDeInvocacion(tablaAuxiliar);  tablaDeParametros = NULL; tablaAuxiliar = NULL; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 178 "../src/tpIntegrador.y"
    { agregarParametro(&tablaDeParametros, (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 179 "../src/tpIntegrador.y"
    { agregarParametro(&tablaDeParametros, (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 182 "../src/tpIntegrador.y"
    { tablaAuxiliar = devolverIdentificador((yyvsp[(1) - (1)].cadena)); if(tablaAuxiliar != NULL) (validacionBinaria == 0) ? (tipoAuxiliar1 = tablaAuxiliar->tipo) : (tipoAuxiliar2 = tablaAuxiliar->tipo) ; validacionBinaria = 1; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 184 "../src/tpIntegrador.y"
    {(validacionBinaria == 0) ? (tipoAuxiliar1 = "char*") : (tipoAuxiliar2 = "char*"); validacionBinaria = 1; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 191 "../src/tpIntegrador.y"
    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 192 "../src/tpIntegrador.y"
    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 193 "../src/tpIntegrador.y"
    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "int"  ) : (tipoAuxiliar2 = "int"  ); validacionBinaria = 1; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 194 "../src/tpIntegrador.y"
    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "float") : (tipoAuxiliar2 = "float"); validacionBinaria = 1; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 195 "../src/tpIntegrador.y"
    { (validacionBinaria == 0) ? (tipoAuxiliar1 = "char" ) : (tipoAuxiliar2 = "char" ); validacionBinaria = 1; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 206 "../src/tpIntegrador.y"
    { tipoAuxiliar = strdup((yyvsp[(1) - (3)].cadena)); tipoAuxiliar = insertarDeclaradores(tipoAuxiliar); agregarSimbolosSinRepetir(tipoAuxiliar,identificadorAuxiliar, 0);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 226 "../src/tpIntegrador.y"
    { agregarSimbolosSinRepetir((yyvsp[(1) - (6)].cadena),(yyvsp[(2) - (6)].cadena), 1);  agregarParametros((yyvsp[(2) - (6)].cadena)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 227 "../src/tpIntegrador.y"
    { agregarSimbolosSinRepetir((yyvsp[(1) - (6)].cadena),(yyvsp[(2) - (6)].cadena), 1);  agregarParametros((yyvsp[(2) - (6)].cadena));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 234 "../src/tpIntegrador.y"
    { tipoAuxiliar = strdup((yyvsp[(1) - (2)].cadena)); tipoAuxiliar = insertarDeclaradores(tipoAuxiliar); agregarParametro(&tablaDeParametros, tipoAuxiliar); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 240 "../src/tpIntegrador.y"
    { identificadorAuxiliar = strdup((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 241 "../src/tpIntegrador.y"
    { contador.dimensiones++; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 255 "../src/tpIntegrador.y"
    { printf("\nLinea %i - SENTENCIA - EXPRESION:  VACIA", yylineno);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 259 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-EXPRESION: COMPUESTA", yylineno); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 270 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  IF", yylineno);    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 271 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  IF/ELSE", yylineno);    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 272 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-SELECCION:  SWITCH ", yylineno);    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 275 "../src/tpIntegrador.y"
    { printf("\nLinea %i - SENTENCIA - ITERACION:  WHILE   ", yylineno);   ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 276 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-ITERACION:  DO/WHILE", yylineno);   ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 277 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro una SENTENCIA-ITERACION:  FOR     ", yylineno);   ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 284 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  CONTINUE", yylineno);   ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 285 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  BREAK   ", yylineno);   ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 286 "../src/tpIntegrador.y"
    { printf("\nLinea %i Se encontro la SENTENCIA-SALTO:  RETURN  ", yylineno);   ;}
    break;



/* Line 1455 of yacc.c  */
#line 1887 "tpIntegrador.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 317 "../src/tpIntegrador.y"


int main(){

     #ifdef BISON_DEBUG
        yydebug = 1;
    #endif 
    
    yyin = fopen("./codigoEnC.c", "r");
    
    printf("\nTipos de errores y advertencias de casteo:");
    yyparse();
    printf("\n------------------------------------");

    printf("\nValidaciones semanticas:");
    
    printf("\nDoble declaraciones: ");
    imprimirSimbolos(tablaDeDobleDeclaracion);
    printf("\n-----------------------------------");
    
    printf("\nTabla de simbolos:");
    imprimirSimbolos(tablaDeSimbolos);

    
 


}
