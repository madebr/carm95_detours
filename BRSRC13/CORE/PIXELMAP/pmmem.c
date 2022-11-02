#include "pmmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
struct br_tv_template_entry(* hookvar_matchTemplateEntries )[6] = (void*)0x00521ab8;
struct pm_type_info(* hookvar_pmTypeInfo )[30] = (void*)0x00505610;
struct br_tv_template_entry(* hookvar_devicePixelmapTemplateEntries )[4] = (void*)0x00505700;
struct br_device_pixelmap_dispatch * hookvar_devicePixelmapDispatch  = (void*)0x00505760;

function_hook_state_t function_hook_state_DevicePixelmapMemAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DevicePixelmapMemAllocate)
static br_device_pixelmap *(__stdcall*original_DevicePixelmapMemAllocate)(br_uint_8, br_uint_16, br_uint_16, void *, int) = (br_device_pixelmap *(__stdcall*)(br_uint_8, br_uint_16, br_uint_16, void *, int))0x004caf10;
CARM95_HOOK_FUNCTION(original_DevicePixelmapMemAllocate, DevicePixelmapMemAllocate)
br_device_pixelmap* __stdcall DevicePixelmapMemAllocate(br_uint_8 type, br_uint_16 w, br_uint_16 h, void *pixels, int flags) {
    br_device_pixelmap *pm;
    struct pm_type_info *tip;
    LOG_TRACE("(%u, %u, %u, %p, %d)", type, w, h, pixels, flags);

    (void)type;
    (void)w;
    (void)h;
    (void)pixels;
    (void)flags;
    (void)pm;
    (void)tip;

    if (function_hook_state_DevicePixelmapMemAllocate == HOOK_ENABLED) {
        assert(0 && "DevicePixelmapMemAllocate not implemented.");
        abort();
    } else {
        return original_DevicePixelmapMemAllocate(type, w, h, pixels, flags);
    }
}

function_hook_state_t function_hook_state__CheckDispatch = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__CheckDispatch)
void _CheckDispatch(br_device_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    if (function_hook_state__CheckDispatch == HOOK_ENABLED) {
        assert(0 && "_CheckDispatch not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_allocateSub = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_allocateSub)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_allocateSub)(br_device_pixelmap *, br_device_pixelmap **, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap **, br_rectangle *))0x004cb040;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_allocateSub, _M_br_device_pixelmap_mem_allocateSub)
br_error __cdecl _M_br_device_pixelmap_mem_allocateSub(br_device_pixelmap *self, br_device_pixelmap **newpm, br_rectangle *rect) {
    br_device_pixelmap *pm;
    br_rectangle out;
    LOG_TRACE("(%p, %p, %p)", self, newpm, rect);

    (void)self;
    (void)newpm;
    (void)rect;
    (void)pm;
    (void)out;

    if (function_hook_state__M_br_device_pixelmap_mem_allocateSub == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_allocateSub not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_allocateSub(self, newpm, rect);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_free = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_free)
static void(__cdecl*original__M_br_device_pixelmap_mem_free)(br_device_pixelmap *) = (void(__cdecl*)(br_device_pixelmap *))0x004cb0e0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_free, _M_br_device_pixelmap_mem_free)
void __cdecl _M_br_device_pixelmap_mem_free(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_free == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_free not implemented.");
        abort();
    } else {
        original__M_br_device_pixelmap_mem_free(self);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_identifier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_identifier)
static char *(__cdecl*original__M_br_device_pixelmap_mem_identifier)(br_device_pixelmap *) = (char *(__cdecl*)(br_device_pixelmap *))0x004cb0f0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_identifier, _M_br_device_pixelmap_mem_identifier)
char* __cdecl _M_br_device_pixelmap_mem_identifier(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_identifier == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_identifier not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_identifier(self);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_type = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_type)
static br_token(__cdecl*original__M_br_device_pixelmap_mem_type)(br_device_pixelmap *) = (br_token(__cdecl*)(br_device_pixelmap *))0x004cb100;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_type, _M_br_device_pixelmap_mem_type)
br_token __cdecl _M_br_device_pixelmap_mem_type(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_type == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_type not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_type(self);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_isType = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_isType)
static br_boolean(__cdecl*original__M_br_device_pixelmap_mem_isType)(br_device_pixelmap *, br_token) = (br_boolean(__cdecl*)(br_device_pixelmap *, br_token))0x004cb110;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_isType, _M_br_device_pixelmap_mem_isType)
br_boolean __cdecl _M_br_device_pixelmap_mem_isType(br_device_pixelmap *self, br_token t) {
    LOG_TRACE("(%p, %d)", self, t);

    (void)self;
    (void)t;

    if (function_hook_state__M_br_device_pixelmap_mem_isType == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_isType not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_isType(self, t);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_device = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_device)
struct br_device *(__cdecl*_M_br_device_pixelmap_mem_device)(br_device_pixelmap *) = (struct br_device *(__cdecl*)(br_device_pixelmap *))0x004cb130;
struct br_device* _M_br_device_pixelmap_mem_device_do_not_use(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_device == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_device_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_space = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_space)
static br_int_32(__cdecl*original__M_br_device_pixelmap_mem_space)(br_device_pixelmap *) = (br_int_32(__cdecl*)(br_device_pixelmap *))0x004cb140;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_space, _M_br_device_pixelmap_mem_space)
br_int_32 __cdecl _M_br_device_pixelmap_mem_space(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_space == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_space not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_space(self);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_queryTemplate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_queryTemplate)
static struct br_tv_template *(__cdecl*original__M_br_device_pixelmap_mem_queryTemplate)(br_device_pixelmap *) = (struct br_tv_template *(__cdecl*)(br_device_pixelmap *))0x004cb150;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_queryTemplate, _M_br_device_pixelmap_mem_queryTemplate)
struct br_tv_template* __cdecl _M_br_device_pixelmap_mem_queryTemplate(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_queryTemplate == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_queryTemplate not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_queryTemplate(self);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_validSource = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_validSource)
br_error(__cdecl*_M_br_device_pixelmap_mem_validSource)(br_device_pixelmap *, br_object *) = (br_error(__cdecl*)(br_device_pixelmap *, br_object *))0x004cb180;
br_error _M_br_device_pixelmap_mem_validSource_do_not_use(br_device_pixelmap *self, br_object *h) {
    LOG_TRACE("(%p, %p)", self, h);

    (void)self;
    (void)h;

    if (function_hook_state__M_br_device_pixelmap_mem_validSource == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_validSource_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_resize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_resize)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_resize)(br_device_pixelmap *, br_int_32, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_int_32, br_int_32))0x004cb190;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_resize, _M_br_device_pixelmap_mem_resize)
