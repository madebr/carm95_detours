#include "piping.h"

#include "car.h"
#include "crush.h"
#include "errors.h"
#include "globvars.h"
#include "globvrpb.h"
#include "graphics.h"
#include "oil.h"
#include "pc-dos/dossys.h"
#include "opponent.h"
#include "pedestrn.h"
#include "replay.h"
#include "skidmark.h"
#include "sound.h"
#include "spark.h"
#include "utility.h"
#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tU8 ** hookvar_gPipe_buffer_start  = (void*)0x0050ba00;
int * hookvar_gDisable_sound  = (void*)0x0050ba04;
int * hookvar_gDisable_advance  = (void*)0x0050ba08;
int * hookvar_gMax_rewind_chunks  = (void*)0x0050ba0c;
float * hookvar_gWall_severity  = (void*)0x0050ba10;
tPipe_reset_proc*(* hookvar_gReset_procs )[32] = (void*)0x0050ba18;
#if 0
tPiped_registration_snapshot(* hookvar_gRegistration_snapshots )[5];
#endif
tPipe_smudge_data ** hookvar_gSmudge_space  = (void*)0x00531ffc;
tU32 * hookvar_gOldest_time  = (void*)0x00531ff8;
#if 0
int * hookvar_gCurrent_snapshot_registration_index ;
#endif
tPipe_chunk ** hookvar_gMr_chunky  = (void*)0x00531fa0;
tCar_spec ** hookvar_gCar_ptr  = (void*)0x00532040;
br_vector3 * hookvar_gZero_vector  = (void*)0x00532068;
tPipe_chunk_type(* hookvar_gReentrancy_array )[5] = (void*)0x00532050;
#if 0
tU32 * hookvar_gLast_time ;
#endif
tPipe_model_geometry_data ** hookvar_gModel_geometry_space  = (void*)0x0053204c;
#if 0
tU32 * hookvar_gEnd_time ;
#endif
tU32 * hookvar_gTrigger_time  = (void*)0x00532094;
int * hookvar_gReentrancy_count  = (void*)0x00532074;
br_vector3 * hookvar_gCar_pos  = (void*)0x00532030;
br_vector3 * hookvar_gReference_pos  = (void*)0x00532020;
br_scalar * hookvar_gMax_distance  = (void*)0x00532004;
#if 0
tU32 * hookvar_gLoop_abort_time ;
#endif
br_vector3 * hookvar_gWall_impact_point  = (void*)0x00532078;
tU8 ** hookvar_gPipe_buffer_working_end  = (void*)0x00532044;
tU32 * hookvar_gYoungest_time  = (void*)0x00532084;
tU8 ** hookvar_gPipe_buffer_phys_end  = (void*)0x0053208c;
#if 0
tU8 ** hookvar_gLocal_buffer_record_ptr ;
#endif
tU8 ** hookvar_gPipe_play_ptr  = (void*)0x00532018;
tU8 ** hookvar_gEnd_of_session  = (void*)0x00532048;
tU8 ** hookvar_gPipe_record_ptr  = (void*)0x0053201c;
tU8 ** hookvar_gPipe_buffer_oldest  = (void*)0x0053200c;
tU32 * hookvar_gPipe_buffer_size  = (void*)0x00532088;
tU8 ** hookvar_gLocal_buffer  = (void*)0x00532014;
tU32 * hookvar_gLocal_buffer_size  = (void*)0x00532090;
tPipe_chunk ** hookvar_gIncidentChunk = (void*)0x0053203c; // FIXME: added by DethRace (really needed?)

#define LOCAL_BUFFER_SIZE 15000

function_hook_state_t function_hook_state_GetReducedPos = HOOK_ENABLED;
static void(__cdecl*original_GetReducedPos)(br_vector3 *, tReduced_pos *) = (void(__cdecl*)(br_vector3 *, tReduced_pos *))0x00427ed0;
CARM95_HOOK_FUNCTION(original_GetReducedPos, GetReducedPos)
void __cdecl GetReducedPos(br_vector3 *v, tReduced_pos *p) {
    LOG_TRACE("(%p, %p)", v, p);

    (void)v;
    (void)p;

    if (function_hook_state_GetReducedPos == HOOK_ENABLED) {
        v->v[0] = p->v[0] / 800.f;
        v->v[1] = p->v[1] / 800.f;
        v->v[2] = p->v[2] / 800.f;
        BrVector3Accumulate(v, &HV(gProgram_state).current_car.car_master_actor->t.t.translate.t);
    } else {
        original_GetReducedPos(v, p);
    }
}

function_hook_state_t function_hook_state_SaveReducedPos = HOOK_ENABLED;
static void(__cdecl*original_SaveReducedPos)(tReduced_pos *, br_vector3 *) = (void(__cdecl*)(tReduced_pos *, br_vector3 *))0x00427f61;
CARM95_HOOK_FUNCTION(original_SaveReducedPos, SaveReducedPos)
void __cdecl SaveReducedPos(tReduced_pos *p, br_vector3 *v) {
    br_vector3 tv;
    LOG_TRACE("(%p, %p)", p, v);

    (void)p;
    (void)v;
    (void)tv;

    if (function_hook_state_SaveReducedPos == HOOK_ENABLED) {
        BrVector3Sub(&tv, v, &HV(gProgram_state).current_car.car_master_actor->t.t.translate.t);
        p->v[0] = tv.v[0] * 800.f;
        p->v[1] = tv.v[1] * 800.f;
        p->v[2] = tv.v[2] * 800.f;
    } else {
        original_SaveReducedPos(p, v);
    }
}

function_hook_state_t function_hook_state_PipeSearchForwards = HOOK_ENABLED;
static int(__cdecl*original_PipeSearchForwards)() = (int(__cdecl*)())0x00427fdf;
CARM95_HOOK_FUNCTION(original_PipeSearchForwards, PipeSearchForwards)
int __cdecl PipeSearchForwards() {
    LOG_TRACE("()");


    if (function_hook_state_PipeSearchForwards == HOOK_ENABLED) {
        if (HV(gPipe_play_ptr) == HV(gPipe_record_ptr)) {
            return 0;
        }
        if (HV(gPipe_play_ptr) == HV(gPipe_buffer_oldest)) {
            return 1;
        }
        if (GetReplayRate() == 0.f) {
            return GetReplayDirection() > 0;
        } else {
            return GetReplayRate() > 0.f;
        }
    } else {
        return original_PipeSearchForwards();
    }
}

function_hook_state_t function_hook_state_IsActionReplayAvailable = HOOK_ENABLED;
static int(__cdecl*original_IsActionReplayAvailable)() = (int(__cdecl*)())0x00428078;
CARM95_HOOK_FUNCTION(original_IsActionReplayAvailable, IsActionReplayAvailable)
int __cdecl IsActionReplayAvailable() {
    LOG_TRACE("()");


    if (function_hook_state_IsActionReplayAvailable == HOOK_ENABLED) {
        return HV(gPipe_buffer_start) != NULL;
    } else {
        return original_IsActionReplayAvailable();
    }
}

function_hook_state_t function_hook_state_SomeReplayLeft = HOOK_ENABLED;
static int(__cdecl*original_SomeReplayLeft)() = (int(__cdecl*)())0x004280a1;
CARM95_HOOK_FUNCTION(original_SomeReplayLeft, SomeReplayLeft)
int __cdecl SomeReplayLeft() {
    LOG_TRACE("()");


    if (function_hook_state_SomeReplayLeft == HOOK_ENABLED) {
        return ((GetReplayDirection() >= 1 && HV(gPipe_play_ptr) != HV(gPipe_record_ptr)) ||
            (GetReplayDirection() <= -1 && HV(gPipe_play_ptr) != HV(gPipe_buffer_oldest)));
    } else {
        return original_SomeReplayLeft();
    }
}

function_hook_state_t function_hook_state_DisablePipedSounds = HOOK_ENABLED;
static void(__cdecl*original_DisablePipedSounds)() = (void(__cdecl*)())0x004280f9;
CARM95_HOOK_FUNCTION(original_DisablePipedSounds, DisablePipedSounds)
void __cdecl DisablePipedSounds() {
    LOG_TRACE("()");


    if (function_hook_state_DisablePipedSounds == HOOK_ENABLED) {
        HV(gDisable_sound) = 1;
    } else {
        original_DisablePipedSounds();
    }
}

function_hook_state_t function_hook_state_EnablePipedSounds = HOOK_ENABLED;
static void(__cdecl*original_EnablePipedSounds)() = (void(__cdecl*)())0x0042810e;
CARM95_HOOK_FUNCTION(original_EnablePipedSounds, EnablePipedSounds)
void __cdecl EnablePipedSounds() {
    LOG_TRACE("()");


    if (function_hook_state_EnablePipedSounds == HOOK_ENABLED) {
        HV(gDisable_sound) = 0;
    } else {
        original_EnablePipedSounds();
    }
}

