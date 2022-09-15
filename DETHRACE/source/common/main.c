#include "main.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_QuitGame)() = (void(*)())0x004a9ea0;
CARM95_HOOK_FUNCTION(original_QuitGame, QuitGame)
void QuitGame() {
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

static void(*original_ServiceTheGame)(int, ...) = (void(*)(int, ...))0x004a9f29;
CARM95_HOOK_FUNCTION(original_ServiceTheGame, ServiceTheGame)
void ServiceTheGame(int pRacing) {
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;

    original_ServiceTheGame(pRacing);
}

static void(*original_ServiceGame)() = (void(*)())0x004a9fe4;
CARM95_HOOK_FUNCTION(original_ServiceGame, ServiceGame)
void ServiceGame() {
    LOG_TRACE("()");


    original_ServiceGame();
}

static void(*original_ServiceGameInRace)() = (void(*)())0x004a9ff9;
CARM95_HOOK_FUNCTION(original_ServiceGameInRace, ServiceGameInRace)
void ServiceGameInRace() {
    LOG_TRACE("()");


    original_ServiceGameInRace();
}

static void(*original_GameMain)(int, char **, ...) = (void(*)(int, char **, ...))0x004aa013;
CARM95_HOOK_FUNCTION(original_GameMain, GameMain)
void GameMain(int pArgc, char **pArgv) {
    tPath_name CD_dir;
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;
    (void)CD_dir;

    original_GameMain(pArgc, pArgv);
}

