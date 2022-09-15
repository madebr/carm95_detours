#ifndef _PRINTF_H_
#define _PRINTF_H_

#include "br_types.h"


extern br_int_32(*BrSprintf)(char *, char *, ...);
br_int_32 BrSprintf_do_not_use(char *buf, char *fmt);

extern br_int_32(*BrSprintfN)(char *, br_size_t, char *, ...);
br_int_32 BrSprintfN_do_not_use(char *buf, br_size_t buf_size, char *fmt);

extern int(*BrLogPrintf)(char *, ...);
int BrLogPrintf_do_not_use(char *fmt);

extern br_int_32(*BrSScanf)(char *, char *, ...);
br_int_32 BrSScanf_do_not_use(char *str, char *fmt);

#endif
