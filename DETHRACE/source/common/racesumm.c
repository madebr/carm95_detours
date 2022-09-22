#include "racesumm.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int(* hookvar_gPlayer_lookup )[6] = (void*)0x00530e38;
tMouse_area * hookvar_gOld_back_button  = (void*)0x00530e58;
tWreck_info(* hookvar_gWreck_array )[30] = (void*)0x00530ec0;
br_actor ** hookvar_gWreck_root  = (void*)0x00530e94;
br_actor ** hookvar_gWreck_camera  = (void*)0x00530e2c;
tU32 * hookvar_gWreck_start_zoom  = (void*)0x00530eac;
tU32 * hookvar_gWreck_gallery_start  = (void*)0x00530ea4;
float * hookvar_gTemp_rank_increase  = (void*)0x00530e28;
float * hookvar_gRank_per_ms  = (void*)0x00530eb8;
tU32 * hookvar_gLast_wreck_draw  = (void*)0x00530eb0;
tS3_sound_tag * hookvar_gSumm_sound  = (void*)0x00530ea0;
float * hookvar_gCredits_per_ms  = (void*)0x00530e8c;
tMouse_area ** hookvar_gBack_button_ptr  = (void*)0x00530e10;
tU32 * hookvar_gSummary_start  = (void*)0x00530e18;
br_pixelmap ** hookvar_gWreck_z_buffer  = (void*)0x00530e98;
br_pixelmap ** hookvar_gWreck_render_area  = (void*)0x00530e08;
int * hookvar_gWreck_selected  = (void*)0x00531d48;
int * hookvar_gWreck_zoom_out  = (void*)0x00531d4c;
br_pixelmap ** hookvar_gChrome_font  = (void*)0x00530e90;
int * hookvar_gWreck_zoom_in  = (void*)0x00530eb4;
int * hookvar_gTemp_credits  = (void*)0x00530ea8;
int * hookvar_gUser_interacted  = (void*)0x00530e50;
int * hookvar_gWreck_count  = (void*)0x00530e00;
int * hookvar_gRank_etc_munged  = (void*)0x00530e88;
int * hookvar_gRank_increase  = (void*)0x00530e0c;
int * hookvar_gTemp_earned  = (void*)0x00530e14;
int * hookvar_gTemp_rank  = (void*)0x00530e30;
int * hookvar_gWreck_zoomed_in  = (void*)0x00530e24;
int * hookvar_gDone_initial  = (void*)0x00530e04;
int * hookvar_gTemp_lost  = (void*)0x00530e20;

static void(__cdecl*original_MungeRankEtc)(tProgram_state *) = (void(__cdecl*)(tProgram_state *))0x00415740;
CARM95_HOOK_FUNCTION(original_MungeRankEtc, MungeRankEtc)
void __cdecl MungeRankEtc(tProgram_state *pThe_state) {
    int i;
    int not_done_yet;
    LOG_TRACE("(%p)", pThe_state);

    (void)pThe_state;
    (void)i;
    (void)not_done_yet;

    original_MungeRankEtc(pThe_state);
}

static void(__cdecl*original_CalcRankIncrease)() = (void(__cdecl*)())0x0041631f;
CARM95_HOOK_FUNCTION(original_CalcRankIncrease, CalcRankIncrease)
void __cdecl CalcRankIncrease() {
    LOG_TRACE("()");


    original_CalcRankIncrease();
}

