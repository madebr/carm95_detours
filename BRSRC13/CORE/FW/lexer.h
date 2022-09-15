#ifndef _LEXER_H_
#define _LEXER_H_

#include "br_types.h"


void lexerError(struct br_lexer *l, char *string);

struct br_lexer* BrLexerAllocate(struct br_lexer_keyword *keywords, int nkeywords);

char BrLexerCommentSet(struct br_lexer *l, char eol_comment);

br_lexer_error_cbfn* BrLexerErrorSet(struct br_lexer *l, br_lexer_error_cbfn *error);

void BrLexerFree(struct br_lexer *l);

void fileGetchar(struct br_lexer_source *source);

br_error BrLexerPushFile(struct br_lexer *l, char *file);

void stringGetchar(struct br_lexer_source *source);

br_error BrLexerPushString(struct br_lexer *l, char *string, char *name);

struct br_lexer_source* BrLexerPop(struct br_lexer *l);

void lexerAdvance(struct br_lexer *l);

void lexerAdvanceDump(struct br_lexer *l);

br_error BrLexerDumpSet(struct br_lexer *l, br_putline_cbfn *putline, void *putline_arg);

void BrLexerTokenError(struct br_lexer *l, br_lexer_token_id t);

void BrLexerPosition(struct br_lexer *l, char *buf, br_size_t buf_size);

br_scalar BrParseFixed(struct br_lexer *l);

br_float BrParseFloat(struct br_lexer *l);

br_int_32 BrParseInteger(struct br_lexer *l);

br_int_32 BrParseVectorFixed(struct br_lexer *l, br_fixed_ls *v, br_int_32 max);

br_int_32 BrParseVectorFloat(struct br_lexer *l, br_float *v, br_int_32 max);

br_int_32 BrParseMatrixFixed(struct br_lexer *l, br_fixed_ls *m, br_int_32 width, br_int_32 max_h);

br_int_32 BrParseMatrixFloat(struct br_lexer *l, br_float *m, br_int_32 width, br_int_32 max_h);

#endif