br_error __cdecl _M_br_device_pixelmap_mem_resize(br_device_pixelmap *self, br_int_32 width, br_int_32 height) {
    char *pixels;
    struct pm_type_info *tip;
    br_int_16 old_row_bytes;
    LOG_TRACE("(%p, %d, %d)", self, width, height);

    (void)self;
    (void)width;
    (void)height;
    (void)pixels;
    (void)tip;
    (void)old_row_bytes;

    if (function_hook_state__M_br_device_pixelmap_mem_resize == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_resize not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_resize(self, width, height);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_match = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_match)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_match)(br_device_pixelmap *, br_device_pixelmap **, br_token_value *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap **, br_token_value *))0x004cb290;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_match, _M_br_device_pixelmap_mem_match)
br_error __cdecl _M_br_device_pixelmap_mem_match(br_device_pixelmap *self, br_device_pixelmap **newpm, br_token_value *tv) {
    struct match_tokens mt;
    br_int_32 count;
    br_device_pixelmap *pm;
    br_int_32 bytes;
    br_int_32 r;
    LOG_TRACE("(%p, %p, %p)", self, newpm, tv);

    (void)self;
    (void)newpm;
    (void)tv;
    (void)mt;
    (void)count;
    (void)pm;
    (void)bytes;
    (void)r;

    if (function_hook_state__M_br_device_pixelmap_mem_match == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_match not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_match(self, newpm, tv);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyTo)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyTo)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cb500;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyTo, _M_br_device_pixelmap_mem_copyTo)
br_error __cdecl _M_br_device_pixelmap_mem_copyTo(br_device_pixelmap *self, br_device_pixelmap *src) {
    br_int_8 bytes;
    char *__block0__s;
    char *__block0__d;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;
    (void)bytes;
    (void)__block0__s;
    (void)__block0__d;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_copyTo == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyTo not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyTo(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyFrom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyFrom)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyFrom)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cb6f0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyFrom, _M_br_device_pixelmap_mem_copyFrom)