static int(__cdecl*original_RaceSummaryDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0041587e;
CARM95_HOOK_FUNCTION(original_RaceSummaryDone, RaceSummaryDone)
int __cdecl RaceSummaryDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_RaceSummaryDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(__cdecl*original_DrawInBox)(int, int, int, int, int, int, int) = (void(__cdecl*)(int, int, int, int, int, int, int))0x00415e44;
CARM95_HOOK_FUNCTION(original_DrawInBox, DrawInBox)
void __cdecl DrawInBox(int pBox_left, int pText_left, int pTop, int pRight, int pBottom, int pColour, int pAmount) {
    LOG_TRACE("(%d, %d, %d, %d, %d, %d, %d)", pBox_left, pText_left, pTop, pRight, pBottom, pColour, pAmount);

    (void)pBox_left;
    (void)pText_left;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pColour;
    (void)pAmount;

    original_DrawInBox(pBox_left, pText_left, pTop, pRight, pBottom, pColour, pAmount);
}

static void(__cdecl*original_DrawChromeNumber)(int, int, int, int, int) = (void(__cdecl*)(int, int, int, int, int))0x00415ebd;
CARM95_HOOK_FUNCTION(original_DrawChromeNumber, DrawChromeNumber)
void __cdecl DrawChromeNumber(int pLeft_1, int pLeft_2, int pPitch, int pTop, int pAmount) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pLeft_1, pLeft_2, pPitch, pTop, pAmount);

    (void)pLeft_1;
    (void)pLeft_2;
    (void)pPitch;
    (void)pTop;
    (void)pAmount;

    original_DrawChromeNumber(pLeft_1, pLeft_2, pPitch, pTop, pAmount);
}

static void(__cdecl*original_DrawSummaryItems)() = (void(__cdecl*)())0x00415beb;
CARM95_HOOK_FUNCTION(original_DrawSummaryItems, DrawSummaryItems)
void __cdecl DrawSummaryItems() {
    LOG_TRACE("()");


    original_DrawSummaryItems();
}

static void(__cdecl*original_RampUpRate)(float *, tU32) = (void(__cdecl*)(float *, tU32))0x00415f72;
CARM95_HOOK_FUNCTION(original_RampUpRate, RampUpRate)
void __cdecl RampUpRate(float *pRate, tU32 pTime) {
    LOG_TRACE("(%p, %u)", pRate, pTime);

    (void)pRate;
    (void)pTime;

    original_RampUpRate(pRate, pTime);
}

static void(__cdecl*original_DrawSummary)(int, int) = (void(__cdecl*)(int, int))0x004158c0;
CARM95_HOOK_FUNCTION(original_DrawSummary, DrawSummary)
void __cdecl DrawSummary(int pCurrent_choice, int pCurrent_mode) {
    tU32 the_time;
    static tU32 last_time;
    static tU32 last_change_time;
    int credit_delta;
    float old_temp_increase;
    float rank_delta;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)the_time;
    (void)last_time;
    (void)last_change_time;
    (void)credit_delta;
    (void)old_temp_increase;
    (void)rank_delta;

    original_DrawSummary(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_StartSummary)() = (void(__cdecl*)())0x00415ff2;
CARM95_HOOK_FUNCTION(original_StartSummary, StartSummary)
void __cdecl StartSummary() {
    LOG_TRACE("()");


    original_StartSummary();
}

static void(__cdecl*original_SetUpTemps)() = (void(__cdecl*)())0x00416046;
CARM95_HOOK_FUNCTION(original_SetUpTemps, SetUpTemps)
void __cdecl SetUpTemps() {
    LOG_TRACE("()");


    original_SetUpTemps();
}

static int(__cdecl*original_Summ1GoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0041600c;
CARM95_HOOK_FUNCTION(original_Summ1GoAhead, Summ1GoAhead)
int __cdecl Summ1GoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_Summ1GoAhead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_SummCheckGameOver)(int *, int *) = (int(__cdecl*)(int *, int *))0x0041608d;
CARM95_HOOK_FUNCTION(original_SummCheckGameOver, SummCheckGameOver)
int __cdecl SummCheckGameOver(int *pCurrent_choice, int *pCurrent_mode) {
    int i;
    tS3_sound_tag sound_tag;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)sound_tag;

    return original_SummCheckGameOver(pCurrent_choice, pCurrent_mode);
}

