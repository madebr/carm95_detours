#include "readmse.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

br_error DOSMouseBegin() {
    host_info hi;
    LOG_TRACE("()");

    (void)hi;

    NOT_IMPLEMENTED();
}

void DOSMouseEnd() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

