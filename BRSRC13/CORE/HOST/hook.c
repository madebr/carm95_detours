#include "hook.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_error(*original_HostInterruptHook)(host_interrupt_hook *, br_uint_8, br_uint_32, br_uint_16, ...) = (br_error(*)(host_interrupt_hook *, br_uint_8, br_uint_32, br_uint_16, ...))0x00501a70;
CARM95_HOOK_FUNCTION(original_HostInterruptHook, HostInterruptHook)
br_error HostInterruptHook(host_interrupt_hook *h, br_uint_8 vector, br_uint_32 off, br_uint_16 sel) {
    br_error r;
    LOG_TRACE("(%p, %u, %u, %u)", h, vector, off, sel);

    (void)h;
    (void)vector;
    (void)off;
    (void)sel;
    (void)r;

    return original_HostInterruptHook(h, vector, off, sel);
}

static br_error(*original_HostInterruptUnhook)(host_interrupt_hook *, ...) = (br_error(*)(host_interrupt_hook *, ...))0x00501ae0;
CARM95_HOOK_FUNCTION(original_HostInterruptUnhook, HostInterruptUnhook)
br_error HostInterruptUnhook(host_interrupt_hook *h) {
    br_error r;
    LOG_TRACE("(%p)", h);

    (void)h;
    (void)r;

    return original_HostInterruptUnhook(h);
}

static br_error(*original_HostExceptionHook)(host_exception_hook *, br_uint_8, br_uint_32, br_uint_16, ...) = (br_error(*)(host_exception_hook *, br_uint_8, br_uint_32, br_uint_16, ...))0x00501b20;
CARM95_HOOK_FUNCTION(original_HostExceptionHook, HostExceptionHook)
br_error HostExceptionHook(host_exception_hook *h, br_uint_8 exception, br_uint_32 off, br_uint_16 sel) {
    br_error r;
    LOG_TRACE("(%p, %u, %u, %u)", h, exception, off, sel);

    (void)h;
    (void)exception;
    (void)off;
    (void)sel;
    (void)r;

    return original_HostExceptionHook(h, exception, off, sel);
}

static br_error(*original_HostExceptionUnhook)(host_exception_hook *, ...) = (br_error(*)(host_exception_hook *, ...))0x00501b90;
CARM95_HOOK_FUNCTION(original_HostExceptionUnhook, HostExceptionUnhook)
br_error HostExceptionUnhook(host_exception_hook *h) {
    br_error r;
    LOG_TRACE("(%p)", h);

    (void)h;
    (void)r;

    return original_HostExceptionUnhook(h);
}

