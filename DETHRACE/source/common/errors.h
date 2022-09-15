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

extern void(*FatalError)(int, ...);
void FatalError_do_not_use(int pStr_index);

extern void(*NonFatalError)(int, ...);
void NonFatalError_do_not_use(int pStr_index);

void CloseDiagnostics();

void OpenDiagnostics();

void dprintf(char *fmt_string);

int DoErrorInterface(int pMisc_text_index);

#endif
