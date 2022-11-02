#include "brucetrk.h"

#include "brender/brender.h"
#include "errors.h"
#include "globvars.h"
#include "globvrbm.h"
#include "init.h"
#include "utility.h"
#include "world.h"
#include "pc-dos/dossys.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

br_actor ** hookvar_gMr_blendy  = (void*)0x0053e488;
int * hookvar_gDefault_blend_pc  = (void*)0x00550244;

function_hook_state_t function_hook_state_AllocateActorMatrix = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(AllocateActorMatrix, function_hook_state_AllocateActorMatrix)
static void(__cdecl*original_AllocateActorMatrix)(tTrack_spec *, br_actor ****) = (void(__cdecl*)(tTrack_spec *, br_actor ****))0x004a8a26;
CARM95_HOOK_FUNCTION(original_AllocateActorMatrix, AllocateActorMatrix)
void __cdecl AllocateActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pDst) {
    tU16 z;
    LOG_TRACE("(%p, %p)", pTrack_spec, pDst);

    (void)pTrack_spec;
    (void)pDst;
    (void)z;

    if (function_hook_state_AllocateActorMatrix == HOOK_ENABLED) {
        *pDst = BrMemAllocate(sizeof(br_actor***) * pTrack_spec->ncolumns_z, kMem_columns_z);
        for (z = 0; z < pTrack_spec->ncolumns_z; z++) {
            (*pDst)[z] = BrMemAllocate(sizeof(br_actor**) * pTrack_spec->ncolumns_x, kMem_columns_x);
            memset((*pDst)[z], 0, sizeof(br_actor**) * pTrack_spec->ncolumns_x);
        }
    } else {
        original_AllocateActorMatrix(pTrack_spec, pDst);
    }
}

function_hook_state_t function_hook_state_DisposeActorMatrix = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DisposeActorMatrix, function_hook_state_DisposeActorMatrix)
static void(__cdecl*original_DisposeActorMatrix)(tTrack_spec *, br_actor ****, int) = (void(__cdecl*)(tTrack_spec *, br_actor ****, int))0x004a8610;
CARM95_HOOK_FUNCTION(original_DisposeActorMatrix, DisposeActorMatrix)
void __cdecl DisposeActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pVictim, int pRemove_act_mod) {
    tU16 z;
    tU16 x;
    LOG_TRACE("(%p, %p, %d)", pTrack_spec, pVictim, pRemove_act_mod);

    (void)pTrack_spec;
    (void)pVictim;
    (void)pRemove_act_mod;
    (void)z;
    (void)x;

    if (function_hook_state_DisposeActorMatrix == HOOK_ENABLED) {
        if (*pVictim != NULL) {
            for (z = 0; z != pTrack_spec->ncolumns_z; z++) {
                if (pRemove_act_mod != 0) {
                    for (x = 0; x != pTrack_spec->ncolumns_x; x++) {
                        if ((*pVictim)[z][x] != NULL && (*pVictim)[z][x]->model != NULL) {
                            BrModelRemove((*pVictim)[z][x]->model);
                            BrModelFree((*pVictim)[z][x]->model);
                        }
                    }
                }
                BrMemFree((*pVictim)[z]);
            }
            BrMemFree(*pVictim);
        }
    } else {
        original_DisposeActorMatrix(pTrack_spec, pVictim, pRemove_act_mod);
    }
}

function_hook_state_t function_hook_state_DisposeColumns = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DisposeColumns, function_hook_state_DisposeColumns)
static void(__cdecl*original_DisposeColumns)(tTrack_spec *) = (void(__cdecl*)(tTrack_spec *))0x004a8590;
CARM95_HOOK_FUNCTION(original_DisposeColumns, DisposeColumns)
void __cdecl DisposeColumns(tTrack_spec *pTrack_spec) {
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;

    if (function_hook_state_DisposeColumns == HOOK_ENABLED) {
        DisposeActorMatrix(pTrack_spec, &pTrack_spec->columns, 0);
        DisposeActorMatrix(pTrack_spec, &pTrack_spec->lollipops, 0);
        if (HV(gAusterity_mode) == 0) {
            DisposeActorMatrix(pTrack_spec, &pTrack_spec->blends, 1);
        }
        if (pTrack_spec->non_car_list != NULL && (0 < pTrack_spec->ampersand_digits)) {
            BrMemFree(pTrack_spec->non_car_list);
        }
    } else {
        original_DisposeColumns(pTrack_spec);
    }
}

