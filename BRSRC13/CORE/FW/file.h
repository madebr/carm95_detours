#ifndef _FILE_H_
#define _FILE_H_

#include "br_types.h"


void _BrFileFree(void *res, br_uint_8 res_class, br_size_t size);

br_uint_32 __stdcall BrFileAttributes();

void* __cdecl BrFileOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *mode_test, int *mode_result);

void* __cdecl BrFileOpenWrite(char *name, int mode);

void __cdecl BrFileClose(void *f);

int __cdecl BrFileEof(void *f);

int __cdecl BrFileGetChar(void *f);

void __cdecl BrFilePutChar(int c, void *f);

int __cdecl BrFileRead(void *buf, int size, int n, void *f);

int __cdecl BrFileWrite(void *buf, int size, int n, void *f);

int __cdecl BrFileGetLine(char *buf, br_size_t buf_len, void *f);

void __cdecl BrFilePutLine(char *buf, void *f);

void __cdecl BrFileAdvance(long count, void *f);

extern int(__cdecl*BrFilePrintf)(void *, char *);
#if 0
int BrFilePrintf_do_not_use(void *f, char *fmt);
#endif

#endif
