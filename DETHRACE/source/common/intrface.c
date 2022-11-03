#include "intrface.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int(* hookvar_gDisabled_choices )[10] = (void*)0x0053a4d8;
int * hookvar_gCurrent_mode  = (void*)0x0053a500;
tU32 * hookvar_gStart_time  = (void*)0x0053a508;
int * hookvar_gCurrent_choice  = (void*)0x0053a504;
tInterface_spec ** hookvar_gSpec  = (void*)0x0053a4c8;
int * hookvar_gAlways_typing  = (void*)0x0053a4d0;
int * hookvar_gDisabled_count  = (void*)0x0053a4cc;

function_hook_state_t function_hook_state_SetAlwaysTyping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetAlwaysTyping, function_hook_state_SetAlwaysTyping)
static void(__cdecl*original_SetAlwaysTyping)() = (void(__cdecl*)())0x004735b0;
CARM95_HOOK_FUNCTION(original_SetAlwaysTyping, SetAlwaysTyping)
void __cdecl SetAlwaysTyping() {
    LOG_TRACE("()");


    if (function_hook_state_SetAlwaysTyping == HOOK_ENABLED) {
        assert(0 && "SetAlwaysTyping not implemented.");
        abort();
    } else {
        original_SetAlwaysTyping();
    }
}

function_hook_state_t function_hook_state_ClearAlwaysTyping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ClearAlwaysTyping, function_hook_state_ClearAlwaysTyping)
static void(__cdecl*original_ClearAlwaysTyping)() = (void(__cdecl*)())0x004735c5;
CARM95_HOOK_FUNCTION(original_ClearAlwaysTyping, ClearAlwaysTyping)
void __cdecl ClearAlwaysTyping() {
    LOG_TRACE("()");


    if (function_hook_state_ClearAlwaysTyping == HOOK_ENABLED) {
        assert(0 && "ClearAlwaysTyping not implemented.");
        abort();
    } else {
        original_ClearAlwaysTyping();
    }
}

function_hook_state_t function_hook_state_ChoiceDisabled = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChoiceDisabled, function_hook_state_ChoiceDisabled)
static int(__cdecl*original_ChoiceDisabled)(int) = (int(__cdecl*)(int))0x00475027;
CARM95_HOOK_FUNCTION(original_ChoiceDisabled, ChoiceDisabled)
int __cdecl ChoiceDisabled(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    if (function_hook_state_ChoiceDisabled == HOOK_ENABLED) {
        assert(0 && "ChoiceDisabled not implemented.");
        abort();
    } else {
        return original_ChoiceDisabled(pChoice);
    }
}

function_hook_state_t function_hook_state_ResetInterfaceTimeout = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetInterfaceTimeout, function_hook_state_ResetInterfaceTimeout)
static void(__cdecl*original_ResetInterfaceTimeout)() = (void(__cdecl*)())0x004735da;
CARM95_HOOK_FUNCTION(original_ResetInterfaceTimeout, ResetInterfaceTimeout)
void __cdecl ResetInterfaceTimeout() {
    LOG_TRACE("()");


    if (function_hook_state_ResetInterfaceTimeout == HOOK_ENABLED) {
        assert(0 && "ResetInterfaceTimeout not implemented.");
        abort();
    } else {
        original_ResetInterfaceTimeout();
    }
}

function_hook_state_t function_hook_state_ChangeSelection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChangeSelection, function_hook_state_ChangeSelection)
static void(__cdecl*original_ChangeSelection)(tInterface_spec *, int *, int *, int, int) = (void(__cdecl*)(tInterface_spec *, int *, int *, int, int))0x00474d84;
CARM95_HOOK_FUNCTION(original_ChangeSelection, ChangeSelection)
void __cdecl ChangeSelection(tInterface_spec *pSpec, int *pOld_selection, int *pNew_selection, int pMode, int pSkip_disabled) {
    int i;
    LOG_TRACE("(%p, %p, %p, %d, %d)", pSpec, pOld_selection, pNew_selection, pMode, pSkip_disabled);

    (void)pSpec;
    (void)pOld_selection;
    (void)pNew_selection;
    (void)pMode;
    (void)pSkip_disabled;
    (void)i;

    if (function_hook_state_ChangeSelection == HOOK_ENABLED) {
        assert(0 && "ChangeSelection not implemented.");
        abort();
    } else {
        original_ChangeSelection(pSpec, pOld_selection, pNew_selection, pMode, pSkip_disabled);
    }
}