function_hook_state_t function_hook_state_XZToColumnXZ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(XZToColumnXZ, function_hook_state_XZToColumnXZ)
static void(__cdecl*original_XZToColumnXZ)(tU8 *, tU8 *, br_scalar, br_scalar, tTrack_spec *) = (void(__cdecl*)(tU8 *, tU8 *, br_scalar, br_scalar, tTrack_spec *))0x004a874b;
CARM95_HOOK_FUNCTION(original_XZToColumnXZ, XZToColumnXZ)
void __cdecl XZToColumnXZ(tU8 *pColumn_x, tU8 *pColumn_z, br_scalar pX, br_scalar pZ, tTrack_spec *pTrack_spec) {
    br_scalar x;
    br_scalar z;
    LOG_TRACE("(%p, %p, %f, %f, %p)", pColumn_x, pColumn_z, pX, pZ, pTrack_spec);

    (void)pColumn_x;
    (void)pColumn_z;
    (void)pX;
    (void)pZ;
    (void)pTrack_spec;
    (void)x;
    (void)z;

    if (function_hook_state_XZToColumnXZ == HOOK_ENABLED) {
        x = (pX - pTrack_spec->origin_x) / pTrack_spec->column_size_x;
        z = (pZ - pTrack_spec->origin_z) / pTrack_spec->column_size_z;
        if (x < 0.0f) {
            x = 0.0f;
        }
        if (x >= pTrack_spec->ncolumns_x) {
            x = pTrack_spec->ncolumns_x - 1.0f;
        }
        if (z < 0.0f) {
            z = 0.0f;
        }
        if (z >= pTrack_spec->ncolumns_z) {
            z = pTrack_spec->ncolumns_z - 1.0f;
        }
        *pColumn_x = x;
        *pColumn_z = z;
    } else {
        original_XZToColumnXZ(pColumn_x, pColumn_z, pX, pZ, pTrack_spec);
    }
}

function_hook_state_t function_hook_state_StripBlendedFaces = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(StripBlendedFaces, function_hook_state_StripBlendedFaces)
static void(__cdecl*original_StripBlendedFaces)(br_actor *, br_model *) = (void(__cdecl*)(br_actor *, br_model *))0x004a8d47;
CARM95_HOOK_FUNCTION(original_StripBlendedFaces, StripBlendedFaces)
void __cdecl StripBlendedFaces(br_actor *pActor, br_model *pModel) {
    int i;
    br_face *face;
    int changed_one;
    char s[256];
    static tU16 nfaces_allocated;
    LOG_TRACE("(%p, %p)", pActor, pModel);

    (void)pActor;
    (void)pModel;
    (void)i;
    (void)face;
    (void)changed_one;
    (void)s;
    (void)nfaces_allocated;

    if (function_hook_state_StripBlendedFaces == HOOK_ENABLED) {
        changed_one = 0;
        face = &pModel->faces[0];
        for (i = 0; i < pModel->nfaces; i++, face++) {
            if (face->material != NULL && face->material->identifier != NULL && ((face->material->identifier[0] == '!' && face->material->identifier[1] == '!' && HV(gDefault_blend_pc) != 0) || face->material->identifier[1] == '\\' )) {
                if (HV(gMr_blendy) == NULL) {
                    HV(gMr_blendy) = BrActorAllocate(BR_ACTOR_MODEL, NULL);
                    HV(gMr_blendy)->render_style = BR_RSTYLE_NONE;
                    HV(gMr_blendy)->model = BrModelAllocate(NULL, pModel->nvertices, pModel->nfaces);
                    nfaces_allocated = pModel->nfaces;
                    HV(gMr_blendy)->model->nfaces = 0;
                    HV(gMr_blendy)->model->flags |= BR_MODF_UPDATEABLE;
                    memcpy(HV(gMr_blendy)->model->vertices, pModel->vertices, pModel->nvertices * sizeof(br_vertex));
                }
                if (!AlreadyBlended(face->material)) {
                    if (face->material->identifier[1] == '\\') {
                        if (face->material->identifier[2] == '2') {
                            BlendifyMaterial(face->material, 25);
                        } else if (face->material->identifier[2] == '7') {
                            BlendifyMaterial(face->material, 75);
                        } else {
                            BlendifyMaterial(face->material, 50);
                        }
                        BrMaterialUpdate(face->material, BR_MATU_ALL);
                    }
                }
                if (nfaces_allocated <= HV(gMr_blendy)->model->nfaces) {
                    PDFatalError("Perfectly understandable error by Batwick, thank you very much Bruce.");
                }
                memcpy(&HV(gMr_blendy)->model->faces[HV(gMr_blendy)->model->nfaces], face, sizeof(br_face));
                HV(gMr_blendy)->model->nfaces++;
                if (i < (pModel->nfaces - 1)) {
                    memmove(&pModel->faces[i], &pModel->faces[i + 1], (pModel->nfaces - i - 1) * sizeof(br_face));
                }
                pModel->nfaces--;
                changed_one = 1;
                i--;
                face = &pModel->faces[i];
            }
        }
        if (changed_one) {
            if (pModel->nfaces != 0) {
                BrModelUpdate(pModel, BR_MODU_ALL);
            } else {
                pActor->model = NULL;
                pActor->type = BR_ACTOR_NONE;
            }
        }
    } else {
        original_StripBlendedFaces(pActor, pModel);
    }
}

