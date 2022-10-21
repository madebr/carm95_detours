#include "resource.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_ResToUser = HOOK_UNAVAILABLE;
void* ResToUser(struct resource_header *r) {
    br_int_32 align;
    LOG_TRACE("(%p)", r);

    (void)r;
    (void)align;

    if (function_hook_state_ResToUser == HOOK_ENABLED) {
        assert(0 && "ResToUser not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_UserToRes = HOOK_UNAVAILABLE;
struct resource_header* UserToRes(void *r) {
    br_uint_8 *p;
    LOG_TRACE("(%p)", r);

    (void)r;
    (void)p;

    if (function_hook_state_UserToRes == HOOK_ENABLED) {
        assert(0 && "UserToRes not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrResAllocate = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrResAllocate)(void *, br_size_t, br_uint_8) = (void *(__cdecl*)(void *, br_size_t, br_uint_8))0x004df370;
CARM95_HOOK_FUNCTION(original_BrResAllocate, BrResAllocate)
void* __cdecl BrResAllocate(void *vparent, br_size_t size, br_uint_8 res_class) {
    struct resource_header *res;
    struct resource_header *parent;
    br_int_32 malign;
    br_int_32 calign;
    br_int_32 pad;
    br_int_32 actual_pad;
    LOG_TRACE("(%p, %u, %u)", vparent, size, res_class);

    (void)vparent;
    (void)size;
    (void)res_class;
    (void)res;
    (void)parent;
    (void)malign;
    (void)calign;
    (void)pad;
    (void)actual_pad;

    if (function_hook_state_BrResAllocate == HOOK_ENABLED) {
        assert(0 && "BrResAllocate not implemented.");
        abort();
    } else {
        return original_BrResAllocate(vparent, size, res_class);
    }
}

function_hook_state_t function_hook_state_BrResInternalFree = HOOK_UNAVAILABLE;
static void(__stdcall*original_BrResInternalFree)(struct resource_header *, br_boolean) = (void(__stdcall*)(struct resource_header *, br_boolean))0x004df490;
CARM95_HOOK_FUNCTION(original_BrResInternalFree, BrResInternalFree)
void __stdcall BrResInternalFree(struct resource_header *res, br_boolean callback) {
    int c;
    void *r;
    LOG_TRACE("(%p, %d)", res, callback);

    (void)res;
    (void)callback;
    (void)c;
    (void)r;

    if (function_hook_state_BrResInternalFree == HOOK_ENABLED) {
        assert(0 && "BrResInternalFree not implemented.");
        abort();
    } else {
        original_BrResInternalFree(res, callback);
    }
}

function_hook_state_t function_hook_state_BrResFree = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrResFree)(void *) = (void(__cdecl*)(void *))0x004df460;
CARM95_HOOK_FUNCTION(original_BrResFree, BrResFree)
void __cdecl BrResFree(void *vres) {
    LOG_TRACE("(%p)", vres);

    (void)vres;

    if (function_hook_state_BrResFree == HOOK_ENABLED) {
        assert(0 && "BrResFree not implemented.");
        abort();
    } else {
        original_BrResFree(vres);
    }
}

function_hook_state_t function_hook_state_BrResFreeNoCallback = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrResFreeNoCallback)(void *) = (void(__cdecl*)(void *))0x004df560;
CARM95_HOOK_FUNCTION(original_BrResFreeNoCallback, BrResFreeNoCallback)
void __cdecl BrResFreeNoCallback(void *vres) {
    LOG_TRACE("(%p)", vres);

    (void)vres;

    if (function_hook_state_BrResFreeNoCallback == HOOK_ENABLED) {
        assert(0 && "BrResFreeNoCallback not implemented.");
        abort();
    } else {
        original_BrResFreeNoCallback(vres);
    }
}

function_hook_state_t function_hook_state_BrResAdd = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrResAdd)(void *, void *) = (void *(__cdecl*)(void *, void *))0x004df590;
CARM95_HOOK_FUNCTION(original_BrResAdd, BrResAdd)
void* __cdecl BrResAdd(void *vparent, void *vres) {
    struct resource_header *res;
    struct resource_header *parent;
    LOG_TRACE("(%p, %p)", vparent, vres);

    (void)vparent;
    (void)vres;
    (void)res;
    (void)parent;

    if (function_hook_state_BrResAdd == HOOK_ENABLED) {
        assert(0 && "BrResAdd not implemented.");
        abort();
    } else {
        return original_BrResAdd(vparent, vres);
    }
}

function_hook_state_t function_hook_state_BrResRemove = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrResRemove)(void *) = (void *(__cdecl*)(void *))0x004df5f0;
CARM95_HOOK_FUNCTION(original_BrResRemove, BrResRemove)
void* __cdecl BrResRemove(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    if (function_hook_state_BrResRemove == HOOK_ENABLED) {
        assert(0 && "BrResRemove not implemented.");
        abort();
    } else {
        return original_BrResRemove(vres);
    }
}

function_hook_state_t function_hook_state_BrResClass = HOOK_UNAVAILABLE;
static br_uint_8(__cdecl*original_BrResClass)(void *) = (br_uint_8(__cdecl*)(void *))0x004df620;
CARM95_HOOK_FUNCTION(original_BrResClass, BrResClass)
br_uint_8 __cdecl BrResClass(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    if (function_hook_state_BrResClass == HOOK_ENABLED) {
        assert(0 && "BrResClass not implemented.");
        abort();
    } else {
        return original_BrResClass(vres);
    }
}

function_hook_state_t function_hook_state_BrResIsChild = HOOK_UNAVAILABLE;
static br_boolean(__cdecl*original_BrResIsChild)(void *, void *) = (br_boolean(__cdecl*)(void *, void *))0x004df640;
CARM95_HOOK_FUNCTION(original_BrResIsChild, BrResIsChild)
br_boolean __cdecl BrResIsChild(void *vparent, void *vchild) {
    struct resource_header *parent;
    struct resource_header *child;
    struct resource_header *cp;
    LOG_TRACE("(%p, %p)", vparent, vchild);

    (void)vparent;
    (void)vchild;
    (void)parent;
    (void)child;
    (void)cp;

    if (function_hook_state_BrResIsChild == HOOK_ENABLED) {
        assert(0 && "BrResIsChild not implemented.");
        abort();
    } else {
        return original_BrResIsChild(vparent, vchild);
    }
}

function_hook_state_t function_hook_state_BrResSize = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrResSize)(void *) = (br_uint_32(__cdecl*)(void *))0x004df690;
CARM95_HOOK_FUNCTION(original_BrResSize, BrResSize)
br_uint_32 __cdecl BrResSize(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    if (function_hook_state_BrResSize == HOOK_ENABLED) {
        assert(0 && "BrResSize not implemented.");
        abort();
    } else {
        return original_BrResSize(vres);
    }
}

function_hook_state_t function_hook_state_ResSizeTotal = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_ResSizeTotal)(void *, br_uint_32 *) = (br_uint_32(__cdecl*)(void *, br_uint_32 *))0x004df770;
CARM95_HOOK_FUNCTION(original_ResSizeTotal, ResSizeTotal)
br_uint_32 __cdecl ResSizeTotal(void *vres, br_uint_32 *ptotal) {
    LOG_TRACE("(%p, %p)", vres, ptotal);

    (void)vres;
    (void)ptotal;

    if (function_hook_state_ResSizeTotal == HOOK_ENABLED) {
        assert(0 && "ResSizeTotal not implemented.");
        abort();
    } else {
        return original_ResSizeTotal(vres, ptotal);
    }
}