static tSO_result(__cdecl*original_DoEndRaceSummary1)() = (tSO_result(__cdecl*)())0x004161dd;
CARM95_HOOK_FUNCTION(original_DoEndRaceSummary1, DoEndRaceSummary1)
tSO_result __cdecl DoEndRaceSummary1() {
    static tFlicette flicker_on[1];
    static tFlicette flicker_off[1];
    static tFlicette push[1];
    static tMouse_area mouse_areas[1];
    static tInterface_spec interface_spec;
    int result;
    int completed_already;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;
    (void)completed_already;

    return original_DoEndRaceSummary1();
}

static void(__cdecl*original_PrepareBoundingRadius__racesumm)(br_model *) = (void(__cdecl*)(br_model *))0x00417e27;
CARM95_HOOK_FUNCTION(original_PrepareBoundingRadius__racesumm, PrepareBoundingRadius__racesumm)
void __cdecl PrepareBoundingRadius__racesumm(br_model *model) {
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

    original_PrepareBoundingRadius__racesumm(model);
}

static void(__cdecl*original_BuildWrecks)() = (void(__cdecl*)())0x00417a91;
CARM95_HOOK_FUNCTION(original_BuildWrecks, BuildWrecks)
void __cdecl BuildWrecks() {
    int cat;
    int i;
    int position;
    int car_count;
    br_actor *this_car;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)cat;
    (void)i;
    (void)position;
    (void)car_count;
    (void)this_car;
    (void)the_car;

    original_BuildWrecks();
}

static void(__cdecl*original_DisposeWrecks)() = (void(__cdecl*)())0x00417eba;
CARM95_HOOK_FUNCTION(original_DisposeWrecks, DisposeWrecks)
void __cdecl DisposeWrecks() {
    int cat;
    int i;
    int position;
    int car_count;
    br_actor *this_car;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)cat;
    (void)i;
    (void)position;
    (void)car_count;
    (void)this_car;
    (void)the_car;

    original_DisposeWrecks();
}

static int(__cdecl*original_MatrixIsIdentity)(br_matrix34 *) = (int(__cdecl*)(br_matrix34 *))0x00416f4e;
CARM95_HOOK_FUNCTION(original_MatrixIsIdentity, MatrixIsIdentity)
int __cdecl MatrixIsIdentity(br_matrix34 *pMat) {
    LOG_TRACE("(%p)", pMat);

    (void)pMat;

    return original_MatrixIsIdentity(pMat);
}

static void(__cdecl*original_SpinWrecks)(tU32) = (void(__cdecl*)(tU32))0x00416d47;
CARM95_HOOK_FUNCTION(original_SpinWrecks, SpinWrecks)
void __cdecl SpinWrecks(tU32 pFrame_period) {
    int i;
    br_vector3 translation;
    br_matrix34 old_mat;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)translation;
    (void)old_mat;

    original_SpinWrecks(pFrame_period);
}

static void(__cdecl*original_ZoomInTo)(int, int *, int *) = (void(__cdecl*)(int, int *, int *))0x0041778f;
CARM95_HOOK_FUNCTION(original_ZoomInTo, ZoomInTo)
void __cdecl ZoomInTo(int pIndex, int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%d, %p, %p)", pIndex, pCurrent_choice, pCurrent_mode);

    (void)pIndex;
    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_ZoomInTo(pIndex, pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_ZoomOutTo)(int, int *, int *) = (void(__cdecl*)(int, int *, int *))0x00416413;
CARM95_HOOK_FUNCTION(original_ZoomOutTo, ZoomOutTo)
void __cdecl ZoomOutTo(int pIndex, int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%d, %p, %p)", pIndex, pCurrent_choice, pCurrent_mode);

    (void)pIndex;
    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_ZoomOutTo(pIndex, pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_WreckPick)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *) = (int(__cdecl*)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *))0x0041660d;
