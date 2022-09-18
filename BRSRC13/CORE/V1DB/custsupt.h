#ifndef _CUSTSUPT_H_
#define _CUSTSUPT_H_

#include "br_types.h"


void __cdecl BrModelToScreenQuery(br_matrix4 *dest);

void __cdecl BrModelToViewQuery(br_matrix34 *dest);

br_uint_8 __cdecl BrOriginToScreenXY(br_vector2 *screen);

br_uint_32 __cdecl BrOriginToScreenXYZO(br_vector3 *screen);

br_uint_8 __cdecl BrPointToScreenXY(br_vector2 *screen, br_vector3 *point);

br_uint_32 __cdecl BrPointToScreenXYZO(br_vector3 *screen, br_vector3 *point);

void __stdcall BrPointToScreenXYMany(br_vector2 *screens, br_vector3 *points, br_uint_32 npoints);

void __stdcall BrPointToScreenXYZOMany(br_vector3 *screens, br_uint_32 *outcodes, br_vector3 *points, br_uint_32 npoints);

br_scalar __cdecl BrZbDepthToScreenZ(br_uint_32 depth_z, br_camera *camera);

br_uint_32 __cdecl BrZbScreenZToDepth(br_scalar sz, br_camera *camera);

br_scalar __cdecl BrZsDepthToScreenZ(br_scalar depth_z, br_camera *camera);

br_scalar __cdecl BrZsScreenZToDepth(br_scalar sz, br_camera *camera);

br_scalar __cdecl BrScreenZToCamera(br_actor *camera, br_scalar sz);

void __cdecl BrScreenXYZToCamera(br_vector3 *point, br_actor *camera, br_pixelmap *screen_buffer, br_int_16 x, br_int_16 y, br_scalar sz);

#endif
