#ifndef _STDFILE_H_
#define _STDFILE_H_

#include "br_types.h"

extern br_filesystem * hookvar_BrStdioFilesystem ; // addr: 005300E0
extern br_filesystem ** hookvar__BrDefaultFilesystem ; // addr: 00530114

br_uint_32 BrStdioAttributes();

void* __cdecl BrStdioOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *identify, int *mode_result);

void* __cdecl BrStdioOpenWrite(char *name, int mode);

void __cdecl BrStdioClose(void *f);

int __cdecl BrStdioEof(void *f);

int __cdecl BrStdioGetChar(void *f);

void __cdecl BrStdioPutChar(int c, void *f);

br_size_t __cdecl BrStdioRead(void *buf, br_size_t size, unsigned int n, void *f);

br_size_t __cdecl BrStdioWrite(void *buf, br_size_t size, unsigned int n, void *f);

br_size_t __cdecl BrStdioGetLine(char *buf, br_size_t buf_len, void *f);

void __cdecl BrStdioPutLine(char *buf, void *f);

void __cdecl BrStdioAdvance(br_size_t count, void *f);

#endif