br_error __cdecl _M_br_device_pixelmap_mem_copyFrom(br_device_pixelmap *self, br_device_pixelmap *dest) {
    br_int_8 bytes;
    char *__block0__s;
    char *__block0__d;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %p)", self, dest);

    (void)self;
    (void)dest;
    (void)bytes;
    (void)__block0__s;
    (void)__block0__d;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_copyFrom == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyFrom not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyFrom(self, dest);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_fill = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_fill)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_fill)(br_device_pixelmap *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_uint_32))0x004cb8d0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_fill, _M_br_device_pixelmap_mem_fill)
br_error __cdecl _M_br_device_pixelmap_mem_fill(br_device_pixelmap *self, br_uint_32 colour) {
    br_int_8 bytes;
    char *__block0__d;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %u)", self, colour);

    (void)self;
    (void)colour;
    (void)bytes;
    (void)__block0__d;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_fill == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_fill not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_fill(self, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_doubleBuffer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_doubleBuffer)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_doubleBuffer)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cba30;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_doubleBuffer, _M_br_device_pixelmap_mem_doubleBuffer)
br_error __cdecl _M_br_device_pixelmap_mem_doubleBuffer(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    if (function_hook_state__M_br_device_pixelmap_mem_doubleBuffer == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_doubleBuffer not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_doubleBuffer(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cba40;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyDirty, _M_br_device_pixelmap_mem_copyDirty)
br_error __cdecl _M_br_device_pixelmap_mem_copyDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    if (function_hook_state__M_br_device_pixelmap_mem_copyDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyToDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyToDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyToDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cba50;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyToDirty, _M_br_device_pixelmap_mem_copyToDirty)
br_error __cdecl _M_br_device_pixelmap_mem_copyToDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    if (function_hook_state__M_br_device_pixelmap_mem_copyToDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyToDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyToDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyFromDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyFromDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyFromDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cba60;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyFromDirty, _M_br_device_pixelmap_mem_copyFromDirty)
br_error __cdecl _M_br_device_pixelmap_mem_copyFromDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    if (function_hook_state__M_br_device_pixelmap_mem_copyFromDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyFromDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyFromDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_fillDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_fillDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_fillDirty)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32))0x004cba70;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_fillDirty, _M_br_device_pixelmap_mem_fillDirty)
br_error __cdecl _M_br_device_pixelmap_mem_fillDirty(br_device_pixelmap *self, br_uint_32 colour, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %u, %p, %d)", self, colour, dirty, num_rects);

    (void)self;
    (void)colour;
    (void)dirty;
    (void)num_rects;

    if (function_hook_state__M_br_device_pixelmap_mem_fillDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_fillDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_fillDirty(self, colour, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_doubleBufferDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_doubleBufferDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_doubleBufferDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cba80;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_doubleBufferDirty, _M_br_device_pixelmap_mem_doubleBufferDirty)
br_error __cdecl _M_br_device_pixelmap_mem_doubleBufferDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    if (function_hook_state__M_br_device_pixelmap_mem_doubleBufferDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_doubleBufferDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_doubleBufferDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rectangleCopyTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rectangleCopyTo)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_rectangleCopyTo)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004cba90;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_rectangleCopyTo, _M_br_device_pixelmap_mem_rectangleCopyTo)
br_error __cdecl _M_br_device_pixelmap_mem_rectangleCopyTo(br_device_pixelmap *self, br_point *p, br_device_pixelmap *src, br_rectangle *r) {
    int bytes;
    br_rectangle ar;
    br_point ap;
    char *__block0__s;
    char *__block0__d;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %p, %p, %p)", self, p, src, r);

    (void)self;
    (void)p;
    (void)src;
    (void)r;
    (void)bytes;
    (void)ar;
    (void)ap;
    (void)__block0__s;
    (void)__block0__d;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_rectangleCopyTo == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rectangleCopyTo not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_rectangleCopyTo(self, p, src, r);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rectangleCopyFrom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rectangleCopyFrom)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_rectangleCopyFrom)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004cbd50;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_rectangleCopyFrom, _M_br_device_pixelmap_mem_rectangleCopyFrom)
