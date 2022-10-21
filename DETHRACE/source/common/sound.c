#include "sound.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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
tS3_outlet_ptr(* hookvar_gIndexed_outlets )[6] = (void*)0x00550a20;
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

function_hook_state_t function_hook_state_UsePathFileToDetermineIfFullInstallation = HOOK_UNAVAILABLE;
static void(__cdecl*original_UsePathFileToDetermineIfFullInstallation)() = (void(__cdecl*)())0x00463fb0;
CARM95_HOOK_FUNCTION(original_UsePathFileToDetermineIfFullInstallation, UsePathFileToDetermineIfFullInstallation)
void __cdecl UsePathFileToDetermineIfFullInstallation() {
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

    if (function_hook_state_UsePathFileToDetermineIfFullInstallation == HOOK_ENABLED) {
        assert(0 && "UsePathFileToDetermineIfFullInstallation not implemented.");
        abort();
    } else {
        original_UsePathFileToDetermineIfFullInstallation();
    }
}

function_hook_state_t function_hook_state_InitSound = HOOK_UNAVAILABLE;
static void(__cdecl*original_InitSound)() = (void(__cdecl*)())0x00464117;
CARM95_HOOK_FUNCTION(original_InitSound, InitSound)
void __cdecl InitSound() {
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

    if (function_hook_state_InitSound == HOOK_ENABLED) {
        assert(0 && "InitSound not implemented.");
        abort();
    } else {
        original_InitSound();
    }
}

function_hook_state_t function_hook_state_DRS3StartSound = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSound)(tS3_outlet_ptr, tS3_sound_id) = (tS3_sound_tag(__cdecl*)(tS3_outlet_ptr, tS3_sound_id))0x0046458b;
CARM95_HOOK_FUNCTION(original_DRS3StartSound, DRS3StartSound)
tS3_sound_tag __cdecl DRS3StartSound(tS3_outlet_ptr pOutlet, tS3_sound_id pSound) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pSound);

    (void)pOutlet;
    (void)pSound;

    if (function_hook_state_DRS3StartSound == HOOK_ENABLED) {
        assert(0 && "DRS3StartSound not implemented.");
        abort();
    } else {
        return original_DRS3StartSound(pOutlet, pSound);
    }
}

function_hook_state_t function_hook_state_DRS3StartSoundNoPiping = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSoundNoPiping)(tS3_outlet_ptr, tS3_sound_id) = (tS3_sound_tag(__cdecl*)(tS3_outlet_ptr, tS3_sound_id))0x0046461d;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundNoPiping, DRS3StartSoundNoPiping)
tS3_sound_tag __cdecl DRS3StartSoundNoPiping(tS3_outlet_ptr pOutlet, tS3_sound_id pSound) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pSound);

    (void)pOutlet;
    (void)pSound;

    if (function_hook_state_DRS3StartSoundNoPiping == HOOK_ENABLED) {
        assert(0 && "DRS3StartSoundNoPiping not implemented.");
        abort();
    } else {
        return original_DRS3StartSoundNoPiping(pOutlet, pSound);
    }
}

function_hook_state_t function_hook_state_DRS3StartSound2 = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSound2)(tS3_outlet_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_volume, tS3_pitch, tS3_speed) = (tS3_sound_tag(__cdecl*)(tS3_outlet_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_volume, tS3_pitch, tS3_speed))0x00464656;
CARM95_HOOK_FUNCTION(original_DRS3StartSound2, DRS3StartSound2)
tS3_sound_tag __cdecl DRS3StartSound2(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pLVolume, tS3_volume pRVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %d, %d)", pOutlet, pSound, pRepeats, pLVolume, pRVolume, pPitch, pSpeed);

    (void)pOutlet;
    (void)pSound;
    (void)pRepeats;
    (void)pLVolume;
    (void)pRVolume;
    (void)pPitch;
    (void)pSpeed;

    if (function_hook_state_DRS3StartSound2 == HOOK_ENABLED) {
        assert(0 && "DRS3StartSound2 not implemented.");
        abort();
    } else {
        return original_DRS3StartSound2(pOutlet, pSound, pRepeats, pLVolume, pRVolume, pPitch, pSpeed);
    }
}

