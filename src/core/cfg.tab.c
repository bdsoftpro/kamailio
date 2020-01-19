/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 30 "core/cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "shm_init.h"
#include "route.h"
#include "switch.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "select.h"
#include "flags.h"
#include "tcp_init.h"
#include "tcp_options.h"
#include "sctp_core.h"
#include "pvar.h"
#include "lvalue.h"
#include "rvalue.h"
#include "sr_compat.h"
#include "msg_translator.h"
#include "async_task.h"

#include "kemi.h"
#include "ppcfg.h"
#include "pvapi.h"
#include "config.h"
#include "cfg_core.h"
#include "cfg/cfg.h"
#ifdef CORE_TLS
#include "tls/tls_config.h"
#endif
#include "timer_ticks.h"

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H

#define onsend_check(s) \
	do{\
		if (rt!=ONSEND_ROUTE) yyerror( s " allowed only in onsend_routes");\
	}while(0)

	#define IF_AUTO_BIND_IPV6(x) x

#ifdef USE_DNS_CACHE
	#define IF_DNS_CACHE(x) x
#else
	#define IF_DNS_CACHE(x) warn("dns cache support not compiled in")
#endif

#ifdef USE_DNS_FAILOVER
	#define IF_DNS_FAILOVER(x) x
#else
	#define IF_DNS_FAILOVER(x) warn("dns failover support not compiled in")
#endif

#ifdef USE_NAPTR
	#define IF_NAPTR(x) x
#else
	#define IF_NAPTR(x) warn("dns naptr support not compiled in")
#endif

#ifdef USE_DST_BLACKLIST
	#define IF_DST_BLACKLIST(x) x
#else
	#define IF_DST_BLACKLIST(x) warn("dst blacklist support not compiled in")
#endif

#ifdef USE_SCTP
	#define IF_SCTP(x) x
#else
	#define IF_SCTP(x) warn("sctp support not compiled in")
#endif

#ifdef USE_RAW_SOCKS
	#define IF_RAW_SOCKS(x) x
#else
	#define IF_RAW_SOCKS(x) warn("raw socket support not compiled in")
#endif


extern int yylex();
/* safer then using yytext which can be array or pointer */
extern char* yy_number_str;

static void yyerror(char* s, ...);
static void yyerror_at(struct cfg_pos* pos, char* s, ...);
static char* tmp;
static int i_tmp;
static struct socket_id* lst_tmp;
static struct name_lst*  nl_tmp;
static int rt;  /* Type of route block for find_export */
static str* str_tmp;
static str s_tmp;
static struct ip_addr* ip_tmp;
static struct avp_spec* s_attr;
static select_t sel;
static select_t* sel_ptr;
static pv_spec_t* pv_spec;
static struct action *mod_func_action;
static struct lvalue* lval_tmp;
static struct rvalue* rval_tmp;

static void warn(char* s, ...);
static void warn_at(struct cfg_pos* pos, char* s, ...);
static void get_cpos(struct cfg_pos* pos);
static struct rval_expr* mk_rve_rval(enum rval_type, void* v);
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1);
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2);
static int rval_expr_int_check(struct rval_expr *rve);
static int warn_ct_rve(struct rval_expr *rve, char* name);
static struct socket_id* mk_listen_id(char*, int, int);
static struct name_lst* mk_name_lst(char* name, int flags);
static struct socket_id* mk_listen_id2(struct name_lst*, int, int);
static void free_name_lst(struct name_lst* lst);
static void free_socket_id_lst(struct socket_id* i);

static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re, 
									struct action* a, int* err);
static int case_check_type(struct case_stms* stms);
static int case_check_default(struct case_stms* stms);
static int mod_f_params_pre_fixup(struct action* a);
static void free_mod_func_action(struct action* a);


extern int line;
extern int column;
extern int startcolumn;
extern int startline;
extern char *finame;
extern char *routename;
extern char *default_routename;

#define set_cfg_pos(x) \
	do{\
		if(x) {\
		(x)->cline = line;\
		(x)->cfile = (finame!=0)?finame:((cfg_file!=0)?cfg_file:"default");\
		(x)->rname = (routename!=0)?routename:((default_routename!=0)?default_routename:"DEFAULT");\
		}\
	}while(0)



#line 236 "core/cfg.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CORE_CFG_TAB_H_INCLUDED
# define YY_YY_CORE_CFG_TAB_H_INCLUDED
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
    FORWARD = 258,
    FORWARD_TCP = 259,
    FORWARD_TLS = 260,
    FORWARD_SCTP = 261,
    FORWARD_UDP = 262,
    EXIT = 263,
    DROP = 264,
    RETURN = 265,
    BREAK = 266,
    LOG_TOK = 267,
    ERROR = 268,
    ROUTE = 269,
    ROUTE_REQUEST = 270,
    ROUTE_FAILURE = 271,
    ROUTE_ONREPLY = 272,
    ROUTE_REPLY = 273,
    ROUTE_BRANCH = 274,
    ROUTE_SEND = 275,
    ROUTE_EVENT = 276,
    EXEC = 277,
    SET_HOST = 278,
    SET_HOSTPORT = 279,
    SET_HOSTPORTTRANS = 280,
    PREFIX = 281,
    STRIP = 282,
    STRIP_TAIL = 283,
    SET_USERPHONE = 284,
    APPEND_BRANCH = 285,
    REMOVE_BRANCH = 286,
    CLEAR_BRANCHES = 287,
    SET_USER = 288,
    SET_USERPASS = 289,
    SET_PORT = 290,
    SET_URI = 291,
    REVERT_URI = 292,
    FORCE_RPORT = 293,
    ADD_LOCAL_RPORT = 294,
    FORCE_TCP_ALIAS = 295,
    UDP_MTU = 296,
    UDP_MTU_TRY_PROTO = 297,
    UDP4_RAW = 298,
    UDP4_RAW_MTU = 299,
    UDP4_RAW_TTL = 300,
    IF = 301,
    ELSE = 302,
    SET_ADV_ADDRESS = 303,
    SET_ADV_PORT = 304,
    FORCE_SEND_SOCKET = 305,
    SET_FWD_NO_CONNECT = 306,
    SET_RPL_NO_CONNECT = 307,
    SET_FWD_CLOSE = 308,
    SET_RPL_CLOSE = 309,
    SWITCH = 310,
    CASE = 311,
    DEFAULT = 312,
    WHILE = 313,
    CFG_SELECT = 314,
    CFG_RESET = 315,
    URIHOST = 316,
    URIPORT = 317,
    MAX_LEN = 318,
    SETFLAG = 319,
    RESETFLAG = 320,
    ISFLAGSET = 321,
    SETAVPFLAG = 322,
    RESETAVPFLAG = 323,
    ISAVPFLAGSET = 324,
    METHOD = 325,
    URI = 326,
    FROM_URI = 327,
    TO_URI = 328,
    SRCIP = 329,
    SRCPORT = 330,
    DSTIP = 331,
    DSTPORT = 332,
    TOIP = 333,
    TOPORT = 334,
    SNDIP = 335,
    SNDPORT = 336,
    SNDPROTO = 337,
    SNDAF = 338,
    PROTO = 339,
    AF = 340,
    MYSELF = 341,
    MSGLEN = 342,
    UDP = 343,
    TCP = 344,
    TLS = 345,
    SCTP = 346,
    WS = 347,
    WSS = 348,
    DEBUG_V = 349,
    FORK = 350,
    FORK_DELAY = 351,
    MODINIT_DELAY = 352,
    LOGSTDERROR = 353,
    LOGFACILITY = 354,
    LOGNAME = 355,
    LOGCOLOR = 356,
    LOGPREFIX = 357,
    LOGPREFIXMODE = 358,
    LOGENGINETYPE = 359,
    LOGENGINEDATA = 360,
    XAVPVIAPARAMS = 361,
    XAVPVIAFIELDS = 362,
    LISTEN = 363,
    ADVERTISE = 364,
    ALIAS = 365,
    SR_AUTO_ALIASES = 366,
    DNS = 367,
    REV_DNS = 368,
    DNS_TRY_IPV6 = 369,
    DNS_TRY_NAPTR = 370,
    DNS_SRV_LB = 371,
    DNS_UDP_PREF = 372,
    DNS_TCP_PREF = 373,
    DNS_TLS_PREF = 374,
    DNS_SCTP_PREF = 375,
    DNS_RETR_TIME = 376,
    DNS_SLOW_QUERY_MS = 377,
    DNS_RETR_NO = 378,
    DNS_SERVERS_NO = 379,
    DNS_USE_SEARCH = 380,
    DNS_SEARCH_FMATCH = 381,
    DNS_NAPTR_IGNORE_RFC = 382,
    DNS_CACHE_INIT = 383,
    DNS_USE_CACHE = 384,
    DNS_USE_FAILOVER = 385,
    DNS_CACHE_FLAGS = 386,
    DNS_CACHE_NEG_TTL = 387,
    DNS_CACHE_MIN_TTL = 388,
    DNS_CACHE_MAX_TTL = 389,
    DNS_CACHE_MEM = 390,
    DNS_CACHE_GC_INT = 391,
    DNS_CACHE_DEL_NONEXP = 392,
    DNS_CACHE_REC_PREF = 393,
    AUTO_BIND_IPV6 = 394,
    BIND_IPV6_LINK_LOCAL = 395,
    DST_BLST_INIT = 396,
    USE_DST_BLST = 397,
    DST_BLST_MEM = 398,
    DST_BLST_TTL = 399,
    DST_BLST_GC_INT = 400,
    DST_BLST_UDP_IMASK = 401,
    DST_BLST_TCP_IMASK = 402,
    DST_BLST_TLS_IMASK = 403,
    DST_BLST_SCTP_IMASK = 404,
    IP_FREE_BIND = 405,
    PORT = 406,
    STAT = 407,
    CHILDREN = 408,
    SOCKET_WORKERS = 409,
    ASYNC_WORKERS = 410,
    ASYNC_USLEEP = 411,
    ASYNC_NONBLOCK = 412,
    CHECK_VIA = 413,
    PHONE2TEL = 414,
    MEMLOG = 415,
    MEMDBG = 416,
    MEMSUM = 417,
    MEMSAFETY = 418,
    MEMJOIN = 419,
    MEMSTATUSMODE = 420,
    CORELOG = 421,
    SIP_WARNING = 422,
    SERVER_SIGNATURE = 423,
    SERVER_HEADER = 424,
    USER_AGENT_HEADER = 425,
    REPLY_TO_VIA = 426,
    LOADMODULE = 427,
    LOADPATH = 428,
    MODPARAM = 429,
    CFGENGINE = 430,
    MAXBUFFER = 431,
    SQL_BUFFER_SIZE = 432,
    USER = 433,
    GROUP = 434,
    CHROOT = 435,
    WDIR = 436,
    RUNDIR = 437,
    MHOMED = 438,
    DISABLE_TCP = 439,
    TCP_ACCEPT_ALIASES = 440,
    TCP_ACCEPT_UNIQUE = 441,
    TCP_CONNECTION_MATCH = 442,
    TCP_CHILDREN = 443,
    TCP_CONNECT_TIMEOUT = 444,
    TCP_SEND_TIMEOUT = 445,
    TCP_CON_LIFETIME = 446,
    TCP_POLL_METHOD = 447,
    TCP_MAX_CONNECTIONS = 448,
    TLS_MAX_CONNECTIONS = 449,
    TCP_NO_CONNECT = 450,
    TCP_SOURCE_IPV4 = 451,
    TCP_SOURCE_IPV6 = 452,
    TCP_OPT_FD_CACHE = 453,
    TCP_OPT_BUF_WRITE = 454,
    TCP_OPT_CONN_WQ_MAX = 455,
    TCP_OPT_WQ_MAX = 456,
    TCP_OPT_RD_BUF = 457,
    TCP_OPT_WQ_BLK = 458,
    TCP_OPT_DEFER_ACCEPT = 459,
    TCP_OPT_DELAYED_ACK = 460,
    TCP_OPT_SYNCNT = 461,
    TCP_OPT_LINGER2 = 462,
    TCP_OPT_KEEPALIVE = 463,
    TCP_OPT_KEEPIDLE = 464,
    TCP_OPT_KEEPINTVL = 465,
    TCP_OPT_KEEPCNT = 466,
    TCP_OPT_CRLF_PING = 467,
    TCP_OPT_ACCEPT_NO_CL = 468,
    TCP_OPT_ACCEPT_HEP3 = 469,
    TCP_OPT_ACCEPT_HAPROXY = 470,
    TCP_CLONE_RCVBUF = 471,
    TCP_REUSE_PORT = 472,
    DISABLE_TLS = 473,
    ENABLE_TLS = 474,
    TLSLOG = 475,
    TLS_PORT_NO = 476,
    TLS_METHOD = 477,
    TLS_HANDSHAKE_TIMEOUT = 478,
    TLS_SEND_TIMEOUT = 479,
    SSLv23 = 480,
    SSLv2 = 481,
    SSLv3 = 482,
    TLSv1 = 483,
    TLS_VERIFY = 484,
    TLS_REQUIRE_CERTIFICATE = 485,
    TLS_CERTIFICATE = 486,
    TLS_PRIVATE_KEY = 487,
    TLS_CA_LIST = 488,
    DISABLE_SCTP = 489,
    ENABLE_SCTP = 490,
    SCTP_CHILDREN = 491,
    ADVERTISED_ADDRESS = 492,
    ADVERTISED_PORT = 493,
    DISABLE_CORE = 494,
    OPEN_FD_LIMIT = 495,
    SHM_MEM_SZ = 496,
    SHM_FORCE_ALLOC = 497,
    MLOCK_PAGES = 498,
    REAL_TIME = 499,
    RT_PRIO = 500,
    RT_POLICY = 501,
    RT_TIMER1_PRIO = 502,
    RT_TIMER1_POLICY = 503,
    RT_TIMER2_PRIO = 504,
    RT_TIMER2_POLICY = 505,
    MCAST_LOOPBACK = 506,
    MCAST_TTL = 507,
    MCAST = 508,
    TOS = 509,
    PMTU_DISCOVERY = 510,
    KILL_TIMEOUT = 511,
    MAX_WLOOPS = 512,
    PVBUFSIZE = 513,
    PVBUFSLOTS = 514,
    PVCACHELIMIT = 515,
    PVCACHEACTION = 516,
    HTTP_REPLY_PARSE = 517,
    VERSION_TABLE_CFG = 518,
    VERBOSE_STARTUP = 519,
    ROUTE_LOCKS_SIZE = 520,
    CFG_DESCRIPTION = 521,
    SERVER_ID = 522,
    KEMI = 523,
    ONSEND_ROUTE_CALLBACK = 524,
    REPLY_ROUTE_CALLBACK = 525,
    EVENT_ROUTE_CALLBACK = 526,
    RECEIVED_ROUTE_CALLBACK = 527,
    RECEIVED_ROUTE_MODE = 528,
    MAX_RECURSIVE_LEVEL = 529,
    MAX_BRANCHES_PARAM = 530,
    LATENCY_CFG_LOG = 531,
    LATENCY_LOG = 532,
    LATENCY_LIMIT_DB = 533,
    LATENCY_LIMIT_ACTION = 534,
    LATENCY_LIMIT_CFG = 535,
    MSG_TIME = 536,
    ONSEND_RT_REPLY = 537,
    URI_HOST_EXTRA_CHARS = 538,
    FLAGS_DECL = 539,
    AVPFLAGS_DECL = 540,
    ATTR_MARK = 541,
    SELECT_MARK = 542,
    ATTR_FROM = 543,
    ATTR_TO = 544,
    ATTR_FROMURI = 545,
    ATTR_TOURI = 546,
    ATTR_FROMUSER = 547,
    ATTR_TOUSER = 548,
    ATTR_FROMDOMAIN = 549,
    ATTR_TODOMAIN = 550,
    ATTR_GLOBAL = 551,
    ADDEQ = 552,
    SUBST = 553,
    SUBSTDEF = 554,
    SUBSTDEFS = 555,
    EQUAL = 556,
    LOG_OR = 557,
    LOG_AND = 558,
    BIN_OR = 559,
    BIN_AND = 560,
    BIN_XOR = 561,
    BIN_LSHIFT = 562,
    BIN_RSHIFT = 563,
    EQUAL_T = 564,
    DIFF = 565,
    MATCH = 566,
    INTEQ = 567,
    INTDIFF = 568,
    STREQ = 569,
    STRDIFF = 570,
    GT = 571,
    LT = 572,
    GTE = 573,
    LTE = 574,
    PLUS = 575,
    MINUS = 576,
    STAR = 577,
    SLASH = 578,
    MODULO = 579,
    NOT = 580,
    UNARY = 581,
    BIN_NOT = 582,
    DEFINED = 583,
    INTCAST = 584,
    STRCAST = 585,
    DOT = 586,
    STRLEN = 587,
    STREMPTY = 588,
    NUMBER = 589,
    ID = 590,
    NUM_ID = 591,
    STRING = 592,
    IPV6ADDR = 593,
    PVAR = 594,
    AVP_OR_PVAR = 595,
    EVENT_RT_NAME = 596,
    COMMA = 597,
    SEMICOLON = 598,
    RPAREN = 599,
    LPAREN = 600,
    LBRACE = 601,
    RBRACE = 602,
    LBRACK = 603,
    RBRACK = 604,
    CR = 605,
    COLON = 606
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 196 "core/cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct case_stms* case_stms;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct name_lst* name_l;
	struct avp_spec* attr;
	struct _pv_spec* pvar;
	struct lvalue* lval;
	struct rvalue* rval;
	struct rval_expr* rv_expr;
	select_t* select;

#line 650 "core/cfg.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  467
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11967

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  352
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  907
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1693

#define YYUNDEFTOK  2
#define YYMAXUTOK   606

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   626,   626,   629,   630,   631,   634,   635,   636,   637,
     638,   639,   639,   640,   640,   641,   642,   642,   643,   643,
     644,   644,   645,   646,   649,   665,   673,   687,   688,   694,
     695,   699,   700,   701,   702,   703,   706,   707,   708,   709,
     710,   711,   712,   715,   716,   719,   720,   721,   722,   723,
     727,   728,   729,   730,   731,   735,   736,   739,   740,   743,
     744,   746,   747,   750,   753,   759,   760,   764,   765,   768,
     769,   772,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   789,   790,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   812,   813,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   833,   835,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     878,   881,   882,   885,   886,   889,   890,   891,   892,   895,
     896,   899,   900,   903,   904,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   938,   939,   940,   941,
     942,   943,   944,   945,   946,   949,   950,   957,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   986,   987,   994,   995,  1002,  1003,
    1010,  1011,  1018,  1019,  1026,  1027,  1034,  1035,  1045,  1046,
    1060,  1074,  1075,  1082,  1083,  1090,  1091,  1098,  1099,  1108,
    1109,  1118,  1119,  1126,  1127,  1134,  1135,  1142,  1143,  1150,
    1151,  1158,  1159,  1166,  1167,  1174,  1175,  1182,  1183,  1190,
    1191,  1198,  1199,  1206,  1207,  1214,  1215,  1222,  1223,  1230,
    1231,  1238,  1239,  1246,  1247,  1254,  1255,  1262,  1264,  1271,
    1272,  1283,  1284,  1291,  1292,  1299,  1300,  1307,  1308,  1315,
    1316,  1323,  1330,  1337,  1344,  1351,  1358,  1359,  1366,  1367,
    1374,  1375,  1382,  1383,  1390,  1391,  1398,  1399,  1406,  1407,
    1414,  1415,  1422,  1423,  1430,  1431,  1432,  1433,  1436,  1437,
    1440,  1441,  1442,  1443,  1444,  1445,  1457,  1470,  1483,  1485,
    1496,  1497,  1498,  1499,  1505,  1506,  1516,  1517,  1518,  1519,
    1520,  1521,  1528,  1529,  1536,  1537,  1538,  1539,  1540,  1541,
    1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,
    1552,  1553,  1560,  1561,  1568,  1569,  1576,  1583,  1584,  1585,
    1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,
    1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,
    1632,  1633,  1634,  1635,  1644,  1645,  1654,  1655,  1664,  1665,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1697,  1698,  1700,  1702,  1703,  1704,  1707,  1708,
    1711,  1712,  1713,  1716,  1717,  1720,  1721,  1722,  1730,  1735,
    1740,  1745,  1750,  1753,  1758,  1766,  1772,  1773,  1783,  1784,
    1794,  1795,  1804,  1813,  1814,  1820,  1821,  1827,  1831,  1832,
    1835,  1864,  1879,  1880,  1884,  1895,  1896,  1900,  1901,  1905,
    1912,  1928,  1929,  1932,  1935,  1942,  1958,  1962,  1963,  1968,
    1968,  1975,  1976,  1978,  1977,  2000,  2005,  2008,  2015,  2031,
    2034,  2037,  2044,  2060,  2063,  2066,  2083,  2086,  2087,  2088,
    2089,  2090,  2091,  2113,  2114,  2115,  2116,  2119,  2120,  2121,
    2122,  2125,  2126,  2132,  2133,  2134,  2135,  2136,  2137,  2138,
    2141,  2142,  2143,  2144,  2151,  2152,  2153,  2160,  2161,  2162,
    2166,  2167,  2168,  2169,  2170,  2175,  2176,  2179,  2180,  2181,
    2187,  2189,  2191,  2192,  2194,  2196,  2198,  2200,  2202,  2203,
    2205,  2206,  2207,  2208,  2210,  2212,  2214,  2216,  2218,  2220,
    2221,  2257,  2259,  2261,  2263,  2266,  2268,  2270,  2272,  2276,
    2277,  2288,  2289,  2293,  2294,  2309,  2324,  2325,  2328,  2329,
    2330,  2342,  2343,  2358,  2373,  2375,  2382,  2424,  2425,  2428,
    2429,  2430,  2433,  2434,  2435,  2436,  2437,  2438,  2439,  2440,
    2443,  2451,  2461,  2478,  2485,  2492,  2499,  2506,  2511,  2516,
    2517,  2518,  2519,  2520,  2523,  2532,  2539,  2564,  2580,  2581,
    2586,  2605,  2614,  2626,  2641,  2642,  2645,  2645,  2655,  2656,
    2657,  2658,  2659,  2660,  2661,  2662,  2663,  2666,  2669,  2670,
    2673,  2680,  2683,  2690,  2696,  2697,  2706,  2707,  2708,  2711,
    2712,  2724,  2748,  2759,  2790,  2794,  2804,  2818,  2830,  2831,
    2833,  2834,  2835,  2849,  2850,  2851,  2852,  2853,  2854,  2855,
    2859,  2860,  2861,  2874,  2880,  2881,  2882,  2883,  2884,  2885,
    2886,  2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,  2912,
    2913,  2914,  2915,  2916,  2917,  2918,  2919,  2920,  2921,  2922,
    2923,  2924,  2925,  2926,  2927,  2928,  2930,  2932,  2933,  2934,
    2935,  2936,  2939,  2957,  2958,  2959,  2962,  2963,  2964,  2965,
    2966,  2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2975,
    2976,  2977,  2978,  2979,  2980,  2981,  2982,  2983,  2984,  2985,
    2986,  2987,  2988,  2989,  2990,  2991,  2992,  2993,  2994,  2995,
    2996,  3004,  3012,  3020,  3028,  3036,  3044,  3052,  3060,  3068,
    3069,  3071,  3079,  3087,  3095,  3104,  3113,  3122,  3130,  3139,
    3147,  3148,  3150,  3153,  3154,  3155,  3156,  3163,  3170,  3171,
    3177,  3184,  3185,  3191,  3198,  3199,  3205,  3208,  3211,  3212,
    3213,  3216,  3217,  3218,  3227,  3236,  3237,  3238,  3239,  3240,
    3241,  3242,  3243,  3244,  3245,  3246,  3247,  3248,  3249,  3250,
    3251,  3252,  3253,  3257,  3261,  3262,  3263,  3264,  3265,  3266,
    3267,  3268,  3269,  3270,  3271,  3272,  3273,  3274,  3275,  3276,
    3277,  3278,  3279,  3280,  3281,  3282,  3283,  3284,  3285,  3286,
    3287,  3288,  3296,  3304,  3312,  3313,  3315,  3317,  3328,  3329,
    3330,  3346,  3347,  3348,  3352,  3355,  3356,  3359,  3362,  3365,
    3368,  3371,  3374,  3377,  3380,  3383,  3386,  3387,  3388,  3391,
    3392,  3393,  3393,  3419,  3421,  3423,  3424,  3427,  3444,  3448,
    3452,  3456,  3461,  3465,  3470,  3474,  3478,  3482
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "FORWARD_TCP", "FORWARD_TLS",
  "FORWARD_SCTP", "FORWARD_UDP", "EXIT", "DROP", "RETURN", "BREAK",
  "LOG_TOK", "ERROR", "ROUTE", "ROUTE_REQUEST", "ROUTE_FAILURE",
  "ROUTE_ONREPLY", "ROUTE_REPLY", "ROUTE_BRANCH", "ROUTE_SEND",
  "ROUTE_EVENT", "EXEC", "SET_HOST", "SET_HOSTPORT", "SET_HOSTPORTTRANS",
  "PREFIX", "STRIP", "STRIP_TAIL", "SET_USERPHONE", "APPEND_BRANCH",
  "REMOVE_BRANCH", "CLEAR_BRANCHES", "SET_USER", "SET_USERPASS",
  "SET_PORT", "SET_URI", "REVERT_URI", "FORCE_RPORT", "ADD_LOCAL_RPORT",
  "FORCE_TCP_ALIAS", "UDP_MTU", "UDP_MTU_TRY_PROTO", "UDP4_RAW",
  "UDP4_RAW_MTU", "UDP4_RAW_TTL", "IF", "ELSE", "SET_ADV_ADDRESS",
  "SET_ADV_PORT", "FORCE_SEND_SOCKET", "SET_FWD_NO_CONNECT",
  "SET_RPL_NO_CONNECT", "SET_FWD_CLOSE", "SET_RPL_CLOSE", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "CFG_SELECT", "CFG_RESET", "URIHOST", "URIPORT",
  "MAX_LEN", "SETFLAG", "RESETFLAG", "ISFLAGSET", "SETAVPFLAG",
  "RESETAVPFLAG", "ISAVPFLAGSET", "METHOD", "URI", "FROM_URI", "TO_URI",
  "SRCIP", "SRCPORT", "DSTIP", "DSTPORT", "TOIP", "TOPORT", "SNDIP",
  "SNDPORT", "SNDPROTO", "SNDAF", "PROTO", "AF", "MYSELF", "MSGLEN", "UDP",
  "TCP", "TLS", "SCTP", "WS", "WSS", "DEBUG_V", "FORK", "FORK_DELAY",
  "MODINIT_DELAY", "LOGSTDERROR", "LOGFACILITY", "LOGNAME", "LOGCOLOR",
  "LOGPREFIX", "LOGPREFIXMODE", "LOGENGINETYPE", "LOGENGINEDATA",
  "XAVPVIAPARAMS", "XAVPVIAFIELDS", "LISTEN", "ADVERTISE", "ALIAS",
  "SR_AUTO_ALIASES", "DNS", "REV_DNS", "DNS_TRY_IPV6", "DNS_TRY_NAPTR",
  "DNS_SRV_LB", "DNS_UDP_PREF", "DNS_TCP_PREF", "DNS_TLS_PREF",
  "DNS_SCTP_PREF", "DNS_RETR_TIME", "DNS_SLOW_QUERY_MS", "DNS_RETR_NO",
  "DNS_SERVERS_NO", "DNS_USE_SEARCH", "DNS_SEARCH_FMATCH",
  "DNS_NAPTR_IGNORE_RFC", "DNS_CACHE_INIT", "DNS_USE_CACHE",
  "DNS_USE_FAILOVER", "DNS_CACHE_FLAGS", "DNS_CACHE_NEG_TTL",
  "DNS_CACHE_MIN_TTL", "DNS_CACHE_MAX_TTL", "DNS_CACHE_MEM",
  "DNS_CACHE_GC_INT", "DNS_CACHE_DEL_NONEXP", "DNS_CACHE_REC_PREF",
  "AUTO_BIND_IPV6", "BIND_IPV6_LINK_LOCAL", "DST_BLST_INIT",
  "USE_DST_BLST", "DST_BLST_MEM", "DST_BLST_TTL", "DST_BLST_GC_INT",
  "DST_BLST_UDP_IMASK", "DST_BLST_TCP_IMASK", "DST_BLST_TLS_IMASK",
  "DST_BLST_SCTP_IMASK", "IP_FREE_BIND", "PORT", "STAT", "CHILDREN",
  "SOCKET_WORKERS", "ASYNC_WORKERS", "ASYNC_USLEEP", "ASYNC_NONBLOCK",
  "CHECK_VIA", "PHONE2TEL", "MEMLOG", "MEMDBG", "MEMSUM", "MEMSAFETY",
  "MEMJOIN", "MEMSTATUSMODE", "CORELOG", "SIP_WARNING", "SERVER_SIGNATURE",
  "SERVER_HEADER", "USER_AGENT_HEADER", "REPLY_TO_VIA", "LOADMODULE",
  "LOADPATH", "MODPARAM", "CFGENGINE", "MAXBUFFER", "SQL_BUFFER_SIZE",
  "USER", "GROUP", "CHROOT", "WDIR", "RUNDIR", "MHOMED", "DISABLE_TCP",
  "TCP_ACCEPT_ALIASES", "TCP_ACCEPT_UNIQUE", "TCP_CONNECTION_MATCH",
  "TCP_CHILDREN", "TCP_CONNECT_TIMEOUT", "TCP_SEND_TIMEOUT",
  "TCP_CON_LIFETIME", "TCP_POLL_METHOD", "TCP_MAX_CONNECTIONS",
  "TLS_MAX_CONNECTIONS", "TCP_NO_CONNECT", "TCP_SOURCE_IPV4",
  "TCP_SOURCE_IPV6", "TCP_OPT_FD_CACHE", "TCP_OPT_BUF_WRITE",
  "TCP_OPT_CONN_WQ_MAX", "TCP_OPT_WQ_MAX", "TCP_OPT_RD_BUF",
  "TCP_OPT_WQ_BLK", "TCP_OPT_DEFER_ACCEPT", "TCP_OPT_DELAYED_ACK",
  "TCP_OPT_SYNCNT", "TCP_OPT_LINGER2", "TCP_OPT_KEEPALIVE",
  "TCP_OPT_KEEPIDLE", "TCP_OPT_KEEPINTVL", "TCP_OPT_KEEPCNT",
  "TCP_OPT_CRLF_PING", "TCP_OPT_ACCEPT_NO_CL", "TCP_OPT_ACCEPT_HEP3",
  "TCP_OPT_ACCEPT_HAPROXY", "TCP_CLONE_RCVBUF", "TCP_REUSE_PORT",
  "DISABLE_TLS", "ENABLE_TLS", "TLSLOG", "TLS_PORT_NO", "TLS_METHOD",
  "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "SSLv23", "SSLv2", "SSLv3",
  "TLSv1", "TLS_VERIFY", "TLS_REQUIRE_CERTIFICATE", "TLS_CERTIFICATE",
  "TLS_PRIVATE_KEY", "TLS_CA_LIST", "DISABLE_SCTP", "ENABLE_SCTP",
  "SCTP_CHILDREN", "ADVERTISED_ADDRESS", "ADVERTISED_PORT", "DISABLE_CORE",
  "OPEN_FD_LIMIT", "SHM_MEM_SZ", "SHM_FORCE_ALLOC", "MLOCK_PAGES",
  "REAL_TIME", "RT_PRIO", "RT_POLICY", "RT_TIMER1_PRIO",
  "RT_TIMER1_POLICY", "RT_TIMER2_PRIO", "RT_TIMER2_POLICY",
  "MCAST_LOOPBACK", "MCAST_TTL", "MCAST", "TOS", "PMTU_DISCOVERY",
  "KILL_TIMEOUT", "MAX_WLOOPS", "PVBUFSIZE", "PVBUFSLOTS", "PVCACHELIMIT",
  "PVCACHEACTION", "HTTP_REPLY_PARSE", "VERSION_TABLE_CFG",
  "VERBOSE_STARTUP", "ROUTE_LOCKS_SIZE", "CFG_DESCRIPTION", "SERVER_ID",
  "KEMI", "ONSEND_ROUTE_CALLBACK", "REPLY_ROUTE_CALLBACK",
  "EVENT_ROUTE_CALLBACK", "RECEIVED_ROUTE_CALLBACK", "RECEIVED_ROUTE_MODE",
  "MAX_RECURSIVE_LEVEL", "MAX_BRANCHES_PARAM", "LATENCY_CFG_LOG",
  "LATENCY_LOG", "LATENCY_LIMIT_DB", "LATENCY_LIMIT_ACTION",
  "LATENCY_LIMIT_CFG", "MSG_TIME", "ONSEND_RT_REPLY",
  "URI_HOST_EXTRA_CHARS", "FLAGS_DECL", "AVPFLAGS_DECL", "ATTR_MARK",
  "SELECT_MARK", "ATTR_FROM", "ATTR_TO", "ATTR_FROMURI", "ATTR_TOURI",
  "ATTR_FROMUSER", "ATTR_TOUSER", "ATTR_FROMDOMAIN", "ATTR_TODOMAIN",
  "ATTR_GLOBAL", "ADDEQ", "SUBST", "SUBSTDEF", "SUBSTDEFS", "EQUAL",
  "LOG_OR", "LOG_AND", "BIN_OR", "BIN_AND", "BIN_XOR", "BIN_LSHIFT",
  "BIN_RSHIFT", "EQUAL_T", "DIFF", "MATCH", "INTEQ", "INTDIFF", "STREQ",
  "STRDIFF", "GT", "LT", "GTE", "LTE", "PLUS", "MINUS", "STAR", "SLASH",
  "MODULO", "NOT", "UNARY", "BIN_NOT", "DEFINED", "INTCAST", "STRCAST",
  "DOT", "STRLEN", "STREMPTY", "NUMBER", "ID", "NUM_ID", "STRING",
  "IPV6ADDR", "PVAR", "AVP_OR_PVAR", "EVENT_RT_NAME", "COMMA", "SEMICOLON",
  "RPAREN", "LPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "CR",
  "COLON", "$accept", "cfg", "statements", "statement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "listen_id", "listen_id_lst", "listen_id2", "proto",
  "eqproto", "port", "phostport", "listen_phostport", "id_lst", "intno",
  "flags_decl", "flag_list", "flag_spec", "flag_name", "avpflags_decl",
  "avpflag_list", "avpflag_spec", "assign_stm", "cfg_var_id",
  "cfg_var_idn", "cfg_var", "module_stm", "ip", "ipv4", "ipv6addr", "ipv6",
  "route_name", "route_main", "route_stm", "failure_route_main",
  "failure_route_stm", "route_reply_main", "onreply_route_stm", "$@6",
  "$@7", "branch_route_main", "branch_route_stm", "send_route_main",
  "send_route_stm", "event_route_main", "event_route_stm",
  "preprocess_stm", "equalop", "cmpop", "strop", "rve_equalop",
  "rve_cmpop", "uri_type", "eint_op_onsend", "eint_op", "eip_op_onsend",
  "eip_op", "exp_elem", "ipnet", "host", "host_if_id", "host_or_if",
  "fcmd", "stm", "actions", "action", "if_cmd", "ct_rval", "single_case",
  "case_stms", "switch_cmd", "while_cmd", "select_param", "select_params",
  "select_id", "$@8", "attr_class_spec", "attr_name_spec", "attr_spec",
  "attr_mark", "attr_id", "attr_id_num_idx", "attr_id_no_idx",
  "attr_id_ass", "attr_id_any", "attr_id_any_str", "pvar", "avp_pvar",
  "assign_op", "lval", "rval", "rve_un_op", "rval_expr", "assign_action",
  "avpflag_oper", "cmd", "$@9", "func_params", "func_param", "ret_cmd", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606
};
# endif

