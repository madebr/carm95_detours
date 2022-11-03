#include "custsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrModelToScreenQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrModelToScreenQuery, function_hook_state_BrModelToScreenQuery)
static void(__cdecl*original_BrModelToScreenQuery)(br_matrix4 *) = (void(__cdecl*)(br_matrix4 *))0x004de500;
CARM95_HOOK_FUNCTION(original_BrModelToScreenQuery, BrModelToScreenQuery)
void __cdecl BrModelToScreenQuery(br_matrix4 *dest) {
    br_uint_32 dummy;
    br_matrix4 v2s;
    br_matrix34 m2v;
    LOG_TRACE("(%p)", dest);

    (void)dest;
    (void)dummy;
    (void)v2s;
    (void)m2v;

    if (function_hook_state_BrModelToScreenQuery == HOOK_ENABLED) {
        assert(0 && "BrModelToScreenQuery not implemented.");
        abort();
    } else {
        original_BrModelToScreenQuery(dest);
    }
}

function_hook_state_t function_hook_state_BrModelToViewQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrModelToViewQuery, function_hook_state_BrModelToViewQuery)
static void(__cdecl*original_BrModelToViewQuery)(br_matrix34 *) = (void(__cdecl*)(br_matrix34 *))0x004de570;
CARM95_HOOK_FUNCTION(original_BrModelToViewQuery, BrModelToViewQuery)
void __cdecl BrModelToViewQuery(br_matrix34 *dest) {
    br_uint_32 dummy;
    LOG_TRACE("(%p)", dest);

    (void)dest;
    (void)dummy;

    if (function_hook_state_BrModelToViewQuery == HOOK_ENABLED) {
        assert(0 && "BrModelToViewQuery not implemented.");
        abort();
    } else {
        original_BrModelToViewQuery(dest);
    }
}

function_hook_state_t function_hook_state_BrOriginToScreenXY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrOriginToScreenXY, function_hook_state_BrOriginToScreenXY)
static br_uint_8(__cdecl*original_BrOriginToScreenXY)(br_vector2 *) = (br_uint_8(__cdecl*)(br_vector2 *))0x004de5a0;
CARM95_HOOK_FUNCTION(original_BrOriginToScreenXY, BrOriginToScreenXY)
br_uint_8 __cdecl BrOriginToScreenXY(br_vector2 *screen) {
    LOG_TRACE("(%p)", screen);

    (void)screen;

    if (function_hook_state_BrOriginToScreenXY == HOOK_ENABLED) {
        assert(0 && "BrOriginToScreenXY not implemented.");
        abort();
    } else {
        return original_BrOriginToScreenXY(screen);
    }
}

function_hook_state_t function_hook_state_BrOriginToScreenXYZO = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrOriginToScreenXYZO, function_hook_state_BrOriginToScreenXYZO)
static br_uint_32(__cdecl*original_BrOriginToScreenXYZO)(br_vector3 *) = (br_uint_32(__cdecl*)(br_vector3 *))0x004de670;
CARM95_HOOK_FUNCTION(original_BrOriginToScreenXYZO, BrOriginToScreenXYZO)
br_uint_32 __cdecl BrOriginToScreenXYZO(br_vector3 *screen) {
    br_uint_32 outcode;
    LOG_TRACE("(%p)", screen);

    (void)screen;
    (void)outcode;

    if (function_hook_state_BrOriginToScreenXYZO == HOOK_ENABLED) {
        assert(0 && "BrOriginToScreenXYZO not implemented.");
        abort();
    } else {
        return original_BrOriginToScreenXYZO(screen);
    }
}

function_hook_state_t function_hook_state_BrPointToScreenXY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPointToScreenXY, function_hook_state_BrPointToScreenXY)
static br_uint_8(__cdecl*original_BrPointToScreenXY)(br_vector2 *, br_vector3 *) = (br_uint_8(__cdecl*)(br_vector2 *, br_vector3 *))0x004de7f0;
CARM95_HOOK_FUNCTION(original_BrPointToScreenXY, BrPointToScreenXY)
br_uint_8 __cdecl BrPointToScreenXY(br_vector2 *screen, br_vector3 *point) {
    br_vector4 sp;
    LOG_TRACE("(%p, %p)", screen, point);

    (void)screen;
    (void)point;
    (void)sp;

    if (function_hook_state_BrPointToScreenXY == HOOK_ENABLED) {
        assert(0 && "BrPointToScreenXY not implemented.");
        abort();
    } else {
        return original_BrPointToScreenXY(screen, point);
    }
}

