#ifndef _STDDIAG_H_
#define _STDDIAG_H_

#include "br_types.h"

extern br_diaghandler * hookvar_BrStdioDiagHandler ; // addr: 00530168
extern br_diaghandler ** hookvar__BrDefaultDiagHandler ; // addr: 00530174

void __cdecl BrStdioWarning(char *message);

void __cdecl BrStdioFailure(char *message);

#endif
