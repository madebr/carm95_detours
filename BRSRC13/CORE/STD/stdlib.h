#ifndef _STDLIB_H_
#define _STDLIB_H_

#include "br_types.h"


int __cdecl BrMemCmp(void *s1, void *s2, size_t n);

void* __cdecl BrMemCpy(void *s1, void *s2, size_t n);

void* __cdecl BrMemSet(void *s, int c, size_t n);

char* __cdecl BrStrCat(char *s1, char *s2);

int __cdecl BrStrCmp(char *s1, char *s2);

int BrStrICmp(char *s1, char *s2);

char* __cdecl BrStrCpy(char *s1, char *s2);

br_size_t __cdecl BrStrLen(char *s);

int __cdecl BrStrNCmp(char *s1, char *s2, size_t n);

int __cdecl BrStrNICmp(char *s1, char *s2, size_t n);

char* __cdecl BrStrNCpy(char *s1, char *s2, size_t n);

char* __cdecl BrStrRChr(char *s1, char c);

#if 0
void BrAbort_do_not_use();
#endif

char* __cdecl BrGetEnv(char *name);

float __cdecl BrStrToF(char *nptr, char **endptr);

double __cdecl BrStrToD(char *nptr, char **endptr);

long __cdecl BrStrToL(char *nptr, char **endptr, int base);

unsigned long __cdecl BrStrToUL(char *nptr, char **endptr, int base);

br_boolean __cdecl BrIsAlpha(int c);

br_boolean __cdecl BrIsDigit(int c);

br_boolean __cdecl BrIsSpace(int c);

br_boolean __cdecl BrIsPrint(int c);

br_int_32 __cdecl BrVSprintf(char *buf, char *fmt, char **args);

br_int_32 __cdecl BrVSprintfN(char *buf, br_size_t buf_size, char *fmt, char **args);

br_int_32 __cdecl BrVSScanf(char *buf, char *fmt, char **args);

#endif