function_hook_state_t function_hook_state_FindNonCarsCB = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(FindNonCarsCB, function_hook_state_FindNonCarsCB)
static br_uint_32(__cdecl*original_FindNonCarsCB)(br_actor *, tTrack_spec *) = (br_uint_32(__cdecl*)(br_actor *, tTrack_spec *))0x004a90ff;
CARM95_HOOK_FUNCTION(original_FindNonCarsCB, FindNonCarsCB)
br_uint_32 __cdecl FindNonCarsCB(br_actor *pActor, tTrack_spec *pTrack_spec) {
    int i;
    br_scalar r1;
    br_scalar r2;
    br_scalar r3;
    LOG_TRACE("(%p, %p)", pActor, pTrack_spec);

    (void)pActor;
    (void)pTrack_spec;
    (void)i;
    (void)r1;
    (void)r2;
    (void)r3;

    if (function_hook_state_FindNonCarsCB == HOOK_ENABLED) {
        if (pActor->identifier != NULL && pActor->identifier[0] == '&' && pActor->identifier[1] >= '0' && pActor->identifier[1] <= '9') {
            i = (pActor->identifier[4] - '0') * 1000 + (pActor->identifier[5] - '0') * 100 + (pActor->identifier[6] - '0') * 10 + (pActor->identifier[7] - '0');
            if (i < 0 || pTrack_spec->ampersand_digits <= i) {
                return 1;
            }
            r1 = BR_SQR3(pActor->t.t.mat.m[0][0], pActor->t.t.mat.m[0][1], pActor->t.t.mat.m[0][2]);
            r2 = BR_SQR3(pActor->t.t.mat.m[1][0], pActor->t.t.mat.m[1][1], pActor->t.t.mat.m[1][2]);
            r3 = BR_SQR3(pActor->t.t.mat.m[2][0], pActor->t.t.mat.m[2][1], pActor->t.t.mat.m[2][2]);
            if (r1 < .999f || r2 < .999f || r3 < .999f) {
                dr_dprintf("non car was scaled down %s", pActor->identifier);
                pActor->t.t.translate.t.v[0] += 2000.f;
            }
            if (r1 > 1.001f || r2 > 1.001f || r3 > 1.001f) {
                r1 = 1.f / sqrtf(r1);
                r2 = 1.f / sqrtf(r2);
                r3 = 1.f / sqrtf(r3);
                pActor->t.t.mat.m[0][0] *= r1;
                pActor->t.t.mat.m[0][1] *= r1;
                pActor->t.t.mat.m[0][2] *= r1;
                pActor->t.t.mat.m[1][0] *= r2;
                pActor->t.t.mat.m[1][1] *= r2;
                pActor->t.t.mat.m[1][2] *= r2;
                pActor->t.t.mat.m[2][0] *= r3;
                pActor->t.t.mat.m[2][1] *= r3;
                pActor->t.t.mat.m[2][2] *= r3;
                dr_dprintf("non car was scaled up %s", pActor->identifier);
            }
            pTrack_spec->non_car_list[i] = pActor;
            pActor->type_data = NULL;
            return 0;
        } else {
            if (pActor->model != NULL && !HV(gAusterity_mode) && pActor->identifier != NULL && pActor->identifier[0] != '&') {
                StripBlendedFaces(pActor, pActor->model);
            }
            return BrActorEnum(pActor, (br_actor_enum_cbfn*)FindNonCarsCB, pTrack_spec);
        }
    } else {
        return original_FindNonCarsCB(pActor, pTrack_spec);
    }
}

