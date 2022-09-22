#ifndef _GENFILE_H_
#define _GENFILE_H_

#include "br_types.h"

extern br_file_enum_member(* hookvar_file_type_FM )[10]; // addr: 00527B20
extern br_file_enum * hookvar_file_type_F ; // addr: 00527B70

int __stdcall FopRead_END(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int __stdcall FopWrite_END(br_datafile *df);

int __stdcall FopWrite_FILE_INFO(br_datafile *df, br_uint_32 type);

#endif
