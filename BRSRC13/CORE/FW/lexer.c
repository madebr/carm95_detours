#include "lexer.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_lexerError = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(lexerError, function_hook_state_lexerError)
void(__cdecl*lexerError)(struct br_lexer *, char *) = (void(__cdecl*)(struct br_lexer *, char *))0x004e6d60;
void lexerError_do_not_use(struct br_lexer *l, char *string) {
    LOG_TRACE("(%p, \"%s\")", l, string);

    (void)l;
    (void)string;

    if (function_hook_state_lexerError == HOOK_ENABLED) {
        assert(0 && "lexerError_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrLexerAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerAllocate, function_hook_state_BrLexerAllocate)
static struct br_lexer *(__cdecl*original_BrLexerAllocate)(struct br_lexer_keyword *, int) = (struct br_lexer *(__cdecl*)(struct br_lexer_keyword *, int))0x004e6d00;
CARM95_HOOK_FUNCTION(original_BrLexerAllocate, BrLexerAllocate)
struct br_lexer* __cdecl BrLexerAllocate(struct br_lexer_keyword *keywords, int nkeywords) {
    struct br_lexer *l;
    LOG_TRACE("(%p, %d)", keywords, nkeywords);

    (void)keywords;
    (void)nkeywords;
    (void)l;

    if (function_hook_state_BrLexerAllocate == HOOK_ENABLED) {
        assert(0 && "BrLexerAllocate not implemented.");
        abort();
    } else {
        return original_BrLexerAllocate(keywords, nkeywords);
    }
}

function_hook_state_t function_hook_state_BrLexerCommentSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerCommentSet, function_hook_state_BrLexerCommentSet)
static char(__cdecl*original_BrLexerCommentSet)(struct br_lexer *, char) = (char(__cdecl*)(struct br_lexer *, char))0x004e6d70;
CARM95_HOOK_FUNCTION(original_BrLexerCommentSet, BrLexerCommentSet)
char __cdecl BrLexerCommentSet(struct br_lexer *l, char eol_comment) {
    char old;
    LOG_TRACE("(%p, '%c')", l, eol_comment);

    (void)l;
    (void)eol_comment;
    (void)old;

    if (function_hook_state_BrLexerCommentSet == HOOK_ENABLED) {
        assert(0 && "BrLexerCommentSet not implemented.");
        abort();
    } else {
        return original_BrLexerCommentSet(l, eol_comment);
    }
}

function_hook_state_t function_hook_state_BrLexerErrorSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerErrorSet, function_hook_state_BrLexerErrorSet)
static br_lexer_error_cbfn *(__cdecl*original_BrLexerErrorSet)(struct br_lexer *, br_lexer_error_cbfn *) = (br_lexer_error_cbfn *(__cdecl*)(struct br_lexer *, br_lexer_error_cbfn *))0x004e6d80;
CARM95_HOOK_FUNCTION(original_BrLexerErrorSet, BrLexerErrorSet)
br_lexer_error_cbfn* __cdecl BrLexerErrorSet(struct br_lexer *l, br_lexer_error_cbfn *error) {
    br_lexer_error_cbfn *old;
    LOG_TRACE("(%p, %p)", l, error);

    (void)l;
    (void)error;
    (void)old;

    if (function_hook_state_BrLexerErrorSet == HOOK_ENABLED) {
        assert(0 && "BrLexerErrorSet not implemented.");
        abort();
    } else {
        return original_BrLexerErrorSet(l, error);
    }
}

function_hook_state_t function_hook_state_BrLexerFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerFree, function_hook_state_BrLexerFree)
static void(__cdecl*original_BrLexerFree)(struct br_lexer *) = (void(__cdecl*)(struct br_lexer *))0x004e6db0;
CARM95_HOOK_FUNCTION(original_BrLexerFree, BrLexerFree)
void __cdecl BrLexerFree(struct br_lexer *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    if (function_hook_state_BrLexerFree == HOOK_ENABLED) {
        assert(0 && "BrLexerFree not implemented.");
        abort();
    } else {
        original_BrLexerFree(l);
    }
}

function_hook_state_t function_hook_state_fileGetchar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(fileGetchar, function_hook_state_fileGetchar)
static void(__cdecl*original_fileGetchar)(struct br_lexer_source *) = (void(__cdecl*)(struct br_lexer_source *))0x004e6e60;
CARM95_HOOK_FUNCTION(original_fileGetchar, fileGetchar)
void __cdecl fileGetchar(struct br_lexer_source *source) {
    LOG_TRACE("(%p)", source);

    (void)source;

    if (function_hook_state_fileGetchar == HOOK_ENABLED) {
        assert(0 && "fileGetchar not implemented.");
        abort();
    } else {
        original_fileGetchar(source);
    }
}

function_hook_state_t function_hook_state_BrLexerPushFile = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerPushFile, function_hook_state_BrLexerPushFile)
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

    if (function_hook_state_BrLexerPushFile == HOOK_ENABLED) {
        assert(0 && "BrLexerPushFile not implemented.");
        abort();
    } else {
        return original_BrLexerPushFile(l, file);
    }
}