function_hook_state_t function_hook_state_BrResSizeTotal = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrResSizeTotal)(void *) = (br_uint_32(__cdecl*)(void *))0x004df6d0;
CARM95_HOOK_FUNCTION(original_BrResSizeTotal, BrResSizeTotal)
br_uint_32 __cdecl BrResSizeTotal(void *vres) {
    br_uint_32 total;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)total;

    if (function_hook_state_BrResSizeTotal == HOOK_ENABLED) {
        assert(0 && "BrResSizeTotal not implemented.");
        abort();
    } else {
        return original_BrResSizeTotal(vres);
    }
}

function_hook_state_t function_hook_state_BrResChildEnum = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrResChildEnum)(void *, br_resenum_cbfn *, void *) = (br_uint_32(__cdecl*)(void *, br_resenum_cbfn *, void *))0x004df810;
CARM95_HOOK_FUNCTION(original_BrResChildEnum, BrResChildEnum)
br_uint_32 __cdecl BrResChildEnum(void *vres, br_resenum_cbfn *callback, void *arg) {
    struct resource_header *res;
    struct resource_header *rp;
    br_uint_32 r;
    LOG_TRACE("(%p, %p, %p)", vres, callback, arg);

    (void)vres;
    (void)callback;
    (void)arg;
    (void)res;
    (void)rp;
    (void)r;

    if (function_hook_state_BrResChildEnum == HOOK_ENABLED) {
        assert(0 && "BrResChildEnum not implemented.");
        abort();
    } else {
        return original_BrResChildEnum(vres, callback, arg);
    }
}

