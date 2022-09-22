#ifndef _FWSETUP_H_
#define _FWSETUP_H_

#include "br_types.h"

// extern br_resource_class(* hookvar_resourceClasses__fwsetup )[25]; // suffix added to avoid duplicate symbol
extern char *(* hookvar_namePointers_BRCORE1 )[185]; // addr: 005261B8
// extern br_uint_16(* hookvar_nameOrdinals_BRCORE1 )[185];
extern void *(* hookvar_functionPointers_BRCORE1 )[185]; // addr: 00526618
extern br_image * hookvar_Image_BRCORE1 ; // addr: 00526900
extern br_framework_state * hookvar_fw ; // addr: 00552610

br_error __stdcall BrFwBegin();

br_error __stdcall BrFwEnd();

br_diaghandler* __cdecl BrDiagHandlerSet(br_diaghandler *newdh);

br_filesystem* __cdecl BrFilesystemSet(br_filesystem *newfs);

br_allocator* __cdecl BrAllocatorSet(br_allocator *newal);

#endif
