#include "prepmesh.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
#if 0
int * hookvar_num_edges ;
#endif
br_model ** hookvar_compareModel  = (void*)0x00541644;
#if 0
char ** hookvar_pm_edge_scratch ;
#endif
#if 0
struct pm_temp_edge *** hookvar_pm_edge_hash ;
#endif
#if 0
struct pm_temp_edge ** hookvar_pm_edge_table ;
#endif

int addEdge(br_uint_16 first, br_uint_16 last) {
    struct pm_temp_edge *tep;
    LOG_TRACE("(%u, %u)", first, last);

    (void)first;
    (void)last;
    (void)tep;

    NOT_IMPLEMENTED();
}

void prepareEdges(struct v11group *group, br_model *model) {
    br_size_t scratch_size;
    br_face *mfp;
    struct v11face *fp;
    int f;
    LOG_TRACE("(%p, %p)", group, model);

    (void)group;
    (void)model;
    (void)scratch_size;
    (void)mfp;
    (void)fp;
    (void)f;

    NOT_IMPLEMENTED();
}

void BrPrepareEdges(br_model *model) {
    int g;
    struct v11model *v11m;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)g;
    (void)v11m;

    NOT_IMPLEMENTED();
}

static int(*original_FacesCompare)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004d8a40;
CARM95_HOOK_FUNCTION(original_FacesCompare, FacesCompare)
int FacesCompare(void *p1, void *p2) {
    br_face *f1;
    br_face *f2;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)f1;
    (void)f2;

    return original_FacesCompare(p1, p2);
}

static int(*original_TVCompare_XYZ)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004d8a70;
CARM95_HOOK_FUNCTION(original_TVCompare_XYZ, TVCompare_XYZ)
int TVCompare_XYZ(void *p1, void *p2) {
    struct prep_vertex *tv1;
    struct prep_vertex *tv2;
    struct br_vertex *v1;
    struct br_vertex *v2;
    int i;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)tv1;
    (void)tv2;
    (void)v1;
    (void)v2;
    (void)i;

    return original_TVCompare_XYZ(p1, p2);
}

static int(*original_TVCompare_MXYZUVN)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004d8af0;
CARM95_HOOK_FUNCTION(original_TVCompare_MXYZUVN, TVCompare_MXYZUVN)
int TVCompare_MXYZUVN(void *p1, void *p2) {
    struct prep_vertex *tv1;
    struct prep_vertex *tv2;
    struct br_vertex *v1;
    struct br_vertex *v2;
    int i;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)tv1;
    (void)tv2;
    (void)v1;
    (void)v2;
    (void)i;

    return original_TVCompare_MXYZUVN(p1, p2);
}

static int(*original_TVCompare_MVN)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004d8c50;
CARM95_HOOK_FUNCTION(original_TVCompare_MVN, TVCompare_MVN)
int TVCompare_MVN(void *p1, void *p2) {
    struct prep_vertex *tv1;
    struct prep_vertex *tv2;
    int i;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)tv1;
    (void)tv2;
    (void)i;

    return original_TVCompare_MVN(p1, p2);
}

static br_fraction(*original_BrScalarToFractionClamp)(br_scalar, ...) = (br_fraction(*)(br_scalar, ...))0x004d7807;
CARM95_HOOK_FUNCTION(original_BrScalarToFractionClamp, BrScalarToFractionClamp)
br_fraction BrScalarToFractionClamp(br_scalar s) {
    LOG_TRACE("(%f)", s);

    (void)s;

    return original_BrScalarToFractionClamp(s);
}

void PrepareFaceNormals(br_model *model) {
    br_vertex *vertices;
    br_vector4 v4;
    br_face *fp;
    int f;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)vertices;
    (void)v4;
    (void)fp;
    (void)f;

    NOT_IMPLEMENTED();
}

static void(*original_Smoothing)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **, ...) = (void(*)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **, ...))0x004d8d00;
CARM95_HOOK_FUNCTION(original_Smoothing, Smoothing)
void Smoothing(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end) {
    struct prep_vertex **outer;
    struct prep_vertex **inner;
    LOG_TRACE("(%p, %f, %p, %p)", model, crease_limit, start, end);

    (void)model;
    (void)crease_limit;
    (void)start;
    (void)end;
    (void)outer;
    (void)inner;

    original_Smoothing(model, crease_limit, start, end);
}

static void(*original_SmoothingCreased)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **, ...) = (void(*)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **, ...))0x004d8db0;
CARM95_HOOK_FUNCTION(original_SmoothingCreased, SmoothingCreased)
void SmoothingCreased(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end) {
    br_vector3 o_n;
    struct prep_vertex **outer;
    struct prep_vertex **inner;
    LOG_TRACE("(%p, %f, %p, %p)", model, crease_limit, start, end);

    (void)model;
    (void)crease_limit;
    (void)start;
    (void)end;
    (void)o_n;
    (void)outer;
    (void)inner;

    original_SmoothingCreased(model, crease_limit, start, end);
}

void CopyVertex__prepmesh(struct v11group *group, int v, struct prep_vertex *src, br_model *model) {
    br_vertex *srcv;
    br_vector3 n;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %d, %p, %p)", group, v, src, model);

    (void)group;
    (void)v;
    (void)src;
    (void)model;
    (void)srcv;
    (void)n;

    NOT_IMPLEMENTED();
}

