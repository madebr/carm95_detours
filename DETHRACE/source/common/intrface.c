#include "intrface.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
int(* hookvar_gDisabled_choices )[10] = (void*)0x0053a4d8;
int * hookvar_gCurrent_mode  = (void*)0x0053a500;
tU32 * hookvar_gStart_time  = (void*)0x0053a508;
int * hookvar_gCurrent_choice  = (void*)0x0053a504;
tInterface_spec ** hookvar_gSpec  = (void*)0x0053a4c8;
int * hookvar_gAlways_typing  = (void*)0x0053a4d0;
int * hookvar_gDisabled_count  = (void*)0x0053a4cc;

static void(*original_SetAlwaysTyping)() = (void(*)())0x004735b0;
CARM95_HOOK_FUNCTION(original_SetAlwaysTyping, SetAlwaysTyping)
void SetAlwaysTyping() {
    LOG_TRACE("()");


    original_SetAlwaysTyping();
}

static void(*original_ClearAlwaysTyping)() = (void(*)())0x004735c5;
CARM95_HOOK_FUNCTION(original_ClearAlwaysTyping, ClearAlwaysTyping)
void ClearAlwaysTyping() {
    LOG_TRACE("()");


    original_ClearAlwaysTyping();
}

static int(*original_ChoiceDisabled)(int, ...) = (int(*)(int, ...))0x00475027;
CARM95_HOOK_FUNCTION(original_ChoiceDisabled, ChoiceDisabled)
int ChoiceDisabled(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    return original_ChoiceDisabled(pChoice);
}

static void(*original_ResetInterfaceTimeout)() = (void(*)())0x004735da;
CARM95_HOOK_FUNCTION(original_ResetInterfaceTimeout, ResetInterfaceTimeout)
void ResetInterfaceTimeout() {
    LOG_TRACE("()");


    original_ResetInterfaceTimeout();
}

static void(*original_ChangeSelection)(tInterface_spec *, int *, int *, int, int, ...) = (void(*)(tInterface_spec *, int *, int *, int, int, ...))0x00474d84;
CARM95_HOOK_FUNCTION(original_ChangeSelection, ChangeSelection)
void ChangeSelection(tInterface_spec *pSpec, int *pOld_selection, int *pNew_selection, int pMode, int pSkip_disabled) {
    int i;
    LOG_TRACE("(%p, %p, %p, %d, %d)", pSpec, pOld_selection, pNew_selection, pMode, pSkip_disabled);

    (void)pSpec;
    (void)pOld_selection;
    (void)pNew_selection;
    (void)pMode;
    (void)pSkip_disabled;
    (void)i;

    original_ChangeSelection(pSpec, pOld_selection, pNew_selection, pMode, pSkip_disabled);
}

static void(*original_RecopyAreas)(tInterface_spec *, br_pixelmap **, ...) = (void(*)(tInterface_spec *, br_pixelmap **, ...))0x0047507b;
CARM95_HOOK_FUNCTION(original_RecopyAreas, RecopyAreas)
void RecopyAreas(tInterface_spec *pSpec, br_pixelmap **pCopy_areas) {
    int i;
    LOG_TRACE("(%p, %p)", pSpec, pCopy_areas);

    (void)pSpec;
    (void)pCopy_areas;
    (void)i;

    original_RecopyAreas(pSpec, pCopy_areas);
}

static void(*original_DisableChoice)(int, ...) = (void(*)(int, ...))0x004735ef;
CARM95_HOOK_FUNCTION(original_DisableChoice, DisableChoice)
void DisableChoice(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    original_DisableChoice(pChoice);
}

static void(*original_EnableChoice)(int, ...) = (void(*)(int, ...))0x0047364d;
CARM95_HOOK_FUNCTION(original_EnableChoice, EnableChoice)
void EnableChoice(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    original_EnableChoice(pChoice);
}

static int(*original_DoInterfaceScreen)(tInterface_spec *, int, int, ...) = (int(*)(tInterface_spec *, int, int, ...))0x004736cc;
CARM95_HOOK_FUNCTION(original_DoInterfaceScreen, DoInterfaceScreen)
int DoInterfaceScreen(tInterface_spec *pSpec, int pOptions, int pCurrent_choice) {
    tProg_status entry_status;
    int x_coord;
    int y_coord;
    int mouse_in_somewhere;
    int i;
    int key2;
    int mouse_was_started;
    int last_choice;
    int escaped;
    int timed_out;
    int go_ahead;
    int last_mode;
    int result;
    int the_key;
    int the_max;
    int mouse_down;
    int new_mouse_down;
    int last_mouse_down;
    int defeat_mode_change;
    int selection_changed;
    char the_str[256];
    tU32 last_press;
    tU32 last_left_press;
    tU32 last_right_press;
    tU32 last_up_press;
    tU32 last_down_press;
    br_pixelmap **copy_areas;
    br_pixelmap *old_current_splash;
    void *pixels_copy;
    void *palette_copy;
    LOG_TRACE("(%p, %d, %d)", pSpec, pOptions, pCurrent_choice);

    (void)pSpec;
    (void)pOptions;
    (void)pCurrent_choice;
    (void)entry_status;
    (void)x_coord;
    (void)y_coord;
    (void)mouse_in_somewhere;
    (void)i;
    (void)key2;
    (void)mouse_was_started;
    (void)last_choice;
    (void)escaped;
    (void)timed_out;
    (void)go_ahead;
    (void)last_mode;
    (void)result;
    (void)the_key;
    (void)the_max;
    (void)mouse_down;
    (void)new_mouse_down;
    (void)last_mouse_down;
    (void)defeat_mode_change;
    (void)selection_changed;
    (void)the_str;
    (void)last_press;
    (void)last_left_press;
    (void)last_right_press;
    (void)last_up_press;
    (void)last_down_press;
    (void)copy_areas;
    (void)old_current_splash;
    (void)pixels_copy;
    (void)palette_copy;

    return original_DoInterfaceScreen(pSpec, pOptions, pCurrent_choice);
}

static void(*original_ChangeSelectionTo)(int, int, ...) = (void(*)(int, int, ...))0x00475175;
CARM95_HOOK_FUNCTION(original_ChangeSelectionTo, ChangeSelectionTo)
void ChangeSelectionTo(int pNew_choice, int pNew_mode) {
    int last_choice;
    LOG_TRACE("(%d, %d)", pNew_choice, pNew_mode);

    (void)pNew_choice;
    (void)pNew_mode;
    (void)last_choice;

    original_ChangeSelectionTo(pNew_choice, pNew_mode);
}