br_error __cdecl _M_br_device_pixelmap_mem_rectangleCopyFrom(br_device_pixelmap *self, br_point *p, br_device_pixelmap *dest, br_rectangle *r) {
    int bytes;
    br_rectangle ar;
    br_point ap;
    char *__block0__s;
    char *__block0__d;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %p, %p, %p)", self, p, dest, r);

    (void)self;
    (void)p;
    (void)dest;
    (void)r;
    (void)bytes;
    (void)ar;
    (void)ap;
    (void)__block0__s;
    (void)__block0__d;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_rectangleCopyFrom == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rectangleCopyFrom not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_rectangleCopyFrom(self, p, dest, r);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyTo)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_rectangleStretchCopyTo)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *))0x004cc010;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_rectangleStretchCopyTo, _M_br_device_pixelmap_mem_rectangleStretchCopyTo)
br_error __cdecl _M_br_device_pixelmap_mem_rectangleStretchCopyTo(br_device_pixelmap *self, br_rectangle *destinationRectangle, br_device_pixelmap *src, br_rectangle *sourceRectangle) {
    LOG_TRACE("(%p, %p, %p, %p)", self, destinationRectangle, src, sourceRectangle);

    (void)self;
    (void)destinationRectangle;
    (void)src;
    (void)sourceRectangle;

    if (function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyTo == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rectangleStretchCopyTo not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_rectangleStretchCopyTo(self, destinationRectangle, src, sourceRectangle);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyFrom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyFrom)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_rectangleStretchCopyFrom)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *))0x004cc020;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_rectangleStretchCopyFrom, _M_br_device_pixelmap_mem_rectangleStretchCopyFrom)
br_error __cdecl _M_br_device_pixelmap_mem_rectangleStretchCopyFrom(br_device_pixelmap *self, br_rectangle *d, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, d, src, s);

    (void)self;
    (void)d;
    (void)src;
    (void)s;

    if (function_hook_state__M_br_device_pixelmap_mem_rectangleStretchCopyFrom == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rectangleStretchCopyFrom not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_rectangleStretchCopyFrom(self, d, src, s);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rectangleFill = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rectangleFill)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_rectangleFill)(br_device_pixelmap *, br_rectangle *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_uint_32))0x004cc030;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_rectangleFill, _M_br_device_pixelmap_mem_rectangleFill)
br_error __cdecl _M_br_device_pixelmap_mem_rectangleFill(br_device_pixelmap *self, br_rectangle *rect, br_uint_32 colour) {
    br_rectangle arect;
    br_int_8 bytes;
    br_uint_32 __block0__y;
    LOG_TRACE("(%p, %p, %u)", self, rect, colour);

    (void)self;
    (void)rect;
    (void)colour;
    (void)arect;
    (void)bytes;
    (void)__block0__y;

    if (function_hook_state__M_br_device_pixelmap_mem_rectangleFill == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rectangleFill not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_rectangleFill(self, rect, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_pixelSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_pixelSet)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_pixelSet)(br_device_pixelmap *, br_point *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_uint_32))0x004cc200;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_pixelSet, _M_br_device_pixelmap_mem_pixelSet)
br_error __cdecl _M_br_device_pixelmap_mem_pixelSet(br_device_pixelmap *self, br_point *p, br_uint_32 colour) {
    br_point ap;
    br_int_8 bytes;
    LOG_TRACE("(%p, %p, %u)", self, p, colour);

    (void)self;
    (void)p;
    (void)colour;
    (void)ap;
    (void)bytes;

    if (function_hook_state__M_br_device_pixelmap_mem_pixelSet == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_pixelSet not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_pixelSet(self, p, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_line = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_line)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_line)(br_device_pixelmap *, br_point *, br_point *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_point *, br_uint_32))0x004cc290;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_line, _M_br_device_pixelmap_mem_line)
