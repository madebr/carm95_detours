#include "cutscene.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
#if 0
tS32 * hookvar_gLast_demo_end_anim ;
#endif

void* radmalloc(unsigned long numbytes) {
    unsigned char *temp;
    unsigned char i;
    LOG_TRACE("(%u)", numbytes);

    (void)numbytes;
    (void)temp;
    (void)i;

    NOT_IMPLEMENTED();
}

void radfree(void *ptr) {
    LOG_TRACE("(%p)", ptr);

    (void)ptr;

    NOT_IMPLEMENTED();
}

static void(*original_ShowCutScene)(int, int, int, br_scalar, ...) = (void(*)(int, int, int, br_scalar, ...))0x004a58c0;
CARM95_HOOK_FUNCTION(original_ShowCutScene, ShowCutScene)
void ShowCutScene(int pIndex, int pWait_end, int pSound_ID, br_scalar pDelay) {
    LOG_TRACE("(%d, %d, %d, %f)", pIndex, pWait_end, pSound_ID, pDelay);

    (void)pIndex;
    (void)pWait_end;
    (void)pSound_ID;
    (void)pDelay;

    original_ShowCutScene(pIndex, pWait_end, pSound_ID, pDelay);
}

static void(*original_DoSCILogo)() = (void(*)())0x004a5974;
CARM95_HOOK_FUNCTION(original_DoSCILogo, DoSCILogo)
void DoSCILogo() {
    LOG_TRACE("()");


    original_DoSCILogo();
}

static void(*original_DoStainlessLogo)() = (void(*)())0x004a597f;
CARM95_HOOK_FUNCTION(original_DoStainlessLogo, DoStainlessLogo)
void DoStainlessLogo() {
    LOG_TRACE("()");


    original_DoStainlessLogo();
}

static void(*original_PlaySmackerFile)(char *, ...) = (void(*)(char *, ...))0x004a598a;
CARM95_HOOK_FUNCTION(original_PlaySmackerFile, PlaySmackerFile)
void PlaySmackerFile(char *pSmack_name) {
    tPath_name the_path;
    br_colour *br_colours_ptr;
    tU8 *smack_colours_ptr;
    Smack *smk;
    int i;
    int j;
    int len;
    int fuck_off;
    LOG_TRACE("(\"%s\")", pSmack_name);

    (void)pSmack_name;
    (void)the_path;
    (void)br_colours_ptr;
    (void)smack_colours_ptr;
    (void)smk;
    (void)i;
    (void)j;
    (void)len;
    (void)fuck_off;

    original_PlaySmackerFile(pSmack_name);
}

static void(*original_DoOpeningAnimation)() = (void(*)())0x004a5d73;
CARM95_HOOK_FUNCTION(original_DoOpeningAnimation, DoOpeningAnimation)
void DoOpeningAnimation() {
    LOG_TRACE("()");


    original_DoOpeningAnimation();
}

static void(*original_DoNewGameAnimation)() = (void(*)())0x004a5de6;
CARM95_HOOK_FUNCTION(original_DoNewGameAnimation, DoNewGameAnimation)
void DoNewGameAnimation() {
    LOG_TRACE("()");


    original_DoNewGameAnimation();
}

static void(*original_DoGoToRaceAnimation)() = (void(*)())0x004a5d9d;
CARM95_HOOK_FUNCTION(original_DoGoToRaceAnimation, DoGoToRaceAnimation)
void DoGoToRaceAnimation() {
    LOG_TRACE("()");


    original_DoGoToRaceAnimation();
}

static void(*original_DoEndRaceAnimation)() = (void(*)())0x004a5df1;
CARM95_HOOK_FUNCTION(original_DoEndRaceAnimation, DoEndRaceAnimation)
void DoEndRaceAnimation() {
    int made_a_profit;
    int went_up_a_rank;
    LOG_TRACE("()");

    (void)made_a_profit;
    (void)went_up_a_rank;

    original_DoEndRaceAnimation();
}

static void(*original_DoGameOverAnimation)() = (void(*)())0x004a5ed6;
CARM95_HOOK_FUNCTION(original_DoGameOverAnimation, DoGameOverAnimation)
void DoGameOverAnimation() {
    LOG_TRACE("()");


    original_DoGameOverAnimation();
}

static void(*original_DoGameCompletedAnimation)() = (void(*)())0x004a5ef8;
CARM95_HOOK_FUNCTION(original_DoGameCompletedAnimation, DoGameCompletedAnimation)
void DoGameCompletedAnimation() {
    LOG_TRACE("()");


    original_DoGameCompletedAnimation();
}

static void(*original_StartLoadingScreen)() = (void(*)())0x004a5f1a;
CARM95_HOOK_FUNCTION(original_StartLoadingScreen, StartLoadingScreen)
void StartLoadingScreen() {
    LOG_TRACE("()");


    original_StartLoadingScreen();
}