#define YYPACT_NINF -1166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1166)))

#define YYTABLE_NINF -892

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2402,  -269,    59,     6,  -230,  -224,  -180,  -175,  -157,  -145,
   -1166,  -140,   -75,   -62,   -57,   -54,   -30,   -27,    -2,   288,
     371,   417,   448,   476,   481,   505,   509,   513,   514,   527,
      46,   203,   214,   308,   312,   604,   738,   753,   825,   826,
     838,   839,   843,   857,   861,   866,   883,   884,   885,   889,
     890,   891,   892,   893,   894,   896,   900,   902,   915,   938,
     949,   951,   960,   963,   966,   969,   545,   550,   565,   574,
     598,   609,   611,   643,   644,   665,   670,   705,   718,   731,
     764,   766,   793,   844,   847,   852,   853,   121,   149,    53,
     161,   868,   878,   879,   882,   904,   910,   913,   914,   936,
     937,   958,   962,   967,   968,   973,   978,   991,   992,  1004,
    1017,  1021,  1023,  1027,  1028,   985,   987,   989,   990,  1030,
    1031,  1033,  1034,  1035,  1037,  1039,  1044,  1065,  1119,  1120,
    1124,  1125,  1131,  1135,  1141,  1142,  1143,  1144,  1150,  1157,
    1158,  1160,  1161,  1163,  1164,  1210,  1211,  1212,  1213,  1214,
    1216,  1217,  1218,  1219,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1240,   993,  1241,  1242,  1243,
    1245,  1246,  1252,  1253,  1254,  1255,  1256,  1257,   -13,  1258,
    1259,  1260,  1261,  1262,  1287,  1288,  1289,  1290,  1292,  1293,
     209,   223,   135,   179,   202, -1166, -1166, -1166,   324,  1507,
   -1166,   292,   539,   323,   607,   908, -1166, -1166, -1166,  -267,
   -1166, -1166,   554, -1166, -1166, -1166, -1166,  -128, -1166,   176,
     185,   837,   327,   215,   222,   332,   242,   299,   301,   321,
      45,   216,   325,   230,   326,   231,   245,   250,   254,    84,
     145,   331,   495,   600, -1166,   661, -1166,   679, -1166,   697,
   -1166,  -186, -1166,  -186, -1166,  -186, -1166,  -186, -1166,   703,
   -1166,   710, -1166,   711, -1166,   722, -1166,   726, -1166,   734,
   -1166,   746, -1166,   758, -1166,   763, -1166,   834, -1166,   950,
   -1166,  1045, -1166,  1206, -1166,  1264, -1166,  1265, -1166,  1282,
   -1166,  1325, -1166,  1398, -1166,  1399, -1166,  1400, -1166,  1401,
   -1166,  1439, -1166,  1442, -1166,  1443, -1166,  1444, -1166,  1445,
   -1166,  1459, -1166,  1460, -1166,  1461,   336,   617,   628,   662,
     677,   678,   680,   684,   686,   337,   488,   490,   516,   549,
     553,   568,   687,   688,   255,   256,   689, -1166, -1166, -1166,
     257, -1166, -1166,   905, -1166,   258, -1166,   690,   691,   224,
     228,   236,   237,   240,   692,   693,   694,   695,   699,   700,
     577,   583,   601,   244,   707,   708,   709,   712,    23,   713,
     714, -1166,  1462, -1166,  1463, -1166,  1464, -1166,  1465,   715,
     716,   719,   721,   723,   724,   725,   727,   728,   729,   730,
     735,   736,   737,   739,   740,   741,   742,  1029,   743,   744,
     745,   747,   259,   260,   261,   749,   750,   751,    55,   755,
     756,   757,   759,   761,   762,   765,   767,   768,   773,   774,
     775,   777,   778,   779,   248,   109, -1166,  1466,   783,   784,
     785,   786,   787,   788,   789,   262,   790,   791,   796,   501,
     602,  1467,  1468,   653,   676,   797,   798,   799,   800,   801,
     263, -1166, -1166, -1166, -1166,  1491,  1244, -1166, -1166, -1166,
    1492, -1166, -1166, -1166, -1166, -1166, -1166, -1166,  -269, -1166,
      65,    41,   706, -1166,    66,   752, -1166,    82,   754, -1166,
      92,  1250, -1166,    17,  1249, -1166,   -31,  1469, -1166, -1166,
   -1166, -1166,  1455, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166,  1474, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166,  1478, -1166, -1166, -1166, -1166,  1093,  1497, -1166,  1485,
    1486,  1118,  1729, -1166, -1166, -1166, -1166, -1166,  -262, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166,  1498, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166,  1478, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166,  1538,  1540,  1542,  1543, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166,  -135,  1511,  -135, -1166,  -128,
   -1166, 11624, -1166,  -128, 11624, -1166,  -128, 11624, -1166,  -128,
   11624, -1166,  1505, -1166, -1166, -1166,  1546,  1499, 11624,    48,
   -1166,  1515,  1509,  1510,  1504,     9,  1112, -1166,  1093,   304,
     307,  1518,   267,   269,   278,   279, -1166, -1166, -1166,  1521,
      72,    78,    86,    96,   101, 10542, 10886, 10971, -1166,   116,
     124,   126,  1526,   128,   129,   130,   131,   132,   133,   140,
     142,  1527,   150,   163,   166,   167,  1528,  1529,  1530,  1531,
    1551, 11056,   169,   175,   181,  1553,  1554,  1555,  1557,  6230,
   11056,   182,   188,   192,   193,   195, -1166, -1166, -1166, -1166,
     196, -1166, -1166, -1166,    15,  3501, -1166, -1166, -1166, -1166,
    1007, -1166, -1166, -1166, -1166, -1166,  1584,  1568,   198, -1166,
    1569,  1567,  3575,  1577,  3655,  1590,  3920,  1591,    90,  1586,
    4000, -1166,  1572,  1610,  1093, -1166, -1166, -1166, -1166, -1166,
   -1166,  1592,  1593, -1166, -1166, -1166, -1166, -1166,  1600, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166,  1599, -1166,    11,
   -1166,    19, -1166,    40, -1166,    62, -1166,   118,   832, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
     498, -1166,   498, -1166,   663, -1166, -1166,  1474, -1166, -1166,
    6317,  6404,  6750,  1609,  1620, -1166,  5364, 11554, -1166,   846,
   -1166,   856, -1166,   867, -1166, -1166, -1166,  1007, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166,  6837,  1263,  5710,  1263,  5797,
    1263, -1166,   111, -1166,   282, -1166,  6924,  1630, -1166,   283,
   -1166,   284, -1166,   285, -1166,   286, -1166,   802, -1166,   803,
   -1166,  1624, -1166,   213,  1625, -1166,   287, -1166,   289, -1166,
     291, -1166,   293,  1627,  1636,  1637,    51,   842,  7270, 10475,
   -1166,    99, -1166,   804, -1166,   187,  1641,  1642,  1643,  1651,
   -1166,  1078, 10475, -1166,   295, -1166,   297, -1166,  -107, -1166,
     664, -1166,   701, -1166,  1663, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
    1678, -1166,  1662, -1166, 11056, -1166, -1166,   211, -1166,  1665,
   -1166,  1666, -1166,  1667, -1166,  1668, -1166,  1757,  1768,   -31,
   -1166, 11624,  1702, -1166,  -272,  1703,  -136, 11624,  1694,  -274,
   -1166,   -32, -1166,   -28,  -266,  1696,    -8,   411,   439,   983,
    1705,   479,   599,   658,   995,  1706,   854,   860,   880,   999,
    1710,   909,   916,   931,  1002, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166,  7357,  5178,  5271, -1166,  1239,  1720, -1166, -1166,
   -1166, -1166, -1166, -1166,  7444,  7790,  1712, -1166,  1763,  1776,
    1777,  1778,  1165,  1736,  1734,  4069, -1166,  7877, -1166, -1166,
   -1166, -1166, -1166,  7964,  8310, -1166,  2735,  1735, -1166, -1166,
    8397,  8484,  8830,  8917, 11056, 11056, 11056, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,  9004,  9350,
    9437,  9524,  9870,  9957, 10044, -1166, -1166,  1738,  1750,  1759,
    1761,  1764,  1765,    37,  1508,  1774,  1775,  1779,  1780,  1781,
    1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795, -1166,  1796,
   -1166,  1798, -1166,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806, -1166, -1166, -1166,  1807,  1808, -1166,  1809,  1810, 11624,
    2060, -1166,  1811,  1812,  1836,  1837,  1838,  1832,  1833,  1841,
   -1166, -1166, -1166, -1166,    57, -1166,  1843,  1846,  1845,  1847,
    1848,  1849,  1852,  1858,  1859,  1860, 11056,  1870,  1862,  1263,
     941, -1166,  1007, -1166,  1865, -1166, 11624, 11624, 11624, 11624,
    1871,  1872,  1911,  4143,  1882, -1166, -1166,  1873,  1874,  4265,
   -1166,   -23, -1166,  1880, -1166,  1881, -1166,    81,   164,  1885,
   -1166, -1166,   -17, -1166,  1886, -1166,  1887, -1166,  1888, -1166,
   -1166,   -14, -1166,  1889, -1166,  1890, -1166,  1891, -1166, -1166,
      -9, -1166,  1915, -1166,  1916, -1166,  1917, -1166, -1166,    -5,
   -1166,  1918, -1166,  1919, -1166,  1920, -1166, -1166,  1924,  1053,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,  1053,
   -1166, -1166,  1053, -1166, -1166, -1166,  1868, -1166,  1925,  1913,
    2167,  1914,  2406, -1166, -1166, -1166, -1166, -1166, -1166,  1993,
    1053, -1166,  1053, -1166,   912, -1166,  2062,  1478,  1855,  1932,
   -1166,  -162,  1053,  -260, -1166,  2727, -1166,  2943, -1166,  2963,
   -1166,  2895,  1040,  1182,  1094, -1166,   360, -1166,   360, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166,  1053, -1166,   912, -1166,
    1923, -1166, -1166,  1928, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166,  4488, 11485, -1166, -1166, -1166, -1166,
   -1166,   585,  1093, -1166,  1926,  5884,  1910, -1166, -1166,   816,
   -1166, 11400, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
    1263,   945, -1166, -1166, -1166,  -135, -1166, -1166,   253,  4610,
    4679,  4753,  4833, -1166, -1166,  -242, -1166,  1937, -1166, -1166,
   -1166,  1930,  1933,  1934,  1936, -1166, -1166, -1166, -1166,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,
    1949,  1950,  1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,
    -129,  1720, -1166, -1166, -1166, -1166,    35,  1927,  1982,  1983,
   -1166, -1166, -1166, -1166,  1921, -1166,  1987, 10390,  1989,  1263,
   11624, -1166, -1166,  1985,  2876, 11056, -1166,  1986,  1990,  1997,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1166,  1994,  1996, -1166, -1166,  1478, -1166, -1166, -1166,
   -1166,  -272, 11624,  1991,  1995,  2822,  2891, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166,  2960, 11624, 11624, -1166,
    3087,  3310,  3432
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     454,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   453,    22,    23,     0,     0,
       4,     0,     0,     0,     0,     0,     8,     9,     6,     0,
     451,    10,     0,    15,     7,   452,   501,     0,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,   107,     0,   109,     0,
     111,     0,   113,     0,   115,     0,   117,     0,   119,     0,
     121,     0,   123,     0,   125,     0,   127,     0,   129,     0,
     131,     0,   133,     0,   135,     0,   137,     0,   139,     0,
     141,     0,   145,     0,   143,     0,   147,     0,   149,     0,
     151,     0,   153,     0,   155,     0,   157,     0,   159,     0,
     161,     0,   163,     0,   165,     0,   167,     0,   169,     0,
     171,     0,   173,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   465,   468,
       0,   467,   473,     0,   475,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,     0,   269,     0,   271,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    66,    65,    59,    61,    63,    68,    71,    67,
      69,   518,   517,   520,   519,   522,   521,     1,     5,     3,
       0,     0,     0,    12,     0,     0,    14,     0,     0,    17,
       0,     0,    19,     0,     0,    21,     0,     0,   499,   484,
     485,   486,     0,   442,   441,   440,   439,   444,    31,    32,
      33,    34,    35,   443,   446,     0,    57,   445,   448,   447,
     450,   449,    73,    72,    75,    74,    77,    76,    79,    78,
      81,    80,    83,    82,    85,    84,    87,    86,    89,    88,
      91,    90,    93,    92,    95,    94,    97,    96,    99,    98,
     348,   600,   598,   599,    25,   481,     0,     0,    30,    50,
       0,    55,   345,    24,   478,   482,   479,   601,    26,   350,
     349,   352,   351,   101,   100,   103,   102,   104,   106,   108,
     110,   112,   114,   116,   118,   120,   122,   124,   126,   128,
     130,   132,   134,   136,   138,   140,   144,   142,   146,   148,
     150,   152,   154,   156,   158,   160,   162,   164,   166,   168,
     170,   172,   174,   177,   176,   183,   178,   185,   184,   187,
     186,   189,   188,   191,   190,   193,   192,   195,   194,   197,
     196,   199,   198,   201,   200,   203,   202,   205,   204,   207,
     206,   209,   208,   211,   210,   213,   212,   336,   335,   338,
     337,   340,   339,   344,   343,   470,   469,     0,   477,   476,
     180,   179,   182,   181,   218,   217,   216,   221,   220,   219,
     224,   223,   222,   227,   226,   225,   230,   229,   228,   232,
     231,   234,   233,   236,   235,   238,   237,   240,   239,   242,
     241,   244,   243,   246,   245,   248,   247,   251,   249,   250,
     253,   252,   255,   254,   257,   256,   259,     0,   258,   261,
     260,   263,   262,   265,   264,   266,   268,   270,   272,   275,
     274,   277,   276,   279,   278,   281,   280,   283,   282,   285,
     284,   287,   286,   289,   288,   291,   290,   293,   292,   295,
     294,   297,   296,   299,   298,   301,   300,   303,   302,   305,
     304,   307,   306,   309,   308,   314,   310,   311,   312,   313,
     326,   325,   328,   327,   316,   315,   318,   317,   320,   319,
     322,   321,   324,   323,   330,   329,   332,   331,   334,   333,
     354,   353,   356,   355,   358,   357,   360,   359,   362,   361,
     364,   363,   366,   365,   368,   367,   370,   369,   372,   371,
     374,   373,   376,   375,   378,   377,   380,   379,   382,   381,
     384,   383,   387,   385,   386,   390,   388,   389,   391,   394,
     393,   396,   395,   398,   397,   400,   399,   402,   401,   404,
     403,   406,   405,   215,   214,   408,   407,   410,   409,   412,
     411,     0,     0,     0,     0,   422,   421,   423,   424,   428,
     427,   426,   425,   430,   429,   432,   431,   434,   433,   436,
     435,   438,   437,   342,   341,     0,     0,     0,   491,     0,
     492,     0,   496,     0,     0,   509,     0,     0,   513,     0,
       0,   516,     0,   456,   457,   455,     0,     0,     0,     0,
      58,     0,    27,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    64,    70,     0,
       0,     0,     0,     0,     0,   903,   900,   904,   907,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   856,   858,   860,   863,
       0,     0,     0,     0,     0,   877,   879,   881,   883,     0,
       0,     0,     0,     0,     0,     0,   733,   734,   735,   660,
       0,   672,   673,   618,     0,     0,   610,   613,   614,   615,
       0,   664,   665,   675,   676,   677,     0,     0,     0,   606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,    29,   483,    54,    44,    43,
      51,    52,   347,   605,   600,   603,   604,   602,     0,   414,
     413,   416,   415,   418,   417,   420,   419,     0,   746,     0,
     768,     0,   779,     0,   790,     0,   757,     0,     0,   544,
     545,   546,   557,   550,   558,   551,   556,   548,   555,   547,
       0,   549,     0,   552,     0,   553,   646,   692,   690,   691,
       0,     0,     0,     0,     0,   679,     0,     0,   678,     0,
     554,     0,   559,     0,   685,   684,   683,     0,   666,   668,
     667,   680,   681,   682,   693,     0,   902,     0,   899,     0,
     906,   794,     0,   811,     0,   815,     0,     0,   819,     0,
     838,     0,   841,     0,   822,     0,   828,     0,   825,     0,
     831,     0,   834,     0,     0,   847,     0,   850,     0,   844,
       0,   853,     0,     0,     0,     0,     0,     0,     0,     0,
     869,     0,   872,     0,   875,     0,     0,     0,     0,     0,
     638,     0,     0,   886,     0,   889,     0,   798,     0,   801,
       0,   804,     0,   893,     0,   619,   612,   611,   489,   609,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
       0,   658,   661,   674,     0,   617,   809,     0,   616,     0,
     494,     0,   507,     0,   511,     0,   462,   458,   459,     0,
     500,     0,     0,    28,     0,     0,     0,     0,     0,     0,
     593,     0,   736,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   563,   523,   524,   532,   525,
     526,   531,     0,     0,     0,   588,     0,     0,   731,   714,
     716,   695,   717,   696,     0,     0,     0,   901,   666,   667,
     681,   682,     0,     0,     0,     0,   567,     0,   572,   527,
     528,   529,   530,     0,     0,   584,     0,   661,   715,   694,
       0,     0,     0,     0,     0,     0,     0,   533,   534,   539,
     535,   536,   537,   538,   540,   541,   542,   543,     0,     0,
       0,     0,     0,     0,     0,   898,   905,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   830,     0,
     833,     0,   836,     0,     0,     0,     0,     0,     0,     0,
       0,   855,   857,   859,     0,     0,   862,     0,     0,     0,
     620,   607,     0,     0,     0,     0,     0,    45,     0,     0,
     876,   878,   880,   882,     0,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,     0,     0,   732,
       0,   671,     0,   669,     0,   670,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,   346,     0,     0,     0,
     747,     0,   745,     0,   738,     0,   739,     0,     0,     0,
     737,   769,     0,   767,     0,   760,     0,   761,     0,   759,
     780,     0,   778,     0,   771,     0,   772,     0,   770,   791,
       0,   789,     0,   782,     0,   783,     0,   781,   758,     0,
     756,     0,   749,     0,   750,     0,   748,   562,     0,   560,
     578,    36,    37,    38,    39,    40,    41,    42,   576,   577,
     575,   573,   574,   587,   585,   586,   641,   645,   647,     0,
       0,     0,     0,   689,   711,   688,   687,   686,   566,     0,
     564,   571,   569,   570,   568,   583,     0,    57,     0,   591,
     579,   581,   580,     0,   728,   710,   727,   709,   723,   702,
     724,   703,   704,   705,   706,   718,   697,   719,   698,   720,
     699,   721,   700,   722,   701,   726,   708,   725,   707,   795,
       0,   792,   812,     0,   816,   814,   813,   817,   820,   818,
     839,   837,   842,   840,   823,   821,   829,   827,   826,   824,
     835,   832,   848,   846,   851,   849,   845,   843,   854,   852,
     864,   861,   866,   865,     0,     0,   868,   867,   871,   870,
     874,     0,     0,   873,     0,     0,     0,   637,   635,     0,
     887,     0,   890,   888,   796,   797,   799,   800,   802,   803,
     897,     0,   896,   659,   663,     0,   808,   661,     0,     0,
       0,     0,     0,   460,   461,     0,   504,     0,   471,   472,
     490,     0,     0,     0,     0,   597,   595,   596,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   729,   712,   730,   713,     0,     0,     0,     0,
     608,   621,    49,    46,    47,   639,     0,     0,     0,   622,
     628,   636,   634,    57,     0,     0,   892,     0,     0,     0,
     495,   508,   512,   515,   463,   464,   480,   743,   744,   741,
     742,   740,   765,   766,   763,   764,   762,   776,   777,   774,
     775,   773,   787,   788,   785,   786,   784,   754,   755,   752,
     753,   751,     0,     0,   644,   592,   590,   589,   662,   793,
     810,     0,   631,     0,     0,     0,     0,   884,   885,   895,
     807,   806,   805,   643,   642,    48,     0,   632,   626,   633,
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1166, -1166, -1166,  2063, -1166, -1166, -1166, -1166, -1166,  -404,
    1297,  1470,  -219,  1117, -1165, -1166, -1166,  -210,  -222, -1166,
    1494, -1166,  -190, -1166,  1490, -1166, -1166, -1166,  1181, -1166,
   -1166,  -996,  1984,  1813,  2019,   354, -1166, -1166, -1166, -1166,
   -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166, -1166,
   -1166, -1007, -1166,  -938, -1166, -1166,  1136, -1166, -1166, -1166,
    1137, -1166, -1166,  -927,   -94, -1166,  -253, -1116,  -712,  -604,
   -1166,   771,   815, -1166, -1166, -1166,   760, -1166, -1166, -1166,
   -1166,  1008, -1029,  -410,  -856, -1166,  -707, -1166, -1166, -1166,
    -683,  -827, -1166, -1166, -1166, -1166,   -25,  -971, -1166, -1166,
   -1166, -1166,   732, -1166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   548,
     883,   549,   550,  1428,   990,  1329,   551,   552,  1048,   206,
     454,   455,   456,   207,   459,   460,   208,   209,   876,   210,
     211,   553,   554,   555,   556,   492,   472,   473,   475,   476,
     212,   213,   878,   982,   478,   479,   481,   482,   484,   485,
     214,  1211,  1244,  1212,  1273,  1274,  1049,  1050,  1051,  1052,
    1053,  1054,  1460,  1184,   557,   558,  1055,  1320,   955,   956,
     957,  1618,  1538,  1539,   958,   959,  1437,  1438,  1056,  1217,
    1150,  1151,  1152,  1057,  1058,  1059,  1060,   963,  1061,  1354,
    1062,  1063,  1154,   966,  1064,  1065,  1232,   967,   968,   969,
    1134,  1551,  1552,   970
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     507,   458,   503,   513,   771,   961,  1335,   218,   961,  1365,
     987,   961,  1178,  1183,   961,  1188,  1135,  1193,   871,  1198,
    1185,  1203,   961,  1213,   699,  1214,   873,  1216,  1247,   570,
     560,   571,   215,   572,   965,   573,  1665,   965,  1133,  1571,
     965,  1190,   860,   965,  1243,  1580,   522,   244,  1585,   981,
     988,   965,  1314,  1590,   342,  1377,   770,  1595,  1534,   889,
     216,   505,   989,  1195,   486,  1378,   858,   862,  1371,   890,
    1372,   219,  1179,  1008,   506,  1233,  1379,   220,  1380,  1010,
    1186,   487,  1575,   865,  1189,   540,  1194,  1012,  1199,  1554,
    1204,  1166,  1634,   868,   604,  1635,  1233,  1014,  1233,   961,
    1322,  1191,  1016,   622,   624,   626,   628,   630,   632,   634,
     805,  1237,  1277,  1535,  1536,  1246,   961,  1071,   961,  1200,
     961,   221,   337,  1196,   961,  1073,   222,  1075,   965,  1078,
    1080,  1082,  1084,  1086,  1088,   505,   461,  1233,   682,   684,
     686,  1090,   882,  1092,   223,   965,   559,   965,   506,   965,
     339,  1095,   972,   965,   962,   974,   224,   962,   976,  1377,
     962,   225,   344,   962,  1097,  1577,   980,  1099,  1101,  1378,
    1110,   962,   498,   499,   500,   501,  1112,   493,   964,  1201,
     463,   964,  1114,  1123,   964,   505,   495,   964,  1326,  1125,
    1228,   961,   505,  1127,  1129,   964,  1131,  1133,   506,  1156,
     452,  1367,   453,   465,   246,   506,   489,   490,  1662,   491,
     451,  1228,  1350,  1228,  1299,   248,   508,   524,   836,  1231,
     965,   840,   842,   510,   457,   654,   226,  1340,   452,   657,
     453,   528,   532,   498,   499,   500,   501,   660,   663,   227,
    1231,   666,  1231,   514,   228,   687,   534,   229,   962,   802,
    1459,   536,  1228,   961,  1628,   538,   639,   641,   645,   648,
     758,   760,   762,   823,   853,   962,   961,   962,   999,   962,
    1001,   230,   964,   962,   231,   498,   499,   500,   501,  1003,
    1005,  1231,   965,  1280,  1286,  1288,  1290,  1292,  1303,   964,
    1305,   964,  1307,   964,  1309,   965,  1336,   964,  1338,   232,
     516,  1353,   518,   874,   875,   993,   470,   471,   996,   250,
    1373,  1572,  1374,   252,  1375,   961,  1376,  1581,   439,  1461,
    1586,   961,   520,  1557,   467,  1591,   526,   530,   504,  1596,
    1355,   988,   561,   512,  1382,  1235,  1383,   603,   621,  1229,
     962,   887,   477,   989,   965,   697,  1180,   245,  1181,   545,
     965,  1139,  -498,   697,  1180,  1182,  1187,   545,  1136,   547,
    1229,   545,  1229,  1230,   964,  -514,  1613,   547,  1139,  1666,
    1139,   547,  1139,   545,   697,  1180,  1139,  1192,   545,   961,
     523,  1495,  -891,   547,  1230,  1315,  1230,  -488,   547,   541,
     542,   543,   544,   545,  -503,  1316,   697,  1180,   343,  1197,
     545,  1229,   962,   547,  1537,  -497,   502,   217,   965,  1611,
     547,  -487,  -493,   859,   863,   962,  1576,  1009,   541,   542,
     543,   544,   545,  1011,  1167,  1230,   964,  1168,  -506,   546,
     866,  1013,   547,   541,   542,   543,   544,   545,  -510,   964,
     869,  1015,  1216,   806,   807,  1278,  1017,   547,  1279,  1216,
     340,   960,   697,  1180,   960,  1202,   545,   960,   338,  1363,
     960,  1072,   345,   961,   962,  1369,   547,   502,   960,  1074,
     962,  1076,   462,  1079,  1081,  1083,  1085,  1087,  1089,   541,
     542,   543,   544,   545,   992,  1091,   341,  1093,   964,   623,
     546,   625,   965,   547,   964,  1096,   563,   949,   346,  1578,
     961,   961,   961,   961,   247,  1321,  1685,   961,  1098,   502,
     494,  1100,  1102,   961,  1111,   249,   464,   627,  1321,   496,
    1113,   541,   542,   543,   544,   545,  1115,  1124,   962,   965,
     965,   965,   965,  1126,   505,   547,   965,  1128,  1130,   466,
    1132,  -891,   965,  1157,   452,   960,   453,   506,  1351,   509,
     629,   952,   964,   525,   631,   474,   511,  1300,   452,   655,
     453,   656,   960,   658,   960,   659,   960,   529,   533,   633,
     960,   661,   664,   662,   665,   667,   515,   668,   681,   688,
     882,   689,   535,   803,   683,   804,  1612,   537,   452,   233,
     453,   539,   640,   642,   646,   649,   759,   761,   763,   824,
     854,   565,   685,   835,  1000,   254,  1002,  1524,   954,   251,
    1667,   954,   962,   253,   954,  1004,  1006,   954,   605,  1281,
    1287,  1289,  1291,  1293,  1304,   954,  1306,   480,  1308,   607,
    1310,  1139,  1337,   517,  1339,   519,   964,   960,   994,   542,
     543,   994,   542,   543,  1559,  1560,  1561,  1562,   505,   962,
     962,   962,   962,   505,   839,   521,   962,   505,   505,   527,
     531,   506,   962,   609,  1215,   562,   506,   458,   961,   961,
     506,   506,   234,   964,   964,   964,   964,   841,   611,   613,
     964,   615,  1270,  1271,  1272,   617,   964,   619,   635,   637,
     643,   650,   652,   669,   671,   673,   675,   965,   965,   960,
     677,   679,   954,   961,   961,   961,   961,  1323,   690,   692,
     694,  1327,   960,   696,   701,   703,   709,   711,   235,   954,
     713,   954,   715,   954,   717,   719,   721,   954,   723,   725,
     727,   729,   965,   965,   965,   965,   731,   733,   735,   256,
     737,   739,   741,   743,   750,   752,   754,  1352,   756,   236,
     764,   766,   768,  1384,   258,  1385,   772,   774,   776,  1139,
     778,   960,   780,   782,   961,  1139,   784,   960,   786,   788,
     831,   832,   833,   834,   790,   792,   794,   237,   796,   798,
     800,  1386,   238,  1387,   809,   811,   813,   815,   817,   819,
     821,   825,   827,   965,   954,   995,   997,   829,   843,   845,
     847,   849,   851,  1294,  1296,  1324,   239,  1206,  1207,   505,
     240,   505,  1209,  1210,   241,   242,   961,   962,   962,   961,
     961,  1391,   506,  1392,   506,   960,   260,   262,   243,   564,
     961,   961,   961,  1205,   961,   961,   961,   505,   497,   264,
     266,   964,   964,  1317,   268,   965,   316,  1236,   965,   965,
     506,   317,   962,   962,   962,   962,   954,  1238,   270,   965,
     965,   965,   272,   965,   965,   965,   318,   274,  1245,   954,
     505,  1301,  1535,  1536,   505,   319,   964,   964,   964,   964,
    1066,  1068,  1070,   506,   276,   278,   280,   506,  1318,   505,
     282,   284,   286,   288,   290,   292,  1328,   294,   505,   320,
     488,   296,   506,   298,   505,   255,  1109,   988,  1676,   960,
     321,   506,   322,   962,  1121,  1122,   300,   506,   954,   989,
    1139,  1321,   505,   505,   954,   498,   499,   500,   501,   483,
     498,   499,   500,   501,   566,   506,   506,   964,  1341,   302,
    1343,  1393,  1345,  1394,   323,   324,   960,   960,   960,   960,
     304,   606,   306,   960,  1368,  1139,  1139,  1139,  1139,   960,
    1686,   308,   608,  1690,   310,   962,   325,   312,   962,   962,
     314,   326,  1206,  1207,   505,  1691,  1692,  1209,  1210,   962,
     962,   962,   954,   962,   962,   962,   371,   506,   373,   964,
     375,   377,   964,   964,   426,   567,   610,   505,  1342,   452,
    1395,   453,  1396,   964,   964,   964,   327,   964,   964,   964,
     506,   612,   614,   568,   616,  1219,  1221,  1223,   618,   328,
     620,   636,   638,   644,   651,   653,   670,   672,   674,   676,
     745,   569,   329,   678,   680,  1344,   452,   574,   453,   257,
    1249,   691,   693,   695,   575,   576,   697,   702,   704,   710,
     712,  1284,   861,   714,   259,   716,   577,   718,   720,   722,
     578,   724,   726,   728,   730,   330,   954,   331,   579,   732,
     734,   736,  1139,   738,   740,   742,   744,   751,   753,   755,
     580,   757,  1139,   765,   767,   769,  1139,  1139,  1139,   773,
     775,   777,   581,   779,   332,   781,   783,   582,   864,   785,
     867,   787,   789,   954,   954,   954,   954,   791,   793,   795,
     954,   797,   799,   801,   960,   960,   954,   810,   812,   814,
     816,   818,   820,   822,   826,   828,   261,   263,  1614,  1349,
     830,   844,   846,   848,   850,   852,  1295,  1297,  1325,   265,
     267,  1206,  1207,  1208,   269,   333,  1209,  1210,   334,   960,
     960,   960,   960,   335,   336,  1206,  1207,  1208,   271,   502,
    1209,  1210,   273,  1621,   502,  1206,  1207,   275,   583,   347,
    1209,  1210,  1239,  1240,  1241,  1242,  1206,  1207,  1208,   348,
     349,  1209,  1210,   350,   277,   279,   281,  1419,  1429,  1432,
     283,   285,   287,   289,   291,   293,  1400,   295,  1401,  1440,
    1442,   297,  1402,   299,  1403,   351,   498,   499,   500,   501,
     960,   352,  1450,   899,   353,   354,   301,   971,  1452,  1454,
     973,  1462,  1404,   975,  1405,  1465,  1467,  1469,  1471,  1472,
    1473,  1474,  1268,  1269,  1270,  1271,  1272,   355,   356,   303,
    1433,  1607,   647,  1476,  1478,  1480,  1482,  1484,  1486,  1488,
     305,  1409,   307,  1410,   746,   747,   748,   749,  1411,   357,
    1412,   309,   960,   358,   311,   960,   960,   313,   359,   360,
     315,   954,   954,  1413,   361,  1414,   960,   960,   960,   362,
     960,   960,   960,  1555,   584,  1556,   372,  1625,   374,  1626,
     376,   378,   363,   364,   427,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1377,   365,   954,   954,   954,   954,
    1019,  1020,  1021,  1022,  1378,  1024,  1377,  1026,   366,  1028,
    1377,  1550,   367,  1377,   368,  1388,  1378,  1389,   369,   370,
    1378,   379,   380,  1378,   381,   382,   383,  1397,   384,  1398,
     385,  1406,  1149,  1407,  1415,   386,  1416,  1255,  1256,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1627,   387,   954,  1629,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1663,   585,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,   954,
     388,   389,   954,   954,  1334,   390,   391,   541,   542,   543,
     544,   545,   392,   954,   954,   954,   393,   954,   954,   954,
     502,   547,   394,   395,   396,   397,   541,   542,   543,   544,
     545,   398,   541,   542,   543,   544,   545,   546,   399,   400,
     547,   401,   402,   546,   403,   404,   547,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,    -2,   468,  1444,
    1619,   405,   406,   407,   408,   409,  1624,   410,   411,   412,
     413,   -11,   -11,   -13,     2,     3,   -16,   -18,   -20,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     586,   425,   428,   429,   430,     4,   431,   432,     5,     6,
       7,     8,     9,   433,   434,   435,   436,   437,   438,   440,
     441,   442,   443,   444,    10,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,   445,   446,
     447,   448,  1619,   449,   450,   856,   870,   872,   587,   588,
    1550,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   589,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   590,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   591,   592,   593,   594,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   595,   177,   178,   596,   597,   598,   599,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   600,   601,   602,   705,   706,   707,   708,
     808,   837,   838,   877,   879,   192,   193,   194,   880,   881,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,   855,   857,   545,   885,   886,   888,   892,
     891,   893,   195,   894,   895,   897,   977,   978,   979,   983,
     196,   984,  1496,   986,   985,   998,  1133,   197,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    1007,  1077,  1094,  1103,  1104,  1105,  1106,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  1153,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  1107,  -593,  1116,  1117,
    1118,  -593,  1119,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    -593,  1155,  1158,  -593,  -593,  -593,  1159,  1169,  1171,  -593,
    -593,  -593,  -593,  -593,  -593,  1133,  1161,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  1163,
    1165,  1172,  1176,  1174,  1175,  1177,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  1224,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  1225,  -561,  1285,  1298,  1302,
    -561,  1311,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    1312,  1313,  -561,  -561,  -561,  1330,  1331,  1332,  -561,  -561,
    -561,  -561,  -561,  -561,  1215,  1333,  -565,  -565,  -565,  -565,
    -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  1346,  1347,
    1348,  1356,  1357,  1358,  1359,  -565,  -565,  -565,  -565,  -565,
    -565,  -565,  -565,  1360,  -565,  -565,  -565,  -565,  -565,  -565,
    -565,  -565,  -565,  -565,  1361,  -565,  1364,  1366,  1370,  -565,
    1381,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  1390,
    1399,  -565,  -565,  -565,  1408,  1436,  1443,  -565,  -565,  -565,
    -565,  -565,  -565,  1215,  -664,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -665,  -676,  -677,
    1445,  1446,  1489,  1463,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  1490,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  1491,  -582,  1492,  1493,  1525,  -582,  1494,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  1497,  1498,
    -582,  -582,  -582,  1499,  1500,  1501,  -582,  -582,  -582,  -582,
    -582,  -582,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  -593,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,
    1519,  1520,  1521,  1522,  1523,  1526,  1527,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    1528,  1529,  1530,  1531,  1532,  1533,  -593,  1540,  1541,  1542,
    -593,  1543,  1544,  1545,  -593,  -593,  1546,  -593,  -593,  -593,
    -891,  -593,  1547,  1548,  1549,  1149,  -593,  1558,  1563,  1564,
    -561,  1554,  1565,  1567,  1573,  1574,  1600,  1568,  1569,  1579,
    1582,  1583,  1584,  1587,  1588,  1589,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  1592,
    1593,  1594,  1597,  1598,  1599,  1606,  1601,  1602,  1604,  -561,
    1608,  1620,   469,  -561,  -561,  1609,  -561,  -561,  -561,  -891,
    -561,  1636,  1671,  1615,  1637,  -561,  1668,  1638,  1639,  -565,
    1640,  1173,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,  1651,  1652,  1653,  -565,  -565,  -565,  -565,  -565,
    -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,
    -565,  -565,  -565,  -565,  -565,  -565,  -565,  -565,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1669,  1670,  -565,  1677,
    1680,  1431,  -565,  -565,  1681,  -565,  -565,  -565,  1672,  -565,
    1675,  1682,  1687,  1683,  -565,  1684,  1688,   898,  -582,   896,
    1362,   698,  1434,  1435,  1622,  1553,   991,  1679,     0,     0,
     884,  1664,     0,     0,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,   700,  1674,     0,
       0,     0,     0,     0,     0,     0,     0,  -582,     0,     0,
       0,  -582,  -582,     1,  -582,  -582,  -582,     0,  -582,     0,
       0,     0,     0,  -582,     0,     0,   -11,   -11,   -13,     2,
       3,   -16,   -18,   -20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     5,     6,     7,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1271,  1272,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,  1603,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,     0,   177,
     178,     0,     0,     0,     0,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,     0,     0,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,
    1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,
    1272,     0,     0,     0,     0,     0,  1455,   195,   900,   901,
     902,   903,   904,     0,     0,   196,     0,   909,   910,   911,
    1605,     0,   197,     0,     0,     0,     0,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,     0,     0,   932,   933,   934,   935,   936,   937,   938,
       0,     0,     0,     0,   941,   942,     0,     0,     0,   943,
     944,   945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1456,  1035,  1689,     0,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,     0,     0,     0,
       0,     0,     0,     0,   912,   913,   914,   915,   916,   917,
     918,   919,     0,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,     0,   930,     0,     0,     0,   931,     0,
     932,   933,   934,   935,   936,   937,   938,   939,  -625,  -625,
     940,   941,   942,     0,     0,     0,   943,   944,   945,   946,
     947,   948,  1137,     0,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,     0,     0,     0,     0,
       0,     0,     0,   912,   913,   914,   915,   916,   917,   918,
     919,     0,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   929,     0,   930,     0,     0,     0,   931,     0,   932,
     933,   934,   935,   936,   937,   938,   939,  -627,  -627,   940,
     941,   942,     0,     0,     0,   943,   944,   945,   946,   947,
     948,  1137,     0,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,   931,     0,   932,   933,
     934,   935,   936,   937,   938,   939,  -629,  -629,   940,   941,
     942,   949,  1036,     0,   943,   944,   945,   946,   947,   948,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1271,  1272,     0,     0,     0,     0,  1037,     0,     0,     0,
    1038,     0,  1039,  1040,  1041,  1042,     0,  1043,  1044,  1457,
    1458,     0,  1045,   545,   951,   952,     0,     0,     0,     0,
    1108,  1047,     0,   547,     0,     0,     0,     0,  1137,     0,
     900,   901,   902,   903,   904,   905,   906,   907,   908,   909,
     910,   911,     0,     0,     0,     0,     0,     0,   949,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,   931,     0,   932,   933,   934,   935,   936,
     937,   938,   939,  -623,  -623,   940,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,   950,     0,     0,
       0,   951,   952,     0,     0,   953,     0,     0,     0,  -625,
       0,     0,     0,     0,     0,     0,     0,   949,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,
    1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,
    1272,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1678,     0,     0,     0,     0,     0,   950,     0,     0,     0,
     951,   952,     0,     0,   953,     0,     0,     0,  -627,     0,
       0,     0,     0,     0,     0,     0,   949,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,     0,     0,
       0,     0,     0,     0,     0,   950,     0,     0,     0,   951,
     952,     0,     0,   953,     0,     0,     0,  -629,     0,     0,
       0,  1137,     0,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,   931,     0,   932,   933,
     934,   935,   936,   937,   938,   939,  -630,  -630,   940,   941,
     942,     0,     0,   949,   943,   944,   945,   946,   947,   948,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   950,     0,     0,     0,   951,   952,     0,     0,
     953,     0,     0,  1137,  -623,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,     0,     0,     0,
       0,     0,     0,     0,   912,   913,   914,   915,   916,   917,
     918,   919,     0,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,     0,   930,     0,     0,     0,   931,     0,
     932,   933,   934,   935,   936,   937,   938,   939,  -624,  -624,
     940,   941,   942,     0,     0,     0,   943,   944,   945,   946,
     947,   948,  1137,     0,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,     0,     0,     0,     0,
       0,     0,     0,   912,   913,   914,   915,   916,   917,   918,
     919,     0,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   929,     0,   930,     0,     0,     0,   931,     0,   932,
     933,   934,   935,   936,   937,   938,   939,     0,     0,   940,
     941,   942,     0,     0,     0,   943,   944,   945,   946,   947,
     948,     0,     0,     0,     0,     0,  1137,     0,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,     0,     0,   949,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,   931,     0,   932,   933,   934,   935,   936,   937,   938,
     939,     0,     0,   940,   941,   942,     0,     0,     0,   943,
     944,   945,   946,   947,   948,   950,     0,     0,     0,   951,
     952,     0,     0,   953,     0,     0,  1137,  -630,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,     0,     0,     0,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,   931,     0,   932,   933,   934,   935,   936,   937,   938,
     939,     0,     0,   940,   941,   942,     0,     0,   949,   943,
     944,   945,   946,   947,   948,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   950,     0,     0,
       0,   951,   952,     0,     0,   953,     0,     0,     0,  -624,
       0,     0,     0,     0,     0,     0,     0,   949,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   950,     0,     0,     0,
     951,   952,     0,     0,   953,     0,     0,     0,  1138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     950,     0,     0,     0,   951,   952,     0,     0,   953,     0,
       0,  1137,  1160,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,     0,     0,     0,     0,     0,
       0,   949,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,   931,     0,   932,   933,
     934,   935,   936,   937,   938,   939,     0,     0,   940,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
     950,     0,     0,     0,   951,   952,     0,     0,   953,     0,
       0,  1137,  1162,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,   931,     0,   932,   933,
     934,   935,   936,   937,   938,   939,     0,     0,   940,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1137,     0,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,     0,     0,     0,     0,     0,     0,
       0,   912,   913,   914,   915,   916,   917,   918,   919,     0,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
       0,   930,     0,     0,     0,   931,     0,   932,   933,   934,
     935,   936,   937,   938,   939,     0,     0,   940,   941,   942,
       0,     0,     0,   943,   944,   945,   946,   947,   948,     0,
       0,     0,     0,     0,  1137,     0,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,     0,     0,
       0,     0,     0,     0,     0,   912,   913,   914,   915,   916,
     917,   918,   919,     0,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,     0,   930,     0,     0,     0,   931,
       0,   932,   933,   934,   935,   936,   937,   938,   939,     0,
       0,   940,   941,   942,     0,     0,   949,   943,   944,   945,
     946,   947,   948,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   950,     0,     0,     0,   951,
     952,     0,     0,   953,     0,     0,  1137,  1164,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,     0,     0,   949,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,   931,     0,   932,   933,   934,   935,   936,   937,   938,
     939,     0,     0,   940,   941,   942,     0,     0,     0,   943,
     944,   945,   946,   947,   948,   950,     0,     0,     0,   951,
     952,     0,     0,   953,     0,     0,     0,  1170,     0,     0,
       0,     0,     0,     0,     0,   949,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   950,     0,     0,     0,   951,   952,
       0,     0,   953,     0,     0,     0,  1447,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   950,     0,
       0,     0,   951,   952,     0,     0,   953,     0,     0,  1137,
    1566,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,     0,     0,     0,     0,     0,     0,     0,
     912,   913,   914,   915,   916,   917,   918,   919,     0,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,     0,
     930,     0,     0,     0,   931,     0,   932,   933,   934,   935,
     936,   937,   938,   939,     0,     0,   940,   941,   942,     0,
       0,   949,   943,   944,   945,   946,   947,   948,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     950,     0,     0,     0,   951,   952,     0,     0,   953,     0,
       0,  1137,  1570,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,   931,     0,   932,   933,
     934,   935,   936,   937,   938,   939,     0,     0,   940,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1137,     0,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,     0,     0,     0,     0,     0,     0,
       0,   912,   913,   914,   915,   916,   917,   918,   919,     0,
     920,   921,   922,   923,   924,   925,   926,   927,   928,   929,
       0,   930,     0,     0,     0,   931,     0,   932,   933,   934,
     935,   936,   937,   938,   939,     0,     0,   940,   941,   942,
       0,     0,     0,   943,   944,   945,   946,   947,   948,     0,
       0,     0,     0,     0,  1137,     0,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,     0,     0,
       0,     0,     0,     0,   949,   912,   913,   914,   915,   916,
     917,   918,   919,     0,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,     0,   930,     0,     0,     0,   931,
       0,   932,   933,   934,   935,   936,   937,   938,   939,     0,
       0,   940,   941,   942,     0,     0,     0,   943,   944,   945,
     946,   947,   948,   950,     0,     0,     0,   951,   952,     0,
       0,   953,     0,     0,  1137,  1610,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,     0,     0,
       0,     0,     0,     0,     0,   912,   913,   914,   915,   916,
     917,   918,   919,     0,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,     0,   930,     0,     0,     0,   931,
       0,   932,   933,   934,   935,   936,   937,   938,   939,     0,
       0,   940,   941,   942,     0,     0,   949,   943,   944,   945,
     946,   947,   948,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   950,     0,     0,     0,   951,
     952,     0,     0,   953,     0,     0,     0,  1630,     0,     0,
       0,     0,     0,     0,     0,   949,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   950,     0,     0,     0,   951,   952,
       0,     0,   953,     0,     0,     0,  1631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   950,     0,
       0,     0,   951,   952,     0,     0,   953,     0,     0,     0,
    1632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   950,     0,
       0,     0,   951,   952,     0,     0,   953,     0,     0,  1420,
    1633,   900,   901,   902,   903,   904,     0,     0,     0,     0,
     909,   910,   911,     0,     0,     0,     0,     0,     0,     0,
     912,   913,   914,   915,   916,   917,   918,   919,     0,   920,
     921,   922,   923,   924,   925,   926,   927,   928,   929,     0,
     930,     0,     0,     0,     0,     0,   932,   933,   934,   935,
     936,   937,   938,     0,     0,     0,     0,   941,   942,     0,
       0,     0,   943,   944,   945,   946,   947,   948,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1421,  1422,  1423,  1424,
    1425,  1426,  1430,     0,   900,   901,   902,   903,   904,     0,
       0,     0,     0,   909,   910,   911,     0,     0,     0,     0,
       0,     0,     0,   912,   913,   914,   915,   916,   917,   918,
     919,     0,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   929,     0,   930,     0,     0,     0,     0,     0,   932,
     933,   934,   935,   936,   937,   938,     0,     0,     0,     0,
     941,   942,     0,     0,     0,   943,   944,   945,   946,   947,
     948,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1421,
    1422,  1423,  1424,  1425,  1426,  1226,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   949,  1036,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1037,
    1427,     0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,
    1043,  1044,   506,   950,     0,  1045,     0,   951,   952,     0,
       0,     0,     0,  1108,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   949,  1036,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1037,  1427,     0,     0,  1038,     0,  1039,  1040,
    1041,  1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,
     951,   952,     0,     0,     0,     0,  1108,  1047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,  1227,  1108,
    1047,  1226,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1226,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1616,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,  1275,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,  1276,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,  1617,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1120,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1218,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1220,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1222,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1248,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1282,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,  1283,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1226,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1417,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1439,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,  1418,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1441,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1448,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1449,  1035,  1451,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1453,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1464,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1466,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1468,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1470,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1475,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1477,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1479,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1481,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1483,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1485,     0,
     900,   901,   902,   903,   904,     0,     0,     0,     0,   909,
     910,   911,     0,     0,     0,     0,     0,     0,     0,   912,
     913,   914,   915,   916,   917,   918,   919,     0,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,     0,   930,
       0,     0,     0,     0,     0,   932,   933,   934,   935,   936,
     937,   938,     0,     0,     0,     0,   941,   942,     0,     0,
       0,   943,   944,   945,   946,   947,   948,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1035,  1487,     0,   900,   901,   902,
     903,   904,     0,     0,     0,     0,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
       0,     0,   932,   933,   934,   935,   936,   937,   938,     0,
       0,     0,     0,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   949,  1036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1037,     0,
       0,     0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,
    1044,   506,   950,     0,  1045,     0,   951,   952,     0,     0,
       0,     0,  1108,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,  1036,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1037,     0,     0,     0,  1038,
       0,  1039,  1040,  1041,  1042,     0,  1043,  1044,   506,   950,
       0,  1045,     0,   951,   952,     0,     0,     0,     0,  1108,
    1047,  1673,     0,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,     0,     0,     0,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,   931,     0,   932,   933,   934,   935,   936,   937,   938,
     939,     0,     0,   940,   941,   942,     0,     0,     0,   943,
     944,   945,   946,   947,   948,   900,   901,   902,   903,   904,
       0,     0,     0,     0,   909,   910,   911,     0,     0,     0,
       0,     0,     0,     0,   912,   913,   914,   915,   916,   917,
     918,   919,     0,   920,   921,   922,   923,   924,   925,   926,
     927,   928,   929,     0,   930,     0,     0,     0,     0,     0,
     932,   933,   934,   935,   936,   937,   938,     0,     0,     0,
       0,   941,   942,     0,     0,     0,   943,   944,   945,   946,
     947,   948,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   949,  1036,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     950,     0,     0,     0,   951,   952,     0,     0,   953,     0,
       0,  1319,     0,     0,     0,     0,     0,     0,   949,  1036,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1037,     0,     0,     0,  1038,     0,  1039,
    1040,  1041,  1042,     0,  1043,  1044,   506,   950,     0,  1045,
       0,   951,   952,     0,     0,     0,     0,  1046,  1047,   900,
     901,   902,   903,   904,     0,     0,     0,     0,   909,   910,
     911,     0,     0,     0,     0,     0,     0,     0,   912,   913,
     914,   915,   916,   917,   918,   919,     0,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,     0,   930,     0,
       0,     0,     0,     0,   932,   933,   934,   935,   936,   937,
     938,     0,     0,     0,     0,   941,   942,     0,     0,     0,
     943,   944,   945,   946,   947,   948,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,   900,   901,   902,   903,   904,     0,
       0,     0,     0,   909,   910,   911,     0,     0,     0,     0,
       0,     0,     0,   912,   913,   914,   915,   916,   917,   918,
     919,     0,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   929,     0,   930,     0,     0,     0,     0,     0,   932,
     933,   934,   935,   936,   937,   938,     0,     0,     0,     0,
     941,   942,     0,     0,     0,   943,   944,   945,   946,   947,
     948,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,   900,
     901,   902,   903,   904,     0,     0,     0,     0,   909,   910,
     911,     0,     0,     0,     0,     0,     0,     0,   912,   913,
     914,   915,   916,   917,   918,   919,     0,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,     0,   930,     0,
       0,     0,     0,     0,   932,   933,   934,   935,   936,   937,
     938,     0,     0,     0,     0,   941,   942,     0,     0,     0,
     943,   944,   945,   946,   947,   948,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   949,  1036,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1037,     0,     0,
       0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,  1044,
     506,   950,     0,  1045,     0,   951,   952,     0,     0,     0,
       0,  1067,  1047,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   949,  1036,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,
    1041,  1042,     0,  1043,  1044,   506,   950,     0,  1045,     0,
     951,   952,     0,     0,     0,     0,  1069,  1047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   949,  1036,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1037,     0,     0,
       0,  1038,     0,  1039,  1040,  1041,  1042,     0,  1043,  1044,
     506,   950,     0,  1045,     0,   951,   952,     0,     0,     0,
       0,  1108,  1047,   900,   901,   902,   903,   904,     0,     0,
       0,     0,   909,   910,   911,     0,     0,     0,     0,     0,
       0,     0,   912,   913,   914,   915,   916,   917,   918,   919,
       0,   920,   921,   922,   923,   924,   925,   926,   927,   928,
     929,     0,   930,     0,     0,     0,     0,     0,   932,   933,
     934,   935,   936,   937,   938,     0,     0,     0,     0,   941,
     942,     0,     0,     0,   943,   944,   945,   946,   947,   948,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
       0,     0,     0,     0,     0,     0,     0,   912,   913,   914,
     915,   916,   917,   918,   919,     0,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,     0,   930,     0,     0,
       0,   931,     0,   932,   933,   934,   935,   936,   937,   938,
     939,     0,     0,   940,   941,   942,     0,     0,     0,   943,
     944,   945,   946,   947,   948,  1234,     0,   900,   901,   902,
     903,   904,   905,   906,   907,   908,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
     931,     0,   932,   933,   934,   935,   936,   937,   938,   939,
       0,     0,   940,   941,   942,     0,     0,     0,   943,   944,
     945,   946,   947,   948,     0,     0,     0,   900,   901,   902,
     903,   904,   905,   906,   907,   908,   909,   910,   911,     0,
       0,     0,     0,     0,     0,     0,   912,   913,   914,   915,
     916,   917,   918,   919,     0,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,     0,   930,     0,     0,     0,
     931,     0,   932,   933,   934,   935,   936,   937,   938,   939,
       0,     0,   940,   941,   942,     0,   949,  1036,   943,   944,
     945,   946,   947,   948,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1037,     0,     0,     0,  1038,     0,  1039,  1040,  1041,
    1042,     0,  1043,  1044,  1623,   950,     0,  1045,     0,   951,
     952,     0,     0,     0,     0,  1108,  1047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     950,     0,     0,     0,   951,   952,     0,     0,   953,     0,
       0,  1319,     0,     0,     0,     0,     0,     0,     0,     0,
     949,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   950,
       0,     0,     0,   951,   952,     0,     0,   953,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     949,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   950,
       0,     0,     0,   951,   952,     0,     0,   953
};

