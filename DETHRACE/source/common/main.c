#include "main.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void(__cdecl*original_QuitGame)() = (void(__cdecl*)())0x004a9ea0;
CARM95_HOOK_FUNCTION(original_QuitGame, QuitGame)
void __cdecl QuitGame() {
    LOG_TRACE("()");


    original_QuitGame();
}

tU32 TrackCount(br_actor *pActor, tU32 *pCount) {
    unsigned int x;
    unsigned int z;
    int ad;
    float e;
    LOG_TRACE("(%p, %p)", pActor, pCount);

    (void)pActor;
    (void)pCount;
    (void)x;
    (void)z;
    (void)ad;
    (void)e;

    NOT_IMPLEMENTED();
}

void CheckNumberOfTracks() {
    tU32 track_count;
    LOG_TRACE("()");

    (void)track_count;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_ServiceTheGame)(int) = (void(__cdecl*)(int))0x004a9f29;
CARM95_HOOK_FUNCTION(original_ServiceTheGame, ServiceTheGame)
void __cdecl ServiceTheGame(int pRacing) {
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;

    original_ServiceTheGame(pRacing);
}

static void(__cdecl*original_ServiceGame)() = (void(__cdecl*)())0x004a9fe4;
CARM95_HOOK_FUNCTION(original_ServiceGame, ServiceGame)
void __cdecl ServiceGame() {
    LOG_TRACE("()");


    original_ServiceGame();
}

static void(__cdecl*original_ServiceGameInRace)() = (void(__cdecl*)())0x004a9ff9;
CARM95_HOOK_FUNCTION(original_ServiceGameInRace, ServiceGameInRace)
void __cdecl ServiceGameInRace() {
    LOG_TRACE("()");


    original_ServiceGameInRace();
}

static void(__cdecl*original_GameMain)(int, char **) = (void(__cdecl*)(int, char **))0x004aa013;
CARM95_HOOK_FUNCTION(original_GameMain, GameMain)
void __cdecl GameMain(int pArgc, char **pArgv) {
    tPath_name CD_dir;
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;
    (void)CD_dir;

    original_GameMain(pArgc, pArgv);
}

