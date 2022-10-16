#include "devsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_pixelmap ** hookvar_last_begin_screen  = (void*)0x00541b08;

static br_pixelmap *(__cdecl*original_BrDevLastBeginQuery)() = (br_pixelmap *(__cdecl*)())0x004dff60;
CARM95_HOOK_FUNCTION(original_BrDevLastBeginQuery, BrDevLastBeginQuery)
br_pixelmap* __cdecl BrDevLastBeginQuery() {
    LOG_TRACE("()");


    return original_BrDevLastBeginQuery();
}

static void(__stdcall*original_BrDevLastBeginSet)(br_pixelmap *) = (void(__stdcall*)(br_pixelmap *))0x004dff70;
CARM95_HOOK_FUNCTION(original_BrDevLastBeginSet, BrDevLastBeginSet)
void __stdcall BrDevLastBeginSet(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    original_BrDevLastBeginSet(pm);
}

br_error(__stdcall*BrDevBeginVar)(br_pixelmap **, char *) = (br_error(__stdcall*)(br_pixelmap **, char *))0x004dff80;
br_error BrDevBeginVar_do_not_use(br_pixelmap **ppm, char *setup_string) {
    va_list vl;
    br_uint_32 i;
    br_uint_32 n;
    br_token_value tv[64];
    LOG_TRACE("(%p, \"%s\")", ppm, setup_string);

    (void)ppm;
    (void)setup_string;
    (void)vl;
    (void)i;
    (void)n;
    (void)tv;

    NOT_IMPLEMENTED();
}

static br_error(__cdecl*original_BrDevBegin)(br_pixelmap **, char *) = (br_error(__cdecl*)(br_pixelmap **, char *))0x004e0140;
CARM95_HOOK_FUNCTION(original_BrDevBegin, BrDevBegin)
br_error __cdecl BrDevBegin(br_pixelmap **ppm, char *setup_string) {
    LOG_TRACE("(%p, \"%s\")", ppm, setup_string);

    (void)ppm;
    (void)setup_string;

    return original_BrDevBegin(ppm, setup_string);
}

br_error BrDevBeginTV(br_pixelmap **ppm, char *setup_string, br_token_value *setup_tv) {
    char str[512];
    char *args;
    char *devname;
    char *devargs;
    char devices_str[512];
    char *device_name;
    char *device_args;
    char *next_device;
    br_token_value args_tv[64];
    br_token_value *tv;
    br_output_facility *output_facility;
    br_device *device;
    br_pixelmap *screen;
    int i;
    int n;
    br_error r;
    LOG_TRACE("(%p, \"%s\", %p)", ppm, setup_string, setup_tv);

    (void)ppm;
    (void)setup_string;
    (void)setup_tv;
    (void)str;
    (void)args;
    (void)devname;
    (void)devargs;
    (void)devices_str;
    (void)device_name;
    (void)device_args;
    (void)next_device;
    (void)args_tv;
    (void)tv;
    (void)output_facility;
    (void)device;
    (void)screen;
    (void)i;
    (void)n;
    (void)r;

    NOT_IMPLEMENTED();
}

br_pixelmap* BrDevBeginOld(char *setup_string) {
    br_pixelmap *s;
    LOG_TRACE("(\"%s\")", setup_string);

    (void)setup_string;
    (void)s;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_BrDevEndOld)() = (void(__cdecl*)())0x004e0360;
CARM95_HOOK_FUNCTION(original_BrDevEndOld, BrDevEndOld)
void __cdecl BrDevEndOld() {
    LOG_TRACE("()");


    original_BrDevEndOld();
}

static void(__cdecl*original_BrDevPaletteSetOld)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x004e0380;
CARM95_HOOK_FUNCTION(original_BrDevPaletteSetOld, BrDevPaletteSetOld)
void __cdecl BrDevPaletteSetOld(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    original_BrDevPaletteSetOld(pm);
}

