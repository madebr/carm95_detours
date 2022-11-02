#include "prepmesh.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_addEdge = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_addEdge)
int addEdge(br_uint_16 first, br_uint_16 last) {
    struct pm_temp_edge *tep;
    LOG_TRACE("(%u, %u)", first, last);

    (void)first;
    (void)last;
    (void)tep;

    if (function_hook_state_addEdge == HOOK_ENABLED) {
        assert(0 && "addEdge not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_prepareEdges = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_prepareEdges)
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

    if (function_hook_state_prepareEdges == HOOK_ENABLED) {
        assert(0 && "prepareEdges not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrPrepareEdges = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrPrepareEdges)
void BrPrepareEdges(br_model *model) {
    int g;
    struct v11model *v11m;
    LOG_TRACE("(%p)", model);

    (void)model;
    (void)g;
    (void)v11m;

    if (function_hook_state_BrPrepareEdges == HOOK_ENABLED) {
        assert(0 && "BrPrepareEdges not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_FacesCompare = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FacesCompare)
static int(__cdecl*original_FacesCompare)(void *, void *) = (int(__cdecl*)(void *, void *))0x004d8a40;
CARM95_HOOK_FUNCTION(original_FacesCompare, FacesCompare)
int __cdecl FacesCompare(void *p1, void *p2) {
    br_face *f1;
    br_face *f2;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)f1;
    (void)f2;

    if (function_hook_state_FacesCompare == HOOK_ENABLED) {
        assert(0 && "FacesCompare not implemented.");
        abort();
    } else {
        return original_FacesCompare(p1, p2);
    }
}

function_hook_state_t function_hook_state_TVCompare_XYZ = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TVCompare_XYZ)
static int(__cdecl*original_TVCompare_XYZ)(void *, void *) = (int(__cdecl*)(void *, void *))0x004d8a70;
CARM95_HOOK_FUNCTION(original_TVCompare_XYZ, TVCompare_XYZ)
int __cdecl TVCompare_XYZ(void *p1, void *p2) {
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

    if (function_hook_state_TVCompare_XYZ == HOOK_ENABLED) {
        assert(0 && "TVCompare_XYZ not implemented.");
        abort();
    } else {
        return original_TVCompare_XYZ(p1, p2);
    }
}

function_hook_state_t function_hook_state_TVCompare_MXYZUVN = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TVCompare_MXYZUVN)
static int(__cdecl*original_TVCompare_MXYZUVN)(void *, void *) = (int(__cdecl*)(void *, void *))0x004d8af0;
CARM95_HOOK_FUNCTION(original_TVCompare_MXYZUVN, TVCompare_MXYZUVN)
int __cdecl TVCompare_MXYZUVN(void *p1, void *p2) {
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

    if (function_hook_state_TVCompare_MXYZUVN == HOOK_ENABLED) {
        assert(0 && "TVCompare_MXYZUVN not implemented.");
        abort();
    } else {
        return original_TVCompare_MXYZUVN(p1, p2);
    }
}

function_hook_state_t function_hook_state_TVCompare_MVN = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TVCompare_MVN)
static int(__cdecl*original_TVCompare_MVN)(void *, void *) = (int(__cdecl*)(void *, void *))0x004d8c50;
CARM95_HOOK_FUNCTION(original_TVCompare_MVN, TVCompare_MVN)
int __cdecl TVCompare_MVN(void *p1, void *p2) {
    struct prep_vertex *tv1;
    struct prep_vertex *tv2;
    int i;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)tv1;
    (void)tv2;
    (void)i;

    if (function_hook_state_TVCompare_MVN == HOOK_ENABLED) {
        assert(0 && "TVCompare_MVN not implemented.");
        abort();
    } else {
        return original_TVCompare_MVN(p1, p2);
    }
}

function_hook_state_t function_hook_state_BrScalarToFractionClamp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScalarToFractionClamp)
static br_fraction(__stdcall*original_BrScalarToFractionClamp)(br_scalar) = (br_fraction(__stdcall*)(br_scalar))0x004d7807;
CARM95_HOOK_FUNCTION(original_BrScalarToFractionClamp, BrScalarToFractionClamp)
br_fraction __stdcall BrScalarToFractionClamp(br_scalar s) {
    LOG_TRACE("(%f)", s);

    (void)s;

    if (function_hook_state_BrScalarToFractionClamp == HOOK_ENABLED) {
        assert(0 && "BrScalarToFractionClamp not implemented.");
        abort();
    } else {
        return original_BrScalarToFractionClamp(s);
    }
}

function_hook_state_t function_hook_state_PrepareFaceNormals = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PrepareFaceNormals)
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

    if (function_hook_state_PrepareFaceNormals == HOOK_ENABLED) {
        assert(0 && "PrepareFaceNormals not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_Smoothing = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_Smoothing)
static void(__stdcall*original_Smoothing)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **) = (void(__stdcall*)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **))0x004d8d00;
CARM95_HOOK_FUNCTION(original_Smoothing, Smoothing)
void __stdcall Smoothing(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end) {
    struct prep_vertex **outer;
    struct prep_vertex **inner;
    LOG_TRACE("(%p, %f, %p, %p)", model, crease_limit, start, end);

    (void)model;
    (void)crease_limit;
    (void)start;
    (void)end;
    (void)outer;
    (void)inner;

    if (function_hook_state_Smoothing == HOOK_ENABLED) {
        assert(0 && "Smoothing not implemented.");
        abort();
    } else {
        original_Smoothing(model, crease_limit, start, end);
    }
}

function_hook_state_t function_hook_state_SmoothingCreased = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SmoothingCreased)
static void(__stdcall*original_SmoothingCreased)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **) = (void(__stdcall*)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **))0x004d8db0;
CARM95_HOOK_FUNCTION(original_SmoothingCreased, SmoothingCreased)
void __stdcall SmoothingCreased(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end) {
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

    if (function_hook_state_SmoothingCreased == HOOK_ENABLED) {
        assert(0 && "SmoothingCreased not implemented.");
        abort();
    } else {
        original_SmoothingCreased(model, crease_limit, start, end);
    }
}