function_hook_state_t function_hook_state_LengthOfSession = HOOK_ENABLED;
static tU32(__cdecl*original_LengthOfSession)(tPipe_session *) = (tU32(__cdecl*)(tPipe_session *))0x00428123;
CARM95_HOOK_FUNCTION(original_LengthOfSession, LengthOfSession)
tU32 __cdecl LengthOfSession(tPipe_session *pSession) {
    int i;
    tU32 running_total;
    tPipe_chunk *the_chunk;
    LOG_TRACE("(%p)", pSession);

    (void)pSession;
    (void)i;
    (void)running_total;
    (void)the_chunk;

    if (function_hook_state_LengthOfSession == HOOK_ENABLED) {

#define SIZEOF_CHUNK(MEMBER) (offsetof(tPipe_chunk, chunk_data) + sizeof(pSession->chunks.chunk_data.MEMBER))
#define ROUND_UP(V, M) (((V) + (M) - 1) & (~((M) - 1)))

    switch ((int)pSession->chunk_type) {
        case ePipe_chunk_actor_rstyle:
            running_total = SIZEOF_CHUNK(actor_rstyle_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_actor_translate:
            running_total = SIZEOF_CHUNK(actor_translate_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_actor_transform:
            running_total = SIZEOF_CHUNK(actor_transform_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_actor_create:
            running_total = 0;
            break;
        case ePipe_chunk_actor_destroy:
            running_total = 0;
            break;
        case ePipe_chunk_actor_relink:
            running_total = SIZEOF_CHUNK(actor_relink_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_actor_material:
            running_total = SIZEOF_CHUNK(actor_material_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_face_material:
            running_total = SIZEOF_CHUNK(face_material_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_material_trans:
            running_total = SIZEOF_CHUNK(material_trans_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_material_pixelmap:
            running_total = SIZEOF_CHUNK(material_pixelmap_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_model_geometry:
            running_total = 0;
            for (i = 0; i < pSession->number_of_chunks; i++) {
                the_chunk = (tPipe_chunk*)&((tU8*)&pSession->chunks)[running_total];
                running_total += the_chunk->chunk_data.model_geometry_data.vertex_count * sizeof(tChanged_vertex) + offsetof(tPipe_model_geometry_data, vertex_changes) + offsetof(tPipe_chunk, chunk_data);
            }
            break;
        case ePipe_chunk_pedestrian:
            running_total = 0;
            for (i = 0; i < pSession->number_of_chunks; i++) {
                the_chunk = (tPipe_chunk*)&(((tU8*)&pSession->chunks)[running_total]);
                if (the_chunk->chunk_data.pedestrian_data.hit_points <= 0) {
                    running_total += SIZEOF_CHUNK(pedestrian_data);
                } else {
                    running_total += offsetof(tPipe_pedestrian_data, spin_period) + offsetof(tPipe_chunk, chunk_data);
                }
            }
            break;
        case ePipe_chunk_frame_boundary:
            running_total = SIZEOF_CHUNK(frame_boundary_data);
            break;
        case ePipe_chunk_car:
            running_total = SIZEOF_CHUNK(car_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_sound:
            running_total = SIZEOF_CHUNK(sound_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_damage:
            running_total = SIZEOF_CHUNK(damage_data);
            break;
        case ePipe_chunk_special:
            running_total = SIZEOF_CHUNK(special_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_ped_gib:
            running_total = SIZEOF_CHUNK(ped_gib_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_incident:
            running_total = SIZEOF_CHUNK(incident_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_spark:
            running_total = SIZEOF_CHUNK(spark_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_shrapnel:
            running_total = 0;
            for (i = 0; i < pSession->number_of_chunks; i++) {
                the_chunk = (tPipe_chunk*)&((tU8*)&pSession->chunks)[running_total];
                if (the_chunk->subject_index & 0x8000) {
                    running_total += SIZEOF_CHUNK(shrapnel_data);
                } else {
                    running_total += offsetof(tPipe_shrapnel_data, age) + offsetof(tPipe_chunk, chunk_data);
                }
            }
            break;
        case ePipe_chunk_screen_shake:
            running_total = SIZEOF_CHUNK(screen_shake_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_groove_stop:
            running_total = SIZEOF_CHUNK(groove_stop_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_non_car:
            running_total = SIZEOF_CHUNK(non_car_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_smoke:
            running_total = SIZEOF_CHUNK(smoke_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_oil_spill:
            running_total = SIZEOF_CHUNK(oil_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_smoke_column:
            running_total = ROUND_UP(SIZEOF_CHUNK(smoke_column_data), 4) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_flame:
            running_total = SIZEOF_CHUNK(flame_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_smudge:
            running_total = 0;
            for (i = 0; i < pSession->number_of_chunks; i++) {
                the_chunk = (tPipe_chunk*)&((tU8*)&pSession->chunks)[running_total];
                running_total += the_chunk->chunk_data.smudge_data.vertex_count * sizeof(tSmudged_vertex) + offsetof(tPipe_smudge_data, vertex_changes) + sizeof(int);
            }
            break;
        case ePipe_chunk_splash:
            running_total = SIZEOF_CHUNK(splash_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_prox_ray:
            running_total = SIZEOF_CHUNK(prox_ray_data) * pSession->number_of_chunks;
            break;
        case ePipe_chunk_skid_adjustment:
            running_total = SIZEOF_CHUNK(skid_adjustment) * pSession->number_of_chunks;
            break;
        default:
            running_total = 0;
            break;
    }
    running_total += offsetof(tPipe_session, chunks) + sizeof(tU16);
    if (running_total % 2 != 0) {
        FatalError(98);
    }
    assert(original_LengthOfSession(pSession) == running_total);
    return running_total;
    } else {
        return original_LengthOfSession(pSession);
    }
}

function_hook_state_t function_hook_state_StartPipingSession2 = HOOK_ENABLED;
static void(__cdecl*original_StartPipingSession2)(tPipe_chunk_type, int) = (void(__cdecl*)(tPipe_chunk_type, int))0x004285e1;
CARM95_HOOK_FUNCTION(original_StartPipingSession2, StartPipingSession2)
void __cdecl StartPipingSession2(tPipe_chunk_type pThe_type, int pMunge_reentrancy) {
    LOG_TRACE("(%d, %d)", pThe_type, pMunge_reentrancy);

    (void)pThe_type;
    (void)pMunge_reentrancy;

    if (function_hook_state_StartPipingSession2 == HOOK_ENABLED) {
        if (HV(gPipe_buffer_start) != NULL && !HV(gAction_replay_mode) && HV(gProgram_state).racing) {
            if (pMunge_reentrancy) {
                if (HV(gReentrancy_count) != 0) {
                    HV(gReentrancy_array)[HV(gReentrancy_count) - 1] = ((tPipe_session *) HV(
                            gLocal_buffer))->chunk_type;
                    EndPipingSession2(0);
                }
                HV(gReentrancy_count)++;
            }
            ((tPipe_session *) HV(gLocal_buffer))->chunk_type = pThe_type;
            ((tPipe_session *) HV(gLocal_buffer))->number_of_chunks = 0;
            HV(gLocal_buffer_size) = offsetof(tPipe_session, chunks);
            HV(gMr_chunky) = &((tPipe_session *) HV(gLocal_buffer))->chunks;
        }
    } else {
        original_StartPipingSession2(pThe_type, pMunge_reentrancy);
    }
}

function_hook_state_t function_hook_state_StartPipingSession = HOOK_ENABLED;
static void(__cdecl*original_StartPipingSession)(tPipe_chunk_type) = (void(__cdecl*)(tPipe_chunk_type))0x0042868f;
CARM95_HOOK_FUNCTION(original_StartPipingSession, StartPipingSession)
void __cdecl StartPipingSession(tPipe_chunk_type pThe_type) {
    LOG_TRACE("(%d)", pThe_type);

    (void)pThe_type;

    if (function_hook_state_StartPipingSession == HOOK_ENABLED) {
        StartPipingSession2(pThe_type, 1);
    } else {
        original_StartPipingSession(pThe_type);
    }
}

function_hook_state_t function_hook_state_EndPipingSession2 = HOOK_ENABLED;
static void(__cdecl*original_EndPipingSession2)(int) = (void(__cdecl*)(int))0x004286a8;
CARM95_HOOK_FUNCTION(original_EndPipingSession2, EndPipingSession2)
void __cdecl EndPipingSession2(int pMunge_reentrancy) {
    int a;
    LOG_TRACE("(%d)", pMunge_reentrancy);

    (void)pMunge_reentrancy;
    (void)a;

    if (function_hook_state_EndPipingSession2 == HOOK_ENABLED) {
        if (HV(gPipe_buffer_start) != NULL && !HV(gAction_replay_mode) && HV(gProgram_state).racing) {
            // Each session ends with a tU16, containing the session size
            *(tU16*)&HV(gLocal_buffer)[HV(gLocal_buffer_size)] = HV(gLocal_buffer_size);
            a = HV(gLocal_buffer_size);
            HV(gLocal_buffer_size) += sizeof(tU16);
            if (((tPipe_session*)HV(gLocal_buffer))->number_of_chunks != 0 && (HV(gLocal_buffer_size) < LOCAL_BUFFER_SIZE || a == LOCAL_BUFFER_SIZE - 2)) {
                if (HV(gPipe_buffer_phys_end) < HV(gPipe_record_ptr) + HV(gLocal_buffer_size)) {
                    // Put session at begin of pipe, as no place at end
                    HV(gPipe_buffer_working_end) = HV(gPipe_record_ptr);
                    HV(gPipe_buffer_oldest) = HV(gPipe_buffer_start);
                    HV(gPipe_record_ptr) = HV(gPipe_buffer_start);
                }
                while (HV(gPipe_record_ptr) <= HV(gPipe_buffer_oldest) && HV(gPipe_buffer_oldest) < HV(gPipe_record_ptr) + HV(gLocal_buffer_size)) {
                    // Remove older sessions
                    HV(gPipe_buffer_oldest) += LengthOfSession((tPipe_session*)HV(gPipe_buffer_oldest));
                    if (HV(gPipe_buffer_working_end) <= HV(gPipe_buffer_oldest)) {
                        HV(gPipe_buffer_working_end) = HV(gPipe_buffer_phys_end);
                        HV(gPipe_buffer_oldest) = HV(gPipe_buffer_start);
                    }
                }
                if (HV(gPipe_buffer_oldest) == NULL) {
                    HV(gPipe_buffer_oldest) = HV(gPipe_record_ptr);
                }
                memcpy(HV(gPipe_record_ptr), HV(gLocal_buffer), HV(gLocal_buffer_size));
                HV(gPipe_record_ptr) += HV(gLocal_buffer_size);
                if (HV(gPipe_buffer_working_end) < HV(gPipe_record_ptr)) {
                    HV(gPipe_buffer_working_end) = HV(gPipe_record_ptr);
                }
            }
            if (pMunge_reentrancy) {
                if (HV(gReentrancy_count) != 0) {
                    HV(gReentrancy_count)--;
                    if (HV(gReentrancy_count) != 0) {
                        StartPipingSession2(HV(gReentrancy_array)[HV(gReentrancy_count) - 1], 0);
                    }
                }
            }
        }
    } else {
        original_EndPipingSession2(pMunge_reentrancy);
    }
}

function_hook_state_t function_hook_state_EndPipingSession = HOOK_ENABLED;
static void(__cdecl*original_EndPipingSession)() = (void(__cdecl*)())0x0042884c;
CARM95_HOOK_FUNCTION(original_EndPipingSession, EndPipingSession)
void __cdecl EndPipingSession() {
    LOG_TRACE("()");


    if (function_hook_state_EndPipingSession == HOOK_ENABLED) {
        EndPipingSession2(1);
    } else {
        original_EndPipingSession();
    }
}

function_hook_state_t function_hook_state_AddDataToSession = HOOK_ENABLED;
static void(__cdecl*original_AddDataToSession)(int, void *, tU32) = (void(__cdecl*)(int, void *, tU32))0x00428861;
CARM95_HOOK_FUNCTION(original_AddDataToSession, AddDataToSession)
void __cdecl AddDataToSession(int pSubject_index, void *pData, tU32 pData_length) {
    tU32 temp_buffer_size;
    int variable_for_breaking_on;
    LOG_TRACE("(%d, %p, %u)", pSubject_index, pData, pData_length);

    (void)pSubject_index;
    (void)pData;
    (void)pData_length;
    (void)temp_buffer_size;
    (void)variable_for_breaking_on;

    if (function_hook_state_AddDataToSession == HOOK_ENABLED) {
        if (HV(gPipe_buffer_start) != NULL && !HV(gAction_replay_mode) && HV(gProgram_state).racing) {
            temp_buffer_size = HV(gLocal_buffer_size) + offsetof(tPipe_chunk, chunk_data) + pData_length;
            if (temp_buffer_size >= LOCAL_BUFFER_SIZE) {
                return;
            }
            ((tPipe_session*)HV(gLocal_buffer))->number_of_chunks++;
            HV(gMr_chunky)->subject_index = pSubject_index;
            memcpy(&HV(gMr_chunky)->chunk_data, pData, pData_length);
            HV(gMr_chunky) = (tPipe_chunk*)(((tU8*)&HV(gMr_chunky)->chunk_data) + pData_length);
            HV(gLocal_buffer_size) = temp_buffer_size;
        }
    } else {
        original_AddDataToSession(pSubject_index, pData, pData_length);
    }
}

function_hook_state_t function_hook_state_AddModelGeometryToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddModelGeometryToPipingSession)(tU16, int, int, tChanged_vertex *) = (void(__cdecl*)(tU16, int, int, tChanged_vertex *))0x00428904;
CARM95_HOOK_FUNCTION(original_AddModelGeometryToPipingSession, AddModelGeometryToPipingSession)
void __cdecl AddModelGeometryToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    if (function_hook_state_AddModelGeometryToPipingSession == HOOK_ENABLED) {
        if (HV(gModel_geometry_space) != NULL) {
            if (pVertex_count > 600) {
                pVertex_count = 600;
            }
            data_size = offsetof(tPipe_model_geometry_data, vertex_changes) + pVertex_count * sizeof(tChanged_vertex);
            HV(gModel_geometry_space)->vertex_count = pVertex_count;
            HV(gModel_geometry_space)->model_index = pModel_index;
            memcpy(HV(gModel_geometry_space)->vertex_changes, pCoordinates, pVertex_count * sizeof(tChanged_vertex));
            AddDataToSession(pCar_ID, HV(gModel_geometry_space), data_size);
        }
    } else {
        original_AddModelGeometryToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
    }
}

function_hook_state_t function_hook_state_AddSmudgeToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSmudgeToPipingSession)(tU16, int, int, tSmudged_vertex *) = (void(__cdecl*)(tU16, int, int, tSmudged_vertex *))0x0042898f;
CARM95_HOOK_FUNCTION(original_AddSmudgeToPipingSession, AddSmudgeToPipingSession)
void __cdecl AddSmudgeToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tSmudged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    if (function_hook_state_AddSmudgeToPipingSession == HOOK_ENABLED) {
        if (HV(gSmudge_space) != NULL) {
            if (pVertex_count > 600) {
                pVertex_count = 600;
            }
            HV(gSmudge_space)->vertex_count = pVertex_count;
            HV(gSmudge_space)->model_index = pModel_index;
            memcpy(HV(gSmudge_space)->vertex_changes, pCoordinates, pVertex_count * sizeof(tSmudged_vertex));
            data_size = offsetof(tPipe_smudge_data, vertex_changes) + pVertex_count * sizeof(tSmudged_vertex);
            AddDataToSession(pCar_ID, HV(gSmudge_space), data_size);
        }
    } else {
        original_AddSmudgeToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
    }
}

function_hook_state_t function_hook_state_AddPedestrianToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddPedestrianToPipingSession)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *) = (void(__cdecl*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *))0x00428a1a;
CARM95_HOOK_FUNCTION(original_AddPedestrianToPipingSession, AddPedestrianToPipingSession)
void __cdecl AddPedestrianToPipingSession(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
    tPipe_pedestrian_data data;
    tU32 data_size;
    LOG_TRACE("(%d, %p, %u, %u, %d, %d, %u, %f, %f, %p)", pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);

    (void)pPedestrian_index;
    (void)pTrans;
    (void)pAction_index;
    (void)pFrame_index;
    (void)pHit_points;
    (void)pDone_initial;
    (void)pParent_ID;
    (void)pSpin_period;
    (void)pJump_magnitude;
    (void)pOffset;
    (void)data;
    (void)data_size;

    if (function_hook_state_AddPedestrianToPipingSession == HOOK_ENABLED) {
        if (pFrame_index == 0xff) {
            pFrame_index = 0;
        }
        data.action_and_frame_index = (pDone_initial ? 1 : 0) << 7 | pAction_index << 4 | pFrame_index;
        data.hit_points = pHit_points;
        data.new_translation.v[0] = pTrans->m[3][0];
        data.new_translation.v[1] = pTrans->m[3][1];
        data.new_translation.v[2] = pTrans->m[3][2];
        data.parent = pParent_ID;
        if (pHit_points <= 0) {
            data.spin_period = pSpin_period;
            data.parent_actor = GetPedestrianActor(pPedestrian_index)->parent;
            BrVector3Copy(&data.offset, pOffset);
            data.jump_magnitude = pJump_magnitude;
            data_size = sizeof(tPipe_pedestrian_data);
        } else {
            data_size = offsetof(tPipe_pedestrian_data, spin_period);
        }
        AddDataToSession(pPedestrian_index, &data, data_size);
    } else {
        original_AddPedestrianToPipingSession(pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);
    }
}

function_hook_state_t function_hook_state_AddSparkToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSparkToPipingSession)(int, br_vector3 *, br_vector3 *) = (void(__cdecl*)(int, br_vector3 *, br_vector3 *))0x00428af9;
CARM95_HOOK_FUNCTION(original_AddSparkToPipingSession, AddSparkToPipingSession)
void __cdecl AddSparkToPipingSession(int pSpark_index, br_vector3 *pPos, br_vector3 *pV) {
    tPipe_spark_data data;
    LOG_TRACE("(%d, %p, %p)", pSpark_index, pPos, pV);

    (void)pSpark_index;
    (void)pPos;
    (void)pV;
    (void)data;

    if (function_hook_state_AddSparkToPipingSession == HOOK_ENABLED) {
        BrVector3Copy(&data.pos, pPos);
        BrVector3Copy(&data.v, pV);
        AddDataToSession(pSpark_index, &data, sizeof(tPipe_spark_data));
    } else {
        original_AddSparkToPipingSession(pSpark_index, pPos, pV);
    }
}

function_hook_state_t function_hook_state_AddShrapnelToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddShrapnelToPipingSession)(int, br_vector3 *, tU16, br_material *) = (void(__cdecl*)(int, br_vector3 *, tU16, br_material *))0x00428b4d;
CARM95_HOOK_FUNCTION(original_AddShrapnelToPipingSession, AddShrapnelToPipingSession)
void __cdecl AddShrapnelToPipingSession(int pShrapnel_index, br_vector3 *pPos, tU16 pAge, br_material *pMaterial) {
    tPipe_shrapnel_data data;
    tU32 data_size;
    LOG_TRACE("(%d, %p, %u, %p)", pShrapnel_index, pPos, pAge, pMaterial);

    (void)pShrapnel_index;
    (void)pPos;
    (void)pAge;
    (void)pMaterial;
    (void)data;
    (void)data_size;

    if (function_hook_state_AddShrapnelToPipingSession == HOOK_ENABLED) {
        BrVector3Copy(&data.pos, pPos);
        if ((pShrapnel_index & 0x8000) != 0) {
            data.age = pAge;
            data.material = pMaterial;
            data_size = sizeof(tPipe_shrapnel_data);
        } else {
            data_size = offsetof(tPipe_shrapnel_data, age);
        }
        AddDataToSession(pShrapnel_index, &data, data_size);
    } else {
        original_AddShrapnelToPipingSession(pShrapnel_index, pPos, pAge, pMaterial);
    }
}

function_hook_state_t function_hook_state_AddScreenWobbleToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddScreenWobbleToPipingSession)(int, int) = (void(__cdecl*)(int, int))0x00428bb4;
CARM95_HOOK_FUNCTION(original_AddScreenWobbleToPipingSession, AddScreenWobbleToPipingSession)
void __cdecl AddScreenWobbleToPipingSession(int pWobble_x, int pWobble_y) {
    tPipe_screen_shake_data data;
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;
    (void)data;

    if (function_hook_state_AddScreenWobbleToPipingSession == HOOK_ENABLED) {
        data.wobble_x = pWobble_x;
        data.wobble_y = pWobble_y;
        AddDataToSession(0, &data, sizeof(tPipe_screen_shake_data));
    } else {
        original_AddScreenWobbleToPipingSession(pWobble_x, pWobble_y);
    }
}

function_hook_state_t function_hook_state_AddGrooveStopToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddGrooveStopToPipingSession)(int, br_matrix34 *, int, int, float, float) = (void(__cdecl*)(int, br_matrix34 *, int, int, float, float))0x00428bde;
CARM95_HOOK_FUNCTION(original_AddGrooveStopToPipingSession, AddGrooveStopToPipingSession)
void __cdecl AddGrooveStopToPipingSession(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    tPipe_groove_stop_data data;
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;
    (void)data;

    if (function_hook_state_AddGrooveStopToPipingSession == HOOK_ENABLED) {
        BrMatrix34Copy(&data.matrix, pMatrix);
        data.path_interrupt = pPath_interrupt;
        data.object_interrupt = pObject_interrupt;
        data.path_resumption = pPath_resumption;
        data.object_resumption = pObject_resumption;
        AddDataToSession(pGroove_index, &data, sizeof(tPipe_groove_stop_data));
    } else {
        original_AddGrooveStopToPipingSession(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
    }
}

function_hook_state_t function_hook_state_AddNonCarToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddNonCarToPipingSession)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x00428c26;
CARM95_HOOK_FUNCTION(original_AddNonCarToPipingSession, AddNonCarToPipingSession)
void __cdecl AddNonCarToPipingSession(int pIndex, br_actor *pActor) {
    tPipe_non_car_data data;
    LOG_TRACE("(%d, %p)", pIndex, pActor);

    (void)pIndex;
    (void)pActor;
    (void)data;

    if (function_hook_state_AddNonCarToPipingSession == HOOK_ENABLED) {
        BrMatrix34Copy(&data.mat, &pActor->t.t.mat);
        data.actor = pActor;
        AddDataToSession(pIndex, &data, sizeof(tPipe_non_car_data));
    } else {
        original_AddNonCarToPipingSession(pIndex, pActor);
    }
}

function_hook_state_t function_hook_state_AddSmokeToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSmokeToPipingSession)(int, tU8, br_vector3 *, br_scalar, br_scalar) = (void(__cdecl*)(int, tU8, br_vector3 *, br_scalar, br_scalar))0x00428c5f;
CARM95_HOOK_FUNCTION(original_AddSmokeToPipingSession, AddSmokeToPipingSession)
void __cdecl AddSmokeToPipingSession(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength) {
    tPipe_smoke_data data;
    LOG_TRACE("(%d, %u, %p, %f, %f)", pIndex, pType, pPos, pRadius, pStrength);

    (void)pIndex;
    (void)pType;
    (void)pPos;
    (void)pRadius;
    (void)pStrength;
    (void)data;

    if (function_hook_state_AddSmokeToPipingSession == HOOK_ENABLED) {
        SaveReducedPos(&data.pos, pPos);
        data.type = pType;
        data.radius = pRadius * 1024.f;
        data.strength = pStrength * 255.f;
        AddDataToSession(pIndex, &data, sizeof(tPipe_smoke_data));
    } else {
        original_AddSmokeToPipingSession(pIndex, pType, pPos, pRadius, pStrength);
    }
}

function_hook_state_t function_hook_state_AddSmokeColumnToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSmokeColumnToPipingSession)(int, tCar_spec *, int, int) = (void(__cdecl*)(int, tCar_spec *, int, int))0x00428cb8;
CARM95_HOOK_FUNCTION(original_AddSmokeColumnToPipingSession, AddSmokeColumnToPipingSession)
void __cdecl AddSmokeColumnToPipingSession(int pIndex, tCar_spec *pCar, int pVertex, int pColour) {
    tPipe_smoke_column_data data;
    LOG_TRACE("(%d, %p, %d, %d)", pIndex, pCar, pVertex, pColour);

    (void)pIndex;
    (void)pCar;
    (void)pVertex;
    (void)pColour;
    (void)data;

    if (function_hook_state_AddSmokeColumnToPipingSession == HOOK_ENABLED) {
        data.car_ID = pCar->car_ID;
        data.vertex = pVertex;
        AddDataToSession(pColour << 14 | pIndex, &data, sizeof(tPipe_smoke_column_data));
    } else {
        original_AddSmokeColumnToPipingSession(pIndex, pCar, pVertex, pColour);
    }
}

function_hook_state_t function_hook_state_AddFlameToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddFlameToPipingSession)(int, int, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(int, int, br_scalar, br_scalar, br_scalar, br_scalar))0x00428cf7;
CARM95_HOOK_FUNCTION(original_AddFlameToPipingSession, AddFlameToPipingSession)
void __cdecl AddFlameToPipingSession(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z) {
    tPipe_flame_data data;
    LOG_TRACE("(%d, %d, %f, %f, %f, %f)", pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);

    (void)pIndex;
    (void)pFrame_count;
    (void)pScale_x;
    (void)pScale_y;
    (void)pOffset_x;
    (void)pOffset_z;
    (void)data;

    if (function_hook_state_AddFlameToPipingSession == HOOK_ENABLED) {
        data.frame_count = pFrame_count;
        data.scale_x = pScale_x;
        data.scale_y = pScale_y;
        data.offset_x = pOffset_x;
        data.offset_z = pOffset_z;
        AddDataToSession(pIndex, &data, sizeof(tPipe_flame_data));
    } else {
        original_AddFlameToPipingSession(pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);
    }
}

function_hook_state_t function_hook_state_AddSplashToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSplashToPipingSession)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x00428d36;
CARM95_HOOK_FUNCTION(original_AddSplashToPipingSession, AddSplashToPipingSession)
void __cdecl AddSplashToPipingSession(tCollision_info *pCar) {
    tPipe_splash_data data;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)data;

    if (function_hook_state_AddSplashToPipingSession == HOOK_ENABLED) {
        if (pCar->driver >= eDriver_oppo) {
            data.d = pCar->water_d;
            BrVector3Copy(&data.normal, &pCar->water_normal);
            AddDataToSession(pCar->car_ID, &data, sizeof(tPipe_splash_data));
        }
    } else {
        original_AddSplashToPipingSession(pCar);
    }
}

function_hook_state_t function_hook_state_AddOilSpillToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddOilSpillToPipingSession)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *) = (void(__cdecl*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *))0x00428da1;
CARM95_HOOK_FUNCTION(original_AddOilSpillToPipingSession, AddOilSpillToPipingSession)
void __cdecl AddOilSpillToPipingSession(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
    tPipe_oil_spill_data data;
    LOG_TRACE("(%d, %p, %f, %f, %u, %u, %p, %p, %p)", pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);

    (void)pIndex;
    (void)pMat;
    (void)pFull_size;
    (void)pGrow_rate;
    (void)pSpill_time;
    (void)pStop_time;
    (void)pCar;
    (void)pOriginal_pos;
    (void)pPixelmap;
    (void)data;

    if (function_hook_state_AddOilSpillToPipingSession == HOOK_ENABLED) {
        BrMatrix34Copy(&data.mat, pMat);
        data.full_size = pFull_size;
        data.grow_rate = pGrow_rate;
        data.spill_time = pSpill_time;
        data.previous_stop_time = pStop_time;
        data.car = pCar;
        BrVector3Copy(&data.original_pos, pOriginal_pos);
        data.pixelmap = pPixelmap;
        AddDataToSession(pIndex, &data, sizeof(tPipe_oil_spill_data));
    } else {
        original_AddOilSpillToPipingSession(pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);
    }
}

function_hook_state_t function_hook_state_AddFrameFinishToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddFrameFinishToPipingSession)(tU32) = (void(__cdecl*)(tU32))0x00428e0f;
CARM95_HOOK_FUNCTION(original_AddFrameFinishToPipingSession, AddFrameFinishToPipingSession)
void __cdecl AddFrameFinishToPipingSession(tU32 pThe_time) {
    tPipe_frame_boundary_data data;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)data;

    if (function_hook_state_AddFrameFinishToPipingSession == HOOK_ENABLED) {
        data.time = pThe_time;
        AddDataToSession(0, &data, sizeof(tPipe_frame_boundary_data));
    } else {
        original_AddFrameFinishToPipingSession(pThe_time);
    }
}

function_hook_state_t function_hook_state_AddCarToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddCarToPipingSession)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int) = (void(__cdecl*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int))0x00428e33;
CARM95_HOOK_FUNCTION(original_AddCarToPipingSession, AddCarToPipingSession)
void __cdecl AddCarToPipingSession(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
    tPipe_car_data data;
    LOG_TRACE("(%d, %p, %p, %f, %f, %f, %f, %f, %f, %f, %d, %d)", pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);

    (void)pCar_ID;
    (void)pCar_mat;
    (void)pCar_velocity;
    (void)pSpeedo_speed;
    (void)pLf_sus_position;
    (void)pRf_sus_position;
    (void)pLr_sus_position;
    (void)pRr_sus_position;
    (void)pSteering_angle;
    (void)pRevs;
    (void)pGear;
    (void)pFrame_coll_flag;
    (void)data;

    if (function_hook_state_AddCarToPipingSession == HOOK_ENABLED) {
        BrMatrix34Copy(&data.transformation, pCar_mat);
        BrVector3Copy(&data.velocity, pCar_velocity);
        data.speedo_speed = pSpeedo_speed * 32767.f / 0.07f;
        data.lf_sus_position = pLf_sus_position * 127.f / .15f;
        data.rf_sus_position = pRf_sus_position * 127.f / .15f;
        data.lr_sus_position = pLr_sus_position * 127.f / .15f;
        data.rr_sus_position = pRr_sus_position * 127.f / .15f;
        data.steering_angle = pSteering_angle * 32767.f / 60.f;
        data.revs_and_gear = (pGear + 1) << 12 | (pFrame_coll_flag ? 0 : 1) << 11 | ((((int)pRevs) / 10) & 0x7ff);
        AddDataToSession(pCar_ID, &data, sizeof(tPipe_car_data));
    } else {
        original_AddCarToPipingSession(pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);
    }
}

