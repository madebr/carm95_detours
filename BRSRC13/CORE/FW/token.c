#include "token.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_token_entry(* hookvar_predefinedTokens )[457] = (void*)0x005289c0;
struct token_type(* hookvar_tokenTypes )[37] = (void*)0x0052b210;

function_hook_state_t function_hook_state_BrTokenBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenBegin)
static void(__cdecl*original_BrTokenBegin)() = (void(__cdecl*)())0x004e6980;
CARM95_HOOK_FUNCTION(original_BrTokenBegin, BrTokenBegin)
void __cdecl BrTokenBegin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_BrTokenBegin == HOOK_ENABLED) {
        assert(0 && "BrTokenBegin not implemented.");
        abort();
    } else {
        original_BrTokenBegin();
    }
}

function_hook_state_t function_hook_state_BrTokenCreate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenCreate)
static br_token(__cdecl*original_BrTokenCreate)(char *, br_token) = (br_token(__cdecl*)(char *, br_token))0x004e69c0;
CARM95_HOOK_FUNCTION(original_BrTokenCreate, BrTokenCreate)
br_token __cdecl BrTokenCreate(char *identifier, br_token type) {
    br_token_entry *te;
    int i;
    int l;
    LOG_TRACE("(\"%s\", %d)", identifier, type);

    (void)identifier;
    (void)type;
    (void)te;
    (void)i;
    (void)l;

    if (function_hook_state_BrTokenCreate == HOOK_ENABLED) {
        assert(0 && "BrTokenCreate not implemented.");
        abort();
    } else {
        return original_BrTokenCreate(identifier, type);
    }
}

function_hook_state_t function_hook_state_BrTokenIdentifier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenIdentifier)
static char *(__cdecl*original_BrTokenIdentifier)(br_token) = (char *(__cdecl*)(br_token))0x004e6b30;
CARM95_HOOK_FUNCTION(original_BrTokenIdentifier, BrTokenIdentifier)
char* __cdecl BrTokenIdentifier(br_token t) {
    br_token_entry *te;
    LOG_TRACE("(%d)", t);

    (void)t;
    (void)te;

    if (function_hook_state_BrTokenIdentifier == HOOK_ENABLED) {
        assert(0 && "BrTokenIdentifier not implemented.");
        abort();
    } else {
        return original_BrTokenIdentifier(t);
    }
}

function_hook_state_t function_hook_state_BrTokenType = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenType)
static br_token(__cdecl*original_BrTokenType)(br_token) = (br_token(__cdecl*)(br_token))0x004e6b60;
CARM95_HOOK_FUNCTION(original_BrTokenType, BrTokenType)
br_token __cdecl BrTokenType(br_token t) {
    br_token_entry *te;
    LOG_TRACE("(%d)", t);

    (void)t;
    (void)te;

    if (function_hook_state_BrTokenType == HOOK_ENABLED) {
        assert(0 && "BrTokenType not implemented.");
        abort();
    } else {
        return original_BrTokenType(t);
    }
}

function_hook_state_t function_hook_state_BrTokenCount = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenCount)
static br_int_32(__cdecl*original_BrTokenCount)(char *) = (br_int_32(__cdecl*)(char *))0x004e6b90;
CARM95_HOOK_FUNCTION(original_BrTokenCount, BrTokenCount)
br_int_32 __cdecl BrTokenCount(char *pattern) {
    br_token_entry *te;
    int n;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)te;
    (void)n;

    if (function_hook_state_BrTokenCount == HOOK_ENABLED) {
        assert(0 && "BrTokenCount not implemented.");
        abort();
    } else {
        return original_BrTokenCount(pattern);
    }
}

function_hook_state_t function_hook_state_BrTokenFind = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenFind)
static br_token(__cdecl*original_BrTokenFind)(char *) = (br_token(__cdecl*)(char *))0x004e6be0;
CARM95_HOOK_FUNCTION(original_BrTokenFind, BrTokenFind)
br_token __cdecl BrTokenFind(char *pattern) {
    br_token_entry *te;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)te;

    if (function_hook_state_BrTokenFind == HOOK_ENABLED) {
        assert(0 && "BrTokenFind not implemented.");
        abort();
    } else {
        return original_BrTokenFind(pattern);
    }
}

function_hook_state_t function_hook_state_BrTokenFindMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenFindMany)
static br_int_32(__cdecl*original_BrTokenFindMany)(char *, br_token *, br_int_32) = (br_int_32(__cdecl*)(char *, br_token *, br_int_32))0x004e6c20;
CARM95_HOOK_FUNCTION(original_BrTokenFindMany, BrTokenFindMany)
br_int_32 __cdecl BrTokenFindMany(char *pattern, br_token *tokens, br_int_32 max_tokens) {
    br_token_entry *te;
    int n;
    LOG_TRACE("(\"%s\", %p, %d)", pattern, tokens, max_tokens);

    (void)pattern;
    (void)tokens;
    (void)max_tokens;
    (void)te;
    (void)n;

    if (function_hook_state_BrTokenFindMany == HOOK_ENABLED) {
        assert(0 && "BrTokenFindMany not implemented.");
        abort();
    } else {
        return original_BrTokenFindMany(pattern, tokens, max_tokens);
    }
}

function_hook_state_t function_hook_state_BrTokenFindType = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTokenFindType)
static br_token(__stdcall*original_BrTokenFindType)(br_token *, char *, br_token *, br_int_32) = (br_token(__stdcall*)(br_token *, char *, br_token *, br_int_32))0x004e6c70;
CARM95_HOOK_FUNCTION(original_BrTokenFindType, BrTokenFindType)
br_token __stdcall BrTokenFindType(br_token *ptype, char *base, br_token *types, br_int_32 ntypes) {
    br_token_entry *te;
    int l;
    int t;
    LOG_TRACE("(%p, \"%s\", %p, %d)", ptype, base, types, ntypes);

    (void)ptype;
    (void)base;
    (void)types;
    (void)ntypes;
    (void)te;
    (void)l;
    (void)t;

    if (function_hook_state_BrTokenFindType == HOOK_ENABLED) {
        assert(0 && "BrTokenFindType not implemented.");
        abort();
    } else {
        return original_BrTokenFindType(ptype, base, types, ntypes);
    }
}