function_hook_state_t function_hook_state_ProcessModelsCB = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ProcessModelsCB, function_hook_state_ProcessModelsCB)
static br_uint_32(__cdecl*original_ProcessModelsCB)(br_actor *, tTrack_spec *) = (br_uint_32(__cdecl*)(br_actor *, tTrack_spec *))0x004a8afc;
CARM95_HOOK_FUNCTION(original_ProcessModelsCB, ProcessModelsCB)
br_uint_32 __cdecl ProcessModelsCB(br_actor *pActor, tTrack_spec *pTrack_spec) {
    unsigned int x;
    unsigned int z;
    int group;
    LOG_TRACE("(%p, %p)", pActor, pTrack_spec);

    (void)pActor;
    (void)pTrack_spec;
    (void)x;
    (void)z;
    (void)group;

    if (function_hook_state_ProcessModelsCB == HOOK_ENABLED) {
        if (sscanf(pActor->identifier, "%u%u", &x, &z) == 2 && pTrack_spec->ncolumns_x > x && pTrack_spec->ncolumns_z > z) {
            pActor->material = HV(gDefault_track_material);
            pTrack_spec->columns[z][x] = pActor;
            HV(gMr_blendy) = NULL;
            if (pActor->model && !HV(gAusterity_mode)) {
                StripBlendedFaces(pActor, pActor->model);
            }
            BrActorEnum(pActor, (br_actor_enum_cbfn*)FindNonCarsCB, pTrack_spec);
            if (HV(gMr_blendy)) {
                BrActorAdd(pActor, HV(gMr_blendy));
                BrModelAdd(HV(gMr_blendy)->model);
                for (group = 0; V11MODEL(HV(gMr_blendy)->model)->ngroups > group; ++group) {
                    V11MODEL(HV(gMr_blendy)->model)->groups[group].face_colours_material = HV(gMr_blendy)->model->faces[*V11MODEL(HV(gMr_blendy)->model)->groups[group].face_user].material;
                }
                HV(gMr_blendy)->model->flags &= ~BR_MODF_UPDATEABLE;
                DodgyModelUpdate(HV(gMr_blendy)->model);
                pTrack_spec->blends[z][x] = HV(gMr_blendy);
            }
        } else if (*pActor->identifier == '%' && sscanf((const char*)pActor->identifier + 1, "%u%u", &x, &z) == 2 && pTrack_spec->ncolumns_x > x && pTrack_spec->ncolumns_z > z) {
            pTrack_spec->lollipops[z][x] = pActor;
        } else {
            BrActorEnum(pActor, (br_actor_enum_cbfn*)ProcessModelsCB, pTrack_spec);
        }
        return 0;
    } else {
        return original_ProcessModelsCB(pActor, pTrack_spec);
    }
}

function_hook_state_t function_hook_state_ProcessModels = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ProcessModels, function_hook_state_ProcessModels)
static void(__cdecl*original_ProcessModels)(tTrack_spec *) = (void(__cdecl*)(tTrack_spec *))0x004a8ad9;
CARM95_HOOK_FUNCTION(original_ProcessModels, ProcessModels)
void __cdecl ProcessModels(tTrack_spec *pTrack_spec) {
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;

    if (function_hook_state_ProcessModels == HOOK_ENABLED) {
        BrActorEnum(pTrack_spec->the_actor, (br_actor_enum_cbfn*)ProcessModelsCB, pTrack_spec);
    } else {
        original_ProcessModels(pTrack_spec);
    }
}