CARM95_HOOK_FUNCTION(original_WreckPick, WreckPick)
int __cdecl WreckPick(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pNear, br_scalar pFar, void *pArg) {
    int i;
    LOG_TRACE("(%p, %p, %p, %p, %p, %f, %f, %p)", pActor, pModel, pMaterial, pRay_pos, pRay_dir, pNear, pFar, pArg);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pNear;
    (void)pFar;
    (void)pArg;
    (void)i;

    return original_WreckPick(pActor, pModel, pMaterial, pRay_pos, pRay_dir, pNear, pFar, pArg);
}

static int(__cdecl*original_CastSelectionRay)(int *, int *) = (int(__cdecl*)(int *, int *))0x00416486;
CARM95_HOOK_FUNCTION(original_CastSelectionRay, CastSelectionRay)
int __cdecl CastSelectionRay(int *pCurrent_choice, int *pCurrent_mode) {
    int mouse_x;
    int mouse_y;
    int i;
    int result;
    br_scalar inv_wreck_pick_scale_factor;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)mouse_x;
    (void)mouse_y;
    (void)i;
    (void)result;
    (void)inv_wreck_pick_scale_factor;

    return original_CastSelectionRay(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnExit)(int *, int *) = (int(__cdecl*)(int *, int *))0x0041636e;
