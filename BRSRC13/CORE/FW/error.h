#ifndef _ERROR_H_
#define _ERROR_H_

#include "br_types.h"


br_error __cdecl BrLastErrorGet(void **valuep);

void __cdecl BrLastErrorSet(br_error type, void *value);

#endif
