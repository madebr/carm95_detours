#include "stdmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_allocator * hookvar_BrStdlibAllocator  = (void*)0x00530090;
#if 0
br_allocator ** hookvar__BrDefaultAllocator ;
#endif

function_hook_state_t function_hook_state_BrStdlibAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdlibAllocate)
void* BrStdlibAllocate(br_size_t size, br_uint_8 type) {
    void *m;
    LOG_TRACE("(%u, %u)", size, type);

    (void)size;
    (void)type;
    (void)m;

    if (function_hook_state_BrStdlibAllocate == HOOK_ENABLED) {
        assert(0 && "BrStdlibAllocate not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrStdlibFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdlibFree)
void BrStdlibFree(void *mem) {
    LOG_TRACE("(%p)", mem);

    (void)mem;

    if (function_hook_state_BrStdlibFree == HOOK_ENABLED) {
        assert(0 && "BrStdlibFree not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrStdlibInquire = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdlibInquire)
br_size_t BrStdlibInquire(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    if (function_hook_state_BrStdlibInquire == HOOK_ENABLED) {
        assert(0 && "BrStdlibInquire not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrStdlibAlign = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdlibAlign)
br_uint_32 BrStdlibAlign(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    if (function_hook_state_BrStdlibAlign == HOOK_ENABLED) {
        assert(0 && "BrStdlibAlign not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