function_hook_state_t function_hook_state_DRS3ChangeVolume = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ChangeVolume)(tS3_sound_tag, tS3_volume) = (int(__cdecl*)(tS3_sound_tag, tS3_volume))0x00464724;
CARM95_HOOK_FUNCTION(original_DRS3ChangeVolume, DRS3ChangeVolume)
int __cdecl DRS3ChangeVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_volume) {
    LOG_TRACE("(%d, %d)", pSound_tag, pNew_volume);

    (void)pSound_tag;
    (void)pNew_volume;

    if (function_hook_state_DRS3ChangeVolume == HOOK_ENABLED) {
        assert(0 && "DRS3ChangeVolume not implemented.");
        abort();
    } else {
        return original_DRS3ChangeVolume(pSound_tag, pNew_volume);
    }
}

function_hook_state_t function_hook_state_DRS3ChangeLRVolume = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ChangeLRVolume)(tS3_sound_tag, tS3_volume, tS3_volume) = (int(__cdecl*)(tS3_sound_tag, tS3_volume, tS3_volume))0x0046475d;
CARM95_HOOK_FUNCTION(original_DRS3ChangeLRVolume, DRS3ChangeLRVolume)
int __cdecl DRS3ChangeLRVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_Lvolume, tS3_volume pNew_Rvolume) {
    LOG_TRACE("(%d, %d, %d)", pSound_tag, pNew_Lvolume, pNew_Rvolume);

    (void)pSound_tag;
    (void)pNew_Lvolume;
    (void)pNew_Rvolume;

    if (function_hook_state_DRS3ChangeLRVolume == HOOK_ENABLED) {
        assert(0 && "DRS3ChangeLRVolume not implemented.");
        abort();
    } else {
        return original_DRS3ChangeLRVolume(pSound_tag, pNew_Lvolume, pNew_Rvolume);
    }
}

function_hook_state_t function_hook_state_DRS3ChangePitch = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ChangePitch)(tS3_sound_tag, tS3_pitch) = (int(__cdecl*)(tS3_sound_tag, tS3_pitch))0x0046479a;
CARM95_HOOK_FUNCTION(original_DRS3ChangePitch, DRS3ChangePitch)
int __cdecl DRS3ChangePitch(tS3_sound_tag pTag, tS3_pitch pNew_pitch) {
    LOG_TRACE("(%d, %d)", pTag, pNew_pitch);

    (void)pTag;
    (void)pNew_pitch;

    if (function_hook_state_DRS3ChangePitch == HOOK_ENABLED) {
        assert(0 && "DRS3ChangePitch not implemented.");
        abort();
    } else {
        return original_DRS3ChangePitch(pTag, pNew_pitch);
    }
}

function_hook_state_t function_hook_state_DRS3ChangeSpeed = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ChangeSpeed)(tS3_sound_tag, tS3_pitch) = (int(__cdecl*)(tS3_sound_tag, tS3_pitch))0x004647d3;
CARM95_HOOK_FUNCTION(original_DRS3ChangeSpeed, DRS3ChangeSpeed)
int __cdecl DRS3ChangeSpeed(tS3_sound_tag pTag, tS3_pitch pNew_speed) {
    LOG_TRACE("(%d, %d)", pTag, pNew_speed);

    (void)pTag;
    (void)pNew_speed;

    if (function_hook_state_DRS3ChangeSpeed == HOOK_ENABLED) {
        assert(0 && "DRS3ChangeSpeed not implemented.");
        abort();
    } else {
        return original_DRS3ChangeSpeed(pTag, pNew_speed);
    }
}

function_hook_state_t function_hook_state_DRS3ChangePitchSpeed = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ChangePitchSpeed)(tS3_sound_tag, tS3_pitch) = (int(__cdecl*)(tS3_sound_tag, tS3_pitch))0x0046480c;
CARM95_HOOK_FUNCTION(original_DRS3ChangePitchSpeed, DRS3ChangePitchSpeed)
int __cdecl DRS3ChangePitchSpeed(tS3_sound_tag pTag, tS3_pitch pNew_pitch) {
    LOG_TRACE("(%d, %d)", pTag, pNew_pitch);

    (void)pTag;
    (void)pNew_pitch;

    if (function_hook_state_DRS3ChangePitchSpeed == HOOK_ENABLED) {
        assert(0 && "DRS3ChangePitchSpeed not implemented.");
        abort();
    } else {
        return original_DRS3ChangePitchSpeed(pTag, pNew_pitch);
    }
}

