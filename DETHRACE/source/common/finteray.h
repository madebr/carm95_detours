#ifndef _FINTERAY_H_
#define _FINTERAY_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gPling_materials ; // addr: 0051E8FC
// extern br_material ** hookvar_gSub_material ;
// extern br_material ** hookvar_gReal_material ;
extern int * hookvar_gNfaces ; // addr: 0051E908
extern br_matrix34 * hookvar_gPick_model_to_view__finteray ; // addr: 0053E558 // suffix added to avoid duplicate symbol
extern int * hookvar_gTemp_group ; // addr: 0053E588
extern br_model ** hookvar_gNearest_model ; // addr: 0053E54C
extern br_model ** hookvar_gSelected_model ; // addr: 0053E58C
extern int * hookvar_gNearest_face_group ; // addr: 0053E554
extern int * hookvar_gNearest_face ; // addr: 0053E548
extern br_scalar * hookvar_gNearest_T ; // addr: 0053E550
extern tFace_ref ** hookvar_gPling_face ; // addr: 00550240

int BadDiv__finteray(br_scalar a, br_scalar b);

void DRVector2AccumulateScale__finteray(br_vector2 *a, br_vector2 *b, br_scalar s);

int PickBoundsTestRay__finteray(br_bounds *b, br_vector3 *rp, br_vector3 *rd, br_scalar t_near, br_scalar t_far, br_scalar *new_t_near, br_scalar *new_t_far);

int ActorRayPick2D(br_actor *ap, br_vector3 *pPosition, br_vector3 *pDir, br_model *model, br_material *material, dr_pick2d_cbfn *callback);

int DRSceneRayPick2D(br_actor *world, br_vector3 *pPosition, br_vector3 *pDir, dr_pick2d_cbfn *callback);

int DRModelPick2D__finteray(br_model *model, br_material *material, br_vector3 *ray_pos, br_vector3 *ray_dir, br_scalar t_near, br_scalar t_far, dr_modelpick2d_cbfn *callback, void *arg);

int FindHighestPolyCallBack__finteray(br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT, int pF, int pE, int pV, br_vector3 *pPoint, br_vector2 *pMap, void *pArg);

int FindHighestCallBack__finteray(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT_near, br_scalar pT_far, void *pArg);

void FindFace(br_vector3 *pPosition, br_vector3 *pDir, br_vector3 *nor, br_scalar *t, br_material **material);

void EnablePlingMaterials();

void DisablePlingMaterials();

void CheckSingleFace(tFace_ref *pFace, br_vector3 *ray_pos, br_vector3 *ray_dir, br_vector3 *normal, br_scalar *rt);

void MultiRayCheckSingleFace(int pNum_rays, tFace_ref *pFace, br_vector3 *ray_pos, br_vector3 *ray_dir, br_vector3 *normal, br_scalar *rt);

void GetNewBoundingBox(br_bounds *b2, br_bounds *b1, br_matrix34 *m);

int FindFacesInBox(tBounds *bnds, tFace_ref *face_list, int max_face);

int FindFacesInBox2(tBounds *bnds, tFace_ref *face_list, int max_face);

int ActorBoxPick(tBounds *bnds, br_actor *ap, br_model *model, br_material *material, tFace_ref *face_list, int max_face, br_matrix34 *pMat);

int ModelPickBox(br_actor *actor, tBounds *bnds, br_model *model, br_material *model_material, tFace_ref *face_list, int max_face, br_matrix34 *pMat);

void ClipToPlaneGE(br_vector3 *p, int *nv, int i, br_scalar limit);

void ClipToPlaneLE(br_vector3 *p, int *nv, int i, br_scalar limit);

int BoundsOverlapTest__finteray(br_bounds *b1, br_bounds *b2);

int BoundsTransformTest(br_bounds *b1, br_bounds *b2, br_matrix34 *M);

int LineBoxColl(br_vector3 *o, br_vector3 *p, br_bounds *pB, br_vector3 *pHit_point);

int SphereBoxIntersection(br_bounds *pB, br_vector3 *pC, br_scalar pR_squared, br_vector3 *pHit_point);

int LineBoxCollWithSphere(br_vector3 *o, br_vector3 *p, br_bounds *pB, br_vector3 *pHit_point);

int CompVert(int v1, int v2);

void SetFacesGroup(int pFace);

void SelectFace(br_vector3 *pDir);

void GetTilingLimits(br_vector2 *min, br_vector2 *max);

void Scale(int pD, int factor);

void ScaleUpX();

void ScaleDnX();

void ScaleUpY();

void ScaleDnY();

void SelectFaceForward();

void SelectFaceDown();

#endif
