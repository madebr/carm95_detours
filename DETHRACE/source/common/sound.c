#include "sound.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
int * hookvar_gSound_detail_level  = (void*)0x00514928;
#if 0
int * hookvar_gVirgin_pass ;
#endif
#if 0
int * hookvar_gOld_sound_detail_level ;
#endif
#if 0
int * hookvar_gLast_tune ;
#endif
#if 0
int(* hookvar_gRandom_MIDI_tunes )[3];
#endif
#if 0
int(* hookvar_gRandom_Rockin_MIDI_tunes )[3];
#endif
int(* hookvar_gRandom_CDA_tunes )[7] = (void*)0x00514958;
int * hookvar_gCDA_is_playing  = (void*)0x00514980;
#if 0
int * hookvar_gServicing_sound ;
#endif
#if 0
int * hookvar_gSong_repeat_count ;
#endif
#if 0
int * hookvar_gSound_sources_inited ;
#endif
#if 0
int * hookvar_gMusic_available ;
#endif
#if 0
tS3_sound_tag * hookvar_gCDA_tag ;
#endif
int * hookvar_gCD_fully_installed  = (void*)0x00514990;
tS3_outlet_ptr * hookvar_gEffects_outlet  = (void*)0x00514994;
tS3_outlet_ptr * hookvar_gCar_outlet  = (void*)0x00514998;
tS3_outlet_ptr * hookvar_gEngine_outlet  = (void*)0x0051499c;
tS3_outlet_ptr * hookvar_gDriver_outlet  = (void*)0x005149a0;
tS3_outlet_ptr * hookvar_gPedestrians_outlet  = (void*)0x005149a4;
tS3_outlet_ptr * hookvar_gMusic_outlet  = (void*)0x005149a8;
#if 0
tS3_sound_id * hookvar_gMIDI_id ;
#endif
#if 0
tS3_outlet_ptr(* hookvar_gIndexed_outlets )[6];
#endif
#if 0
tU32 * hookvar_gLast_sound_service ;
#endif
#if 0
int * hookvar_gCD_is_disabled ;
#endif
br_vector3 * hookvar_gCamera_left  = (void*)0x00550a00;
br_vector3 * hookvar_gCamera_position  = (void*)0x00550a10;
br_vector3 * hookvar_gOld_camera_position  = (void*)0x00550a40;
br_vector3 * hookvar_gCamera_velocity  = (void*)0x00550a50;

static void(*original_UsePathFileToDetermineIfFullInstallation)() = (void(*)())0x00463fb0;
CARM95_HOOK_FUNCTION(original_UsePathFileToDetermineIfFullInstallation, UsePathFileToDetermineIfFullInstallation)
void UsePathFileToDetermineIfFullInstallation() {
    char line1[80];
    char line2[80];
    char line3[80];
    char path_file[80];
    FILE *fp;
    LOG_TRACE("()");

    (void)line1;
    (void)line2;
    (void)line3;
    (void)path_file;
    (void)fp;

    original_UsePathFileToDetermineIfFullInstallation();
}

static void(*original_InitSound)() = (void(*)())0x00464117;
CARM95_HOOK_FUNCTION(original_InitSound, InitSound)
void InitSound() {
    tPath_name the_path;
    tS3_sound_tag tag;
    int engine_channel_count;
    int car_channel_count;
    int ped_channel_count;
    LOG_TRACE("()");

    (void)the_path;
    (void)tag;
    (void)engine_channel_count;
    (void)car_channel_count;
    (void)ped_channel_count;

    original_InitSound();
}

static tS3_sound_tag(*original_DRS3StartSound)(tS3_outlet_ptr, tS3_sound_id, ...) = (tS3_sound_tag(*)(tS3_outlet_ptr, tS3_sound_id, ...))0x0046458b;
CARM95_HOOK_FUNCTION(original_DRS3StartSound, DRS3StartSound)
tS3_sound_tag DRS3StartSound(tS3_outlet_ptr pOutlet, tS3_sound_id pSound) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pSound);

    (void)pOutlet;
    (void)pSound;

    return original_DRS3StartSound(pOutlet, pSound);
}