function_hook_state_t function_hook_state_BrPointToScreenXYZO = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPointToScreenXYZO, function_hook_state_BrPointToScreenXYZO)
static br_uint_32(__cdecl*original_BrPointToScreenXYZO)(br_vector3 *, br_vector3 *) = (br_uint_32(__cdecl*)(br_vector3 *, br_vector3 *))0x004de8e0;
CARM95_HOOK_FUNCTION(original_BrPointToScreenXYZO, BrPointToScreenXYZO)
br_uint_32 __cdecl BrPointToScreenXYZO(br_vector3 *screen, br_vector3 *point) {
    br_vector4 sp;
    br_uint_32 outcode;
    LOG_TRACE("(%p, %p)", screen, point);

    (void)screen;
    (void)point;
    (void)sp;
    (void)outcode;

    if (function_hook_state_BrPointToScreenXYZO == HOOK_ENABLED) {
        assert(0 && "BrPointToScreenXYZO not implemented.");
        abort();
    } else {
        return original_BrPointToScreenXYZO(screen, point);
    }
}

function_hook_state_t function_hook_state_BrPointToScreenXYMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPointToScreenXYMany, function_hook_state_BrPointToScreenXYMany)
static void(__stdcall*original_BrPointToScreenXYMany)(br_vector2 *, br_vector3 *, br_uint_32) = (void(__stdcall*)(br_vector2 *, br_vector3 *, br_uint_32))0x004dea70;
CARM95_HOOK_FUNCTION(original_BrPointToScreenXYMany, BrPointToScreenXYMany)
void __stdcall BrPointToScreenXYMany(br_vector2 *screens, br_vector3 *points, br_uint_32 npoints) {
    br_vector4 sp;
    int i;
    LOG_TRACE("(%p, %p, %u)", screens, points, npoints);

    (void)screens;
    (void)points;
    (void)npoints;
    (void)sp;
    (void)i;

    if (function_hook_state_BrPointToScreenXYMany == HOOK_ENABLED) {
        assert(0 && "BrPointToScreenXYMany not implemented.");
        abort();
    } else {
        original_BrPointToScreenXYMany(screens, points, npoints);
    }
}

function_hook_state_t function_hook_state_BrPointToScreenXYZOMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPointToScreenXYZOMany, function_hook_state_BrPointToScreenXYZOMany)
static void(__stdcall*original_BrPointToScreenXYZOMany)(br_vector3 *, br_uint_32 *, br_vector3 *, br_uint_32) = (void(__stdcall*)(br_vector3 *, br_uint_32 *, br_vector3 *, br_uint_32))0x004deb70;
CARM95_HOOK_FUNCTION(original_BrPointToScreenXYZOMany, BrPointToScreenXYZOMany)
void __stdcall BrPointToScreenXYZOMany(br_vector3 *screens, br_uint_32 *outcodes, br_vector3 *points, br_uint_32 npoints) {
    br_vector4 sp;
    int i;
    br_uint_32 outcode;
    LOG_TRACE("(%p, %p, %p, %u)", screens, outcodes, points, npoints);

    (void)screens;
    (void)outcodes;
    (void)points;
    (void)npoints;
    (void)sp;
    (void)i;
    (void)outcode;

    if (function_hook_state_BrPointToScreenXYZOMany == HOOK_ENABLED) {
        assert(0 && "BrPointToScreenXYZOMany not implemented.");
        abort();
    } else {
        original_BrPointToScreenXYZOMany(screens, outcodes, points, npoints);
    }
}

function_hook_state_t function_hook_state_BrZbDepthToScreenZ = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbDepthToScreenZ, function_hook_state_BrZbDepthToScreenZ)
static br_scalar(__cdecl*original_BrZbDepthToScreenZ)(br_uint_32, br_camera *) = (br_scalar(__cdecl*)(br_uint_32, br_camera *))0x004ded30;
CARM95_HOOK_FUNCTION(original_BrZbDepthToScreenZ, BrZbDepthToScreenZ)
br_scalar __cdecl BrZbDepthToScreenZ(br_uint_32 depth_z, br_camera *camera) {
    LOG_TRACE("(%u, %p)", depth_z, camera);

    (void)depth_z;
    (void)camera;

    if (function_hook_state_BrZbDepthToScreenZ == HOOK_ENABLED) {
        assert(0 && "BrZbDepthToScreenZ not implemented.");
        abort();
    } else {
        return original_BrZbDepthToScreenZ(depth_z, camera);
    }
}

function_hook_state_t function_hook_state_BrZbScreenZToDepth = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbScreenZToDepth, function_hook_state_BrZbScreenZToDepth)
static br_uint_32(__cdecl*original_BrZbScreenZToDepth)(br_scalar, br_camera *) = (br_uint_32(__cdecl*)(br_scalar, br_camera *))0x004ded50;
CARM95_HOOK_FUNCTION(original_BrZbScreenZToDepth, BrZbScreenZToDepth)
br_uint_32 __cdecl BrZbScreenZToDepth(br_scalar sz, br_camera *camera) {
    br_uint_32 depth;
    LOG_TRACE("(%f, %p)", sz, camera);

    (void)sz;
    (void)camera;
    (void)depth;

    if (function_hook_state_BrZbScreenZToDepth == HOOK_ENABLED) {
        assert(0 && "BrZbScreenZToDepth not implemented.");
        abort();
    } else {
        return original_BrZbScreenZToDepth(sz, camera);
    }
}

