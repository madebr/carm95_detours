#include "loader.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_image *(*original_ImageLoad)(char *, ...) = (br_image *(*)(char *, ...))0x004e8bb0;
CARM95_HOOK_FUNCTION(original_ImageLoad, ImageLoad)
br_image* ImageLoad(char *name) {
    void *fh;
    int mode;
    struct msdos_header dos_header;
    struct coff_header coff_header;
    struct nt_optional_header nt_header;
    struct section_header section_header;
    br_uint_32 pe;
    br_image *img;
    br_uint_8 *arena_base;
    int arena_size;
    int arena_align;
    int i;
    br_uint_32 offset;
    unsigned int n;
    struct export_directory *__block0__ed;
    struct import_directory *__block1__id;
    void **__block1__at;
    br_uint_32 *__block1__lt;
    br_image *__block1__import_img;
    basereloc_header *__block2__header;
    br_uint_16 *__block2__entry;
    br_uint_8 *__block2__fixup;
    br_int_32 __block2__delta;
    br_int_16 __block2__delta_h;
    br_int_16 __block2__delta_l;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)fh;
    (void)mode;
    (void)dos_header;
    (void)coff_header;
    (void)nt_header;
    (void)section_header;
    (void)pe;
    (void)img;
    (void)arena_base;
    (void)arena_size;
    (void)arena_align;
    (void)i;
    (void)offset;
    (void)n;

    return original_ImageLoad(name);
}