CARM95_HOOK_FUNCTION(original_DamageScrnExit, DamageScrnExit)
int __cdecl DamageScrnExit(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DamageScrnExit(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_DamageScrnDraw)(int, int) = (void(__cdecl*)(int, int))0x00416671;
CARM95_HOOK_FUNCTION(original_DamageScrnDraw, DamageScrnDraw)
void __cdecl DamageScrnDraw(int pCurrent_choice, int pCurrent_mode) {
    tU32 the_time;
    br_vector3 camera_movement;
    int finished;
    int h;
    int v;
    int rows;
    int columns;
    float spacing;
    br_actor *sel_actor;
    char *name;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)the_time;
    (void)camera_movement;
    (void)finished;
    (void)h;
    (void)v;
    (void)rows;
    (void)columns;
    (void)spacing;
    (void)sel_actor;
    (void)name;

    original_DamageScrnDraw(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x00417038;
CARM95_HOOK_FUNCTION(original_DamageScrnLeft, DamageScrnLeft)
int __cdecl DamageScrnLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;

    return original_DamageScrnLeft(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x00417175;
CARM95_HOOK_FUNCTION(original_DamageScrnRight, DamageScrnRight)
int __cdecl DamageScrnRight(int *pCurrent_choice, int *pCurrent_mode) {
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;

    return original_DamageScrnRight(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x004172b9;
CARM95_HOOK_FUNCTION(original_DamageScrnUp, DamageScrnUp)
int __cdecl DamageScrnUp(int *pCurrent_choice, int *pCurrent_mode) {
    int i;
    int difference;
    int new_difference;
    int new_selection;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)difference;
    (void)new_difference;
    (void)new_selection;

    return original_DamageScrnUp(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x004174a9;
CARM95_HOOK_FUNCTION(original_DamageScrnDown, DamageScrnDown)
int __cdecl DamageScrnDown(int *pCurrent_choice, int *pCurrent_mode) {
    int i;
    int difference;
    int new_difference;
    int new_selection;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)difference;
    (void)new_difference;
    (void)new_selection;

    return original_DamageScrnDown(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DamageScrnGoHead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004176dd;
CARM95_HOOK_FUNCTION(original_DamageScrnGoHead, DamageScrnGoHead)
int __cdecl DamageScrnGoHead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DamageScrnGoHead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_ClickDamage)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x00417839;
CARM95_HOOK_FUNCTION(original_ClickDamage, ClickDamage)
int __cdecl ClickDamage(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int mouse_x;
    int mouse_y;
    int old_mouse_x;
    int old_mouse_y;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)mouse_x;
    (void)mouse_y;
    (void)old_mouse_x;
    (void)old_mouse_y;

    return original_ClickDamage(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_DamageScrnDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0041794f;
CARM95_HOOK_FUNCTION(original_DamageScrnDone, DamageScrnDone)
int __cdecl DamageScrnDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_DamageScrnDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static tSO_result(__cdecl*original_DoEndRaceSummary2)() = (tSO_result(__cdecl*)())0x0041797b;
CARM95_HOOK_FUNCTION(original_DoEndRaceSummary2, DoEndRaceSummary2)
tSO_result __cdecl DoEndRaceSummary2() {
    static tFlicette flicker_on[3];
    static tFlicette flicker_off[3];
    static tFlicette push[3];
    static tMouse_area mouse_areas[3];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    return original_DoEndRaceSummary2();
}

static void(__cdecl*original_DrawAnItem__racesumm)(int, int, int, char *) = (void(__cdecl*)(int, int, int, char *))0x004183be;
CARM95_HOOK_FUNCTION(original_DrawAnItem__racesumm, DrawAnItem__racesumm)
void __cdecl DrawAnItem__racesumm(int pX, int pY_index, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, \"%s\")", pX, pY_index, pFont_index, pText);

    (void)pX;
    (void)pY_index;
    (void)pFont_index;
    (void)pText;

    original_DrawAnItem__racesumm(pX, pY_index, pFont_index, pText);
}

static void(__cdecl*original_DrawColumnHeading__racesumm)(int, int) = (void(__cdecl*)(int, int))0x00418405;
CARM95_HOOK_FUNCTION(original_DrawColumnHeading__racesumm, DrawColumnHeading__racesumm)
void __cdecl DrawColumnHeading__racesumm(int pStr_index, int pX) {
    LOG_TRACE("(%d, %d)", pStr_index, pX);

    (void)pStr_index;
    (void)pX;

    original_DrawColumnHeading__racesumm(pStr_index, pX);
}

static int(__cdecl*original_SortScores)(void *, void *) = (int(__cdecl*)(void *, void *))0x0041853a;
CARM95_HOOK_FUNCTION(original_SortScores, SortScores)
int __cdecl SortScores(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    return original_SortScores(pFirst_one, pSecond_one);
}

static void(__cdecl*original_SortGameScores)() = (void(__cdecl*)())0x00418515;
CARM95_HOOK_FUNCTION(original_SortGameScores, SortGameScores)
void __cdecl SortGameScores() {
    LOG_TRACE("()");


    original_SortGameScores();
}

static void(__cdecl*original_NetSumDraw)(int, int) = (void(__cdecl*)(int, int))0x0041804b;
CARM95_HOOK_FUNCTION(original_NetSumDraw, NetSumDraw)
void __cdecl NetSumDraw(int pCurrent_choice, int pCurrent_mode) {
    int i;
    char s[256];
    tNet_game_player_info *player;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)s;
    (void)player;

    original_NetSumDraw(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_DoNetRaceSummary)() = (void(__cdecl*)())0x00418452;
CARM95_HOOK_FUNCTION(original_DoNetRaceSummary, DoNetRaceSummary)
void __cdecl DoNetRaceSummary() {
    static tFlicette flicker_on[1];
    static tFlicette flicker_off[1];
    static tFlicette push[1];
    static tMouse_area mouse_areas[1];
    static tInterface_spec interface_spec;
    int i;
    int result;
    tS32 start_time;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)i;
    (void)result;
    (void)start_time;

    original_DoNetRaceSummary();
}

static tSO_result(__cdecl*original_DoEndRaceSummary)(int *, tRace_result) = (tSO_result(__cdecl*)(int *, tRace_result))0x00418590;
CARM95_HOOK_FUNCTION(original_DoEndRaceSummary, DoEndRaceSummary)
tSO_result __cdecl DoEndRaceSummary(int *pFirst_summary_done, tRace_result pRace_result) {
    tSO_result result;
    LOG_TRACE("(%p, %d)", pFirst_summary_done, pRace_result);

    (void)pFirst_summary_done;
    (void)pRace_result;
    (void)result;

    return original_DoEndRaceSummary(pFirst_summary_done, pRace_result);
}

