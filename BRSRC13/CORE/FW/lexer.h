#ifndef _LEXER_H_
#define _LEXER_H_

#include "br_types.h"


#if 0
void lexerError_do_not_use(struct br_lexer *l, char *string);
#endif

struct br_lexer* __cdecl BrLexerAllocate(struct br_lexer_keyword *keywords, int nkeywords);

char __cdecl BrLexerCommentSet(struct br_lexer *l, char eol_comment);

br_lexer_error_cbfn* __cdecl BrLexerErrorSet(struct br_lexer *l, br_lexer_error_cbfn *error);

void __cdecl BrLexerFree(struct br_lexer *l);

void __cdecl fileGetchar(struct br_lexer_source *source);

br_error __cdecl BrLexerPushFile(struct br_lexer *l, char *file);

void __cdecl stringGetchar(struct br_lexer_source *source);

br_error __cdecl BrLexerPushString(struct br_lexer *l, char *string, char *name);

struct br_lexer_source* __cdecl BrLexerPop(struct br_lexer *l);

void __stdcall lexerAdvance(struct br_lexer *l);

void lexerAdvanceDump(struct br_lexer *l);

#if 0
br_error BrLexerDumpSet_do_not_use(struct br_lexer *l, br_putline_cbfn *putline, void *putline_arg);
#endif

void __cdecl BrLexerTokenError(struct br_lexer *l, br_lexer_token_id t);

void __cdecl BrLexerPosition(struct br_lexer *l, char *buf, br_size_t buf_size);

br_scalar __cdecl BrParseFixed(struct br_lexer *l);

br_float __cdecl BrParseFloat(struct br_lexer *l);

br_int_32 __cdecl BrParseInteger(struct br_lexer *l);

br_int_32 __cdecl BrParseVectorFixed(struct br_lexer *l, br_fixed_ls *v, br_int_32 max);

br_int_32 __cdecl BrParseVectorFloat(struct br_lexer *l, br_float *v, br_int_32 max);

br_int_32 __cdecl BrParseMatrixFixed(struct br_lexer *l, br_fixed_ls *m, br_int_32 width, br_int_32 max_h);

br_int_32 __cdecl BrParseMatrixFloat(struct br_lexer *l, br_float *m, br_int_32 width, br_int_32 max_h);

#endif
