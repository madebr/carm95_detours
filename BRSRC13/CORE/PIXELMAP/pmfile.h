#ifndef _PMFILE_H_
#define _PMFILE_H_

#include "br_types.h"

extern br_file_enum_member(* hookvar_pixelmap_type_FM )[15]; // addr: 005216C8
extern br_file_enum * hookvar_pixelmap_type_F ; // addr: 00521740
extern br_chunks_table_entry(* hookvar_PixelmapLoadEntries )[5]; // addr: 00521858
extern br_chunks_table * hookvar_PixelmapLoadTable ; // addr: 00521898

int FopWrite_PIXELMAP(br_datafile *df, br_pixelmap *pixelmap);

int FopRead_OLD_PIXELMAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopRead_PIXELMAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_PIXELS(br_datafile *df, br_pixelmap *pixelmap);

int FopRead_PIXELS(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

int FopWrite_ADD_MAP(br_datafile *df);

int FopRead_ADD_MAP(br_datafile *df, br_uint_32 id, br_uint_32 length, br_uint_32 count);

br_uint_32 BrPixelmapLoadMany(char *filename, br_pixelmap **pixelmaps, br_uint_16 num);

int WritePixelmap(br_pixelmap *pp, br_datafile *df);

br_uint_32 BrPixelmapSaveMany(char *filename, br_pixelmap **pixelmaps, br_uint_16 num);

br_pixelmap* BrPixelmapLoad(char *filename);

br_uint_32 BrPixelmapSave(char *filename, br_pixelmap *ptr);

#endif
