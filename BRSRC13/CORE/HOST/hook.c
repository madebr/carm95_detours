#include "hook.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_HostInterruptHook = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_HostInterruptHook)(host_interrupt_hook *, br_uint_8, br_uint_32, br_uint_16) = (br_error(__cdecl*)(host_interrupt_hook *, br_uint_8, br_uint_32, br_uint_16))0x00501a70;
CARM95_HOOK_FUNCTION(original_HostInterruptHook, HostInterruptHook)
br_error __cdecl HostInterruptHook(host_interrupt_hook *h, br_uint_8 vector, br_uint_32 off, br_uint_16 sel) {
    br_error r;
    LOG_TRACE("(%p, %u, %u, %u)", h, vector, off, sel);

    (void)h;
    (void)vector;
    (void)off;
    (void)sel;
    (void)r;

    if (function_hook_state_HostInterruptHook == HOOK_ENABLED) {
        assert(0 && "HostInterruptHook not implemented.");
        abort();
    } else {
        return original_HostInterruptHook(h, vector, off, sel);
    }
}

function_hook_state_t function_hook_state_HostInterruptUnhook = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_HostInterruptUnhook)(host_interrupt_hook *) = (br_error(__cdecl*)(host_interrupt_hook *))0x00501ae0;
CARM95_HOOK_FUNCTION(original_HostInterruptUnhook, HostInterruptUnhook)
br_error __cdecl HostInterruptUnhook(host_interrupt_hook *h) {
    br_error r;
    LOG_TRACE("(%p)", h);

    (void)h;
    (void)r;

    if (function_hook_state_HostInterruptUnhook == HOOK_ENABLED) {
        assert(0 && "HostInterruptUnhook not implemented.");
        abort();
    } else {
        return original_HostInterruptUnhook(h);
    }
}

function_hook_state_t function_hook_state_HostExceptionHook = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_HostExceptionHook)(host_exception_hook *, br_uint_8, br_uint_32, br_uint_16) = (br_error(__cdecl*)(host_exception_hook *, br_uint_8, br_uint_32, br_uint_16))0x00501b20;
CARM95_HOOK_FUNCTION(original_HostExceptionHook, HostExceptionHook)
br_error __cdecl HostExceptionHook(host_exception_hook *h, br_uint_8 exception, br_uint_32 off, br_uint_16 sel) {
    br_error r;
    LOG_TRACE("(%p, %u, %u, %u)", h, exception, off, sel);

    (void)h;
    (void)exception;
    (void)off;
    (void)sel;
    (void)r;

    if (function_hook_state_HostExceptionHook == HOOK_ENABLED) {
        assert(0 && "HostExceptionHook not implemented.");
        abort();
    } else {
        return original_HostExceptionHook(h, exception, off, sel);
    }
}

function_hook_state_t function_hook_state_HostExceptionUnhook = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_HostExceptionUnhook)(host_exception_hook *) = (br_error(__cdecl*)(host_exception_hook *))0x00501b90;
CARM95_HOOK_FUNCTION(original_HostExceptionUnhook, HostExceptionUnhook)
br_error __cdecl HostExceptionUnhook(host_exception_hook *h) {
    br_error r;
    LOG_TRACE("(%p)", h);

    (void)h;
    (void)r;

    if (function_hook_state_HostExceptionUnhook == HOOK_ENABLED) {
        assert(0 && "HostExceptionUnhook not implemented.");
        abort();
    } else {
        return original_HostExceptionUnhook(h);
    }
}