function_hook_state_t function_hook_state_RecopyAreas = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RecopyAreas, function_hook_state_RecopyAreas)
static void(__cdecl*original_RecopyAreas)(tInterface_spec *, br_pixelmap **) = (void(__cdecl*)(tInterface_spec *, br_pixelmap **))0x0047507b;
CARM95_HOOK_FUNCTION(original_RecopyAreas, RecopyAreas)
void __cdecl RecopyAreas(tInterface_spec *pSpec, br_pixelmap **pCopy_areas) {
    int i;
    LOG_TRACE("(%p, %p)", pSpec, pCopy_areas);

    (void)pSpec;
    (void)pCopy_areas;
    (void)i;

    if (function_hook_state_RecopyAreas == HOOK_ENABLED) {
        assert(0 && "RecopyAreas not implemented.");
        abort();
    } else {
        original_RecopyAreas(pSpec, pCopy_areas);
    }
}

function_hook_state_t function_hook_state_DisableChoice = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisableChoice, function_hook_state_DisableChoice)
static void(__cdecl*original_DisableChoice)(int) = (void(__cdecl*)(int))0x004735ef;
CARM95_HOOK_FUNCTION(original_DisableChoice, DisableChoice)
void __cdecl DisableChoice(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    if (function_hook_state_DisableChoice == HOOK_ENABLED) {
        assert(0 && "DisableChoice not implemented.");
        abort();
    } else {
        original_DisableChoice(pChoice);
    }
}

function_hook_state_t function_hook_state_EnableChoice = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EnableChoice, function_hook_state_EnableChoice)
static void(__cdecl*original_EnableChoice)(int) = (void(__cdecl*)(int))0x0047364d;
CARM95_HOOK_FUNCTION(original_EnableChoice, EnableChoice)
void __cdecl EnableChoice(int pChoice) {
    int i;
    LOG_TRACE("(%d)", pChoice);

    (void)pChoice;
    (void)i;

    if (function_hook_state_EnableChoice == HOOK_ENABLED) {
        assert(0 && "EnableChoice not implemented.");
        abort();
    } else {
        original_EnableChoice(pChoice);
    }
}

function_hook_state_t function_hook_state_DoInterfaceScreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoInterfaceScreen, function_hook_state_DoInterfaceScreen)
static int(__cdecl*original_DoInterfaceScreen)(tInterface_spec *, int, int) = (int(__cdecl*)(tInterface_spec *, int, int))0x004736cc;
CARM95_HOOK_FUNCTION(original_DoInterfaceScreen, DoInterfaceScreen)
int __cdecl DoInterfaceScreen(tInterface_spec *pSpec, int pOptions, int pCurrent_choice) {
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

    if (function_hook_state_DoInterfaceScreen == HOOK_ENABLED) {
        assert(0 && "DoInterfaceScreen not implemented.");
        abort();
    } else {
        return original_DoInterfaceScreen(pSpec, pOptions, pCurrent_choice);
    }
}

function_hook_state_t function_hook_state_ChangeSelectionTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChangeSelectionTo, function_hook_state_ChangeSelectionTo)
static void(__cdecl*original_ChangeSelectionTo)(int, int) = (void(__cdecl*)(int, int))0x00475175;
CARM95_HOOK_FUNCTION(original_ChangeSelectionTo, ChangeSelectionTo)
void __cdecl ChangeSelectionTo(int pNew_choice, int pNew_mode) {
    int last_choice;
    LOG_TRACE("(%d, %d)", pNew_choice, pNew_mode);

    (void)pNew_choice;
    (void)pNew_mode;
    (void)last_choice;

    if (function_hook_state_ChangeSelectionTo == HOOK_ENABLED) {
        assert(0 && "ChangeSelectionTo not implemented.");
        abort();
    } else {
        original_ChangeSelectionTo(pNew_choice, pNew_mode);
    }
}

