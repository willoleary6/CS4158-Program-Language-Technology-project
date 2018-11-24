#define VARIABLE 257
#define INTEGER 258
#define NUMSIZE 259
#define BEGINING 260
#define BODY 261
#define END 262
#define MOVE 263
#define TO 264
#define ADD 265
#define INPUT 266
#define PRINT 267
#define TEXT 268
#define SEMICOLON 269
#define TERMINATOR 270
#define INVALID 271
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
        char *id; 
        int size;
    } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