function_hook_state_t function_hook_state_DRS3StopSound = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3StopSound)(tS3_sound_tag) = (int(__cdecl*)(tS3_sound_tag))0x00464845;
CARM95_HOOK_FUNCTION(original_DRS3StopSound, DRS3StopSound)
int __cdecl DRS3StopSound(tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d)", pSound_tag);

    (void)pSound_tag;

    if (function_hook_state_DRS3StopSound == HOOK_ENABLED) {
        assert(0 && "DRS3StopSound not implemented.");
        abort();
    } else {
        return original_DRS3StopSound(pSound_tag);
    }
}

function_hook_state_t function_hook_state_DRS3LoadSound = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3LoadSound)(tS3_sound_id) = (int(__cdecl*)(tS3_sound_id))0x0046487a;
CARM95_HOOK_FUNCTION(original_DRS3LoadSound, DRS3LoadSound)
int __cdecl DRS3LoadSound(tS3_sound_id pThe_sound) {
    LOG_TRACE("(%d)", pThe_sound);

    (void)pThe_sound;

    if (function_hook_state_DRS3LoadSound == HOOK_ENABLED) {
        assert(0 && "DRS3LoadSound not implemented.");
        abort();
    } else {
        return original_DRS3LoadSound(pThe_sound);
    }
}

function_hook_state_t function_hook_state_DRS3ReleaseSound = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3ReleaseSound)(tS3_sound_id) = (int(__cdecl*)(tS3_sound_id))0x004648af;
CARM95_HOOK_FUNCTION(original_DRS3ReleaseSound, DRS3ReleaseSound)
int __cdecl DRS3ReleaseSound(tS3_sound_id pThe_sound) {
    LOG_TRACE("(%d)", pThe_sound);

    (void)pThe_sound;

    if (function_hook_state_DRS3ReleaseSound == HOOK_ENABLED) {
        assert(0 && "DRS3ReleaseSound not implemented.");
        abort();
    } else {
        return original_DRS3ReleaseSound(pThe_sound);
    }
}

function_hook_state_t function_hook_state_DRS3Service = HOOK_UNAVAILABLE;
void DRS3Service() {
    LOG_TRACE("()");


    if (function_hook_state_DRS3Service == HOOK_ENABLED) {
        assert(0 && "DRS3Service not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DRS3OutletSoundsPlaying = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3OutletSoundsPlaying)(tS3_outlet_ptr) = (int(__cdecl*)(tS3_outlet_ptr))0x0046493a;
CARM95_HOOK_FUNCTION(original_DRS3OutletSoundsPlaying, DRS3OutletSoundsPlaying)
int __cdecl DRS3OutletSoundsPlaying(tS3_outlet_ptr pOutlet) {
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;

    if (function_hook_state_DRS3OutletSoundsPlaying == HOOK_ENABLED) {
        assert(0 && "DRS3OutletSoundsPlaying not implemented.");
        abort();
    } else {
        return original_DRS3OutletSoundsPlaying(pOutlet);
    }
}

function_hook_state_t function_hook_state_DRS3SoundStillPlaying = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3SoundStillPlaying)(tS3_sound_tag) = (int(__cdecl*)(tS3_sound_tag))0x0046496f;
CARM95_HOOK_FUNCTION(original_DRS3SoundStillPlaying, DRS3SoundStillPlaying)
int __cdecl DRS3SoundStillPlaying(tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d)", pSound_tag);

    (void)pSound_tag;

    if (function_hook_state_DRS3SoundStillPlaying == HOOK_ENABLED) {
        assert(0 && "DRS3SoundStillPlaying not implemented.");
        abort();
    } else {
        return original_DRS3SoundStillPlaying(pSound_tag);
    }
}

function_hook_state_t function_hook_state_DRS3ShutDown = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRS3ShutDown)() = (void(__cdecl*)())0x004649a4;
CARM95_HOOK_FUNCTION(original_DRS3ShutDown, DRS3ShutDown)
void __cdecl DRS3ShutDown() {
    LOG_TRACE("()");


    if (function_hook_state_DRS3ShutDown == HOOK_ENABLED) {
        assert(0 && "DRS3ShutDown not implemented.");
        abort();
    } else {
        original_DRS3ShutDown();
    }
}

