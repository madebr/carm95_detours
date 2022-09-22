#include "racestrt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int(* hookvar_gGrid_number_colour )[4] = (void*)0x0050f198;
int * hookvar_gJust_bought_part  = (void*)0x0050f1a8;
#if 0
tU32 * hookvar_gLast_host_query ;
#endif
br_pixelmap ** hookvar_gDead_car  = (void*)0x00550acc;
int * hookvar_gFade_away_parts_shop  = (void*)0x00536408;
tU32 * hookvar_gDare_start_time  = (void*)0x0053635c;
int * hookvar_gRefund_rate  = (void*)0x00536418;
int * hookvar_gSwap_grid_2  = (void*)0x0053640c;
int * hookvar_gSwap_grid_1  = (void*)0x00536410;
int * hookvar_gChange_race_net_mode  = (void*)0x005363f0;
tParts_category * hookvar_gPart_category  = (void*)0x0053641c;
#if 0
tU32 * hookvar_gNet_synch_start ;
#endif
tNet_game_details ** hookvar_gChoose_car_net_game  = (void*)0x0053634c;
int * hookvar_gPart_index  = (void*)0x00536404;
 // Suffix added to avoid duplicate symbol
int * hookvar_gChallenger_index__racestrt  = (void*)0x0053636c;
tGrid_draw * hookvar_gDraw_grid_status  = (void*)0x00536360;
 // Suffix added to avoid duplicate symbol
tNet_sequence_type * hookvar_gNet_race_sequence__racestrt  = (void*)0x005363ec;
br_pixelmap ** hookvar_gTaken_image  = (void*)0x0053642c;
int(* hookvar_gGrid_number_x_coords )[31] = (void*)0x00536370;
int * hookvar_gGrid_transition_stage  = (void*)0x005363f4;
int * hookvar_gGrid_y_adjust  = (void*)0x00536428;
br_pixelmap ** hookvar_gBullet_image  = (void*)0x00536400;
br_pixelmap ** hookvar_gDeceased_image  = (void*)0x005363f8;
int * hookvar_gBest_pos_available  = (void*)0x00536364;
int * hookvar_gChallenger_position  = (void*)0x00536358;
int * hookvar_gOpponent_index  = (void*)0x00536414;
int * hookvar_gChallenge_time  = (void*)0x005363fc;
int * hookvar_gOriginal_position  = (void*)0x00536354;
int * hookvar_gCurrent_race_index  = (void*)0x00536420;
tInterface_spec ** hookvar_gStart_interface_spec  = (void*)0x00536350;
int * hookvar_gCurrent_car_index  = (void*)0x00536424;
int * hookvar_gOur_starting_position  = (void*)0x00536368;

static void(__cdecl*original_DrawRaceList)(int) = (void(__cdecl*)(int))0x0044e944;
CARM95_HOOK_FUNCTION(original_DrawRaceList, DrawRaceList)
void __cdecl DrawRaceList(int pOffset) {
    int i;
    int font_height;
    int pitch;
    int y;
    int left_most;
    int right_most;
    int rank_colour;
    int text_colour;
    int box_bot;
    int text_width;
    int text_x;
    char rank_str[256];
    LOG_TRACE("(%d)", pOffset);

    (void)pOffset;
    (void)i;
    (void)font_height;
    (void)pitch;
    (void)y;
    (void)left_most;
    (void)right_most;
    (void)rank_colour;
    (void)text_colour;
    (void)box_bot;
    (void)text_width;
    (void)text_x;
    (void)rank_str;

    original_DrawRaceList(pOffset);
}

static void(__cdecl*original_MoveRaceList)(int, int, tS32) = (void(__cdecl*)(int, int, tS32))0x0044e8c7;
CARM95_HOOK_FUNCTION(original_MoveRaceList, MoveRaceList)
void __cdecl MoveRaceList(int pFrom, int pTo, tS32 pTime_to_move) {
    tS32 start_time;
    tS32 the_time;
    int move_distance;
    int pitch;
    LOG_TRACE("(%d, %d, %d)", pFrom, pTo, pTime_to_move);

    (void)pFrom;
    (void)pTo;
    (void)pTime_to_move;
    (void)start_time;
    (void)the_time;
    (void)move_distance;
    (void)pitch;

    original_MoveRaceList(pFrom, pTo, pTime_to_move);
}

