#include "genfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_file_enum_member(* hookvar_file_type_FM )[10] = (void*)0x00527b20;
br_file_enum * hookvar_file_type_F  = (void*)0x00527b70;
br_file_struct_member(* hookvar_file_info_FM )[2] = (void*)0x00527b78;
br_file_struct * hookvar_file_info_F  = (void*)0x00527b98;

static int(__stdcall*original_FopRead_END)(br_datafile *, br_uint_32, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32))0x004e0a20;
CARM95_HOOK_FUNCTION(original_FopRead_END, FopRead_END)
int __stdcall FopRead_END(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;

    return original_FopRead_END(df, id, length, count);
}

static int(__stdcall*original_FopWrite_END)(br_datafile *) = (int(__stdcall*)(br_datafile *))0x004e0a30;
CARM95_HOOK_FUNCTION(original_FopWrite_END, FopWrite_END)
int __stdcall FopWrite_END(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    return original_FopWrite_END(df);
}

static int(__stdcall*original_FopWrite_FILE_INFO)(br_datafile *, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32))0x004e0a50;
CARM95_HOOK_FUNCTION(original_FopWrite_FILE_INFO, FopWrite_FILE_INFO)
int __stdcall FopWrite_FILE_INFO(br_datafile *df, br_uint_32 type) {
    struct file_info fi;
    LOG_TRACE("(%p, %u)", df, type);

    (void)df;
    (void)type;
    (void)fi;

    return original_FopWrite_FILE_INFO(df, type);
}