function_hook_state_t function_hook_state_BrResCheck = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrResCheck)(void *, int) = (br_uint_32(__cdecl*)(void *, int))0x004df870;
CARM95_HOOK_FUNCTION(original_BrResCheck, BrResCheck)
br_uint_32 __cdecl BrResCheck(void *vres, int no_tag) {
    struct resource_header *res;
    LOG_TRACE("(%p, %d)", vres, no_tag);

    (void)vres;
    (void)no_tag;
    (void)res;

    if (function_hook_state_BrResCheck == HOOK_ENABLED) {
        assert(0 && "BrResCheck not implemented.");
        abort();
    } else {
        return original_BrResCheck(vres, no_tag);
    }
}

function_hook_state_t function_hook_state_BrResStrDup = HOOK_UNAVAILABLE;
static char *(__cdecl*original_BrResStrDup)(void *, char *) = (char *(__cdecl*)(void *, char *))0x004df8b0;
CARM95_HOOK_FUNCTION(original_BrResStrDup, BrResStrDup)
char* __cdecl BrResStrDup(void *vparent, char *str) {
    int l;
    char *nstr;
    LOG_TRACE("(%p, \"%s\")", vparent, str);

    (void)vparent;
    (void)str;
    (void)l;
    (void)nstr;

    if (function_hook_state_BrResStrDup == HOOK_ENABLED) {
        assert(0 && "BrResStrDup not implemented.");
        abort();
    } else {
        return original_BrResStrDup(vparent, str);
    }
}

function_hook_state_t function_hook_state_InternalResourceDump = HOOK_UNAVAILABLE;
void InternalResourceDump(struct resource_header *res, br_putline_cbfn *putline, void *arg, int level) {
    int i;
    char *cp;
    struct resource_header *child;
    br_resource_class *rclass;
    LOG_TRACE("(%p, %p, %p, %d)", res, putline, arg, level);

    (void)res;
    (void)putline;
    (void)arg;
    (void)level;
    (void)i;
    (void)cp;
    (void)child;
    (void)rclass;

    if (function_hook_state_InternalResourceDump == HOOK_ENABLED) {
        assert(0 && "InternalResourceDump not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrResDump = HOOK_UNAVAILABLE;
void(__cdecl*BrResDump)(void *, br_putline_cbfn *, void *) = (void(__cdecl*)(void *, br_putline_cbfn *, void *))0x004df8f0;
void BrResDump_do_not_use(void *vres, br_putline_cbfn *putline, void *arg) {
    struct resource_header *res;
    LOG_TRACE("(%p, %p, %p)", vres, putline, arg);

    (void)vres;
    (void)putline;
    (void)arg;
    (void)res;

    if (function_hook_state_BrResDump == HOOK_ENABLED) {
        assert(0 && "BrResDump_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrResClassIdentifier = HOOK_UNAVAILABLE;
char* BrResClassIdentifier(br_uint_8 res_class) {
    br_resource_class *rclass;
    LOG_TRACE("(%u)", res_class);

    (void)res_class;
    (void)rclass;

    if (function_hook_state_BrResClassIdentifier == HOOK_ENABLED) {
        assert(0 && "BrResClassIdentifier not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