static int(__cdecl*original_UpRace)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044e7f0;
CARM95_HOOK_FUNCTION(original_UpRace, UpRace)
int __cdecl UpRace(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_UpRace(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DownRace)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044ef24;
CARM95_HOOK_FUNCTION(original_DownRace, DownRace)
int __cdecl DownRace(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DownRace(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_ClickOnRace)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0044f000;
CARM95_HOOK_FUNCTION(original_ClickOnRace, ClickOnRace)
int __cdecl ClickOnRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int x_coord;
    int y_coord;
    int race_delta;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)x_coord;
    (void)y_coord;
    (void)race_delta;

    return original_ClickOnRace(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_UpClickRace)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0044f0cd;
CARM95_HOOK_FUNCTION(original_UpClickRace, UpClickRace)
int __cdecl UpClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_UpClickRace(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_DownClickRace)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0044f0ef;
CARM95_HOOK_FUNCTION(original_DownClickRace, DownClickRace)
int __cdecl DownClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_DownClickRace(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static void(__cdecl*original_StartChangeRace)() = (void(__cdecl*)())0x0044f111;
CARM95_HOOK_FUNCTION(original_StartChangeRace, StartChangeRace)
void __cdecl StartChangeRace() {
    LOG_TRACE("()");


    original_StartChangeRace();
}

static int(__cdecl*original_ChangeRace)(int *, int, tNet_sequence_type) = (int(__cdecl*)(int *, int, tNet_sequence_type))0x0044f131;
CARM95_HOOK_FUNCTION(original_ChangeRace, ChangeRace)
int __cdecl ChangeRace(int *pRace_index, int pNet_mode, tNet_sequence_type pNet_race_sequence) {
    static tFlicette flicker_on[4];
    static tFlicette flicker_off[4];
    static tFlicette push[4];
    static tMouse_area mouse_areas[5];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("(%p, %d, %d)", pRace_index, pNet_mode, pNet_race_sequence);

    (void)pRace_index;
    (void)pNet_mode;
    (void)pNet_race_sequence;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    return original_ChangeRace(pRace_index, pNet_mode, pNet_race_sequence);
}

static void(__cdecl*original_DoChangeRace)() = (void(__cdecl*)())0x00451fe5;
CARM95_HOOK_FUNCTION(original_DoChangeRace, DoChangeRace)
void __cdecl DoChangeRace() {
    LOG_TRACE("()");


    original_DoChangeRace();
}

static void(__cdecl*original_DrawCar)(int, int) = (void(__cdecl*)(int, int))0x0044f1f2;
CARM95_HOOK_FUNCTION(original_DrawCar, DrawCar)
void __cdecl DrawCar(int pCurrent_choice, int pCurrent_mode) {
    char s[64];
    int text_x;
    int text_width;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)s;
    (void)text_x;
    (void)text_width;

    original_DrawCar(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_SetCarFlic)() = (void(__cdecl*)())0x0044f5de;
CARM95_HOOK_FUNCTION(original_SetCarFlic, SetCarFlic)
void __cdecl SetCarFlic() {
    LOG_TRACE("()");


    original_SetCarFlic();
}

static int(__cdecl*original_UpCar)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044f4cc;
CARM95_HOOK_FUNCTION(original_UpCar, UpCar)
int __cdecl UpCar(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_UpCar(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DownCar)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044f62d;
CARM95_HOOK_FUNCTION(original_DownCar, DownCar)
int __cdecl DownCar(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DownCar(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_UpClickCar)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0044f744;
CARM95_HOOK_FUNCTION(original_UpClickCar, UpClickCar)
int __cdecl UpClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_UpClickCar(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_DownClickCar)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0044f766;
CARM95_HOOK_FUNCTION(original_DownClickCar, DownClickCar)
int __cdecl DownClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_DownClickCar(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_ChangeCarGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044f788;
CARM95_HOOK_FUNCTION(original_ChangeCarGoAhead, ChangeCarGoAhead)
int __cdecl ChangeCarGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_ChangeCarGoAhead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_ChangeCar)(int, int *, tNet_game_details *) = (int(__cdecl*)(int, int *, tNet_game_details *))0x0044f7e6;
CARM95_HOOK_FUNCTION(original_ChangeCar, ChangeCar)
int __cdecl ChangeCar(int pNet_mode, int *pCar_index, tNet_game_details *pNet_game) {
    static tFlicette flicker_on[4];
    static tFlicette flicker_off[4];
    static tFlicette push[4];
    static tMouse_area mouse_areas[4];
    static tInterface_spec interface_spec;
    int i;
    int result;
    int power_up_levels[3];
    LOG_TRACE("(%d, %p, %p)", pNet_mode, pCar_index, pNet_game);

    (void)pNet_mode;
    (void)pCar_index;
    (void)pNet_game;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)i;
    (void)result;
    (void)power_up_levels;

    return original_ChangeCar(pNet_mode, pCar_index, pNet_game);
}

static void(__cdecl*original_DoChangeCar)() = (void(__cdecl*)())0x00452017;
CARM95_HOOK_FUNCTION(original_DoChangeCar, DoChangeCar)
void __cdecl DoChangeCar() {
    LOG_TRACE("()");


    original_DoChangeCar();
}

static int(__cdecl*original_PartsShopRecommended)() = (int(__cdecl*)())0x00450cf3;
CARM95_HOOK_FUNCTION(original_PartsShopRecommended, PartsShopRecommended)
int __cdecl PartsShopRecommended() {
    int running_cost;
    int i;
    int current_index;
    int counter;
    LOG_TRACE("()");

    (void)running_cost;
    (void)i;
    (void)current_index;
    (void)counter;

    return original_PartsShopRecommended();
}

static void(__cdecl*original_CalcPartPrice)(int, int, int *, int *) = (void(__cdecl*)(int, int, int *, int *))0x004502ec;
CARM95_HOOK_FUNCTION(original_CalcPartPrice, CalcPartPrice)
void __cdecl CalcPartPrice(int pCategory, int pIndex, int *pPrice, int *pCost) {
    int current_value;
    LOG_TRACE("(%d, %d, %p, %p)", pCategory, pIndex, pPrice, pCost);

    (void)pCategory;
    (void)pIndex;
    (void)pPrice;
    (void)pCost;
    (void)current_value;

    original_CalcPartPrice(pCategory, pIndex, pPrice, pCost);
}

static int(__cdecl*original_BuyPart)(int, int) = (int(__cdecl*)(int, int))0x004504c4;
CARM95_HOOK_FUNCTION(original_BuyPart, BuyPart)
int __cdecl BuyPart(int pCategory, int pIndex) {
    int price;
    int cost;
    LOG_TRACE("(%d, %d)", pCategory, pIndex);

    (void)pCategory;
    (void)pIndex;
    (void)price;
    (void)cost;

    return original_BuyPart(pCategory, pIndex);
}

static void(__cdecl*original_DoAutoParts)() = (void(__cdecl*)())0x00450bc8;
CARM95_HOOK_FUNCTION(original_DoAutoParts, DoAutoParts)
void __cdecl DoAutoParts() {
    int i;
    int lowest_yet;
    int lowest_one;
    int price;
    int cost;
    int current_level;
    LOG_TRACE("()");

    (void)i;
    (void)lowest_yet;
    (void)lowest_one;
    (void)price;
    (void)cost;
    (void)current_level;

    original_DoAutoParts();
}

static void(__cdecl*original_DrawPartsLabel)() = (void(__cdecl*)())0x0044fdd1;
CARM95_HOOK_FUNCTION(original_DrawPartsLabel, DrawPartsLabel)
void __cdecl DrawPartsLabel() {
    LOG_TRACE("()");


    original_DrawPartsLabel();
}

static void(__cdecl*original_ErasePartsText)(int) = (void(__cdecl*)(int))0x0044fe92;
CARM95_HOOK_FUNCTION(original_ErasePartsText, ErasePartsText)
void __cdecl ErasePartsText(int pTotal_as_well) {
    LOG_TRACE("(%d)", pTotal_as_well);

    (void)pTotal_as_well;

    original_ErasePartsText(pTotal_as_well);
}

static void(__cdecl*original_DrawPartsText)() = (void(__cdecl*)())0x0044fffc;
CARM95_HOOK_FUNCTION(original_DrawPartsText, DrawPartsText)
void __cdecl DrawPartsText() {
    int price;
    int cost;
    LOG_TRACE("()");

    (void)price;
    (void)cost;

    original_DrawPartsText();
}

static void(__cdecl*original_SetPartsImage)() = (void(__cdecl*)())0x0044ff71;
CARM95_HOOK_FUNCTION(original_SetPartsImage, SetPartsImage)
void __cdecl SetPartsImage() {
    LOG_TRACE("()");


    original_SetPartsImage();
}

static int(__cdecl*original_GetPartsMax)() = (int(__cdecl*)())0x004506e4;
CARM95_HOOK_FUNCTION(original_GetPartsMax, GetPartsMax)
int __cdecl GetPartsMax() {
    int i;
    LOG_TRACE("()");

    (void)i;

    return original_GetPartsMax();
}

static void(__cdecl*original_CalcPartsIndex)() = (void(__cdecl*)())0x0045039b;
CARM95_HOOK_FUNCTION(original_CalcPartsIndex, CalcPartsIndex)
void __cdecl CalcPartsIndex() {
    int current_index;
    LOG_TRACE("()");

    (void)current_index;

    original_CalcPartsIndex();
}

static void(__cdecl*original_DoExchangePart)() = (void(__cdecl*)())0x00450429;
CARM95_HOOK_FUNCTION(original_DoExchangePart, DoExchangePart)
void __cdecl DoExchangePart() {
    int price;
    int cost;
    LOG_TRACE("()");

    (void)price;
    (void)cost;

    original_DoExchangePart();
}

static int(__cdecl*original_PartsShopGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044fbb7;
CARM95_HOOK_FUNCTION(original_PartsShopGoAhead, PartsShopGoAhead)
int __cdecl PartsShopGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    int flic_index;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)flic_index;

    return original_PartsShopGoAhead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_UpPart)(int *, int *) = (int(__cdecl*)(int *, int *))0x0045055c;
CARM95_HOOK_FUNCTION(original_UpPart, UpPart)
int __cdecl UpPart(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_UpPart(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DownPart)(int *, int *) = (int(__cdecl*)(int *, int *))0x0045076c;
CARM95_HOOK_FUNCTION(original_DownPart, DownPart)
int __cdecl DownPart(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DownPart(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_UpClickPart)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x004508fb;
CARM95_HOOK_FUNCTION(original_UpClickPart, UpClickPart)
int __cdecl UpClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_UpClickPart(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_DownClickPart)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0045091d;
CARM95_HOOK_FUNCTION(original_DownClickPart, DownClickPart)
int __cdecl DownClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_DownClickPart(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_PartsArrowsOn)(int *, int *) = (int(__cdecl*)(int *, int *))0x0045093f;
CARM95_HOOK_FUNCTION(original_PartsArrowsOn, PartsArrowsOn)
int __cdecl PartsArrowsOn(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_PartsArrowsOn(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_PartsArrowsOff)(int *, int *) = (int(__cdecl*)(int *, int *))0x004509de;
CARM95_HOOK_FUNCTION(original_PartsArrowsOff, PartsArrowsOff)
int __cdecl PartsArrowsOff(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_PartsArrowsOff(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_StartPartsShop)() = (void(__cdecl*)())0x00450a7d;
CARM95_HOOK_FUNCTION(original_StartPartsShop, StartPartsShop)
void __cdecl StartPartsShop() {
    LOG_TRACE("()");


    original_StartPartsShop();
}

static int(__fastcall*original_DonePartsShop)(int, int, int, int, int) = (int(__fastcall*)(int, int, int, int, int))0x00450a92;
CARM95_HOOK_FUNCTION(original_DonePartsShop, DonePartsShop)
int __fastcall DonePartsShop(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_DonePartsShop(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(__cdecl*original_DrawPartsShop)(int, int) = (void(__cdecl*)(int, int))0x00450ac9;
CARM95_HOOK_FUNCTION(original_DrawPartsShop, DrawPartsShop)
void __cdecl DrawPartsShop(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_DrawPartsShop(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_DoPartsShop)(int) = (void(__cdecl*)(int))0x00450e06;
CARM95_HOOK_FUNCTION(original_DoPartsShop, DoPartsShop)
void __cdecl DoPartsShop(int pFade_away) {
    static tFlicette flicker_on[7];
    static tFlicette flicker_off[7];
    static tFlicette push[7];
    static tMouse_area mouse_areas[7];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("(%d)", pFade_away);

    (void)pFade_away;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    original_DoPartsShop(pFade_away);
}

static int(__cdecl*original_AutoPartsDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x00450ad9;
CARM95_HOOK_FUNCTION(original_AutoPartsDone, AutoPartsDone)
int __cdecl AutoPartsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_AutoPartsDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static tSO_result(__cdecl*original_DoAutoPartsShop)() = (tSO_result(__cdecl*)())0x00450b05;
CARM95_HOOK_FUNCTION(original_DoAutoPartsShop, DoAutoPartsShop)
tSO_result __cdecl DoAutoPartsShop() {
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

    return original_DoAutoPartsShop();
}

static void(__cdecl*original_SetOpponentFlic)() = (void(__cdecl*)())0x004510ba;
CARM95_HOOK_FUNCTION(original_SetOpponentFlic, SetOpponentFlic)
void __cdecl SetOpponentFlic() {
    LOG_TRACE("()");


    original_SetOpponentFlic();
}

static void(__cdecl*original_DrawSceneyMappyInfoVieweyThing)() = (void(__cdecl*)())0x00451002;
CARM95_HOOK_FUNCTION(original_DrawSceneyMappyInfoVieweyThing, DrawSceneyMappyInfoVieweyThing)
void __cdecl DrawSceneyMappyInfoVieweyThing() {
    LOG_TRACE("()");


    original_DrawSceneyMappyInfoVieweyThing();
}

static void(__cdecl*original_DismissSceneyMappyInfoVieweyThing)() = (void(__cdecl*)())0x00450eea;
CARM95_HOOK_FUNCTION(original_DismissSceneyMappyInfoVieweyThing, DismissSceneyMappyInfoVieweyThing)
void __cdecl DismissSceneyMappyInfoVieweyThing() {
    LOG_TRACE("()");


    original_DismissSceneyMappyInfoVieweyThing();
}

static int(__cdecl*original_SelectRaceDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x00450eb9;
CARM95_HOOK_FUNCTION(original_SelectRaceDone, SelectRaceDone)
int __cdecl SelectRaceDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_SelectRaceDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(__cdecl*original_StartRaceGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x00450f2a;
CARM95_HOOK_FUNCTION(original_StartRaceGoAhead, StartRaceGoAhead)
int __cdecl StartRaceGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_StartRaceGoAhead(pCurrent_choice, pCurrent_mode);
}

int TryToMoveToArrows(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    NOT_IMPLEMENTED();
}

static int(__cdecl*original_UpOpponent)(int *, int *) = (int(__cdecl*)(int *, int *))0x00451160;
CARM95_HOOK_FUNCTION(original_UpOpponent, UpOpponent)
int __cdecl UpOpponent(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_UpOpponent(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_DownOpponent)(int *, int *) = (int(__cdecl*)(int *, int *))0x00451285;
CARM95_HOOK_FUNCTION(original_DownOpponent, DownOpponent)
int __cdecl DownOpponent(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_DownOpponent(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_UpClickOpp)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x004513a8;
CARM95_HOOK_FUNCTION(original_UpClickOpp, UpClickOpp)
int __cdecl UpClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_UpClickOpp(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_DownClickOpp)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x004513ca;
CARM95_HOOK_FUNCTION(original_DownClickOpp, DownClickOpp)
int __cdecl DownClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_DownClickOpp(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static void(__cdecl*original_SelectRaceStart)() = (void(__cdecl*)())0x004513ec;
CARM95_HOOK_FUNCTION(original_SelectRaceStart, SelectRaceStart)
void __cdecl SelectRaceStart() {
    LOG_TRACE("()");


    original_SelectRaceStart();
}

static int(__cdecl*original_SuggestRace)() = (int(__cdecl*)())0x0045140b;
CARM95_HOOK_FUNCTION(original_SuggestRace, SuggestRace)
int __cdecl SuggestRace() {
    int i;
    int least_done;
    int suggested_so_far;
    int suggested_race;
    int new_suggestion;
    int number_of_visits;
    LOG_TRACE("()");

    (void)i;
    (void)least_done;
    (void)suggested_so_far;
    (void)suggested_race;
    (void)new_suggestion;
    (void)number_of_visits;

    return original_SuggestRace();
}

static void(__cdecl*original_SelectRaceDraw)(int, int) = (void(__cdecl*)(int, int))0x00451634;
CARM95_HOOK_FUNCTION(original_SelectRaceDraw, SelectRaceDraw)
void __cdecl SelectRaceDraw(int pCurrent_choice, int pCurrent_mode) {
    tOpponent *the_opponent;
    tText_chunk *the_chunk;
    int j;
    int k;
    int y_coord;
    char s[256];
    char temp_str[256];
    char *sub_pt;
    char sub_str[16];
    tU32 *test;
    static tU32 test2;
    char __block0__s[128];
    FILE *__block0__f;
    int __block0__i;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)the_opponent;
    (void)the_chunk;
    (void)j;
    (void)k;
    (void)y_coord;
    (void)s;
    (void)temp_str;
    (void)sub_pt;
    (void)sub_str;
    (void)test;
    (void)test2;
    (void)__block0__s;
    (void)__block0__f;
    (void)__block0__i;

    original_SelectRaceDraw(pCurrent_choice, pCurrent_mode);
}

static tSO_result(__cdecl*original_DoSelectRace)(int *) = (tSO_result(__cdecl*)(int *))0x00451c8e;
CARM95_HOOK_FUNCTION(original_DoSelectRace, DoSelectRace)
tSO_result __cdecl DoSelectRace(int *pSecond_time_around) {
    static tFlicette flicker_on[7];
    static tFlicette flicker_off[7];
    static tFlicette push[7];
    static tMouse_area mouse_areas[7];
    static tInterface_spec interface_spec;
    int result;
    int default_choice;
    int suggested;
    int old_current_race;
    LOG_TRACE("(%p)", pSecond_time_around);

    (void)pSecond_time_around;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;
    (void)default_choice;
    (void)suggested;
    (void)old_current_race;

    return original_DoSelectRace(pSecond_time_around);
}

static void(__cdecl*original_DrawGridCar)(int, int, br_pixelmap *) = (void(__cdecl*)(int, int, br_pixelmap *))0x00452b89;
CARM95_HOOK_FUNCTION(original_DrawGridCar, DrawGridCar)
void __cdecl DrawGridCar(int pX, int pY, br_pixelmap *pImage) {
    LOG_TRACE("(%d, %d, %p)", pX, pY, pImage);

    (void)pX;
    (void)pY;
    (void)pImage;

    original_DrawGridCar(pX, pY, pImage);
}

static void(__cdecl*original_DrawGrid)(int, int) = (void(__cdecl*)(int, int))0x00452077;
CARM95_HOOK_FUNCTION(original_DrawGrid, DrawGrid)
void __cdecl DrawGrid(int pOffset, int pDraw_it) {
    int i;
    int j;
    int y;
    int x;
    int str_x;
    int width_job;
    int done_highest;
    int str_index;
    int swap_1_x;
    int swap_1_y;
    int swap_2_x;
    int swap_2_y;
    br_pixelmap *the_image;
    br_pixelmap *swap_1_image;
    br_pixelmap *swap_2_image;
    char numbers_str[4][100];
    char total_str[256];
    tU32 the_time;
    LOG_TRACE("(%d, %d)", pOffset, pDraw_it);

    (void)pOffset;
    (void)pDraw_it;
    (void)i;
    (void)j;
    (void)y;
    (void)x;
    (void)str_x;
    (void)width_job;
    (void)done_highest;
    (void)str_index;
    (void)swap_1_x;
    (void)swap_1_y;
    (void)swap_2_x;
    (void)swap_2_y;
    (void)the_image;
    (void)swap_1_image;
    (void)swap_2_image;
    (void)numbers_str;
    (void)total_str;
    (void)the_time;

    original_DrawGrid(pOffset, pDraw_it);
}

static void(__cdecl*original_MoveGrid)(int, int, tS32) = (void(__cdecl*)(int, int, tS32))0x004531d4;
CARM95_HOOK_FUNCTION(original_MoveGrid, MoveGrid)
void __cdecl MoveGrid(int pFrom, int pTo, tS32 pTime_to_move) {
    tS32 start_time;
    tS32 the_time;
    int move_distance;
    int pitch;
    LOG_TRACE("(%d, %d, %d)", pFrom, pTo, pTime_to_move);

    (void)pFrom;
    (void)pTo;
    (void)pTime_to_move;
    (void)start_time;
    (void)the_time;
    (void)move_distance;
    (void)pitch;

    original_MoveGrid(pFrom, pTo, pTime_to_move);
}

static int(__cdecl*original_CalcGridOffset)(int) = (int(__cdecl*)(int))0x00452bf3;
CARM95_HOOK_FUNCTION(original_CalcGridOffset, CalcGridOffset)
int __cdecl CalcGridOffset(int pPosition) {
    LOG_TRACE("(%d)", pPosition);

    (void)pPosition;

    return original_CalcGridOffset(pPosition);
}

static void(__cdecl*original_GridDraw)(int, int) = (void(__cdecl*)(int, int))0x00452039;
CARM95_HOOK_FUNCTION(original_GridDraw, GridDraw)
void __cdecl GridDraw(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_GridDraw(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_ActuallySwapOrder)(int, int) = (void(__cdecl*)(int, int))0x00453255;
CARM95_HOOK_FUNCTION(original_ActuallySwapOrder, ActuallySwapOrder)
void __cdecl ActuallySwapOrder(int pFirst_index, int pSecond_index) {
    tOpp_spec temp_opp;
    LOG_TRACE("(%d, %d)", pFirst_index, pSecond_index);

    (void)pFirst_index;
    (void)pSecond_index;
    (void)temp_opp;

    original_ActuallySwapOrder(pFirst_index, pSecond_index);
}

static void(__cdecl*original_DoGridTransition)(int, int) = (void(__cdecl*)(int, int))0x004530ca;
CARM95_HOOK_FUNCTION(original_DoGridTransition, DoGridTransition)
void __cdecl DoGridTransition(int pFirst_index, int pSecond_index) {
    tU32 start_time;
    tU32 the_time;
    LOG_TRACE("(%d, %d)", pFirst_index, pSecond_index);

    (void)pFirst_index;
    (void)pSecond_index;
    (void)start_time;
    (void)the_time;

    original_DoGridTransition(pFirst_index, pSecond_index);
}

static void(__cdecl*original_ChallengeStart)() = (void(__cdecl*)())0x00452c0c;
CARM95_HOOK_FUNCTION(original_ChallengeStart, ChallengeStart)
void __cdecl ChallengeStart() {
    br_pixelmap *the_map;
    int i;
    int j;
    int line_count;
    int dare_index;
    FILE *f;
    tPath_name the_path;
    char s[256];
    LOG_TRACE("()");

    (void)the_map;
    (void)i;
    (void)j;
    (void)line_count;
    (void)dare_index;
    (void)f;
    (void)the_path;
    (void)s;

    original_ChallengeStart();
}

static int(__cdecl*original_CheckNextStage)(int *, int *) = (int(__cdecl*)(int *, int *))0x00453021;
CARM95_HOOK_FUNCTION(original_CheckNextStage, CheckNextStage)
int __cdecl CheckNextStage(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_CheckNextStage(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_ChallengeDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004532f7;
CARM95_HOOK_FUNCTION(original_ChallengeDone, ChallengeDone)
int __cdecl ChallengeDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_ChallengeDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(__cdecl*original_DoChallengeScreen)() = (void(__cdecl*)())0x00453952;
CARM95_HOOK_FUNCTION(original_DoChallengeScreen, DoChallengeScreen)
void __cdecl DoChallengeScreen() {
    static tFlicette flicker_on[2];
    static tFlicette flicker_off[2];
    static tFlicette push[2];
    static tMouse_area mouse_areas[2];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    original_DoChallengeScreen();
}

static int(__cdecl*original_GridDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004533c6;
CARM95_HOOK_FUNCTION(original_GridDone, GridDone)
int __cdecl GridDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_GridDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(__cdecl*original_GridStart)() = (void(__cdecl*)())0x00453408;
CARM95_HOOK_FUNCTION(original_GridStart, GridStart)
void __cdecl GridStart() {
    LOG_TRACE("()");


    original_GridStart();
}

static int(__cdecl*original_GridMoveLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x00453440;
CARM95_HOOK_FUNCTION(original_GridMoveLeft, GridMoveLeft)
int __cdecl GridMoveLeft(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_GridMoveLeft(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_GridMoveRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x004534e7;
CARM95_HOOK_FUNCTION(original_GridMoveRight, GridMoveRight)
int __cdecl GridMoveRight(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_GridMoveRight(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_GridClickCar)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x00453578;
CARM95_HOOK_FUNCTION(original_GridClickCar, GridClickCar)
int __cdecl GridClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int rel_pos;
    int new_pos;
    int base_pos;
    int x_coord;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)rel_pos;
    (void)new_pos;
    (void)base_pos;
    (void)x_coord;

    return original_GridClickCar(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_GridClickNumbers)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x00453671;
CARM95_HOOK_FUNCTION(original_GridClickNumbers, GridClickNumbers)
int __cdecl GridClickNumbers(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int new_pos;
    int i;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)new_pos;
    (void)i;

    return original_GridClickNumbers(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_GridClickLeft)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x00453746;
CARM95_HOOK_FUNCTION(original_GridClickLeft, GridClickLeft)
int __cdecl GridClickLeft(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_GridClickLeft(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_GridClickRight)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x00453768;
CARM95_HOOK_FUNCTION(original_GridClickRight, GridClickRight)
int __cdecl GridClickRight(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;

    return original_GridClickRight(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(__cdecl*original_CheckChallenge)(int *, int *) = (int(__cdecl*)(int *, int *))0x0045378a;
CARM95_HOOK_FUNCTION(original_CheckChallenge, CheckChallenge)
int __cdecl CheckChallenge(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_CheckChallenge(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_FindBestPos)(int) = (int(__cdecl*)(int))0x00453b41;
CARM95_HOOK_FUNCTION(original_FindBestPos, FindBestPos)
int __cdecl FindBestPos(int pOur_rank) {
    int i;
    LOG_TRACE("(%d)", pOur_rank);

    (void)pOur_rank;
    (void)i;

    return original_FindBestPos(pOur_rank);
}

static int(__cdecl*original_SortGridFunction)(void *, void *) = (int(__cdecl*)(void *, void *))0x004537d2;
CARM95_HOOK_FUNCTION(original_SortGridFunction, SortGridFunction)
int __cdecl SortGridFunction(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    return original_SortGridFunction(pFirst_one, pSecond_one);
}

static void(__cdecl*original_SortOpponents)() = (void(__cdecl*)())0x004539f6;
CARM95_HOOK_FUNCTION(original_SortOpponents, SortOpponents)
void __cdecl SortOpponents() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_SortOpponents();
}

static tSO_result(__cdecl*original_DoGridPosition)() = (tSO_result(__cdecl*)())0x004537ee;
CARM95_HOOK_FUNCTION(original_DoGridPosition, DoGridPosition)
tSO_result __cdecl DoGridPosition() {
    static tFlicette flicker_on[3];
    static tFlicette flicker_off[3];
    static tFlicette push[3];
    static tMouse_area mouse_areas[5];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    return original_DoGridPosition();
}

static void(__cdecl*original_CheckPlayersAreResponding)() = (void(__cdecl*)())0x00453ba4;
CARM95_HOOK_FUNCTION(original_CheckPlayersAreResponding, CheckPlayersAreResponding)
void __cdecl CheckPlayersAreResponding() {
    int i;
    tU32 time;
    tNet_message *message;
    LOG_TRACE("()");

    (void)i;
    (void)time;
    (void)message;

    original_CheckPlayersAreResponding();
}

static void(__cdecl*original_NetSynchStartStart)() = (void(__cdecl*)())0x00453b94;
CARM95_HOOK_FUNCTION(original_NetSynchStartStart, NetSynchStartStart)
void __cdecl NetSynchStartStart() {
    LOG_TRACE("()");


    original_NetSynchStartStart();
}

static void(__cdecl*original_DrawAnItem__racestrt)(int, int, int, char *) = (void(__cdecl*)(int, int, int, char *))0x00453fc0;
CARM95_HOOK_FUNCTION(original_DrawAnItem__racestrt, DrawAnItem__racestrt)
void __cdecl DrawAnItem__racestrt(int pX, int pY_index, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, \"%s\")", pX, pY_index, pFont_index, pText);

    (void)pX;
    (void)pY_index;
    (void)pFont_index;
    (void)pText;

    original_DrawAnItem__racestrt(pX, pY_index, pFont_index, pText);
}

static void(__cdecl*original_NetSynchStartDraw)(int, int) = (void(__cdecl*)(int, int))0x00453c5b;
CARM95_HOOK_FUNCTION(original_NetSynchStartDraw, NetSynchStartDraw)
void __cdecl NetSynchStartDraw(int pCurrent_choice, int pCurrent_mode) {
    int i;
    int number_ready;
    char s[256];
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)number_ready;
    (void)s;

    original_NetSynchStartDraw(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_NetSynchStartDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x00454007;
CARM95_HOOK_FUNCTION(original_NetSynchStartDone, NetSynchStartDone)
int __cdecl NetSynchStartDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_NetSynchStartDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(__cdecl*original_NetSynchStartGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x00454047;
CARM95_HOOK_FUNCTION(original_NetSynchStartGoAhead, NetSynchStartGoAhead)
int __cdecl NetSynchStartGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetSynchStartGoAhead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_ExitWhenReady)(int *, int *) = (int(__cdecl*)(int *, int *))0x0045412d;
CARM95_HOOK_FUNCTION(original_ExitWhenReady, ExitWhenReady)
int __cdecl ExitWhenReady(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_ExitWhenReady(pCurrent_choice, pCurrent_mode);
}

static tSO_result(__cdecl*original_NetSynchRaceStart2)(tNet_synch_mode) = (tSO_result(__cdecl*)(tNet_synch_mode))0x00454196;
CARM95_HOOK_FUNCTION(original_NetSynchRaceStart2, NetSynchRaceStart2)
tSO_result __cdecl NetSynchRaceStart2(tNet_synch_mode pMode) {
    static tFlicette flicker_on_hf[2];
    static tFlicette flicker_off_hf[2];
    static tFlicette push_hf[2];
    static tMouse_area mouse_areas_hf[2];
    static tInterface_spec interface_spec_hf;
    static tFlicette flicker_on_hs[1];
    static tFlicette flicker_off_hs[1];
    static tFlicette push_hs[1];
    static tMouse_area mouse_areas_hs[1];
    static tInterface_spec interface_spec_hs;
    static tFlicette flicker_on_c[1];
    static tFlicette flicker_off_c[1];
    static tFlicette push_c[1];
    static tMouse_area mouse_areas_c[1];
    static tInterface_spec interface_spec_c;
    int result;
    LOG_TRACE("(%d)", pMode);

    (void)pMode;
    (void)flicker_on_hf;
    (void)flicker_off_hf;
    (void)push_hf;
    (void)mouse_areas_hf;
    (void)interface_spec_hf;
    (void)flicker_on_hs;
    (void)flicker_off_hs;
    (void)push_hs;
    (void)mouse_areas_hs;
    (void)interface_spec_hs;
    (void)flicker_on_c;
    (void)flicker_off_c;
    (void)push_c;
    (void)mouse_areas_c;
    (void)interface_spec_c;
    (void)result;

    return original_NetSynchRaceStart2(pMode);
}

static tSO_result(__cdecl*original_NetSynchRaceStart)() = (tSO_result(__cdecl*)())0x004542c4;
CARM95_HOOK_FUNCTION(original_NetSynchRaceStart, NetSynchRaceStart)
tSO_result __cdecl NetSynchRaceStart() {
    LOG_TRACE("()");


    return original_NetSynchRaceStart();
}