function_hook_state_t function_hook_state_stringGetchar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(stringGetchar, function_hook_state_stringGetchar)
static void(__cdecl*original_stringGetchar)(struct br_lexer_source *) = (void(__cdecl*)(struct br_lexer_source *))0x004e6ed0;
CARM95_HOOK_FUNCTION(original_stringGetchar, stringGetchar)
void __cdecl stringGetchar(struct br_lexer_source *source) {
    char *cp;
    LOG_TRACE("(%p)", source);

    (void)source;
    (void)cp;

    if (function_hook_state_stringGetchar == HOOK_ENABLED) {
        assert(0 && "stringGetchar not implemented.");
        abort();
    } else {
        original_stringGetchar(source);
    }
}

function_hook_state_t function_hook_state_BrLexerPushString = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerPushString, function_hook_state_BrLexerPushString)
static br_error(__cdecl*original_BrLexerPushString)(struct br_lexer *, char *, char *) = (br_error(__cdecl*)(struct br_lexer *, char *, char *))0x004e6e80;
CARM95_HOOK_FUNCTION(original_BrLexerPushString, BrLexerPushString)
br_error __cdecl BrLexerPushString(struct br_lexer *l, char *string, char *name) {
    br_lexer_source *s;
    LOG_TRACE("(%p, \"%s\", \"%s\")", l, string, name);

    (void)l;
    (void)string;
    (void)name;
    (void)s;

    if (function_hook_state_BrLexerPushString == HOOK_ENABLED) {
        assert(0 && "BrLexerPushString not implemented.");
        abort();
    } else {
        return original_BrLexerPushString(l, string, name);
    }
}

function_hook_state_t function_hook_state_BrLexerPop = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerPop, function_hook_state_BrLexerPop)
static struct br_lexer_source *(__cdecl*original_BrLexerPop)(struct br_lexer *) = (struct br_lexer_source *(__cdecl*)(struct br_lexer *))0x004e6f00;
CARM95_HOOK_FUNCTION(original_BrLexerPop, BrLexerPop)
struct br_lexer_source* __cdecl BrLexerPop(struct br_lexer *l) {
    br_lexer_source *s;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)s;

    if (function_hook_state_BrLexerPop == HOOK_ENABLED) {
        assert(0 && "BrLexerPop not implemented.");
        abort();
    } else {
        return original_BrLexerPop(l);
    }
}

function_hook_state_t function_hook_state_lexerAdvance = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(lexerAdvance, function_hook_state_lexerAdvance)
static void(__stdcall*original_lexerAdvance)(struct br_lexer *) = (void(__stdcall*)(struct br_lexer *))0x004e6f20;
CARM95_HOOK_FUNCTION(original_lexerAdvance, lexerAdvance)
void __stdcall lexerAdvance(struct br_lexer *l) {
    int n;
    br_boolean got_point;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)n;
    (void)got_point;

    if (function_hook_state_lexerAdvance == HOOK_ENABLED) {
        assert(0 && "lexerAdvance not implemented.");
        abort();
    } else {
        original_lexerAdvance(l);
    }
}

function_hook_state_t function_hook_state_lexerAdvanceDump = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(lexerAdvanceDump, function_hook_state_lexerAdvanceDump)
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

    if (function_hook_state_lexerAdvanceDump == HOOK_ENABLED) {
        assert(0 && "lexerAdvanceDump not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrLexerDumpSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerDumpSet, function_hook_state_BrLexerDumpSet)
br_error(__cdecl*BrLexerDumpSet)(struct br_lexer *, br_putline_cbfn *, void *) = (br_error(__cdecl*)(struct br_lexer *, br_putline_cbfn *, void *))0x004e7290;
br_error BrLexerDumpSet_do_not_use(struct br_lexer *l, br_putline_cbfn *putline, void *putline_arg) {
    LOG_TRACE("(%p, %p, %p)", l, putline, putline_arg);

    (void)l;
    (void)putline;
    (void)putline_arg;

    if (function_hook_state_BrLexerDumpSet == HOOK_ENABLED) {
        assert(0 && "BrLexerDumpSet_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrLexerTokenError = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerTokenError, function_hook_state_BrLexerTokenError)
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

    if (function_hook_state_BrLexerTokenError == HOOK_ENABLED) {
        assert(0 && "BrLexerTokenError not implemented.");
        abort();
    } else {
        original_BrLexerTokenError(l, t);
    }
}

function_hook_state_t function_hook_state_BrLexerPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLexerPosition, function_hook_state_BrLexerPosition)
static void(__cdecl*original_BrLexerPosition)(struct br_lexer *, char *, br_size_t) = (void(__cdecl*)(struct br_lexer *, char *, br_size_t))0x004e73e0;
CARM95_HOOK_FUNCTION(original_BrLexerPosition, BrLexerPosition)
void __cdecl BrLexerPosition(struct br_lexer *l, char *buf, br_size_t buf_size) {
    LOG_TRACE("(%p, \"%s\", %u)", l, buf, buf_size);

    (void)l;
    (void)buf;
    (void)buf_size;

    if (function_hook_state_BrLexerPosition == HOOK_ENABLED) {
        assert(0 && "BrLexerPosition not implemented.");
        abort();
    } else {
        original_BrLexerPosition(l, buf, buf_size);
    }
}

function_hook_state_t function_hook_state_BrParseFixed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseFixed, function_hook_state_BrParseFixed)
static br_scalar(__cdecl*original_BrParseFixed)(struct br_lexer *) = (br_scalar(__cdecl*)(struct br_lexer *))0x004e7420;
CARM95_HOOK_FUNCTION(original_BrParseFixed, BrParseFixed)
br_scalar __cdecl BrParseFixed(struct br_lexer *l) {
    br_boolean neg;
    br_fixed_ls x;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)x;

    if (function_hook_state_BrParseFixed == HOOK_ENABLED) {
        assert(0 && "BrParseFixed not implemented.");
        abort();
    } else {
        return original_BrParseFixed(l);
    }
}

function_hook_state_t function_hook_state_BrParseFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseFloat, function_hook_state_BrParseFloat)
static br_float(__cdecl*original_BrParseFloat)(struct br_lexer *) = (br_float(__cdecl*)(struct br_lexer *))0x004e74a0;
CARM95_HOOK_FUNCTION(original_BrParseFloat, BrParseFloat)
br_float __cdecl BrParseFloat(struct br_lexer *l) {
    br_boolean neg;
    br_float f;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)f;

    if (function_hook_state_BrParseFloat == HOOK_ENABLED) {
        assert(0 && "BrParseFloat not implemented.");
        abort();
    } else {
        return original_BrParseFloat(l);
    }
}

