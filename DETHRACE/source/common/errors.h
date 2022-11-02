#ifndef _ERRORS_H_
#define _ERRORS_H_

#include "br_types.h"
#include "dr_types.h"

extern char *(* hookvar_gError_messages )[126]; // addr: 005120A0
extern int * hookvar_gError_code ; // addr: 0051D424
// extern char ** hookvar_gPalette_copy__errors ; // suffix added to avoid duplicate symbol
// extern int * hookvar_gPixel_buffer_size__errors ; // suffix added to avoid duplicate symbol
// extern int * hookvar_gMouse_was_started__errors ; // suffix added to avoid duplicate symbol
// extern char ** hookvar_gPixels_copy__errors ; // suffix added to avoid duplicate symbol

extern void(__cdecl*FatalError)(int);
#if 0
void FatalError_do_not_use(int pStr_index);
#endif

extern void(__cdecl*NonFatalError)(int);
#if 0
void NonFatalError_do_not_use(int pStr_index);
#endif

void __cdecl CloseDiagnostics();

void __cdecl OpenDiagnostics();

extern void(__cdecl*dr_dprintf)(char *fmt_string, ...);
#if 0
void dr_dprintf(char *fmt_string);
#endif

int __cdecl DoErrorInterface(int pMisc_text_index);

#endif