static tS3_sound_tag(*original_DRS3StartSoundNoPiping)(tS3_outlet_ptr, tS3_sound_id, ...) = (tS3_sound_tag(*)(tS3_outlet_ptr, tS3_sound_id, ...))0x0046461d;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundNoPiping, DRS3StartSoundNoPiping)
tS3_sound_tag DRS3StartSoundNoPiping(tS3_outlet_ptr pOutlet, tS3_sound_id pSound) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pSound);

    (void)pOutlet;
    (void)pSound;

    return original_DRS3StartSoundNoPiping(pOutlet, pSound);
}

static tS3_sound_tag(*original_DRS3StartSound2)(tS3_outlet_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_volume, tS3_pitch, tS3_speed, ...) = (tS3_sound_tag(*)(tS3_outlet_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_volume, tS3_pitch, tS3_speed, ...))0x00464656;
CARM95_HOOK_FUNCTION(original_DRS3StartSound2, DRS3StartSound2)
tS3_sound_tag DRS3StartSound2(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pLVolume, tS3_volume pRVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %d, %d)", pOutlet, pSound, pRepeats, pLVolume, pRVolume, pPitch, pSpeed);

    (void)pOutlet;
    (void)pSound;
    (void)pRepeats;
    (void)pLVolume;
    (void)pRVolume;
    (void)pPitch;
    (void)pSpeed;

    return original_DRS3StartSound2(pOutlet, pSound, pRepeats, pLVolume, pRVolume, pPitch, pSpeed);
}

static int(*original_DRS3ChangeVolume)(tS3_sound_tag, tS3_volume, ...) = (int(*)(tS3_sound_tag, tS3_volume, ...))0x00464724;
CARM95_HOOK_FUNCTION(original_DRS3ChangeVolume, DRS3ChangeVolume)
int DRS3ChangeVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_volume) {
    LOG_TRACE("(%d, %d)", pSound_tag, pNew_volume);

    (void)pSound_tag;
    (void)pNew_volume;

    return original_DRS3ChangeVolume(pSound_tag, pNew_volume);
}

static int(*original_DRS3ChangeLRVolume)(tS3_sound_tag, tS3_volume, tS3_volume, ...) = (int(*)(tS3_sound_tag, tS3_volume, tS3_volume, ...))0x0046475d;
CARM95_HOOK_FUNCTION(original_DRS3ChangeLRVolume, DRS3ChangeLRVolume)
int DRS3ChangeLRVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_Lvolume, tS3_volume pNew_Rvolume) {
    LOG_TRACE("(%d, %d, %d)", pSound_tag, pNew_Lvolume, pNew_Rvolume);

    (void)pSound_tag;
    (void)pNew_Lvolume;
    (void)pNew_Rvolume;

    return original_DRS3ChangeLRVolume(pSound_tag, pNew_Lvolume, pNew_Rvolume);
}

static int(*original_DRS3ChangePitch)(tS3_sound_tag, tS3_pitch, ...) = (int(*)(tS3_sound_tag, tS3_pitch, ...))0x0046479a;
CARM95_HOOK_FUNCTION(original_DRS3ChangePitch, DRS3ChangePitch)
int DRS3ChangePitch(tS3_sound_tag pTag, tS3_pitch pNew_pitch) {
    LOG_TRACE("(%d, %d)", pTag, pNew_pitch);

    (void)pTag;
    (void)pNew_pitch;

    return original_DRS3ChangePitch(pTag, pNew_pitch);
}

static int(*original_DRS3ChangeSpeed)(tS3_sound_tag, tS3_pitch, ...) = (int(*)(tS3_sound_tag, tS3_pitch, ...))0x004647d3;
CARM95_HOOK_FUNCTION(original_DRS3ChangeSpeed, DRS3ChangeSpeed)
int DRS3ChangeSpeed(tS3_sound_tag pTag, tS3_pitch pNew_speed) {
    LOG_TRACE("(%d, %d)", pTag, pNew_speed);

    (void)pTag;
    (void)pNew_speed;

    return original_DRS3ChangeSpeed(pTag, pNew_speed);
}