function_hook_state_t function_hook_state_BrParseInteger = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseInteger, function_hook_state_BrParseInteger)
static br_int_32(__cdecl*original_BrParseInteger)(struct br_lexer *) = (br_int_32(__cdecl*)(struct br_lexer *))0x004e7520;
CARM95_HOOK_FUNCTION(original_BrParseInteger, BrParseInteger)
br_int_32 __cdecl BrParseInteger(struct br_lexer *l) {
    br_boolean neg;
    br_int_32 i;
    LOG_TRACE("(%p)", l);

    (void)l;
    (void)neg;
    (void)i;

    if (function_hook_state_BrParseInteger == HOOK_ENABLED) {
        assert(0 && "BrParseInteger not implemented.");
        abort();
    } else {
        return original_BrParseInteger(l);
    }
}

function_hook_state_t function_hook_state_BrParseVectorFixed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseVectorFixed, function_hook_state_BrParseVectorFixed)
static br_int_32(__cdecl*original_BrParseVectorFixed)(struct br_lexer *, br_fixed_ls *, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_fixed_ls *, br_int_32))0x004e7580;
CARM95_HOOK_FUNCTION(original_BrParseVectorFixed, BrParseVectorFixed)
br_int_32 __cdecl BrParseVectorFixed(struct br_lexer *l, br_fixed_ls *v, br_int_32 max) {
    int n;
    LOG_TRACE("(%p, %p, %d)", l, v, max);

    (void)l;
    (void)v;
    (void)max;
    (void)n;

    if (function_hook_state_BrParseVectorFixed == HOOK_ENABLED) {
        assert(0 && "BrParseVectorFixed not implemented.");
        abort();
    } else {
        return original_BrParseVectorFixed(l, v, max);
    }
}

function_hook_state_t function_hook_state_BrParseVectorFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseVectorFloat, function_hook_state_BrParseVectorFloat)
static br_int_32(__cdecl*original_BrParseVectorFloat)(struct br_lexer *, br_float *, br_int_32) = (br_int_32(__cdecl*)(struct br_lexer *, br_float *, br_int_32))0x004e7610;
CARM95_HOOK_FUNCTION(original_BrParseVectorFloat, BrParseVectorFloat)
br_int_32 __cdecl BrParseVectorFloat(struct br_lexer *l, br_float *v, br_int_32 max) {
    int n;
    LOG_TRACE("(%p, %p, %d)", l, v, max);

    (void)l;
    (void)v;
    (void)max;
    (void)n;

    if (function_hook_state_BrParseVectorFloat == HOOK_ENABLED) {
        assert(0 && "BrParseVectorFloat not implemented.");
        abort();
    } else {
        return original_BrParseVectorFloat(l, v, max);
    }
}

function_hook_state_t function_hook_state_BrParseMatrixFixed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseMatrixFixed, function_hook_state_BrParseMatrixFixed)
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

    if (function_hook_state_BrParseMatrixFixed == HOOK_ENABLED) {
        assert(0 && "BrParseMatrixFixed not implemented.");
        abort();
    } else {
        return original_BrParseMatrixFixed(l, m, width, max_h);
    }
}

function_hook_state_t function_hook_state_BrParseMatrixFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrParseMatrixFloat, function_hook_state_BrParseMatrixFloat)
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

    if (function_hook_state_BrParseMatrixFloat == HOOK_ENABLED) {
        assert(0 && "BrParseMatrixFloat not implemented.");
        abort();
    } else {
        return original_BrParseMatrixFloat(l, m, width, max_h);
    }
}

