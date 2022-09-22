#ifndef _PMSETUP_H_
#define _PMSETUP_H_

#include "br_types.h"

extern char *(* hookvar_namePointers_BRPMAP1 )[77]; // addr: 00522D60
extern br_uint_16(* hookvar_nameOrdinals_BRPMAP1 )[77]; // addr: 00522E98
extern void *(* hookvar_functionPointers_BRPMAP1 )[77]; // addr: 00522F38
extern br_image * hookvar_Image_BRPMAP1 ; // addr: 00523070
// extern br_resource_class(* hookvar_resourceClasses__pmsetup )[2]; // suffix added to avoid duplicate symbol

void __stdcall BrPixelmapBegin();

void __stdcall BrPixelmapEnd();

#endif