static int(*original_DRS3ChangePitchSpeed)(tS3_sound_tag, tS3_pitch, ...) = (int(*)(tS3_sound_tag, tS3_pitch, ...))0x0046480c;
CARM95_HOOK_FUNCTION(original_DRS3ChangePitchSpeed, DRS3ChangePitchSpeed)
int DRS3ChangePitchSpeed(tS3_sound_tag pTag, tS3_pitch pNew_pitch) {
    LOG_TRACE("(%d, %d)", pTag, pNew_pitch);

    (void)pTag;
    (void)pNew_pitch;

    return original_DRS3ChangePitchSpeed(pTag, pNew_pitch);
}

static int(*original_DRS3StopSound)(tS3_sound_tag, ...) = (int(*)(tS3_sound_tag, ...))0x00464845;
CARM95_HOOK_FUNCTION(original_DRS3StopSound, DRS3StopSound)
int DRS3StopSound(tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d)", pSound_tag);

    (void)pSound_tag;

    return original_DRS3StopSound(pSound_tag);
}

static int(*original_DRS3LoadSound)(tS3_sound_id, ...) = (int(*)(tS3_sound_id, ...))0x0046487a;
CARM95_HOOK_FUNCTION(original_DRS3LoadSound, DRS3LoadSound)
int DRS3LoadSound(tS3_sound_id pThe_sound) {
    LOG_TRACE("(%d)", pThe_sound);

    (void)pThe_sound;

    return original_DRS3LoadSound(pThe_sound);
}

static int(*original_DRS3ReleaseSound)(tS3_sound_id, ...) = (int(*)(tS3_sound_id, ...))0x004648af;
CARM95_HOOK_FUNCTION(original_DRS3ReleaseSound, DRS3ReleaseSound)
int DRS3ReleaseSound(tS3_sound_id pThe_sound) {
    LOG_TRACE("(%d)", pThe_sound);

    (void)pThe_sound;

    return original_DRS3ReleaseSound(pThe_sound);
}

void DRS3Service() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static int(*original_DRS3OutletSoundsPlaying)(tS3_outlet_ptr, ...) = (int(*)(tS3_outlet_ptr, ...))0x0046493a;
CARM95_HOOK_FUNCTION(original_DRS3OutletSoundsPlaying, DRS3OutletSoundsPlaying)
int DRS3OutletSoundsPlaying(tS3_outlet_ptr pOutlet) {
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;

    return original_DRS3OutletSoundsPlaying(pOutlet);
}

static int(*original_DRS3SoundStillPlaying)(tS3_sound_tag, ...) = (int(*)(tS3_sound_tag, ...))0x0046496f;
CARM95_HOOK_FUNCTION(original_DRS3SoundStillPlaying, DRS3SoundStillPlaying)
int DRS3SoundStillPlaying(tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d)", pSound_tag);

    (void)pSound_tag;

    return original_DRS3SoundStillPlaying(pSound_tag);
}

static void(*original_DRS3ShutDown)() = (void(*)())0x004649a4;
CARM95_HOOK_FUNCTION(original_DRS3ShutDown, DRS3ShutDown)
void DRS3ShutDown() {
    LOG_TRACE("()");


    original_DRS3ShutDown();
}

static int(*original_DRS3SetOutletVolume)(tS3_outlet_ptr, tS3_volume, ...) = (int(*)(tS3_outlet_ptr, tS3_volume, ...))0x004649cb;
CARM95_HOOK_FUNCTION(original_DRS3SetOutletVolume, DRS3SetOutletVolume)
int DRS3SetOutletVolume(tS3_outlet_ptr pOutlet, tS3_volume pVolume) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pVolume);

    (void)pOutlet;
    (void)pVolume;

    return original_DRS3SetOutletVolume(pOutlet, pVolume);
}

static int(*original_DRS3OverallVolume)(tS3_volume, ...) = (int(*)(tS3_volume, ...))0x00464a04;
CARM95_HOOK_FUNCTION(original_DRS3OverallVolume, DRS3OverallVolume)
int DRS3OverallVolume(tS3_volume pVolume) {
    LOG_TRACE("(%d)", pVolume);

    (void)pVolume;

    return original_DRS3OverallVolume(pVolume);
}

