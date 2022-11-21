#ifndef _DATAFILE_H_
#define _DATAFILE_H_

#include "br_types.h"

extern int * hookvar_DatafileStackTop ; // addr: 00527C80
extern char *(* hookvar_member_type_names )[32]; // addr: 00527C88
extern char *(* hookvar_ChunkNames )[61]; // addr: 00527D08
extern br_file_primitives * hookvar__BrFilePrimsNull ; // addr: 00527E00
extern br_file_primitives * hookvar__BrFilePrimsReadBinary ; // addr: 00527E40
extern br_file_primitives * hookvar__BrFilePrimsWriteBinary ; // addr: 00527E80
extern br_file_primitives * hookvar__BrFilePrimsReadText ; // addr: 00527EC0
extern br_file_primitives * hookvar__BrFilePrimsWriteText ; // addr: 00527F00

void __stdcall DfPush(int type, void *value, int count);

void* __stdcall DfPop(int type, int *countp);

void* __stdcall DfTop(int type, int *countp);

int __cdecl DfTopType();

int __stdcall TextReadLine(br_datafile *df, char **ident, char **data);

br_uint_16 scalarTypeConvert(br_datafile *df, br_uint_16 t);

br_uint_32 __stdcall DfStructWriteBinary(br_datafile *df, br_file_struct *str, void *base);

br_uint_32 __stdcall DfStructReadBinary(br_datafile *df, br_file_struct *str, void *base);

int __stdcall DfStructSizeBinary(br_datafile *df, br_file_struct *str, void *base);

int EnumFromString(br_file_enum *e, char *str);

char* EnumToString(br_file_enum *e, int num);

br_uint_32 DfStructWriteText(br_datafile *df, br_file_struct *str, void *base);

br_uint_32 __stdcall StructWriteTextSub(br_datafile *df, br_file_struct *str, void *base, int indent);

br_uint_32 DfStructReadText(br_datafile *df, br_file_struct *str, void *base);

br_uint_32 __stdcall StructReadTextSub(br_datafile *df, br_file_struct *str, void *base);

int __stdcall DfStructSizeText(br_datafile *df, br_file_struct *str, void *base);

br_uint_32 __stdcall DfStructWriteArray(br_datafile *df, br_file_struct *str, void *base, int n);

br_uint_32 __stdcall DfStructReadArray(br_datafile *df, br_file_struct *str, void *base, int n);

int __stdcall DfChunkWriteText(br_datafile *df, br_uint_32 id, br_uint_32 length);

int __stdcall DfChunkReadText(br_datafile *df, br_uint_32 *plength);

int __stdcall DfChunkWriteBinary(br_datafile *df, br_uint_32 id, br_uint_32 length);

int __stdcall DfChunkReadBinary(br_datafile *df, br_uint_32 *plength);

void __stdcall DfCountWriteText(br_datafile *df, br_uint_32 count);

br_uint_32 __stdcall DfCountReadText(br_datafile *df);

void __stdcall DfCountWriteBinary(br_datafile *df, br_uint_32 count);

br_uint_32 __stdcall DfCountReadBinary(br_datafile *df);

int __stdcall DfCountSizeText(br_datafile *df);

int __stdcall DfCountSizeBinary(br_datafile *df);

br_uint_8* BlockWriteSetup(void *base, int block_size, int block_stride, int block_count, int size);

int __stdcall DfBlockWriteText(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size);

void* __stdcall DfBlockReadText(br_datafile *df, void *base, int *count, int size, int mtype);

int __stdcall DfBlockWriteBinary(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size);

void* __stdcall DfBlockReadBinary(br_datafile *df, void *base, int *count, int size, int mtype);

int __stdcall DfBlockSizeText(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size);

int DfBlockSizeBinary(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size);

char* __stdcall DfNameReadText(br_datafile *df, char *name);

int __stdcall DfNameWriteText(br_datafile *df, char *name);

int __stdcall DfNameSizeText(br_datafile *df, char *name);

char* __stdcall DfNameReadBinary(br_datafile *df, char *name);

int __stdcall DfNameWriteBinary(br_datafile *df, char *name);

int __stdcall DfNameSizeBinary(br_datafile *df, char *name);

int __stdcall DfSkipText(br_datafile *df, br_uint_32 length);

int __stdcall DfSkipBinary(br_datafile *df, br_uint_32 length);

int __stdcall DfChunksInterpret(br_datafile *df, br_chunks_table *table);

void __cdecl BrNullOther();

int __cdecl DfFileIdentify(br_uint_8 *magics, br_size_t n_magics);

br_datafile* __stdcall DfOpen(char *name, int write, br_token scalar_type);

void __stdcall DfClose(br_datafile *df);

int BrWriteModeSet(int mode);

#endif
