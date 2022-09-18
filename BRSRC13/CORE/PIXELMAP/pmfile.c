#include "pmfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_file_enum_member(* hookvar_pixelmap_type_FM )[15] = (void*)0x005216c8;
br_file_enum * hookvar_pixelmap_type_F  = (void*)0x00521740;
br_file_struct_member(* hookvar_br_old_pixelmap_FM )[7] = (void*)0x00521748;
br_file_struct_member(* hookvar_br_pixelmap_FM )[8] = (void*)0x005217b8;
br_file_struct * hookvar_br_pixelmap_F  = (void*)0x00521838;
br_file_struct * hookvar_br_old_pixelmap_F  = (void*)0x00521848;
br_chunks_table_entry(* hookvar_PixelmapLoadEntries )[5] = (void*)0x00521858;
br_chunks_table * hookvar_PixelmapLoadTable  = (void*)0x00521898;

int FopWrite_PIXELMAP(br_datafile *df, br_pixelmap *pixelmap) {
    br_pixelmap pmap;
    LOG_TRACE("(%p, %p)", df, pixelmap);

    (void)df;
    (void)pixelmap;
    (void)pmap;

    NOT_IMPLEMENTED();
}

static int(__stdcall*original_FopRead_OLD_PIXELMAP)(br_datafile *, br_uint_32, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32))0x004ca6a0;
CARM95_HOOK_FUNCTION(original_FopRead_OLD_PIXELMAP, FopRead_OLD_PIXELMAP)
int __stdcall FopRead_OLD_PIXELMAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_pixelmap *pp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)pp;

    return original_FopRead_OLD_PIXELMAP(df, id, length, count);
}

static int(__stdcall*original_FopRead_PIXELMAP)(br_datafile *, br_uint_32, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32))0x004ca700;
CARM95_HOOK_FUNCTION(original_FopRead_PIXELMAP, FopRead_PIXELMAP)
int __stdcall FopRead_PIXELMAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_pixelmap *pp;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)pp;

    return original_FopRead_PIXELMAP(df, id, length, count);
}

int FopWrite_PIXELS(br_datafile *df, br_pixelmap *pixelmap) {
    int size;
    int bytes;
    int block_count;
    char *pixels;
    int __block0__mipSize;
    int __block0__currentMipSize;
    LOG_TRACE("(%p, %p)", df, pixelmap);

    (void)df;
    (void)pixelmap;
    (void)size;
    (void)bytes;
    (void)block_count;
    (void)pixels;
    (void)__block0__mipSize;
    (void)__block0__currentMipSize;

    NOT_IMPLEMENTED();
}

static int(__stdcall*original_FopRead_PIXELS)(br_datafile *, br_uint_32, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32))0x004ca760;
CARM95_HOOK_FUNCTION(original_FopRead_PIXELS, FopRead_PIXELS)
int __stdcall FopRead_PIXELS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    int icount;
    br_pixelmap *pp;
    int size;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)icount;
    (void)pp;
    (void)size;

    return original_FopRead_PIXELS(df, id, length, count);
}

int FopWrite_ADD_MAP(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    NOT_IMPLEMENTED();
}

static int(__stdcall*original_FopRead_ADD_MAP)(br_datafile *, br_uint_32, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32, br_uint_32))0x004ca7c0;
CARM95_HOOK_FUNCTION(original_FopRead_ADD_MAP, FopRead_ADD_MAP)
int __stdcall FopRead_ADD_MAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count) {
    br_pixelmap *pp;
    br_pixelmap *map;
    LOG_TRACE("(%p, %u, %u, %u)", df, id, length, count);

    (void)df;
    (void)id;
    (void)length;
    (void)count;
    (void)pp;
    (void)map;

    return original_FopRead_ADD_MAP(df, id, length, count);
}

static br_uint_32(__cdecl*original_BrPixelmapLoadMany)(char *, br_pixelmap **, br_uint_16) = (br_uint_32(__cdecl*)(char *, br_pixelmap **, br_uint_16))0x004ca7f0;
CARM95_HOOK_FUNCTION(original_BrPixelmapLoadMany, BrPixelmapLoadMany)
br_uint_32 __cdecl BrPixelmapLoadMany(char *filename, br_pixelmap **pixelmaps, br_uint_16 num) {
    br_datafile *df;
    int count;
    int r;
    LOG_TRACE("(\"%s\", %p, %u)", filename, pixelmaps, num);

    (void)filename;
    (void)pixelmaps;
    (void)num;
    (void)df;
    (void)count;
    (void)r;

    return original_BrPixelmapLoadMany(filename, pixelmaps, num);
}

static int(__stdcall*original_WritePixelmap)(br_pixelmap *, br_datafile *) = (int(__stdcall*)(br_pixelmap *, br_datafile *))0x004caac0;
CARM95_HOOK_FUNCTION(original_WritePixelmap, WritePixelmap)
int __stdcall WritePixelmap(br_pixelmap *pp, br_datafile *df) {
    LOG_TRACE("(%p, %p)", pp, df);

    (void)pp;
    (void)df;

    return original_WritePixelmap(pp, df);
}

static br_uint_32(__cdecl*original_BrPixelmapSaveMany)(char *, br_pixelmap **, br_uint_16) = (br_uint_32(__cdecl*)(char *, br_pixelmap **, br_uint_16))0x004ca86b;
CARM95_HOOK_FUNCTION(original_BrPixelmapSaveMany, BrPixelmapSaveMany)
br_uint_32 __cdecl BrPixelmapSaveMany(char *filename, br_pixelmap **pixelmaps, br_uint_16 num) {
    br_datafile *df;
    int i;
    LOG_TRACE("(\"%s\", %p, %u)", filename, pixelmaps, num);

    (void)filename;
    (void)pixelmaps;
    (void)num;
    (void)df;
    (void)i;

    return original_BrPixelmapSaveMany(filename, pixelmaps, num);
}

static br_pixelmap *(__cdecl*original_BrPixelmapLoad)(char *) = (br_pixelmap *(__cdecl*)(char *))0x004cac60;
CARM95_HOOK_FUNCTION(original_BrPixelmapLoad, BrPixelmapLoad)
br_pixelmap* __cdecl BrPixelmapLoad(char *filename) {
    br_pixelmap *ptr;
    LOG_TRACE("(\"%s\")", filename);

    (void)filename;
    (void)ptr;

    return original_BrPixelmapLoad(filename);
}

static br_uint_32(__cdecl*original_BrPixelmapSave)(char *, br_pixelmap *) = (br_uint_32(__cdecl*)(char *, br_pixelmap *))0x004cace0;
CARM95_HOOK_FUNCTION(original_BrPixelmapSave, BrPixelmapSave)
br_uint_32 __cdecl BrPixelmapSave(char *filename, br_pixelmap *ptr) {
    LOG_TRACE("(\"%s\", %p)", filename, ptr);

    (void)filename;
    (void)ptr;

    return original_BrPixelmapSave(filename, ptr);
}

