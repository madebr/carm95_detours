#include "resreg.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrResClassAdd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassAdd)
static br_resource_class *(__cdecl*original_BrResClassAdd)(br_resource_class *) = (br_resource_class *(__cdecl*)(br_resource_class *))0x004dfe00;
CARM95_HOOK_FUNCTION(original_BrResClassAdd, BrResClassAdd)
br_resource_class* __cdecl BrResClassAdd(br_resource_class *rclass) {
    br_resource_class *r;
    LOG_TRACE("(%p)", rclass);

    (void)rclass;
    (void)r;

    if (function_hook_state_BrResClassAdd == HOOK_ENABLED) {
        assert(0 && "BrResClassAdd not implemented.");
        abort();
    } else {
        return original_BrResClassAdd(rclass);
    }
}

function_hook_state_t function_hook_state_BrResClassRemove = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassRemove)
static br_resource_class *(__cdecl*original_BrResClassRemove)(br_resource_class *) = (br_resource_class *(__cdecl*)(br_resource_class *))0x004dfe30;
CARM95_HOOK_FUNCTION(original_BrResClassRemove, BrResClassRemove)
br_resource_class* __cdecl BrResClassRemove(br_resource_class *rclass) {
    br_resource_class *r;
    LOG_TRACE("(%p)", rclass);

    (void)rclass;
    (void)r;

    if (function_hook_state_BrResClassRemove == HOOK_ENABLED) {
        assert(0 && "BrResClassRemove not implemented.");
        abort();
    } else {
        return original_BrResClassRemove(rclass);
    }
}

function_hook_state_t function_hook_state_BrResClassFind = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassFind)
static br_resource_class *(__cdecl*original_BrResClassFind)(char *) = (br_resource_class *(__cdecl*)(char *))0x004dfe60;
CARM95_HOOK_FUNCTION(original_BrResClassFind, BrResClassFind)
br_resource_class* __cdecl BrResClassFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    if (function_hook_state_BrResClassFind == HOOK_ENABLED) {
        assert(0 && "BrResClassFind not implemented.");
        abort();
    } else {
        return original_BrResClassFind(pattern);
    }
}

function_hook_state_t function_hook_state_BrResClassFindHook = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassFindHook)
static br_resclass_find_cbfn *(__cdecl*original_BrResClassFindHook)(br_resclass_find_cbfn *) = (br_resclass_find_cbfn *(__cdecl*)(br_resclass_find_cbfn *))0x004dfe70;
CARM95_HOOK_FUNCTION(original_BrResClassFindHook, BrResClassFindHook)
br_resclass_find_cbfn* __cdecl BrResClassFindHook(br_resclass_find_cbfn *hook) {
    br_resclass_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    if (function_hook_state_BrResClassFindHook == HOOK_ENABLED) {
        assert(0 && "BrResClassFindHook not implemented.");
        abort();
    } else {
        return original_BrResClassFindHook(hook);
    }
}

function_hook_state_t function_hook_state_BrResClassAddMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassAddMany)
static br_uint_32(__cdecl*original_BrResClassAddMany)(br_resource_class **, int) = (br_uint_32(__cdecl*)(br_resource_class **, int))0x004dfe80;
CARM95_HOOK_FUNCTION(original_BrResClassAddMany, BrResClassAddMany)
br_uint_32 __cdecl BrResClassAddMany(br_resource_class **items, int n) {
    int i;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;

    if (function_hook_state_BrResClassAddMany == HOOK_ENABLED) {
        assert(0 && "BrResClassAddMany not implemented.");
        abort();
    } else {
        return original_BrResClassAddMany(items, n);
    }
}

function_hook_state_t function_hook_state_BrResClassRemoveMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassRemoveMany)
static br_uint_32(__cdecl*original_BrResClassRemoveMany)(br_resource_class **, int) = (br_uint_32(__cdecl*)(br_resource_class **, int))0x004dfec0;
CARM95_HOOK_FUNCTION(original_BrResClassRemoveMany, BrResClassRemoveMany)
br_uint_32 __cdecl BrResClassRemoveMany(br_resource_class **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    if (function_hook_state_BrResClassRemoveMany == HOOK_ENABLED) {
        assert(0 && "BrResClassRemoveMany not implemented.");
        abort();
    } else {
        return original_BrResClassRemoveMany(items, n);
    }
}

function_hook_state_t function_hook_state_BrResClassFindMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassFindMany)
static br_uint_32(__cdecl*original_BrResClassFindMany)(char *, br_resource_class **, int) = (br_uint_32(__cdecl*)(char *, br_resource_class **, int))0x004dff10;
CARM95_HOOK_FUNCTION(original_BrResClassFindMany, BrResClassFindMany)
br_uint_32 __cdecl BrResClassFindMany(char *pattern, br_resource_class **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    if (function_hook_state_BrResClassFindMany == HOOK_ENABLED) {
        assert(0 && "BrResClassFindMany not implemented.");
        abort();
    } else {
        return original_BrResClassFindMany(pattern, items, max);
    }
}

function_hook_state_t function_hook_state_BrResClassCount = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassCount)
static br_uint_32(__cdecl*original_BrResClassCount)(char *) = (br_uint_32(__cdecl*)(char *))0x004dff30;
CARM95_HOOK_FUNCTION(original_BrResClassCount, BrResClassCount)
br_uint_32 __cdecl BrResClassCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    if (function_hook_state_BrResClassCount == HOOK_ENABLED) {
        assert(0 && "BrResClassCount not implemented.");
        abort();
    } else {
        return original_BrResClassCount(pattern);
    }
}

function_hook_state_t function_hook_state_BrResClassEnum = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrResClassEnum)
static br_uint_32(__cdecl*original_BrResClassEnum)(char *, br_resclass_enum_cbfn *, void *) = (br_uint_32(__cdecl*)(char *, br_resclass_enum_cbfn *, void *))0x004dff40;
CARM95_HOOK_FUNCTION(original_BrResClassEnum, BrResClassEnum)
br_uint_32 __cdecl BrResClassEnum(char *pattern, br_resclass_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    if (function_hook_state_BrResClassEnum == HOOK_ENABLED) {
        assert(0 && "BrResClassEnum not implemented.");
        abort();
    } else {
        return original_BrResClassEnum(pattern, callback, arg);
    }
}