function_hook_state_t function_hook_state_ExtractColumns = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ExtractColumns, function_hook_state_ExtractColumns)
static void(__cdecl*original_ExtractColumns)(tTrack_spec *) = (void(__cdecl*)(tTrack_spec *))0x004a884d;
CARM95_HOOK_FUNCTION(original_ExtractColumns, ExtractColumns)
void __cdecl ExtractColumns(tTrack_spec *pTrack_spec) {
    unsigned int x;
    unsigned int z;
    int ad;
    int unsplit;
    float e;
    br_scalar extra_room;
    br_bounds bounds;
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;
    (void)x;
    (void)z;
    (void)ad;
    (void)unsplit;
    (void)e;
    (void)extra_room;
    (void)bounds;

    if (function_hook_state_ExtractColumns == HOOK_ENABLED) {
        unsplit = 0;
        switch (sscanf(pTrack_spec->the_actor->identifier, "%u%u%f%d", &x, &z, &extra_room, &ad)) {
            case 3:
                BrFailure(
                        "Attempt to extract columns from invalid track\n"
                        "(It might have been produced by an ancient preproc.\n"
                        "This is no longer supported.\n");
                break;

            case 4:
                pTrack_spec->ampersand_digits = ad;
                break;

            default:
                unsplit = 1;
                x = 1;
                z = 1;
                extra_room = 0.0;
                pTrack_spec->ampersand_digits = 0;
        }
        pTrack_spec->ncolumns_x = x;
        pTrack_spec->ncolumns_z = z;

        BrActorToBounds(&bounds, pTrack_spec->the_actor);
        pTrack_spec->column_size_x = (bounds.max.v[0] - bounds.min.v[0] + extra_room * 2.0) / (double)pTrack_spec->ncolumns_x;
        pTrack_spec->column_size_z = (bounds.max.v[2] - bounds.min.v[2] + extra_room * 2.0) / (double)pTrack_spec->ncolumns_z;
        pTrack_spec->origin_x = bounds.min.v[0] - extra_room;
        pTrack_spec->origin_z = bounds.min.v[2] - extra_room;
        AllocateActorMatrix(pTrack_spec, &pTrack_spec->columns);
        AllocateActorMatrix(pTrack_spec, &pTrack_spec->lollipops);
        AllocateActorMatrix(pTrack_spec, &pTrack_spec->blends);
        if (pTrack_spec->ampersand_digits <= 0) {
            pTrack_spec->non_car_list = NULL;
        } else {
            pTrack_spec->non_car_list = BrMemAllocate(sizeof(br_actor*) * pTrack_spec->ampersand_digits, kMem_non_car_list);
        }
        if (unsplit) {
            **pTrack_spec->columns = pTrack_spec->the_actor;
        } else {
            ProcessModels(pTrack_spec);
        }
    } else {
        original_ExtractColumns(pTrack_spec);
    }
}

