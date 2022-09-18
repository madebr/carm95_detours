#include "stdmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_allocator * hookvar_BrStdlibAllocator  = (void*)0x00530090;
#if 0
br_allocator ** hookvar__BrDefaultAllocator ;
#endif

void* BrStdlibAllocate(br_size_t size, br_uint_8 type) {
    void *m;
    LOG_TRACE("(%u, %u)", size, type);

    (void)size;
    (void)type;
    (void)m;

    NOT_IMPLEMENTED();
}

void BrStdlibFree(void *mem) {
    LOG_TRACE("(%p)", mem);

    (void)mem;

    NOT_IMPLEMENTED();
}

br_size_t BrStdlibInquire(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    NOT_IMPLEMENTED();
}

br_uint_32 BrStdlibAlign(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    NOT_IMPLEMENTED();
}