function_hook_state_t function_hook_state_DRS3SetOutletVolume = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3SetOutletVolume)(tS3_outlet_ptr, tS3_volume) = (int(__cdecl*)(tS3_outlet_ptr, tS3_volume))0x004649cb;
CARM95_HOOK_FUNCTION(original_DRS3SetOutletVolume, DRS3SetOutletVolume)
int __cdecl DRS3SetOutletVolume(tS3_outlet_ptr pOutlet, tS3_volume pVolume) {
    LOG_TRACE("(\"%s\", %d)", pOutlet, pVolume);

    (void)pOutlet;
    (void)pVolume;

    if (function_hook_state_DRS3SetOutletVolume == HOOK_ENABLED) {
        assert(0 && "DRS3SetOutletVolume not implemented.");
        abort();
    } else {
        return original_DRS3SetOutletVolume(pOutlet, pVolume);
    }
}

function_hook_state_t function_hook_state_DRS3OverallVolume = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3OverallVolume)(tS3_volume) = (int(__cdecl*)(tS3_volume))0x00464a04;
CARM95_HOOK_FUNCTION(original_DRS3OverallVolume, DRS3OverallVolume)
int __cdecl DRS3OverallVolume(tS3_volume pVolume) {
    LOG_TRACE("(%d)", pVolume);

    (void)pVolume;

    if (function_hook_state_DRS3OverallVolume == HOOK_ENABLED) {
        assert(0 && "DRS3OverallVolume not implemented.");
        abort();
    } else {
        return original_DRS3OverallVolume(pVolume);
    }
}

function_hook_state_t function_hook_state_DRS3StopOutletSound = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3StopOutletSound)(tS3_outlet_ptr) = (int(__cdecl*)(tS3_outlet_ptr))0x00464a39;
CARM95_HOOK_FUNCTION(original_DRS3StopOutletSound, DRS3StopOutletSound)
int __cdecl DRS3StopOutletSound(tS3_outlet_ptr pOutlet) {
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;

    if (function_hook_state_DRS3StopOutletSound == HOOK_ENABLED) {
        assert(0 && "DRS3StopOutletSound not implemented.");
        abort();
    } else {
        return original_DRS3StopOutletSound(pOutlet);
    }
}

function_hook_state_t function_hook_state_DRS3StopAllOutletSounds = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3StopAllOutletSounds)() = (int(__cdecl*)())0x00464a6e;
CARM95_HOOK_FUNCTION(original_DRS3StopAllOutletSounds, DRS3StopAllOutletSounds)
int __cdecl DRS3StopAllOutletSounds() {
    LOG_TRACE("()");


    if (function_hook_state_DRS3StopAllOutletSounds == HOOK_ENABLED) {
        assert(0 && "DRS3StopAllOutletSounds not implemented.");
        abort();
    } else {
        return original_DRS3StopAllOutletSounds();
    }
}

function_hook_state_t function_hook_state_ToggleSoundEnable = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleSoundEnable)() = (void(__cdecl*)())0x00464a9c;
CARM95_HOOK_FUNCTION(original_ToggleSoundEnable, ToggleSoundEnable)
void __cdecl ToggleSoundEnable() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleSoundEnable == HOOK_ENABLED) {
        assert(0 && "ToggleSoundEnable not implemented.");
        abort();
    } else {
        original_ToggleSoundEnable();
    }
}

function_hook_state_t function_hook_state_SoundService = HOOK_UNAVAILABLE;
static void(__cdecl*original_SoundService)() = (void(__cdecl*)())0x00464adc;
CARM95_HOOK_FUNCTION(original_SoundService, SoundService)
void __cdecl SoundService() {
    tU32 this_service;
    br_matrix34 mat;
    LOG_TRACE("()");

    (void)this_service;
    (void)mat;

    if (function_hook_state_SoundService == HOOK_ENABLED) {
        assert(0 && "SoundService not implemented.");
        abort();
    } else {
        original_SoundService();
    }
}

function_hook_state_t function_hook_state_InitSoundSources = HOOK_UNAVAILABLE;
static void(__cdecl*original_InitSoundSources)() = (void(__cdecl*)())0x00464b51;
CARM95_HOOK_FUNCTION(original_InitSoundSources, InitSoundSources)
void __cdecl InitSoundSources() {
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

    if (function_hook_state_InitSoundSources == HOOK_ENABLED) {
        assert(0 && "InitSoundSources not implemented.");
        abort();
    } else {
        original_InitSoundSources();
    }
}