function_hook_state_t function_hook_state_LollipopizeActor4 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LollipopizeActor4, function_hook_state_LollipopizeActor4)
void LollipopizeActor4(br_actor *pActor, br_matrix34 *pRef_to_world, br_actor *pCamera) {
    LOG_TRACE("(%p, %p, %p)", pActor, pRef_to_world, pCamera);

    (void)pActor;
    (void)pRef_to_world;
    (void)pCamera;

    if (function_hook_state_LollipopizeActor4 == HOOK_ENABLED) {
        pActor->t.t.mat.m[1][0] = 0.0;
        pActor->t.t.mat.m[1][1] = 1.0;
        pActor->t.t.mat.m[1][2] = 0.0;
        pActor->t.t.mat.m[2][0] = pRef_to_world->m[2][0];
        pActor->t.t.mat.m[2][1] = pRef_to_world->m[2][1];
        pActor->t.t.mat.m[2][2] = pRef_to_world->m[2][2];
        pActor->t.t.mat.m[0][0] = pActor->t.t.mat.m[1][1] * pActor->t.t.mat.m[2][2]
                                  - pActor->t.t.mat.m[1][2] * pActor->t.t.mat.m[2][1];
        pActor->t.t.mat.m[0][1] = pActor->t.t.mat.m[1][2] * pActor->t.t.mat.m[2][0]
                                  - pActor->t.t.mat.m[1][0] * pActor->t.t.mat.m[2][2];
        pActor->t.t.mat.m[0][2] = pActor->t.t.mat.m[2][1] * pActor->t.t.mat.m[1][0]
                                  - pActor->t.t.mat.m[1][1] * pActor->t.t.mat.m[2][0];
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_LollipopizeChildren = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LollipopizeChildren, function_hook_state_LollipopizeChildren)
br_uint_32 LollipopizeChildren(br_actor *pActor, void *pArg) {
    tMatrix_and_actor *maa;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)maa;

    if (function_hook_state_LollipopizeChildren == HOOK_ENABLED) {
        maa = pArg;
        LollipopizeActor4(pActor, maa->m, maa->a);
        return 0;
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DrawColumns = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DrawColumns, function_hook_state_DrawColumns)
static void(__cdecl*original_DrawColumns)(int, tTrack_spec *, int, int, int, int, br_matrix34 *) = (void(__cdecl*)(int, tTrack_spec *, int, int, int, int, br_matrix34 *))0x004a9a01;
CARM95_HOOK_FUNCTION(original_DrawColumns, DrawColumns)
void __cdecl DrawColumns(int pDraw_blends, tTrack_spec *pTrack_spec, int pMin_x, int pMax_x, int pMin_z, int pMax_z, br_matrix34 *pCamera_to_world) {
    tU8 column_x;
    tU8 column_z;
    tU8 column_x2;
    tU8 column_z2;
    tMatrix_and_actor maa;
    br_actor *blended_polys;
    LOG_TRACE("(%d, %p, %d, %d, %d, %d, %p)", pDraw_blends, pTrack_spec, pMin_x, pMax_x, pMin_z, pMax_z, pCamera_to_world);

    (void)pDraw_blends;
    (void)pTrack_spec;
    (void)pMin_x;
    (void)pMax_x;
    (void)pMin_z;
    (void)pMax_z;
    (void)pCamera_to_world;
    (void)column_x;
    (void)column_z;
    (void)column_x2;
    (void)column_z2;
    (void)maa;
    (void)blended_polys;

    if (function_hook_state_DrawColumns == HOOK_ENABLED) {
        maa.m = pCamera_to_world;
        if (fabs(pCamera_to_world->m[2][2]) >= fabs(pCamera_to_world->m[2][0])) {
            for (column_z = pMin_z; column_z <= pMax_z; ++column_z) {
                for (column_x = pMin_x; column_x <= pMax_x; ++column_x) {
                    if (pCamera_to_world->m[2][0] <= 0.0) {
                        column_x2 = pMin_x + pMax_x - column_x;
                    } else {
                        column_x2 = column_x;
                    }
                    if (pCamera_to_world->m[2][2] <= 0.0) {
                        column_z2 = pMax_z + pMin_z - column_z;
                    } else {
                        column_z2 = column_z;
                    }
                    if (pDraw_blends) {
                        blended_polys = pTrack_spec->blends[column_z2][column_x2];
                        if (blended_polys) {
                            blended_polys->render_style = BR_RSTYLE_FACES;
                            BrZbSceneRenderAdd(blended_polys);
                            blended_polys->render_style = BR_RSTYLE_NONE;
                        }
                    } else {
                        if (pTrack_spec->columns[column_z2][column_x2]) {
                            BrZbSceneRenderAdd(pTrack_spec->columns[column_z2][column_x2]);
                        }
                        if (pTrack_spec->lollipops[column_z2][column_x2]) {
                            maa.a = pTrack_spec->lollipops[column_z2][column_x2];
                            BrActorEnum(pTrack_spec->lollipops[column_z2][column_x2], (void*)LollipopizeChildren, &maa);
                            BrZbSceneRenderAdd(pTrack_spec->lollipops[column_z2][column_x2]);
                        }
                    }
                }
            }
        } else {
            for (column_x = pMin_x; column_x <= pMax_x; ++column_x) {
                for (column_z = pMin_z; column_z <= pMax_z; ++column_z) {
                    if (pCamera_to_world->m[2][0] <= 0.0) {
                        column_x2 = pMin_x + pMax_x - column_x;
                    } else {
                        column_x2 = column_x;
                    }
                    if (pCamera_to_world->m[2][2] <= 0.0) {
                        column_z2 = pMax_z + pMin_z - column_z;
                    } else {
                        column_z2 = column_z;
                    }
                    if (pDraw_blends) {
                        blended_polys = pTrack_spec->blends[column_z2][column_x2];
                        if (blended_polys) {
                            blended_polys->render_style = 4;
                            BrZbSceneRenderAdd(blended_polys);
                            blended_polys->render_style = 1;
                        }
                    } else {
                        if (pTrack_spec->columns[column_z2][column_x2]) {
                            BrZbSceneRenderAdd(pTrack_spec->columns[column_z2][column_x2]);
                        }
                        if (pTrack_spec->lollipops[column_z2][column_x2]) {
                            maa.a = pTrack_spec->lollipops[column_z2][column_x2];
                            BrActorEnum(pTrack_spec->lollipops[column_z2][column_x2], (void*)LollipopizeChildren, &maa);
                            BrZbSceneRenderAdd(pTrack_spec->lollipops[column_z2][column_x2]);
                        }
                    }
                }
            }
        }
    } else {
        original_DrawColumns(pDraw_blends, pTrack_spec, pMin_x, pMax_x, pMin_z, pMax_z, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_RenderTrack = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(RenderTrack, function_hook_state_RenderTrack)
static void(__cdecl*original_RenderTrack)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int) = (void(__cdecl*)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int))0x004a944a;
CARM95_HOOK_FUNCTION(original_RenderTrack, RenderTrack)
void __cdecl RenderTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world, int pRender_blends) {
    static tU8 column_x;
    static tU8 column_z;
    static tU8 min_x;
    static tU8 max_x;
    static tU8 min_z;
    static tU8 max_z;
    static br_vector3 edge_before;
    static br_vector3 edge_after;
    static br_camera *camera;
    static br_scalar tan_fov_ish;
    static br_actor *result;
    LOG_TRACE("(%p, %p, %p, %p, %d)", pWorld, pTrack_spec, pCamera, pCamera_to_world, pRender_blends);

    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pRender_blends;
    (void)column_x;
    (void)column_z;
    (void)min_x;
    (void)max_x;
    (void)min_z;
    (void)max_z;
    (void)edge_before;
    (void)edge_after;
    (void)camera;
    (void)tan_fov_ish;
    (void)result;

    if (function_hook_state_RenderTrack == HOOK_ENABLED) {
        if (pTrack_spec->columns != NULL) {
            if (pRender_blends) {
                DrawColumns(1, pTrack_spec, min_x, max_x, min_z, max_z, pCamera_to_world);
            } else {
                camera = (br_camera*)pCamera->type_data;
                XZToColumnXZ(&column_x, &column_z, pCamera_to_world->m[3][0], pCamera_to_world->m[3][2], pTrack_spec);
                min_x = column_x;
                max_x = column_x;
                min_z = column_z;
                max_z = column_z;
                tan_fov_ish = sinf(BrAngleToRadian(camera->field_of_view / 2)) / cosf(BrAngleToRadian(camera->field_of_view / 2));
                edge_after.v[0] = camera->aspect * tan_fov_ish;
                edge_after.v[1] = tan_fov_ish;
                edge_after.v[2] = -1.0;
                edge_before.v[0] = camera->yon_z * HV(gYon_factor) * edge_after.v[0];
                edge_before.v[1] = camera->yon_z * HV(gYon_factor) * tan_fov_ish;
                edge_before.v[2] = camera->yon_z * HV(gYon_factor) * -1.0;
                BrMatrix34ApplyV(&edge_after, &edge_before, pCamera_to_world);
                XZToColumnXZ(&column_x, &column_z, pCamera_to_world->m[3][0] + edge_after.v[0], pCamera_to_world->m[3][2] + edge_after.v[2], pTrack_spec);
                if (column_x < min_x) {
                    min_x = column_x;
                } else if (column_x > max_x) {
                    max_x = column_x;
                }
                if (column_z < min_z) {
                    min_z = column_z;
                } else if (column_z > max_z) {
                    max_z = column_z;
                }
                edge_before.v[0] = -edge_before.v[0];
                BrMatrix34ApplyV(&edge_after, &edge_before, pCamera_to_world);
                XZToColumnXZ(&column_x, &column_z, pCamera_to_world->m[3][0] + edge_after.v[0], pCamera_to_world->m[3][2] + edge_after.v[2], pTrack_spec);
                if (column_x < min_x) {
                    min_x = column_x;
                } else if (column_x > max_x) {
                    max_x = column_x;
                }
                if (column_z >= min_z) {
                    if (column_z > max_z) {
                        max_z = column_z;
                    }
                } else {
                    min_z = column_z;
                }
                edge_before.v[1] = -edge_before.v[1];
                BrMatrix34ApplyV(&edge_after, &edge_before, pCamera_to_world);
                XZToColumnXZ(&column_x, &column_z, pCamera_to_world->m[3][0] + edge_after.v[0], pCamera_to_world->m[3][2] + edge_after.v[2], pTrack_spec);
                if (column_x < min_x) {
                    min_x = column_x;
                } else if (column_x > max_x) {
                    max_x = column_x;
                }
                if (column_z < min_z) {
                    min_z = column_z;
                } else if (column_z > max_z) {
                    max_z = column_z;
                }
                edge_before.v[0] = -edge_before.v[0];
                BrMatrix34ApplyV(&edge_after, &edge_before, pCamera_to_world);
                XZToColumnXZ(&column_x, &column_z, pCamera_to_world->m[3][0] + edge_after.v[0], pCamera_to_world->m[3][2] + edge_after.v[2], pTrack_spec);
                if (column_x < min_x) {
                    min_x = column_x;
                } else if (column_x > max_x) {
                    max_x = column_x;
                }
                if (column_z < min_z) {
                    min_z = column_z;
                } else if (column_z > max_z) {
                    max_z = column_z;
                }
                if (min_x != 0) {
                    min_x--;
                }
                if (pTrack_spec->ncolumns_x - 1 > max_x) {
                    max_x++;
                }
                if (min_z != 0) {
                    min_z--;
                }
                if (pTrack_spec->ncolumns_z - 1 > max_z) {
                    max_z++;
                }
                DrawColumns(0, pTrack_spec, min_x, max_x, min_z, max_z, pCamera_to_world);
            }
        } else {
            BrZbSceneRenderAdd(pWorld);
        }
    } else {
        original_RenderTrack(pWorld, pTrack_spec, pCamera, pCamera_to_world, pRender_blends);
    }
}

function_hook_state_t function_hook_state_GetYonFactor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GetYonFactor, function_hook_state_GetYonFactor)
static br_scalar(__cdecl*original_GetYonFactor)() = (br_scalar(__cdecl*)())0x004a9e6e;
CARM95_HOOK_FUNCTION(original_GetYonFactor, GetYonFactor)
br_scalar __cdecl GetYonFactor() {
    LOG_TRACE("()");


    if (function_hook_state_GetYonFactor == HOOK_ENABLED) {
        return HV(gYon_factor);
    } else {
        return original_GetYonFactor();
    }
}

function_hook_state_t function_hook_state_SetYonFactor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetYonFactor, function_hook_state_SetYonFactor)
static void(__cdecl*original_SetYonFactor)(br_scalar) = (void(__cdecl*)(br_scalar))0x004a9e84;
CARM95_HOOK_FUNCTION(original_SetYonFactor, SetYonFactor)
void __cdecl SetYonFactor(br_scalar pNew) {
    LOG_TRACE("(%f)", pNew);

    (void)pNew;

    if (function_hook_state_SetYonFactor == HOOK_ENABLED) {
        HV(gYon_factor) = pNew;
    } else {
        original_SetYonFactor(pNew);
    }
}