static void(__cdecl*original_BrDevPaletteSetEntryOld)(int, br_colour) = (void(__cdecl*)(int, br_colour))0x004e03a0;
CARM95_HOOK_FUNCTION(original_BrDevPaletteSetEntryOld, BrDevPaletteSetEntryOld)
void __cdecl BrDevPaletteSetEntryOld(int i, br_colour colour) {
    LOG_TRACE("(%d, %u)", i, colour);

    (void)i;
    (void)colour;

    original_BrDevPaletteSetEntryOld(i, colour);
}

static br_error(__cdecl*original_BrRendererFacilityFind)(br_renderer_facility **, br_device_pixelmap *, br_token) = (br_error(__cdecl*)(br_renderer_facility **, br_device_pixelmap *, br_token))0x004e03c0;
CARM95_HOOK_FUNCTION(original_BrRendererFacilityFind, BrRendererFacilityFind)
br_error __cdecl BrRendererFacilityFind(br_renderer_facility **prf, br_device_pixelmap *destination, br_token scalar_type) {
    br_renderer_facility *renderer_facility;
    br_error r;
    br_output_facility *ot;
    char object_name[23];
    char image_name[9];
    br_boolean scalar_is_valid;
    LOG_TRACE("(%p, %p, %d)", prf, destination, scalar_type);

    (void)prf;
    (void)destination;
    (void)scalar_type;
    (void)renderer_facility;
    (void)r;
    (void)ot;
    (void)object_name;
    (void)image_name;
    (void)scalar_is_valid;

    return original_BrRendererFacilityFind(prf, destination, scalar_type);
}

static br_error(__cdecl*original_BrPrimitiveLibraryFind)(br_primitive_library **, br_device_pixelmap *, br_token) = (br_error(__cdecl*)(br_primitive_library **, br_device_pixelmap *, br_token))0x004e0580;
CARM95_HOOK_FUNCTION(original_BrPrimitiveLibraryFind, BrPrimitiveLibraryFind)
br_error __cdecl BrPrimitiveLibraryFind(br_primitive_library **ppl, br_device_pixelmap *destination, br_token scalar_type) {
    br_primitive_library *primitive_library;
    br_error r;
    br_output_facility *ot;
    char object_name[25];
    char image_name[9];
    br_boolean scalar_is_valid;
    LOG_TRACE("(%p, %p, %d)", ppl, destination, scalar_type);

    (void)ppl;
    (void)destination;
    (void)scalar_type;
    (void)primitive_library;
    (void)r;
    (void)ot;
    (void)object_name;
    (void)image_name;
    (void)scalar_is_valid;

    return original_BrPrimitiveLibraryFind(ppl, destination, scalar_type);
}

static br_error(__cdecl*original_BrGeometryFormatFind)(br_geometry **, br_renderer *, br_renderer_facility *, br_token, br_token) = (br_error(__cdecl*)(br_geometry **, br_renderer *, br_renderer_facility *, br_token, br_token))0x004e0740;
CARM95_HOOK_FUNCTION(original_BrGeometryFormatFind, BrGeometryFormatFind)
br_error __cdecl BrGeometryFormatFind(br_geometry **pgf, br_renderer *renderer, br_renderer_facility *renderer_facility, br_token scalar_type, br_token format_type) {
    br_error r;
    br_geometry *gf;
    char object_name[21];
    char image_name[9];
    br_boolean scalar_is_valid;
    LOG_TRACE("(%p, %p, %p, %d, %d)", pgf, renderer, renderer_facility, scalar_type, format_type);

    (void)pgf;
    (void)renderer;
    (void)renderer_facility;
    (void)scalar_type;
    (void)format_type;
    (void)r;
    (void)gf;
    (void)object_name;
    (void)image_name;
    (void)scalar_is_valid;

    return original_BrGeometryFormatFind(pgf, renderer, renderer_facility, scalar_type, format_type);
}