function_hook_state_t function_hook_state_CopyVertex__prepmesh = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyVertex__prepmesh)
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
    (void)__block0___scale;

    if (function_hook_state_CopyVertex__prepmesh == HOOK_ENABLED) {
        assert(0 && "CopyVertex__prepmesh not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CopyFace__prepmesh = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyFace__prepmesh)
void CopyFace__prepmesh(struct v11group *group, int f, br_face *src, br_model *model) {
    LOG_TRACE("(%p, %d, %p, %p)", group, f, src, model);

    (void)group;
    (void)f;
    (void)src;
    (void)model;

    if (function_hook_state_CopyFace__prepmesh == HOOK_ENABLED) {
        assert(0 && "CopyFace__prepmesh not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PrepareGroups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PrepareGroups)
static void(__stdcall*original_PrepareGroups)(br_model *) = (void(__stdcall*)(br_model *))0x004d83c0;
CARM95_HOOK_FUNCTION(original_PrepareGroups, PrepareGroups)
void __stdcall PrepareGroups(br_model *model) {
    br_qsort_cbfn *vertex_compare_smoothing;
    br_qsort_cbfn *vertex_compare_groups;
    void(**smoothing_fn)(br_model *, br_scalar, struct prep_vertex **, struct prep_vertex **);
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

    if (function_hook_state_PrepareGroups == HOOK_ENABLED) {
        assert(0 && "PrepareGroups not implemented.");
        abort();
    } else {
        original_PrepareGroups(model);
    }
}

function_hook_state_t function_hook_state_PrepareBoundingRadius__prepmesh = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PrepareBoundingRadius__prepmesh)
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

    if (function_hook_state_PrepareBoundingRadius__prepmesh == HOOK_ENABLED) {
        assert(0 && "PrepareBoundingRadius__prepmesh not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PrepareBoundingBox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PrepareBoundingBox)
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

    if (function_hook_state_PrepareBoundingBox == HOOK_ENABLED) {
        assert(0 && "PrepareBoundingBox not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RegenerateFaceNormals = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RegenerateFaceNormals)
static void(__stdcall*original_RegenerateFaceNormals)(struct v11model *) = (void(__stdcall*)(struct v11model *))0x004d7840;
CARM95_HOOK_FUNCTION(original_RegenerateFaceNormals, RegenerateFaceNormals)
void __stdcall RegenerateFaceNormals(struct v11model *v11m) {
    int g;
    int f;
    struct v11face *fp;
    LOG_TRACE("(%p)", v11m);

    (void)v11m;
    (void)g;
    (void)f;
    (void)fp;

    if (function_hook_state_RegenerateFaceNormals == HOOK_ENABLED) {
        assert(0 && "RegenerateFaceNormals not implemented.");
        abort();
    } else {
        original_RegenerateFaceNormals(v11m);
    }
}

function_hook_state_t function_hook_state_RegenerateVertexNormals = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RegenerateVertexNormals)
static void(__stdcall*original_RegenerateVertexNormals)(struct v11model *) = (void(__stdcall*)(struct v11model *))0x004d78e0;
CARM95_HOOK_FUNCTION(original_RegenerateVertexNormals, RegenerateVertexNormals)
void __stdcall RegenerateVertexNormals(struct v11model *v11m) {
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
    (void)__block0___scale;

    if (function_hook_state_RegenerateVertexNormals == HOOK_ENABLED) {
        assert(0 && "RegenerateVertexNormals not implemented.");
        abort();
    } else {
        original_RegenerateVertexNormals(v11m);
    }
}

function_hook_state_t function_hook_state_BrModelUpdate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrModelUpdate)
static void(__cdecl*original_BrModelUpdate)(br_model *, br_uint_16) = (void(__cdecl*)(br_model *, br_uint_16))0x004d7af0;
CARM95_HOOK_FUNCTION(original_BrModelUpdate, BrModelUpdate)
void __cdecl BrModelUpdate(br_model *model, br_uint_16 flags) {
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
    (void)__block0__r;
    (void)__block0__sg;
    (void)__block0__b;
    (void)__block0__tv;

    if (function_hook_state_BrModelUpdate == HOOK_ENABLED) {
        assert(0 && "BrModelUpdate not implemented.");
        abort();
    } else {
        original_BrModelUpdate(model, flags);
    }
}

function_hook_state_t function_hook_state_BrModelClear = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrModelClear)
static void(__stdcall*original_BrModelClear)(struct br_model *) = (void(__stdcall*)(struct br_model *))0x004d90a0;
CARM95_HOOK_FUNCTION(original_BrModelClear, BrModelClear)
void __stdcall BrModelClear(struct br_model *model) {
    LOG_TRACE("(%p)", model);

    (void)model;

    if (function_hook_state_BrModelClear == HOOK_ENABLED) {
        assert(0 && "BrModelClear not implemented.");
        abort();
    } else {
        original_BrModelClear(model);
    }
}

