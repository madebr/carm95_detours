#ifndef _HSTSETUP_H_
#define _HSTSETUP_H_

#include "br_types.h"

extern char *(* hookvar_namePointers_BRHOST1 )[50]; // addr: 0052EE10
extern br_uint_16(* hookvar_nameOrdinals_BRHOST1 )[50]; // addr: 0052EED8
extern void *(* hookvar_functionPointers_BRHOST1 )[50]; // addr: 0052EF40
extern br_image * hookvar_Image_BRHOST1 ; // addr: 0052F008
extern host_info * hookvar_hostInfo ; // addr: 0052F048

void HostBegin();

void HostEnd();

br_error HostInfo(host_info *buffer, br_size_t buffersize);

#endif
