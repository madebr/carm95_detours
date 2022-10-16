#include "logwrite.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static int(__cdecl*original_BrLogWrite)(void *, br_size_t, br_size_t) = (int(__cdecl*)(void *, br_size_t, br_size_t))0x00503120;
CARM95_HOOK_FUNCTION(original_BrLogWrite, BrLogWrite)
int __cdecl BrLogWrite(void *buffer, br_size_t s, br_size_t n) {
    LOG_TRACE("(%p, %u, %u)", buffer, s, n);

    (void)buffer;
    (void)s;
    (void)n;

    return original_BrLogWrite(buffer, s, n);
}
