#include <windows.h>
#include <detours.h>

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include "br_types.h"
#include "dr_types.h"
#include "br_inlines.h"
#include "constants.h"
#include "macros.h"
#include "hooks.h"
#include "declarations.h"
#include "br_declarations.h"

class StaticPatcher
{
private:
    using Patcher = void(*)();

    Patcher m_func;
    StaticPatcher   *m_next;
    static StaticPatcher    *ms_head;

    void Run() { m_func(); }
public:
    StaticPatcher(Patcher func);
    static void Apply();
};

StaticPatcher* StaticPatcher::ms_head;

StaticPatcher::StaticPatcher(Patcher func)
        : m_func(func)
{
    m_next = ms_head;
    ms_head = this;
}

void
StaticPatcher::Apply()
{
    StaticPatcher *current = ms_head;
    while(current){
        current->Run();
        current = current->m_next;
    }
    ms_head = nullptr;
}

#define STARTPATCHES_INNER2(VAL) static StaticPatcher Patcher##VAL([](){
#define STARTPATCHES_INNER(VAL) STARTPATCHES_INNER2(VAL)
#define STARTPATCHES STARTPATCHES_INNER(__COUNTER__)
#define ENDPATCHES });


enum class Carm95Type {
    CARM95_UNKNOWN,
    CARM95_C1,
    CARM95_SPLATPACK,
};

//__COUNTER__

static Carm95Type DetectCarm95Type() {
    if (*(uint32_t*)0x004b2600 == 0x8b575653) {
        return Carm95Type::CARM95_SPLATPACK;
    }
    if (*(uint32_t*)0x004985ec == 0xfdf4858b) {
        return Carm95Type::CARM95_C1;
    }
    return Carm95Type::CARM95_UNKNOWN;
}



BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
    if (DetourIsHelperProcess()) {
        return TRUE;
    }

    if (dwReason == DLL_PROCESS_ATTACH) {
        BOOL bSuccess = AllocConsole();
        SetConsoleTitle(TEXT("CARM95 Console"));
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);

        DetourRestoreAfterWith();

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        switch (DetectCarm95Type()) {
        case Carm95Type::CARM95_SPLATPACK:
            printf("Detected Carmageddon Splat Pack CARM95.EXE executable\n");
            break;
        case Carm95Type::CARM95_C1:
            printf("Detected Carmageddon1 CARM95.EXE executable\n");
            break;
        case Carm95Type::CARM95_UNKNOWN:
            printf("UNKNOWN executable\n");
            break;
        }
        StaticPatcher::Apply();

        DetourTransactionCommit();
    }
    else if (dwReason == DLL_PROCESS_DETACH) {
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        DetourTransactionCommit();
    }
    return TRUE;
}


static tFollowCheatyPath followCheatyPathOriginal;

static tOpponent_spec original_opp;
static tCar_spec original_car;

static tOpponent_spec original_opp2;
static tCar_spec original_car2;