void CopyFace__prepmesh(struct v11group *group, int f, br_face *src, br_model *model) {
    LOG_TRACE("(%p, %d, %p, %p)", group, f, src, model);

    (void)group;
    (void)f;
    (void)src;
    (void)model;

    NOT_IMPLEMENTED();
}

static void(*original_PrepareGroups)(br_model *, ...) = (void(*)(br_model *, ...))0x004d83c0;
CARM95_HOOK_FUNCTION(original_PrepareGroups, PrepareGroups)
void PrepareGroups(br_model *model) {
    br_qsort_cbfn *vertex_compare_smoothing;
    br_qsort_cbfn *vertex_compare_groups;
    void(**smoothing_fn)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **, ...);
    void *vp;
    br_size_t block_size;
    struct prep_vertex *temp_verts;
    struct prep_vertex *gtvp;
    struct prep_vertex **sorted_vertices;
    struct br_face *fp;
    int g;
    int f;
    int v;
    int i;
    int ntemps;
    int count;
    int nf;
    int nv;
    int ng;
    int old_count;
    br_scalar crease_limit;
    struct v11model *v11m;
    struct v11group *v11g;
    struct v11face *v11f;
    struct fmt_vertex *v11v;
    br_colour *v11fcolours;
    br_colour *v11vcolours;
    br_uint_16 *v11fuser;
    br_uint_16 *v11vuser;
    struct br_face **sorted_faces;
    char *cp;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)vertex_compare_smoothing;
    (void)vertex_compare_groups;
    (void)smoothing_fn;
    (void)vp;
    (void)block_size;
    (void)temp_verts;
    (void)gtvp;
    (void)sorted_vertices;
    (void)fp;
    (void)g;
    (void)f;
    (void)v;
    (void)i;
    (void)ntemps;
    (void)count;
    (void)nf;
    (void)nv;
    (void)ng;
    (void)old_count;
    (void)crease_limit;
    (void)v11m;
    (void)v11g;
    (void)v11f;
    (void)v11v;
    (void)v11fcolours;
    (void)v11vcolours;
    (void)v11fuser;
    (void)v11vuser;
    (void)sorted_faces;
    (void)cp;

    original_PrepareGroups(model);
}

void PrepareBoundingRadius__prepmesh(br_model *model) {
    float d;
    float max;
    int v;
    br_vertex *vp;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)d;
    (void)max;
    (void)v;
    (void)vp;

    NOT_IMPLEMENTED();
}

void PrepareBoundingBox(br_model *model) {
    int axis;
    int v;
    br_vertex *vp;
    br_scalar x;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)axis;
    (void)v;
    (void)vp;
    (void)x;

    NOT_IMPLEMENTED();
}

static void(*original_RegenerateFaceNormals)(struct v11model *, ...) = (void(*)(struct v11model *, ...))0x004d7840;
CARM95_HOOK_FUNCTION(original_RegenerateFaceNormals, RegenerateFaceNormals)
void RegenerateFaceNormals(struct v11model *v11m) {
    int g;
    int f;
    struct v11face *fp;
    LOG_TRACE("(%p)", v11m);

    (void)v11m;
    (void)g;
    (void)f;
    (void)fp;

    original_RegenerateFaceNormals(v11m);
}

static void(*original_RegenerateVertexNormals)(struct v11model *, ...) = (void(*)(struct v11model *, ...))0x004d78e0;
CARM95_HOOK_FUNCTION(original_RegenerateVertexNormals, RegenerateVertexNormals)
void RegenerateVertexNormals(struct v11model *v11m) {
    int g;
    int v;
    int f;
    struct v11face *fp;
    struct fmt_vertex *vp;
    br_vector3 *normals;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", v11m);

    (void)v11m;
    (void)g;
    (void)v;
    (void)f;
    (void)fp;
    (void)vp;
    (void)normals;

    original_RegenerateVertexNormals(v11m);
}

static void(*original_BrModelUpdate)(br_model *, br_uint_16, ...) = (void(*)(br_model *, br_uint_16, ...))0x004d7af0;
CARM95_HOOK_FUNCTION(original_BrModelUpdate, BrModelUpdate)
void BrModelUpdate(br_model *model, br_uint_16 flags) {
    int g;
    int f;
    int v;
    struct v11model *v11m;
    struct fmt_vertex *fvp;
    struct v11face *ffp;
    br_vertex *vp;
    br_face *fp;
    br_error __block0__r;
    struct br_geometry_stored *__block0__sg;
    br_boolean __block0__b;
    br_token_value __block0__tv[2];
    LOG_TRACE("(%p, %u)", model, flags);

    (void)model;
    (void)flags;
    (void)g;
    (void)f;
    (void)v;
    (void)v11m;
    (void)fvp;
    (void)ffp;
    (void)vp;
    (void)fp;

    original_BrModelUpdate(model, flags);
}

static void(*original_BrModelClear)(struct br_model *, ...) = (void(*)(struct br_model *, ...))0x004d90a0;
CARM95_HOOK_FUNCTION(original_BrModelClear, BrModelClear)
void BrModelClear(struct br_model *model) {
    LOG_TRACE("(%p)", model);

    (void)model;

    original_BrModelClear(model);
}

