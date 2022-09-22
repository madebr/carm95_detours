#ifndef _READMSE_H_
#define _READMSE_H_

#include "br_types.h"

// extern unsigned char(* hookvar_mouseHandler )[245];
// extern br_boolean * hookvar_mouseActive ;
// extern host_real_memory * hookvar_mouseMemory ;
// extern host_regs * hookvar_regs__readmse ; // suffix added to avoid duplicate symbol

br_error DOSMouseBegin();

void DOSMouseEnd();

br_error DOSMouseRead(br_int_32 *mouse_x, br_int_32 *mouse_y, br_uint_32 *mouse_buttons);

#endif