function_hook_state_t function_hook_state_DisposeSoundSources = HOOK_UNAVAILABLE;
static void(__cdecl*original_DisposeSoundSources)() = (void(__cdecl*)())0x00464d79;
CARM95_HOOK_FUNCTION(original_DisposeSoundSources, DisposeSoundSources)
void __cdecl DisposeSoundSources() {
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

    if (function_hook_state_DisposeSoundSources == HOOK_ENABLED) {
        assert(0 && "DisposeSoundSources not implemented.");
        abort();
    } else {
        original_DisposeSoundSources();
    }
}

function_hook_state_t function_hook_state_DRS3StartSound3D = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSound3D)(tS3_outlet_ptr, tS3_sound_id, br_vector3 *, br_vector3 *, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed) = (tS3_sound_tag(__cdecl*)(tS3_outlet_ptr, tS3_sound_id, br_vector3 *, br_vector3 *, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed))0x00464f39;
CARM95_HOOK_FUNCTION(original_DRS3StartSound3D, DRS3StartSound3D)
tS3_sound_tag __cdecl DRS3StartSound3D(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, br_vector3 *pInitial_position, br_vector3 *pInitial_velocity, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
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

    if (function_hook_state_DRS3StartSound3D == HOOK_ENABLED) {
        assert(0 && "DRS3StartSound3D not implemented.");
        abort();
    } else {
        return original_DRS3StartSound3D(pOutlet, pSound, pInitial_position, pInitial_velocity, pRepeats, pVolume, pPitch, pSpeed);
    }
}

function_hook_state_t function_hook_state_DRS3StartSoundFromSource3 = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSoundFromSource3)(tS3_sound_source_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed) = (tS3_sound_tag(__cdecl*)(tS3_sound_source_ptr, tS3_sound_id, tS3_repeats, tS3_volume, tS3_pitch, tS3_speed))0x00464ffc;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundFromSource3, DRS3StartSoundFromSource3)
tS3_sound_tag __cdecl DRS3StartSoundFromSource3(tS3_sound_source_ptr pSource, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed) {
    tS3_sound_tag tag;
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %d)", pSource, pSound, pRepeats, pVolume, pPitch, pSpeed);

    (void)pSource;
    (void)pSound;
    (void)pRepeats;
    (void)pVolume;
    (void)pPitch;
    (void)pSpeed;
    (void)tag;

    if (function_hook_state_DRS3StartSoundFromSource3 == HOOK_ENABLED) {
        assert(0 && "DRS3StartSoundFromSource3 not implemented.");
        abort();
    } else {
        return original_DRS3StartSoundFromSource3(pSource, pSound, pRepeats, pVolume, pPitch, pSpeed);
    }
}

function_hook_state_t function_hook_state_DRS3StartSoundFromSource = HOOK_UNAVAILABLE;
static tS3_sound_tag(__cdecl*original_DRS3StartSoundFromSource)(tS3_sound_source_ptr, tS3_sound_id) = (tS3_sound_tag(__cdecl*)(tS3_sound_source_ptr, tS3_sound_id))0x0046504e;
CARM95_HOOK_FUNCTION(original_DRS3StartSoundFromSource, DRS3StartSoundFromSource)
tS3_sound_tag __cdecl DRS3StartSoundFromSource(tS3_sound_source_ptr pSource, tS3_sound_id pSound) {
    tS3_sound_tag tag;
    LOG_TRACE("(\"%s\", %d)", pSource, pSound);

    (void)pSource;
    (void)pSound;
    (void)tag;

    if (function_hook_state_DRS3StartSoundFromSource == HOOK_ENABLED) {
        assert(0 && "DRS3StartSoundFromSource not implemented.");
        abort();
    } else {
        return original_DRS3StartSoundFromSource(pSource, pSound);
    }
}

function_hook_state_t function_hook_state_MungeEngineNoise = HOOK_UNAVAILABLE;
static void(__cdecl*original_MungeEngineNoise)() = (void(__cdecl*)())0x00465090;
CARM95_HOOK_FUNCTION(original_MungeEngineNoise, MungeEngineNoise)
void __cdecl MungeEngineNoise() {
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

    if (function_hook_state_MungeEngineNoise == HOOK_ENABLED) {
        assert(0 && "MungeEngineNoise not implemented.");
        abort();
    } else {
        original_MungeEngineNoise();
    }
}

