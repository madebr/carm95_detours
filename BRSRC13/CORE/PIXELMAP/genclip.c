#include "genclip.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_PixelmapPointClip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PixelmapPointClip)
static br_clip_result(__cdecl*original_PixelmapPointClip)(br_point *, br_point *, br_pixelmap *) = (br_clip_result(__cdecl*)(br_point *, br_point *, br_pixelmap *))0x004d0470;
CARM95_HOOK_FUNCTION(original_PixelmapPointClip, PixelmapPointClip)
br_clip_result __cdecl PixelmapPointClip(br_point *out, br_point *in, br_pixelmap *pm) {
    LOG_TRACE("(%p, %p, %p)", out, in, pm);

    (void)out;
    (void)in;
    (void)pm;

    if (function_hook_state_PixelmapPointClip == HOOK_ENABLED) {
        assert(0 && "PixelmapPointClip not implemented.");
        abort();
    } else {
        return original_PixelmapPointClip(out, in, pm);
    }
}

function_hook_state_t function_hook_state_PixelmapLineClip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PixelmapLineClip)
static br_clip_result(__cdecl*original_PixelmapLineClip)(br_point *, br_point *, br_point *, br_point *, br_pixelmap *) = (br_clip_result(__cdecl*)(br_point *, br_point *, br_point *, br_point *, br_pixelmap *))0x004d04d0;
CARM95_HOOK_FUNCTION(original_PixelmapLineClip, PixelmapLineClip)
br_clip_result __cdecl PixelmapLineClip(br_point *s_out, br_point *e_out, br_point *s_in, br_point *e_in, br_pixelmap *pm) {
    int temp;
    br_int_32 w;
    br_int_32 h;
    br_int_32 x1;
    br_int_32 x2;
    br_int_32 y1;
    br_int_32 y2;
    int __block0____temp__;
    int __block1____temp__;
    LOG_TRACE("(%p, %p, %p, %p, %p)", s_out, e_out, s_in, e_in, pm);

    (void)s_out;
    (void)e_out;
    (void)s_in;
    (void)e_in;
    (void)pm;
    (void)temp;
    (void)w;
    (void)h;
    (void)x1;
    (void)x2;
    (void)y1;
    (void)y2;
    (void)__block0____temp__;
    (void)__block1____temp__;

    if (function_hook_state_PixelmapLineClip == HOOK_ENABLED) {
        assert(0 && "PixelmapLineClip not implemented.");
        abort();
    } else {
        return original_PixelmapLineClip(s_out, e_out, s_in, e_in, pm);
    }
}

function_hook_state_t function_hook_state_PixelmapRectangleClip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PixelmapRectangleClip)
static br_clip_result(__cdecl*original_PixelmapRectangleClip)(br_rectangle *, br_rectangle *, br_pixelmap *) = (br_clip_result(__cdecl*)(br_rectangle *, br_rectangle *, br_pixelmap *))0x004d06c0;
CARM95_HOOK_FUNCTION(original_PixelmapRectangleClip, PixelmapRectangleClip)
br_clip_result __cdecl PixelmapRectangleClip(br_rectangle *out, br_rectangle *in, br_pixelmap *pm) {
    LOG_TRACE("(%p, %p, %p)", out, in, pm);

    (void)out;
    (void)in;
    (void)pm;

    if (function_hook_state_PixelmapRectangleClip == HOOK_ENABLED) {
        assert(0 && "PixelmapRectangleClip not implemented.");
        abort();
    } else {
        return original_PixelmapRectangleClip(out, in, pm);
    }
}

function_hook_state_t function_hook_state_PixelmapRectangleClipTwo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PixelmapRectangleClipTwo)
static br_clip_result(__cdecl*original_PixelmapRectangleClipTwo)(br_rectangle *, br_point *, br_rectangle *, br_point *, br_pixelmap *, br_pixelmap *) = (br_clip_result(__cdecl*)(br_rectangle *, br_point *, br_rectangle *, br_point *, br_pixelmap *, br_pixelmap *))0x004d0790;
CARM95_HOOK_FUNCTION(original_PixelmapRectangleClipTwo, PixelmapRectangleClipTwo)
br_clip_result __cdecl PixelmapRectangleClipTwo(br_rectangle *r_out, br_point *p_out, br_rectangle *r_in, br_point *p_in, br_pixelmap *pm_dst, br_pixelmap *pm_src) {
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", r_out, p_out, r_in, p_in, pm_dst, pm_src);

    (void)r_out;
    (void)p_out;
    (void)r_in;
    (void)p_in;
    (void)pm_dst;
    (void)pm_src;

    if (function_hook_state_PixelmapRectangleClipTwo == HOOK_ENABLED) {
        assert(0 && "PixelmapRectangleClipTwo not implemented.");
        abort();
    } else {
        return original_PixelmapRectangleClipTwo(r_out, p_out, r_in, p_in, pm_dst, pm_src);
    }
}

function_hook_state_t function_hook_state_PixelmapCopyBitsClip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PixelmapCopyBitsClip)
static br_clip_result(__cdecl*original_PixelmapCopyBitsClip)(br_rectangle *, br_point *, br_rectangle *, br_point *, br_pixelmap *) = (br_clip_result(__cdecl*)(br_rectangle *, br_point *, br_rectangle *, br_point *, br_pixelmap *))0x004d0980;
CARM95_HOOK_FUNCTION(original_PixelmapCopyBitsClip, PixelmapCopyBitsClip)
br_clip_result __cdecl PixelmapCopyBitsClip(br_rectangle *r_out, br_point *p_out, br_rectangle *r_in, br_point *p_in, br_pixelmap *pm) {
    LOG_TRACE("(%p, %p, %p, %p, %p)", r_out, p_out, r_in, p_in, pm);

    (void)r_out;
    (void)p_out;
    (void)r_in;
    (void)p_in;
    (void)pm;

    if (function_hook_state_PixelmapCopyBitsClip == HOOK_ENABLED) {
        assert(0 && "PixelmapCopyBitsClip not implemented.");
        abort();
    } else {
        return original_PixelmapCopyBitsClip(r_out, p_out, r_in, p_in, pm);
    }
}