function_hook_state_t function_hook_state_AddSoundToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSoundToPipingSession)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *) = (void(__cdecl*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *))0x00428f38;
CARM95_HOOK_FUNCTION(original_AddSoundToPipingSession, AddSoundToPipingSession)
void __cdecl AddSoundToPipingSession(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
    tPipe_sound_data data;
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %p)", pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);

    (void)pOutlet;
    (void)pSound_index;
    (void)pL_volume;
    (void)pR_volume;
    (void)pPitch;
    (void)pPos;
    (void)data;

    if (function_hook_state_AddSoundToPipingSession == HOOK_ENABLED) {
        data.pitch = pPitch;
        if (pPos == NULL) {
            BrVector3Set(&data.position, 0.f, 0.f, 0.f);
        } else {
            BrVector3Copy(&data.position, pPos);
        }
        data.volume = (pR_volume << 8) | (pL_volume << 0);
        data.outlet_index = GetIndexFromOutlet(pOutlet);
        AddDataToSession(pSound_index, &data, sizeof(tPipe_sound_data));
    } else {
        original_AddSoundToPipingSession(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
    }
}

function_hook_state_t function_hook_state_AddDamageToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddDamageToPipingSession)(int, tS8 *) = (void(__cdecl*)(int, tS8 *))0x00428fb5;
CARM95_HOOK_FUNCTION(original_AddDamageToPipingSession, AddDamageToPipingSession)
void __cdecl AddDamageToPipingSession(int pCar_ID, tS8 *pDifferences) {
    tPipe_damage_data data;
    int i;
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;
    (void)data;
    (void)i;

    if (function_hook_state_AddDamageToPipingSession == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(data.damage_delta); i++) {
            data.damage_delta[i] = pDifferences[i];
        }
        AddDataToSession(pCar_ID, &data, sizeof(tPipe_damage_data));
    } else {
        original_AddDamageToPipingSession(pCar_ID, pDifferences);
    }
}

function_hook_state_t function_hook_state_AddSpecialToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSpecialToPipingSession)(tSpecial_type) = (void(__cdecl*)(tSpecial_type))0x00429003;
CARM95_HOOK_FUNCTION(original_AddSpecialToPipingSession, AddSpecialToPipingSession)
void __cdecl AddSpecialToPipingSession(tSpecial_type pType) {
    tPipe_special_data data;
    LOG_TRACE("(%d)", pType);

    (void)pType;
    (void)data;

    if (function_hook_state_AddSpecialToPipingSession == HOOK_ENABLED) {
        AddDataToSession(pType, &data, sizeof(tPipe_special_data));
    } else {
        original_AddSpecialToPipingSession(pType);
    }
}

function_hook_state_t function_hook_state_AddPedGibToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddPedGibToPipingSession)(int, br_matrix34 *, int, int, int) = (void(__cdecl*)(int, br_matrix34 *, int, int, int))0x00429023;
CARM95_HOOK_FUNCTION(original_AddPedGibToPipingSession, AddPedGibToPipingSession)
void __cdecl AddPedGibToPipingSession(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
    tPipe_ped_gib_data data;
    LOG_TRACE("(%d, %p, %d, %d, %d)", pIndex, pTrans, pSize, pGib_index, pPed_index);

    (void)pIndex;
    (void)pTrans;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;
    (void)data;

    if (function_hook_state_AddPedGibToPipingSession == HOOK_ENABLED) {
        data.ped_parent_index = pPed_index;
        data.size = pSize;
        data.gib_index = pGib_index;
        BrMatrix34Copy(&data.transform, pTrans);
        AddDataToSession(pIndex, &data, sizeof(tPipe_ped_gib_data));
    } else {
        original_AddPedGibToPipingSession(pIndex, pTrans, pSize, pGib_index, pPed_index);
    }
}

function_hook_state_t function_hook_state_AddCarIncidentToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddCarIncidentToPipingSession)(float, tCar_spec *, br_vector3 *) = (void(__cdecl*)(float, tCar_spec *, br_vector3 *))0x00429063;
CARM95_HOOK_FUNCTION(original_AddCarIncidentToPipingSession, AddCarIncidentToPipingSession)
void __cdecl AddCarIncidentToPipingSession(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;
    (void)data;

    if (function_hook_state_AddCarIncidentToPipingSession == HOOK_ENABLED) {
        data.severity = pSeverity;
        data.info.car_info.car_ID = pCar->car_ID;
        BrVector3Copy(&data.info.car_info.impact_point, pImpact_point);
        AddDataToSession(1, &data, sizeof(tPipe_incident_data));
    } else {
        original_AddCarIncidentToPipingSession(pSeverity, pCar, pImpact_point);
    }
}

function_hook_state_t function_hook_state_AddPedIncidentToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddPedIncidentToPipingSession)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x004290ab;
CARM95_HOOK_FUNCTION(original_AddPedIncidentToPipingSession, AddPedIncidentToPipingSession)
void __cdecl AddPedIncidentToPipingSession(int pPed_index, br_actor *pActor) {
    tPipe_incident_data data;
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;
    (void)data;

    if (function_hook_state_AddPedIncidentToPipingSession == HOOK_ENABLED) {
        data.severity = 0.f;
        data.info.ped_info.ped_index = pPed_index;
        data.info.ped_info.actor = pActor;
        AddDataToSession(0, &data, sizeof(tPipe_incident_data));
    } else {
        original_AddPedIncidentToPipingSession(pPed_index, pActor);
    }
}

function_hook_state_t function_hook_state_AddWallIncidentToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddWallIncidentToPipingSession)(float, br_vector3 *) = (void(__cdecl*)(float, br_vector3 *))0x004290dd;
CARM95_HOOK_FUNCTION(original_AddWallIncidentToPipingSession, AddWallIncidentToPipingSession)
void __cdecl AddWallIncidentToPipingSession(float pSeverity, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;
    (void)data;

    if (function_hook_state_AddWallIncidentToPipingSession == HOOK_ENABLED) {
        data.severity = pSeverity;
        BrVector3Copy(&data.info.wall_info.pos, pImpact_point);
        AddDataToSession(2, &data, sizeof(tPipe_incident_data));
    } else {
        original_AddWallIncidentToPipingSession(pSeverity, pImpact_point);
    }
}

function_hook_state_t function_hook_state_AddProxRayToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddProxRayToPipingSession)(int, tCar_spec *, tU16, tU32) = (void(__cdecl*)(int, tCar_spec *, tU16, tU32))0x00429117;
CARM95_HOOK_FUNCTION(original_AddProxRayToPipingSession, AddProxRayToPipingSession)
void __cdecl AddProxRayToPipingSession(int pRay_index, tCar_spec *pCar, tU16 pPed_index, tU32 pTime) {
    tPipe_prox_ray_data data;
    LOG_TRACE("(%d, %p, %u, %u)", pRay_index, pCar, pPed_index, pTime);

    (void)pRay_index;
    (void)pCar;
    (void)pPed_index;
    (void)pTime;
    (void)data;

    if (function_hook_state_AddProxRayToPipingSession == HOOK_ENABLED) {
        data.ped_index = pPed_index;
        data.car_ID = pCar->car_ID;
        data.time = pTime;
        AddDataToSession(pRay_index, &data, sizeof(tPipe_prox_ray_data));
    } else {
        original_AddProxRayToPipingSession(pRay_index, pCar, pPed_index, pTime);
    }
}

function_hook_state_t function_hook_state_AddSkidAdjustmentToPipingSession = HOOK_ENABLED;
static void(__cdecl*original_AddSkidAdjustmentToPipingSession)(int, br_matrix34 *, int) = (void(__cdecl*)(int, br_matrix34 *, int))0x00429153;
CARM95_HOOK_FUNCTION(original_AddSkidAdjustmentToPipingSession, AddSkidAdjustmentToPipingSession)
void __cdecl AddSkidAdjustmentToPipingSession(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    tPipe_skid_adjustment adjustment;
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;
    (void)adjustment;

    if (function_hook_state_AddSkidAdjustmentToPipingSession == HOOK_ENABLED) {
        BrMatrix34Copy(&adjustment.matrix, pMatrix);
        adjustment.material_index = pMaterial_index;
        AddDataToSession(pSkid_num, &adjustment, sizeof(tPipe_skid_adjustment));
    } else {
        original_AddSkidAdjustmentToPipingSession(pSkid_num, pMatrix, pMaterial_index);
    }
}

function_hook_state_t function_hook_state_PipeSingleModelGeometry = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleModelGeometry)(tU16, int, int, tChanged_vertex *) = (void(__cdecl*)(tU16, int, int, tChanged_vertex *))0x00429186;
CARM95_HOOK_FUNCTION(original_PipeSingleModelGeometry, PipeSingleModelGeometry)
void __cdecl PipeSingleModelGeometry(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;

    if (function_hook_state_PipeSingleModelGeometry == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_model_geometry);
        AddModelGeometryToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
        EndPipingSession();
    } else {
        original_PipeSingleModelGeometry(pCar_ID, pModel_index, pVertex_count, pCoordinates);
    }
}

function_hook_state_t function_hook_state_PipeSinglePedestrian = HOOK_ENABLED;
static void(__cdecl*original_PipeSinglePedestrian)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *) = (void(__cdecl*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *))0x004291b8;
CARM95_HOOK_FUNCTION(original_PipeSinglePedestrian, PipeSinglePedestrian)
void __cdecl PipeSinglePedestrian(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
    LOG_TRACE("(%d, %p, %u, %u, %d, %d, %u, %f, %f, %p)", pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);

    (void)pPedestrian_index;
    (void)pTrans;
    (void)pAction_index;
    (void)pFrame_index;
    (void)pHit_points;
    (void)pDone_initial;
    (void)pParent_ID;
    (void)pSpin_period;
    (void)pJump_magnitude;
    (void)pOffset;

    if (function_hook_state_PipeSinglePedestrian == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_pedestrian);
        AddPedestrianToPipingSession(pPedestrian_index, pTrans, pAction_index,
                                     pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period,
                                     pJump_magnitude, pOffset);
        EndPipingSession();
    } else {
        original_PipeSinglePedestrian(pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);
    }
}

function_hook_state_t function_hook_state_PipeSingleCar = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleCar)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int) = (void(__cdecl*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int))0x00429202;
CARM95_HOOK_FUNCTION(original_PipeSingleCar, PipeSingleCar)
void __cdecl PipeSingleCar(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
    LOG_TRACE("(%d, %p, %p, %f, %f, %f, %f, %f, %f, %f, %d, %d)", pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);

    (void)pCar_ID;
    (void)pCar_mat;
    (void)pCar_velocity;
    (void)pSpeedo_speed;
    (void)pLf_sus_position;
    (void)pRf_sus_position;
    (void)pLr_sus_position;
    (void)pRr_sus_position;
    (void)pSteering_angle;
    (void)pRevs;
    (void)pGear;
    (void)pFrame_coll_flag;

    if (function_hook_state_PipeSingleCar == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_car);
        AddCarToPipingSession(pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed,
                              pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position,
                              pSteering_angle, pRevs, pGear, pFrame_coll_flag);
        EndPipingSession();
    } else {
        original_PipeSingleCar(pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);
    }
}

