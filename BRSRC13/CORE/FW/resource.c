#include "resource.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

void* ResToUser(struct resource_header *r) {
    br_int_32 align;
    LOG_TRACE("(%p)", r);

    (void)r;
    (void)align;

    NOT_IMPLEMENTED();
}

struct resource_header* UserToRes(void *r) {
    br_uint_8 *p;
    LOG_TRACE("(%p)", r);

    (void)r;
    (void)p;

    NOT_IMPLEMENTED();
}

static void *(*original_BrResAllocate)(void *, br_size_t, br_uint_8, ...) = (void *(*)(void *, br_size_t, br_uint_8, ...))0x004df370;
CARM95_HOOK_FUNCTION(original_BrResAllocate, BrResAllocate)
void* BrResAllocate(void *vparent, br_size_t size, br_uint_8 res_class) {
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

    return original_BrResAllocate(vparent, size, res_class);
}

static void(*original_BrResInternalFree)(struct resource_header *, br_boolean, ...) = (void(*)(struct resource_header *, br_boolean, ...))0x004df490;
CARM95_HOOK_FUNCTION(original_BrResInternalFree, BrResInternalFree)
void BrResInternalFree(struct resource_header *res, br_boolean callback) {
    int c;
    void *r;
    LOG_TRACE("(%p, %d)", res, callback);

    (void)res;
    (void)callback;
    (void)c;
    (void)r;

    original_BrResInternalFree(res, callback);
}

static void(*original_BrResFree)(void *, ...) = (void(*)(void *, ...))0x004df460;
CARM95_HOOK_FUNCTION(original_BrResFree, BrResFree)
void BrResFree(void *vres) {
    LOG_TRACE("(%p)", vres);

    (void)vres;

    original_BrResFree(vres);
}

static void(*original_BrResFreeNoCallback)(void *, ...) = (void(*)(void *, ...))0x004df560;
CARM95_HOOK_FUNCTION(original_BrResFreeNoCallback, BrResFreeNoCallback)
void BrResFreeNoCallback(void *vres) {
    LOG_TRACE("(%p)", vres);

    (void)vres;

    original_BrResFreeNoCallback(vres);
}

static void *(*original_BrResAdd)(void *, void *, ...) = (void *(*)(void *, void *, ...))0x004df590;
CARM95_HOOK_FUNCTION(original_BrResAdd, BrResAdd)
void* BrResAdd(void *vparent, void *vres) {
    struct resource_header *res;
    struct resource_header *parent;
    LOG_TRACE("(%p, %p)", vparent, vres);

    (void)vparent;
    (void)vres;
    (void)res;
    (void)parent;

    return original_BrResAdd(vparent, vres);
}

static void *(*original_BrResRemove)(void *, ...) = (void *(*)(void *, ...))0x004df5f0;
CARM95_HOOK_FUNCTION(original_BrResRemove, BrResRemove)
void* BrResRemove(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    return original_BrResRemove(vres);
}

static br_uint_8(*original_BrResClass)(void *, ...) = (br_uint_8(*)(void *, ...))0x004df620;
CARM95_HOOK_FUNCTION(original_BrResClass, BrResClass)
br_uint_8 BrResClass(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    return original_BrResClass(vres);
}

static br_boolean(*original_BrResIsChild)(void *, void *, ...) = (br_boolean(*)(void *, void *, ...))0x004df640;
CARM95_HOOK_FUNCTION(original_BrResIsChild, BrResIsChild)
br_boolean BrResIsChild(void *vparent, void *vchild) {
    struct resource_header *parent;
    struct resource_header *child;
    struct resource_header *cp;
    LOG_TRACE("(%p, %p)", vparent, vchild);

    (void)vparent;
    (void)vchild;
    (void)parent;
    (void)child;
    (void)cp;

    return original_BrResIsChild(vparent, vchild);
}

static br_uint_32(*original_BrResSize)(void *, ...) = (br_uint_32(*)(void *, ...))0x004df690;
CARM95_HOOK_FUNCTION(original_BrResSize, BrResSize)
br_uint_32 BrResSize(void *vres) {
    struct resource_header *res;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)res;

    return original_BrResSize(vres);
}

static br_uint_32(*original_ResSizeTotal)(void *, br_uint_32 *, ...) = (br_uint_32(*)(void *, br_uint_32 *, ...))0x004df770;
CARM95_HOOK_FUNCTION(original_ResSizeTotal, ResSizeTotal)
br_uint_32 ResSizeTotal(void *vres, br_uint_32 *ptotal) {
    LOG_TRACE("(%p, %p)", vres, ptotal);

    (void)vres;
    (void)ptotal;

    return original_ResSizeTotal(vres, ptotal);
}

static br_uint_32(*original_BrResSizeTotal)(void *, ...) = (br_uint_32(*)(void *, ...))0x004df6d0;
CARM95_HOOK_FUNCTION(original_BrResSizeTotal, BrResSizeTotal)
br_uint_32 BrResSizeTotal(void *vres) {
    br_uint_32 total;
    LOG_TRACE("(%p)", vres);

    (void)vres;
    (void)total;

    return original_BrResSizeTotal(vres);
}

static br_uint_32(*original_BrResChildEnum)(void *, br_resenum_cbfn *, void *, ...) = (br_uint_32(*)(void *, br_resenum_cbfn *, void *, ...))0x004df810;
CARM95_HOOK_FUNCTION(original_BrResChildEnum, BrResChildEnum)
br_uint_32 BrResChildEnum(void *vres, br_resenum_cbfn *callback, void *arg) {
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

    return original_BrResChildEnum(vres, callback, arg);
}

static br_uint_32(*original_BrResCheck)(void *, int, ...) = (br_uint_32(*)(void *, int, ...))0x004df870;
CARM95_HOOK_FUNCTION(original_BrResCheck, BrResCheck)
br_uint_32 BrResCheck(void *vres, int no_tag) {
    struct resource_header *res;
    LOG_TRACE("(%p, %d)", vres, no_tag);

    (void)vres;
    (void)no_tag;
    (void)res;

    return original_BrResCheck(vres, no_tag);
}

static char *(*original_BrResStrDup)(void *, char *, ...) = (char *(*)(void *, char *, ...))0x004df8b0;
CARM95_HOOK_FUNCTION(original_BrResStrDup, BrResStrDup)
char* BrResStrDup(void *vparent, char *str) {
    int l;
    char *nstr;
    LOG_TRACE("(%p, \"%s\")", vparent, str);

    (void)vparent;
    (void)str;
    (void)l;
    (void)nstr;

    return original_BrResStrDup(vparent, str);
}

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

    NOT_IMPLEMENTED();
}

static void(*original_BrResDump)(void *, br_putline_cbfn *, void *, ...) = (void(*)(void *, br_putline_cbfn *, void *, ...))0x004df8f0;
CARM95_HOOK_FUNCTION(original_BrResDump, BrResDump)
void BrResDump(void *vres, br_putline_cbfn *putline, void *arg) {
    struct resource_header *res;
    LOG_TRACE("(%p, %p, %p)", vres, putline, arg);

    (void)vres;
    (void)putline;
    (void)arg;
    (void)res;

    original_BrResDump(vres, putline, arg);
}

char* BrResClassIdentifier(br_uint_8 res_class) {
    br_resource_class *rclass;
    LOG_TRACE("(%u)", res_class);

    (void)res_class;
    (void)rclass;

    NOT_IMPLEMENTED();
}

