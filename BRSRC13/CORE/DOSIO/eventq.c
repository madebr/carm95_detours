#include "eventq.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
int * hookvar__DOSEventQEnabled ;
#endif
#if 0
host_real_memory * hookvar__DOSEventMemory ;
#endif

function_hook_state_t function_hook_state_DOSEventBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DOSEventBegin)
br_error DOSEventBegin() {
    host_info hi;
    int s;
    LOG_TRACE("()");

    (void)hi;
    (void)s;

    if (function_hook_state_DOSEventBegin == HOOK_ENABLED) {
        assert(0 && "DOSEventBegin not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DOSEventEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DOSEventEnd)
void DOSEventEnd() {
    LOG_TRACE("()");


    if (function_hook_state_DOSEventEnd == HOOK_ENABLED) {
        assert(0 && "DOSEventEnd not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DOSEventWait = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DOSEventWait)
br_boolean DOSEventWait(dosio_event *event, br_boolean block) {
    int t;
    LOG_TRACE("(%p, %d)", event, block);

    (void)event;
    (void)block;
    (void)t;

    if (function_hook_state_DOSEventWait == HOOK_ENABLED) {
        assert(0 && "DOSEventWait not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