br_error __cdecl _M_br_device_pixelmap_mem_line(br_device_pixelmap *self, br_point *s, br_point *e, br_uint_32 colour) {
    int dx;
    int dy;
    int incr1;
    int incr2;
    int D;
    int x;
    int y;
    int xend;
    int c;
    int pixels_left;
    int x1;
    int y1;
    int sign_x;
    int sign_y;
    int step;
    int reverse;
    int i;
    char *dest;
    int bytes;
    br_point as;
    br_point ae;
    LOG_TRACE("(%p, %p, %p, %u)", self, s, e, colour);

    (void)self;
    (void)s;
    (void)e;
    (void)colour;
    (void)dx;
    (void)dy;
    (void)incr1;
    (void)incr2;
    (void)D;
    (void)x;
    (void)y;
    (void)xend;
    (void)c;
    (void)pixels_left;
    (void)x1;
    (void)y1;
    (void)sign_x;
    (void)sign_y;
    (void)step;
    (void)reverse;
    (void)i;
    (void)dest;
    (void)bytes;
    (void)as;
    (void)ae;

    if (function_hook_state__M_br_device_pixelmap_mem_line == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_line not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_line(self, s, e, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_copyBits = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_copyBits)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_copyBits)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32))0x004cd850;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_copyBits, _M_br_device_pixelmap_mem_copyBits)
br_error __cdecl _M_br_device_pixelmap_mem_copyBits(br_device_pixelmap *self, br_point *point, br_uint_8 *src, br_uint_16 s_stride, br_rectangle *bit_rect, br_uint_32 colour) {
    int bytes;
    int bit;
    br_rectangle ar;
    br_point ap;
    LOG_TRACE("(%p, %p, %p, %u, %p, %u)", self, point, src, s_stride, bit_rect, colour);

    (void)self;
    (void)point;
    (void)src;
    (void)s_stride;
    (void)bit_rect;
    (void)colour;
    (void)bytes;
    (void)bit;
    (void)ar;
    (void)ap;

    if (function_hook_state__M_br_device_pixelmap_mem_copyBits == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_copyBits not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_copyBits(self, point, src, s_stride, bit_rect, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_pixelQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_pixelQuery)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_pixelQuery)(br_device_pixelmap *, br_uint_32 *, br_point *) = (br_error(__cdecl*)(br_device_pixelmap *, br_uint_32 *, br_point *))0x004cd920;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_pixelQuery, _M_br_device_pixelmap_mem_pixelQuery)
br_error __cdecl _M_br_device_pixelmap_mem_pixelQuery(br_device_pixelmap *self, br_uint_32 *pcolour, br_point *p) {
    br_point ap;
    br_int_8 bytes;
    LOG_TRACE("(%p, %p, %p)", self, pcolour, p);

    (void)self;
    (void)pcolour;
    (void)p;
    (void)ap;
    (void)bytes;

    if (function_hook_state__M_br_device_pixelmap_mem_pixelQuery == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_pixelQuery not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_pixelQuery(self, pcolour, p);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_pixelAddressQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_pixelAddressQuery)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_pixelAddressQuery)(br_device_pixelmap *, void **, br_uint_32 *, br_point *) = (br_error(__cdecl*)(br_device_pixelmap *, void **, br_uint_32 *, br_point *))0x004cd9b0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_pixelAddressQuery, _M_br_device_pixelmap_mem_pixelAddressQuery)
br_error __cdecl _M_br_device_pixelmap_mem_pixelAddressQuery(br_device_pixelmap *self, void **pptr, br_uint_32 *pqual, br_point *p) {
    br_int_8 bytes;
    br_point ap;
    LOG_TRACE("(%p, %p, %p, %p)", self, pptr, pqual, p);

    (void)self;
    (void)pptr;
    (void)pqual;
    (void)p;
    (void)bytes;
    (void)ap;

    if (function_hook_state__M_br_device_pixelmap_mem_pixelAddressQuery == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_pixelAddressQuery not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_pixelAddressQuery(self, pptr, pqual, p);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_pixelAddressSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_pixelAddressSet)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_pixelAddressSet)(br_device_pixelmap *, void *, br_uint_32 *) = (br_error(__cdecl*)(br_device_pixelmap *, void *, br_uint_32 *))0x004cda40;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_pixelAddressSet, _M_br_device_pixelmap_mem_pixelAddressSet)
br_error __cdecl _M_br_device_pixelmap_mem_pixelAddressSet(br_device_pixelmap *self, void *ptr, br_uint_32 *qual) {
    LOG_TRACE("(%p, %p, %p)", self, ptr, qual);

    (void)self;
    (void)ptr;
    (void)qual;

    if (function_hook_state__M_br_device_pixelmap_mem_pixelAddressSet == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_pixelAddressSet not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_pixelAddressSet(self, ptr, qual);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_originSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_originSet)
static br_error(__cdecl*original__M_br_device_pixelmap_mem_originSet)(br_device_pixelmap *, br_point *) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *))0x004cda60;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_mem_originSet, _M_br_device_pixelmap_mem_originSet)
br_error __cdecl _M_br_device_pixelmap_mem_originSet(br_device_pixelmap *self, br_point *p) {
    LOG_TRACE("(%p, %p)", self, p);

    (void)self;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_mem_originSet == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_originSet not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_mem_originSet(self, p);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rowSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rowSize)
