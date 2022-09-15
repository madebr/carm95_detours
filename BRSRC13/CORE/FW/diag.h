#ifndef _DIAG_H_
#define _DIAG_H_

#include "br_types.h"

// extern char(* hookvar__diag_scratch )[128];

extern void(*BrFailure)(char *, ...);
void BrFailure_do_not_use(char *s);

extern void(*BrWarning)(char *, ...);
void BrWarning_do_not_use(char *s);

extern void(*BrFatal)(char *, int, char *, ...);
void BrFatal_do_not_use(char *name, int line, char *s);

void _BrAssert(char *condition, char *file, unsigned int line);

void _BrUAssert(char *condition, char *file, unsigned int line);

#endif
