#include "logwrite.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrLogWrite = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrLogWrite)
static int(__cdecl*original_BrLogWrite)(void *, br_size_t, br_size_t) = (int(__cdecl*)(void *, br_size_t, br_size_t))0x00503120;
CARM95_HOOK_FUNCTION(original_BrLogWrite, BrLogWrite)
int __cdecl BrLogWrite(void *buffer, br_size_t s, br_size_t n) {
    LOG_TRACE("(%p, %u, %u)", buffer, s, n);

    (void)buffer;
    (void)s;
    (void)n;

    if (function_hook_state_BrLogWrite == HOOK_ENABLED) {
        assert(0 && "BrLogWrite not implemented.");
        abort();
    } else {
        return original_BrLogWrite(buffer, s, n);
    }
}