void SetInitialPosition_hook(tRace_info* pThe_race, int pCar_index, int pGrid_index) {
    int place_on_grid;
    int i;
    int start_i;
    int j;
    br_actor* car_actor;
    br_angle initial_yaw = 0;
    br_scalar nearest_y_above;
    br_scalar nearest_y_below;
    br_scalar speed;
    int below_face_index;
    int above_face_index;
    br_model* below_model;
    br_model* above_model;
    tCar_spec* car;
    br_vector3 grid_offset;
    br_vector3 dist;
    br_vector3 real_pos;
    br_matrix34 initial_yaw_matrix;
    br_bounds bnds;

    car_actor = pThe_race->opponent_list[pCar_index].car_spec->car_master_actor;
    car = pThe_race->opponent_list[pCar_index].car_spec;
    BrMatrix34Identity(&car_actor->t.t.mat);
    place_on_grid = 1;
    
    if (place_on_grid) {
        initial_yaw = (pThe_race->initial_yaw * 182.0444444444445);
        BrMatrix34RotateY(&initial_yaw_matrix, initial_yaw);
        grid_offset.v[0] = 0.0 - pGrid_index % 2;
        grid_offset.v[1] = 0.0;
        grid_offset.v[2] = (double)(pGrid_index / 2) * 2.0 + (double)(pGrid_index % 2) * 0.40000001;
        BrMatrix34ApplyV(&car_actor->t.t.translate.t, &grid_offset, &initial_yaw_matrix);
        BrVector3Accumulate(&car_actor->t.t.translate.t, &pThe_race->initial_position);
    }
    FindBestY(
        &car_actor->t.t.translate.t,
        HOOK_VARIABLE(gTrack_actor),
        10.0,
        &nearest_y_above,
        &nearest_y_below,
        &above_model,
        &below_model,
        &above_face_index,
        &below_face_index);
    if (nearest_y_above == 30000.0) {
        if (nearest_y_below == -30000.0) {
            car_actor->t.t.translate.t.v[1] = 0.0;
        }
        else {
            car_actor->t.t.translate.t.v[1] = nearest_y_below;
        }
    }
    else {
        car_actor->t.t.translate.t.v[1] = nearest_y_above;
    }
    BrMatrix34PreRotateY(&car_actor->t.t.mat, initial_yaw);
    
    
    if (strcmp(car->name, "NEWEAGLE.TXT") != 0) {
        car_actor->t.t.translate.t.v[1] += 2;
        car_actor->t.t.look_up.up.v[1] = -1;
    }
}

static void dr_dprintf_hook(const char* fmt, ...) {
    va_list ap;

    if (strcmp(fmt, "ACTIVE but couldn't get keyboard device state on 1st attempt") == 0
        || strcmp(fmt, "Keyboard input lost; reacquiring...") == 0
        || strcmp(fmt, "Couldn't get keyboard device state on 2nd attempt") == 0
        || strcmp(fmt, "Zeroing pKeys") == 0
        || strcmp(fmt, "Keyboard reacquired OK.") == 0) {
        // Avoid noisy prints when Carmageddon loses focus
        return;
    }

    printf("dr_dprintf: ");
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    printf("\n");
}