function_hook_state_t function_hook_state_PipeSingleSound = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleSound)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *) = (void(__cdecl*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *))0x00429254;
CARM95_HOOK_FUNCTION(original_PipeSingleSound, PipeSingleSound)
void __cdecl PipeSingleSound(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %p)", pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);

    (void)pOutlet;
    (void)pSound_index;
    (void)pL_volume;
    (void)pR_volume;
    (void)pPitch;
    (void)pPos;

    if (function_hook_state_PipeSingleSound == HOOK_ENABLED) {
        if (!HV(gAction_replay_mode) && HV(gProgram_state).racing) {
            StartPipingSession(ePipe_chunk_sound);
            AddSoundToPipingSession(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
            EndPipingSession();
        }
    } else {
        original_PipeSingleSound(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
    }
}

function_hook_state_t function_hook_state_PipeSingleOilSpill = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleOilSpill)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *) = (void(__cdecl*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *))0x004292a8;
CARM95_HOOK_FUNCTION(original_PipeSingleOilSpill, PipeSingleOilSpill)
void __cdecl PipeSingleOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
    LOG_TRACE("(%d, %p, %f, %f, %u, %u, %p, %p, %p)", pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);

    (void)pIndex;
    (void)pMat;
    (void)pFull_size;
    (void)pGrow_rate;
    (void)pSpill_time;
    (void)pStop_time;
    (void)pCar;
    (void)pOriginal_pos;
    (void)pPixelmap;

    if (function_hook_state_PipeSingleOilSpill == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_oil_spill);
        AddOilSpillToPipingSession(pIndex, pMat, pFull_size, pGrow_rate,
                                   pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);
        EndPipingSession();
    } else {
        original_PipeSingleOilSpill(pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);
    }
}

function_hook_state_t function_hook_state_PipeSingleDamage = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleDamage)(int, tS8 *) = (void(__cdecl*)(int, tS8 *))0x004292ee;
CARM95_HOOK_FUNCTION(original_PipeSingleDamage, PipeSingleDamage)
void __cdecl PipeSingleDamage(int pCar_ID, tS8 *pDifferences) {
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;

    if (function_hook_state_PipeSingleDamage == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_damage);
        AddDamageToPipingSession(pCar_ID, pDifferences);
        EndPipingSession();
    } else {
        original_PipeSingleDamage(pCar_ID, pDifferences);
    }
}

function_hook_state_t function_hook_state_PipeSingleSpecial = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleSpecial)(tSpecial_type) = (void(__cdecl*)(tSpecial_type))0x00429318;
CARM95_HOOK_FUNCTION(original_PipeSingleSpecial, PipeSingleSpecial)
void __cdecl PipeSingleSpecial(tSpecial_type pType) {
    LOG_TRACE("(%d)", pType);

    (void)pType;

    if (function_hook_state_PipeSingleSpecial == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_special);
        AddSpecialToPipingSession(pType);
        EndPipingSession();
    } else {
        original_PipeSingleSpecial(pType);
    }
}

function_hook_state_t function_hook_state_PipeSinglePedGib = HOOK_ENABLED;
static void(__cdecl*original_PipeSinglePedGib)(int, br_matrix34 *, int, int, int) = (void(__cdecl*)(int, br_matrix34 *, int, int, int))0x0042933e;
CARM95_HOOK_FUNCTION(original_PipeSinglePedGib, PipeSinglePedGib)
void __cdecl PipeSinglePedGib(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
    LOG_TRACE("(%d, %p, %d, %d, %d)", pIndex, pTrans, pSize, pGib_index, pPed_index);

    (void)pIndex;
    (void)pTrans;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;

    if (function_hook_state_PipeSinglePedGib == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_ped_gib);
        AddPedGibToPipingSession(pIndex, pTrans, pSize, pGib_index, pPed_index);
        EndPipingSession();
    } else {
        original_PipeSinglePedGib(pIndex, pTrans, pSize, pGib_index, pPed_index);
    }
}

function_hook_state_t function_hook_state_PipeSingleCarIncident = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleCarIncident)(float, tCar_spec *, br_vector3 *) = (void(__cdecl*)(float, tCar_spec *, br_vector3 *))0x00429374;
CARM95_HOOK_FUNCTION(original_PipeSingleCarIncident, PipeSingleCarIncident)
void __cdecl PipeSingleCarIncident(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;

    if (function_hook_state_PipeSingleCarIncident == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_incident);
        AddCarIncidentToPipingSession(pSeverity, pCar, pImpact_point);
        EndPipingSession();
    } else {
        original_PipeSingleCarIncident(pSeverity, pCar, pImpact_point);
    }
}

function_hook_state_t function_hook_state_PipeSinglePedIncident = HOOK_ENABLED;
static void(__cdecl*original_PipeSinglePedIncident)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x004293a2;
CARM95_HOOK_FUNCTION(original_PipeSinglePedIncident, PipeSinglePedIncident)
void __cdecl PipeSinglePedIncident(int pPed_index, br_actor *pActor) {
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;

    if (function_hook_state_PipeSinglePedIncident == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_incident);
        AddPedIncidentToPipingSession(pPed_index, pActor);
        EndPipingSession();
        HV(gWall_severity) = 0.f;
    } else {
        original_PipeSinglePedIncident(pPed_index, pActor);
    }
}

function_hook_state_t function_hook_state_PipeSingleWallIncident = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleWallIncident)(float, br_vector3 *) = (void(__cdecl*)(float, br_vector3 *))0x004293d6;
CARM95_HOOK_FUNCTION(original_PipeSingleWallIncident, PipeSingleWallIncident)
void __cdecl PipeSingleWallIncident(float pSeverity, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;

    if (function_hook_state_PipeSingleWallIncident == HOOK_ENABLED) {
        if (pSeverity > HV(gWall_severity)) {
            HV(gWall_severity) = pSeverity;
            BrVector3Copy(&HV(gWall_impact_point), pImpact_point);
        }
    } else {
        original_PipeSingleWallIncident(pSeverity, pImpact_point);
    }
}

function_hook_state_t function_hook_state_PipeSingleScreenShake = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleScreenShake)(int, int) = (void(__cdecl*)(int, int))0x00429415;
CARM95_HOOK_FUNCTION(original_PipeSingleScreenShake, PipeSingleScreenShake)
void __cdecl PipeSingleScreenShake(int pWobble_x, int pWobble_y) {
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;

    if (function_hook_state_PipeSingleScreenShake == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_screen_shake);
        AddScreenWobbleToPipingSession(pWobble_x, pWobble_y);
        EndPipingSession();
    } else {
        original_PipeSingleScreenShake(pWobble_x, pWobble_y);
    }
}

function_hook_state_t function_hook_state_PipeSingleGrooveStop = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleGrooveStop)(int, br_matrix34 *, int, int, float, float) = (void(__cdecl*)(int, br_matrix34 *, int, int, float, float))0x0042943f;
CARM95_HOOK_FUNCTION(original_PipeSingleGrooveStop, PipeSingleGrooveStop)
void __cdecl PipeSingleGrooveStop(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;

    if (function_hook_state_PipeSingleGrooveStop == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_groove_stop);
        AddGrooveStopToPipingSession(pGroove_index, pMatrix, pPath_interrupt,
                                     pObject_interrupt, pPath_resumption, pObject_resumption);
        EndPipingSession();
    } else {
        original_PipeSingleGrooveStop(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
    }
}

function_hook_state_t function_hook_state_PipeFrameFinish = HOOK_ENABLED;
static void(__cdecl*original_PipeFrameFinish)() = (void(__cdecl*)())0x00429479;
CARM95_HOOK_FUNCTION(original_PipeFrameFinish, PipeFrameFinish)
void __cdecl PipeFrameFinish() {
    LOG_TRACE("()");


    if (function_hook_state_PipeFrameFinish == HOOK_ENABLED) {
        if (HV(gWall_severity) != 0.f) {
            StartPipingSession(ePipe_chunk_incident);
            AddWallIncidentToPipingSession(HV(gWall_severity), &HV(gWall_impact_point));
            EndPipingSession();
            HV(gWall_severity) = 0.f;
        }
        StartPipingSession(ePipe_chunk_frame_boundary);
        AddFrameFinishToPipingSession(GetTotalTime());
        EndPipingSession();
    } else {
        original_PipeFrameFinish();
    }
}

function_hook_state_t function_hook_state_PipingFrameReset = HOOK_ENABLED;
static void(__cdecl*original_PipingFrameReset)() = (void(__cdecl*)())0x004294e4;
CARM95_HOOK_FUNCTION(original_PipingFrameReset, PipingFrameReset)
void __cdecl PipingFrameReset() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_PipingFrameReset == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(HV(gReset_procs)); i++) {
            if (HV(gReset_procs)[i] != NULL) {
                HV(gReset_procs)[i]();
            }
        }
    } else {
        original_PipingFrameReset();
    }
}

function_hook_state_t function_hook_state_PipeSingleSkidAdjustment = HOOK_ENABLED;
static void(__cdecl*original_PipeSingleSkidAdjustment)(int, br_matrix34 *, int) = (void(__cdecl*)(int, br_matrix34 *, int))0x0042952b;
CARM95_HOOK_FUNCTION(original_PipeSingleSkidAdjustment, PipeSingleSkidAdjustment)
void __cdecl PipeSingleSkidAdjustment(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;

    if (function_hook_state_PipeSingleSkidAdjustment == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_skid_adjustment);
        AddSkidAdjustmentToPipingSession(pSkid_num, pMatrix, pMaterial_index);
        EndPipingSession();
    } else {
        original_PipeSingleSkidAdjustment(pSkid_num, pMatrix, pMaterial_index);
    }
}

function_hook_state_t function_hook_state_ResetPiping = HOOK_ENABLED;
static void(__cdecl*original_ResetPiping)() = (void(__cdecl*)())0x00429559;
CARM95_HOOK_FUNCTION(original_ResetPiping, ResetPiping)
void __cdecl ResetPiping() {
    LOG_TRACE("()");


    if (function_hook_state_ResetPiping == HOOK_ENABLED) {
        HV(gWall_severity) = 0.f;
        HV(gPipe_buffer_oldest) = NULL;
        HV(gPipe_record_ptr) = HV(gPipe_buffer_start);
        HV(gPipe_buffer_working_end) = HV(gPipe_buffer_phys_end);
        HV(gReentrancy_count) = 0;
    } else {
        original_ResetPiping();
    }
}

function_hook_state_t function_hook_state_InitialisePiping = HOOK_ENABLED;
static void(__cdecl*original_InitialisePiping)() = (void(__cdecl*)())0x00429596;
CARM95_HOOK_FUNCTION(original_InitialisePiping, InitialisePiping)
void __cdecl InitialisePiping() {
    LOG_TRACE("()");


    if (function_hook_state_InitialisePiping == HOOK_ENABLED) {
        if (!HV(gAusterity_mode) && HV(gNet_mode) == eNet_mode_none) {
            PDAllocateActionReplayBuffer((char**)&HV(gPipe_buffer_start), &HV(gPipe_buffer_size));
            HV(gPipe_buffer_phys_end) = HV(gPipe_buffer_start) + HV(gPipe_buffer_size);
            HV(gSmudge_space) = BrMemAllocate(offsetof(tPipe_smudge_data, vertex_changes) + sizeof(tSmudged_vertex) * 2400, kMem_pipe_model_geometry);
            // DAT_00532008 = 0;
            BrVector3SetFloat(&HV(gZero_vector), 0.f, 0.f, 0.f);
            HV(gModel_geometry_space) = (tPipe_model_geometry_data*)HV(gSmudge_space);
            HV(gLocal_buffer) = BrMemAllocate(LOCAL_BUFFER_SIZE, kMem_pipe_model_geometry);
        } else {
            HV(gPipe_buffer_start) = NULL;
            HV(gLocal_buffer) = NULL;
            HV(gModel_geometry_space) = NULL;
            HV(gSmudge_space) = NULL;
        }
        ResetPiping();
    } else {
        original_InitialisePiping();
    }
}

function_hook_state_t function_hook_state_DisposePiping = HOOK_ENABLED;
static void(__cdecl*original_DisposePiping)() = (void(__cdecl*)())0x0042966f;
CARM95_HOOK_FUNCTION(original_DisposePiping, DisposePiping)
void __cdecl DisposePiping() {
    LOG_TRACE("()");


    if (function_hook_state_DisposePiping == HOOK_ENABLED) {
        if (HV(gPipe_buffer_start) != NULL) {
            PDDisposeActionReplayBuffer((char*)HV(gPipe_buffer_start));
        }
        HV(gPipe_buffer_start) = NULL;
        if (HV(gModel_geometry_space) != NULL) {
            BrMemFree(HV(gModel_geometry_space));
            HV(gModel_geometry_space) = NULL;
        }
        if (HV(gLocal_buffer) != NULL) {
            BrMemFree(HV(gLocal_buffer));
            HV(gLocal_buffer) = NULL;
        }
    } else {
        original_DisposePiping();
    }
}

function_hook_state_t function_hook_state_InitLastDamageArrayEtc = HOOK_ENABLED;
static void(__cdecl*original_InitLastDamageArrayEtc)() = (void(__cdecl*)())0x004296e9;
CARM95_HOOK_FUNCTION(original_InitLastDamageArrayEtc, InitLastDamageArrayEtc)
void __cdecl InitLastDamageArrayEtc() {
    int i;
    int j;
    int cat;
    int car_count;
    tCar_spec *car;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)cat;
    (void)car_count;
    (void)car;

    if (function_hook_state_InitLastDamageArrayEtc == HOOK_ENABLED) {
        for (cat = eVehicle_self; cat <= eVehicle_not_really; cat++) {
            if (cat == eVehicle_self) {
                car_count = 1;
            } else {
                car_count = GetCarCount(cat);
            }
            for (i = 0; i < car_count; i++) {
                if (cat == eVehicle_self) {
                    car = &HV(gProgram_state).current_car;
                } else {
                    car = GetCarSpec(cat, i);
                }
                if (cat != eVehicle_not_really) {
                    for (j = 0; j < COUNT_OF(car->frame_start_damage); j++) {
                        car->frame_start_damage[j] = 0;
                    }
                }
                car->car_ID = (cat << 8) | i;
            }
        }
    } else {
        original_InitLastDamageArrayEtc();
    }
}

function_hook_state_t function_hook_state_ResetCars = HOOK_ENABLED;
static void(__cdecl*original_ResetCars)() = (void(__cdecl*)())0x004297d2;
CARM95_HOOK_FUNCTION(original_ResetCars, ResetCars)
void __cdecl ResetCars() {
    tCar_spec *car;
    int cat;
    int i;
    int car_count;
    LOG_TRACE("()");

    (void)car;
    (void)cat;
    (void)i;
    (void)car_count;

    if (function_hook_state_ResetCars == HOOK_ENABLED) {
        for (cat = eVehicle_self; cat < eVehicle_not_really; cat++) {
            if (cat == eVehicle_self) {
                car_count = 1;
            } else {
                car_count = GetCarCount(cat);
            }
            for (i = 0; i < car_count; i++) {
                if (cat == eVehicle_self) {
                    car = &HV(gProgram_state).current_car;
                } else {
                    car = GetCarSpec(cat, i);
                }
                car->active = 0;
            }
        }
    } else {
        original_ResetCars();
    }
}

function_hook_state_t function_hook_state_PipeCarPositions = HOOK_ENABLED;
static void(__cdecl*original_PipeCarPositions)() = (void(__cdecl*)())0x0042987f;
CARM95_HOOK_FUNCTION(original_PipeCarPositions, PipeCarPositions)
void __cdecl PipeCarPositions() {
    tCar_spec *car;
    int cat;
    int i;
    int j;
    int car_count;
    int session_started;
    int difference_found;
    tS8 damage_deltas[12];
    LOG_TRACE("()");

    (void)car;
    (void)cat;
    (void)i;
    (void)j;
    (void)car_count;
    (void)session_started;
    (void)difference_found;
    (void)damage_deltas;

    if (function_hook_state_PipeCarPositions == HOOK_ENABLED) {
        StartPipingSession(ePipe_chunk_car);
        for (cat = eVehicle_self; cat < eVehicle_not_really; cat++) {
            if (cat == eVehicle_self) {
                car_count = 1;
            } else {
                car_count = GetCarCount(cat);
            }
            for (i = 0; i < car_count; i++) {
                if (cat == eVehicle_self) {
                    car = &HV(gProgram_state).current_car;
                } else {
                    car = GetCarSpec(cat, i);
                }
                AddCarToPipingSession(cat << 8 | i,
                                      &car->car_master_actor->t.t.mat, &car->v, car->speedo_speed,
                                      car->lf_sus_position, car->rf_sus_position, car->lr_sus_position, car->rr_sus_position,
                                      car->steering_angle, car->revs, car->gear, car->frame_collision_flag);
            }
        }
        EndPipingSession();
        session_started = 0;
        for (cat = eVehicle_self; cat < eVehicle_net_player; cat++) {
            if (cat == eVehicle_self) {
                car_count = 1;
            } else {
                car_count = GetCarCount(cat);
            }
            for (i = 0; i < car_count; i++) {
                if (cat == eVehicle_self) {
                    car = &HV(gProgram_state).current_car;
                } else {
                    car = GetCarSpec(cat, i);
                }
                if (car->active) {
                    difference_found = 0;
                    for (j = 0; j < COUNT_OF(car->damage_units); j++) {
                        damage_deltas[j] = car->damage_units[j].damage_level - car->frame_start_damage[j];
                        difference_found |= damage_deltas[j];
                        car->frame_start_damage[j] = car->damage_units[j].damage_level;
                    }
                    if (difference_found) {
                        if (!session_started) {
                            StartPipingSession(ePipe_chunk_damage);
                            session_started = 1;
                        }
                        AddDamageToPipingSession(cat << 8 | i, damage_deltas);
                    }
                }
            }
        }
        if (session_started) {
            EndPipingSession();
        }
    } else {
        original_PipeCarPositions();
    }
}

