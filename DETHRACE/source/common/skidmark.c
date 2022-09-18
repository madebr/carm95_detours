#include "skidmark.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#if 0
char *(* hookvar_gBoring_material_names )[2];
#endif
#if 0
char *(* hookvar_gMaterial_names )[2];
#endif
tSkid(* hookvar_gSkids )[100] = (void*)0x00530190;

static void(__cdecl*original_StretchMark)(tSkid *, br_vector3 *, br_vector3 *, br_scalar) = (void(__cdecl*)(tSkid *, br_vector3 *, br_vector3 *, br_scalar))0x00401e7c;
CARM95_HOOK_FUNCTION(original_StretchMark, StretchMark)
void __cdecl StretchMark(tSkid *pMark, br_vector3 *pFrom, br_vector3 *pTo, br_scalar pTexture_start) {
    br_vector3 temp;
    br_vector3 *rows;
    br_scalar len;
    br_model *model;
    LOG_TRACE("(%p, %p, %p, %f)", pMark, pFrom, pTo, pTexture_start);

    (void)pMark;
    (void)pFrom;
    (void)pTo;
    (void)pTexture_start;
    (void)temp;
    (void)rows;
    (void)len;
    (void)model;

    original_StretchMark(pMark, pFrom, pTo, pTexture_start);
}

static br_material *(__cdecl*original_MaterialFromIndex)(int) = (br_material *(__cdecl*)(int))0x00401088;
CARM95_HOOK_FUNCTION(original_MaterialFromIndex, MaterialFromIndex)
br_material* __cdecl MaterialFromIndex(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    return original_MaterialFromIndex(pIndex);
}

static void(__cdecl*original_AdjustSkid)(int, br_matrix34 *, int) = (void(__cdecl*)(int, br_matrix34 *, int))0x00401000;
CARM95_HOOK_FUNCTION(original_AdjustSkid, AdjustSkid)
void __cdecl AdjustSkid(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;

    original_AdjustSkid(pSkid_num, pMatrix, pMaterial_index);
}

static int(__cdecl*original_FarFromLine2D)(br_vector3 *, br_vector3 *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *))0x004020dc;
CARM95_HOOK_FUNCTION(original_FarFromLine2D, FarFromLine2D)
int __cdecl FarFromLine2D(br_vector3 *pPt, br_vector3 *pL1, br_vector3 *pL2) {
    br_vector2 line;
    br_vector2 to_pt;
    br_scalar line_len;
    br_scalar cross;
    LOG_TRACE("(%p, %p, %p)", pPt, pL1, pL2);

    (void)pPt;
    (void)pL1;
    (void)pL2;
    (void)line;
    (void)to_pt;
    (void)line_len;
    (void)cross;

    return original_FarFromLine2D(pPt, pL1, pL2);
}

static int(__cdecl*original_Reflex2D)(br_vector3 *, br_vector3 *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *))0x00402179;
CARM95_HOOK_FUNCTION(original_Reflex2D, Reflex2D)
int __cdecl Reflex2D(br_vector3 *pPt, br_vector3 *pL1, br_vector3 *pL2) {
    br_vector2 line;
    br_vector2 to_pt;
    LOG_TRACE("(%p, %p, %p)", pPt, pL1, pL2);

    (void)pPt;
    (void)pL1;
    (void)pL2;
    (void)line;
    (void)to_pt;

    return original_Reflex2D(pPt, pL1, pL2);
}

static void(__cdecl*original_InitSkids)() = (void(__cdecl*)())0x004010c8;
CARM95_HOOK_FUNCTION(original_InitSkids, InitSkids)
void __cdecl InitSkids() {
    int skid;
    int mat;
    int sl;
    br_model *square;
    char *str;
    LOG_TRACE("()");

    (void)skid;
    (void)mat;
    (void)sl;
    (void)square;
    (void)str;

    original_InitSkids();
}

static void(__cdecl*original_HideSkid)(int) = (void(__cdecl*)(int))0x0040148d;
CARM95_HOOK_FUNCTION(original_HideSkid, HideSkid)
void __cdecl HideSkid(int pSkid_num) {
    LOG_TRACE("(%d)", pSkid_num);

    (void)pSkid_num;

    original_HideSkid(pSkid_num);
}

static void(__cdecl*original_HideSkids)() = (void(__cdecl*)())0x004014ad;
CARM95_HOOK_FUNCTION(original_HideSkids, HideSkids)
void __cdecl HideSkids() {
    int skid;
    LOG_TRACE("()");

    (void)skid;

    original_HideSkids();
}

static br_scalar(__cdecl*original_SkidLen)(int) = (br_scalar(__cdecl*)(int))0x004021f1;
CARM95_HOOK_FUNCTION(original_SkidLen, SkidLen)
br_scalar __cdecl SkidLen(int pSkid) {
    LOG_TRACE("(%d)", pSkid);

    (void)pSkid;

    return original_SkidLen(pSkid);
}

void SkidSection(tCar_spec *pCar, int pWheel_num, br_vector3 *pPos, int pMaterial_index) {
    static tU16 skid;
    br_material *material;
    LOG_TRACE("(%p, %d, %p, %d)", pCar, pWheel_num, pPos, pMaterial_index);

    (void)pCar;
    (void)pWheel_num;
    (void)pPos;
    (void)pMaterial_index;
    (void)skid;
    (void)material;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_SkidMark)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x004014e5;
CARM95_HOOK_FUNCTION(original_SkidMark, SkidMark)
void __cdecl SkidMark(tCar_spec *pCar, int pWheel_num) {
    br_vector3 pos;
    br_vector3 world_pos;
    br_vector3 disp;
    br_vector3 spesh_to_wheel;
    int material_index;
    br_scalar dist;
    br_scalar dist2;
    int on_ground;
    br_material *material;
    LOG_TRACE("(%p, %d)", pCar, pWheel_num);

    (void)pCar;
    (void)pWheel_num;
    (void)pos;
    (void)world_pos;
    (void)disp;
    (void)spesh_to_wheel;
    (void)material_index;
    (void)dist;
    (void)dist2;
    (void)on_ground;
    (void)material;

    original_SkidMark(pCar, pWheel_num);
}

static void(__cdecl*original_InitCarSkidStuff)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00402282;
CARM95_HOOK_FUNCTION(original_InitCarSkidStuff, InitCarSkidStuff)
void __cdecl InitCarSkidStuff(tCar_spec *pCar) {
    int wheel;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)wheel;

    original_InitCarSkidStuff(pCar);
}

static void(__cdecl*original_SkidsPerFrame)() = (void(__cdecl*)())0x004022f1;
CARM95_HOOK_FUNCTION(original_SkidsPerFrame, SkidsPerFrame)
void __cdecl SkidsPerFrame() {
    int skid;
    LOG_TRACE("()");

    (void)skid;

    original_SkidsPerFrame();
}

void RemoveMaterialsFromSkidmarks() {
    int skid;
    LOG_TRACE("()");

    (void)skid;

    NOT_IMPLEMENTED();
}

