#include "custsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


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

    original_BrModelToScreenQuery(dest);
}

static void(__cdecl*original_BrModelToViewQuery)(br_matrix34 *) = (void(__cdecl*)(br_matrix34 *))0x004de570;
CARM95_HOOK_FUNCTION(original_BrModelToViewQuery, BrModelToViewQuery)
void __cdecl BrModelToViewQuery(br_matrix34 *dest) {
    br_uint_32 dummy;
    LOG_TRACE("(%p)", dest);

    (void)dest;
    (void)dummy;

    original_BrModelToViewQuery(dest);
}

static br_uint_8(__cdecl*original_BrOriginToScreenXY)(br_vector2 *) = (br_uint_8(__cdecl*)(br_vector2 *))0x004de5a0;
CARM95_HOOK_FUNCTION(original_BrOriginToScreenXY, BrOriginToScreenXY)
br_uint_8 __cdecl BrOriginToScreenXY(br_vector2 *screen) {
    LOG_TRACE("(%p)", screen);

    (void)screen;

    return original_BrOriginToScreenXY(screen);
}

static br_uint_32(__cdecl*original_BrOriginToScreenXYZO)(br_vector3 *) = (br_uint_32(__cdecl*)(br_vector3 *))0x004de670;
CARM95_HOOK_FUNCTION(original_BrOriginToScreenXYZO, BrOriginToScreenXYZO)
br_uint_32 __cdecl BrOriginToScreenXYZO(br_vector3 *screen) {
    br_uint_32 outcode;
    LOG_TRACE("(%p)", screen);

    (void)screen;
    (void)outcode;

    return original_BrOriginToScreenXYZO(screen);
}

static br_uint_8(__cdecl*original_BrPointToScreenXY)(br_vector2 *, br_vector3 *) = (br_uint_8(__cdecl*)(br_vector2 *, br_vector3 *))0x004de7f0;
CARM95_HOOK_FUNCTION(original_BrPointToScreenXY, BrPointToScreenXY)
br_uint_8 __cdecl BrPointToScreenXY(br_vector2 *screen, br_vector3 *point) {
    br_vector4 sp;
    LOG_TRACE("(%p, %p)", screen, point);

    (void)screen;
    (void)point;
    (void)sp;

    return original_BrPointToScreenXY(screen, point);
}

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

    return original_BrPointToScreenXYZO(screen, point);
}

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

    original_BrPointToScreenXYMany(screens, points, npoints);
}

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

    original_BrPointToScreenXYZOMany(screens, outcodes, points, npoints);
}

static br_scalar(__cdecl*original_BrZbDepthToScreenZ)(br_uint_32, br_camera *) = (br_scalar(__cdecl*)(br_uint_32, br_camera *))0x004ded30;
CARM95_HOOK_FUNCTION(original_BrZbDepthToScreenZ, BrZbDepthToScreenZ)
br_scalar __cdecl BrZbDepthToScreenZ(br_uint_32 depth_z, br_camera *camera) {
    LOG_TRACE("(%u, %p)", depth_z, camera);

    (void)depth_z;
    (void)camera;

    return original_BrZbDepthToScreenZ(depth_z, camera);
}

static br_uint_32(__cdecl*original_BrZbScreenZToDepth)(br_scalar, br_camera *) = (br_uint_32(__cdecl*)(br_scalar, br_camera *))0x004ded50;
CARM95_HOOK_FUNCTION(original_BrZbScreenZToDepth, BrZbScreenZToDepth)
br_uint_32 __cdecl BrZbScreenZToDepth(br_scalar sz, br_camera *camera) {
    br_uint_32 depth;
    LOG_TRACE("(%f, %p)", sz, camera);

    (void)sz;
    (void)camera;
    (void)depth;

    return original_BrZbScreenZToDepth(sz, camera);
}

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

    return original_BrZsDepthToScreenZ(depth_z, camera);
}

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

    return original_BrZsScreenZToDepth(sz, camera);
}

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

    return original_BrScreenZToCamera(camera, sz);
}

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

    original_BrScreenXYZToCamera(point, camera, screen_buffer, x, y, sz);
}

