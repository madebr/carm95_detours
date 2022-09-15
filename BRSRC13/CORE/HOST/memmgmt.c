#include "memmgmt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
 // Suffix added to avoid duplicate symbol
#if 0
host_regs * hookvar_regs__memmgmt ;
#endif

static br_error(*original_HostLock)(br_uint_32, br_uint_16, br_size_t, ...) = (br_error(*)(br_uint_32, br_uint_16, br_size_t, ...))0x005014f0;
CARM95_HOOK_FUNCTION(original_HostLock, HostLock)
br_error HostLock(br_uint_32 offset, br_uint_16 sel, br_size_t size) {
    LOG_TRACE("(%u, %u, %u)", offset, sel, size);

    (void)offset;
    (void)sel;
    (void)size;

    return original_HostLock(offset, sel, size);
}

static br_error(*original_HostUnlock)(br_uint_32, br_uint_16, br_size_t, ...) = (br_error(*)(br_uint_32, br_uint_16, br_size_t, ...))0x00501500;
CARM95_HOOK_FUNCTION(original_HostUnlock, HostUnlock)
br_error HostUnlock(br_uint_32 offset, br_uint_16 sel, br_size_t size) {
    LOG_TRACE("(%u, %u, %u)", offset, sel, size);

    (void)offset;
    (void)sel;
    (void)size;

    return original_HostUnlock(offset, sel, size);
}

static br_error(*original_HostSelectorAllocate)(br_uint_16 *, ...) = (br_error(*)(br_uint_16 *, ...))0x00501510;
CARM95_HOOK_FUNCTION(original_HostSelectorAllocate, HostSelectorAllocate)
br_error HostSelectorAllocate(br_uint_16 *selp) {
    LOG_TRACE("(%p)", selp);

    (void)selp;

    return original_HostSelectorAllocate(selp);
}

static br_error(*original_HostSelectorAllocateLinear)(br_uint_16 *, br_uint_32, br_size_t, ...) = (br_error(*)(br_uint_16 *, br_uint_32, br_size_t, ...))0x00501520;
CARM95_HOOK_FUNCTION(original_HostSelectorAllocateLinear, HostSelectorAllocateLinear)
br_error HostSelectorAllocateLinear(br_uint_16 *selp, br_uint_32 base, br_size_t size) {
    br_uint_16 sel;
    br_error r;
    LOG_TRACE("(%p, %u, %u)", selp, base, size);

    (void)selp;
    (void)base;
    (void)size;
    (void)sel;
    (void)r;

    return original_HostSelectorAllocateLinear(selp, base, size);
}

static br_error(*original_HostSelectorAllocateAlias)(br_uint_16 *, br_uint_16, ...) = (br_error(*)(br_uint_16 *, br_uint_16, ...))0x00501530;
CARM95_HOOK_FUNCTION(original_HostSelectorAllocateAlias, HostSelectorAllocateAlias)
br_error HostSelectorAllocateAlias(br_uint_16 *aliasp, br_uint_16 sel) {
    br_uint_16 alias;
    br_uint_32 base;
    br_uint_32 limit;
    br_error r;
    LOG_TRACE("(%p, %u)", aliasp, sel);

    (void)aliasp;
    (void)sel;
    (void)alias;
    (void)base;
    (void)limit;
    (void)r;

    return original_HostSelectorAllocateAlias(aliasp, sel);
}

static br_error(*original_HostSelectorAllocatePhysical)(br_uint_16 *, br_uint_32, br_size_t, ...) = (br_error(*)(br_uint_16 *, br_uint_32, br_size_t, ...))0x00501540;
CARM95_HOOK_FUNCTION(original_HostSelectorAllocatePhysical, HostSelectorAllocatePhysical)
br_error HostSelectorAllocatePhysical(br_uint_16 *selp, br_uint_32 phys_addr, br_size_t size) {
    LOG_TRACE("(%p, %u, %u)", selp, phys_addr, size);

    (void)selp;
    (void)phys_addr;
    (void)size;

    return original_HostSelectorAllocatePhysical(selp, phys_addr, size);
}

static br_error(*original_HostSelectorFree)(br_uint_16, ...) = (br_error(*)(br_uint_16, ...))0x00501550;
CARM95_HOOK_FUNCTION(original_HostSelectorFree, HostSelectorFree)
br_error HostSelectorFree(br_uint_16 sel) {
    br_uint_16 rsel;
    LOG_TRACE("(%u)", sel);

    (void)sel;
    (void)rsel;

    return original_HostSelectorFree(sel);
}

static br_error(*original_HostSelectorBaseSet)(br_uint_16, br_uint_32, ...) = (br_error(*)(br_uint_16, br_uint_32, ...))0x00501580;
CARM95_HOOK_FUNCTION(original_HostSelectorBaseSet, HostSelectorBaseSet)
br_error HostSelectorBaseSet(br_uint_16 sel, br_uint_32 base) {
    LOG_TRACE("(%u, %u)", sel, base);

    (void)sel;
    (void)base;

    return original_HostSelectorBaseSet(sel, base);
}

static br_error(*original_HostSelectorLimitSet)(br_uint_16, br_size_t, ...) = (br_error(*)(br_uint_16, br_size_t, ...))0x00501590;
CARM95_HOOK_FUNCTION(original_HostSelectorLimitSet, HostSelectorLimitSet)
br_error HostSelectorLimitSet(br_uint_16 sel, br_size_t limit) {
    LOG_TRACE("(%u, %u)", sel, limit);

    (void)sel;
    (void)limit;

    return original_HostSelectorLimitSet(sel, limit);
}

static br_error(*original_HostSelectorBaseQuery)(br_uint_32 *, br_uint_16, ...) = (br_error(*)(br_uint_32 *, br_uint_16, ...))0x005015a0;
CARM95_HOOK_FUNCTION(original_HostSelectorBaseQuery, HostSelectorBaseQuery)
br_error HostSelectorBaseQuery(br_uint_32 *basep, br_uint_16 sel) {
    br_uint_32 base;
    LOG_TRACE("(%p, %u)", basep, sel);

    (void)basep;
    (void)sel;
    (void)base;

    return original_HostSelectorBaseQuery(basep, sel);
}

static br_error(*original_HostSelectorLimitQuery)(br_uint_32 *, br_uint_16, ...) = (br_error(*)(br_uint_32 *, br_uint_16, ...))0x005015b0;
CARM95_HOOK_FUNCTION(original_HostSelectorLimitQuery, HostSelectorLimitQuery)
br_error HostSelectorLimitQuery(br_uint_32 *limitp, br_uint_16 sel) {
    br_uint_32 limit;
    struct ldt ldt;
    LOG_TRACE("(%p, %u)", limitp, sel);

    (void)limitp;
    (void)sel;
    (void)limit;
    (void)ldt;

    return original_HostSelectorLimitQuery(limitp, sel);
}

