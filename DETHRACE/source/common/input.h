#ifndef _INPUT_H_
#define _INPUT_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gEdge_trigger_mode ; // addr: 00514C70
extern tU32 * hookvar_gLast_poll_keys ; // addr: 00514C74
extern int * hookvar_gInsert_mode ; // addr: 00514C78
extern int(* hookvar_gGo_ahead_keys )[3]; // addr: 00514C80
extern tJoy_array * hookvar_gJoy_array ; // addr: 005505F4
extern tKey_array * hookvar_gKey_array ; // addr: 0053A250
extern int * hookvar_gKey_poll_counter ; // addr: 0053A248
extern tRolling_letter ** hookvar_gRolling_letters ; // addr: 0053A1F8
extern int * hookvar_gCurrent_cursor ; // addr: 0053A440
extern int * hookvar_gCurrent_position ; // addr: 0053A4C0
extern int(* hookvar_gLetter_x_coords )[15]; // addr: 0053A200
extern int * hookvar_gVisible_length ; // addr: 0053A240
extern int(* hookvar_gLetter_y_coords )[15]; // addr: 0053A1B8
// extern int * hookvar_gThe_key ;
extern tU32 * hookvar_gLast_key_down_time ; // addr: 0053A444
extern int * hookvar_gThe_length ; // addr: 0053A1F4
extern tU32 * hookvar_gLast_roll ; // addr: 0053A448
extern int * hookvar_gLast_key_down ; // addr: 0053A244
extern int(* hookvar_gKey_mapping )[67]; // addr: 005507E0
extern char(* hookvar_gCurrent_typing )[110]; // addr: 0053A450

void SetJoystickArrays(int *pKeys, int pMark);

void PollKeys();

void CyclePollKeys();

void ResetPollKeys();

void CheckKeysForMouldiness();

int EitherMouseButtonDown();

tKey_down_result PDKeyDown2(int pKey_index);

int PDKeyDown(int pKey_index);

int PDKeyDown3(int pKey_index);

int PDAnyKeyDown();

int AnyKeyDown();

tU32* KevKeyService();

int OldKeyIsDown(int pKey_index);

int KeyIsDown(int pKey_index);

void WaitForNoKeys();

void WaitForAKey();

int CmdKeyDown(int pFKey_ID, int pCmd_key_ID);

void GetMousePosition(int *pX_coord, int *pY_coord);

void InitRollingLetters();

void EndRollingLetters();

int AddRollingLetter(char pChar, int pX, int pY, tRolling_type rolling_type);

void AddRollingString(char *pStr, int pX, int pY, tRolling_type rolling_type);

void AddRollingNumber(tU32 pNumber, int pWidth, int pX, int pY);

void RollLettersIn();

int ChangeCharTo(int pSlot_index, int pChar_index, char pNew_char);

void ChangeTextTo(int pXcoord, int pYcoord, char *pNew_str, char *pOld_str);

void SetRollingCursor(int pSlot_index);

void BlankSlot(int pIndex, int pName_length, int pVisible_length);

void DoRLBackspace(int pSlot_index);

void DoRLDelete(int pSlot_index);

void DoRLInsert(int pSlot_index);

void DoRLCursorLeft(int pSlot_index);

void DoRLCursorRight(int pSlot_index);

void DoRLTypeLetter(int pChar, int pSlot_index);

void StopTyping(int pSlot_index);

void RevertTyping(int pSlot_index, char *pRevert_str);

void StartTyping(int pSlot_index, char *pText, int pVisible_length);

void TypeKey(int pSlot_index, char pKey);

void SetSlotXY(int pSlot_index, int pX_coord, int pY_coord);

void GetTypedName(char *pDestn, int pMax_length);

void KillCursor(int pSlot_index);

void EdgeTriggerModeOn();

void EdgeTriggerModeOff();

#endif
