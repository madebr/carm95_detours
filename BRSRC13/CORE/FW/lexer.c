#include "lexer.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


void(__cdecl*lexerError)(struct br_lexer *, char *) = (void(__cdecl*)(struct br_lexer *, char *))0x004e6d60;
void lexerError_do_not_use(struct br_lexer *l, char *string) {
    LOG_TRACE("(%p, \"%s\")", l, string);

    (void)l;
    (void)string;

    NOT_IMPLEMENTED();
}

static struct br_lexer *(__cdecl*original_BrLexerAllocate)(struct br_lexer_keyword *, int) = (struct br_lexer *(__cdecl*)(struct br_lexer_keyword *, int))0x004e6d00;
CARM95_HOOK_FUNCTION(original_BrLexerAllocate, BrLexerAllocate)
struct br_lexer* __cdecl BrLexerAllocate(struct br_lexer_keyword *keywords, int nkeywords) {
    struct br_lexer *l;
    LOG_TRACE("(%p, %d)", keywords, nkeywords);

    (void)keywords;
    (void)nkeywords;
    (void)l;

    return original_BrLexerAllocate(keywords, nkeywords);
}

static char(__cdecl*original_BrLexerCommentSet)(struct br_lexer *, char) = (char(__cdecl*)(struct br_lexer *, char))0x004e6d70;
CARM95_HOOK_FUNCTION(original_BrLexerCommentSet, BrLexerCommentSet)
char __cdecl BrLexerCommentSet(struct br_lexer *l, char eol_comment) {
    char old;
    LOG_TRACE("(%p, '%c')", l, eol_comment);

    (void)l;
    (void)eol_comment;
    (void)old;

    return original_BrLexerCommentSet(l, eol_comment);
}

static br_lexer_error_cbfn *(__cdecl*original_BrLexerErrorSet)(struct br_lexer *, br_lexer_error_cbfn *) = (br_lexer_error_cbfn *(__cdecl*)(struct br_lexer *, br_lexer_error_cbfn *))0x004e6d80;
CARM95_HOOK_FUNCTION(original_BrLexerErrorSet, BrLexerErrorSet)
br_lexer_error_cbfn* __cdecl BrLexerErrorSet(struct br_lexer *l, br_lexer_error_cbfn *error) {
    br_lexer_error_cbfn *old;
    LOG_TRACE("(%p, %p)", l, error);

    (void)l;
    (void)error;
    (void)old;

    return original_BrLexerErrorSet(l, error);
}

static void(__cdecl*original_BrLexerFree)(struct br_lexer *) = (void(__cdecl*)(struct br_lexer *))0x004e6db0;
CARM95_HOOK_FUNCTION(original_BrLexerFree, BrLexerFree)
void __cdecl BrLexerFree(struct br_lexer *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    original_BrLexerFree(l);
}

static void(__cdecl*original_fileGetchar)(struct br_lexer_source *) = (void(__cdecl*)(struct br_lexer_source *))0x004e6e60;
CARM95_HOOK_FUNCTION(original_fileGetchar, fileGetchar)
void __cdecl fileGetchar(struct br_lexer_source *source) {
    LOG_TRACE("(%p)", source);

    (void)source;

    original_fileGetchar(source);
}

static br_error(__cdecl*original_BrLexerPushFile)(struct br_lexer *, char *) = (br_error(__cdecl*)(struct br_lexer *, char *))0x004e6dc0;
CARM95_HOOK_FUNCTION(original_BrLexerPushFile, BrLexerPushFile)
br_error __cdecl BrLexerPushFile(struct br_lexer *l, char *file) {
    br_lexer_source *s;
    void *f;
    int mode;
    LOG_TRACE("(%p, \"%s\")", l, file);

    (void)l;
    (void)file;
    (void)s;
    (void)f;
    (void)mode;

    return original_BrLexerPushFile(l, file);
}