function_hook_state_t function_hook_state_ResetPipePlayToEnd = HOOK_ENABLED;
static void(__cdecl*original_ResetPipePlayToEnd)() = (void(__cdecl*)())0x00429b22;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToEnd, ResetPipePlayToEnd)
void __cdecl ResetPipePlayToEnd() {
    LOG_TRACE("()");


    if (function_hook_state_ResetPipePlayToEnd == HOOK_ENABLED) {
        HV(gPipe_play_ptr) = HV(gPipe_record_ptr);
    } else {
        original_ResetPipePlayToEnd();
    }
}

function_hook_state_t function_hook_state_ResetPipePlayToStart = HOOK_ENABLED;
static void(__cdecl*original_ResetPipePlayToStart)() = (void(__cdecl*)())0x00429b37;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToStart, ResetPipePlayToStart)
void __cdecl ResetPipePlayToStart() {
    LOG_TRACE("()");


    if (function_hook_state_ResetPipePlayToStart == HOOK_ENABLED) {
        HV(gPipe_play_ptr) = HV(gPipe_buffer_oldest);
    } else {
        original_ResetPipePlayToStart();
    }
}

function_hook_state_t function_hook_state_GetPipePlayPtr = HOOK_ENABLED;
static tU8 *(__cdecl*original_GetPipePlayPtr)() = (tU8 *(__cdecl*)())0x00429b4c;
CARM95_HOOK_FUNCTION(original_GetPipePlayPtr, GetPipePlayPtr)
tU8* __cdecl GetPipePlayPtr() {
    LOG_TRACE("()");


    if (function_hook_state_GetPipePlayPtr == HOOK_ENABLED) {
        return HV(gPipe_play_ptr);
    } else {
        return original_GetPipePlayPtr();
    }
}

function_hook_state_t function_hook_state_SetPipePlayPtr = HOOK_ENABLED;
static void(__cdecl*original_SetPipePlayPtr)(tU8 *) = (void(__cdecl*)(tU8 *))0x00429b61;
CARM95_HOOK_FUNCTION(original_SetPipePlayPtr, SetPipePlayPtr)
void __cdecl SetPipePlayPtr(tU8 *pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_SetPipePlayPtr == HOOK_ENABLED) {
        HV(gPipe_play_ptr) = pPtr;
    } else {
        original_SetPipePlayPtr(pPtr);
    }
}

function_hook_state_t function_hook_state_AdvanceChunkPtr = HOOK_ENABLED;
static void(__cdecl*original_AdvanceChunkPtr)(tPipe_chunk **, tChunk_subject_index) = (void(__cdecl*)(tPipe_chunk **, tChunk_subject_index))0x00429fcd;
CARM95_HOOK_FUNCTION(original_AdvanceChunkPtr, AdvanceChunkPtr)
void __cdecl AdvanceChunkPtr(tPipe_chunk **pChunk, tChunk_subject_index pType) {
    tPipe_chunk *old_chunk;
    LOG_TRACE("(%p, %u)", pChunk, pType);

    (void)pChunk;
    (void)pType;
    (void)old_chunk;

    if (function_hook_state_AdvanceChunkPtr == HOOK_ENABLED) {
        old_chunk = *pChunk;
        if (HV(gDisable_advance)) {
            return;
        }
        switch (pType) {
            case ePipe_chunk_model_geometry:
                *(tU8**)pChunk += offsetof(tPipe_model_geometry_data, vertex_changes) + (*pChunk)->chunk_data.model_geometry_data.vertex_count * sizeof(tChanged_vertex);
                break;
            case ePipe_chunk_pedestrian:
                *(tU8**)pChunk += (((*pChunk)->chunk_data.pedestrian_data.hit_points <= 0) ? sizeof(tPipe_pedestrian_data) : offsetof(tPipe_pedestrian_data, spin_period));
                break;
            case ePipe_chunk_frame_boundary:
                *(tU8**)pChunk += sizeof(tPipe_frame_boundary_data);
                break;
            case ePipe_chunk_car:
                *(tU8**)pChunk += sizeof(tPipe_car_data);
                break;
            case ePipe_chunk_sound:
                *(tU8**)pChunk += sizeof(tPipe_sound_data);
                break;
            case ePipe_chunk_damage:
                *(tU8**)pChunk += sizeof(tPipe_damage_data);
                break;
            case ePipe_chunk_special:
                *(tU8**)pChunk += sizeof(tPipe_special_data);
                break;
            case ePipe_chunk_ped_gib:
                *(tU8**)pChunk += sizeof(tPipe_ped_gib_data);
                break;
            case ePipe_chunk_incident:
                *(tU8**)pChunk += sizeof(tPipe_incident_data);
                break;
            case ePipe_chunk_spark:
                *(tU8**)pChunk += sizeof(tPipe_spark_data);
                break;
            case ePipe_chunk_shrapnel:
                *(tU8**)pChunk += (((*pChunk)->subject_index & 0x8000) ? sizeof(tPipe_shrapnel_data) : offsetof(tPipe_shrapnel_data, age));
                break;
            case ePipe_chunk_screen_shake:
                *(tU8**)pChunk += sizeof(tPipe_screen_shake_data);
                break;
            case ePipe_chunk_groove_stop:
                *(tU8**)pChunk += sizeof(tPipe_groove_stop_data);
                break;
            case ePipe_chunk_non_car:
                *(tU8**)pChunk += sizeof(tPipe_non_car_data);
                break;
            case ePipe_chunk_smoke:
                *(tU8**)pChunk += sizeof(tPipe_smoke_data);
                break;
            case ePipe_chunk_oil_spill:
                *(tU8**)pChunk += sizeof(tPipe_oil_spill_data);
                break;
            case ePipe_chunk_smoke_column:
                *(tU8**)pChunk += sizeof(tPipe_smoke_column_data);
                break;
            case ePipe_chunk_flame:
                *(tU8**)pChunk += sizeof(tPipe_flame_data);
                break;
            case ePipe_chunk_smudge:
                *(tU8**)pChunk += offsetof(tPipe_smudge_data, vertex_changes) + (*pChunk)->chunk_data.smudge_data.vertex_count * sizeof(tSmudged_vertex);
                break;
            case ePipe_chunk_splash:
                *(tU8**)pChunk += sizeof(tPipe_splash_data);
                break;
            case ePipe_chunk_prox_ray:
                *(tU8**)pChunk += sizeof(tPipe_prox_ray_data);
                break;
            case ePipe_chunk_skid_adjustment:
                *(tU8**)pChunk += sizeof(tPipe_skid_adjustment);
                break;
        }
        *(tU8**)pChunk += offsetof(tPipe_chunk, chunk_data);
        if (*(tU8**)pChunk == HV(gEnd_of_session)) {
            *pChunk = old_chunk;
        } else if (*(tU8**)pChunk > HV(gEnd_of_session)) {
            *pChunk = old_chunk;
        }
    } else {
        original_AdvanceChunkPtr(pChunk, pType);
    }
}

function_hook_state_t function_hook_state_ApplyModelGeometry = HOOK_ENABLED;
static void(__cdecl*original_ApplyModelGeometry)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a1fd;
CARM95_HOOK_FUNCTION(original_ApplyModelGeometry, ApplyModelGeometry)
void __cdecl ApplyModelGeometry(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    if (function_hook_state_ApplyModelGeometry == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        } else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0xff);
        }
        model_ptr = car->car_model_actors[(*pChunk)->chunk_data.model_geometry_data.model_index].actor->model;
        for (i = 0; i < (*pChunk)->chunk_data.model_geometry_data.vertex_count; i++) {
            BrVector3Accumulate(&model_ptr->vertices[(*pChunk)->chunk_data.model_geometry_data.vertex_changes[i].vertex_index].p,
                                &(*pChunk)->chunk_data.model_geometry_data.vertex_changes[i].delta_coordinates);
        }
        SetModelForUpdate(model_ptr, car, 0);
        AdvanceChunkPtr(pChunk, ePipe_chunk_model_geometry);
    } else {
        original_ApplyModelGeometry(pChunk);
    }
}

function_hook_state_t function_hook_state_DoSmudge = HOOK_ENABLED;
static void(__cdecl*original_DoSmudge)(tPipe_chunk **, int) = (void(__cdecl*)(tPipe_chunk **, int))0x00429b74;
CARM95_HOOK_FUNCTION(original_DoSmudge, DoSmudge)
void __cdecl DoSmudge(tPipe_chunk **pChunk, int pDir) {
    int i;
    int v;
    tU8 inc;
    br_model *model_ptr;
    tCar_spec *car;
    int group;
    LOG_TRACE("(%p, %d)", pChunk, pDir);

    (void)pChunk;
    (void)pDir;
    (void)i;
    (void)v;
    (void)inc;
    (void)model_ptr;
    (void)car;
    (void)group;

    if (function_hook_state_DoSmudge == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        } else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0xff);
        }
        model_ptr = car->car_model_actors[(*pChunk)->chunk_data.smudge_data.model_index].actor->model;
        for (i = 0; i < (*pChunk)->chunk_data.smudge_data.vertex_count; i++) {
            v = (*pChunk)->chunk_data.smudge_data.vertex_changes[i].vertex_index;
            inc = (*pChunk)->chunk_data.smudge_data.vertex_changes[i].light_index * pDir;
            V11MODEL(model_ptr)->groups->vertex_colours[v] = ((V11MODEL(model_ptr)->groups->vertex_colours[v] >> 24) + inc) << 24;
            if (model_ptr->flags & BR_MODF_UPDATEABLE) {
                model_ptr->vertices[V11MODEL(model_ptr)->groups->vertex_user[v]].index = (V11MODEL(model_ptr)->groups->vertex_colours[v] >> 24) + inc;
            }
        }
    } else {
        original_DoSmudge(pChunk, pDir);
    }
}