br_error(__cdecl*_M_br_device_pixelmap_mem_rowSize)(br_device_pixelmap *, br_size_t *) = (br_error(__cdecl*)(br_device_pixelmap *, br_size_t *))0x004cda80;
br_error _M_br_device_pixelmap_mem_rowSize_do_not_use(br_device_pixelmap *self, br_size_t *sizep) {
    LOG_TRACE("(%p, %p)", self, sizep);

    (void)self;
    (void)sizep;

    if (function_hook_state__M_br_device_pixelmap_mem_rowSize == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rowSize_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rowQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rowQuery)
br_error(__cdecl*_M_br_device_pixelmap_mem_rowQuery)(br_device_pixelmap *, void *, br_size_t, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, void *, br_size_t, br_int_32))0x004cdaa0;
br_error _M_br_device_pixelmap_mem_rowQuery_do_not_use(br_device_pixelmap *self, void *buffer, br_size_t buffer_size, br_int_32 row) {
    LOG_TRACE("(%p, %p, %u, %d)", self, buffer, buffer_size, row);

    (void)self;
    (void)buffer;
    (void)buffer_size;
    (void)row;

    if (function_hook_state__M_br_device_pixelmap_mem_rowQuery == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rowQuery_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_rowSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_rowSet)
br_error(__cdecl*_M_br_device_pixelmap_mem_rowSet)(br_device_pixelmap *, void *, br_size_t, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, void *, br_size_t, br_int_32))0x004cda90;
br_error _M_br_device_pixelmap_mem_rowSet_do_not_use(br_device_pixelmap *self, void *buffer, br_size_t buffer_size, br_int_32 row) {
    LOG_TRACE("(%p, %p, %u, %d)", self, buffer, buffer_size, row);

    (void)self;
    (void)buffer;
    (void)buffer_size;
    (void)row;

    if (function_hook_state__M_br_device_pixelmap_mem_rowSet == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_rowSet_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_flush = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_flush)
br_error(__cdecl*_M_br_device_pixelmap_mem_flush)(struct br_device_pixelmap *) = (br_error(__cdecl*)(struct br_device_pixelmap *))0x004cdab0;
br_error _M_br_device_pixelmap_mem_flush_do_not_use(struct br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_flush == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_flush_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_synchronise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_synchronise)
br_error(__cdecl*_M_br_device_pixelmap_mem_synchronise)(struct br_device_pixelmap *, br_token, br_boolean) = (br_error(__cdecl*)(struct br_device_pixelmap *, br_token, br_boolean))0x004cdac0;
br_error _M_br_device_pixelmap_mem_synchronise_do_not_use(struct br_device_pixelmap *self, br_token sync_type, br_boolean block) {
    LOG_TRACE("(%p, %d, %d)", self, sync_type, block);

    (void)self;
    (void)sync_type;
    (void)block;

    if (function_hook_state__M_br_device_pixelmap_mem_synchronise == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_synchronise_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_directLock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_directLock)
br_error(__cdecl*_M_br_device_pixelmap_mem_directLock)(struct br_device_pixelmap *, br_boolean) = (br_error(__cdecl*)(struct br_device_pixelmap *, br_boolean))0x004cdad0;
br_error _M_br_device_pixelmap_mem_directLock_do_not_use(struct br_device_pixelmap *self, br_boolean block) {
    LOG_TRACE("(%p, %d)", self, block);

    (void)self;
    (void)block;

    if (function_hook_state__M_br_device_pixelmap_mem_directLock == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_directLock_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_mem_directUnlock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_mem_directUnlock)
br_error(__cdecl*_M_br_device_pixelmap_mem_directUnlock)(struct br_device_pixelmap *) = (br_error(__cdecl*)(struct br_device_pixelmap *))0x004cdae0;
br_error _M_br_device_pixelmap_mem_directUnlock_do_not_use(struct br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_mem_directUnlock == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_mem_directUnlock_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

