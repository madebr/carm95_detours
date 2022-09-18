#ifndef _PRINTF_H_
#define _PRINTF_H_

#include "br_types.h"


extern br_int_32(__cdecl*BrSprintf)(char *, char *);
#if 0
br_int_32 BrSprintf_do_not_use(char *buf, char *fmt);
#endif

extern br_int_32(__cdecl*BrSprintfN)(char *, br_size_t, char *);
#if 0
br_int_32 BrSprintfN_do_not_use(char *buf, br_size_t buf_size, char *fmt);
#endif

extern int(__cdecl*BrLogPrintf)(char *);
#if 0
int BrLogPrintf_do_not_use(char *fmt);
#endif

extern br_int_32(__cdecl*BrSScanf)(char *, char *);
#if 0
br_int_32 BrSScanf_do_not_use(char *str, char *fmt);
#endif

#endif
