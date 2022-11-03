#include "readmse.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
unsigned char(* hookvar_mouseHandler )[245];
#endif
#if 0
br_boolean * hookvar_mouseActive ;
#endif
#if 0
host_real_memory * hookvar_mouseMemory ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
host_regs * hookvar_regs__readmse ;
#endif

function_hook_state_t function_hook_state_DOSMouseBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DOSMouseBegin, function_hook_state_DOSMouseBegin)
br_error DOSMouseBegin() {
    host_info hi;
    LOG_TRACE("()");

    (void)hi;

    if (function_hook_state_DOSMouseBegin == HOOK_ENABLED) {
        assert(0 && "DOSMouseBegin not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DOSMouseEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DOSMouseEnd, function_hook_state_DOSMouseEnd)
void DOSMouseEnd() {
    LOG_TRACE("()");


    if (function_hook_state_DOSMouseEnd == HOOK_ENABLED) {
        assert(0 && "DOSMouseEnd not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DOSMouseRead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DOSMouseRead, function_hook_state_DOSMouseRead)
br_error DOSMouseRead(br_int_32 *mouse_x, br_int_32 *mouse_y, br_uint_32 *mouse_buttons) {
    br_int_16 mx;
    br_int_16 my;
    static br_int_16 ox;
    static br_int_16 oy;
    LOG_TRACE("(%p, %p, %p)", mouse_x, mouse_y, mouse_buttons);

    (void)mouse_x;
    (void)mouse_y;
    (void)mouse_buttons;
    (void)mx;
    (void)my;
    (void)ox;
    (void)oy;

    if (function_hook_state_DOSMouseRead == HOOK_ENABLED) {
        assert(0 && "DOSMouseRead not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