int DoCrashEarnings_hook(tCar_spec* pCar1, tCar_spec* pCar2) {
    tCar_spec* culprit;
    tCar_spec* victim;
    int i;
    int net_loop;
    int head_on;
    int bonus_level;
    int credits;
    int impact_in_moving_direction_1;
    int impact_in_moving_direction_2;
    int car_off_ground_1;
    int car_off_ground_2;
    int total_units_of_damage;
    int inherited_damage;
    int dam_acc_1;
    int dam_acc_2;
    int car_1_culpable;
    int car_2_culpable;
    int mutual_culpability;
    tU32 the_time;
    tU32 time;
    float credits_squared;
    static tU32 last_earn_time;
    char s[256];
    tImpact_location modified_location_1;
    tImpact_location modified_location_2;
    tImpact_location car_direction_1;
    tImpact_location car_direction_2;
    br_scalar car_1_height;
    br_scalar car_2_height;
    br_scalar dp;
    br_vector3 car_1_pos;
    br_vector3 car_2_pos;
    br_vector3 car_1_offset;
    br_vector3 car_2_offset;
    tNet_message* message;

    culprit = 0;
    victim = 0;
    head_on = 0;
    bonus_level = 1;
    car_1_culpable = 0;
    car_2_culpable = 0;
    mutual_culpability = 0;
    the_time = PDGetTotalTime();
    inherited_damage = 0;
    if (pCar1->driver <= eDriver_non_car) {
        dam_acc_1 = 0;
    }
    else {
        dam_acc_1 = pCar1->damage_magnitude_accumulator;
    }
    // dam_acc_2 = pCar2
    //     && (pCar2->driver <= eDriver_non_car ? (v21 = 0.0) : (v21 = pCar2->damage_magnitude_accumulator), v21 != 0.0);

    dam_acc_2 = 0;
    if (pCar2) {
        if (pCar1->driver <= eDriver_non_car) {
            dam_acc_2 = 0;
        }
        else {
            dam_acc_2 = pCar2->damage_magnitude_accumulator != 0;
        }
    }

    if (pCar1->driver <= eDriver_non_car) {
        if (pCar2 == NULL || pCar2->driver <= eDriver_non_car) {
            return 0;
        }
        pCar1 = pCar2;
        pCar2 = NULL;
    }
    if (pCar2 != NULL && pCar2->driver <= eDriver_non_car) {
        pCar2 = NULL;
    }

    if (pCar1->pre_car_col_knackered || (pCar2 && pCar2->pre_car_col_knackered) || (pCar2 && pCar2->damage_magnitude_accumulator <= 0.00005f && pCar1->damage_magnitude_accumulator <= 0.00005f)) {
        return dam_acc_1 || (pCar2 && dam_acc_2);
    }
    // if (!pCar1->pre_car_col_knackered
    //     && (pCar2 == NULL || !pCar2->pre_car_col_knackered)
    //     && (pCar2 == NULL || pCar2->damage_magnitude_accumulator > 0.00005f || pCar1->damage_magnitude_accumulator > 0.00005f)) {

    modified_location_1 = CalcModifiedLocation(pCar1);
    car_direction_1 = GetDirection(&pCar1->pre_car_col_velocity_car_space);
    impact_in_moving_direction_1 = car_direction_1 == modified_location_1;
    if (pCar2 != NULL) {
        modified_location_2 = CalcModifiedLocation(pCar2);
        car_direction_2 = GetDirection(&pCar2->pre_car_col_velocity_car_space);
        impact_in_moving_direction_2 = car_direction_2 == modified_location_2;
    }
    if (pCar1->driver >= eDriver_net_human && pCar2) {
        if (impact_in_moving_direction_1 && (pCar1->driver < eDriver_net_human || (pCar1->pre_car_col_velocity_car_space.v[2] != 0.0 && pCar1->pre_car_col_velocity_car_space.v[2] > 0.0 != pCar1->gear > 0 && (pCar1->keys.acc != 0 || pCar1->joystick.acc > 0x8000)))) {
            pCar2->time_last_hit = the_time;
            pCar2->last_hit_by = pCar1;
        }
    }
    else if (pCar2 && pCar2->driver >= eDriver_net_human && impact_in_moving_direction_2 && (pCar2->driver < eDriver_net_human || (pCar2->pre_car_col_velocity_car_space.v[2] != 0.0f && pCar2->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar2->gear > 0 && (pCar2->keys.acc != 0 || pCar2->joystick.acc > 0x8000)))) {
        pCar1->time_last_hit = the_time;
        pCar1->last_hit_by = pCar2;
    }
    if (pCar2) {
        if (impact_in_moving_direction_1
            && pCar1->pre_car_col_speed * 5.0f > pCar2->pre_car_col_speed
            && pCar1->pre_car_col_speed > 0.0005f
            && (pCar1->driver < eDriver_net_human
                || (pCar1->pre_car_col_velocity_car_space.v[2] != 0.0f
                    && pCar1->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar1->gear > 0
                    && (pCar1->keys.acc != 0 || pCar1->joystick.acc > 0x8000)))) {
            car_1_culpable = 1;
        }
        if (impact_in_moving_direction_2
            && pCar2->pre_car_col_speed * 5.0f > pCar1->pre_car_col_speed
            && pCar2->pre_car_col_speed > 0.0005f
            && (pCar2->driver < eDriver_net_human
                || (pCar2->pre_car_col_velocity_car_space.v[2] != 0.0f
                    && pCar2->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar2->gear > 0
                    && (pCar2->keys.acc != 0 || pCar2->joystick.acc > 0x8000)))) {
            car_2_culpable = 1;
        }
        if (HOOK_VARIABLE(gNet_mode) && car_1_culpable && car_2_culpable) {
            mutual_culpability = 1;
        }
        else {
            if (car_2_culpable && pCar2->driver == eDriver_local_human) {
                car_1_culpable = 0;
            }
            if (car_1_culpable) {
                culprit = pCar1;
                victim = pCar2;
                dp = BrVector3Dot(&pCar1->pre_car_col_direction, &pCar1->pre_car_col_direction); /* pCar1->pre_car_col_direction.v[2] * pCar2->pre_car_col_direction.v[2]
                     + pCar2->pre_car_col_direction.v[1] * pCar1->pre_car_col_direction.v[1]
                     + pCar2->pre_car_col_direction.v[0] * pCar1->pre_car_col_direction.v[0];*/
                if (modified_location_1 == eImpact_front && modified_location_2 == eImpact_front && pCar1->pre_car_col_speed > 0.001f && pCar2->pre_car_col_speed > 0.001f && dp < -0.7f) {
                    head_on = 1;
                    bonus_level = 2;
                }
                else {
                    bonus_level = 1;
                }
            }
            else if (car_2_culpable) {
                culprit = pCar2;
                victim = pCar1;
                // dp = pCar1->pre_car_col_direction.v[2] * pCar2->pre_car_col_direction.v[2]
                //     + pCar2->pre_car_col_direction.v[1] * pCar1->pre_car_col_direction.v[1]
                //     + pCar2->pre_car_col_direction.v[0] * pCar1->pre_car_col_direction.v[0];
                dp = BrVector3Dot(&pCar1->pre_car_col_direction, &pCar1->pre_car_col_direction);
                if (modified_location_1 == eImpact_front && modified_location_2 == eImpact_front && pCar1->pre_car_col_speed > 0.001f && pCar2->pre_car_col_speed > 0.001f && dp < -0.7f) {
                    head_on = 1;
                    bonus_level = 2;
                }
                else {
                    bonus_level = 1;
                }
            }
        }
    }
    else {
        // LOG_DEBUG("no pCar2, timediff is %d", the_time - pCar1->time_last_hit);
        if (the_time - pCar1->time_last_hit >= 3000) {
            return 1;
        }
        culprit = pCar1->last_hit_by;
        victim = pCar1;
        bonus_level = 1;
        inherited_damage = 1;
    }
    if (!mutual_culpability && (!victim || culprit->driver < eDriver_net_human)) {
        if (pCar2 && pCar2->last_culprit == pCar1 && the_time - pCar2->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar1;
            victim = pCar2;
        }
        else if (pCar2 && pCar1->last_culprit == pCar2 && the_time - pCar1->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar2;
            victim = pCar1;
        }
        else if (!pCar2 && the_time - pCar1->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar1->last_culprit;
            victim = pCar1;
        }
    }
    if (culprit && victim) {
        RecordOpponentTwattageOccurrence(culprit, victim);
        total_units_of_damage = 0;
        for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
            if (victim->damage_units[i].damage_level > victim->damage_units[i].last_level) {
                victim->damage_units[i].damage_level = (victim->damage_units[i].damage_level - victim->damage_units[i].last_level) * 2.0f + victim->damage_units[i].last_level;
                if (victim->damage_units[i].damage_level >= 99) {
                    victim->damage_units[i].damage_level = 99;
                }
                total_units_of_damage += victim->damage_units[i].damage_level - victim->damage_units[i].last_level;
            }
            if (culprit->damage_units[i].damage_level > culprit->damage_units[i].last_level) {
                culprit->damage_units[i].damage_level = (culprit->damage_units[i].damage_level - culprit->damage_units[i].last_level) * 0.1f + (double)culprit->damage_units[i].last_level;
                if (culprit->damage_units[i].damage_level < 0) {
                    culprit->damage_units[i].damage_level = 0;
                }
            }
        }
    }
    // TODO: tidy this up
    for (net_loop = 0; 2 - (mutual_culpability == 0) > net_loop; net_loop++) {
        if (mutual_culpability) {
            if (net_loop) {
                culprit = pCar1;
                victim = pCar2;
            }
            else {
                culprit = pCar2;
                victim = pCar1;
            }
            total_units_of_damage = 0;
            for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
                if (victim->damage_units[i].damage_level > victim->damage_units[i].last_level) {
                    total_units_of_damage += victim->damage_units[i].damage_level - victim->damage_units[i].last_level;
                }
            }
        }
        if (culprit && (culprit->driver == eDriver_local_human || HOOK_VARIABLE(gNet_mode)) && victim) {
            SetKnackeredFlag(victim);
            if (victim->knackered && !victim->pre_car_col_knackered) {
                victim->pre_car_col_knackered = 1;
                credits_squared = sqr(0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor) * HOOK_VARIABLE(gWasted_creds)[HOOK_VARIABLE(gProgram_state).skill_level] + 50.0f;
                credits = 100 * (credits_squared / 100.0f);
                if (HOOK_VARIABLE(gNet_mode)) {
                    message = NetBuildMessage(0x18u, 0);
                    message->contents.data.wasted.victim = NetPlayerFromCar(victim)->ID;
                    if (NetPlayerFromCar(culprit)) {
                        message->contents.data.wasted.culprit = NetPlayerFromCar(culprit)->ID;
                    }
                    else {
                        message->contents.data.wasted.culprit = -2;
                    }
                    //NetGuaranteedSendMessageToEverybody(gCurrent_net_game, message, NULL);
                    NetEarnCredits(NetPlayerFromCar(culprit), credits);
                }
                else {
                    PratcamEvent(32);
                    DoFancyHeadup(11);
                    credits_squared = sqr(0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor) * HOOK_VARIABLE(gWasted_creds)[HOOK_VARIABLE(gProgram_state).skill_level] + 50.0f;
                    credits = 100 * (credits_squared / 100.0);
                    AwardTime(HOOK_VARIABLE(gWasted_time)[HOOK_VARIABLE(gProgram_state).skill_level]);
                    EarnCredits(credits);
                    if (victim->can_be_stolen && !HOOK_VARIABLE(gOpponents)[victim->index].dead && ((PercentageChance(50) && HOOK_VARIABLE(gSteal_ranks)[HOOK_VARIABLE(gOpponents)[victim->index].strength_rating] >= HOOK_VARIABLE(gProgram_state).rank) || victim->index == 4)) {
                        StealCar(victim);
                    }
                }
            }
            victim->time_last_hit = the_time;
            victim->last_hit_by = culprit;
            if (!inherited_damage) {
                victim->time_last_victim = the_time;
                victim->last_culprit = culprit;
            }
            if (victim && (fabs(victim->omega.v[0]) > 4.0f || fabs(victim->omega.v[1]) > 6.0f || fabs(victim->omega.v[2]) > 4.0f)) {
                bonus_level *= 2;
            }
            if (pCar1->number_of_wheels_on_ground) {
                car_off_ground_1 = 0;
            }
            else {
                // car_1_pos.v[0] = pCar1->car_master_actor->t.t.mat.m[3][0] / 6.9000001;
                // car_1_pos.v[1] = pCar1->car_master_actor->t.t.mat.m[3][1] / 6.9000001;
                // car_1_pos.v[2] = pCar1->car_master_actor->t.t.mat.m[3][2] / 6.9000001;
                BrVector3InvScale(&car_1_pos, &pCar1->car_master_actor->t.t.translate.t, WORLD_SCALE);
                BrMatrix34ApplyV(&car_1_offset, &pCar1->car_model_actors[pCar1->principal_car_actor].actor->t.t.translate.t, &pCar1->car_master_actor->t.t.mat);
                // car_1_pos.v[0] = car_1_offset.v[0] + car_1_pos.v[0];
                // car_1_pos.v[1] = car_1_offset.v[1] + car_1_pos.v[1];
                // car_1_pos.v[2] = car_1_offset.v[2] + car_1_pos.v[2];
                BrVector3Accumulate(&car_1_pos, &car_1_offset);
                car_1_pos.v[1] += 0.15f;
                car_1_height = FindYVerticallyBelow2(&car_1_pos);
                car_off_ground_1 = car_1_height > -100.0f
                    && pCar1->car_model_actors[pCar1->principal_car_actor].actor->t.t.translate.t.v[1] * 4.0f <= car_1_pos.v[1] - car_1_height - 0.15f;
            }
            if (!pCar2 || pCar2->number_of_wheels_on_ground) {
                car_off_ground_2 = 0;
            }
            else {
                // car_2_pos.v[0] = pCar2->car_master_actor->t.t.mat.m[3][0] / 6.9000001;
                // car_2_pos.v[1] = pCar2->car_master_actor->t.t.mat.m[3][1] / 6.9000001;
                // car_2_pos.v[2] = pCar2->car_master_actor->t.t.mat.m[3][2] / 6.9000001;
                BrVector3InvScale(&car_2_pos, &pCar2->car_master_actor->t.t.translate.t, WORLD_SCALE);
                BrMatrix34ApplyV(&car_2_offset, &pCar2->car_model_actors[pCar2->principal_car_actor].actor->t.t.translate.t, &pCar2->car_master_actor->t.t.mat);
                // car_2_pos.v[0] = car_2_offset.v[0] + car_2_pos.v[0];
                // car_2_pos.v[1] = car_2_offset.v[1] + car_2_pos.v[1];
                // car_2_pos.v[2] = car_2_pos.v[2] + car_2_offset.v[2];
                BrVector3Accumulate(&car_2_pos, &car_2_offset);
                car_2_pos.v[1] += 0.15f;
                car_2_height = FindYVerticallyBelow2(&car_2_pos);
                car_off_ground_2 = car_2_height > -100.0f
                    && pCar2->car_model_actors[pCar2->principal_car_actor].actor->t.t.translate.t.v[1] * 4.0f <= car_2_pos.v[1] - car_2_height - 0.15f;
            }
            if (car_off_ground_1) {
                bonus_level *= 2;
            }
            if (car_off_ground_2) {
                bonus_level *= 2;
            }
            total_units_of_damage = 0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor * total_units_of_damage;
            if (!victim->has_been_stolen) {
                credits = 100 * (HOOK_VARIABLE(gCar_cred_value)[HOOK_VARIABLE(gProgram_state).skill_level] * MIN(bonus_level, 8) * total_units_of_damage + 50.0f) / 100.0f;
                if (credits || victim->knackered) {
                    if (!victim->knackered) {
                        if (HOOK_VARIABLE(gNet_mode)) {
                            NetEarnCredits(NetPlayerFromCar(culprit), MIN(credits, 2000));
                        }
                        else {
                            EarnCredits(MIN(credits, 2000));
                        }
                        last_earn_time = the_time;
                        if (HOOK_VARIABLE(gNet_mode) == eNet_mode_none) {
                            time = 5 * ((total_units_of_damage * HOOK_VARIABLE(gCar_time_value)[HOOK_VARIABLE(gProgram_state).skill_level] + 2.5f) / 5.0f);
                            AwardTime(MIN(time, 90));
                            if (pCar2) {
                                if (head_on) {
                                    DoFancyHeadup(10);
                                }
                                else if (bonus_level <= 2) {
                                    if (bonus_level > 1) {
                                        DoFancyHeadup(2);
                                    }
                                }
                                else {
                                    DoFancyHeadup(3);
                                }
                            }
                        }
                    }
                    for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
                        victim->damage_units[i].last_level = victim->damage_units[i].damage_level;
                    }
                }
            }
        }
        else {
            pCar1->time_last_hit = 0;
            if (pCar2) {
                pCar2->time_last_hit = 0;
            }
        }
    }
    pCar1->damage_magnitude_accumulator = 0.0f;
    if (pCar2) {
        pCar2->damage_magnitude_accumulator = 0.0f;
    }
    return 1;

    // return dam_acc_1 || pCar2 && dam_acc_2;
}

STARTPATCHES
    
DetourAttach((PVOID*)&SetInitialPosition, SetInitialPosition_hook);
DetourAttach((PVOID*)&dr_dprintf, dr_dprintf_hook);
DetourAttach((PVOID*)&DoCrashEarnings, DoCrashEarnings_hook);
    
ENDPATCHES