function_hook_state_t function_hook_state_SetSoundVolumes = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetSoundVolumes)() = (void(__cdecl*)())0x004655d8;
CARM95_HOOK_FUNCTION(original_SetSoundVolumes, SetSoundVolumes)
void __cdecl SetSoundVolumes() {
    LOG_TRACE("()");


    if (function_hook_state_SetSoundVolumes == HOOK_ENABLED) {
        assert(0 && "SetSoundVolumes not implemented.");
        abort();
    } else {
        original_SetSoundVolumes();
    }
}

function_hook_state_t function_hook_state_GetOutletFromIndex = HOOK_UNAVAILABLE;
static tS3_outlet_ptr(__cdecl*original_GetOutletFromIndex)(int) = (tS3_outlet_ptr(__cdecl*)(int))0x004656b1;
CARM95_HOOK_FUNCTION(original_GetOutletFromIndex, GetOutletFromIndex)
tS3_outlet_ptr __cdecl GetOutletFromIndex(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_GetOutletFromIndex == HOOK_ENABLED) {
        assert(0 && "GetOutletFromIndex not implemented.");
        abort();
    } else {
        return original_GetOutletFromIndex(pIndex);
    }
}

function_hook_state_t function_hook_state_GetIndexFromOutlet = HOOK_UNAVAILABLE;
static int(__cdecl*original_GetIndexFromOutlet)(tS3_outlet_ptr) = (int(__cdecl*)(tS3_outlet_ptr))0x004656cb;
CARM95_HOOK_FUNCTION(original_GetIndexFromOutlet, GetIndexFromOutlet)
int __cdecl GetIndexFromOutlet(tS3_outlet_ptr pOutlet) {
    int i;
    LOG_TRACE("(\"%s\")", pOutlet);

    (void)pOutlet;
    (void)i;

    if (function_hook_state_GetIndexFromOutlet == HOOK_ENABLED) {
        assert(0 && "GetIndexFromOutlet not implemented.");
        abort();
    } else {
        return original_GetIndexFromOutlet(pOutlet);
    }
}

function_hook_state_t function_hook_state_DRS3StartCDA = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3StartCDA)(tS3_sound_id) = (int(__cdecl*)(tS3_sound_id))0x00465719;
CARM95_HOOK_FUNCTION(original_DRS3StartCDA, DRS3StartCDA)
int __cdecl DRS3StartCDA(tS3_sound_id pCDA_id) {
    LOG_TRACE("(%d)", pCDA_id);

    (void)pCDA_id;

    if (function_hook_state_DRS3StartCDA == HOOK_ENABLED) {
        assert(0 && "DRS3StartCDA not implemented.");
        abort();
    } else {
        return original_DRS3StartCDA(pCDA_id);
    }
}

function_hook_state_t function_hook_state_DRS3StopCDA = HOOK_UNAVAILABLE;
static int(__cdecl*original_DRS3StopCDA)() = (int(__cdecl*)())0x00465848;
CARM95_HOOK_FUNCTION(original_DRS3StopCDA, DRS3StopCDA)
int __cdecl DRS3StopCDA() {
    LOG_TRACE("()");


    if (function_hook_state_DRS3StopCDA == HOOK_ENABLED) {
        assert(0 && "DRS3StopCDA not implemented.");
        abort();
    } else {
        return original_DRS3StopCDA();
    }
}

function_hook_state_t function_hook_state_StartMusic = HOOK_UNAVAILABLE;
static void(__cdecl*original_StartMusic)() = (void(__cdecl*)())0x00465899;
CARM95_HOOK_FUNCTION(original_StartMusic, StartMusic)
void __cdecl StartMusic() {
    LOG_TRACE("()");


    if (function_hook_state_StartMusic == HOOK_ENABLED) {
        assert(0 && "StartMusic not implemented.");
        abort();
    } else {
        original_StartMusic();
    }
}

function_hook_state_t function_hook_state_StopMusic = HOOK_UNAVAILABLE;
static void(__cdecl*original_StopMusic)() = (void(__cdecl*)())0x004658c3;
CARM95_HOOK_FUNCTION(original_StopMusic, StopMusic)
void __cdecl StopMusic() {
    LOG_TRACE("()");


    if (function_hook_state_StopMusic == HOOK_ENABLED) {
        assert(0 && "StopMusic not implemented.");
        abort();
    } else {
        original_StopMusic();
    }
}