static void(__cdecl*original_stringGetchar)(struct br_lexer_source *) = (void(__cdecl*)(struct br_lexer_source *))0x004e6ed0;
CARM95_HOOK_FUNCTION(original_stringGetchar, stringGetchar)
void __cdecl stringGetchar(struct br_lexer_source *source) {
    char *cp;
    LOG_TRACE("(%p)", source);

    (void)source;
    (void)cp;

    original_stringGetchar(source);
}

static br_error(__cdecl*original_BrLexerPushString)(struct br_lexer *, char *, char *) = (br_error(__cdecl*)(struct br_lexer *, char *, char *))0x004e6e80;
CARM95_HOOK_FUNCTION(original_BrLexerPushString, BrLexerPushString)
br_error __cdecl BrLexerPushString(struct br_lexer *l, char *string, char *name) {
    br_lexer_source *s;
    LOG_TRACE("(%p, \"%s\", \"%s\")", l, string, name);

    (void)l;
    (void)string;
    (void)name;
    (void)s;

    return original_BrLexerPushString(l, string, name);
}

static struct br_lexer_source *(__cdecl*original_BrLexerPop)(struct br_lexer *) = (struct br_lexer_source *(__cdecl*)(struct br_lexer *))0x004e6f00;
CARM95_HOOK_FUNCTION(original_BrLexerPop, BrLexerPop)
struct br_lexer_source* __cdecl BrLexerPop(struct br_lexer *l) {
    br_lexer_source *s;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)s;

    return original_BrLexerPop(l);
}

static void(__stdcall*original_lexerAdvance)(struct br_lexer *) = (void(__stdcall*)(struct br_lexer *))0x004e6f20;
CARM95_HOOK_FUNCTION(original_lexerAdvance, lexerAdvance)
void __stdcall lexerAdvance(struct br_lexer *l) {
    int n;
    br_boolean got_point;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)n;
    (void)got_point;

    original_lexerAdvance(l);
}

void lexerAdvanceDump(struct br_lexer *l) {
    char *tname;
    char *tvalue;
    char val[40];
    char tmp[256];
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)tname;
    (void)tvalue;
    (void)val;
    (void)tmp;

    NOT_IMPLEMENTED();
}

br_error(__cdecl*BrLexerDumpSet)(struct br_lexer *, br_putline_cbfn *, void *) = (br_error(__cdecl*)(struct br_lexer *, br_putline_cbfn *, void *))0x004e7290;
br_error BrLexerDumpSet_do_not_use(struct br_lexer *l, br_putline_cbfn *putline, void *putline_arg) {
    LOG_TRACE("(%p, %p, %p)", l, putline, putline_arg);

    (void)l;
    (void)putline;
    (void)putline_arg;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_BrLexerTokenError)(struct br_lexer *, br_lexer_token_id) = (void(__cdecl*)(struct br_lexer *, br_lexer_token_id))0x004e72a0;
CARM95_HOOK_FUNCTION(original_BrLexerTokenError, BrLexerTokenError)
void __cdecl BrLexerTokenError(struct br_lexer *l, br_lexer_token_id t) {
    int i;
    char tmp[256];
    LOG_TRACE("(%p, %d)", l, t);

    (void)l;
    (void)t;
    (void)i;
    (void)tmp;

    original_BrLexerTokenError(l, t);
}

static void(__cdecl*original_BrLexerPosition)(struct br_lexer *, char *, br_size_t) = (void(__cdecl*)(struct br_lexer *, char *, br_size_t))0x004e73e0;
CARM95_HOOK_FUNCTION(original_BrLexerPosition, BrLexerPosition)
void __cdecl BrLexerPosition(struct br_lexer *l, char *buf, br_size_t buf_size) {
    LOG_TRACE("(%p, \"%s\", %u)", l, buf, buf_size);

    (void)l;
    (void)buf;
    (void)buf_size;

    original_BrLexerPosition(l, buf, buf_size);
}

