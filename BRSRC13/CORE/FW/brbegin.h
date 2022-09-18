#ifndef _BRBEGIN_H_
#define _BRBEGIN_H_

#include "br_types.h"

extern br_boolean * hookvar_active ; // addr: 005289B0

br_error __stdcall BrBegin();

br_error __cdecl BrEnd();

#endif
