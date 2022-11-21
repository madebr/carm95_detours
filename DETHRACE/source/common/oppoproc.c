#include "oppoproc.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_StraightestArcForCorner2D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(StraightestArcForCorner2D, function_hook_state_StraightestArcForCorner2D)
int StraightestArcForCorner2D(br_vector2 *pCent, br_scalar *pRadius, br_scalar *pEntry_length, int *pLeft_not_right, br_vector2 *p1, br_vector2 *p2, br_vector2 *p3, br_scalar pWidth12, br_scalar pWidth23) {
    br_vector2 rel1;
    br_vector2 rel3;
    br_vector2 rot1;
    br_vector2 rot1u;
    br_scalar len12_squared;
    br_scalar len23_squared;
    br_scalar c;
    br_scalar numerator;
    br_scalar x;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %p, %f, %f)", pCent, pRadius, pEntry_length, pLeft_not_right, p1, p2, p3, pWidth12, pWidth23);

    (void)pCent;
    (void)pRadius;
    (void)pEntry_length;
    (void)pLeft_not_right;
    (void)p1;
    (void)p2;
    (void)p3;
    (void)pWidth12;
    (void)pWidth23;
    (void)rel1;
    (void)rel3;
    (void)rot1;
    (void)rot1u;
    (void)len12_squared;
    (void)len23_squared;
    (void)c;
    (void)numerator;
    (void)x;
    (void)__block0___scale;

    if (function_hook_state_StraightestArcForCorner2D == HOOK_ENABLED) {
        assert(0 && "StraightestArcForCorner2D not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CornerFudge = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CornerFudge, function_hook_state_CornerFudge)
static br_scalar(__cdecl*original_CornerFudge)(tCar_spec *) = (br_scalar(__cdecl*)(tCar_spec *))0x004a003e;
CARM95_HOOK_FUNCTION(original_CornerFudge, CornerFudge)
br_scalar __cdecl CornerFudge(tCar_spec *pCar_spec) {
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;

    if (function_hook_state_CornerFudge == HOOK_ENABLED) {
        assert(0 && "CornerFudge not implemented.");
        abort();
    } else {
        return original_CornerFudge(pCar_spec);
    }
}

function_hook_state_t function_hook_state_MaxCurvatureForCarSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MaxCurvatureForCarSpeed, function_hook_state_MaxCurvatureForCarSpeed)
static br_scalar(__cdecl*original_MaxCurvatureForCarSpeed)(tCar_spec *, br_scalar) = (br_scalar(__cdecl*)(tCar_spec *, br_scalar))0x004a0054;
CARM95_HOOK_FUNCTION(original_MaxCurvatureForCarSpeed, MaxCurvatureForCarSpeed)
br_scalar __cdecl MaxCurvatureForCarSpeed(tCar_spec *pCar, br_scalar pSpeed) {
    br_scalar curv;
    LOG_TRACE("(%p, %f)", pCar, pSpeed);

    (void)pCar;
    (void)pSpeed;
    (void)curv;

    if (function_hook_state_MaxCurvatureForCarSpeed == HOOK_ENABLED) {
        assert(0 && "MaxCurvatureForCarSpeed not implemented.");
        abort();
    } else {
        return original_MaxCurvatureForCarSpeed(pCar, pSpeed);
    }
}

function_hook_state_t function_hook_state_Vector2Cross = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(Vector2Cross, function_hook_state_Vector2Cross)
br_scalar Vector2Cross(br_vector2 *pA, br_vector2 *pB) {
    LOG_TRACE("(%p, %p)", pA, pB);

    (void)pA;
    (void)pB;

    if (function_hook_state_Vector2Cross == HOOK_ENABLED) {
        assert(0 && "Vector2Cross not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_EndOfPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EndOfPath, function_hook_state_EndOfPath)
tFollow_path_result EndOfPath(tOpponent_spec *pOpponent_spec) {
    tCar_spec *car_spec;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)car_spec;

    if (function_hook_state_EndOfPath == HOOK_ENABLED) {
        assert(0 && "EndOfPath not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RoughlyColinear = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RoughlyColinear, function_hook_state_RoughlyColinear)
int RoughlyColinear(br_vector2 *p1, br_vector2 *p2, br_vector2 *p3) {
    br_vector2 rel1;
    br_vector2 rel2;
    br_vector2 sum;
    br_scalar cross;
    br_scalar dot;
    br_scalar wibble;
    LOG_TRACE("(%p, %p, %p)", p1, p2, p3);

    (void)p1;
    (void)p2;
    (void)p3;
    (void)rel1;
    (void)rel2;
    (void)sum;
    (void)cross;
    (void)dot;
    (void)wibble;

    if (function_hook_state_RoughlyColinear == HOOK_ENABLED) {
        assert(0 && "RoughlyColinear not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetStraight = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetStraight, function_hook_state_GetStraight)
int GetStraight(br_vector2 *pStart, br_vector2 *pFinish, br_scalar *pWidth, int section1, tOpponent_spec *pOpponent_spec, tFollow_path_data *data) {
    int section;
    br_vector2 next;
    br_scalar next_width;
    LOG_TRACE("(%p, %p, %p, %d, %p, %p)", pStart, pFinish, pWidth, section1, pOpponent_spec, data);

    (void)pStart;
    (void)pFinish;
    (void)pWidth;
    (void)section1;
    (void)pOpponent_spec;
    (void)data;
    (void)section;
    (void)next;
    (void)next_width;

    if (function_hook_state_GetStraight == HOOK_ENABLED) {
        assert(0 && "GetStraight not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ProcessFollowPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ProcessFollowPath, function_hook_state_ProcessFollowPath)
static tFollow_path_result(__cdecl*original_ProcessFollowPath)(tOpponent_spec *, tProcess_objective_command, int, int, int) = (tFollow_path_result(__cdecl*)(tOpponent_spec *, tProcess_objective_command, int, int, int))0x0049e3a0;
CARM95_HOOK_FUNCTION(original_ProcessFollowPath, ProcessFollowPath)
tFollow_path_result __cdecl ProcessFollowPath(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand, int pPursuit_mode, int pIgnore_end, int pNever_struggle) {
    tS16 real_section_no;
    tFollow_path_data *data;
    br_vector3 wank;
    br_vector3 wank2;
    br_vector3 *not_our_dir;
    br_vector3 section_dir;
    br_vector3 section_v;
    br_vector3 start;
    br_vector3 corner;
    br_vector3 next;
    br_vector3 goal_dir;
    br_vector3 intersect;
    br_vector3 a;
    br_vector3 p;
    br_vector3 car_to_end;
    br_actor *car_master_actor;
    br_scalar stopped_speed;
    br_scalar dist_to_end;
    br_scalar t;
    br_scalar acc;
    br_scalar speed;
    br_scalar dist_to_goal;
    br_scalar section_width;
    br_scalar goal_width;
    br_scalar desired_speed;
    br_scalar dist_along;
    br_scalar acc_factor;
    br_scalar max_acc;
    br_scalar speed_to_goal;
    br_scalar error;
    br_scalar radius;
    br_scalar entry_len;
    br_scalar corner_speed2;
    br_scalar distance;
    br_scalar stopping_distance;
    br_scalar corner_speed;
    br_scalar dot_a;
    br_scalar dot_d;
    br_scalar further_along;
    tCar_spec *car_spec;
    int engine_damage;
    int trans_damage;
    int section_no;
    int sx;
    int just_fucking_brake;
    br_vector2 oppo_pos2d;
    br_vector2 start2d;
    br_vector2 finish2d;
    br_vector2 next2d;
    br_vector2 oppo_pos_rel;
    br_vector2 oppo_pos_rel_next;
    br_vector2 section_rel;
    br_vector2 section_rel_next;
    br_vector2 v2d;
    br_vector2 corner2d;
    br_vector2 after_corner2d;
    br_vector2 next_turning_cent;
    br_vector2 temp2d;
    br_scalar section_len;
    br_scalar section_len_next;
    br_scalar pos_error;
    br_scalar pos_error_next;
    br_scalar pos_error_factor;
    br_scalar sin_error;
    br_scalar corner_radius;
    br_scalar corner_entry_length;
    br_scalar corner_distance;
    br_scalar speed2d;
    br_scalar stemp1;
    br_scalar width;
    br_scalar next_width;
    br_scalar next_turning_radius;
    br_scalar next_corner_size;
    br_scalar later_width;
    br_scalar effective_speed_factor;
    int first_straight;
    int next_straight;
    int left_not_right;
    int later_straight;
    int next_left_not_right;
    LOG_TRACE("(%p, %d, %d, %d, %d)", pOpponent_spec, pCommand, pPursuit_mode, pIgnore_end, pNever_struggle);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)pPursuit_mode;
    (void)pIgnore_end;
    (void)pNever_struggle;
    (void)real_section_no;
    (void)data;
    (void)wank;
    (void)wank2;
    (void)not_our_dir;
    (void)section_dir;
    (void)section_v;
    (void)start;
    (void)corner;
    (void)next;
    (void)goal_dir;
    (void)intersect;
    (void)a;
    (void)p;
    (void)car_to_end;
    (void)car_master_actor;
    (void)stopped_speed;
    (void)dist_to_end;
    (void)t;
    (void)acc;
    (void)speed;
    (void)dist_to_goal;
    (void)section_width;
    (void)goal_width;
    (void)desired_speed;
    (void)dist_along;
    (void)acc_factor;
    (void)max_acc;
    (void)speed_to_goal;
    (void)error;
    (void)radius;
    (void)entry_len;
    (void)corner_speed2;
    (void)distance;
    (void)stopping_distance;
    (void)corner_speed;
    (void)dot_a;
    (void)dot_d;
    (void)further_along;
    (void)car_spec;
    (void)engine_damage;
    (void)trans_damage;
    (void)section_no;
    (void)sx;
    (void)just_fucking_brake;
    (void)oppo_pos2d;
    (void)start2d;
    (void)finish2d;
    (void)next2d;
    (void)oppo_pos_rel;
    (void)oppo_pos_rel_next;
    (void)section_rel;
    (void)section_rel_next;
    (void)v2d;
    (void)corner2d;
    (void)after_corner2d;
    (void)next_turning_cent;
    (void)temp2d;
    (void)section_len;
    (void)section_len_next;
    (void)pos_error;
    (void)pos_error_next;
    (void)pos_error_factor;
    (void)sin_error;
    (void)corner_radius;
    (void)corner_entry_length;
    (void)corner_distance;
    (void)speed2d;
    (void)stemp1;
    (void)width;
    (void)next_width;
    (void)next_turning_radius;
    (void)next_corner_size;
    (void)later_width;
    (void)effective_speed_factor;
    (void)first_straight;
    (void)next_straight;
    (void)left_not_right;
    (void)later_straight;
    (void)next_left_not_right;

    if (function_hook_state_ProcessFollowPath == HOOK_ENABLED) {
        assert(0 && "ProcessFollowPath not implemented.");
        abort();
    } else {
        return original_ProcessFollowPath(pOpponent_spec, pCommand, pPursuit_mode, pIgnore_end, pNever_struggle);
    }
}

function_hook_state_t function_hook_state_FollowCheatyPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FollowCheatyPath, function_hook_state_FollowCheatyPath)
static tFollow_path_result(__cdecl*original_FollowCheatyPath)(tOpponent_spec *) = (tFollow_path_result(__cdecl*)(tOpponent_spec *))0x004a00a4;
CARM95_HOOK_FUNCTION(original_FollowCheatyPath, FollowCheatyPath)
tFollow_path_result __cdecl FollowCheatyPath(tOpponent_spec *pOpponent_spec) {
    tFollow_path_data *data;
    br_vector3 a;
    br_vector3 p;
    br_vector3 section_v;
    br_vector3 car_to_end;
    br_vector3 car_to_intersect;
    br_vector3 *start;
    br_vector3 *finish;
    br_scalar t;
    br_scalar frame_period_in_secs;
    br_scalar distance_left;
    br_scalar distance_to_end;
    br_scalar distance_to_intersect;
    br_scalar section_min;
    br_scalar section_max;
    br_scalar desired_speed_BRU;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    br_scalar __block3___scale;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)data;
    (void)a;
    (void)p;
    (void)section_v;
    (void)car_to_end;
    (void)car_to_intersect;
    (void)start;
    (void)finish;
    (void)t;
    (void)frame_period_in_secs;
    (void)distance_left;
    (void)distance_to_end;
    (void)distance_to_intersect;
    (void)section_min;
    (void)section_max;
    (void)desired_speed_BRU;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2___scale;
    (void)__block3___scale;

    if (function_hook_state_FollowCheatyPath == HOOK_ENABLED) {
        assert(0 && "FollowCheatyPath not implemented.");
        abort();
    } else {
        return original_FollowCheatyPath(pOpponent_spec);
    }
}

