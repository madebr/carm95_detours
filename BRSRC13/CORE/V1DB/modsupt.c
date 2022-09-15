#include "modsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_BrModelApplyMap)(br_model *, int, br_matrix34 *, ...) = (void(*)(br_model *, int, br_matrix34 *, ...))0x004d6320;
CARM95_HOOK_FUNCTION(original_BrModelApplyMap, BrModelApplyMap)
void BrModelApplyMap(br_model *model, int map_type, br_matrix34 *xform) {
    int v;
    br_vertex *vp;
    br_vector3 mv;
    br_matrix34 default_xform;
    br_scalar d;
    LOG_TRACE("(%p, %d, %p)", model, map_type, xform);

    (void)model;
    (void)map_type;
    (void)xform;
    (void)v;
    (void)vp;
    (void)mv;
    (void)default_xform;
    (void)d;

    original_BrModelApplyMap(model, map_type, xform);
}

static br_matrix34 *(*original_BrModelFitMap)(br_model *, int, int, br_matrix34 *, ...) = (br_matrix34 *(*)(br_model *, int, int, br_matrix34 *, ...))0x004d6500;
CARM95_HOOK_FUNCTION(original_BrModelFitMap, BrModelFitMap)
br_matrix34* BrModelFitMap(br_model *model, int axis_0, int axis_1, br_matrix34 *transform) {
    br_vector3 axis_3;
    br_vector3 tr;
    br_vector3 sc;
    int i;
    static br_vector3 axis_vectors[6];
    LOG_TRACE("(%p, %d, %d, %p)", model, axis_0, axis_1, transform);

    (void)model;
    (void)axis_0;
    (void)axis_1;
    (void)transform;
    (void)axis_3;
    (void)tr;
    (void)sc;
    (void)i;
    (void)axis_vectors;

    return original_BrModelFitMap(model, axis_0, axis_1, transform);
}

static void(*original_BrModelFree)(br_model *, ...) = (void(*)(br_model *, ...))0x004d6680;
CARM95_HOOK_FUNCTION(original_BrModelFree, BrModelFree)
void BrModelFree(br_model *m) {
    LOG_TRACE("(%p)", m);

    (void)m;

    original_BrModelFree(m);
}

static br_model *(*original_BrModelAllocate)(char *, int, int, ...) = (br_model *(*)(char *, int, int, ...))0x004d6690;
CARM95_HOOK_FUNCTION(original_BrModelAllocate, BrModelAllocate)
br_model* BrModelAllocate(char *name, int nvertices, int nfaces) {
    br_model *m;
    LOG_TRACE("(\"%s\", %d, %d)", name, nvertices, nfaces);

    (void)name;
    (void)nvertices;
    (void)nfaces;
    (void)m;

    return original_BrModelAllocate(name, nvertices, nfaces);
}

br_primitive_list* BrPrimitiveListAllocate(br_uint_32 prim_type, br_uint_16 num_prims) {
    LOG_TRACE("(%u, %u)", prim_type, num_prims);

    (void)prim_type;
    (void)num_prims;

    NOT_IMPLEMENTED();
}

br_uint_32 BrModelAddPrimitiveList(br_model *model, br_primitive_list *primitive_list) {
    LOG_TRACE("(%p, %p)", model, primitive_list);

    (void)model;
    (void)primitive_list;

    NOT_IMPLEMENTED();
}