static int(*original_DRS3StopOutletSound)(tS3_outlet_ptr, ...) = (int(*)(tS3_outlet_ptr, ...))0x00464a39;
CARM95_HOOK_FUNCTION(original_DRS3StopOutletSound, DRS3StopOutletSound)
int DRS3StopOutletSound(tS3_outlet_ptr pOutlet) {
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;

    return original_DRS3StopOutletSound(pOutlet);
}

static int(*original_DRS3StopAllOutletSounds)() = (int(*)())0x00464a6e;
CARM95_HOOK_FUNCTION(original_DRS3StopAllOutletSounds, DRS3StopAllOutletSounds)
int DRS3StopAllOutletSounds() {
    LOG_TRACE("()");


    return original_DRS3StopAllOutletSounds();
}

static void(*original_ToggleSoundEnable)() = (void(*)())0x00464a9c;
CARM95_HOOK_FUNCTION(original_ToggleSoundEnable, ToggleSoundEnable)
void ToggleSoundEnable() {
    LOG_TRACE("()");


    original_ToggleSoundEnable();
}

static void(*original_SoundService)() = (void(*)())0x00464adc;
CARM95_HOOK_FUNCTION(original_SoundService, SoundService)
void SoundService() {
    tU32 this_service;
    br_matrix34 mat;
    LOG_TRACE("()");

    (void)this_service;
    (void)mat;

    original_SoundService();
}

static void(*original_InitSoundSources)() = (void(*)())0x00464b51;
CARM95_HOOK_FUNCTION(original_InitSoundSources, InitSoundSources)
void InitSoundSources() {
    int cat;
    int car_count;
    int i;
    int toggle;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)cat;
    (void)car_count;
    (void)i;
    (void)toggle;
    (void)the_car;

    original_InitSoundSources();
}

static void(*original_DisposeSoundSources)() = (void(*)())0x00464d79;
CARM95_HOOK_FUNCTION(original_DisposeSoundSources, DisposeSoundSources)
void DisposeSoundSources() {
    int cat;
    int car_count;
    int i;
    int toggle;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)cat;
    (void)car_count;
    (void)i;
    (void)toggle;
    (void)the_car;

    original_DisposeSoundSources();
}

static tS3_sound_tag(*original_DRS3StartSound3D)(tS3_outlet_ptr, tS3_sound_id, br_vector3 *, br_vector3 *, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed, ...) = (tS3_sound_tag(*)(tS3_outlet_ptr, tS3_sound_id, br_vector3 *, br_vector3 *, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed, ...))0x00464f39;
CARM95_HOOK_FUNCTION(original_DRS3StartSound3D, DRS3StartSound3D)
tS3_sound_tag DRS3StartSound3D(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, br_vector3 *pInitial_position, br_vector3 *pInitial_velocity, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
    tS3_sound_tag tag;
    LOG_TRACE("(\"%s\", %d, %p, %p, %d, %d, %d, %d)", pOutlet, pSound, pInitial_position, pInitial_velocity, pRepeats, pVolume, pPitch, pSpeed);

    (void)pOutlet;
    (void)pSound;
    (void)pInitial_position;
    (void)pInitial_velocity;
    (void)pRepeats;
    (void)pVolume;
    (void)pPitch;
    (void)pSpeed;
    (void)tag;

    return original_DRS3StartSound3D(pOutlet, pSound, pInitial_position, pInitial_velocity, pRepeats, pVolume, pPitch, pSpeed);
}

static tS3_sound_tag(*original_DRS3StartSoundFromSource3)(tS3_sound_source_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed, ...) = (tS3_sound_tag(*)(tS3_sound_source_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed, ...))0x00464ffc;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundFromSource3, DRS3StartSoundFromSource3)
tS3_sound_tag DRS3StartSoundFromSource3(tS3_sound_source_ptr pSource, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
    tS3_sound_tag tag;
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %d)", pSource, pSound, pRepeats, pVolume, pPitch, pSpeed);

    (void)pSource;
    (void)pSound;
    (void)pRepeats;
    (void)pVolume;
    (void)pPitch;
    (void)pSpeed;
    (void)tag;

    return original_DRS3StartSoundFromSource3(pSource, pSound, pRepeats, pVolume, pPitch, pSpeed);
}

