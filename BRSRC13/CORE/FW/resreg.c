#include "resreg.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_resource_class *(__cdecl*original_BrResClassAdd)(br_resource_class *) = (br_resource_class *(__cdecl*)(br_resource_class *))0x004dfe00;
CARM95_HOOK_FUNCTION(original_BrResClassAdd, BrResClassAdd)
br_resource_class* __cdecl BrResClassAdd(br_resource_class *rclass) {
    br_resource_class *r;
    LOG_TRACE("(%p)", rclass);

    (void)rclass;
    (void)r;

    return original_BrResClassAdd(rclass);
}

static br_resource_class *(__cdecl*original_BrResClassRemove)(br_resource_class *) = (br_resource_class *(__cdecl*)(br_resource_class *))0x004dfe30;
CARM95_HOOK_FUNCTION(original_BrResClassRemove, BrResClassRemove)
br_resource_class* __cdecl BrResClassRemove(br_resource_class *rclass) {
    br_resource_class *r;
    LOG_TRACE("(%p)", rclass);

    (void)rclass;
    (void)r;

    return original_BrResClassRemove(rclass);
}

static br_resource_class *(__cdecl*original_BrResClassFind)(char *) = (br_resource_class *(__cdecl*)(char *))0x004dfe60;
CARM95_HOOK_FUNCTION(original_BrResClassFind, BrResClassFind)
br_resource_class* __cdecl BrResClassFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrResClassFind(pattern);
}

static br_resclass_find_cbfn *(__cdecl*original_BrResClassFindHook)(br_resclass_find_cbfn *) = (br_resclass_find_cbfn *(__cdecl*)(br_resclass_find_cbfn *))0x004dfe70;
CARM95_HOOK_FUNCTION(original_BrResClassFindHook, BrResClassFindHook)
br_resclass_find_cbfn* __cdecl BrResClassFindHook(br_resclass_find_cbfn *hook) {
    br_resclass_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    return original_BrResClassFindHook(hook);
}

static br_uint_32(__cdecl*original_BrResClassAddMany)(br_resource_class **, int) = (br_uint_32(__cdecl*)(br_resource_class **, int))0x004dfe80;
CARM95_HOOK_FUNCTION(original_BrResClassAddMany, BrResClassAddMany)
br_uint_32 __cdecl BrResClassAddMany(br_resource_class **items, int n) {
    int i;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;

    return original_BrResClassAddMany(items, n);
}

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

    return original_BrResClassRemoveMany(items, n);
}

static br_uint_32(__cdecl*original_BrResClassFindMany)(char *, br_resource_class **, int) = (br_uint_32(__cdecl*)(char *, br_resource_class **, int))0x004dff10;
CARM95_HOOK_FUNCTION(original_BrResClassFindMany, BrResClassFindMany)
br_uint_32 __cdecl BrResClassFindMany(char *pattern, br_resource_class **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    return original_BrResClassFindMany(pattern, items, max);
}

static br_uint_32(__cdecl*original_BrResClassCount)(char *) = (br_uint_32(__cdecl*)(char *))0x004dff30;
CARM95_HOOK_FUNCTION(original_BrResClassCount, BrResClassCount)
br_uint_32 __cdecl BrResClassCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrResClassCount(pattern);
}

static br_uint_32(__cdecl*original_BrResClassEnum)(char *, br_resclass_enum_cbfn *, void *) = (br_uint_32(__cdecl*)(char *, br_resclass_enum_cbfn *, void *))0x004dff40;
CARM95_HOOK_FUNCTION(original_BrResClassEnum, BrResClassEnum)
br_uint_32 __cdecl BrResClassEnum(char *pattern, br_resclass_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    return original_BrResClassEnum(pattern, callback, arg);
}