function_hook_state_t function_hook_state_ApplySmudge = HOOK_ENABLED;
static void(__cdecl*original_ApplySmudge)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a3b1;
CARM95_HOOK_FUNCTION(original_ApplySmudge, ApplySmudge)
void __cdecl ApplySmudge(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySmudge == HOOK_ENABLED) {
        DoSmudge(pChunk, 1);
        AdvanceChunkPtr(pChunk, ePipe_chunk_smudge);
    } else {
        original_ApplySmudge(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyPedestrian = HOOK_ENABLED;
static void(__cdecl*original_ApplyPedestrian)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a3d8;
CARM95_HOOK_FUNCTION(original_ApplyPedestrian, ApplyPedestrian)
void __cdecl ApplyPedestrian(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyPedestrian == HOOK_ENABLED) {
        AdjustPedestrian(
                (*pChunk)->subject_index,
                ((*pChunk)->chunk_data.pedestrian_data.action_and_frame_index & 0x70) >> 4,
                (*pChunk)->chunk_data.pedestrian_data.action_and_frame_index & 0x0f,
                (*pChunk)->chunk_data.pedestrian_data.hit_points,
                (*pChunk)->chunk_data.pedestrian_data.action_and_frame_index >> 7,
                (*pChunk)->chunk_data.pedestrian_data.parent,
                (*pChunk)->chunk_data.pedestrian_data.parent_actor,
                (*pChunk)->chunk_data.pedestrian_data.spin_period,
                (*pChunk)->chunk_data.pedestrian_data.jump_magnitude,
                &(*pChunk)->chunk_data.pedestrian_data.offset,
                &(*pChunk)->chunk_data.pedestrian_data.new_translation);
        AdvanceChunkPtr(pChunk, ePipe_chunk_pedestrian);
    } else {
        original_ApplyPedestrian(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySpark = HOOK_ENABLED;
static void(__cdecl*original_ApplySpark)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a472;
CARM95_HOOK_FUNCTION(original_ApplySpark, ApplySpark)
void __cdecl ApplySpark(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySpark == HOOK_ENABLED) {
        AdjustSpark((*pChunk)->subject_index,
                    &(*pChunk)->chunk_data.spark_data.pos,
                    &(*pChunk)->chunk_data.spark_data.v);
        AdvanceChunkPtr(pChunk, ePipe_chunk_spark);
    } else {
        original_ApplySpark(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyShrapnel = HOOK_ENABLED;
static void(__cdecl*original_ApplyShrapnel)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a4b0;
CARM95_HOOK_FUNCTION(original_ApplyShrapnel, ApplyShrapnel)
void __cdecl ApplyShrapnel(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyShrapnel == HOOK_ENABLED) {
        AdjustShrapnel((*pChunk)->subject_index,
                       &(*pChunk)->chunk_data.shrapnel_data.pos,
                       (*pChunk)->chunk_data.shrapnel_data.age,
                       (*pChunk)->chunk_data.shrapnel_data.material);
        AdvanceChunkPtr(pChunk, ePipe_chunk_shrapnel);
    } else {
        original_ApplyShrapnel(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyScreenWobble = HOOK_ENABLED;
static void(__cdecl*original_ApplyScreenWobble)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a4f8;
CARM95_HOOK_FUNCTION(original_ApplyScreenWobble, ApplyScreenWobble)
void __cdecl ApplyScreenWobble(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyScreenWobble == HOOK_ENABLED) {
        SetScreenWobble((*pChunk)->chunk_data.screen_shake_data.wobble_x,
                        (*pChunk)->chunk_data.screen_shake_data.wobble_y);
        AdvanceChunkPtr(pChunk, ePipe_chunk_screen_shake);
    } else {
        original_ApplyScreenWobble(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyGrooveStop = HOOK_ENABLED;
static void(__cdecl*original_ApplyGrooveStop)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a52d;
CARM95_HOOK_FUNCTION(original_ApplyGrooveStop, ApplyGrooveStop)
void __cdecl ApplyGrooveStop(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyGrooveStop == HOOK_ENABLED) {
        SetGrooveInterrupt((*pChunk)->subject_index,
                           &(*pChunk)->chunk_data.groove_stop_data.matrix,
                           (*pChunk)->chunk_data.groove_stop_data.path_interrupt,
                           (*pChunk)->chunk_data.groove_stop_data.object_interrupt,
                           (*pChunk)->chunk_data.groove_stop_data.path_resumption,
                           (*pChunk)->chunk_data.groove_stop_data.object_resumption);
        AdvanceChunkPtr(pChunk, ePipe_chunk_groove_stop);
    } else {
        original_ApplyGrooveStop(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyNonCar = HOOK_ENABLED;
static void(__cdecl*original_ApplyNonCar)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a586;
CARM95_HOOK_FUNCTION(original_ApplyNonCar, ApplyNonCar)
void __cdecl ApplyNonCar(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyNonCar == HOOK_ENABLED) {
        AdjustNonCar((*pChunk)->chunk_data.non_car_data.actor,
                     &(*pChunk)->chunk_data.non_car_data.mat);
        AdvanceChunkPtr(pChunk, ePipe_chunk_non_car);
    } else {
        original_ApplyNonCar(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySmoke = HOOK_ENABLED;
static void(__cdecl*original_ApplySmoke)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a5b9;
CARM95_HOOK_FUNCTION(original_ApplySmoke, ApplySmoke)
void __cdecl ApplySmoke(tPipe_chunk **pChunk) {
    br_vector3 pos;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)pos;

    if (function_hook_state_ApplySmoke == HOOK_ENABLED) {
        GetReducedPos(&pos, &(*pChunk)->chunk_data.smoke_data.pos);
        AdjustSmoke((*pChunk)->subject_index,
                    (*pChunk)->chunk_data.smoke_data.type,
                    &pos,
                    (*pChunk)->chunk_data.smoke_data.radius / 1024.f,
                    (*pChunk)->chunk_data.smoke_data.strength / 256.f);
        AdvanceChunkPtr(pChunk, ePipe_chunk_smoke);
    } else {
        original_ApplySmoke(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySmokeColumn = HOOK_ENABLED;
static void(__cdecl*original_ApplySmokeColumn)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a651;
CARM95_HOOK_FUNCTION(original_ApplySmokeColumn, ApplySmokeColumn)
void __cdecl ApplySmokeColumn(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySmokeColumn == HOOK_ENABLED) {
        AdjustSmokeColumn((*pChunk)->subject_index & 0x3fff,
                          ((((*pChunk)->chunk_data.smoke_column_data.car_ID) >> 8) == 0) ? &HV(gProgram_state).current_car : GetCarSpec((*pChunk)->chunk_data.smoke_column_data.car_ID >> 8, (*pChunk)->chunk_data.smoke_column_data.car_ID & 0xff),
                          (*pChunk)->chunk_data.smoke_column_data.vertex,
                          (*pChunk)->subject_index >> 14);
        AdvanceChunkPtr(pChunk, ePipe_chunk_smoke_column);
    } else {
        original_ApplySmokeColumn(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyFlame = HOOK_ENABLED;
static void(__cdecl*original_ApplyFlame)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a6f8;
CARM95_HOOK_FUNCTION(original_ApplyFlame, ApplyFlame)
void __cdecl ApplyFlame(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyFlame == HOOK_ENABLED) {
        AdjustFlame((*pChunk)->subject_index,
                    (*pChunk)->chunk_data.flame_data.frame_count,
                    (*pChunk)->chunk_data.flame_data.scale_x,
                    (*pChunk)->chunk_data.flame_data.scale_y,
                    (*pChunk)->chunk_data.flame_data.offset_x,
                    (*pChunk)->chunk_data.flame_data.offset_x);
        AdvanceChunkPtr(pChunk, ePipe_chunk_flame);
    } else {
        original_ApplyFlame(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySplash = HOOK_ENABLED;
static void(__cdecl*original_ApplySplash)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a752;
CARM95_HOOK_FUNCTION(original_ApplySplash, ApplySplash)
void __cdecl ApplySplash(tPipe_chunk **pChunk) {
    tCar_spec *c;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)c;

    if (function_hook_state_ApplySplash == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            c = &HV(gProgram_state).current_car;
        } else {
            c = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0xff);
        }
        c->water_d = (*pChunk)->chunk_data.splash_data.d;
        BrVector3Copy(&c->water_normal, &(*pChunk)->chunk_data.splash_data.normal);
        AdvanceChunkPtr(pChunk, ePipe_chunk_splash);
    } else {
        original_ApplySplash(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyOilSpill = HOOK_ENABLED;
static void(__cdecl*original_ApplyOilSpill)(tPipe_chunk **, tU32) = (void(__cdecl*)(tPipe_chunk **, tU32))0x0042a80d;
CARM95_HOOK_FUNCTION(original_ApplyOilSpill, ApplyOilSpill)
void __cdecl ApplyOilSpill(tPipe_chunk **pChunk, tU32 pStop_time) {
    LOG_TRACE("(%p, %u)", pChunk, pStop_time);

    (void)pChunk;
    (void)pStop_time;

    if (function_hook_state_ApplyOilSpill == HOOK_ENABLED) {
        AdjustOilSpill((*pChunk)->subject_index,
                       &(*pChunk)->chunk_data.oil_data.mat,
                       (*pChunk)->chunk_data.oil_data.full_size,
                       (*pChunk)->chunk_data.oil_data.grow_rate,
                       (*pChunk)->chunk_data.oil_data.spill_time,
                       pStop_time,
                       (*pChunk)->chunk_data.oil_data.car,
                       &(*pChunk)->chunk_data.oil_data.original_pos,
                       (*pChunk)->chunk_data.oil_data.pixelmap);
        AdvanceChunkPtr(pChunk, ePipe_chunk_oil_spill);
    } else {
        original_ApplyOilSpill(pChunk, pStop_time);
    }
}

function_hook_state_t function_hook_state_ApplyFrameBoundary = HOOK_ENABLED;
static void(__cdecl*original_ApplyFrameBoundary)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a87c;
CARM95_HOOK_FUNCTION(original_ApplyFrameBoundary, ApplyFrameBoundary)
void __cdecl ApplyFrameBoundary(tPipe_chunk **pChunk) {
    tU32 result;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)result;

    if (function_hook_state_ApplyFrameBoundary == HOOK_ENABLED) {
        HV(gLast_replay_frame_time) = (*pChunk)->chunk_data.frame_boundary_data.time;
        // DAT_0054b244 = PDGetTotalTime();
        AdvanceChunkPtr(pChunk, ePipe_chunk_frame_boundary);
    } else {
        original_ApplyFrameBoundary(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySound = HOOK_ENABLED;
static void(__cdecl*original_ApplySound)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a8b5;
CARM95_HOOK_FUNCTION(original_ApplySound, ApplySound)
void __cdecl ApplySound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySound == HOOK_ENABLED) {
        if (!HV(gDisable_sound)) {
            if ((*pChunk)->chunk_data.sound_data.volume == 0) {
                DRS3StartSound2(GetOutletFromIndex((*pChunk)->chunk_data.sound_data.outlet_index),
                                (*pChunk)->subject_index,
                                1,
                                -1,
                                -1,
                                65535.f * GetReplayRate(),
                                0x10000);
            } else if (BrVector3LengthSquared(&(*pChunk)->chunk_data.sound_data.position) == 0) {
                DRS3StartSound2(GetOutletFromIndex((*pChunk)->chunk_data.sound_data.outlet_index),
                                (*pChunk)->subject_index,
                                1,
                                (*pChunk)->chunk_data.sound_data.volume & 0xff,
                                (*pChunk)->chunk_data.sound_data.volume >> 8,
                                (float)(*pChunk)->chunk_data.sound_data.pitch * fabsf(GetReplayRate()),
                                0x10000);
            } else {
                DRS3StartSound3D(GetOutletFromIndex((*pChunk)->chunk_data.sound_data.outlet_index),
                                 (*pChunk)->subject_index,
                                 &(*pChunk)->chunk_data.sound_data.position,
                                 &HV(gZero_vector),
                                 1,
                                 (*pChunk)->chunk_data.sound_data.volume,
                                 (float)(*pChunk)->chunk_data.sound_data.pitch * fabsf(GetReplayRate()),
                                 0x10000);
            }
        }
        AdvanceChunkPtr(pChunk, ePipe_chunk_sound);
    } else {
        original_ApplySound(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyCar = HOOK_ENABLED;
static void(__cdecl*original_ApplyCar)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042aa59;
CARM95_HOOK_FUNCTION(original_ApplyCar, ApplyCar)
void __cdecl ApplyCar(tPipe_chunk **pChunk) {
    tCar_spec *car;
    br_vector3 com_offset_c;
    br_vector3 com_offset_w;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)com_offset_c;
    (void)com_offset_w;
    (void)__block0___scale;

    if (function_hook_state_ApplyCar == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        } else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0x00ff);
        }
        BrMatrix34Copy(&car->car_master_actor->t.t.mat, &(*pChunk)->chunk_data.car_data.transformation);
        BrVector3Copy(&car->v, &(*pChunk)->chunk_data.car_data.velocity);
        BrMatrix34TApplyV(&car->velocity_car_space, &car->v, &car->car_master_actor->t.t.mat);
        BrVector3InvScale(&car->velocity_car_space, &car->velocity_car_space, WORLD_SCALE);
        if (BrVector3LengthSquared(&car->velocity_car_space) >= .0001f) {
            BrVector3Normalise(&car->direction, &car->v);
        } else {
            BrVector3Negate(&car->direction, (br_vector3*)car->car_master_actor->t.t.mat.m[2]);
        }
        BrVector3Copy(&car->pos, &car->car_master_actor->t.t.translate.t);
        BrVector3InvScale(&com_offset_c, &car->cmpos, WORLD_SCALE);
        BrMatrix34ApplyV(&com_offset_w, &com_offset_c, &car->car_master_actor->t.t.mat);
        BrVector3Accumulate(&car->pos, &com_offset_w);
        car->speedo_speed = .07f * (*pChunk)->chunk_data.car_data.speedo_speed / 32767.f;
        car->lf_sus_position = 0.15f * (*pChunk)->chunk_data.car_data.lf_sus_position / 127.f;
        car->rf_sus_position = 0.15f * (*pChunk)->chunk_data.car_data.rf_sus_position / 127.f;
        car->lr_sus_position = 0.15f * (*pChunk)->chunk_data.car_data.lr_sus_position / 127.f;
        car->rr_sus_position = 0.15f * (*pChunk)->chunk_data.car_data.rr_sus_position / 127.f;
        car->steering_angle = 60.f * (*pChunk)->chunk_data.car_data.steering_angle / 32767.f;
        car->revs = 10 * ((*pChunk)->chunk_data.car_data.revs_and_gear & 0x7ff);
        car->gear = ((*pChunk)->chunk_data.car_data.revs_and_gear >> 12) - 1;
        car->frame_collision_flag = ((*pChunk)->chunk_data.car_data.revs_and_gear >> 11) & 0x1;
        AdvanceChunkPtr(pChunk, ePipe_chunk_car);
    } else {
        original_ApplyCar(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyDamage = HOOK_ENABLED;
static void(__cdecl*original_ApplyDamage)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042ae65;
CARM95_HOOK_FUNCTION(original_ApplyDamage, ApplyDamage)
void __cdecl ApplyDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    if (function_hook_state_ApplyDamage == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        } else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0x00ff);
        }
        for (i = 0; i < COUNT_OF(car->damage_units); i++) {
            car->damage_units[i].damage_level += (*pChunk)->chunk_data.damage_data.damage_delta[i];
        }
        AdvanceChunkPtr(pChunk, ePipe_chunk_damage);
    } else {
        original_ApplyDamage(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySpecial = HOOK_ENABLED;
static void(__cdecl*original_ApplySpecial)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042af1e;
CARM95_HOOK_FUNCTION(original_ApplySpecial, ApplySpecial)
void __cdecl ApplySpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySpecial == HOOK_ENABLED) {
        switch ((*pChunk)->subject_index) {
            case 0:
                if (fabsf(GetReplayRate()) <= 1.f) {
                    FadePaletteDown();
                }
                break;
            case 1:
                HV(gPed_scale_factor) = 2.0f;
                break;
            case 2:
                HV(gPed_scale_factor) = 1.0f;
                break;
            case 3:
                HV(gPed_scale_factor) = 0.5f;
                break;
            case 4:
                HV(gPed_scale_factor) = 1.0f;
                break;
        }
        AdvanceChunkPtr(pChunk, ePipe_chunk_special);
    } else {
        original_ApplySpecial(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyPedGib = HOOK_ENABLED;
static void(__cdecl*original_ApplyPedGib)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042afc8;
CARM95_HOOK_FUNCTION(original_ApplyPedGib, ApplyPedGib)
void __cdecl ApplyPedGib(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyPedGib == HOOK_ENABLED) {
        AdjustPedGib((*pChunk)->subject_index,
            (*pChunk)->chunk_data.ped_gib_data.size,
            (*pChunk)->chunk_data.ped_gib_data.gib_index,
            (*pChunk)->chunk_data.ped_gib_data.ped_parent_index,
            &(*pChunk)->chunk_data.ped_gib_data.transform);
        AdvanceChunkPtr(pChunk, ePipe_chunk_ped_gib);
    } else {
        original_ApplyPedGib(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyProxRay = HOOK_ENABLED;
static void(__cdecl*original_ApplyProxRay)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b01f;
CARM95_HOOK_FUNCTION(original_ApplyProxRay, ApplyProxRay)
void __cdecl ApplyProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplyProxRay == HOOK_ENABLED) {
        AdjustProxRay(
                (*pChunk)->subject_index,
                (*pChunk)->chunk_data.prox_ray_data.car_ID,
                (*pChunk)->chunk_data.prox_ray_data.ped_index,
                (*pChunk)->chunk_data.prox_ray_data.time);
        AdvanceChunkPtr(pChunk, ePipe_chunk_prox_ray);
    } else {
        original_ApplyProxRay(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplySkidAdjustment = HOOK_ENABLED;
static void(__cdecl*original_ApplySkidAdjustment)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b068;
CARM95_HOOK_FUNCTION(original_ApplySkidAdjustment, ApplySkidAdjustment)
void __cdecl ApplySkidAdjustment(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_ApplySkidAdjustment == HOOK_ENABLED) {
        AdjustSkid((*pChunk)->subject_index,
                   &(*pChunk)->chunk_data.skid_adjustment.matrix,
                   (*pChunk)->chunk_data.skid_adjustment.material_index);
        AdvanceChunkPtr(pChunk, ePipe_chunk_skid_adjustment);
    } else {
        original_ApplySkidAdjustment(pChunk);
    }
}

function_hook_state_t function_hook_state_ApplyPipedSession = HOOK_ENABLED;
static int(__cdecl*original_ApplyPipedSession)(tU8 **) = (int(__cdecl*)(tU8 **))0x00429cfb;
CARM95_HOOK_FUNCTION(original_ApplyPipedSession, ApplyPipedSession)
int __cdecl ApplyPipedSession(tU8 **pPtr) {
    int i;
    int return_value;
    tPipe_chunk *chunk_ptr;
    tPipe_chunk_type chunk_type;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)i;
    (void)return_value;
    (void)chunk_ptr;
    (void)chunk_type;

    if (function_hook_state_ApplyPipedSession == HOOK_ENABLED) {
        if (*pPtr == HV(gPipe_record_ptr)) {
            return 1;
        }
        HV(gEnd_of_session) = *pPtr + (LengthOfSession((tPipe_session *)*pPtr) - sizeof(tU16));
        chunk_ptr = (tPipe_chunk *)(*pPtr + offsetof(tPipe_session, chunks));
        return_value = 0;
        chunk_type = ((tPipe_session *)*pPtr)->chunk_type;
        for (i = 0; i < ((tPipe_session *)*pPtr)->number_of_chunks; i++) {
            switch ((int)chunk_type) {
                case ePipe_chunk_model_geometry:
                    ApplyModelGeometry(&chunk_ptr);
                    break;
                case ePipe_chunk_pedestrian:
                    ApplyPedestrian(&chunk_ptr);
                    break;
                case ePipe_chunk_frame_boundary:
                    ApplyFrameBoundary(&chunk_ptr);
                    return_value = 1;
                    break;
                case ePipe_chunk_car:
                    ApplyCar(&chunk_ptr);
                    break;
                case ePipe_chunk_sound:
                    ApplySound(&chunk_ptr);
                    break;
                case ePipe_chunk_damage:
                    ApplyDamage(&chunk_ptr);
                    break;
                case ePipe_chunk_special:
                    ApplySpecial(&chunk_ptr);
                    break;
                case ePipe_chunk_ped_gib:
                    ApplyPedGib(&chunk_ptr);
                    break;
                case ePipe_chunk_incident:
                    AdvanceChunkPtr(&chunk_ptr, ePipe_chunk_incident);
                    break;
                case ePipe_chunk_spark:
                    ApplySpark(&chunk_ptr);
                    break;
                case ePipe_chunk_shrapnel:
                    ApplyShrapnel(&chunk_ptr);
                    break;
                case ePipe_chunk_screen_shake:
                    ApplyScreenWobble(&chunk_ptr);
                    break;
                case ePipe_chunk_groove_stop:
                    ApplyGrooveStop(&chunk_ptr);
                    break;
                case ePipe_chunk_non_car:
                    ApplyNonCar(&chunk_ptr);
                    break;
                case ePipe_chunk_smoke:
                    ApplySmoke(&chunk_ptr);
                    break;
                case ePipe_chunk_oil_spill:
                    ApplyOilSpill(&chunk_ptr, 0);
                    break;
                case ePipe_chunk_smoke_column:
                    ApplySmokeColumn(&chunk_ptr);
                    break;
                case ePipe_chunk_flame:
                    ApplyFlame(&chunk_ptr);
                    break;
                case ePipe_chunk_smudge:
                    ApplySmudge(&chunk_ptr);
                    break;
                case ePipe_chunk_splash:
                    ApplySplash(&chunk_ptr);
                    break;
                case ePipe_chunk_prox_ray:
                    ApplyProxRay(&chunk_ptr);
                    break;
                case ePipe_chunk_skid_adjustment:
                    ApplySkidAdjustment(&chunk_ptr);
                    break;
                default:
                    break;
            }
        }
        *pPtr += LengthOfSession((tPipe_session *)*pPtr);
        if (*pPtr >= HV(gPipe_buffer_working_end) && *pPtr != HV(gPipe_record_ptr)) {
            *pPtr = HV(gPipe_buffer_start);
        }
        return return_value;
    } else {
        return original_ApplyPipedSession(pPtr);
    }
}

function_hook_state_t function_hook_state_MoveSessionPointerBackOne = HOOK_ENABLED;
static int(__cdecl*original_MoveSessionPointerBackOne)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042b419;
CARM95_HOOK_FUNCTION(original_MoveSessionPointerBackOne, MoveSessionPointerBackOne)
int __cdecl MoveSessionPointerBackOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_MoveSessionPointerBackOne == HOOK_ENABLED) {
        if (*pPtr == HV(gPipe_buffer_oldest) && *pPtr != HV(gPipe_record_ptr)) {
            return 1;
        }
        if (*pPtr == HV(gPipe_buffer_start)) {
            *pPtr = HV(gPipe_buffer_working_end);
        }
        *pPtr -= sizeof(tU16);
        *pPtr -= *(tU16*)*pPtr;
        return 0;
    } else {
        return original_MoveSessionPointerBackOne(pPtr);
    }
}

function_hook_state_t function_hook_state_MoveSessionPointerForwardOne = HOOK_ENABLED;
static int(__cdecl*original_MoveSessionPointerForwardOne)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042bf9e;
CARM95_HOOK_FUNCTION(original_MoveSessionPointerForwardOne, MoveSessionPointerForwardOne)
int __cdecl MoveSessionPointerForwardOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_MoveSessionPointerForwardOne == HOOK_ENABLED) {
        *pPtr += LengthOfSession((tPipe_session*)*pPtr);
        if (*pPtr >= HV(gPipe_buffer_working_end) && *pPtr != HV(gPipe_record_ptr)) {
            *pPtr = HV(gPipe_buffer_start);
        }
        return *pPtr == HV(gPipe_record_ptr);
    } else {
        return original_MoveSessionPointerForwardOne(pPtr);
    }
}

function_hook_state_t function_hook_state_FindPreviousChunk = HOOK_ENABLED;
static tPipe_chunk *(__cdecl*original_FindPreviousChunk)(tU8 *, tPipe_chunk_type, tChunk_subject_index) = (tPipe_chunk *(__cdecl*)(tU8 *, tPipe_chunk_type, tChunk_subject_index))0x0042b492;
CARM95_HOOK_FUNCTION(original_FindPreviousChunk, FindPreviousChunk)
tPipe_chunk* __cdecl FindPreviousChunk(tU8 *pPtr, tPipe_chunk_type pType, tChunk_subject_index pIndex) {
    tU8 *ptr;
    int i;
    int reached_end;
    int chunk_counter;
    tPipe_chunk *mr_chunky;
    tChunk_subject_index masked_index;
    LOG_TRACE("(%p, %d, %u)", pPtr, pType, pIndex);

    (void)pPtr;
    (void)pType;
    (void)pIndex;
    (void)ptr;
    (void)i;
    (void)reached_end;
    (void)chunk_counter;
    (void)mr_chunky;
    (void)masked_index;

    if (function_hook_state_FindPreviousChunk == HOOK_ENABLED) {
        ptr = pPtr;
        chunk_counter = 0;
        masked_index = pIndex & 0x0fff;
        while (1) {
            if (!MoveSessionPointerBackOne(&pPtr)) {
                reached_end = chunk_counter < HV(gMax_rewind_chunks);
                chunk_counter++;
            } else {
                reached_end = 1;
            }
            if (!reached_end) {
                HV(gEnd_of_session) = pPtr + LengthOfSession((tPipe_session*)ptr) - sizeof(tU16);
                mr_chunky = &((tPipe_session*)ptr)->chunks;
                for (i = 0; i < ((tPipe_session*)ptr)->number_of_chunks && ((tPipe_session*)ptr)->chunk_type == pType; i++) {
                    if ((mr_chunky->subject_index & 0xfff) == masked_index) {
                        return mr_chunky;
                    }
                    AdvanceChunkPtr(&mr_chunky, pType);
                }
            }
            if (reached_end) {
                return NULL;
            }
        }
    } else {
        return original_FindPreviousChunk(pPtr, pType, pIndex);
    }
}

function_hook_state_t function_hook_state_UndoModelGeometry = HOOK_ENABLED;
static void(__cdecl*original_UndoModelGeometry)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b5ae;
CARM95_HOOK_FUNCTION(original_UndoModelGeometry, UndoModelGeometry)
void __cdecl UndoModelGeometry(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    if (function_hook_state_UndoModelGeometry == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        } else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0x00ff);
        }
        model_ptr = car->car_model_actors[(*pChunk)->chunk_data.model_geometry_data.model_index].actor->model;
        for (i = 0; i < (*pChunk)->chunk_data.model_geometry_data.vertex_count; i++) {
            BrVector3Sub(&model_ptr->vertices[(*pChunk)->chunk_data.model_geometry_data.vertex_changes[i].vertex_index].p,
                         &model_ptr->vertices[(*pChunk)->chunk_data.model_geometry_data.vertex_changes[i].vertex_index].p,
                         &(*pChunk)->chunk_data.model_geometry_data.vertex_changes[i].delta_coordinates);
        }
        SetModelForUpdate(model_ptr, car, 0);
        AdvanceChunkPtr(pChunk, ePipe_chunk_model_geometry);
    } else {
        original_UndoModelGeometry(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoSmudge = HOOK_ENABLED;
static void(__cdecl*original_UndoSmudge)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b762;
CARM95_HOOK_FUNCTION(original_UndoSmudge, UndoSmudge)
void __cdecl UndoSmudge(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    if (function_hook_state_UndoSmudge == HOOK_ENABLED) {
        DoSmudge(pChunk, -1);
        AdvanceChunkPtr(pChunk, ePipe_chunk_smudge);
    } else {
        original_UndoSmudge(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoPedestrian = HOOK_ENABLED;
static void(__cdecl*original_UndoPedestrian)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b78c;
CARM95_HOOK_FUNCTION(original_UndoPedestrian, UndoPedestrian)
void __cdecl UndoPedestrian(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoPedestrian == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        if (pPrev_chunk == NULL) {
            ApplyPedestrian(pChunk);
        }
        else {
            HV(gDisable_advance) = 1;
            ApplyPedestrian(&temp_prev_chunk);
            HV(gDisable_advance) = 0;
            AdvanceChunkPtr(pChunk, ePipe_chunk_pedestrian);
        }
    } else {
        original_UndoPedestrian(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoFrameBoundary = HOOK_ENABLED;
static void(__cdecl*original_UndoFrameBoundary)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b7e9;
CARM95_HOOK_FUNCTION(original_UndoFrameBoundary, UndoFrameBoundary)
void __cdecl UndoFrameBoundary(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoFrameBoundary == HOOK_ENABLED) {
        ApplyFrameBoundary(pChunk);
        AdvanceChunkPtr(pChunk, ePipe_chunk_frame_boundary);
    } else {
        original_UndoFrameBoundary(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoCar = HOOK_ENABLED;
static void(__cdecl*original_UndoCar)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b817;
CARM95_HOOK_FUNCTION(original_UndoCar, UndoCar)
void __cdecl UndoCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoCar == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        if (pPrev_chunk == NULL) {
            ApplyCar(pChunk);
        }
        else {
            HV(gDisable_advance) = 1;
            ApplyCar(&temp_prev_chunk);
            HV(gDisable_advance) = 0;
            AdvanceChunkPtr(pChunk, ePipe_chunk_car);
        }
    } else {
        original_UndoCar(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoSound = HOOK_ENABLED;
static void(__cdecl*original_UndoSound)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b874;
CARM95_HOOK_FUNCTION(original_UndoSound, UndoSound)
void __cdecl UndoSound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_UndoSound == HOOK_ENABLED) {
        AdvanceChunkPtr(pChunk,ePipe_chunk_sound);
    } else {
        original_UndoSound(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoDamage = HOOK_ENABLED;
static void(__cdecl*original_UndoDamage)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b88d;
CARM95_HOOK_FUNCTION(original_UndoDamage, UndoDamage)
void __cdecl UndoDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    if (function_hook_state_UndoDamage == HOOK_ENABLED) {
        if (((*pChunk)->subject_index & 0xff00) == 0) {
            car = &HV(gProgram_state).current_car;
        }
        else {
            car = GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0xff);
        }
        for (i = 0; i < COUNT_OF(car->damage_units); i++) {
            car->damage_units[i].damage_level -= (*pChunk)->chunk_data.damage_data.damage_delta[i];
        }
        AdvanceChunkPtr(pChunk, ePipe_chunk_damage);
    } else {
        original_UndoDamage(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoSpecial = HOOK_ENABLED;
static void(__cdecl*original_UndoSpecial)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b94c;
CARM95_HOOK_FUNCTION(original_UndoSpecial, UndoSpecial)
void __cdecl UndoSpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_UndoSpecial == HOOK_ENABLED) {
        if ((*pChunk)->subject_index == 0) {
            ApplySpecial(pChunk);
        } else {
            switch ((*pChunk)->subject_index) {
                case 1:
                    HV(gPed_scale_factor) = 1.0f;
                    break;
                case 2:
                    HV(gPed_scale_factor) = 2.0f;
                    break;
                case 3:
                    HV(gPed_scale_factor) = 1.0f;
                    break;
                case 4:
                    HV(gPed_scale_factor) = 0.5f;
                    break;
            }
            AdvanceChunkPtr(pChunk, ePipe_chunk_special);
        }
    } else {
        original_UndoSpecial(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoPedGib = HOOK_ENABLED;
static void(__cdecl*original_UndoPedGib)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b9f6;
CARM95_HOOK_FUNCTION(original_UndoPedGib, UndoPedGib)
void __cdecl UndoPedGib(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoPedGib == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplyPedGib(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_ped_gib);
    } else {
        original_UndoPedGib(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoSpark = HOOK_ENABLED;
static void(__cdecl*original_UndoSpark)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042ba42;
CARM95_HOOK_FUNCTION(original_UndoSpark, UndoSpark)
void __cdecl UndoSpark(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoSpark == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplySpark(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_spark);
    } else {
        original_UndoSpark(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoShrapnel = HOOK_ENABLED;
static void(__cdecl*original_UndoShrapnel)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042ba8e;
CARM95_HOOK_FUNCTION(original_UndoShrapnel, UndoShrapnel)
void __cdecl UndoShrapnel(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoShrapnel == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplyShrapnel(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_shrapnel);
    } else {
        original_UndoShrapnel(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoScreenWobble = HOOK_ENABLED;
static void(__cdecl*original_UndoScreenWobble)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bada;
CARM95_HOOK_FUNCTION(original_UndoScreenWobble, UndoScreenWobble)
void __cdecl UndoScreenWobble(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoScreenWobble == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk == NULL) {
            SetScreenWobble(0, 0);
        }
        else {
            ApplyScreenWobble(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_screen_shake);
    } else {
        original_UndoScreenWobble(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoGrooveStop = HOOK_ENABLED;
static void(__cdecl*original_UndoGrooveStop)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bb37;
CARM95_HOOK_FUNCTION(original_UndoGrooveStop, UndoGrooveStop)
void __cdecl UndoGrooveStop(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoGrooveStop == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplyGrooveStop(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_groove_stop);
    } else {
        original_UndoGrooveStop(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoNonCar = HOOK_ENABLED;
static void(__cdecl*original_UndoNonCar)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bb83;
CARM95_HOOK_FUNCTION(original_UndoNonCar, UndoNonCar)
void __cdecl UndoNonCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoNonCar == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplyNonCar(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_non_car);
    } else {
        original_UndoNonCar(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoSmoke = HOOK_ENABLED;
static void(__cdecl*original_UndoSmoke)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bbcf;
CARM95_HOOK_FUNCTION(original_UndoSmoke, UndoSmoke)
void __cdecl UndoSmoke(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoSmoke == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplySmoke(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_smoke);
    } else {
        original_UndoSmoke(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoSmokeColumn = HOOK_ENABLED;
static void(__cdecl*original_UndoSmokeColumn)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc1b;
CARM95_HOOK_FUNCTION(original_UndoSmokeColumn, UndoSmokeColumn)
void __cdecl UndoSmokeColumn(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoSmokeColumn == HOOK_ENABLED) {
        ApplySmokeColumn(pChunk);
    } else {
        original_UndoSmokeColumn(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoFlame = HOOK_ENABLED;
static void(__cdecl*original_UndoFlame)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc3b;
CARM95_HOOK_FUNCTION(original_UndoFlame, UndoFlame)
void __cdecl UndoFlame(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    if (function_hook_state_UndoFlame == HOOK_ENABLED) {
        ApplyFlame(pChunk);
    } else {
        original_UndoFlame(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoSplash = HOOK_ENABLED;
static void(__cdecl*original_UndoSplash)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc52;
CARM95_HOOK_FUNCTION(original_UndoSplash, UndoSplash)
void __cdecl UndoSplash(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoSplash == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk == NULL) {
            ((((*pChunk)->subject_index & 0xff00) == 0) ? &HV(gProgram_state).current_car :  GetCarSpec((*pChunk)->subject_index >> 8, (*pChunk)->subject_index & 0xff))->water_d = 10000.f;
        }
        else {
            ApplySplash(&temp_prev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_splash);
    } else {
        original_UndoSplash(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoOilSpill = HOOK_ENABLED;
static void(__cdecl*original_UndoOilSpill)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bd0b;
CARM95_HOOK_FUNCTION(original_UndoOilSpill, UndoOilSpill)
void __cdecl UndoOilSpill(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    if (function_hook_state_UndoOilSpill == HOOK_ENABLED) {
        temp_prev_chunk = pPrev_chunk;
        HV(gDisable_advance) = 1;
        if (pPrev_chunk != NULL) {
            ApplyOilSpill(&temp_prev_chunk, (*pChunk)->chunk_data.oil_data.previous_stop_time);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_oil_spill);
    } else {
        original_UndoOilSpill(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoProxRay = HOOK_ENABLED;
static void(__cdecl*original_UndoProxRay)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042bd60;
CARM95_HOOK_FUNCTION(original_UndoProxRay, UndoProxRay)
void __cdecl UndoProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    if (function_hook_state_UndoProxRay == HOOK_ENABLED) {
        ApplyProxRay(pChunk);
    } else {
        original_UndoProxRay(pChunk);
    }
}

function_hook_state_t function_hook_state_UndoSkidAdjustment = HOOK_ENABLED;
static void(__cdecl*original_UndoSkidAdjustment)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bd77;
CARM95_HOOK_FUNCTION(original_UndoSkidAdjustment, UndoSkidAdjustment)
void __cdecl UndoSkidAdjustment(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    if (function_hook_state_UndoSkidAdjustment == HOOK_ENABLED) {
        HV(gDisable_advance) = 1;
        if (pPrev_chunk == NULL) {
            HideSkid((*pChunk)->subject_index);
        }
        else {
            ApplySkidAdjustment(&pPrev_chunk);
        }
        HV(gDisable_advance) = 0;
        AdvanceChunkPtr(pChunk, ePipe_chunk_skid_adjustment);
    } else {
        original_UndoSkidAdjustment(pChunk, pPrev_chunk);
    }
}

function_hook_state_t function_hook_state_UndoPipedSession = HOOK_ENABLED;
static int(__cdecl*original_UndoPipedSession)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042b0a6;
CARM95_HOOK_FUNCTION(original_UndoPipedSession, UndoPipedSession)
int __cdecl UndoPipedSession(tU8 **pPtr) {
    tPipe_chunk *chunk_ptr;
    tPipe_chunk *prev_chunk;
    tU8 *temp_ptr;
    tU8 *pushed_end_of_session;
    int i;
    tPipe_chunk_type chunk_type;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)chunk_ptr;
    (void)prev_chunk;
    (void)temp_ptr;
    (void)pushed_end_of_session;
    (void)i;
    (void)chunk_type;

    if (function_hook_state_UndoPipedSession == HOOK_ENABLED) {
        if (MoveSessionPointerBackOne(pPtr)) {
            return 1;
        }
        HV(gEnd_of_session) = *pPtr + LengthOfSession((tPipe_session*)*pPtr) - sizeof(tU16);
        chunk_ptr = &((tPipe_session*)*pPtr)->chunks;
        chunk_type = ((tPipe_session*)*pPtr)->chunk_type;
        pushed_end_of_session = HV(gEnd_of_session);
        for (i = 0; i < ((tPipe_session*)*pPtr)->number_of_chunks; i++) {
            if (!(chunk_type == ePipe_chunk_model_geometry || chunk_type == ePipe_chunk_sound || chunk_type == ePipe_chunk_damage || chunk_type == ePipe_chunk_special || chunk_type == ePipe_chunk_incident || chunk_type == ePipe_chunk_prox_ray || chunk_type == ePipe_chunk_smudge)) {
                prev_chunk = FindPreviousChunk(*pPtr, ((tPipe_session*)*pPtr)->chunk_type, chunk_ptr->subject_index);
            }
            HV(gEnd_of_session) = pushed_end_of_session;
            switch ((int)chunk_type) {
                case ePipe_chunk_model_geometry:
                    UndoModelGeometry(&chunk_ptr);
                    break;
                case ePipe_chunk_pedestrian:
                    UndoPedestrian(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_frame_boundary:
                    UndoFrameBoundary(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_car:
                    UndoCar(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_sound:
                    UndoSound(&chunk_ptr);
                    break;
                case ePipe_chunk_damage:
                    UndoDamage(&chunk_ptr);
                    break;
                case ePipe_chunk_special:
                    UndoSpecial(&chunk_ptr);
                    break;
                case ePipe_chunk_ped_gib:
                    UndoPedGib(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_incident:
                    AdvanceChunkPtr(&chunk_ptr, ePipe_chunk_incident);
                    break;
                case ePipe_chunk_spark:
                    UndoSpark(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_shrapnel:
                    UndoShrapnel(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_screen_shake:
                    UndoScreenWobble(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_groove_stop:
                    UndoGrooveStop(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_non_car:
                    UndoNonCar(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_smoke:
                    UndoSmoke(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_oil_spill:
                    UndoOilSpill(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_smoke_column:
                    UndoSmokeColumn(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_flame:
                    UndoFlame(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_smudge:
                    UndoSmudge(&chunk_ptr);
                    break;
                case ePipe_chunk_splash:
                    UndoSplash(&chunk_ptr, prev_chunk);
                    break;
                case ePipe_chunk_prox_ray:
                    UndoProxRay(&chunk_ptr);
                    break;
                case ePipe_chunk_skid_adjustment:
                    UndoSkidAdjustment(&chunk_ptr, prev_chunk);
                    break;
                default:
                    break;
            }
        }
        temp_ptr = *pPtr;
        if (MoveSessionPointerBackOne(&temp_ptr)) {
            return 1;
        }
        return ((tPipe_session*)temp_ptr)->chunk_type == ePipe_chunk_frame_boundary;
    } else {
        return original_UndoPipedSession(pPtr);
    }
}

function_hook_state_t function_hook_state_FindPrevFrameTime = HOOK_ENABLED;
static tU32(__cdecl*original_FindPrevFrameTime)(tU8 *) = (tU32(__cdecl*)(tU8 *))0x0042bdd2;
CARM95_HOOK_FUNCTION(original_FindPrevFrameTime, FindPrevFrameTime)
tU32 __cdecl FindPrevFrameTime(tU8 *pPtr) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)temp_ptr;

    if (function_hook_state_FindPrevFrameTime == HOOK_ENABLED) {
        temp_ptr = pPtr;
        do {
            if (MoveSessionPointerBackOne(&temp_ptr)) {
                return 0;
            }
        } while (((tPipe_session*)temp_ptr)->chunk_type != ePipe_chunk_frame_boundary);
        return ((tPipe_session*)temp_ptr)->chunks.chunk_data.frame_boundary_data.time;
    } else {
        return original_FindPrevFrameTime(pPtr);
    }
}

function_hook_state_t function_hook_state_ScanBuffer = HOOK_ENABLED;
static void(__cdecl*original_ScanBuffer)(tU8 **, tPipe_chunk_type, tU32, int(*)(tPipe_chunk *, int, tU32), int(*)(tU32)) = (void(__cdecl*)(tU8 **, tPipe_chunk_type, tU32, int(*)(tPipe_chunk *, int, tU32), int(*)(tU32)))0x0042be18;
CARM95_HOOK_FUNCTION(original_ScanBuffer, ScanBuffer)
void __cdecl ScanBuffer(tU8 **pPtr, tPipe_chunk_type pType, tU32 pDefault_time, int(*pCall_back)(tPipe_chunk *, int, tU32), int(*pTime_check)(tU32)) {
    tPipe_chunk *chunk_ptr;
    tU32 the_time;
    LOG_TRACE("(%p, %d, %u, %p, %p)", pPtr, pType, pDefault_time, pCall_back, pTime_check);

    (void)pPtr;
    (void)pType;
    (void)pDefault_time;
    (void)pCall_back;
    (void)pTime_check;
    (void)chunk_ptr;
    (void)the_time;

    if (function_hook_state_ScanBuffer == HOOK_ENABLED) {
    the_time = pDefault_time;
        while (1) {
            if (PipeSearchForwards() ? MoveSessionPointerForwardOne(pPtr) : MoveSessionPointerBackOne(pPtr)) {
                return;
            }
            HV(gEnd_of_session) = *pPtr + LengthOfSession((tPipe_session*)*pPtr) - sizeof(tU16);
            if (((tPipe_session*)*pPtr)->chunk_type == ePipe_chunk_frame_boundary) {
                the_time = ((tPipe_session*)*pPtr)->chunks.chunk_data.frame_boundary_data.time;
            } else if (((tPipe_session*)*pPtr)->chunk_type == pType) {
                if (pCall_back(&((tPipe_session*)*pPtr)->chunks, ((tPipe_session*)*pPtr)->number_of_chunks, the_time)) {
                    return;
                }
            }
            if (pTime_check != NULL) {
                if (!pTime_check(the_time)) {
                    return;
                }
            }
        }
    } else {
        original_ScanBuffer(pPtr, pType, pDefault_time, pCall_back, pTime_check);
    }
}

function_hook_state_t function_hook_state_CheckSound = HOOK_UNAVAILABLE;
static int(__cdecl*original_CheckSound)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c00a;
CARM95_HOOK_FUNCTION(original_CheckSound, CheckSound)
int __cdecl CheckSound(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    int i;
    int sound_length;
    tPipe_chunk *temp_ptr;
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;
    (void)i;
    (void)sound_length;
    (void)temp_ptr;

    if (function_hook_state_CheckSound == HOOK_ENABLED) {
        assert(0 && "CheckSound not implemented.");
        abort();
    } else {
        return original_CheckSound(pChunk_ptr, pChunk_count, pTime);
    }
}

function_hook_state_t function_hook_state_SoundTimeout = HOOK_UNAVAILABLE;
static int(__cdecl*original_SoundTimeout)(tU32) = (int(__cdecl*)(tU32))0x0042c132;
CARM95_HOOK_FUNCTION(original_SoundTimeout, SoundTimeout)
int __cdecl SoundTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    if (function_hook_state_SoundTimeout == HOOK_ENABLED) {
        assert(0 && "SoundTimeout not implemented.");
        abort();
    } else {
        return original_SoundTimeout(pTime);
    }
}

function_hook_state_t function_hook_state_ScanAndPlaySoundsToBe = HOOK_UNAVAILABLE;
static void(__cdecl*original_ScanAndPlaySoundsToBe)(tU8 *, tU32, tU32) = (void(__cdecl*)(tU8 *, tU32, tU32))0x0042c06e;
CARM95_HOOK_FUNCTION(original_ScanAndPlaySoundsToBe, ScanAndPlaySoundsToBe)
void __cdecl ScanAndPlaySoundsToBe(tU8 *pPtr, tU32 pOldest_time, tU32 pYoungest_time) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p, %u, %u)", pPtr, pOldest_time, pYoungest_time);

    (void)pPtr;
    (void)pOldest_time;
    (void)pYoungest_time;
    (void)temp_ptr;

    if (function_hook_state_ScanAndPlaySoundsToBe == HOOK_ENABLED) {
        assert(0 && "ScanAndPlaySoundsToBe not implemented.");
        abort();
    } else {
        original_ScanAndPlaySoundsToBe(pPtr, pOldest_time, pYoungest_time);
    }
}

function_hook_state_t function_hook_state_CheckCar = HOOK_ENABLED;
static int(__cdecl*original_CheckCar)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c327;
CARM95_HOOK_FUNCTION(original_CheckCar, CheckCar)
int __cdecl CheckCar(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    int i;
    tCar_spec *car;
    br_vector3 com_offset_c;
    br_vector3 com_offset_w;
    br_vector3 difference;
    tPipe_chunk *temp_ptr;
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;
    (void)i;
    (void)car;
    (void)com_offset_c;
    (void)com_offset_w;
    (void)difference;
    (void)temp_ptr;

    if (function_hook_state_CheckCar == HOOK_ENABLED) {
        temp_ptr = pChunk_ptr;
        if (PipeSearchForwards()) {
            if (pTime <= HV(gOldest_time)) {
                return 0;
            }
        } else {
            if (pTime >= HV(gOldest_time)) {
                return 0;
            }
        }
        for (i = 0; i < pChunk_count; i++) {
            if ((temp_ptr->subject_index & 0xff00) == 0) {
                car = &HV(gProgram_state).current_car;
            } else {
                car = GetCarSpec(temp_ptr->subject_index >> 8, temp_ptr->subject_index & 0xff);
            }
            if (car == HV(gCar_ptr)) {
                BrVector3Copy(&HV(gCar_pos), (br_vector3*)temp_ptr->chunk_data.car_data.transformation.m[3]);
                BrVector3InvScale(&com_offset_c, &car->cmpos, WORLD_SCALE);
                BrMatrix34ApplyV(&com_offset_w, &com_offset_c, &temp_ptr->chunk_data.car_data.transformation);
                BrVector3Accumulate(&HV(gCar_pos), &com_offset_w);
                BrVector3Sub(&difference, &HV(gCar_pos), &HV(gReference_pos));
                if (BrVector3LengthSquared(&difference) <= HV(gMax_distance)) {
                    HV(gTrigger_time) = pTime;
                    return 0;
                } else {
                    HV(gTrigger_time) = pTime;
                    return 1;
                }
            }
            AdvanceChunkPtr(&temp_ptr, ePipe_chunk_car);
        }
        return 0;
    } else {
        return original_CheckCar(pChunk_ptr, pChunk_count, pTime);
    }
}

function_hook_state_t function_hook_state_CarTimeout = HOOK_ENABLED;
static int(__cdecl*original_CarTimeout)(tU32) = (int(__cdecl*)(tU32))0x0042c5b2;
CARM95_HOOK_FUNCTION(original_CarTimeout, CarTimeout)
int __cdecl CarTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    if (function_hook_state_CarTimeout == HOOK_ENABLED) {
        if (PipeSearchForwards()) {
            if (pTime > HV(gYoungest_time)) {
                return 0;
            }
        } else {
            if (pTime < HV(gYoungest_time)) {
                return 0;
            }
        }
        return 1;
    } else {
        return original_CarTimeout(pTime);
    }
}

function_hook_state_t function_hook_state_ScanCarsPositions = HOOK_ENABLED;
static void(__cdecl*original_ScanCarsPositions)(tCar_spec *, br_vector3 *, br_scalar, tU32, tU32, br_vector3 *, tU32 *) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_scalar, tU32, tU32, br_vector3 *, tU32 *))0x0042c171;
CARM95_HOOK_FUNCTION(original_ScanCarsPositions, ScanCarsPositions)
void __cdecl ScanCarsPositions(tCar_spec *pCar, br_vector3 *pSource_pos, br_scalar pMax_distance_sqr, tU32 pOffset_time, tU32 pTime_period, br_vector3 *pCar_pos, tU32 *pTime_returned) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p, %p, %f, %u, %u, %p, %p)", pCar, pSource_pos, pMax_distance_sqr, pOffset_time, pTime_period, pCar_pos, pTime_returned);

    (void)pCar;
    (void)pSource_pos;
    (void)pMax_distance_sqr;
    (void)pOffset_time;
    (void)pTime_period;
    (void)pCar_pos;
    (void)pTime_returned;
    (void)temp_ptr;

    if (function_hook_state_ScanCarsPositions == HOOK_ENABLED) {
        temp_ptr = HV(gPipe_play_ptr);
        HV(gTrigger_time) = 0;
        HV(gMax_distance) = pMax_distance_sqr;
        BrVector3Copy(&HV(gReference_pos), pSource_pos);
        HV(gCar_ptr) = pCar;

        if (PipeSearchForwards()) {
            HV(gOldest_time) = GetTotalTime() + pOffset_time;
            HV(gYoungest_time) = HV(gOldest_time) + pTime_period;
        } else {
            HV(gOldest_time) = GetTotalTime() - pOffset_time;
            HV(gYoungest_time) = HV(gOldest_time) - pTime_period;
        }

        ScanBuffer(&temp_ptr, ePipe_chunk_car, GetTotalTime(), CheckCar, CarTimeout);
        BrVector3Copy(pCar_pos, &HV(gCar_pos));
        if (pCar_pos->v[0] > 500.f) {
            Vector3AddFloats(pCar_pos, pCar_pos, -1000.f, -1000.f, -1000.f);
        }
        *pTime_returned = HV(gTrigger_time);
    } else {
        original_ScanCarsPositions(pCar, pSource_pos, pMax_distance_sqr, pOffset_time, pTime_period, pCar_pos, pTime_returned);
    }
}

function_hook_state_t function_hook_state_CheckIncident = HOOK_ENABLED;
static int(__cdecl*original_CheckIncident)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c90d;
CARM95_HOOK_FUNCTION(original_CheckIncident, CheckIncident)
int __cdecl CheckIncident(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;

    if (function_hook_state_CheckIncident == HOOK_ENABLED) {
        if (PipeSearchForwards()) {
            if (pTime <= HV(gOldest_time)) {
                return 0;
            }
        } else {
            if (pTime >= HV(gOldest_time)) {
                return 0;
            }
        }
        HV(gIncidentChunk) = pChunk_ptr;
        HV(gTrigger_time) = pTime;
        return 1;
    } else {
        return original_CheckIncident(pChunk_ptr, pChunk_count, pTime);
    }
}

function_hook_state_t function_hook_state_GetNextIncident = HOOK_ENABLED;
static int(__cdecl*original_GetNextIncident)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *) = (int(__cdecl*)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *))0x0042c6a3;
CARM95_HOOK_FUNCTION(original_GetNextIncident, GetNextIncident)
int __cdecl GetNextIncident(tU32 pOffset_time, tIncident_type *pIncident_type, float *pSeverity, tIncident_info *pInfo, tU32 *pTime_away) {
    tU8 *temp_ptr;
    LOG_TRACE("(%u, %p, %p, %p, %p)", pOffset_time, pIncident_type, pSeverity, pInfo, pTime_away);

    (void)pOffset_time;
    (void)pIncident_type;
    (void)pSeverity;
    (void)pInfo;
    (void)pTime_away;
    (void)temp_ptr;

    if (function_hook_state_GetNextIncident == HOOK_ENABLED) {
        temp_ptr = HV(gPipe_play_ptr);
        HV(gTrigger_time) = 0;
        if (PipeSearchForwards()) {
            HV(gOldest_time) = GetTotalTime() + pOffset_time;
        } else {
            HV(gOldest_time) = GetTotalTime() - pOffset_time;
        }
        ScanBuffer(&temp_ptr, ePipe_chunk_incident, GetTotalTime(), CheckIncident, NULL);
        if (HV(gTrigger_time) != 0) {
            *pTime_away = HV(gTrigger_time) - GetTotalTime();
            *pIncident_type = HV(gIncidentChunk)->subject_index;
            *pSeverity = HV(gIncidentChunk)->chunk_data.incident_data.severity;
            if (*pIncident_type == eIncident_ped) {
                pInfo->ped_info.ped_actor = GetPedestrianActor(HV(gIncidentChunk)->chunk_data.incident_data.info.ped_info.ped_index);
                pInfo->ped_info.murderer_actor = HV(gIncidentChunk)->chunk_data.incident_data.info.ped_info.actor;
            } else if (*pIncident_type == eIncident_car) {
                if ((HV(gIncidentChunk)->chunk_data.incident_data.info.car_info.car_ID & 0xff00) == 0) {
                    pInfo->car_info.car = &HV(gProgram_state).current_car;
                } else {
                    pInfo->car_info.car = GetCarSpec(HV(gIncidentChunk)->chunk_data.incident_data.info.car_info.car_ID >> 8,
                                                     HV(gIncidentChunk)->chunk_data.incident_data.info.car_info.car_ID & 0xff);
                }
                BrVector3Copy(&pInfo->car_info.impact_point, &HV(gIncidentChunk)->chunk_data.incident_data.info.car_info.impact_point);
            } else if (*pIncident_type == eIncident_wall) {
                BrVector3Copy(&pInfo->wall_info.pos, &HV(gIncidentChunk)->chunk_data.incident_data.info.wall_info.pos);
            }
        }
        return HV(gTrigger_time);
    } else {
        return original_GetNextIncident(pOffset_time, pIncident_type, pSeverity, pInfo, pTime_away);
    }
}

function_hook_state_t function_hook_state_GetARStartTime = HOOK_ENABLED;
static tU32(__cdecl*original_GetARStartTime)() = (tU32(__cdecl*)())0x0042ca0e;
CARM95_HOOK_FUNCTION(original_GetARStartTime, GetARStartTime)
tU32 __cdecl GetARStartTime() {
    tU8 *temp_ptr;
    LOG_TRACE("()");

    (void)temp_ptr;

    if (function_hook_state_GetARStartTime == HOOK_ENABLED) {
        temp_ptr = HV(gPipe_buffer_oldest);
        do {
            if (MoveSessionPointerForwardOne(&temp_ptr)) {
                return 0;
            }
        } while (((tPipe_session*)temp_ptr)->chunk_type != ePipe_chunk_frame_boundary);
        return ((tPipe_session*)temp_ptr)->chunks.chunk_data.frame_boundary_data.time;
    } else {
        return original_GetARStartTime();
    }
}