static const yytype_int16 yycheck[] =
{
     222,   191,   221,   225,   408,   861,  1122,     1,   864,  1174,
       1,   867,     1,  1009,   870,  1011,     1,  1013,     1,  1015,
       1,  1017,   878,  1030,     1,  1032,    57,  1034,  1057,   251,
     240,   253,   301,   255,   861,   257,     1,   864,     1,    62,
     867,     1,     1,   870,  1051,    62,     1,     1,    62,     1,
     322,   878,     1,    62,     1,   321,     1,    62,     1,   321,
       1,   321,   334,     1,   331,   331,     1,     1,   342,   331,
     344,   301,    61,     1,   334,  1046,   342,   301,   344,     1,
      61,   348,     1,     1,  1011,     1,  1013,     1,  1015,   349,
    1017,     1,   334,     1,   316,   337,  1067,     1,  1069,   955,
       1,    61,     1,   325,   326,   327,   328,   329,   330,   331,
       1,  1049,     1,    56,    57,  1053,   972,     1,   974,     1,
     976,   301,     1,    61,   980,     1,   301,     1,   955,     1,
       1,     1,     1,     1,     1,   321,     1,  1108,   360,   361,
     362,     1,   546,     1,   301,   972,     1,   974,   334,   976,
       1,     1,   864,   980,   861,   867,   301,   864,   870,   321,
     867,   301,     1,   870,     1,     1,   878,     1,     1,   331,
       1,   878,    88,    89,    90,    91,     1,     1,   861,    61,
       1,   864,     1,     1,   867,   321,     1,   870,     1,     1,
    1046,  1047,   321,     1,     1,   878,     1,     1,   334,     1,
     335,   337,   337,     1,     1,   334,   334,   335,   337,   337,
       1,  1067,     1,  1069,     1,     1,     1,     1,   440,  1046,
    1047,   443,   444,     1,     1,     1,   301,   334,   335,     1,
     337,     1,     1,    88,    89,    90,    91,     1,     1,   301,
    1067,     1,  1069,     1,   301,     1,     1,   301,   955,     1,
    1246,     1,  1108,  1109,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,   972,  1122,   974,     1,   976,
       1,   301,   955,   980,   301,    88,    89,    90,    91,     1,
       1,  1108,  1109,     1,     1,     1,     1,     1,     1,   972,
       1,   974,     1,   976,     1,  1122,     1,   980,     1,   301,
       1,  1157,     1,   334,   335,     1,    14,    15,     1,     1,
     342,   334,   344,     1,   342,  1171,   344,   334,   331,  1246,
     334,  1177,     1,  1352,     0,   334,     1,     1,     1,   334,
    1157,   322,     1,     1,   342,  1047,   344,     1,     1,  1046,
    1047,   551,    19,   334,  1171,   334,   335,   301,   337,   338,
    1177,   955,   346,   334,   335,   344,   337,   338,   343,   348,
    1067,   338,  1069,  1046,  1047,   348,  1531,   348,   972,   334,
     974,   348,   976,   338,   334,   335,   980,   337,   338,  1235,
     335,   344,   345,   348,  1067,   334,  1069,   346,   348,   334,
     335,   336,   337,   338,   346,   344,   334,   335,   345,   337,
     338,  1108,  1109,   348,   347,   346,   322,   348,  1235,  1525,
     348,   346,   346,   348,   348,  1122,   335,   345,   334,   335,
     336,   337,   338,   345,   334,  1108,  1109,   337,   346,   345,
     348,   345,   348,   334,   335,   336,   337,   338,   346,  1122,
     348,   345,  1449,   334,   335,   334,   345,   348,   337,  1456,
     301,   861,   334,   335,   864,   337,   338,   867,   337,  1171,
     870,   345,   301,  1319,  1171,  1177,   348,   322,   878,   345,
    1177,   345,   337,   345,   345,   345,   345,   345,   345,   334,
     335,   336,   337,   338,   888,   345,   337,   345,  1171,     1,
     345,     1,  1319,   348,  1177,   345,     1,   286,   337,   335,
    1356,  1357,  1358,  1359,   301,  1109,  1671,  1363,   345,   322,
     334,   345,   345,  1369,   345,   301,   337,     1,  1122,   334,
     345,   334,   335,   336,   337,   338,   345,   345,  1235,  1356,
    1357,  1358,  1359,   345,   321,   348,  1363,   345,   345,   337,
     345,   345,  1369,   345,   335,   955,   337,   334,   337,   334,
       1,   340,  1235,   337,     1,    16,   334,   344,   335,   335,
     337,   337,   972,   335,   974,   337,   976,   337,   337,     1,
     980,   335,   335,   337,   337,   335,   334,   337,     1,   335,
     984,   337,   337,   335,     1,   337,     1,   337,   335,   301,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,     1,     1,     1,   337,     1,   337,  1319,   861,   301,
    1606,   864,  1319,   301,   867,   337,   337,   870,     1,   337,
     337,   337,   337,   337,   337,   878,   337,    20,   337,     1,
     337,  1235,   337,   334,   337,   334,  1319,  1047,   334,   335,
     336,   334,   335,   336,  1356,  1357,  1358,  1359,   321,  1356,
    1357,  1358,  1359,   321,     1,   334,  1363,   321,   321,   334,
     334,   334,  1369,     1,     1,   334,   334,   857,  1524,  1525,
     334,   334,   301,  1356,  1357,  1358,  1359,     1,     1,     1,
    1363,     1,   322,   323,   324,     1,  1369,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,  1524,  1525,  1109,
       1,     1,   955,  1559,  1560,  1561,  1562,  1111,     1,     1,
       1,  1115,  1122,     1,     1,     1,     1,     1,   301,   972,
       1,   974,     1,   976,     1,     1,     1,   980,     1,     1,
       1,     1,  1559,  1560,  1561,  1562,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,  1157,     1,   301,
       1,     1,     1,   342,     1,   344,     1,     1,     1,  1363,
       1,  1171,     1,     1,  1620,  1369,     1,  1177,     1,     1,
     269,   270,   271,   272,     1,     1,     1,   301,     1,     1,
       1,   342,   301,   344,     1,     1,     1,     1,     1,     1,
       1,     1,     1,  1620,  1047,   889,   890,     1,     1,     1,
       1,     1,     1,     1,     1,     1,   301,   309,   310,   321,
     301,   321,   314,   315,   301,   301,  1672,  1524,  1525,  1675,
    1676,   342,   334,   344,   334,  1235,     1,     1,   301,   334,
    1686,  1687,  1688,     1,  1690,  1691,  1692,   321,     1,     1,
       1,  1524,  1525,     1,     1,  1672,   301,     1,  1675,  1676,
     334,   301,  1559,  1560,  1561,  1562,  1109,     1,     1,  1686,
    1687,  1688,     1,  1690,  1691,  1692,   301,     1,     1,  1122,
     321,  1093,    56,    57,   321,   301,  1559,  1560,  1561,  1562,
     905,   906,   907,   334,     1,     1,     1,   334,  1107,   321,
       1,     1,     1,     1,     1,     1,  1115,     1,   321,   301,
     346,     1,   334,     1,   321,   301,   931,   322,  1620,  1319,
     301,   334,   301,  1620,   939,   940,     1,   334,  1171,   334,
    1524,  1525,   321,   321,  1177,    88,    89,    90,    91,    21,
      88,    89,    90,    91,   334,   334,   334,  1620,  1128,     1,
    1130,   342,  1132,   344,   301,   301,  1356,  1357,  1358,  1359,
       1,   334,     1,  1363,  1176,  1559,  1560,  1561,  1562,  1369,
    1672,     1,   334,  1675,     1,  1672,   301,     1,  1675,  1676,
       1,   301,   309,   310,   321,  1687,  1688,   314,   315,  1686,
    1687,  1688,  1235,  1690,  1691,  1692,     1,   334,     1,  1672,
       1,     1,  1675,  1676,     1,   334,   334,   321,   334,   335,
     342,   337,   344,  1686,  1687,  1688,   301,  1690,  1691,  1692,
     334,   334,   334,   334,   334,  1040,  1041,  1042,   334,   301,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
       1,   334,   301,   334,   334,   334,   335,   334,   337,   301,
    1065,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,  1076,   346,   334,   301,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   301,  1319,   301,   334,   334,
     334,   334,  1676,   334,   334,   334,   334,   334,   334,   334,
     334,   334,  1686,   334,   334,   334,  1690,  1691,  1692,   334,
     334,   334,   334,   334,   301,   334,   334,   334,   346,   334,
     346,   334,   334,  1356,  1357,  1358,  1359,   334,   334,   334,
    1363,   334,   334,   334,  1524,  1525,  1369,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   301,   301,  1532,  1154,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   301,
     301,   309,   310,   311,   301,   301,   314,   315,   301,  1559,
    1560,  1561,  1562,   301,   301,   309,   310,   311,   301,   322,
     314,   315,   301,   347,   322,   309,   310,   301,   334,   301,
     314,   315,   316,   317,   318,   319,   309,   310,   311,   301,
     301,   314,   315,   301,   301,   301,   301,  1212,  1213,  1214,
     301,   301,   301,   301,   301,   301,   342,   301,   344,  1224,
    1225,   301,   342,   301,   344,   301,    88,    89,    90,    91,
    1620,   301,  1237,   859,   301,   301,   301,   863,  1243,  1244,
     866,  1246,   342,   869,   344,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,   320,   321,   322,   323,   324,   301,   301,   301,
       1,  1463,   337,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
     301,   342,   301,   344,   225,   226,   227,   228,   342,   301,
     344,   301,  1672,   301,   301,  1675,  1676,   301,   301,   301,
     301,  1524,  1525,   342,   301,   344,  1686,  1687,  1688,   301,
    1690,  1691,  1692,   342,   334,   344,   301,   342,   301,   344,
     301,   301,   301,   301,   301,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   321,   301,  1559,  1560,  1561,  1562,
      71,    72,    73,    74,   331,    76,   321,    78,   301,    80,
     321,  1346,   301,   321,   301,   342,   331,   344,   301,   301,
     331,   301,   301,   331,   301,   301,   301,   342,   301,   344,
     301,   342,   335,   344,   342,   301,   344,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,  1555,   301,  1620,  1558,   316,
     317,   318,   319,   320,   321,   322,   323,   324,  1600,   334,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,  1672,
     301,   301,  1675,  1676,   346,   301,   301,   334,   335,   336,
     337,   338,   301,  1686,  1687,  1688,   301,  1690,  1691,  1692,
     322,   348,   301,   301,   301,   301,   334,   335,   336,   337,
     338,   301,   334,   335,   336,   337,   338,   345,   301,   301,
     348,   301,   301,   345,   301,   301,   348,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,     0,     1,   344,
    1535,   301,   301,   301,   301,   301,  1541,   301,   301,   301,
     301,    14,    15,    16,    17,    18,    19,    20,    21,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     334,   301,   301,   301,   301,    38,   301,   301,    41,    42,
      43,    44,    45,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,    57,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   301,   301,
     301,   301,  1617,   301,   301,   351,   346,   348,   334,   334,
    1625,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   334,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   334,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   334,   334,   334,   334,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   334,   267,   268,   334,   334,   334,   334,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   349,   298,   299,   300,   334,   331,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   342,   342,   338,   351,   351,   109,   301,
     342,   301,   335,   301,   301,   334,   341,   301,   349,   334,
     343,   342,   344,   349,   344,   337,     1,   350,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     349,   345,   345,   345,   345,   345,   345,    22,    23,    24,
      25,    26,    27,    28,    29,   301,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   345,    42,   345,   345,
     345,    46,   345,    48,    49,    50,    51,    52,    53,    54,
      55,   343,   343,    58,    59,    60,   349,   331,   346,    64,
      65,    66,    67,    68,    69,     1,   349,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   349,
     349,   331,   342,   351,   351,   346,    22,    23,    24,    25,
      26,    27,    28,    29,   345,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   345,    42,   337,   344,   344,
      46,   344,    48,    49,    50,    51,    52,    53,    54,    55,
     344,   344,    58,    59,    60,   344,   344,   344,    64,    65,
      66,    67,    68,    69,     1,   344,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   345,   331,
     348,   346,   346,   346,   346,    22,    23,    24,    25,    26,
      27,    28,    29,   266,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   266,    42,   334,   334,   344,    46,
     344,    48,    49,    50,    51,    52,    53,    54,    55,   344,
     344,    58,    59,    60,   344,   335,   344,    64,    65,    66,
      67,    68,    69,     1,   301,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   301,   301,   301,
     344,   347,   344,   348,    22,    23,    24,    25,    26,    27,
      28,    29,   342,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   344,    42,   344,   342,    47,    46,   344,
      48,    49,    50,    51,    52,    53,    54,    55,   344,   344,
      58,    59,    60,   344,   344,   344,    64,    65,    66,    67,
      68,    69,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   286,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     344,   344,   344,   351,   351,   344,   331,   344,   342,   344,
     335,   344,   344,   344,   339,   340,   344,   342,   343,   344,
     345,   346,   344,   344,   344,   335,   351,   342,   337,   337,
     286,   349,   301,   331,   334,   334,   348,   344,   344,   334,
     334,   334,   334,   334,   334,   334,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   334,
     334,   334,   334,   334,   334,   323,   331,   344,   344,   335,
     337,   351,   199,   339,   340,   337,   342,   343,   344,   345,
     346,   334,   351,   347,   344,   351,   349,   344,   344,   286,
     344,   984,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   335,   344,
     344,  1214,   339,   340,   344,   342,   343,   344,   351,   346,
     351,   344,   351,   349,   351,   349,   351,   857,   286,   855,
    1169,   367,  1216,  1216,  1539,  1347,   886,  1625,    -1,    -1,
     547,  1601,    -1,    -1,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   368,  1617,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,
      -1,   339,   340,     1,   342,   343,   344,    -1,   346,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   344,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,    -1,    -1,    -1,    -1,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     298,   299,   300,    -1,    -1,    -1,    -1,    -1,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,    -1,    -1,    -1,    -1,    -1,     1,   335,     3,     4,
       5,     6,     7,    -1,    -1,   343,    -1,    12,    13,    14,
     344,    -1,   350,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   286,   287,    -1,    64,    65,    66,    67,    68,    69,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,
     325,    -1,   327,   328,   329,   330,    -1,   332,   333,   334,
     335,    -1,   337,   338,   339,   340,    -1,    -1,    -1,    -1,
     345,   346,    -1,   348,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   286,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,   335,    -1,    -1,
      -1,   339,   340,    -1,    -1,   343,    -1,    -1,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     344,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,
     339,   340,    -1,    -1,   343,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,   286,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   335,    -1,    -1,    -1,   339,   340,    -1,    -1,
     343,    -1,    -1,     1,   347,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   286,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,   343,    -1,    -1,     1,   347,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,   286,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,
      -1,   339,   340,    -1,    -1,   343,    -1,    -1,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,
     339,   340,    -1,    -1,   343,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,
      -1,     1,   347,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
     335,    -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,
      -1,     1,   347,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,   286,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,   343,    -1,    -1,     1,   347,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   286,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,   339,   340,
      -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,   339,   340,    -1,    -1,   343,    -1,    -1,     1,
     347,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    59,    60,    -1,
      -1,   286,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,
      -1,     1,   347,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   286,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,   335,    -1,    -1,    -1,   339,   340,    -1,
      -1,   343,    -1,    -1,     1,   347,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,   286,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,   339,
     340,    -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,   339,   340,
      -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,   339,   340,    -1,    -1,   343,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,
      -1,    -1,   339,   340,    -1,    -1,   343,    -1,    -1,     1,
     347,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
     322,    -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,
     332,   333,   334,   335,    -1,   337,    -1,   339,   340,    -1,
      -1,    -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   321,   322,    -1,    -1,   325,    -1,   327,   328,
     329,   330,    -1,   332,   333,   334,   335,    -1,   337,    -1,
     339,   340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,   344,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,   344,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,   344,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,   323,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,
      -1,    -1,   325,    -1,   327,   328,   329,   330,    -1,   332,
     333,   334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,   325,
      -1,   327,   328,   329,   330,    -1,   332,   333,   334,   335,
      -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,   345,
     346,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   321,    -1,    -1,    -1,   325,    -1,   327,
     328,   329,   330,    -1,   332,   333,   334,   335,    -1,   337,
      -1,   339,   340,    -1,    -1,    -1,    -1,   345,   346,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
      -1,   325,    -1,   327,   328,   329,   330,    -1,   332,   333,
     334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,    -1,
      -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,
     329,   330,    -1,   332,   333,   334,   335,    -1,   337,    -1,
     339,   340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,
      -1,   325,    -1,   327,   328,   329,   330,    -1,   332,   333,
     334,   335,    -1,   337,    -1,   339,   340,    -1,    -1,    -1,
      -1,   345,   346,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    59,    60,    -1,   286,   287,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,   325,    -1,   327,   328,   329,
     330,    -1,   332,   333,   334,   335,    -1,   337,    -1,   339,
     340,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,
      -1,    -1,    -1,   339,   340,    -1,    -1,   343,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,
      -1,    -1,    -1,   339,   340,    -1,    -1,   343
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    17,    18,    38,    41,    42,    43,    44,    45,
      57,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   267,   268,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   298,   299,   300,   335,   343,   350,   353,   354,
     355,   356,   357,   358,   359,   360,   371,   375,   378,   379,
     381,   382,   392,   393,   402,   301,     1,   348,     1,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,     1,   301,     1,   301,
       1,   301,     1,   301,     1,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,     1,   337,     1,
     301,   337,     1,   345,     1,   301,   337,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,     1,   301,     1,   301,     1,   301,     1,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,     1,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   331,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,     1,   335,   337,   372,   373,   374,     1,   374,   376,
     377,     1,   337,     1,   337,     1,   337,     0,     1,   355,
      14,    15,   388,   389,    16,   390,   391,    19,   396,   397,
      20,   398,   399,    21,   400,   401,   331,   348,   346,   334,
     335,   337,   387,     1,   334,     1,   334,     1,    88,    89,
      90,    91,   322,   364,     1,   321,   334,   370,     1,   334,
       1,   334,     1,   370,     1,   334,     1,   334,     1,   334,
       1,   334,     1,   335,     1,   337,     1,   334,     1,   337,
       1,   334,     1,   337,     1,   337,     1,   337,     1,   337,
       1,   334,   335,   336,   337,   338,   345,   348,   361,   363,
     364,   368,   369,   383,   384,   385,   386,   416,   417,     1,
     369,     1,   334,     1,   334,     1,   334,   334,   334,   334,
     370,   370,   370,   370,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,     1,   370,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   370,     1,   370,     1,   370,     1,   370,     1,
     370,     1,   370,     1,   370,     1,   334,     1,   334,     1,
     337,     1,   337,     1,   334,     1,   337,   337,     1,   337,
       1,   334,     1,   334,     1,   335,   337,     1,   335,   337,
       1,   335,   337,     1,   335,   337,     1,   335,   337,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   370,     1,   370,     1,   370,     1,   335,   337,
       1,   334,     1,   334,     1,   334,     1,   334,   384,     1,
     386,     1,   334,     1,   334,   334,   334,   334,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   334,     1,   225,   226,   227,   228,
       1,   334,     1,   334,     1,   334,     1,   334,     1,   337,
       1,   337,     1,   337,     1,   334,     1,   334,     1,   334,
       1,   361,     1,   334,     1,   334,     1,   334,     1,   334,
       1,   334,     1,   334,     1,   334,     1,   334,     1,   334,
       1,   334,     1,   334,     1,   334,     1,   334,     1,   334,
       1,   334,     1,   335,   337,     1,   334,   335,   334,     1,
     334,     1,   334,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   337,     1,   334,     1,   334,     1,
     334,   269,   270,   271,   272,     1,   370,   334,   334,     1,
     370,     1,   370,     1,   334,     1,   334,     1,   334,     1,
     334,     1,   334,     1,   337,   342,   351,   342,     1,   348,
       1,   346,     1,   348,   346,     1,   348,   346,     1,   348,
     346,     1,   348,    57,   334,   335,   380,   334,   394,   349,
     334,   331,   361,   362,   385,   351,   351,   369,   109,   321,
     331,   342,   301,   301,   301,   301,   372,   334,   376,   387,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    22,    23,    24,    25,    26,    27,    28,    29,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      42,    46,    48,    49,    50,    51,    52,    53,    54,    55,
      58,    59,    60,    64,    65,    66,    67,    68,    69,   286,
     335,   339,   340,   343,   418,   420,   421,   422,   426,   427,
     435,   436,   438,   439,   442,   443,   445,   449,   450,   451,
     455,   387,   420,   387,   420,   387,   420,   341,   301,   349,
     420,     1,   395,   334,   342,   344,   349,     1,   322,   334,
     366,   363,   361,     1,   334,   416,     1,   416,   337,     1,
     337,     1,   337,     1,   337,     1,   337,   349,     1,   345,
       1,   345,     1,   345,     1,   345,     1,   345,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   287,   321,   325,   327,
     328,   329,   330,   332,   333,   337,   345,   346,   370,   408,
     409,   410,   411,   412,   413,   418,   430,   435,   436,   437,
     438,   440,   442,   443,   446,   447,   448,   345,   448,   345,
     448,     1,   345,     1,   345,     1,   345,   345,     1,   345,
       1,   345,     1,   345,     1,   345,     1,   345,     1,   345,
       1,   345,     1,   345,   345,     1,   345,     1,   345,     1,
     345,     1,   345,   345,   345,   345,   345,   345,   345,   448,
       1,   345,     1,   345,     1,   345,   345,   345,   345,   345,
       1,   448,   448,     1,   345,     1,   345,     1,   345,     1,
     345,     1,   345,     1,   452,     1,   343,     1,   347,   421,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   335,
     432,   433,   434,   301,   444,   343,     1,   345,   343,   349,
     347,   349,   347,   349,   347,   349,     1,   334,   337,   331,
     347,   346,   331,   362,   351,   351,   342,   346,     1,    61,
     335,   337,   344,   383,   415,     1,    61,   337,   383,   415,
       1,    61,   337,   383,   415,     1,    61,   337,   383,   415,
       1,    61,   337,   383,   415,     1,   309,   310,   311,   314,
     315,   403,   405,   403,   403,     1,   403,   431,     1,   448,
       1,   448,     1,   448,   345,   345,     1,   344,   436,   438,
     442,   443,   448,   449,     1,   420,     1,   405,     1,   316,
     317,   318,   319,   403,   404,     1,   405,   434,     1,   448,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   406,   407,   344,   344,     1,   334,   337,
       1,   337,     1,   335,   448,   337,     1,   337,     1,   337,
       1,   337,     1,   337,     1,   334,     1,   334,   344,     1,
     344,   370,   344,     1,   337,     1,   337,     1,   337,     1,
     337,   344,   344,   344,     1,   334,   344,     1,   364,   346,
     419,   421,     1,   361,     1,   334,     1,   361,   364,   367,
     344,   344,   344,   344,   346,   419,     1,   337,     1,   337,
     334,   374,   334,   374,   334,   374,   345,   331,   348,   448,
       1,   337,   435,   436,   441,   443,   346,   346,   346,   346,
     266,   266,   380,   420,   334,   366,   334,   337,   370,   420,
     344,   342,   344,   342,   344,   342,   344,   321,   331,   342,
     344,   344,   342,   344,   342,   344,   342,   344,   342,   344,
     344,   342,   344,   342,   344,   342,   344,   342,   344,   344,
     342,   344,   342,   344,   342,   344,   342,   344,   344,   342,
     344,   342,   344,   342,   344,   342,   344,     1,   335,   448,
       1,    88,    89,    90,    91,    92,    93,   322,   365,   448,
       1,   365,   448,     1,   408,   412,   335,   428,   429,     1,
     448,     1,   448,   344,   344,   344,   347,   347,     1,    86,
     448,     1,   448,     1,   448,     1,    86,   334,   335,   383,
     414,   415,   448,   348,     1,   448,     1,   448,     1,   448,
       1,   448,   448,   448,   448,     1,   448,     1,   448,     1,
     448,     1,   448,     1,   448,     1,   448,     1,   448,   344,
     342,   344,   344,   342,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   420,    47,   344,   344,   344,   344,
     344,   351,   351,   344,     1,    56,    57,   347,   424,   425,
     344,   342,   344,   344,   344,   344,   344,   344,   344,   344,
     448,   453,   454,   433,   349,   342,   344,   434,   342,   420,
     420,   420,   420,   337,   337,   301,   347,   331,   344,   344,
     347,    62,   334,   334,   334,     1,   335,     1,   335,   334,
      62,   334,   334,   334,   334,    62,   334,   334,   334,   334,
      62,   334,   334,   334,   334,    62,   334,   334,   334,   334,
     348,   331,   344,   344,   344,   344,   323,   370,   337,   337,
     347,   419,     1,   366,   361,   347,     1,   323,   423,   448,
     351,   347,   424,   334,   448,   342,   344,   374,     1,   374,
     347,   347,   347,   347,   334,   337,   334,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   337,   370,   428,     1,   334,   383,   349,   344,
     344,   351,   351,     1,   423,   351,   420,   344,   344,   454,
     344,   344,   344,   349,   349,   366,   420,   351,   351,     1,
     420,   420,   420
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   352,   353,   354,   354,   354,   355,   355,   355,   355,
     355,   356,   355,   357,   355,   355,   358,   355,   359,   355,
     360,   355,   355,   355,   361,   361,   361,   362,   362,   363,
     363,   364,   364,   364,   364,   364,   365,   365,   365,   365,
     365,   365,   365,   366,   366,   367,   367,   367,   367,   367,
     368,   368,   368,   368,   368,   369,   369,   370,   370,   371,
     371,   372,   372,   373,   373,   374,   374,   375,   375,   376,
     376,   377,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   379,   379,   380,   380,   380,   381,   381,
     381,   381,   381,   381,   381,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   383,   383,
     384,   385,   386,   386,   387,   387,   387,   388,   388,   389,
     389,   389,   389,   390,   391,   391,   391,   392,   392,   394,
     393,   393,   393,   395,   393,   393,   396,   397,   397,   397,
     398,   399,   399,   399,   400,   401,   401,   402,   402,   402,
     402,   402,   402,   403,   403,   403,   403,   404,   404,   404,
     404,   405,   405,   406,   406,   406,   406,   406,   406,   406,
     407,   407,   407,   407,   408,   408,   408,   409,   409,   409,
     410,   410,   410,   410,   410,   411,   411,   412,   412,   412,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   414,
     414,   414,   414,   415,   415,   415,   415,   415,   416,   416,
     416,   417,   417,   417,   417,   417,   418,   419,   419,   420,
     420,   420,   421,   421,   421,   421,   421,   421,   421,   421,
     422,   422,   423,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   425,   425,   426,   426,   426,   426,
     427,   428,   428,   428,   429,   429,   431,   430,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   433,   434,   434,
     435,   436,   437,   438,   439,   439,   440,   440,   440,   441,
     441,   441,   442,   443,   444,   445,   445,   445,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     447,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   449,   450,   450,   450,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   452,   451,   451,   453,   453,   453,   454,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     5,     3,
       1,     3,     3,     5,     3,     1,     2,     1,     2,     2,
       2,     1,     3,     1,     3,     1,     1,     2,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     5,     5,     5,     5,     5,     5,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     5,     5,
       7,     7,     5,     8,     8,     2,     2,     2,     2,     3,
       3,     8,     8,     2,     2,     2,     3,     3,     1,     1,
       7,     1,     1,     3,     1,     1,     1,     1,     1,     4,
       7,     2,     2,     1,     4,     7,     2,     1,     1,     0,
       5,     2,     2,     0,     8,     5,     1,     4,     7,     2,
       1,     4,     7,     2,     1,     7,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     3,     2,
       1,     2,     2,     1,     1,     1,     2,     2,     1,     2,
       3,     5,     1,     4,     5,     3,     4,     3,     2,     4,
       5,     3,     4,     4,     2,     1,     5,     4,     2,     5,
       3,     1,     4,     4,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     5,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     2,     3,     1,     1,     1,     3,     4,     4,     4,
       6,     6,     6,     6,     6,     4,     2,     4,     4,     4,
       4,     6,     6,     6,     6,     6,     4,     2,     4,     4,
       4,     4,     6,     6,     6,     6,     6,     4,     2,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     4,     2,
       4,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       2,     4,     4,     6,     2,     4,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     6,     6,     6,     4,     2,
       6,     2,     4,     4,     4,     2,     4,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     4,     4,     2,     4,
       3,     2,     4,     3,     2,     4,     3,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     4,
       2,     4,     4,     2,     4,     3,     1,     3,     1,     3,
       1,     4,     3,     1,     4,     4,     4,     4,     4,     2,
       4,     4,     2,     4,     4,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     6,     6,     2,     4,     4,     2,
       4,     0,     5,     2,     0,     3,     1,     1,     3,     2,
       1,     3,     2,     1,     1,     3,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 629 "core/cfg.y"
    {}
#line 5088 "core/cfg.tab.c"
    break;

  case 4:
#line 630 "core/cfg.y"
    {}
#line 5094 "core/cfg.tab.c"
    break;

  case 5:
#line 631 "core/cfg.y"
    { yyerror(""); YYABORT;}
#line 5100 "core/cfg.tab.c"
    break;

  case 11:
#line 639 "core/cfg.y"
    {rt=REQUEST_ROUTE;}
#line 5106 "core/cfg.tab.c"
    break;

  case 13:
#line 640 "core/cfg.y"
    {rt=FAILURE_ROUTE;}
#line 5112 "core/cfg.tab.c"
    break;

  case 16:
#line 642 "core/cfg.y"
    {rt=BRANCH_ROUTE;}
#line 5118 "core/cfg.tab.c"
    break;

  case 18:
#line 643 "core/cfg.y"
    {rt=ONSEND_ROUTE;}
#line 5124 "core/cfg.tab.c"
    break;

  case 20:
#line 644 "core/cfg.y"
    {rt=EVENT_ROUTE;}
#line 5130 "core/cfg.tab.c"
    break;

  case 24:
#line 649 "core/cfg.y"
    {
		if ((yyvsp[0].ipaddr)){
			tmp=ip_addr2a((yyvsp[0].ipaddr));
			if (tmp==0) {
				LM_CRIT("cfg. parser: bad ip address.\n");
				(yyval.strval)=0;
			} else {
				(yyval.strval)=pkg_malloc(strlen(tmp)+1);
				if ((yyval.strval)==0) {
					PKG_MEM_CRITICAL;
				} else {
					strncpy((yyval.strval), tmp, strlen(tmp)+1);
				}
			}
		}
	}
#line 5151 "core/cfg.tab.c"
    break;

  case 25:
#line 665 "core/cfg.y"
    {
		(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
		if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
		} else {
				strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
		}
	}
#line 5164 "core/cfg.tab.c"
    break;

  case 26:
#line 673 "core/cfg.y"
    {
		if ((yyvsp[0].strval)){
			(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
					PKG_MEM_CRITICAL;
			} else {
					strncpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
			}
		}
	}
#line 5179 "core/cfg.tab.c"
    break;

  case 27:
#line 687 "core/cfg.y"
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), SI_IS_MHOMED); }
#line 5185 "core/cfg.tab.c"
    break;

  case 28:
#line 688 "core/cfg.y"
    { (yyval.name_l)=mk_name_lst((yyvsp[-2].strval), SI_IS_MHOMED);
										if ((yyval.name_l)) (yyval.name_l)->next=(yyvsp[0].name_l);
									}
#line 5193 "core/cfg.tab.c"
    break;

  case 29:
#line 694 "core/cfg.y"
    { (yyval.name_l)=(yyvsp[-1].name_l); }
#line 5199 "core/cfg.tab.c"
    break;

  case 30:
#line 695 "core/cfg.y"
    { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), 0); }
#line 5205 "core/cfg.tab.c"
    break;

  case 31:
#line 699 "core/cfg.y"
    { (yyval.intval)=PROTO_UDP; }
#line 5211 "core/cfg.tab.c"
    break;

  case 32:
#line 700 "core/cfg.y"
    { (yyval.intval)=PROTO_TCP; }
#line 5217 "core/cfg.tab.c"
    break;

  case 33:
#line 701 "core/cfg.y"
    { (yyval.intval)=PROTO_TLS; }
#line 5223 "core/cfg.tab.c"
    break;

  case 34:
#line 702 "core/cfg.y"
    { (yyval.intval)=PROTO_SCTP; }
#line 5229 "core/cfg.tab.c"
    break;

  case 35:
#line 703 "core/cfg.y"
    { (yyval.intval)=0; }
#line 5235 "core/cfg.tab.c"
    break;

  case 36:
#line 706 "core/cfg.y"
    { (yyval.intval)=PROTO_UDP; }
#line 5241 "core/cfg.tab.c"
    break;

  case 37:
#line 707 "core/cfg.y"
    { (yyval.intval)=PROTO_TCP; }
#line 5247 "core/cfg.tab.c"
    break;

  case 38:
#line 708 "core/cfg.y"
    { (yyval.intval)=PROTO_TLS; }
#line 5253 "core/cfg.tab.c"
    break;

  case 39:
#line 709 "core/cfg.y"
    { (yyval.intval)=PROTO_SCTP; }
#line 5259 "core/cfg.tab.c"
    break;

  case 40:
#line 710 "core/cfg.y"
    { (yyval.intval)=PROTO_WS; }
#line 5265 "core/cfg.tab.c"
    break;

  case 41:
#line 711 "core/cfg.y"
    { (yyval.intval)=PROTO_WSS; }
#line 5271 "core/cfg.tab.c"
    break;

  case 42:
#line 712 "core/cfg.y"
    { (yyval.intval)=0; }
#line 5277 "core/cfg.tab.c"
    break;

  case 43:
#line 715 "core/cfg.y"
    { (yyval.intval)=(yyvsp[0].intval); }
#line 5283 "core/cfg.tab.c"
    break;

  case 44:
#line 716 "core/cfg.y"
    { (yyval.intval)=0; }
#line 5289 "core/cfg.tab.c"
    break;

  case 45:
#line 719 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), 0, 0); }
#line 5295 "core/cfg.tab.c"
    break;

  case 46:
#line 720 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), 0, (yyvsp[0].intval)); }
#line 5301 "core/cfg.tab.c"
    break;

  case 47:
#line 721 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), (yyvsp[-2].intval), 0); }
#line 5307 "core/cfg.tab.c"
    break;

  case 48:
#line 722 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5313 "core/cfg.tab.c"
    break;

  case 49:
#line 723 "core/cfg.y"
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5319 "core/cfg.tab.c"
    break;

  case 50:
#line 727 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), 0, 0); }
#line 5325 "core/cfg.tab.c"
    break;

  case 51:
#line 728 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), 0, (yyvsp[0].intval)); }
#line 5331 "core/cfg.tab.c"
    break;

  case 52:
#line 729 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), (yyvsp[-2].intval), 0); }
#line 5337 "core/cfg.tab.c"
    break;

  case 53:
#line 730 "core/cfg.y"
    { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5343 "core/cfg.tab.c"
    break;

  case 54:
#line 731 "core/cfg.y"
    { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5349 "core/cfg.tab.c"
    break;

  case 55:
#line 735 "core/cfg.y"
    {  (yyval.sockid)=(yyvsp[0].sockid) ; }
#line 5355 "core/cfg.tab.c"
    break;

  case 56:
#line 736 "core/cfg.y"
    { (yyval.sockid)=(yyvsp[-1].sockid);  if ((yyval.sockid)) (yyval.sockid)->next=(yyvsp[0].sockid); }
#line 5361 "core/cfg.tab.c"
    break;

  case 58:
#line 740 "core/cfg.y"
    { (yyval.intval)=-(yyvsp[0].intval); }
#line 5367 "core/cfg.tab.c"
    break;

  case 60:
#line 744 "core/cfg.y"
    { yyerror("flag list expected\n"); }
#line 5373 "core/cfg.tab.c"
    break;

  case 63:
#line 750 "core/cfg.y"
    { if (register_flag((yyvsp[0].strval),-1)<0)
								yyerror("register flag failed");
						}
#line 5381 "core/cfg.tab.c"
    break;

  case 64:
#line 753 "core/cfg.y"
    {
						if (register_flag((yyvsp[-2].strval), (yyvsp[0].intval))<0)
								yyerror("register flag failed");
										}
#line 5390 "core/cfg.tab.c"
    break;

  case 65:
#line 759 "core/cfg.y"
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5396 "core/cfg.tab.c"
    break;

  case 66:
#line 760 "core/cfg.y"
    { (yyval.strval)=(yyvsp[0].strval); }
#line 5402 "core/cfg.tab.c"
    break;

  case 68:
#line 765 "core/cfg.y"
    { yyerror("avpflag list expected\n"); }
#line 5408 "core/cfg.tab.c"
    break;

  case 71:
#line 772 "core/cfg.y"
    {
		if (register_avpflag((yyvsp[0].strval))==0)
			yyerror("cannot declare avpflag");
	}
#line 5417 "core/cfg.tab.c"
    break;

  case 72:
#line 778 "core/cfg.y"
    { default_core_cfg.debug=(yyvsp[0].intval); }
#line 5423 "core/cfg.tab.c"
    break;

  case 73:
#line 779 "core/cfg.y"
    { yyerror("number  expected"); }
#line 5429 "core/cfg.tab.c"
    break;

  case 74:
#line 780 "core/cfg.y"
    { dont_fork= ! (yyvsp[0].intval); }
#line 5435 "core/cfg.tab.c"
    break;

  case 75:
#line 781 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5441 "core/cfg.tab.c"
    break;

  case 76:
#line 782 "core/cfg.y"
    { set_fork_delay((yyvsp[0].intval)); }
#line 5447 "core/cfg.tab.c"
    break;

  case 77:
#line 783 "core/cfg.y"
    { yyerror("number expected"); }
#line 5453 "core/cfg.tab.c"
    break;

  case 78:
#line 784 "core/cfg.y"
    { set_modinit_delay((yyvsp[0].intval)); }
#line 5459 "core/cfg.tab.c"
    break;

  case 79:
#line 785 "core/cfg.y"
    { yyerror("number expected"); }
#line 5465 "core/cfg.tab.c"
    break;

  case 80:
#line 786 "core/cfg.y"
    { if (!config_check)  /* if set from cmd line, don't overwrite from yyparse()*/
					if(log_stderr == 0) log_stderr=(yyvsp[0].intval);
				   }
#line 5473 "core/cfg.tab.c"
    break;

  case 81:
#line 789 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5479 "core/cfg.tab.c"
    break;

  case 82:
#line 790 "core/cfg.y"
    {
		if ( (i_tmp=str2facility((yyvsp[0].strval)))==-1)
			yyerror("bad facility (see syslog(3) man page)");
		if (!config_check)
			default_core_cfg.log_facility=i_tmp;
	}
#line 5490 "core/cfg.tab.c"
    break;

  case 83:
#line 796 "core/cfg.y"
    { yyerror("ID expected"); }
#line 5496 "core/cfg.tab.c"
    break;

  case 84:
#line 797 "core/cfg.y"
    { log_name=(yyvsp[0].strval); }
#line 5502 "core/cfg.tab.c"
    break;

  case 85:
#line 798 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5508 "core/cfg.tab.c"
    break;

  case 86:
#line 799 "core/cfg.y"
    { log_color=(yyvsp[0].intval); }
#line 5514 "core/cfg.tab.c"
    break;

  case 87:
#line 800 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5520 "core/cfg.tab.c"
    break;

  case 88:
#line 801 "core/cfg.y"
    { log_prefix_fmt=(yyvsp[0].strval); }
#line 5526 "core/cfg.tab.c"
    break;

  case 89:
#line 802 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5532 "core/cfg.tab.c"
    break;

  case 90:
#line 803 "core/cfg.y"
    { log_prefix_mode=(yyvsp[0].intval); }
#line 5538 "core/cfg.tab.c"
    break;

  case 91:
#line 804 "core/cfg.y"
    { yyerror("number expected"); }
#line 5544 "core/cfg.tab.c"
    break;

  case 92:
#line 805 "core/cfg.y"
    { _km_log_engine_type=(yyvsp[0].strval); }
#line 5550 "core/cfg.tab.c"
    break;

  case 93:
#line 806 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5556 "core/cfg.tab.c"
    break;

  case 94:
#line 807 "core/cfg.y"
    { _km_log_engine_data=(yyvsp[0].strval); }
#line 5562 "core/cfg.tab.c"
    break;

  case 95:
#line 808 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5568 "core/cfg.tab.c"
    break;

  case 96:
#line 809 "core/cfg.y"
    { _ksr_xavp_via_params.s=(yyvsp[0].strval);
			_ksr_xavp_via_params.len=strlen((yyvsp[0].strval));
		}
#line 5576 "core/cfg.tab.c"
    break;

  case 97:
#line 812 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5582 "core/cfg.tab.c"
    break;

  case 98:
#line 813 "core/cfg.y"
    { _ksr_xavp_via_params.s=(yyvsp[0].strval);
			_ksr_xavp_via_fields.len=strlen((yyvsp[0].strval));
		}
#line 5590 "core/cfg.tab.c"
    break;

  case 99:
#line 816 "core/cfg.y"
    { yyerror("string value expected"); }
#line 5596 "core/cfg.tab.c"
    break;

  case 100:
#line 817 "core/cfg.y"
    { received_dns|= ((yyvsp[0].intval))?DO_DNS:0; }
#line 5602 "core/cfg.tab.c"
    break;

  case 101:
#line 818 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5608 "core/cfg.tab.c"
    break;

  case 102:
#line 819 "core/cfg.y"
    { received_dns|= ((yyvsp[0].intval))?DO_REV_DNS:0; }
#line 5614 "core/cfg.tab.c"
    break;

  case 103:
#line 820 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5620 "core/cfg.tab.c"
    break;

  case 104:
#line 821 "core/cfg.y"
    { default_core_cfg.dns_try_ipv6=(yyvsp[0].intval); }
#line 5626 "core/cfg.tab.c"
    break;

  case 105:
#line 822 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5632 "core/cfg.tab.c"
    break;

  case 106:
#line 823 "core/cfg.y"
    { IF_NAPTR(default_core_cfg.dns_try_naptr=(yyvsp[0].intval)); }
#line 5638 "core/cfg.tab.c"
    break;

  case 107:
#line 824 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5644 "core/cfg.tab.c"
    break;

  case 108:
#line 825 "core/cfg.y"
    { IF_DNS_FAILOVER(default_core_cfg.dns_srv_lb=(yyvsp[0].intval)); }
#line 5650 "core/cfg.tab.c"
    break;

  case 109:
#line 826 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5656 "core/cfg.tab.c"
    break;

  case 110:
#line 827 "core/cfg.y"
    { IF_NAPTR(default_core_cfg.dns_udp_pref=(yyvsp[0].intval));}
#line 5662 "core/cfg.tab.c"
    break;

  case 111:
#line 828 "core/cfg.y"
    { yyerror("number expected"); }
#line 5668 "core/cfg.tab.c"
    break;

  case 112:
#line 829 "core/cfg.y"
    { IF_NAPTR(default_core_cfg.dns_tcp_pref=(yyvsp[0].intval));}
#line 5674 "core/cfg.tab.c"
    break;

  case 113:
#line 830 "core/cfg.y"
    { yyerror("number expected"); }
#line 5680 "core/cfg.tab.c"
    break;

  case 114:
#line 831 "core/cfg.y"
    { IF_NAPTR(default_core_cfg.dns_tls_pref=(yyvsp[0].intval));}
#line 5686 "core/cfg.tab.c"
    break;

  case 115:
#line 832 "core/cfg.y"
    { yyerror("number expected"); }
#line 5692 "core/cfg.tab.c"
    break;

  case 116:
#line 833 "core/cfg.y"
    {
								IF_NAPTR(default_core_cfg.dns_sctp_pref=(yyvsp[0].intval)); }
#line 5699 "core/cfg.tab.c"
    break;

  case 117:
#line 835 "core/cfg.y"
    { yyerror("number expected"); }
#line 5705 "core/cfg.tab.c"
    break;

  case 118:
#line 836 "core/cfg.y"
    { default_core_cfg.dns_retr_time=(yyvsp[0].intval); }
#line 5711 "core/cfg.tab.c"
    break;

  case 119:
#line 837 "core/cfg.y"
    { yyerror("number expected"); }
#line 5717 "core/cfg.tab.c"
    break;

  case 120:
#line 838 "core/cfg.y"
    { default_core_cfg.dns_slow_query_ms=(yyvsp[0].intval); }
#line 5723 "core/cfg.tab.c"
    break;

  case 121:
#line 839 "core/cfg.y"
    { yyerror("number expected"); }
#line 5729 "core/cfg.tab.c"
    break;

  case 122:
#line 840 "core/cfg.y"
    { default_core_cfg.dns_retr_no=(yyvsp[0].intval); }
#line 5735 "core/cfg.tab.c"
    break;

  case 123:
#line 841 "core/cfg.y"
    { yyerror("number expected"); }
#line 5741 "core/cfg.tab.c"
    break;

  case 124:
#line 842 "core/cfg.y"
    { default_core_cfg.dns_servers_no=(yyvsp[0].intval); }
#line 5747 "core/cfg.tab.c"
    break;

  case 125:
#line 843 "core/cfg.y"
    { yyerror("number expected"); }
#line 5753 "core/cfg.tab.c"
    break;

  case 126:
#line 844 "core/cfg.y"
    { default_core_cfg.dns_search_list=(yyvsp[0].intval); }
#line 5759 "core/cfg.tab.c"
    break;

  case 127:
#line 845 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5765 "core/cfg.tab.c"
    break;

  case 128:
#line 846 "core/cfg.y"
    { default_core_cfg.dns_search_fmatch=(yyvsp[0].intval); }
#line 5771 "core/cfg.tab.c"
    break;

  case 129:
#line 847 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5777 "core/cfg.tab.c"
    break;

  case 130:
#line 848 "core/cfg.y"
    { default_core_cfg.dns_naptr_ignore_rfc=(yyvsp[0].intval); }
#line 5783 "core/cfg.tab.c"
    break;

  case 131:
#line 849 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5789 "core/cfg.tab.c"
    break;

  case 132:
#line 850 "core/cfg.y"
    { IF_DNS_CACHE(dns_cache_init=(yyvsp[0].intval)); }
#line 5795 "core/cfg.tab.c"
    break;

  case 133:
#line 851 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5801 "core/cfg.tab.c"
    break;

  case 134:
#line 852 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.use_dns_cache=(yyvsp[0].intval)); }
#line 5807 "core/cfg.tab.c"
    break;

  case 135:
#line 853 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5813 "core/cfg.tab.c"
    break;

  case 136:
#line 854 "core/cfg.y"
    { IF_DNS_FAILOVER(default_core_cfg.use_dns_failover=(yyvsp[0].intval));}
#line 5819 "core/cfg.tab.c"
    break;

  case 137:
#line 855 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5825 "core/cfg.tab.c"
    break;

  case 138:
#line 856 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_flags=(yyvsp[0].intval)); }
#line 5831 "core/cfg.tab.c"
    break;

  case 139:
#line 857 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5837 "core/cfg.tab.c"
    break;

  case 140:
#line 858 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_neg_cache_ttl=(yyvsp[0].intval)); }
#line 5843 "core/cfg.tab.c"
    break;

  case 141:
#line 859 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5849 "core/cfg.tab.c"
    break;

  case 142:
#line 860 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_ttl=(yyvsp[0].intval)); }
#line 5855 "core/cfg.tab.c"
    break;

  case 143:
#line 861 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5861 "core/cfg.tab.c"
    break;

  case 144:
#line 862 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_min_ttl=(yyvsp[0].intval)); }
#line 5867 "core/cfg.tab.c"
    break;

  case 145:
#line 863 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5873 "core/cfg.tab.c"
    break;

  case 146:
#line 864 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_max_mem=(yyvsp[0].intval)); }
#line 5879 "core/cfg.tab.c"
    break;

  case 147:
#line 865 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5885 "core/cfg.tab.c"
    break;

  case 148:
#line 866 "core/cfg.y"
    { IF_DNS_CACHE(dns_timer_interval=(yyvsp[0].intval)); }
#line 5891 "core/cfg.tab.c"
    break;

  case 149:
#line 867 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5897 "core/cfg.tab.c"
    break;

  case 150:
#line 868 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_del_nonexp=(yyvsp[0].intval)); }
#line 5903 "core/cfg.tab.c"
    break;

  case 151:
#line 869 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5909 "core/cfg.tab.c"
    break;

  case 152:
#line 870 "core/cfg.y"
    { IF_DNS_CACHE(default_core_cfg.dns_cache_rec_pref=(yyvsp[0].intval)); }
#line 5915 "core/cfg.tab.c"
    break;

  case 153:
#line 871 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5921 "core/cfg.tab.c"
    break;

  case 154:
#line 872 "core/cfg.y"
    {IF_AUTO_BIND_IPV6(auto_bind_ipv6 = (yyvsp[0].intval));}
#line 5927 "core/cfg.tab.c"
    break;

  case 155:
#line 873 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5933 "core/cfg.tab.c"
    break;

  case 156:
#line 874 "core/cfg.y"
    {sr_bind_ipv6_link_local = (yyvsp[0].intval);}
#line 5939 "core/cfg.tab.c"
    break;

  case 157:
#line 875 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5945 "core/cfg.tab.c"
    break;

  case 158:
#line 876 "core/cfg.y"
    { IF_DST_BLACKLIST(dst_blacklist_init=(yyvsp[0].intval)); }
#line 5951 "core/cfg.tab.c"
    break;

  case 159:
#line 877 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5957 "core/cfg.tab.c"
    break;

  case 160:
#line 878 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.use_dst_blacklist=(yyvsp[0].intval));
	}
#line 5965 "core/cfg.tab.c"
    break;

  case 161:
#line 881 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5971 "core/cfg.tab.c"
    break;

  case 162:
#line 882 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_max_mem=(yyvsp[0].intval));
	}
#line 5979 "core/cfg.tab.c"
    break;

  case 163:
#line 885 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5985 "core/cfg.tab.c"
    break;

  case 164:
#line 886 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_timeout=(yyvsp[0].intval));
	}
#line 5993 "core/cfg.tab.c"
    break;

  case 165:
#line 889 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 5999 "core/cfg.tab.c"
    break;

  case 166:
#line 890 "core/cfg.y"
    { IF_DST_BLACKLIST(blst_timer_interval=(yyvsp[0].intval));}
#line 6005 "core/cfg.tab.c"
    break;

  case 167:
#line 891 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6011 "core/cfg.tab.c"
    break;

  case 168:
#line 892 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_udp_imask=(yyvsp[0].intval));
	}
#line 6019 "core/cfg.tab.c"
    break;

  case 169:
#line 895 "core/cfg.y"
    { yyerror("number(flags) expected"); }
#line 6025 "core/cfg.tab.c"
    break;

  case 170:
#line 896 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tcp_imask=(yyvsp[0].intval));
	}
#line 6033 "core/cfg.tab.c"
    break;

  case 171:
#line 899 "core/cfg.y"
    { yyerror("number(flags) expected"); }
#line 6039 "core/cfg.tab.c"
    break;

  case 172:
#line 900 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_tls_imask=(yyvsp[0].intval));
	}
#line 6047 "core/cfg.tab.c"
    break;

  case 173:
#line 903 "core/cfg.y"
    { yyerror("number(flags) expected"); }
#line 6053 "core/cfg.tab.c"
    break;

  case 174:
#line 904 "core/cfg.y"
    {
		IF_DST_BLACKLIST(default_core_cfg.blst_sctp_imask=(yyvsp[0].intval));
	}
#line 6061 "core/cfg.tab.c"
    break;

  case 175:
#line 907 "core/cfg.y"
    { yyerror("number(flags) expected"); }
#line 6067 "core/cfg.tab.c"
    break;

  case 176:
#line 908 "core/cfg.y"
    { _sr_ip_free_bind=(yyvsp[0].intval); }
#line 6073 "core/cfg.tab.c"
    break;

  case 177:
#line 909 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6079 "core/cfg.tab.c"
    break;

  case 178:
#line 910 "core/cfg.y"
    { port_no=(yyvsp[0].intval); }
#line 6085 "core/cfg.tab.c"
    break;

  case 179:
#line 911 "core/cfg.y"
    { maxbuffer=(yyvsp[0].intval); }
#line 6091 "core/cfg.tab.c"
    break;

  case 180:
#line 912 "core/cfg.y"
    { yyerror("number expected"); }
#line 6097 "core/cfg.tab.c"
    break;

  case 181:
#line 913 "core/cfg.y"
    { sql_buffer_size=(yyvsp[0].intval); }
#line 6103 "core/cfg.tab.c"
    break;

  case 182:
#line 914 "core/cfg.y"
    { yyerror("number expected"); }
#line 6109 "core/cfg.tab.c"
    break;

  case 183:
#line 915 "core/cfg.y"
    { yyerror("number expected"); }
#line 6115 "core/cfg.tab.c"
    break;

  case 184:
#line 916 "core/cfg.y"
    { children_no=(yyvsp[0].intval); }
#line 6121 "core/cfg.tab.c"
    break;

  case 185:
#line 917 "core/cfg.y"
    { yyerror("number expected"); }
#line 6127 "core/cfg.tab.c"
    break;

  case 186:
#line 918 "core/cfg.y"
    { socket_workers=(yyvsp[0].intval); }
#line 6133 "core/cfg.tab.c"
    break;

  case 187:
#line 919 "core/cfg.y"
    { yyerror("number expected"); }
#line 6139 "core/cfg.tab.c"
    break;

  case 188:
#line 920 "core/cfg.y"
    { async_task_set_workers((yyvsp[0].intval)); }
#line 6145 "core/cfg.tab.c"
    break;

  case 189:
#line 921 "core/cfg.y"
    { yyerror("number expected"); }
#line 6151 "core/cfg.tab.c"
    break;

  case 190:
#line 922 "core/cfg.y"
    { async_task_set_usleep((yyvsp[0].intval)); }
#line 6157 "core/cfg.tab.c"
    break;

  case 191:
#line 923 "core/cfg.y"
    { yyerror("number expected"); }
#line 6163 "core/cfg.tab.c"
    break;

  case 192:
#line 924 "core/cfg.y"
    { async_task_set_nonblock((yyvsp[0].intval)); }
#line 6169 "core/cfg.tab.c"
    break;

  case 193:
#line 925 "core/cfg.y"
    { yyerror("number expected"); }
#line 6175 "core/cfg.tab.c"
    break;

  case 194:
#line 926 "core/cfg.y"
    { check_via=(yyvsp[0].intval); }
#line 6181 "core/cfg.tab.c"
    break;

  case 195:
#line 927 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6187 "core/cfg.tab.c"
    break;

  case 196:
#line 928 "core/cfg.y"
    { phone2tel=(yyvsp[0].intval); }
#line 6193 "core/cfg.tab.c"
    break;

  case 197:
#line 929 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6199 "core/cfg.tab.c"
    break;

  case 198:
#line 930 "core/cfg.y"
    { default_core_cfg.memlog=(yyvsp[0].intval); }
#line 6205 "core/cfg.tab.c"
    break;

  case 199:
#line 931 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6211 "core/cfg.tab.c"
    break;

  case 200:
#line 932 "core/cfg.y"
    { default_core_cfg.memdbg=(yyvsp[0].intval); }
#line 6217 "core/cfg.tab.c"
    break;

  case 201:
#line 933 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6223 "core/cfg.tab.c"
    break;

  case 202:
#line 934 "core/cfg.y"
    { default_core_cfg.mem_summary=(yyvsp[0].intval); }
#line 6229 "core/cfg.tab.c"
    break;

  case 203:
#line 935 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6235 "core/cfg.tab.c"
    break;

  case 204:
#line 936 "core/cfg.y"
    { default_core_cfg.mem_safety=(yyvsp[0].intval); }
#line 6241 "core/cfg.tab.c"
    break;

  case 205:
#line 937 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6247 "core/cfg.tab.c"
    break;

  case 206:
#line 938 "core/cfg.y"
    { default_core_cfg.mem_join=(yyvsp[0].intval); }
#line 6253 "core/cfg.tab.c"
    break;

  case 207:
#line 939 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6259 "core/cfg.tab.c"
    break;

  case 208:
#line 940 "core/cfg.y"
    { default_core_cfg.mem_status_mode=(yyvsp[0].intval); }
#line 6265 "core/cfg.tab.c"
    break;

  case 209:
#line 941 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6271 "core/cfg.tab.c"
    break;

  case 210:
#line 942 "core/cfg.y"
    { default_core_cfg.corelog=(yyvsp[0].intval); }
#line 6277 "core/cfg.tab.c"
    break;

  case 211:
#line 943 "core/cfg.y"
    { yyerror("int value expected"); }
#line 6283 "core/cfg.tab.c"
    break;

  case 212:
#line 944 "core/cfg.y"
    { sip_warning=(yyvsp[0].intval); }
#line 6289 "core/cfg.tab.c"
    break;

  case 213:
#line 945 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6295 "core/cfg.tab.c"
    break;

  case 214:
#line 946 "core/cfg.y"
    { version_table.s=(yyvsp[0].strval);
			version_table.len=strlen(version_table.s);
	}
#line 6303 "core/cfg.tab.c"
    break;

  case 215:
#line 949 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6309 "core/cfg.tab.c"
    break;

  case 216:
#line 950 "core/cfg.y"
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6321 "core/cfg.tab.c"
    break;

  case 217:
#line 957 "core/cfg.y"
    {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6333 "core/cfg.tab.c"
    break;

  case 218:
#line 964 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6339 "core/cfg.tab.c"
    break;

  case 219:
#line 965 "core/cfg.y"
    { group=(yyvsp[0].strval); }
#line 6345 "core/cfg.tab.c"
    break;

  case 220:
#line 966 "core/cfg.y"
    { group=(yyvsp[0].strval); }
#line 6351 "core/cfg.tab.c"
    break;

  case 221:
#line 967 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6357 "core/cfg.tab.c"
    break;

  case 222:
#line 968 "core/cfg.y"
    { chroot_dir=(yyvsp[0].strval); }
#line 6363 "core/cfg.tab.c"
    break;

  case 223:
#line 969 "core/cfg.y"
    { chroot_dir=(yyvsp[0].strval); }
#line 6369 "core/cfg.tab.c"
    break;

  case 224:
#line 970 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6375 "core/cfg.tab.c"
    break;

  case 225:
#line 971 "core/cfg.y"
    { working_dir=(yyvsp[0].strval); }
#line 6381 "core/cfg.tab.c"
    break;

  case 226:
#line 972 "core/cfg.y"
    { working_dir=(yyvsp[0].strval); }
#line 6387 "core/cfg.tab.c"
    break;

  case 227:
#line 973 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6393 "core/cfg.tab.c"
    break;

  case 228:
#line 974 "core/cfg.y"
    { runtime_dir=(yyvsp[0].strval); }
#line 6399 "core/cfg.tab.c"
    break;

  case 229:
#line 975 "core/cfg.y"
    { runtime_dir=(yyvsp[0].strval); }
#line 6405 "core/cfg.tab.c"
    break;

  case 230:
#line 976 "core/cfg.y"
    { yyerror("string value expected"); }
#line 6411 "core/cfg.tab.c"
    break;

  case 231:
#line 977 "core/cfg.y"
    { mhomed=(yyvsp[0].intval); }
#line 6417 "core/cfg.tab.c"
    break;

  case 232:
#line 978 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6423 "core/cfg.tab.c"
    break;

  case 233:
#line 979 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_disable=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6435 "core/cfg.tab.c"
    break;

  case 234:
#line 986 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6441 "core/cfg.tab.c"
    break;

  case 235:
#line 987 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_aliases=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6453 "core/cfg.tab.c"
    break;

  case 236:
#line 994 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6459 "core/cfg.tab.c"
    break;

  case 237:
#line 995 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_accept_unique=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6471 "core/cfg.tab.c"
    break;

  case 238:
#line 1002 "core/cfg.y"
    { yyerror("number expected"); }
#line 6477 "core/cfg.tab.c"
    break;

  case 239:
#line 1003 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_connection_match=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6489 "core/cfg.tab.c"
    break;

  case 240:
#line 1010 "core/cfg.y"
    { yyerror("number expected"); }
#line 6495 "core/cfg.tab.c"
    break;

  case 241:
#line 1011 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_cfg_children_no=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6507 "core/cfg.tab.c"
    break;

  case 242:
#line 1018 "core/cfg.y"
    { yyerror("number expected"); }
#line 6513 "core/cfg.tab.c"
    break;

  case 243:
#line 1019 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.connect_timeout_s=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6525 "core/cfg.tab.c"
    break;

  case 244:
#line 1026 "core/cfg.y"
    { yyerror("number expected"); }
#line 6531 "core/cfg.tab.c"
    break;

  case 245:
#line 1027 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.send_timeout=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6543 "core/cfg.tab.c"
    break;

  case 246:
#line 1034 "core/cfg.y"
    { yyerror("number expected"); }
#line 6549 "core/cfg.tab.c"
    break;

  case 247:
#line 1035 "core/cfg.y"
    {
		#ifdef USE_TCP
			if ((yyvsp[0].intval)<0)
				tcp_default_cfg.con_lifetime=-1;
			else
				tcp_default_cfg.con_lifetime=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6564 "core/cfg.tab.c"
    break;

  case 248:
#line 1045 "core/cfg.y"
    { yyerror("number expected"); }
#line 6570 "core/cfg.tab.c"
    break;

  case 249:
#line 1046 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6589 "core/cfg.tab.c"
    break;

  case 250:
#line 1060 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6608 "core/cfg.tab.c"
    break;

  case 251:
#line 1074 "core/cfg.y"
    { yyerror("poll method name expected"); }
#line 6614 "core/cfg.tab.c"
    break;

  case 252:
#line 1075 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_max_connections=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6626 "core/cfg.tab.c"
    break;

  case 253:
#line 1082 "core/cfg.y"
    { yyerror("number expected"); }
#line 6632 "core/cfg.tab.c"
    break;

  case 254:
#line 1083 "core/cfg.y"
    {
		#ifdef USE_TLS
			tls_max_connections=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 6644 "core/cfg.tab.c"
    break;

  case 255:
#line 1090 "core/cfg.y"
    { yyerror("number expected"); }
#line 6650 "core/cfg.tab.c"
    break;

  case 256:
#line 1091 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.no_connect=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6662 "core/cfg.tab.c"
    break;

  case 257:
#line 1098 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6668 "core/cfg.tab.c"
    break;

  case 258:
#line 1099 "core/cfg.y"
    {
		#ifdef USE_TCP
			if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
				warn("tcp_source_ipv4 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6682 "core/cfg.tab.c"
    break;

  case 259:
#line 1108 "core/cfg.y"
    { yyerror("IPv4 address expected"); }
#line 6688 "core/cfg.tab.c"
    break;

  case 260:
#line 1109 "core/cfg.y"
    {
		#ifdef USE_TCP
				if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
					warn("tcp_source_ipv6 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 6702 "core/cfg.tab.c"
    break;

  case 261:
#line 1118 "core/cfg.y"
    { yyerror("IPv6 address expected"); }
#line 6708 "core/cfg.tab.c"
    break;

  case 262:
#line 1119 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.fd_cache=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6720 "core/cfg.tab.c"
    break;

  case 263:
#line 1126 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6726 "core/cfg.tab.c"
    break;

  case 264:
#line 1127 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.async=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6738 "core/cfg.tab.c"
    break;

  case 265:
#line 1134 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6744 "core/cfg.tab.c"
    break;

  case 266:
#line 1135 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcpconn_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6756 "core/cfg.tab.c"
    break;

  case 267:
#line 1142 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6762 "core/cfg.tab.c"
    break;

  case 268:
#line 1143 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.tcp_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6774 "core/cfg.tab.c"
    break;

  case 269:
#line 1150 "core/cfg.y"
    { yyerror("number expected"); }
#line 6780 "core/cfg.tab.c"
    break;

  case 270:
#line 1151 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.rd_buf_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6792 "core/cfg.tab.c"
    break;

  case 271:
#line 1158 "core/cfg.y"
    { yyerror("number expected"); }
#line 6798 "core/cfg.tab.c"
    break;

  case 272:
#line 1159 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.wq_blk_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6810 "core/cfg.tab.c"
    break;

  case 273:
#line 1166 "core/cfg.y"
    { yyerror("number expected"); }
#line 6816 "core/cfg.tab.c"
    break;

  case 274:
#line 1167 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.defer_accept=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6828 "core/cfg.tab.c"
    break;

  case 275:
#line 1174 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6834 "core/cfg.tab.c"
    break;

  case 276:
#line 1175 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.delayed_ack=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6846 "core/cfg.tab.c"
    break;

  case 277:
#line 1182 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6852 "core/cfg.tab.c"
    break;

  case 278:
#line 1183 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.syncnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6864 "core/cfg.tab.c"
    break;

  case 279:
#line 1190 "core/cfg.y"
    { yyerror("number expected"); }
#line 6870 "core/cfg.tab.c"
    break;

  case 280:
#line 1191 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.linger2=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6882 "core/cfg.tab.c"
    break;

  case 281:
#line 1198 "core/cfg.y"
    { yyerror("number expected"); }
#line 6888 "core/cfg.tab.c"
    break;

  case 282:
#line 1199 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepalive=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6900 "core/cfg.tab.c"
    break;

  case 283:
#line 1206 "core/cfg.y"
    { yyerror("boolean value expected");}
#line 6906 "core/cfg.tab.c"
    break;

  case 284:
#line 1207 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepidle=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6918 "core/cfg.tab.c"
    break;

  case 285:
#line 1214 "core/cfg.y"
    { yyerror("number expected"); }
#line 6924 "core/cfg.tab.c"
    break;

  case 286:
#line 1215 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepintvl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6936 "core/cfg.tab.c"
    break;

  case 287:
#line 1222 "core/cfg.y"
    { yyerror("number expected"); }
#line 6942 "core/cfg.tab.c"
    break;

  case 288:
#line 1223 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.keepcnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6954 "core/cfg.tab.c"
    break;

  case 289:
#line 1230 "core/cfg.y"
    { yyerror("number expected"); }
#line 6960 "core/cfg.tab.c"
    break;

  case 290:
#line 1231 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.crlf_ping=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6972 "core/cfg.tab.c"
    break;

  case 291:
#line 1238 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6978 "core/cfg.tab.c"
    break;

  case 292:
#line 1239 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_default_cfg.accept_no_cl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 6990 "core/cfg.tab.c"
    break;

  case 293:
#line 1246 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 6996 "core/cfg.tab.c"
    break;

  case 294:
#line 1247 "core/cfg.y"
    {
		#ifdef USE_TCP
			ksr_tcp_accept_hep3=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7008 "core/cfg.tab.c"
    break;

  case 295:
#line 1254 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7014 "core/cfg.tab.c"
    break;

  case 296:
#line 1255 "core/cfg.y"
    {
		#ifdef USE_TCP
			ksr_tcp_accept_haproxy=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7026 "core/cfg.tab.c"
    break;

  case 297:
#line 1262 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7032 "core/cfg.tab.c"
    break;

  case 298:
#line 1264 "core/cfg.y"
    {
		#ifdef USE_TCP
			tcp_set_clone_rcvbuf((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7044 "core/cfg.tab.c"
    break;

  case 299:
#line 1271 "core/cfg.y"
    { yyerror("number expected"); }
#line 7050 "core/cfg.tab.c"
    break;

  case 300:
#line 1272 "core/cfg.y"
    {
		#ifdef USE_TCP
		#ifdef SO_REUSEPORT
			tcp_default_cfg.reuse_port=(yyvsp[0].intval);
		#else
			warn("support for SO_REUSEPORT not compiled in");
		#endif
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7066 "core/cfg.tab.c"
    break;

  case 301:
#line 1283 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7072 "core/cfg.tab.c"
    break;

  case 302:
#line 1284 "core/cfg.y"
    {
		#ifdef USE_TLS
			tls_disable=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7084 "core/cfg.tab.c"
    break;

  case 303:
#line 1291 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7090 "core/cfg.tab.c"
    break;

  case 304:
#line 1292 "core/cfg.y"
    {
		#ifdef USE_TLS
			tls_disable=!((yyvsp[0].intval));
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7102 "core/cfg.tab.c"
    break;

  case 305:
#line 1299 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7108 "core/cfg.tab.c"
    break;

  case 306:
#line 1300 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_log=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7120 "core/cfg.tab.c"
    break;

  case 307:
#line 1307 "core/cfg.y"
    { yyerror("int value expected"); }
#line 7126 "core/cfg.tab.c"
    break;

  case 308:
#line 1308 "core/cfg.y"
    {
		#ifdef USE_TLS
			tls_port_no=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7138 "core/cfg.tab.c"
    break;

  case 309:
#line 1315 "core/cfg.y"
    { yyerror("number expected"); }
#line 7144 "core/cfg.tab.c"
    break;

  case 310:
#line 1316 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv23;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7156 "core/cfg.tab.c"
    break;

  case 311:
#line 1323 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv2;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7168 "core/cfg.tab.c"
    break;

  case 312:
#line 1330 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv3;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7180 "core/cfg.tab.c"
    break;

  case 313:
#line 1337 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_method=TLS_USE_TLSv1;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7192 "core/cfg.tab.c"
    break;

  case 314:
#line 1344 "core/cfg.y"
    {
		#ifdef CORE_TLS
			yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected");
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7204 "core/cfg.tab.c"
    break;

  case 315:
#line 1351 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_verify_cert=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7216 "core/cfg.tab.c"
    break;

  case 316:
#line 1358 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7222 "core/cfg.tab.c"
    break;

  case 317:
#line 1359 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_require_cert=(yyvsp[0].intval);
		#else
			warn( "tls-in-core support not compiled in");
		#endif
	}
#line 7234 "core/cfg.tab.c"
    break;

  case 318:
#line 1366 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7240 "core/cfg.tab.c"
    break;

  case 319:
#line 1367 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_cert_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7252 "core/cfg.tab.c"
    break;

  case 320:
#line 1374 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7258 "core/cfg.tab.c"
    break;

  case 321:
#line 1375 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_pkey_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7270 "core/cfg.tab.c"
    break;

  case 322:
#line 1382 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7276 "core/cfg.tab.c"
    break;

  case 323:
#line 1383 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_ca_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7288 "core/cfg.tab.c"
    break;

  case 324:
#line 1390 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7294 "core/cfg.tab.c"
    break;

  case 325:
#line 1391 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_handshake_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7306 "core/cfg.tab.c"
    break;

  case 326:
#line 1398 "core/cfg.y"
    { yyerror("number expected"); }
#line 7312 "core/cfg.tab.c"
    break;

  case 327:
#line 1399 "core/cfg.y"
    {
		#ifdef CORE_TLS
			tls_send_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7324 "core/cfg.tab.c"
    break;

  case 328:
#line 1406 "core/cfg.y"
    { yyerror("number expected"); }
#line 7330 "core/cfg.tab.c"
    break;

  case 329:
#line 1407 "core/cfg.y"
    {
		#ifdef USE_SCTP
			sctp_disable=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7342 "core/cfg.tab.c"
    break;

  case 330:
#line 1414 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7348 "core/cfg.tab.c"
    break;

  case 331:
#line 1415 "core/cfg.y"
    {
		#ifdef USE_SCTP
			sctp_disable=((yyvsp[0].intval)<=1)?!(yyvsp[0].intval):(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7360 "core/cfg.tab.c"
    break;

  case 332:
#line 1422 "core/cfg.y"
    { yyerror("boolean or number expected"); }
#line 7366 "core/cfg.tab.c"
    break;

  case 333:
#line 1423 "core/cfg.y"
    {
		#ifdef USE_SCTP
			sctp_children_no=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 7378 "core/cfg.tab.c"
    break;

  case 334:
#line 1430 "core/cfg.y"
    { yyerror("number expected"); }
#line 7384 "core/cfg.tab.c"
    break;

  case 335:
#line 1431 "core/cfg.y"
    { server_signature=(yyvsp[0].intval); }
#line 7390 "core/cfg.tab.c"
    break;

  case 336:
#line 1432 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7396 "core/cfg.tab.c"
    break;

  case 337:
#line 1433 "core/cfg.y"
    { server_hdr.s=(yyvsp[0].strval);
			server_hdr.len=strlen(server_hdr.s);
	}
#line 7404 "core/cfg.tab.c"
    break;

  case 338:
#line 1436 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7410 "core/cfg.tab.c"
    break;

  case 339:
#line 1437 "core/cfg.y"
    { user_agent_hdr.s=(yyvsp[0].strval);
			user_agent_hdr.len=strlen(user_agent_hdr.s);
	}
#line 7418 "core/cfg.tab.c"
    break;

  case 340:
#line 1440 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7424 "core/cfg.tab.c"
    break;

  case 341:
#line 1441 "core/cfg.y"
    { _sr_uri_host_extra_chars=(yyvsp[0].strval); }
#line 7430 "core/cfg.tab.c"
    break;

  case 342:
#line 1442 "core/cfg.y"
    { yyerror("string value expected"); }
#line 7436 "core/cfg.tab.c"
    break;

  case 343:
#line 1443 "core/cfg.y"
    { reply_to_via=(yyvsp[0].intval); }
#line 7442 "core/cfg.tab.c"
    break;

  case 344:
#line 1444 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7448 "core/cfg.tab.c"
    break;

  case 345:
#line 1445 "core/cfg.y"
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7465 "core/cfg.tab.c"
    break;

  case 346:
#line 1457 "core/cfg.y"
    {
		for(lst_tmp=(yyvsp[-4].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[-2].strval), (yyvsp[0].intval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-4].sockid));
	}
#line 7483 "core/cfg.tab.c"
    break;

  case 347:
#line 1470 "core/cfg.y"
    {
		for(lst_tmp=(yyvsp[-2].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[0].strval), 0,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-2].sockid));
	}
#line 7501 "core/cfg.tab.c"
    break;

  case 348:
#line 1483 "core/cfg.y"
    { yyerror("ip address, interface name or"
									" hostname expected"); }
#line 7508 "core/cfg.tab.c"
    break;

  case 349:
#line 1485 "core/cfg.y"
    {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next){
			add_alias(	lst_tmp->addr_lst->name,
						strlen(lst_tmp->addr_lst->name),
						lst_tmp->port, lst_tmp->proto);
			for (nl_tmp=lst_tmp->addr_lst->next; nl_tmp; nl_tmp=nl_tmp->next)
				add_alias(nl_tmp->name, strlen(nl_tmp->name),
							lst_tmp->port, lst_tmp->proto);
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 7524 "core/cfg.tab.c"
    break;

  case 350:
#line 1496 "core/cfg.y"
    { yyerror("hostname expected"); }
#line 7530 "core/cfg.tab.c"
    break;

  case 351:
#line 1497 "core/cfg.y"
    { sr_auto_aliases=(yyvsp[0].intval); }
#line 7536 "core/cfg.tab.c"
    break;

  case 352:
#line 1498 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7542 "core/cfg.tab.c"
    break;

  case 353:
#line 1499 "core/cfg.y"
    {
		if ((yyvsp[0].strval)){
			default_global_address.s=(yyvsp[0].strval);
			default_global_address.len=strlen((yyvsp[0].strval));
		}
	}
#line 7553 "core/cfg.tab.c"
    break;

  case 354:
#line 1505 "core/cfg.y"
    {yyerror("ip address or hostname expected"); }
#line 7559 "core/cfg.tab.c"
    break;

  case 355:
#line 1506 "core/cfg.y"
    {
		tmp=int2str((yyvsp[0].intval), &i_tmp);
		if ((default_global_port.s=pkg_malloc(i_tmp))==0) {
			PKG_MEM_CRITICAL;
			default_global_port.len=0;
		} else {
			default_global_port.len=i_tmp;
			memcpy(default_global_port.s, tmp, default_global_port.len);
		};
	}
#line 7574 "core/cfg.tab.c"
    break;

  case 356:
#line 1516 "core/cfg.y"
    {yyerror("ip address or hostname expected"); }
#line 7580 "core/cfg.tab.c"
    break;

  case 357:
#line 1517 "core/cfg.y"
    { disable_core_dump=(yyvsp[0].intval); }
#line 7586 "core/cfg.tab.c"
    break;

  case 358:
#line 1518 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7592 "core/cfg.tab.c"
    break;

  case 359:
#line 1519 "core/cfg.y"
    { open_files_limit=(yyvsp[0].intval); }
#line 7598 "core/cfg.tab.c"
    break;

  case 360:
#line 1520 "core/cfg.y"
    { yyerror("number expected"); }
#line 7604 "core/cfg.tab.c"
    break;

  case 361:
#line 1521 "core/cfg.y"
    {
		if (shm_initialized())
			yyerror("shm/shm_mem_size must be before any modparam or the"
					" route blocks");
		else if (shm_mem_size == 0 || shm_mem_size == SHM_MEM_POOL_SIZE)
			shm_mem_size=(yyvsp[0].intval) * 1024 * 1024;
	}
#line 7616 "core/cfg.tab.c"
    break;

  case 362:
#line 1528 "core/cfg.y"
    { yyerror("number expected"); }
#line 7622 "core/cfg.tab.c"
    break;

  case 363:
#line 1529 "core/cfg.y"
    {
		if (shm_initialized())
			yyerror("shm_force_alloc must be before any modparam or the"
					" route blocks");
		else
			shm_force_alloc=(yyvsp[0].intval);
	}
#line 7634 "core/cfg.tab.c"
    break;

  case 364:
#line 1536 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7640 "core/cfg.tab.c"
    break;

  case 365:
#line 1537 "core/cfg.y"
    { mlock_pages=(yyvsp[0].intval); }
#line 7646 "core/cfg.tab.c"
    break;

  case 366:
#line 1538 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7652 "core/cfg.tab.c"
    break;

  case 367:
#line 1539 "core/cfg.y"
    { real_time=(yyvsp[0].intval); }
#line 7658 "core/cfg.tab.c"
    break;

  case 368:
#line 1540 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7664 "core/cfg.tab.c"
    break;

  case 369:
#line 1541 "core/cfg.y"
    { rt_prio=(yyvsp[0].intval); }
#line 7670 "core/cfg.tab.c"
    break;

  case 370:
#line 1542 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7676 "core/cfg.tab.c"
    break;

  case 371:
#line 1543 "core/cfg.y"
    { rt_policy=(yyvsp[0].intval); }
#line 7682 "core/cfg.tab.c"
    break;

  case 372:
#line 1544 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7688 "core/cfg.tab.c"
    break;

  case 373:
#line 1545 "core/cfg.y"
    { rt_timer1_prio=(yyvsp[0].intval); }
#line 7694 "core/cfg.tab.c"
    break;

  case 374:
#line 1546 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7700 "core/cfg.tab.c"
    break;

  case 375:
#line 1547 "core/cfg.y"
    { rt_timer1_policy=(yyvsp[0].intval); }
#line 7706 "core/cfg.tab.c"
    break;

  case 376:
#line 1548 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7712 "core/cfg.tab.c"
    break;

  case 377:
#line 1549 "core/cfg.y"
    { rt_timer2_prio=(yyvsp[0].intval); }
#line 7718 "core/cfg.tab.c"
    break;

  case 378:
#line 1550 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7724 "core/cfg.tab.c"
    break;

  case 379:
#line 1551 "core/cfg.y"
    { rt_timer2_policy=(yyvsp[0].intval); }
#line 7730 "core/cfg.tab.c"
    break;

  case 380:
#line 1552 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7736 "core/cfg.tab.c"
    break;

  case 381:
#line 1553 "core/cfg.y"
    {
		#ifdef USE_MCAST
			mcast_loopback=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7748 "core/cfg.tab.c"
    break;

  case 382:
#line 1560 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7754 "core/cfg.tab.c"
    break;

  case 383:
#line 1561 "core/cfg.y"
    {
		#ifdef USE_MCAST
			mcast_ttl=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7766 "core/cfg.tab.c"
    break;

  case 384:
#line 1568 "core/cfg.y"
    { yyerror("number expected"); }
#line 7772 "core/cfg.tab.c"
    break;

  case 385:
#line 1569 "core/cfg.y"
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7784 "core/cfg.tab.c"
    break;

  case 386:
#line 1576 "core/cfg.y"
    {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 7796 "core/cfg.tab.c"
    break;

  case 387:
#line 1583 "core/cfg.y"
    { yyerror("string expected"); }
#line 7802 "core/cfg.tab.c"
    break;

  case 388:
#line 1584 "core/cfg.y"
    { tos=(yyvsp[0].intval); }
#line 7808 "core/cfg.tab.c"
    break;

  case 389:
#line 1585 "core/cfg.y"
    { if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWDELAY")) {
			tos=IPTOS_LOWDELAY;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_THROUGHPUT")) {
			tos=IPTOS_THROUGHPUT;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_RELIABILITY")) {
			tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_MINCOST")) {
			tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWCOST")) {
			tos=IPTOS_LOWCOST;
#endif
		} else {
			yyerror("invalid tos value - allowed: "
				"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
				"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
				",IPTOS_LOWCOST"
#endif
#if !defined(IPTOS_MINCOST)
				",IPTOS_MINCOST"
#endif
				"\n");
		}
	}
#line 7840 "core/cfg.tab.c"
    break;

  case 390:
#line 1612 "core/cfg.y"
    { yyerror("number expected"); }
#line 7846 "core/cfg.tab.c"
    break;

  case 391:
#line 1613 "core/cfg.y"
    { pmtu_discovery=(yyvsp[0].intval); }
#line 7852 "core/cfg.tab.c"
    break;

  case 392:
#line 1614 "core/cfg.y"
    { yyerror("number expected"); }
#line 7858 "core/cfg.tab.c"
    break;

  case 393:
#line 1615 "core/cfg.y"
    { ser_kill_timeout=(yyvsp[0].intval); }
#line 7864 "core/cfg.tab.c"
    break;

  case 394:
#line 1616 "core/cfg.y"
    { yyerror("number expected"); }
#line 7870 "core/cfg.tab.c"
    break;

  case 395:
#line 1617 "core/cfg.y"
    { default_core_cfg.max_while_loops=(yyvsp[0].intval); }
#line 7876 "core/cfg.tab.c"
    break;

  case 396:
#line 1618 "core/cfg.y"
    { yyerror("number expected"); }
#line 7882 "core/cfg.tab.c"
    break;

  case 397:
#line 1619 "core/cfg.y"
    { pv_set_buffer_size((yyvsp[0].intval)); }
#line 7888 "core/cfg.tab.c"
    break;

  case 398:
#line 1620 "core/cfg.y"
    { yyerror("number expected"); }
#line 7894 "core/cfg.tab.c"
    break;

  case 399:
#line 1621 "core/cfg.y"
    { pv_set_buffer_slots((yyvsp[0].intval)); }
#line 7900 "core/cfg.tab.c"
    break;

  case 400:
#line 1622 "core/cfg.y"
    { yyerror("number expected"); }
#line 7906 "core/cfg.tab.c"
    break;

  case 401:
#line 1623 "core/cfg.y"
    { default_core_cfg.pv_cache_limit=(yyvsp[0].intval); }
#line 7912 "core/cfg.tab.c"
    break;

  case 402:
#line 1624 "core/cfg.y"
    { yyerror("number expected"); }
#line 7918 "core/cfg.tab.c"
    break;

  case 403:
#line 1625 "core/cfg.y"
    { default_core_cfg.pv_cache_action=(yyvsp[0].intval); }
#line 7924 "core/cfg.tab.c"
    break;

  case 404:
#line 1626 "core/cfg.y"
    { yyerror("number expected"); }
#line 7930 "core/cfg.tab.c"
    break;

  case 405:
#line 1627 "core/cfg.y"
    { http_reply_parse=(yyvsp[0].intval); }
#line 7936 "core/cfg.tab.c"
    break;

  case 406:
#line 1628 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7942 "core/cfg.tab.c"
    break;

  case 407:
#line 1629 "core/cfg.y"
    { ksr_verbose_startup=(yyvsp[0].intval); }
#line 7948 "core/cfg.tab.c"
    break;

  case 408:
#line 1630 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 7954 "core/cfg.tab.c"
    break;

  case 409:
#line 1631 "core/cfg.y"
    { ksr_route_locks_size=(yyvsp[0].intval); }
#line 7960 "core/cfg.tab.c"
    break;

  case 410:
#line 1632 "core/cfg.y"
    { yyerror("number expected"); }
#line 7966 "core/cfg.tab.c"
    break;

  case 411:
#line 1633 "core/cfg.y"
    { server_id=(yyvsp[0].intval); }
#line 7972 "core/cfg.tab.c"
    break;

  case 412:
#line 1634 "core/cfg.y"
    { yyerror("number expected"); }
#line 7978 "core/cfg.tab.c"
    break;

  case 413:
#line 1635 "core/cfg.y"
    {
			kemi_onsend_route_callback.s = (yyvsp[0].strval);
			kemi_onsend_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_onsend_route_callback.len==4
					&& strcasecmp(kemi_onsend_route_callback.s, "none")==0) {
				kemi_onsend_route_callback.s = "";
				kemi_onsend_route_callback.len = 0;
			}
		}
#line 7992 "core/cfg.tab.c"
    break;

  case 414:
#line 1644 "core/cfg.y"
    { yyerror("string expected"); }
#line 7998 "core/cfg.tab.c"
    break;

  case 415:
#line 1645 "core/cfg.y"
    {
			kemi_reply_route_callback.s = (yyvsp[0].strval);
			kemi_reply_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_reply_route_callback.len==4
					&& strcasecmp(kemi_reply_route_callback.s, "none")==0) {
				kemi_reply_route_callback.s = "";
				kemi_reply_route_callback.len = 0;
			}
		}
#line 8012 "core/cfg.tab.c"
    break;

  case 416:
#line 1654 "core/cfg.y"
    { yyerror("string expected"); }
#line 8018 "core/cfg.tab.c"
    break;

  case 417:
#line 1655 "core/cfg.y"
    {
			kemi_event_route_callback.s = (yyvsp[0].strval);
			kemi_event_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_event_route_callback.len==4
					&& strcasecmp(kemi_event_route_callback.s, "none")==0) {
				kemi_event_route_callback.s = "";
				kemi_event_route_callback.len = 0;
			}
		}
#line 8032 "core/cfg.tab.c"
    break;

  case 418:
#line 1664 "core/cfg.y"
    { yyerror("string expected"); }
#line 8038 "core/cfg.tab.c"
    break;

  case 419:
#line 1665 "core/cfg.y"
    {
			kemi_received_route_callback.s = (yyvsp[0].strval);
			kemi_received_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_received_route_callback.len==4
					&& strcasecmp(kemi_received_route_callback.s, "none")==0) {
				kemi_received_route_callback.s = "";
				kemi_received_route_callback.len = 0;
			}
		}
#line 8052 "core/cfg.tab.c"
    break;

  case 420:
#line 1674 "core/cfg.y"
    { yyerror("string expected"); }
#line 8058 "core/cfg.tab.c"
    break;

  case 421:
#line 1675 "core/cfg.y"
    { ksr_evrt_received_mode=(yyvsp[0].intval); }
#line 8064 "core/cfg.tab.c"
    break;

  case 422:
#line 1676 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8070 "core/cfg.tab.c"
    break;

  case 423:
#line 1677 "core/cfg.y"
    { set_max_recursive_level((yyvsp[0].intval)); }
#line 8076 "core/cfg.tab.c"
    break;

  case 424:
#line 1678 "core/cfg.y"
    { sr_dst_max_branches = (yyvsp[0].intval); }
#line 8082 "core/cfg.tab.c"
    break;

  case 425:
#line 1679 "core/cfg.y"
    { default_core_cfg.latency_log=(yyvsp[0].intval); }
#line 8088 "core/cfg.tab.c"
    break;

  case 426:
#line 1680 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8094 "core/cfg.tab.c"
    break;

  case 427:
#line 1681 "core/cfg.y"
    { default_core_cfg.latency_cfg_log=(yyvsp[0].intval); }
#line 8100 "core/cfg.tab.c"
    break;

  case 428:
#line 1682 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8106 "core/cfg.tab.c"
    break;

  case 429:
#line 1683 "core/cfg.y"
    { default_core_cfg.latency_limit_db=(yyvsp[0].intval); }
#line 8112 "core/cfg.tab.c"
    break;

  case 430:
#line 1684 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8118 "core/cfg.tab.c"
    break;

  case 431:
#line 1685 "core/cfg.y"
    { default_core_cfg.latency_limit_action=(yyvsp[0].intval); }
#line 8124 "core/cfg.tab.c"
    break;

  case 432:
#line 1686 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8130 "core/cfg.tab.c"
    break;

  case 433:
#line 1687 "core/cfg.y"
    { default_core_cfg.latency_limit_cfg=(yyvsp[0].intval); }
#line 8136 "core/cfg.tab.c"
    break;

  case 434:
#line 1688 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8142 "core/cfg.tab.c"
    break;

  case 435:
#line 1689 "core/cfg.y"
    { sr_msg_time=(yyvsp[0].intval); }
#line 8148 "core/cfg.tab.c"
    break;

  case 436:
#line 1690 "core/cfg.y"
    { yyerror("number  expected"); }
#line 8154 "core/cfg.tab.c"
    break;

  case 437:
#line 1691 "core/cfg.y"
    { onsend_route_reply=(yyvsp[0].intval); }
#line 8160 "core/cfg.tab.c"
    break;

  case 438:
#line 1692 "core/cfg.y"
    { yyerror("int value expected"); }
#line 8166 "core/cfg.tab.c"
    break;

  case 439:
#line 1693 "core/cfg.y"
    { default_core_cfg.udp_mtu=(yyvsp[0].intval); }
#line 8172 "core/cfg.tab.c"
    break;

  case 440:
#line 1694 "core/cfg.y"
    { yyerror("number expected"); }
#line 8178 "core/cfg.tab.c"
    break;

  case 441:
#line 1696 "core/cfg.y"
    { default_core_cfg.force_rport=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 8184 "core/cfg.tab.c"
    break;

  case 442:
#line 1697 "core/cfg.y"
    { yyerror("boolean value expected"); }
#line 8190 "core/cfg.tab.c"
    break;

  case 443:
#line 1699 "core/cfg.y"
    { default_core_cfg.udp_mtu_try_proto=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 8196 "core/cfg.tab.c"
    break;

  case 444:
#line 1701 "core/cfg.y"
    { yyerror("TCP, TLS, SCTP or UDP expected"); }
#line 8202 "core/cfg.tab.c"
    break;

  case 445:
#line 1702 "core/cfg.y"
    { IF_RAW_SOCKS(default_core_cfg.udp4_raw=(yyvsp[0].intval)); }
#line 8208 "core/cfg.tab.c"
    break;

  case 446:
#line 1703 "core/cfg.y"
    { yyerror("number expected"); }
#line 8214 "core/cfg.tab.c"
    break;

  case 447:
#line 1704 "core/cfg.y"
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_mtu=(yyvsp[0].intval));
	}
#line 8222 "core/cfg.tab.c"
    break;

  case 448:
#line 1707 "core/cfg.y"
    { yyerror("number expected"); }
#line 8228 "core/cfg.tab.c"
    break;

  case 449:
#line 1708 "core/cfg.y"
    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_ttl=(yyvsp[0].intval));
	}
#line 8236 "core/cfg.tab.c"
    break;

  case 450:
#line 1711 "core/cfg.y"
    { yyerror("number expected"); }
#line 8242 "core/cfg.tab.c"
    break;

  case 452:
#line 1713 "core/cfg.y"
    { yyerror("unknown config variable"); }
#line 8248 "core/cfg.tab.c"
    break;

  case 454:
#line 1717 "core/cfg.y"
    { (yyval.strval)="default" ; }
#line 8254 "core/cfg.tab.c"
    break;

  case 456:
#line 1721 "core/cfg.y"
    { (yyval.strval)="default" ; }
#line 8260 "core/cfg.tab.c"
    break;

  case 457:
#line 1722 "core/cfg.y"
    {
		yyerror("cfg var field name - use of number or reserved token not allowed: %s",
				yy_number_str);
		YYERROR;
	}
#line 8270 "core/cfg.tab.c"
    break;

  case 458:
#line 1730 "core/cfg.y"
    {
		if (cfg_declare_int((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].intval), 0, 0, NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 8280 "core/cfg.tab.c"
    break;

  case 459:
#line 1735 "core/cfg.y"
    {
		if (cfg_declare_str((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval), NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 8290 "core/cfg.tab.c"
    break;

  case 460:
#line 1740 "core/cfg.y"
    {
		if (cfg_declare_int((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].intval), 0, 0, (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 8300 "core/cfg.tab.c"
    break;

  case 461:
#line 1745 "core/cfg.y"
    {
		if (cfg_declare_str((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 8310 "core/cfg.tab.c"
    break;

  case 462:
#line 1750 "core/cfg.y"
    {
		yyerror("number or string expected");
	}
#line 8318 "core/cfg.tab.c"
    break;

  case 463:
#line 1753 "core/cfg.y"
    {
		if (cfg_ginst_var_int((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].intval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 8328 "core/cfg.tab.c"
    break;

  case 464:
#line 1758 "core/cfg.y"
    {
		if (cfg_ginst_var_string((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 8338 "core/cfg.tab.c"
    break;

  case 465:
#line 1766 "core/cfg.y"
    {
		LM_DBG("loading module %s\n", (yyvsp[0].strval));
			if (load_module((yyvsp[0].strval))!=0) {
				yyerror("failed to load module");
			}
	}
#line 8349 "core/cfg.tab.c"
    break;

  case 466:
#line 1772 "core/cfg.y"
    { yyerror("string expected"); }
#line 8355 "core/cfg.tab.c"
    break;

  case 467:
#line 1773 "core/cfg.y"
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 8370 "core/cfg.tab.c"
    break;

  case 468:
#line 1783 "core/cfg.y"
    { yyerror("string expected"); }
#line 8376 "core/cfg.tab.c"
    break;

  case 469:
#line 1784 "core/cfg.y"
    {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 8391 "core/cfg.tab.c"
    break;

  case 470:
#line 1794 "core/cfg.y"
    { yyerror("string expected"); }
#line 8397 "core/cfg.tab.c"
    break;

  case 471:
#line 1795 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_STRING, (yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8411 "core/cfg.tab.c"
    break;

  case 472:
#line 1804 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_INT, (void*)(yyvsp[-1].intval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 8425 "core/cfg.tab.c"
    break;

  case 473:
#line 1813 "core/cfg.y"
    { yyerror("Invalid arguments"); }
#line 8431 "core/cfg.tab.c"
    break;

  case 474:
#line 1814 "core/cfg.y"
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8442 "core/cfg.tab.c"
    break;

  case 475:
#line 1820 "core/cfg.y"
    { yyerror("string expected"); }
#line 8448 "core/cfg.tab.c"
    break;

  case 476:
#line 1821 "core/cfg.y"
    {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 8459 "core/cfg.tab.c"
    break;

  case 477:
#line 1827 "core/cfg.y"
    { yyerror("string expected"); }
#line 8465 "core/cfg.tab.c"
    break;

  case 478:
#line 1831 "core/cfg.y"
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8471 "core/cfg.tab.c"
    break;

  case 479:
#line 1832 "core/cfg.y"
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8477 "core/cfg.tab.c"
    break;

  case 480:
#line 1835 "core/cfg.y"
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			PKG_MEM_CRITICAL;
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET;
			(yyval.ipaddr)->len=4;
			if (((yyvsp[-6].intval)>255) || ((yyvsp[-6].intval)<0) ||
				((yyvsp[-4].intval)>255) || ((yyvsp[-4].intval)<0) ||
				((yyvsp[-2].intval)>255) || ((yyvsp[-2].intval)<0) ||
				((yyvsp[0].intval)>255) || ((yyvsp[0].intval)<0)) {
				yyerror("invalid ipv4 address");
				(yyval.ipaddr)->u.addr32[0]=0;
				/* $$=0; */
			} else {
				(yyval.ipaddr)->u.addr[0]=(yyvsp[-6].intval);
				(yyval.ipaddr)->u.addr[1]=(yyvsp[-4].intval);
				(yyval.ipaddr)->u.addr[2]=(yyvsp[-2].intval);
				(yyval.ipaddr)->u.addr[3]=(yyvsp[0].intval);
				/*
				$$=htonl( ($1<<24)|
				($3<<16)| ($5<<8)|$7 );
				*/
			}
		}
	}
#line 8509 "core/cfg.tab.c"
    break;

  case 481:
#line 1864 "core/cfg.y"
    {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			PKG_MEM_CRITICAL;
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET6;
			(yyval.ipaddr)->len=16;
			if (inet_pton(AF_INET6, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0) {
				yyerror("bad ipv6 address");
			}
		}
	}
#line 8527 "core/cfg.tab.c"
    break;

  case 482:
#line 1879 "core/cfg.y"
    { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 8533 "core/cfg.tab.c"
    break;

  case 483:
#line 1880 "core/cfg.y"
    {(yyval.ipaddr)=(yyvsp[-1].ipaddr); }
#line 8539 "core/cfg.tab.c"
    break;

  case 484:
#line 1884 "core/cfg.y"
    {
					tmp=int2str((yyvsp[0].intval), &i_tmp);
					if (((yyval.strval)=pkg_malloc(i_tmp+1))==0) {
						yyerror("out of  memory");
						YYABORT;
					} else {
						memcpy((yyval.strval), tmp, i_tmp);
						(yyval.strval)[i_tmp]=0;
					}
					routename = tmp;
						}
#line 8555 "core/cfg.tab.c"
    break;

  case 485:
#line 1895 "core/cfg.y"
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8561 "core/cfg.tab.c"
    break;

  case 486:
#line 1896 "core/cfg.y"
    { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 8567 "core/cfg.tab.c"
    break;

  case 487:
#line 1900 "core/cfg.y"
    { routename=NULL; }
#line 8573 "core/cfg.tab.c"
    break;

  case 488:
#line 1901 "core/cfg.y"
    { routename=NULL; }
#line 8579 "core/cfg.tab.c"
    break;

  case 489:
#line 1905 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[DEFAULT_RT]);
	}
#line 8591 "core/cfg.tab.c"
    break;

  case 490:
#line 1912 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&main_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (main_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[i_tmp]);
	}
#line 8612 "core/cfg.tab.c"
    break;

  case 491:
#line 1928 "core/cfg.y"
    { yyerror("invalid  route  statement"); }
#line 8618 "core/cfg.tab.c"
    break;

  case 492:
#line 1929 "core/cfg.y"
    { yyerror("invalid  request_route  statement"); }
#line 8624 "core/cfg.tab.c"
    break;

  case 493:
#line 1932 "core/cfg.y"
    { routename=NULL; }
#line 8630 "core/cfg.tab.c"
    break;

  case 494:
#line 1935 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[DEFAULT_RT]);
	}
#line 8642 "core/cfg.tab.c"
    break;

  case 495:
#line 1942 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&failure_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (failure_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[i_tmp]);
	}
#line 8663 "core/cfg.tab.c"
    break;

  case 496:
#line 1958 "core/cfg.y"
    { yyerror("invalid failure_route statement"); }
#line 8669 "core/cfg.tab.c"
    break;

  case 497:
#line 1962 "core/cfg.y"
    { routename=NULL; }
#line 8675 "core/cfg.tab.c"
    break;

  case 498:
#line 1963 "core/cfg.y"
    { routename=NULL; }
#line 8681 "core/cfg.tab.c"
    break;

  case 499:
#line 1968 "core/cfg.y"
    {rt=CORE_ONREPLY_ROUTE;}
#line 8687 "core/cfg.tab.c"
    break;

  case 500:
#line 1968 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
	}
#line 8699 "core/cfg.tab.c"
    break;

  case 501:
#line 1975 "core/cfg.y"
    { yyerror("invalid onreply_route statement"); }
#line 8705 "core/cfg.tab.c"
    break;

  case 502:
#line 1976 "core/cfg.y"
    { yyerror("invalid onreply_route statement"); }
#line 8711 "core/cfg.tab.c"
    break;

  case 503:
#line 1978 "core/cfg.y"
    {rt=(*(yyvsp[-1].strval)=='0' && (yyvsp[-1].strval)[1]==0)?CORE_ONREPLY_ROUTE:TM_ONREPLY_ROUTE;}
#line 8717 "core/cfg.tab.c"
    break;

  case 504:
#line 1979 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (*(yyvsp[-5].strval)=='0' && (yyvsp[-5].strval)[1]==0){
			/* onreply_route[0] {} is equivalent with onreply_route {}*/
			push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
		}else{
			i_tmp=route_get(&onreply_rt, (yyvsp[-5].strval));
			if (i_tmp==-1){
				yyerror("internal error");
				YYABORT;
			}
			if (onreply_rt.rlist[i_tmp]){
				yyerror("duplicate route");
				YYABORT;
			}
			push((yyvsp[-1].action), &onreply_rt.rlist[i_tmp]);
		}
	}
#line 8743 "core/cfg.tab.c"
    break;

  case 505:
#line 2000 "core/cfg.y"
    {
		yyerror("invalid onreply_route statement");
	}
#line 8751 "core/cfg.tab.c"
    break;

  case 506:
#line 2005 "core/cfg.y"
    { routename=NULL; }
#line 8757 "core/cfg.tab.c"
    break;

  case 507:
#line 2008 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[DEFAULT_RT]);
	}
#line 8769 "core/cfg.tab.c"
    break;

  case 508:
#line 2015 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&branch_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (branch_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[i_tmp]);
	}
#line 8790 "core/cfg.tab.c"
    break;

  case 509:
#line 2031 "core/cfg.y"
    { yyerror("invalid branch_route statement"); }
#line 8796 "core/cfg.tab.c"
    break;

  case 510:
#line 2034 "core/cfg.y"
    { routename=NULL; }
#line 8802 "core/cfg.tab.c"
    break;

  case 511:
#line 2037 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[DEFAULT_RT]);
	}
#line 8814 "core/cfg.tab.c"
    break;

  case 512:
#line 2044 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&onsend_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (onsend_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[i_tmp]);
	}
#line 8835 "core/cfg.tab.c"
    break;

  case 513:
#line 2060 "core/cfg.y"
    { yyerror("invalid onsend_route statement"); }
#line 8841 "core/cfg.tab.c"
    break;

  case 514:
#line 2063 "core/cfg.y"
    { routename=NULL; }
#line 8847 "core/cfg.tab.c"
    break;

  case 515:
#line 2066 "core/cfg.y"
    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&event_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (event_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &event_rt.rlist[i_tmp]);
	}
#line 8868 "core/cfg.tab.c"
    break;

  case 516:
#line 2083 "core/cfg.y"
    { yyerror("invalid event_route statement"); }
#line 8874 "core/cfg.tab.c"
    break;

  case 517:
#line 2086 "core/cfg.y"
    { if(pp_subst_add((yyvsp[0].strval))<0) YYERROR; }
#line 8880 "core/cfg.tab.c"
    break;

  case 518:
#line 2087 "core/cfg.y"
    { yyerror("invalid subst preprocess statement"); }
#line 8886 "core/cfg.tab.c"
    break;

  case 519:
#line 2088 "core/cfg.y"
    { if(pp_substdef_add((yyvsp[0].strval), 0)<0) YYERROR; }
#line 8892 "core/cfg.tab.c"
    break;

  case 520:
#line 2089 "core/cfg.y"
    { yyerror("invalid substdef preprocess statement"); }
#line 8898 "core/cfg.tab.c"
    break;

  case 521:
#line 2090 "core/cfg.y"
    { if(pp_substdef_add((yyvsp[0].strval), 1)<0) YYERROR; }
#line 8904 "core/cfg.tab.c"
    break;

  case 522:
#line 2091 "core/cfg.y"
    { yyerror("invalid substdefs preprocess statement"); }
#line 8910 "core/cfg.tab.c"
    break;

  case 523:
#line 2113 "core/cfg.y"
    {(yyval.intval)=EQUAL_OP; }
#line 8916 "core/cfg.tab.c"
    break;

  case 524:
#line 2114 "core/cfg.y"
    {(yyval.intval)=DIFF_OP; }
#line 8922 "core/cfg.tab.c"
    break;

  case 525:
#line 2115 "core/cfg.y"
    {(yyval.intval)=EQUAL_OP; }
#line 8928 "core/cfg.tab.c"
    break;

  case 526:
#line 2116 "core/cfg.y"
    {(yyval.intval)=DIFF_OP; }
#line 8934 "core/cfg.tab.c"
    break;

  case 527:
#line 2119 "core/cfg.y"
    {(yyval.intval)=GT_OP; }
#line 8940 "core/cfg.tab.c"
    break;

  case 528:
#line 2120 "core/cfg.y"
    {(yyval.intval)=LT_OP; }
#line 8946 "core/cfg.tab.c"
    break;

  case 529:
#line 2121 "core/cfg.y"
    {(yyval.intval)=GTE_OP; }
#line 8952 "core/cfg.tab.c"
    break;

  case 530:
#line 2122 "core/cfg.y"
    {(yyval.intval)=LTE_OP; }
#line 8958 "core/cfg.tab.c"
    break;

  case 531:
#line 2125 "core/cfg.y"
    {(yyval.intval)=(yyvsp[0].intval); }
#line 8964 "core/cfg.tab.c"
    break;

  case 532:
#line 2126 "core/cfg.y"
    {(yyval.intval)=MATCH_OP; }
#line 8970 "core/cfg.tab.c"
    break;

  case 533:
#line 2132 "core/cfg.y"
    {(yyval.intval)=RVE_EQ_OP; }
#line 8976 "core/cfg.tab.c"
    break;

  case 534:
#line 2133 "core/cfg.y"
    {(yyval.intval)=RVE_DIFF_OP; }
#line 8982 "core/cfg.tab.c"
    break;

  case 535:
#line 2134 "core/cfg.y"
    {(yyval.intval)=RVE_IEQ_OP; }
#line 8988 "core/cfg.tab.c"
    break;

  case 536:
#line 2135 "core/cfg.y"
    {(yyval.intval)=RVE_IDIFF_OP; }
#line 8994 "core/cfg.tab.c"
    break;

  case 537:
#line 2136 "core/cfg.y"
    {(yyval.intval)=RVE_STREQ_OP; }
#line 9000 "core/cfg.tab.c"
    break;

  case 538:
#line 2137 "core/cfg.y"
    {(yyval.intval)=RVE_STRDIFF_OP; }
#line 9006 "core/cfg.tab.c"
    break;

  case 539:
#line 2138 "core/cfg.y"
    {(yyval.intval)=RVE_MATCH_OP; }
#line 9012 "core/cfg.tab.c"
    break;

  case 540:
#line 2141 "core/cfg.y"
    {(yyval.intval)=RVE_GT_OP; }
#line 9018 "core/cfg.tab.c"
    break;

  case 541:
#line 2142 "core/cfg.y"
    {(yyval.intval)=RVE_LT_OP; }
#line 9024 "core/cfg.tab.c"
    break;

  case 542:
#line 2143 "core/cfg.y"
    {(yyval.intval)=RVE_GTE_OP; }
#line 9030 "core/cfg.tab.c"
    break;

  case 543:
#line 2144 "core/cfg.y"
    {(yyval.intval)=RVE_LTE_OP; }
#line 9036 "core/cfg.tab.c"
    break;

  case 544:
#line 2151 "core/cfg.y"
    {(yyval.intval)=URI_O;}
#line 9042 "core/cfg.tab.c"
    break;

  case 545:
#line 2152 "core/cfg.y"
    {(yyval.intval)=FROM_URI_O;}
#line 9048 "core/cfg.tab.c"
    break;

  case 546:
#line 2153 "core/cfg.y"
    {(yyval.intval)=TO_URI_O;}
#line 9054 "core/cfg.tab.c"
    break;

  case 547:
#line 2160 "core/cfg.y"
    { (yyval.intval)=SNDPORT_O; }
#line 9060 "core/cfg.tab.c"
    break;

  case 548:
#line 2161 "core/cfg.y"
    { (yyval.intval)=TOPORT_O; }
#line 9066 "core/cfg.tab.c"
    break;

  case 549:
#line 2162 "core/cfg.y"
    { (yyval.intval)=SNDAF_O; }
#line 9072 "core/cfg.tab.c"
    break;

  case 550:
#line 2166 "core/cfg.y"
    { (yyval.intval)=SRCPORT_O; }
#line 9078 "core/cfg.tab.c"
    break;

  case 551:
#line 2167 "core/cfg.y"
    { (yyval.intval)=DSTPORT_O; }
#line 9084 "core/cfg.tab.c"
    break;

  case 552:
#line 2168 "core/cfg.y"
    { (yyval.intval)=AF_O; }
#line 9090 "core/cfg.tab.c"
    break;

  case 553:
#line 2169 "core/cfg.y"
    { (yyval.intval)=MSGLEN_O; }
#line 9096 "core/cfg.tab.c"
    break;

  case 555:
#line 2175 "core/cfg.y"
    { onsend_check("snd_ip"); (yyval.intval)=SNDIP_O; }
#line 9102 "core/cfg.tab.c"
    break;

  case 556:
#line 2176 "core/cfg.y"
    { onsend_check("to_ip");  (yyval.intval)=TOIP_O; }
#line 9108 "core/cfg.tab.c"
    break;

  case 557:
#line 2179 "core/cfg.y"
    { (yyval.intval)=SRCIP_O; }
#line 9114 "core/cfg.tab.c"
    break;

  case 558:
#line 2180 "core/cfg.y"
    { (yyval.intval)=DSTIP_O; }
#line 9120 "core/cfg.tab.c"
    break;

  case 560:
#line 2188 "core/cfg.y"
    {(yyval.expr)= mk_elem((yyvsp[-1].intval), METHOD_O, 0, RVE_ST, (yyvsp[0].rv_expr));}
#line 9126 "core/cfg.tab.c"
    break;

  case 561:
#line 2190 "core/cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), METHOD_O, 0, STRING_ST,(yyvsp[0].strval)); }
#line 9132 "core/cfg.tab.c"
    break;

  case 562:
#line 2191 "core/cfg.y"
    { (yyval.expr)=0; yyerror("string expected"); }
#line 9138 "core/cfg.tab.c"
    break;

  case 563:
#line 2193 "core/cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator,== , !=, or =~ expected"); }
#line 9144 "core/cfg.tab.c"
    break;

  case 564:
#line 2195 "core/cfg.y"
    {(yyval.expr) = mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr)); }
#line 9150 "core/cfg.tab.c"
    break;

  case 565:
#line 2197 "core/cfg.y"
    {(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 9156 "core/cfg.tab.c"
    break;

  case 566:
#line 2199 "core/cfg.y"
    { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
#line 9162 "core/cfg.tab.c"
    break;

  case 567:
#line 2201 "core/cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator, == , != or =~ expected"); }
#line 9168 "core/cfg.tab.c"
    break;

  case 568:
#line 2202 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9174 "core/cfg.tab.c"
    break;

  case 569:
#line 2204 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9180 "core/cfg.tab.c"
    break;

  case 570:
#line 2205 "core/cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
#line 9186 "core/cfg.tab.c"
    break;

  case 571:
#line 2206 "core/cfg.y"
    { (yyval.expr)=0; yyerror("number expected"); }
#line 9192 "core/cfg.tab.c"
    break;

  case 572:
#line 2207 "core/cfg.y"
    { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
#line 9198 "core/cfg.tab.c"
    break;

  case 573:
#line 2209 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 9204 "core/cfg.tab.c"
    break;

  case 574:
#line 2211 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9210 "core/cfg.tab.c"
    break;

  case 575:
#line 2213 "core/cfg.y"
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 9216 "core/cfg.tab.c"
    break;

  case 576:
#line 2215 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 9222 "core/cfg.tab.c"
    break;

  case 577:
#line 2217 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 9228 "core/cfg.tab.c"
    break;

  case 578:
#line 2219 "core/cfg.y"
    { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 9234 "core/cfg.tab.c"
    break;

  case 579:
#line 2220 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST, (yyvsp[0].ipnet)); }
#line 9240 "core/cfg.tab.c"
    break;

  case 580:
#line 2221 "core/cfg.y"
    {
			s_tmp.s=0;
			(yyval.expr)=0;
			if (rve_is_constant((yyvsp[0].rv_expr))){
				i_tmp=rve_guess_type((yyvsp[0].rv_expr));
				if (i_tmp==RV_INT)
					yyerror("string expected");
				else if (i_tmp==RV_STR){
					if (((rval_tmp=rval_expr_eval(0, 0, (yyvsp[0].rv_expr)))==0) ||
								(rval_get_str(0, 0, &s_tmp, rval_tmp, 0)<0)){
						rval_destroy(rval_tmp);
						yyerror("bad rvalue expression");
					}else{
						rval_destroy(rval_tmp);
					}
				}else{
					yyerror("BUG: unexpected dynamic type");
				}
			}else{
					/* warn("non constant rvalue in ip comparison") */;
			}
			if (s_tmp.s){
				ip_tmp=str2ip(&s_tmp);
				if (ip_tmp==0)
					ip_tmp=str2ip6(&s_tmp);
				pkg_free(s_tmp.s);
				if (ip_tmp) {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST,
								mk_new_net_bitlen(ip_tmp, ip_tmp->len*8) );
				} else {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
				}
			}else{
				(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
			}
		}
#line 9281 "core/cfg.tab.c"
    break;

  case 581:
#line 2258 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, STRING_ST, (yyvsp[0].strval)); }
#line 9287 "core/cfg.tab.c"
    break;

  case 582:
#line 2260 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 9293 "core/cfg.tab.c"
    break;

  case 583:
#line 2262 "core/cfg.y"
    { (yyval.expr)=0; yyerror( "ip address or hostname expected" ); }
#line 9299 "core/cfg.tab.c"
    break;

  case 584:
#line 2264 "core/cfg.y"
    { (yyval.expr)=0; yyerror("invalid operator, ==, != or =~ expected");}
#line 9305 "core/cfg.tab.c"
    break;

  case 585:
#line 2267 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 9311 "core/cfg.tab.c"
    break;

  case 586:
#line 2269 "core/cfg.y"
    { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 9317 "core/cfg.tab.c"
    break;

  case 587:
#line 2271 "core/cfg.y"
    { (yyval.expr)=0; yyerror("URI, SRCIP or DSTIP expected"); }
#line 9323 "core/cfg.tab.c"
    break;

  case 588:
#line 2272 "core/cfg.y"
    { (yyval.expr)=0; yyerror ("invalid operator, == or != expected"); }
#line 9329 "core/cfg.tab.c"
    break;

  case 589:
#line 2276 "core/cfg.y"
    { (yyval.ipnet)=mk_new_net((yyvsp[-2].ipaddr), (yyvsp[0].ipaddr)); }
#line 9335 "core/cfg.tab.c"
    break;

  case 590:
#line 2277 "core/cfg.y"
    {
		if (((yyvsp[0].intval)<0) || ((yyvsp[0].intval)>(yyvsp[-2].ipaddr)->len*8)) {
			yyerror("invalid bit number in netmask");
			(yyval.ipnet)=0;
		} else {
			(yyval.ipnet)=mk_new_net_bitlen((yyvsp[-2].ipaddr), (yyvsp[0].intval));
		/*
			$$=mk_new_net($1, htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
		*/
		}
	}
#line 9351 "core/cfg.tab.c"
    break;

  case 591:
#line 2288 "core/cfg.y"
    { (yyval.ipnet)=mk_new_net_bitlen((yyvsp[0].ipaddr), (yyvsp[0].ipaddr)->len*8); }
#line 9357 "core/cfg.tab.c"
    break;

  case 592:
#line 2289 "core/cfg.y"
    { (yyval.ipnet)=0; yyerror("netmask (eg:255.0.0.0 or 8) expected"); }
#line 9363 "core/cfg.tab.c"
    break;

  case 593:
#line 2293 "core/cfg.y"
    { (yyval.strval)=(yyvsp[0].strval); }
#line 9369 "core/cfg.tab.c"
    break;

  case 594:
#line 2294 "core/cfg.y"
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9389 "core/cfg.tab.c"
    break;

  case 595:
#line 2309 "core/cfg.y"
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9409 "core/cfg.tab.c"
    break;

  case 596:
#line 2324 "core/cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9415 "core/cfg.tab.c"
    break;

  case 597:
#line 2325 "core/cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 9421 "core/cfg.tab.c"
    break;

  case 600:
#line 2330 "core/cfg.y"
    {
			/* get string version */
			(yyval.strval)=pkg_malloc(strlen(yy_number_str)+1);
			if ((yyval.strval)==0) {
				PKG_MEM_ERROR;
			} else {
				strcpy((yyval.strval), yy_number_str);
			}
		}
#line 9435 "core/cfg.tab.c"
    break;

  case 601:
#line 2342 "core/cfg.y"
    { (yyval.strval)=(yyvsp[0].strval); }
#line 9441 "core/cfg.tab.c"
    break;

  case 602:
#line 2343 "core/cfg.y"
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9461 "core/cfg.tab.c"
    break;

  case 603:
#line 2358 "core/cfg.y"
    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 9481 "core/cfg.tab.c"
    break;

  case 604:
#line 2373 "core/cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9488 "core/cfg.tab.c"
    break;

  case 605:
#line 2375 "core/cfg.y"
    { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 9495 "core/cfg.tab.c"
    break;

  case 606:
#line 2382 "core/cfg.y"
    {
		/* check if allowed */
		if ((yyvsp[0].action) && rt==ONSEND_ROUTE) {
			switch((yyvsp[0].action)->type) {
				case DROP_T:
				case LOG_T:
				case SETFLAG_T:
				case RESETFLAG_T:
				case ISFLAGSET_T:
				case IF_T:
				case MODULE0_T:
				case MODULE1_T:
				case MODULE2_T:
				case MODULE3_T:
				case MODULE4_T:
				case MODULE5_T:
				case MODULE6_T:
				case MODULEX_T:
				case SET_FWD_NO_CONNECT_T:
				case SET_RPL_NO_CONNECT_T:
				case SET_FWD_CLOSE_T:
				case SET_RPL_CLOSE_T:
					(yyval.action)=(yyvsp[0].action);
					break;
				default:
					(yyval.action)=0;
					yyerror("command not allowed in onsend_route\n");
			}
		} else {
			(yyval.action)=(yyvsp[0].action);
		}
	}
#line 9532 "core/cfg.tab.c"
    break;

  case 607:
#line 2424 "core/cfg.y"
    { (yyval.action)=(yyvsp[0].action); }
#line 9538 "core/cfg.tab.c"
    break;

  case 608:
#line 2425 "core/cfg.y"
    { (yyval.action)=(yyvsp[-1].action); }
#line 9544 "core/cfg.tab.c"
    break;

  case 609:
#line 2428 "core/cfg.y"
    {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 9550 "core/cfg.tab.c"
    break;

  case 610:
#line 2429 "core/cfg.y"
    {(yyval.action)=(yyvsp[0].action);}
#line 9556 "core/cfg.tab.c"
    break;

  case 611:
#line 2430 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad command"); }
#line 9562 "core/cfg.tab.c"
    break;

  case 612:
#line 2433 "core/cfg.y"
    {(yyval.action)=(yyvsp[-1].action);}
#line 9568 "core/cfg.tab.c"
    break;

  case 613:
#line 2434 "core/cfg.y"
    {(yyval.action)=(yyvsp[0].action);}
#line 9574 "core/cfg.tab.c"
    break;

  case 614:
#line 2435 "core/cfg.y"
    {(yyval.action)=(yyvsp[0].action);}
#line 9580 "core/cfg.tab.c"
    break;

  case 615:
#line 2436 "core/cfg.y"
    { (yyval.action)=(yyvsp[0].action); }
#line 9586 "core/cfg.tab.c"
    break;

  case 616:
#line 2437 "core/cfg.y"
    { (yyval.action)=(yyvsp[-1].action); }
#line 9592 "core/cfg.tab.c"
    break;

  case 617:
#line 2438 "core/cfg.y"
    {(yyval.action)=(yyvsp[-1].action);}
#line 9598 "core/cfg.tab.c"
    break;

  case 618:
#line 2439 "core/cfg.y"
    {(yyval.action)=0;}
#line 9604 "core/cfg.tab.c"
    break;

  case 619:
#line 2440 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
#line 9610 "core/cfg.tab.c"
    break;

  case 620:
#line 2443 "core/cfg.y"
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action), NOSUBTYPE, 0);
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9623 "core/cfg.tab.c"
    break;

  case 621:
#line 2451 "core/cfg.y"
    {
		if ((yyvsp[-3].rv_expr) && rval_expr_int_check((yyvsp[-3].rv_expr))>=0){
			warn_ct_rve((yyvsp[-3].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-3].rv_expr), ACTIONS_ST, (yyvsp[-2].action), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 9636 "core/cfg.tab.c"
    break;

  case 622:
#line 2461 "core/cfg.y"
    {
			(yyval.rv_expr)=0;
			if ((yyvsp[0].rv_expr) && !rve_is_constant((yyvsp[0].rv_expr))){
				yyerror("constant expected");
				YYERROR;
			/*
			} else if ($1 &&
						!rve_check_type((enum rval_type*)&i_tmp, $1, 0, 0 ,0)){
				yyerror("invalid expression (bad type)");
			}else if ($1 && i_tmp!=RV_INT){
				yyerror("invalid expression type, int expected\n");
			*/
			}else
				(yyval.rv_expr)=(yyvsp[0].rv_expr);
		}
#line 9656 "core/cfg.tab.c"
    break;

  case 623:
#line 2478 "core/cfg.y"
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9668 "core/cfg.tab.c"
    break;

  case 624:
#line 2485 "core/cfg.y"
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 1, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9680 "core/cfg.tab.c"
    break;

  case 625:
#line 2492 "core/cfg.y"
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9692 "core/cfg.tab.c"
    break;

  case 626:
#line 2499 "core/cfg.y"
    {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad regex case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 1, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9704 "core/cfg.tab.c"
    break;

  case 627:
#line 2506 "core/cfg.y"
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9714 "core/cfg.tab.c"
    break;

  case 628:
#line 2511 "core/cfg.y"
    {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 9724 "core/cfg.tab.c"
    break;

  case 629:
#line 2516 "core/cfg.y"
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9730 "core/cfg.tab.c"
    break;

  case 630:
#line 2517 "core/cfg.y"
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9736 "core/cfg.tab.c"
    break;

  case 631:
#line 2518 "core/cfg.y"
    { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 9742 "core/cfg.tab.c"
    break;

  case 632:
#line 2519 "core/cfg.y"
    { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 9748 "core/cfg.tab.c"
    break;

  case 633:
#line 2520 "core/cfg.y"
    { (yyval.case_stms)=0; yyerror ("bad case body"); }
#line 9754 "core/cfg.tab.c"
    break;

  case 634:
#line 2523 "core/cfg.y"
    {
		(yyval.case_stms)=(yyvsp[-1].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		if ((yyval.case_stms)){
			*((yyval.case_stms)->append)=(yyvsp[0].case_stms);
			if (*((yyval.case_stms)->append)!=0)
				(yyval.case_stms)->append=&((*((yyval.case_stms)->append))->next);
		}
	}
#line 9768 "core/cfg.tab.c"
    break;

  case 635:
#line 2532 "core/cfg.y"
    {
		(yyval.case_stms)=(yyvsp[0].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		else (yyval.case_stms)->append=&((yyval.case_stms)->next);
	}
#line 9778 "core/cfg.tab.c"
    break;

  case 636:
#line 2539 "core/cfg.y"
    {
		(yyval.action)=0;
		if ((yyvsp[-3].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else if ((yyvsp[-1].case_stms)==0){
			yyerror ("bad switch body");
			YYERROR;
		}else if (case_check_default((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): too many "
							"\"default:\" labels\n");
			YYERROR;
		}else if (case_check_type((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): mixed integer and"
							" string/RE cases not allowed\n");
			YYERROR;
		}else{
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-3].rv_expr), CASE_ST, (yyvsp[-1].case_stms));
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9808 "core/cfg.tab.c"
    break;

  case 637:
#line 2564 "core/cfg.y"
    {
		(yyval.action)=0;
		warn("empty switch()");
		if ((yyvsp[-2].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else{
			/* it might have sideffects, so leave it for the optimizer */
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-2].rv_expr), CASE_ST, 0);
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 9829 "core/cfg.tab.c"
    break;

  case 638:
#line 2580 "core/cfg.y"
    { (yyval.action)=0; yyerror ("bad expression in switch(...)"); }
#line 9835 "core/cfg.tab.c"
    break;

  case 639:
#line 2582 "core/cfg.y"
    {(yyval.action)=0; yyerror ("bad switch body"); }
#line 9841 "core/cfg.tab.c"
    break;

  case 640:
#line 2586 "core/cfg.y"
    {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "while");
			(yyval.action)=mk_action( WHILE_T, 2, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else{
			yyerror_at(&(yyvsp[-1].rv_expr)->fpos, "bad while(...) expression");
			YYERROR;
		}
	}
#line 9856 "core/cfg.tab.c"
    break;

  case 641:
#line 2605 "core/cfg.y"
    {
		if (sel.n >= MAX_SELECT_PARAMS-1) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[0].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[0].strval));
		sel.n++;
	}
#line 9870 "core/cfg.tab.c"
    break;

  case 642:
#line 2614 "core/cfg.y"
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_INT;
		sel.params[sel.n].v.i = (yyvsp[-1].intval);
		sel.n++;
	}
#line 9887 "core/cfg.tab.c"
    break;

  case 643:
#line 2626 "core/cfg.y"
    {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-1].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-1].strval));
		sel.n++;
	}
#line 9905 "core/cfg.tab.c"
    break;

  case 646:
#line 2645 "core/cfg.y"
    { sel.n = 0; sel.f[0] = 0; }
#line 9911 "core/cfg.tab.c"
    break;

  case 647:
#line 2645 "core/cfg.y"
    {
		sel_ptr = (select_t*)pkg_malloc(sizeof(select_t));
		if (!sel_ptr) {
			yyerror("No memory left to allocate select structure\n");
		}
		memcpy(sel_ptr, &sel, sizeof(select_t));
		(yyval.select) = sel_ptr;
	}
#line 9924 "core/cfg.tab.c"
    break;

  case 648:
#line 2655 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_FROM; }
#line 9930 "core/cfg.tab.c"
    break;

  case 649:
#line 2656 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_TO; }
#line 9936 "core/cfg.tab.c"
    break;

  case 650:
#line 2657 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_URI; }
#line 9942 "core/cfg.tab.c"
    break;

  case 651:
#line 2658 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_URI; }
#line 9948 "core/cfg.tab.c"
    break;

  case 652:
#line 2659 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_USER; }
#line 9954 "core/cfg.tab.c"
    break;

  case 653:
#line 2660 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_USER; }
#line 9960 "core/cfg.tab.c"
    break;

  case 654:
#line 2661 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_DOMAIN; }
#line 9966 "core/cfg.tab.c"
    break;

  case 655:
#line 2662 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_DOMAIN; }
#line 9972 "core/cfg.tab.c"
    break;

  case 656:
#line 2663 "core/cfg.y"
    { s_attr->type |= AVP_TRACK_ALL | AVP_CLASS_GLOBAL; }
#line 9978 "core/cfg.tab.c"
    break;

  case 657:
#line 2666 "core/cfg.y"
    { s_attr->type |= AVP_NAME_STR; s_attr->name.s.s = (yyvsp[0].strval); s_attr->name.s.len = strlen ((yyvsp[0].strval)); }
#line 9984 "core/cfg.tab.c"
    break;

  case 660:
#line 2673 "core/cfg.y"
    {
		s_attr = (struct avp_spec*)pkg_malloc(sizeof(struct avp_spec));
		if (!s_attr) { yyerror("No memory left"); YYABORT; }
		else s_attr->type = 0;
	}
#line 9994 "core/cfg.tab.c"
    break;

  case 661:
#line 2680 "core/cfg.y"
    { (yyval.attr) = s_attr; }
#line 10000 "core/cfg.tab.c"
    break;

  case 662:
#line 2683 "core/cfg.y"
    {
		s_attr->type|= (AVP_NAME_STR | ((yyvsp[-1].intval)<0?AVP_INDEX_BACKWARD:AVP_INDEX_FORWARD));
		s_attr->index = ((yyvsp[-1].intval)<0?-(yyvsp[-1].intval):(yyvsp[-1].intval));
		(yyval.attr) = s_attr;
	}
#line 10010 "core/cfg.tab.c"
    break;

  case 663:
#line 2690 "core/cfg.y"
    {
		s_attr->type|= AVP_INDEX_ALL;
		(yyval.attr) = s_attr;
	}
#line 10019 "core/cfg.tab.c"
    break;

  case 670:
#line 2712 "core/cfg.y"
    {
		if ((yyvsp[0].lval)->type==LV_AVP){
			s_attr = pkg_malloc(sizeof(struct avp_spec));
			if (!s_attr) { yyerror("No memory left"); YYABORT; }
			else{
				*s_attr=(yyvsp[0].lval)->lv.avps;
			}
			(yyval.attr)=s_attr;
		}else
			(yyval.attr)=0; /* not an avp, a pvar */
		pkg_free((yyvsp[0].lval));
	}
#line 10036 "core/cfg.tab.c"
    break;

  case 671:
#line 2724 "core/cfg.y"
    {
		avp_spec_t *avp_spec;
		str s;
		int type, idx;
		avp_spec = pkg_malloc(sizeof(*avp_spec));
		if (!avp_spec) {
			yyerror("Not enough memory");
			YYABORT;
		}
		s.s = (yyvsp[0].strval);
		if (s.s[0] == '$')
			s.s++;
		s.len = strlen(s.s);
		if (parse_avp_name(&s, &type, &avp_spec->name, &idx)) {
			yyerror("error when parsing AVP");
			pkg_free(avp_spec);
			YYABORT;
		}
		avp_spec->type = type;
		avp_spec->index = idx;
		(yyval.attr) = avp_spec;
	}
#line 10063 "core/cfg.tab.c"
    break;

  case 672:
#line 2748 "core/cfg.y"
    {
			s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
			pv_spec=pv_cache_get(&s_tmp);
			if (!pv_spec) {
				yyerror("Can't get from cache: %s", (yyvsp[0].strval));
				YYABORT;
			}
			(yyval.pvar)=pv_spec;
		}
#line 10077 "core/cfg.tab.c"
    break;

  case 673:
#line 2759 "core/cfg.y"
    {
				lval_tmp=pkg_malloc(sizeof(*lval_tmp));
				if (!lval_tmp) {
					yyerror("Not enough memory");
					YYABORT;
				}
				memset(lval_tmp, 0, sizeof(*lval_tmp));
				s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen(s_tmp.s);
				lval_tmp->lv.pvs = pv_cache_get(&s_tmp);
				if (lval_tmp->lv.pvs==NULL){
					lval_tmp->lv.avps.type|= AVP_NAME_STR;
					lval_tmp->lv.avps.name.s.s = s_tmp.s+1;
					lval_tmp->lv.avps.name.s.len = s_tmp.len-1;
					lval_tmp->type=LV_AVP;
				}else{
					lval_tmp->type=LV_PVAR;
				}
				(yyval.lval) = lval_tmp;
				DBG("parsed ambiguous avp/pvar \"%.*s\" to %d\n",
							s_tmp.len, s_tmp.s, lval_tmp->type);
			}
#line 10103 "core/cfg.tab.c"
    break;

  case 674:
#line 2790 "core/cfg.y"
    { (yyval.intval) = ASSIGN_T; }
#line 10109 "core/cfg.tab.c"
    break;

  case 675:
#line 2794 "core/cfg.y"
    {
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_AVP; lval_tmp->lv.avps=*(yyvsp[0].attr);
					pkg_free((yyvsp[0].attr)); /* free the avp spec we just copied */
					(yyval.lval)=lval_tmp;
				}
#line 10124 "core/cfg.tab.c"
    break;

  case 676:
#line 2804 "core/cfg.y"
    {
					if (!pv_is_w((yyvsp[0].pvar)))
						yyerror("read only pvar in assignment left side");
					if ((yyvsp[0].pvar)->trans!=0)
						yyerror("pvar with transformations in assignment"
								" left side");
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_PVAR; lval_tmp->lv.pvs=(yyvsp[0].pvar);
					(yyval.lval)=lval_tmp;
				}
#line 10143 "core/cfg.tab.c"
    break;

  case 677:
#line 2818 "core/cfg.y"
    {
					if (((yyvsp[0].lval))->type==LV_PVAR){
						if (!pv_is_w((yyvsp[0].lval)->lv.pvs))
							yyerror("read only pvar in assignment left side");
						if ((yyvsp[0].lval)->lv.pvs->trans!=0)
							yyerror("pvar with transformations in assignment"
									" left side");
					}
					(yyval.lval)=(yyvsp[0].lval);
				}
#line 10158 "core/cfg.tab.c"
    break;

  case 678:
#line 2830 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_INT, (void*)(yyvsp[0].intval)); }
#line 10164 "core/cfg.tab.c"
    break;

  case 679:
#line 2831 "core/cfg.y"
    {	s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
							(yyval.rv_expr)=mk_rve_rval(RV_STR, &s_tmp); }
#line 10171 "core/cfg.tab.c"
    break;

  case 680:
#line 2833 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_AVP, (yyvsp[0].attr)); pkg_free((yyvsp[0].attr)); }
#line 10177 "core/cfg.tab.c"
    break;

  case 681:
#line 2834 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].pvar)); }
#line 10183 "core/cfg.tab.c"
    break;

  case 682:
#line 2835 "core/cfg.y"
    {
							switch((yyvsp[0].lval)->type){
								case LV_AVP:
									(yyval.rv_expr)=mk_rve_rval(RV_AVP, &(yyvsp[0].lval)->lv.avps);
									break;
								case LV_PVAR:
									(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].lval)->lv.pvs);
									break;
								default:
									yyerror("BUG: invalid lvalue type ");
									YYABORT;
							}
							pkg_free((yyvsp[0].lval)); /* not needed anymore */
						}
#line 10202 "core/cfg.tab.c"
    break;

  case 683:
#line 2849 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_SEL, (yyvsp[0].select)); pkg_free((yyvsp[0].select)); }
#line 10208 "core/cfg.tab.c"
    break;

  case 684:
#line 2850 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[0].action)); }
#line 10214 "core/cfg.tab.c"
    break;

  case 685:
#line 2851 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve_rval(RV_BEXPR, (yyvsp[0].expr)); }
#line 10220 "core/cfg.tab.c"
    break;

  case 686:
#line 2852 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 10226 "core/cfg.tab.c"
    break;

  case 687:
#line 2853 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad command block"); }
#line 10232 "core/cfg.tab.c"
    break;

  case 688:
#line 2854 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 10238 "core/cfg.tab.c"
    break;

  case 689:
#line 2855 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10244 "core/cfg.tab.c"
    break;

  case 690:
#line 2859 "core/cfg.y"
    { (yyval.intval)=RVE_LNOT_OP; }
#line 10250 "core/cfg.tab.c"
    break;

  case 691:
#line 2860 "core/cfg.y"
    { (yyval.intval)=RVE_BNOT_OP; }
#line 10256 "core/cfg.tab.c"
    break;

  case 692:
#line 2861 "core/cfg.y"
    { (yyval.intval)=RVE_UMINUS_OP; }
#line 10262 "core/cfg.tab.c"
    break;

  case 693:
#line 2874 "core/cfg.y"
    { (yyval.rv_expr)=(yyvsp[0].rv_expr);
										if ((yyval.rv_expr)==0){
											/*yyerror("out of memory\n");*/
											YYERROR;
										}
									}
#line 10273 "core/cfg.tab.c"
    break;

  case 694:
#line 2880 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve1((yyvsp[-1].intval), (yyvsp[0].rv_expr)); }
#line 10279 "core/cfg.tab.c"
    break;

  case 695:
#line 2881 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve1(RVE_INT_OP, (yyvsp[0].rv_expr)); }
#line 10285 "core/cfg.tab.c"
    break;

  case 696:
#line 2882 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve1(RVE_STR_OP, (yyvsp[0].rv_expr)); }
#line 10291 "core/cfg.tab.c"
    break;

  case 697:
#line 2883 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_PLUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10297 "core/cfg.tab.c"
    break;

  case 698:
#line 2884 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_MINUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10303 "core/cfg.tab.c"
    break;

  case 699:
#line 2885 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_MUL_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10309 "core/cfg.tab.c"
    break;

  case 700:
#line 2886 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_DIV_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10315 "core/cfg.tab.c"
    break;

  case 701:
#line 2887 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_MOD_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 10321 "core/cfg.tab.c"
    break;

  case 702:
#line 2888 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_BOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr)); }
#line 10327 "core/cfg.tab.c"
    break;

  case 703:
#line 2889 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_BAND_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10333 "core/cfg.tab.c"
    break;

  case 704:
#line 2890 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_BXOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10339 "core/cfg.tab.c"
    break;

  case 705:
#line 2891 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_BLSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10345 "core/cfg.tab.c"
    break;

  case 706:
#line 2892 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve2(RVE_BRSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 10351 "core/cfg.tab.c"
    break;

  case 707:
#line 2893 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve2( (yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10357 "core/cfg.tab.c"
    break;

  case 708:
#line 2894 "core/cfg.y"
    {
			/* comparing with $null => treat as defined or !defined */
			if((yyvsp[0].rv_expr)->op==RVE_RVAL_OP && (yyvsp[0].rv_expr)->left.rval.type==RV_PVAR
					&& (yyvsp[0].rv_expr)->left.rval.v.pvs.type==PVT_NULL) {
				if((yyvsp[-1].intval)==RVE_DIFF_OP || (yyvsp[-1].intval)==RVE_IDIFF_OP
						|| (yyvsp[-1].intval)==RVE_STRDIFF_OP) {
					DBG("comparison with $null switched to notdefined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[-2].rv_expr));
				} else {
					DBG("comparison with $null switched to defined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_NOTDEFINED_OP, (yyvsp[-2].rv_expr));
				}
				/* free rve struct for $null */
				rve_destroy((yyvsp[0].rv_expr));
			} else {
				(yyval.rv_expr)=mk_rve2((yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));
			}
		}
#line 10380 "core/cfg.tab.c"
    break;

  case 709:
#line 2912 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve2(RVE_LAND_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10386 "core/cfg.tab.c"
    break;

  case 710:
#line 2913 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve2(RVE_LOR_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 10392 "core/cfg.tab.c"
    break;

  case 711:
#line 2914 "core/cfg.y"
    { (yyval.rv_expr)=(yyvsp[-1].rv_expr);}
#line 10398 "core/cfg.tab.c"
    break;

  case 712:
#line 2915 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve1(RVE_STRLEN_OP, (yyvsp[-1].rv_expr));}
#line 10404 "core/cfg.tab.c"
    break;

  case 713:
#line 2916 "core/cfg.y"
    {(yyval.rv_expr)=mk_rve1(RVE_STREMPTY_OP, (yyvsp[-1].rv_expr));}
#line 10410 "core/cfg.tab.c"
    break;

  case 714:
#line 2917 "core/cfg.y"
    { (yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[0].rv_expr));}
#line 10416 "core/cfg.tab.c"
    break;

  case 715:
#line 2918 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10422 "core/cfg.tab.c"
    break;

  case 716:
#line 2919 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10428 "core/cfg.tab.c"
    break;

  case 717:
#line 2920 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10434 "core/cfg.tab.c"
    break;

  case 718:
#line 2921 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10440 "core/cfg.tab.c"
    break;

  case 719:
#line 2922 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10446 "core/cfg.tab.c"
    break;

  case 720:
#line 2923 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10452 "core/cfg.tab.c"
    break;

  case 721:
#line 2924 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10458 "core/cfg.tab.c"
    break;

  case 722:
#line 2925 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10464 "core/cfg.tab.c"
    break;

  case 723:
#line 2926 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10470 "core/cfg.tab.c"
    break;

  case 724:
#line 2927 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10476 "core/cfg.tab.c"
    break;

  case 725:
#line 2929 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10482 "core/cfg.tab.c"
    break;

  case 726:
#line 2931 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10488 "core/cfg.tab.c"
    break;

  case 727:
#line 2932 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10494 "core/cfg.tab.c"
    break;

  case 728:
#line 2933 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10500 "core/cfg.tab.c"
    break;

  case 729:
#line 2934 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10506 "core/cfg.tab.c"
    break;

  case 730:
#line 2935 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10512 "core/cfg.tab.c"
    break;

  case 731:
#line 2936 "core/cfg.y"
    { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 10518 "core/cfg.tab.c"
    break;

  case 732:
#line 2939 "core/cfg.y"
    { (yyval.action)=mk_action((yyvsp[-1].intval), 2, LVAL_ST, (yyvsp[-2].lval),
														 	  RVE_ST, (yyvsp[0].rv_expr));
											set_cfg_pos((yyval.action));
										}
#line 10527 "core/cfg.tab.c"
    break;

  case 733:
#line 2957 "core/cfg.y"
    { (yyval.intval) = 1; }
#line 10533 "core/cfg.tab.c"
    break;

  case 734:
#line 2958 "core/cfg.y"
    { (yyval.intval) = 0; }
#line 10539 "core/cfg.tab.c"
    break;

  case 735:
#line 2959 "core/cfg.y"
    { (yyval.intval) = -1; }
#line 10545 "core/cfg.tab.c"
    break;

  case 736:
#line 2962 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10551 "core/cfg.tab.c"
    break;

  case 737:
#line 2963 "core/cfg.y"
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10557 "core/cfg.tab.c"
    break;

  case 738:
#line 2964 "core/cfg.y"
    { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10563 "core/cfg.tab.c"
    break;

  case 739:
#line 2965 "core/cfg.y"
    { (yyval.action)=mk_action(	FORWARD_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10569 "core/cfg.tab.c"
    break;

  case 740:
#line 2966 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10575 "core/cfg.tab.c"
    break;

  case 741:
#line 2967 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10581 "core/cfg.tab.c"
    break;

  case 742:
#line 2968 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10587 "core/cfg.tab.c"
    break;

  case 743:
#line 2969 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10593 "core/cfg.tab.c"
    break;

  case 744:
#line 2970 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10599 "core/cfg.tab.c"
    break;

  case 745:
#line 2971 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10605 "core/cfg.tab.c"
    break;

  case 746:
#line 2972 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10611 "core/cfg.tab.c"
    break;

  case 747:
#line 2973 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad forward argument"); }
#line 10617 "core/cfg.tab.c"
    break;

  case 748:
#line 2974 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10623 "core/cfg.tab.c"
    break;

  case 749:
#line 2975 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10629 "core/cfg.tab.c"
    break;

  case 750:
#line 2976 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10635 "core/cfg.tab.c"
    break;

  case 751:
#line 2977 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10641 "core/cfg.tab.c"
    break;

  case 752:
#line 2978 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10647 "core/cfg.tab.c"
    break;

  case 753:
#line 2979 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10653 "core/cfg.tab.c"
    break;

  case 754:
#line 2980 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10659 "core/cfg.tab.c"
    break;

  case 755:
#line 2981 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10665 "core/cfg.tab.c"
    break;

  case 756:
#line 2982 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10671 "core/cfg.tab.c"
    break;

  case 757:
#line 2983 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10677 "core/cfg.tab.c"
    break;

  case 758:
#line 2984 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad forward_udp argument"); }
#line 10683 "core/cfg.tab.c"
    break;

  case 759:
#line 2985 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10689 "core/cfg.tab.c"
    break;

  case 760:
#line 2986 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10695 "core/cfg.tab.c"
    break;

  case 761:
#line 2987 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10701 "core/cfg.tab.c"
    break;

  case 762:
#line 2988 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10707 "core/cfg.tab.c"
    break;

  case 763:
#line 2989 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10713 "core/cfg.tab.c"
    break;

  case 764:
#line 2990 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10719 "core/cfg.tab.c"
    break;

  case 765:
#line 2991 "core/cfg.y"
    {(yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 10725 "core/cfg.tab.c"
    break;

  case 766:
#line 2992 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 10731 "core/cfg.tab.c"
    break;

  case 767:
#line 2993 "core/cfg.y"
    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 10737 "core/cfg.tab.c"
    break;

  case 768:
#line 2994 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10743 "core/cfg.tab.c"
    break;

  case 769:
#line 2995 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad forward_tcp argument"); }
#line 10749 "core/cfg.tab.c"
    break;

  case 770:
#line 2996 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10762 "core/cfg.tab.c"
    break;

  case 771:
#line 3004 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10775 "core/cfg.tab.c"
    break;

  case 772:
#line 3012 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10788 "core/cfg.tab.c"
    break;

  case 773:
#line 3020 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10801 "core/cfg.tab.c"
    break;

  case 774:
#line 3028 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10814 "core/cfg.tab.c"
    break;

  case 775:
#line 3036 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
					}
#line 10827 "core/cfg.tab.c"
    break;

  case 776:
#line 3044 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10840 "core/cfg.tab.c"
    break;

  case 777:
#line 3052 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10853 "core/cfg.tab.c"
    break;

  case 778:
#line 3060 "core/cfg.y"
    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 10866 "core/cfg.tab.c"
    break;

  case 779:
#line 3068 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 10872 "core/cfg.tab.c"
    break;

  case 780:
#line 3069 "core/cfg.y"
    { (yyval.action)=0;
									yyerror("bad forward_tls argument"); }
#line 10879 "core/cfg.tab.c"
    break;

  case 781:
#line 3071 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10892 "core/cfg.tab.c"
    break;

  case 782:
#line 3079 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10905 "core/cfg.tab.c"
    break;

  case 783:
#line 3087 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10918 "core/cfg.tab.c"
    break;

  case 784:
#line 3095 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10932 "core/cfg.tab.c"
    break;

  case 785:
#line 3104 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10946 "core/cfg.tab.c"
    break;

  case 786:
#line 3113 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
					}
#line 10960 "core/cfg.tab.c"
    break;

  case 787:
#line 3122 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10973 "core/cfg.tab.c"
    break;

  case 788:
#line 3130 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 10987 "core/cfg.tab.c"
    break;

  case 789:
#line 3139 "core/cfg.y"
    {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 11000 "core/cfg.tab.c"
    break;

  case 790:
#line 3147 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11006 "core/cfg.tab.c"
    break;

  case 791:
#line 3148 "core/cfg.y"
    { (yyval.action)=0;
									yyerror("bad forward_sctp argument"); }
#line 11013 "core/cfg.tab.c"
    break;

  case 792:
#line 3150 "core/cfg.y"
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST,
										(void*)(L_DBG+1), STRING_ST, (yyvsp[-1].strval));
									set_cfg_pos((yyval.action)); }
#line 11021 "core/cfg.tab.c"
    break;

  case 793:
#line 3153 "core/cfg.y"
    {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST, (void*)(yyvsp[-3].intval), STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11027 "core/cfg.tab.c"
    break;

  case 794:
#line 3154 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11033 "core/cfg.tab.c"
    break;

  case 795:
#line 3155 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad log argument"); }
#line 11039 "core/cfg.tab.c"
    break;

  case 796:
#line 3156 "core/cfg.y"
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
													(void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 11051 "core/cfg.tab.c"
    break;

  case 797:
#line 3163 "core/cfg.y"
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 11063 "core/cfg.tab.c"
    break;

  case 798:
#line 3170 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 11069 "core/cfg.tab.c"
    break;

  case 799:
#line 3171 "core/cfg.y"
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 11080 "core/cfg.tab.c"
    break;

  case 800:
#line 3177 "core/cfg.y"
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 11092 "core/cfg.tab.c"
    break;

  case 801:
#line 3184 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 11098 "core/cfg.tab.c"
    break;

  case 802:
#line 3185 "core/cfg.y"
    {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 11109 "core/cfg.tab.c"
    break;

  case 803:
#line 3191 "core/cfg.y"
    {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 11121 "core/cfg.tab.c"
    break;

  case 804:
#line 3198 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 11127 "core/cfg.tab.c"
    break;

  case 805:
#line 3199 "core/cfg.y"
    {
		i_tmp=get_avpflag_no((yyvsp[-1].strval));
		if (i_tmp==0) yyerror("avpflag not declared");
		(yyval.action)=mk_action(AVPFLAG_OPER_T, 3, AVP_ST, (yyvsp[-3].attr), NUMBER_ST, (void*)(long)i_tmp, NUMBER_ST, (void*)(yyvsp[-5].intval));
		set_cfg_pos((yyval.action));
	}
#line 11138 "core/cfg.tab.c"
    break;

  case 806:
#line 3205 "core/cfg.y"
    {
		(yyval.action)=0; yyerror("error parsing flag name");
	}
#line 11146 "core/cfg.tab.c"
    break;

  case 807:
#line 3208 "core/cfg.y"
    {
		(yyval.action)=0; yyerror("error parsing first parameter (avp or string)");
	}
#line 11154 "core/cfg.tab.c"
    break;

  case 808:
#line 3211 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad parameters"); }
#line 11160 "core/cfg.tab.c"
    break;

  case 809:
#line 3212 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 11166 "core/cfg.tab.c"
    break;

  case 810:
#line 3213 "core/cfg.y"
    {(yyval.action)=mk_action(ERROR_T, 2, STRING_ST, (yyvsp[-3].strval), STRING_ST, (yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
	}
#line 11174 "core/cfg.tab.c"
    break;

  case 811:
#line 3216 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11180 "core/cfg.tab.c"
    break;

  case 812:
#line 3217 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad error argument"); }
#line 11186 "core/cfg.tab.c"
    break;

  case 813:
#line 3218 "core/cfg.y"
    {
		if ((yyvsp[-1].rv_expr)) {
			(yyval.action) = mk_action(ROUTE_T, 1, RVE_ST, (void*)(yyvsp[-1].rv_expr));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 11200 "core/cfg.tab.c"
    break;

  case 814:
#line 3227 "core/cfg.y"
    {
		if ((yyvsp[-1].strval)) {
			(yyval.action) = mk_action(ROUTE_T, 1, STRING_ST, (void*)(yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 11214 "core/cfg.tab.c"
    break;

  case 815:
#line 3236 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11220 "core/cfg.tab.c"
    break;

  case 816:
#line 3237 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad route argument"); }
#line 11226 "core/cfg.tab.c"
    break;

  case 817:
#line 3238 "core/cfg.y"
    { (yyval.action)=mk_action(EXEC_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11232 "core/cfg.tab.c"
    break;

  case 818:
#line 3239 "core/cfg.y"
    { (yyval.action)=mk_action(SET_HOST_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11238 "core/cfg.tab.c"
    break;

  case 819:
#line 3240 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11244 "core/cfg.tab.c"
    break;

  case 820:
#line 3241 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11250 "core/cfg.tab.c"
    break;

  case 821:
#line 3242 "core/cfg.y"
    { (yyval.action)=mk_action(PREFIX_T, 1, STRING_ST,  (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11256 "core/cfg.tab.c"
    break;

  case 822:
#line 3243 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11262 "core/cfg.tab.c"
    break;

  case 823:
#line 3244 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11268 "core/cfg.tab.c"
    break;

  case 824:
#line 3245 "core/cfg.y"
    { (yyval.action)=mk_action(STRIP_TAIL_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11274 "core/cfg.tab.c"
    break;

  case 825:
#line 3246 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11280 "core/cfg.tab.c"
    break;

  case 826:
#line 3247 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11286 "core/cfg.tab.c"
    break;

  case 827:
#line 3248 "core/cfg.y"
    { (yyval.action)=mk_action(STRIP_T, 1, NUMBER_ST, (void*) (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11292 "core/cfg.tab.c"
    break;

  case 828:
#line 3249 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11298 "core/cfg.tab.c"
    break;

  case 829:
#line 3250 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11304 "core/cfg.tab.c"
    break;

  case 830:
#line 3251 "core/cfg.y"
    { (yyval.action)=mk_action(SET_USERPHONE_T, 0); set_cfg_pos((yyval.action)); }
#line 11310 "core/cfg.tab.c"
    break;

  case 831:
#line 3252 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11316 "core/cfg.tab.c"
    break;

  case 832:
#line 3253 "core/cfg.y"
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
	}
#line 11325 "core/cfg.tab.c"
    break;

  case 833:
#line 3257 "core/cfg.y"
    {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 0);
			set_cfg_pos((yyval.action));
	}
#line 11334 "core/cfg.tab.c"
    break;

  case 834:
#line 3261 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11340 "core/cfg.tab.c"
    break;

  case 835:
#line 3262 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11346 "core/cfg.tab.c"
    break;

  case 836:
#line 3263 "core/cfg.y"
    { (yyval.action)=mk_action(CLEAR_BRANCHES_T, 0); set_cfg_pos((yyval.action)); }
#line 11352 "core/cfg.tab.c"
    break;

  case 837:
#line 3264 "core/cfg.y"
    { (yyval.action)=mk_action(SET_HOSTPORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11358 "core/cfg.tab.c"
    break;

  case 838:
#line 3265 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11364 "core/cfg.tab.c"
    break;

  case 839:
#line 3266 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11370 "core/cfg.tab.c"
    break;

  case 840:
#line 3267 "core/cfg.y"
    { (yyval.action)=mk_action(SET_HOSTPORTTRANS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11376 "core/cfg.tab.c"
    break;

  case 841:
#line 3268 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11382 "core/cfg.tab.c"
    break;

  case 842:
#line 3269 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11388 "core/cfg.tab.c"
    break;

  case 843:
#line 3270 "core/cfg.y"
    { (yyval.action)=mk_action(SET_PORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11394 "core/cfg.tab.c"
    break;

  case 844:
#line 3271 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11400 "core/cfg.tab.c"
    break;

  case 845:
#line 3272 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11406 "core/cfg.tab.c"
    break;

  case 846:
#line 3273 "core/cfg.y"
    { (yyval.action)=mk_action(SET_USER_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11412 "core/cfg.tab.c"
    break;

  case 847:
#line 3274 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11418 "core/cfg.tab.c"
    break;

  case 848:
#line 3275 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11424 "core/cfg.tab.c"
    break;

  case 849:
#line 3276 "core/cfg.y"
    { (yyval.action)=mk_action(SET_USERPASS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11430 "core/cfg.tab.c"
    break;

  case 850:
#line 3277 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11436 "core/cfg.tab.c"
    break;

  case 851:
#line 3278 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11442 "core/cfg.tab.c"
    break;

  case 852:
#line 3279 "core/cfg.y"
    { (yyval.action)=mk_action(SET_URI_T, 1, STRING_ST,(yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 11448 "core/cfg.tab.c"
    break;

  case 853:
#line 3280 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11454 "core/cfg.tab.c"
    break;

  case 854:
#line 3281 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11460 "core/cfg.tab.c"
    break;

  case 855:
#line 3282 "core/cfg.y"
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11466 "core/cfg.tab.c"
    break;

  case 856:
#line 3283 "core/cfg.y"
    { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 11472 "core/cfg.tab.c"
    break;

  case 857:
#line 3284 "core/cfg.y"
    { (yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11478 "core/cfg.tab.c"
    break;

  case 858:
#line 3285 "core/cfg.y"
    {(yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11484 "core/cfg.tab.c"
    break;

  case 859:
#line 3286 "core/cfg.y"
    { (yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11490 "core/cfg.tab.c"
    break;

  case 860:
#line 3287 "core/cfg.y"
    {(yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 11496 "core/cfg.tab.c"
    break;

  case 861:
#line 3288 "core/cfg.y"
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11509 "core/cfg.tab.c"
    break;

  case 862:
#line 3296 "core/cfg.y"
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11522 "core/cfg.tab.c"
    break;

  case 863:
#line 3304 "core/cfg.y"
    {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 11535 "core/cfg.tab.c"
    break;

  case 864:
#line 3312 "core/cfg.y"
    {(yyval.action)=0; yyerror("bad argument, number expected"); }
#line 11541 "core/cfg.tab.c"
    break;

  case 865:
#line 3314 "core/cfg.y"
    { (yyval.action)=mk_action(UDP_MTU_TRY_PROTO_T, 1, NUMBER_ST, (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11547 "core/cfg.tab.c"
    break;

  case 866:
#line 3316 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, UDP, TCP, TLS or SCTP expected"); }
#line 11553 "core/cfg.tab.c"
    break;

  case 867:
#line 3317 "core/cfg.y"
    {
		(yyval.action)=0;
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			PKG_MEM_CRITICAL;
		} else {
			str_tmp->s=(yyvsp[-1].strval);
			str_tmp->len=(yyvsp[-1].strval)?strlen((yyvsp[-1].strval)):0;
			(yyval.action)=mk_action(SET_ADV_ADDR_T, 1, STR_ST, str_tmp);
			set_cfg_pos((yyval.action));
		}
	}
#line 11569 "core/cfg.tab.c"
    break;

  case 868:
#line 3328 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11575 "core/cfg.tab.c"
    break;

  case 869:
#line 3329 "core/cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11581 "core/cfg.tab.c"
    break;

  case 870:
#line 3330 "core/cfg.y"
    {
		(yyval.action)=0;
		tmp=int2str((yyvsp[-1].intval), &i_tmp);
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			PKG_MEM_CRITICAL;
		} else {
			if ((str_tmp->s=pkg_malloc(i_tmp))==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy(str_tmp->s, tmp, i_tmp);
				str_tmp->len=i_tmp;
				(yyval.action)=mk_action(SET_ADV_PORT_T, 1, STR_ST, str_tmp);
				set_cfg_pos((yyval.action));
			}
		}
	}
#line 11602 "core/cfg.tab.c"
    break;

  case 871:
#line 3346 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 11608 "core/cfg.tab.c"
    break;

  case 872:
#line 3347 "core/cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11614 "core/cfg.tab.c"
    break;

  case 873:
#line 3348 "core/cfg.y"
    {
		(yyval.action)=mk_action(FORCE_SEND_SOCKET_T, 1, SOCKID_ST, (yyvsp[-1].sockid));
		set_cfg_pos((yyval.action));
	}
#line 11623 "core/cfg.tab.c"
    break;

  case 874:
#line 3352 "core/cfg.y"
    {
		(yyval.action)=0; yyerror("bad argument, [proto:]host[:port] expected");
	}
#line 11631 "core/cfg.tab.c"
    break;

  case 875:
#line 3355 "core/cfg.y"
    {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11637 "core/cfg.tab.c"
    break;

  case 876:
#line 3356 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11645 "core/cfg.tab.c"
    break;

  case 877:
#line 3359 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11653 "core/cfg.tab.c"
    break;

  case 878:
#line 3362 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11661 "core/cfg.tab.c"
    break;

  case 879:
#line 3365 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 11669 "core/cfg.tab.c"
    break;

  case 880:
#line 3368 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11677 "core/cfg.tab.c"
    break;

  case 881:
#line 3371 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11685 "core/cfg.tab.c"
    break;

  case 882:
#line 3374 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11693 "core/cfg.tab.c"
    break;

  case 883:
#line 3377 "core/cfg.y"
    {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 11701 "core/cfg.tab.c"
    break;

  case 884:
#line 3380 "core/cfg.y"
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
	}
#line 11709 "core/cfg.tab.c"
    break;

  case 885:
#line 3383 "core/cfg.y"
    {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), RVE_ST, (yyvsp[-1].rv_expr)); set_cfg_pos((yyval.action));
	}
#line 11717 "core/cfg.tab.c"
    break;

  case 886:
#line 3386 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11723 "core/cfg.tab.c"
    break;

  case 887:
#line 3387 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad arguments, string and number expected"); }
#line 11729 "core/cfg.tab.c"
    break;

  case 888:
#line 3388 "core/cfg.y"
    {
		(yyval.action)=mk_action(CFG_RESET_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action));
	}
#line 11737 "core/cfg.tab.c"
    break;

  case 889:
#line 3391 "core/cfg.y"
    { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11743 "core/cfg.tab.c"
    break;

  case 890:
#line 3392 "core/cfg.y"
    { (yyval.action)=0; yyerror("bad arguments, string expected"); }
#line 11749 "core/cfg.tab.c"
    break;

  case 891:
#line 3393 "core/cfg.y"
    {mod_func_action = mk_action(MODULE0_T, 2, MODEXP_ST, NULL, NUMBER_ST,
			0); }
#line 11756 "core/cfg.tab.c"
    break;

  case 892:
#line 3394 "core/cfg.y"
    {
		mod_func_action->val[0].u.data =
			find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, rt);
		if (mod_func_action->val[0].u.data == 0) {
			if (find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, 0) ) {
					LM_ERR("misused command %s\n", (yyvsp[-4].strval));
					yyerror("Command cannot be used in the block\n");
			} else {
				LM_ERR("cfg. parser: failed to find command %s (params %ld)\n",
						(yyvsp[-4].strval), mod_func_action->val[1].u.number);
				yyerror("unknown command, missing loadmodule?\n");
			}
			free_mod_func_action(mod_func_action);
			mod_func_action=0;
		}else{
			if (mod_func_action && mod_f_params_pre_fixup(mod_func_action)<0) {
				/* error messages are printed inside the function */
				free_mod_func_action(mod_func_action);
				mod_func_action = 0;
				YYERROR;
			}
		}
		(yyval.action) = mod_func_action;
		set_cfg_pos((yyval.action));
	}
#line 11786 "core/cfg.tab.c"
    break;

  case 893:
#line 3419 "core/cfg.y"
    { yyerror("'('')' expected (function call)");}
#line 11792 "core/cfg.tab.c"
    break;

  case 895:
#line 3423 "core/cfg.y"
    { }
#line 11798 "core/cfg.tab.c"
    break;

  case 896:
#line 3424 "core/cfg.y"
    {}
#line 11804 "core/cfg.tab.c"
    break;

  case 897:
#line 3427 "core/cfg.y"
    {
		if ((yyvsp[0].rv_expr) && mod_func_action->val[1].u.number < MAX_ACTIONS-2) {
			mod_func_action->val[mod_func_action->val[1].u.number+2].type =
				RVE_ST;
			mod_func_action->val[mod_func_action->val[1].u.number+2].u.data =
				(yyvsp[0].rv_expr);
			mod_func_action->val[1].u.number++;
		} else if ((yyvsp[0].rv_expr)) {
			yyerror("Too many arguments\n");
			YYERROR;
		} else {
			YYERROR;
		}
	}
#line 11823 "core/cfg.tab.c"
    break;

  case 898:
#line 3444 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11832 "core/cfg.tab.c"
    break;

  case 899:
#line 3448 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11841 "core/cfg.tab.c"
    break;

  case 900:
#line 3452 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 11850 "core/cfg.tab.c"
    break;

  case 901:
#line 3456 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11860 "core/cfg.tab.c"
    break;

  case 902:
#line 3461 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11869 "core/cfg.tab.c"
    break;

  case 903:
#line 3465 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11879 "core/cfg.tab.c"
    break;

  case 904:
#line 3470 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11888 "core/cfg.tab.c"
    break;

  case 905:
#line 3474 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 11897 "core/cfg.tab.c"
    break;

  case 906:
#line 3478 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)RETURN_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11906 "core/cfg.tab.c"
    break;

  case 907:
#line 3482 "core/cfg.y"
    {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST, (void*)BREAK_R_F);
		set_cfg_pos((yyval.action));
	}
#line 11915 "core/cfg.tab.c"
    break;


#line 11919 "core/cfg.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 3488 "core/cfg.y"


static void get_cpos(struct cfg_pos* pos)
{
	pos->s_line=startline;
	pos->e_line=line;
	pos->s_col=startcolumn;
	pos->e_col=column-1;
	if(finame==0)
		finame = (cfg_file!=0)?cfg_file:"default";
	pos->fname=finame;
	pos->rname=(routename!=0)?routename:default_routename;
}


static void warn_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_WARN("warning in config file %s, from line %d, column %d to"
					" line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_WARN("warning in config file %s, line %d, column %d: %s\n",
				p->fname, p->s_line, p->s_col, s);
	cfg_warnings++;
}



static void yyerror_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_CRIT("parse error in config file %s, from line %d, column %d"
					" to line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_CRIT("parse error in config file %s, line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, s);
	cfg_errors++;
}



static void warn(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	warn_at(&pos, s);
}



static void yyerror(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	yyerror_at(&pos, s);
}



/** mk_rval_expr_v wrapper.
 *  checks mk_rval_expr_v return value and sets the cfg. pos
 *  (line and column numbers)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr_v)
 */
static struct rval_expr* mk_rve_rval(enum rval_type type, void* v)
{
	struct rval_expr* ret;
	struct cfg_pos pos;

	get_cpos(&pos);
	ret=mk_rval_expr_v(type, v, &pos);
	if (ret==0){
		yyerror("internal error: failed to create rval expr");
		/* YYABORT; */
	}
	return ret;
}


/** mk_rval_expr1 wrapper.
 *  checks mk_rval_expr1 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr1)
 */
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve1==0)
		return 0;
	ret=mk_rval_expr1(op, rve1, &rve1->fpos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		yyerror_at(&rve1->fpos, "bad expression: type mismatch"
					" (%s instead of %s)", rval_type_name(bad_t),
					rval_type_name(exp_t));
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** mk_rval_expr2 wrapper.
 *  checks mk_rval_expr2 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr2)
 */
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	struct cfg_pos pos;

	if ((rve1==0) || (rve2==0))
		return 0;
	bad_rve=0;
	bad_t=0;
	exp_t=0;
	cfg_pos_join(&pos, &rve1->fpos, &rve2->fpos);
	ret=mk_rval_expr2(op, rve1, rve2, &pos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		if (bad_rve)
			yyerror_at(&pos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** check if the expression is an int.
 * if the expression does not evaluate to an int return -1 and
 * log an error.
 * @return 0 success, no warnings; 1 success but warnings; -1 on error */
static int rval_expr_int_check(struct rval_expr *rve)
{
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve==0){
		yyerror("invalid expression");
		return -1;
	}else if (!rve_check_type(&type, rve, &bad_rve, &bad_t ,&exp_t)){
		if (bad_rve)
			yyerror_at(&rve->fpos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		return -1;
	}else if (type!=RV_INT && type!=RV_NONE){
		warn_at(&rve->fpos, "non-int expression (you might want to use"
				" casts)\n");
		return 1;
	}
	return 0;
}


/** warn if the expression is constant.
 * @return 0 on success (no warning), 1 when warning */
static int warn_ct_rve(struct rval_expr *rve, char* name)
{
	if (rve && rve_is_constant(rve)){
		warn_at(&rve->fpos, "constant value in %s%s",
				name?name:"expression", name?"(...)":"");
		return 1;
	}
	return 0;
}


static struct name_lst* mk_name_lst(char* host, int flags)
{
	struct name_lst* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct name_lst));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		l->name=host;
		l->flags=flags;
		l->next=0;
	}
	return l;
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		l->addr_lst=mk_name_lst(host, 0);
		if (l->addr_lst==0){
			pkg_free(l);
			return 0;
		}
		l->flags=0;
		l->port=port;
		l->proto=proto;
		l->next=0;
	}
	return l;
}


static void free_name_lst(struct name_lst* lst)
{
	struct name_lst* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		pkg_free(tmp);
	}
}


static struct socket_id* mk_listen_id2(struct name_lst* addr_l, int proto,
										int port)
{
	struct socket_id* l;
	if (addr_l==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		l->flags=addr_l->flags;
		l->port=port;
		l->proto=proto;
		l->addr_lst=addr_l;
		l->next=0;
	}
	return l;
}


static void free_socket_id(struct socket_id* i)
{
	free_name_lst(i->addr_lst);
	pkg_free(i);
}


static void free_socket_id_lst(struct socket_id* lst)
{
	struct socket_id* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		free_socket_id(tmp);
	}
}


/** create a temporary case statmenet structure.
 *  *err will be filled in case of error (return == 0):
 *   -1 - non constant expression
 *   -2 - expression error (bad type)
 *   -10 - memory allocation error
 */
static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re,
											struct action* a, int* err)
{
	struct case_stms* s;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	enum match_str_type t;

	t=MATCH_UNKNOWN;
	if (ct){
		/* if ct!=0 => case, else if ct==0 is a default */
		if (!rve_is_constant(ct)){
			yyerror_at(&ct->fpos, "non constant expression in case");
			*err=-1;
			return 0;
		}
		if (rve_check_type(&type, ct, &bad_rve, &bad_t, &exp_t)!=1){
			yyerror_at(&ct->fpos, "bad expression: type mismatch:"
							" %s instead of %s at (%d,%d)",
							rval_type_name(bad_t), rval_type_name(exp_t),
							bad_rve->fpos.s_line, bad_rve->fpos.s_col);
			*err=-2;
			return 0;
		}
		if (is_re)
			t=MATCH_RE;
		else if (type==RV_STR)
			t=MATCH_STR;
		else
			t=MATCH_INT;
	}

	s=pkg_malloc(sizeof(*s));
	if (s==0) {
		yyerror("internal error: memory allocation failure");
		*err=-10;
	} else {
		memset(s, 0, sizeof(*s));
		s->ct_rve=ct;
		s->type=t;
		s->actions=a;
		s->next=0;
		s->append=0;
	}
	return s;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_type(struct case_stms* stms)
{
	struct case_stms* c;
	struct case_stms* s;

	for(c=stms; c ; c=c->next){
		if (!c->ct_rve) continue;
		for (s=c->next; s; s=s->next){
			if (!s->ct_rve) continue;
			if ((s->type!=c->type) &&
				!(	(c->type==MATCH_STR || c->type==MATCH_RE) &&
					(s->type==MATCH_STR || s->type==MATCH_RE) ) ){
					yyerror_at(&s->ct_rve->fpos, "type mismatch in case");
					return -1;
			}
		}
	}
	return 0;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_default(struct case_stms* stms)
{
	struct case_stms* c;
	int default_no;

	default_no=0;
	for(c=stms; c ; c=c->next)
		if (c->ct_rve==0) default_no++;
	return (default_no<=1)?0:-1;
}



/** fixes the parameters and the type of a module function call.
 * It is done here instead of fix action, to have quicker feedback
 * on error cases (e.g. passing a non constant to a function with a
 * declared fixup)
 * The rest of the fixup is done inside do_action().
 * @param a - filled module function call (MODULE*_T) action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 * @return 0 on success, -1 on error (it will also print the error msg.).
 *
 */
static int mod_f_params_pre_fixup(struct action* a)
{
	ksr_cmd_export_t* cmd_exp;
	action_u_t* params;
	int param_no;
	struct rval_expr* rve;
	struct rvalue* rv;
	int r;
	str s;

	cmd_exp = a->val[0].u.data;
	param_no = a->val[1].u.number;
	params = &a->val[2];

	switch(cmd_exp->param_no) {
		case 0:
			a->type = MODULE0_T;
			break;
		case 1:
			a->type = MODULE1_T;
			break;
		case 2:
			a->type = MODULE2_T;
			break;
		case 3:
			a->type = MODULE3_T;
			break;
		case 4:
			a->type = MODULE4_T;
			break;
		case 5:
			a->type = MODULE5_T;
			break;
		case 6:
			a->type = MODULE6_T;
			break;
		case VAR_PARAM_NO:
			a->type = MODULEX_T;
			break;
		default:
			yyerror("function %s: bad definition"
					" (invalid number of parameters)", cmd_exp->name);
			return -1;
	}

	if ( cmd_exp->fixup) {
		if (is_fparam_rve_fixup(cmd_exp->fixup))
			/* mark known fparam rve safe fixups */
			cmd_exp->fixup_flags  |= FIXUP_F_FPARAM_RVE;
		else if (!(cmd_exp->fixup_flags & FIXUP_F_FPARAM_RVE) &&
				 cmd_exp->free_fixup == 0) {
			/* v0 or v1 functions that have fixups and no coresp. fixup_free
			   functions, need constant, string params.*/
			for (r=0; r < param_no; r++) {
				rve=params[r].u.data;
				if (!rve_is_constant(rve)) {
					yyerror_at(&rve->fpos, "function %s: parameter %d is not"
								" constant\n", cmd_exp->name, r+1);
					return -1;
				}
				if ((rv = rval_expr_eval(0, 0, rve)) == 0 ||
						rval_get_str(0, 0, &s, rv, 0) < 0 ) {
					/* out of mem or bug ? */
					rval_destroy(rv);
					yyerror_at(&rve->fpos, "function %s: bad parameter %d"
									" expression\n", cmd_exp->name, r+1);
					return -1;
				}
				rval_destroy(rv);
				rve_destroy(rve);
				params[r].type = STRING_ST; /* asciiz */
				params[r].u.string = s.s;
				params[r].u.str.len = s.len; /* not used right now */
			}
		}
	}/* else
		if no fixups are present, the RVEs can be transformed
		into strings at runtime, allowing seamless var. use
		even with old functions.
		Further optimizations -> in fix_actions()
		*/
	return 0;
}



/** frees a filled module function call action structure.
 * @param a - filled module function call action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 */
static void free_mod_func_action(struct action* a)
{
	action_u_t* params;
	int param_no;
	int r;

	param_no = a->val[1].u.number;
	params = &a->val[2];

	for (r=0; r < param_no; r++)
		if (params[r].u.data)
			rve_destroy(params[r].u.data);
	pkg_free(a);
}



/*
int main(int argc, char ** argv)
{
	if (yyparse()!=0)
		fprintf(stderr, "parsing error\n");
}
*/
