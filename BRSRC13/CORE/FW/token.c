#include "token.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_token_entry(* hookvar_predefinedTokens )[457] = (void*)0x005289c0;
struct token_type(* hookvar_tokenTypes )[37] = (void*)0x0052b210;

static void(*original_BrTokenBegin)() = (void(*)())0x004e6980;
CARM95_HOOK_FUNCTION(original_BrTokenBegin, BrTokenBegin)
void BrTokenBegin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_BrTokenBegin();
}

static br_token(*original_BrTokenCreate)(char *, br_token, ...) = (br_token(*)(char *, br_token, ...))0x004e69c0;
CARM95_HOOK_FUNCTION(original_BrTokenCreate, BrTokenCreate)
br_token BrTokenCreate(char *identifier, br_token type) {
    br_token_entry *te;
    int i;
    int l;
    LOG_TRACE("(\"%s\", %d)", identifier, type);

    (void)identifier;
    (void)type;
    (void)te;
    (void)i;
    (void)l;

    return original_BrTokenCreate(identifier, type);
}

static char *(*original_BrTokenIdentifier)(br_token, ...) = (char *(*)(br_token, ...))0x004e6b30;
CARM95_HOOK_FUNCTION(original_BrTokenIdentifier, BrTokenIdentifier)
char* BrTokenIdentifier(br_token t) {
    br_token_entry *te;
    LOG_TRACE("(%d)", t);

    (void)t;
    (void)te;

    return original_BrTokenIdentifier(t);
}

static br_token(*original_BrTokenType)(br_token, ...) = (br_token(*)(br_token, ...))0x004e6b60;
CARM95_HOOK_FUNCTION(original_BrTokenType, BrTokenType)
br_token BrTokenType(br_token t) {
    br_token_entry *te;
    LOG_TRACE("(%d)", t);

    (void)t;
    (void)te;

    return original_BrTokenType(t);
}

static br_int_32(*original_BrTokenCount)(char *, ...) = (br_int_32(*)(char *, ...))0x004e6b90;
CARM95_HOOK_FUNCTION(original_BrTokenCount, BrTokenCount)
br_int_32 BrTokenCount(char *pattern) {
    br_token_entry *te;
    int n;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)te;
    (void)n;

    return original_BrTokenCount(pattern);
}

static br_token(*original_BrTokenFind)(char *, ...) = (br_token(*)(char *, ...))0x004e6be0;
CARM95_HOOK_FUNCTION(original_BrTokenFind, BrTokenFind)
br_token BrTokenFind(char *pattern) {
    br_token_entry *te;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)te;

    return original_BrTokenFind(pattern);
}

static br_int_32(*original_BrTokenFindMany)(char *, br_token *, br_int_32, ...) = (br_int_32(*)(char *, br_token *, br_int_32, ...))0x004e6c20;
CARM95_HOOK_FUNCTION(original_BrTokenFindMany, BrTokenFindMany)
br_int_32 BrTokenFindMany(char *pattern, br_token *tokens, br_int_32 max_tokens) {
    br_token_entry *te;
    int n;
    LOG_TRACE("(\"%s\", %p, %d)", pattern, tokens, max_tokens);

    (void)pattern;
    (void)tokens;
    (void)max_tokens;
    (void)te;
    (void)n;

    return original_BrTokenFindMany(pattern, tokens, max_tokens);
}

static br_token(*original_BrTokenFindType)(br_token *, char *, br_token *, br_int_32, ...) = (br_token(*)(br_token *, char *, br_token *, br_int_32, ...))0x004e6c70;
CARM95_HOOK_FUNCTION(original_BrTokenFindType, BrTokenFindType)
br_token BrTokenFindType(br_token *ptype, char *base, br_token *types, br_int_32 ntypes) {
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

    return original_BrTokenFindType(ptype, base, types, ntypes);
}

