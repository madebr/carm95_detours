#ifndef _PREPMESH_H_
#define _PREPMESH_H_

#include "br_types.h"

// extern int * hookvar_num_edges ;
extern br_model ** hookvar_compareModel ; // addr: 00541644
// extern char ** hookvar_pm_edge_scratch ;

int addEdge(br_uint_16 first, br_uint_16 last);

void prepareEdges(struct v11group *group, br_model *model);

void BrPrepareEdges(br_model *model);

int FacesCompare(void *p1, void *p2);

int TVCompare_XYZ(void *p1, void *p2);

int TVCompare_MXYZUVN(void *p1, void *p2);

int TVCompare_MVN(void *p1, void *p2);

br_fraction BrScalarToFractionClamp(br_scalar s);

void PrepareFaceNormals(br_model *model);

void Smoothing(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end);

void SmoothingCreased(br_model *model, br_scalar crease_limit, struct prep_vertex **start, struct prep_vertex **end);

void CopyVertex__prepmesh(struct v11group *group, int v, struct prep_vertex *src, br_model *model);

void CopyFace__prepmesh(struct v11group *group, int f, br_face *src, br_model *model);

void PrepareGroups(br_model *model);

void PrepareBoundingRadius__prepmesh(br_model *model);

void PrepareBoundingBox(br_model *model);

void RegenerateFaceNormals(struct v11model *v11m);

void RegenerateVertexNormals(struct v11model *v11m);

void BrModelUpdate(br_model *model, br_uint_16 flags);

void BrModelClear(struct br_model *model);

#endif
