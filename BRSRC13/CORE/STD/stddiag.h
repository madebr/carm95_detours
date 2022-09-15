#ifndef _STDDIAG_H_
#define _STDDIAG_H_

#include "br_types.h"

extern br_diaghandler * hookvar_BrStdioDiagHandler ; // addr: 00530168
extern br_diaghandler ** hookvar__BrDefaultDiagHandler ; // addr: 00530174

void BrStdioWarning(char *message);

void BrStdioFailure(char *message);

#endif