static br_scalar(__cdecl*original_BrParseFixed)(struct br_lexer *) = (br_scalar(__cdecl*)(struct br_lexer *))0x004e7420;
CARM95_HOOK_FUNCTION(original_BrParseFixed, BrParseFixed)
br_scalar __cdecl BrParseFixed(struct br_lexer *l) {
    br_boolean neg;
    br_fixed_ls x;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)x;

    return original_BrParseFixed(l);
}

static br_float(__cdecl*original_BrParseFloat)(struct br_lexer *) = (br_float(__cdecl*)(struct br_lexer *))0x004e74a0;
CARM95_HOOK_FUNCTION(original_BrParseFloat, BrParseFloat)
br_float __cdecl BrParseFloat(struct br_lexer *l) {
    br_boolean neg;
    br_float f;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)f;

    return original_BrParseFloat(l);
}

static br_int_32(__cdecl*original_BrParseInteger)(struct br_lexer *) = (br_int_32(__cdecl*)(struct br_lexer *))0x004e7520;
CARM95_HOOK_FUNCTION(original_BrParseInteger, BrParseInteger)
br_int_32 __cdecl BrParseInteger(struct br_lexer *l) {
    br_boolean neg;
    br_int_32 i;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)i;

    return original_BrParseInteger(l);
}

static br_int_32(__cdecl*original_BrParseVectorFixed)(struct br_lexer *, br_fixed_ls *, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_fixed_ls *, br_int_32))0x004e7580;
CARM95_HOOK_FUNCTION(original_BrParseVectorFixed, BrParseVectorFixed)
br_int_32 __cdecl BrParseVectorFixed(struct br_lexer *l, br_fixed_ls *v, br_int_32 max) {
    int n;
    LOG_TRACE("(%p, %p, %d)", l, v, max);

    (void)l;
    (void)v;
    (void)max;
    (void)n;

    return original_BrParseVectorFixed(l, v, max);
}

static br_int_32(__cdecl*original_BrParseVectorFloat)(struct br_lexer *, br_float *, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_float *, br_int_32))0x004e7610;
CARM95_HOOK_FUNCTION(original_BrParseVectorFloat, BrParseVectorFloat)
br_int_32 __cdecl BrParseVectorFloat(struct br_lexer *l, br_float *v, br_int_32 max) {
    int n;
    LOG_TRACE("(%p, %p, %d)", l, v, max);

    (void)l;
    (void)v;
    (void)max;
    (void)n;

    return original_BrParseVectorFloat(l, v, max);
}

static br_int_32(__cdecl*original_BrParseMatrixFixed)(struct br_lexer *, br_fixed_ls *, br_int_32, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_fixed_ls *, br_int_32, br_int_32))0x004e7730;
CARM95_HOOK_FUNCTION(original_BrParseMatrixFixed, BrParseMatrixFixed)
br_int_32 __cdecl BrParseMatrixFixed(struct br_lexer *l, br_fixed_ls *m, br_int_32 width, br_int_32 max_h) {
    int n;
    LOG_TRACE("(%p, %p, %d, %d)", l, m, width, max_h);

    (void)l;
    (void)m;
    (void)width;
    (void)max_h;
    (void)n;

    return original_BrParseMatrixFixed(l, m, width, max_h);
}

static br_int_32(__cdecl*original_BrParseMatrixFloat)(struct br_lexer *, br_float *, br_int_32, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_float *, br_int_32, br_int_32))0x004e77c0;
CARM95_HOOK_FUNCTION(original_BrParseMatrixFloat, BrParseMatrixFloat)
br_int_32 __cdecl BrParseMatrixFloat(struct br_lexer *l, br_float *m, br_int_32 width, br_int_32 max_h) {
    int n;
    LOG_TRACE("(%p, %p, %d, %d)", l, m, width, max_h);

    (void)l;
    (void)m;
    (void)width;
    (void)max_h;
    (void)n;

    return original_BrParseMatrixFloat(l, m, width, max_h);
}

