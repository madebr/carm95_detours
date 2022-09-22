#ifndef _DIAG_H_
#define _DIAG_H_

#include "br_types.h"

// extern char(* hookvar__diag_scratch )[128];

extern void(__cdecl*BrFailure)(char *);
#if 0
void BrFailure_do_not_use(char *s);
#endif

extern void(__cdecl*BrWarning)(char *);
#if 0
void BrWarning_do_not_use(char *s);
#endif

extern void(__cdecl*BrFatal)(char *, int, char *);
#if 0
void BrFatal_do_not_use(char *name, int line, char *s);
#endif

void __stdcall _BrAssert(char *condition, char *file, unsigned int line);

void __cdecl _BrUAssert(char *condition, char *file, unsigned int line);

#endif