static tS3_sound_tag(*original_DRS3StartSoundFromSource)(tS3_sound_source_ptr, tS3_sound_id, ...) = (tS3_sound_tag(*)(tS3_sound_source_ptr, tS3_sound_id, ...))0x0046504e;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundFromSource, DRS3StartSoundFromSource)
tS3_sound_tag DRS3StartSoundFromSource(tS3_sound_source_ptr pSource, tS3_sound_id pSound) {
    tS3_sound_tag tag;
    LOG_TRACE("(\"%s\", %d)", pSource, pSound);

    (void)pSource;
    (void)pSound;
    (void)tag;

    return original_DRS3StartSoundFromSource(pSource, pSound);
}

static void(*original_MungeEngineNoise)() = (void(*)())0x00465090;
CARM95_HOOK_FUNCTION(original_MungeEngineNoise, MungeEngineNoise)
void MungeEngineNoise() {
    tCar_spec *the_car;
    tU32 pitch;
    int vol;
    int cat;
    int car_count;
    int i;
    int stop_all;
    int type_of_engine_noise;
    tS3_sound_id engine_noise;
    LOG_TRACE("()");

    (void)the_car;
    (void)pitch;
    (void)vol;
    (void)cat;
    (void)car_count;
    (void)i;
    (void)stop_all;
    (void)type_of_engine_noise;
    (void)engine_noise;

    original_MungeEngineNoise();
}

static void(*original_SetSoundVolumes)() = (void(*)())0x004655d8;
CARM95_HOOK_FUNCTION(original_SetSoundVolumes, SetSoundVolumes)
void SetSoundVolumes() {
    LOG_TRACE("()");


    original_SetSoundVolumes();
}

static tS3_outlet_ptr(*original_GetOutletFromIndex)(int, ...) = (tS3_outlet_ptr(*)(int, ...))0x004656b1;
CARM95_HOOK_FUNCTION(original_GetOutletFromIndex, GetOutletFromIndex)
tS3_outlet_ptr GetOutletFromIndex(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    return original_GetOutletFromIndex(pIndex);
}

static int(*original_GetIndexFromOutlet)(tS3_outlet_ptr, ...) = (int(*)(tS3_outlet_ptr, ...))0x004656cb;
CARM95_HOOK_FUNCTION(original_GetIndexFromOutlet, GetIndexFromOutlet)
int GetIndexFromOutlet(tS3_outlet_ptr pOutlet) {
    int i;
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;
    (void)i;

    return original_GetIndexFromOutlet(pOutlet);
}

static int(*original_DRS3StartCDA)(tS3_sound_id, ...) = (int(*)(tS3_sound_id, ...))0x00465719;
CARM95_HOOK_FUNCTION(original_DRS3StartCDA, DRS3StartCDA)
int DRS3StartCDA(tS3_sound_id pCDA_id) {
    LOG_TRACE("(%d)", pCDA_id);

    (void)pCDA_id;

    return original_DRS3StartCDA(pCDA_id);
}

static int(*original_DRS3StopCDA)() = (int(*)())0x00465848;
CARM95_HOOK_FUNCTION(original_DRS3StopCDA, DRS3StopCDA)
int DRS3StopCDA() {
    LOG_TRACE("()");


    return original_DRS3StopCDA();
}

static void(*original_StartMusic)() = (void(*)())0x00465899;
CARM95_HOOK_FUNCTION(original_StartMusic, StartMusic)
void StartMusic() {
    LOG_TRACE("()");


    original_StartMusic();
}

static void(*original_StopMusic)() = (void(*)())0x004658c3;
CARM95_HOOK_FUNCTION(original_StopMusic, StopMusic)
void StopMusic() {
    LOG_TRACE("()");


    original_StopMusic();
}