function_hook_state_t function_hook_state_BrZsDepthToScreenZ = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsDepthToScreenZ, function_hook_state_BrZsDepthToScreenZ)
static br_scalar(__cdecl*original_BrZsDepthToScreenZ)(br_scalar, br_camera *) = (br_scalar(__cdecl*)(br_scalar, br_camera *))0x004ded90;
CARM95_HOOK_FUNCTION(original_BrZsDepthToScreenZ, BrZsDepthToScreenZ)
br_scalar __cdecl BrZsDepthToScreenZ(br_scalar depth_z, br_camera *camera) {
    br_scalar hither;
    br_scalar yon;
    LOG_TRACE("(%f, %p)", depth_z, camera);

    (void)depth_z;
    (void)camera;
    (void)hither;
    (void)yon;

    if (function_hook_state_BrZsDepthToScreenZ == HOOK_ENABLED) {
        assert(0 && "BrZsDepthToScreenZ not implemented.");
        abort();
    } else {
        return original_BrZsDepthToScreenZ(depth_z, camera);
    }
}

function_hook_state_t function_hook_state_BrZsScreenZToDepth = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsScreenZToDepth, function_hook_state_BrZsScreenZToDepth)
static br_scalar(__cdecl*original_BrZsScreenZToDepth)(br_scalar, br_camera *) = (br_scalar(__cdecl*)(br_scalar, br_camera *))0x004dee10;
CARM95_HOOK_FUNCTION(original_BrZsScreenZToDepth, BrZsScreenZToDepth)
br_scalar __cdecl BrZsScreenZToDepth(br_scalar sz, br_camera *camera) {
    br_scalar hither;
    br_scalar yon;
    br_scalar depth;
    LOG_TRACE("(%f, %p)", sz, camera);

    (void)sz;
    (void)camera;
    (void)hither;
    (void)yon;
    (void)depth;

    if (function_hook_state_BrZsScreenZToDepth == HOOK_ENABLED) {
        assert(0 && "BrZsScreenZToDepth not implemented.");
        abort();
    } else {
        return original_BrZsScreenZToDepth(sz, camera);
    }
}

function_hook_state_t function_hook_state_BrScreenZToCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrScreenZToCamera, function_hook_state_BrScreenZToCamera)
static br_scalar(__cdecl*original_BrScreenZToCamera)(br_actor *, br_scalar) = (br_scalar(__cdecl*)(br_actor *, br_scalar))0x004dee90;
CARM95_HOOK_FUNCTION(original_BrScreenZToCamera, BrScreenZToCamera)
br_scalar __cdecl BrScreenZToCamera(br_actor *camera, br_scalar sz) {
    br_camera *data;
    br_scalar hither;
    br_scalar yon;
    LOG_TRACE("(%p, %f)", camera, sz);

    (void)camera;
    (void)sz;
    (void)data;
    (void)hither;
    (void)yon;

    if (function_hook_state_BrScreenZToCamera == HOOK_ENABLED) {
        assert(0 && "BrScreenZToCamera not implemented.");
        abort();
    } else {
        return original_BrScreenZToCamera(camera, sz);
    }
}

function_hook_state_t function_hook_state_BrScreenXYZToCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrScreenXYZToCamera, function_hook_state_BrScreenXYZToCamera)
static void(__cdecl*original_BrScreenXYZToCamera)(br_vector3 *, br_actor *, br_pixelmap *, br_int_16, br_int_16, br_scalar) = (void(__cdecl*)(br_vector3 *, br_actor *, br_pixelmap *, br_int_16, br_int_16, br_scalar))0x004def70;
CARM95_HOOK_FUNCTION(original_BrScreenXYZToCamera, BrScreenXYZToCamera)
void __cdecl BrScreenXYZToCamera(br_vector3 *point, br_actor *camera, br_pixelmap *screen_buffer, br_int_16 x, br_int_16 y, br_scalar sz) {
    br_scalar hx;
    br_scalar hy;
    br_scalar vz;
    br_camera *data;
    br_angle fov;
    br_scalar scale;
    LOG_TRACE("(%p, %p, %p, %d, %d, %f)", point, camera, screen_buffer, x, y, sz);

    (void)point;
    (void)camera;
    (void)screen_buffer;
    (void)x;
    (void)y;
    (void)sz;
    (void)hx;
    (void)hy;
    (void)vz;
    (void)data;
    (void)fov;
    (void)scale;

    if (function_hook_state_BrScreenXYZToCamera == HOOK_ENABLED) {
        assert(0 && "BrScreenXYZToCamera not implemented.");
        abort();
    } else {
        original_BrScreenXYZToCamera(point, camera, screen_buffer, x, y, sz);
    }
}

