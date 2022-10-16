#ifndef _SOUND_H_
#define _SOUND_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gSound_detail_level ; // addr: 00514928
// extern int * hookvar_gVirgin_pass ;
// extern int * hookvar_gOld_sound_detail_level ;
// extern int * hookvar_gLast_tune ;
// extern int(* hookvar_gRandom_MIDI_tunes )[3];
// extern int(* hookvar_gRandom_Rockin_MIDI_tunes )[3];
extern int(* hookvar_gRandom_CDA_tunes )[7]; // addr: 00514958
extern int * hookvar_gCDA_is_playing ; // addr: 00514980
// extern int * hookvar_gServicing_sound ;
// extern int * hookvar_gSong_repeat_count ;
// extern int * hookvar_gSound_sources_inited ;
// extern int * hookvar_gMusic_available ;
// extern tS3_sound_tag * hookvar_gCDA_tag ;
extern int * hookvar_gCD_fully_installed ; // addr: 00514990
extern tS3_outlet_ptr * hookvar_gEffects_outlet ; // addr: 00514994
extern tS3_outlet_ptr * hookvar_gCar_outlet ; // addr: 00514998
extern tS3_outlet_ptr * hookvar_gEngine_outlet ; // addr: 0051499C
extern tS3_outlet_ptr * hookvar_gDriver_outlet ; // addr: 005149A0
extern tS3_outlet_ptr * hookvar_gPedestrians_outlet ; // addr: 005149A4
extern tS3_outlet_ptr * hookvar_gMusic_outlet ; // addr: 005149A8
// extern tS3_sound_id * hookvar_gMIDI_id ;
extern tS3_outlet_ptr(* hookvar_gIndexed_outlets )[6]; // addr: 00550A20
// extern tU32 * hookvar_gLast_sound_service ;
// extern int * hookvar_gCD_is_disabled ;
extern br_vector3 * hookvar_gCamera_left ; // addr: 00550A00
extern br_vector3 * hookvar_gCamera_position ; // addr: 00550A10
extern br_vector3 * hookvar_gOld_camera_position ; // addr: 00550A40
extern br_vector3 * hookvar_gCamera_velocity ; // addr: 00550A50

void __cdecl UsePathFileToDetermineIfFullInstallation();

void __cdecl InitSound();

tS3_sound_tag __cdecl DRS3StartSound(tS3_outlet_ptr pOutlet, tS3_sound_id pSound);

tS3_sound_tag __cdecl DRS3StartSoundNoPiping(tS3_outlet_ptr pOutlet, tS3_sound_id pSound);

tS3_sound_tag __cdecl DRS3StartSound2(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pLVolume, tS3_volume pRVolume, tS3_pitch pPitch, tS3_speed pSpeed);

int __cdecl DRS3ChangeVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_volume);

int __cdecl DRS3ChangeLRVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_Lvolume, tS3_volume pNew_Rvolume);

int __cdecl DRS3ChangePitch(tS3_sound_tag pTag, tS3_pitch pNew_pitch);

int __cdecl DRS3ChangeSpeed(tS3_sound_tag pTag, tS3_pitch pNew_speed);

int __cdecl DRS3ChangePitchSpeed(tS3_sound_tag pTag, tS3_pitch pNew_pitch);

int __cdecl DRS3StopSound(tS3_sound_tag pSound_tag);

int __cdecl DRS3LoadSound(tS3_sound_id pThe_sound);

int __cdecl DRS3ReleaseSound(tS3_sound_id pThe_sound);

void DRS3Service();

int __cdecl DRS3OutletSoundsPlaying(tS3_outlet_ptr pOutlet);

int __cdecl DRS3SoundStillPlaying(tS3_sound_tag pSound_tag);

void __cdecl DRS3ShutDown();

int __cdecl DRS3SetOutletVolume(tS3_outlet_ptr pOutlet, tS3_volume pVolume);

int __cdecl DRS3OverallVolume(tS3_volume pVolume);

int __cdecl DRS3StopOutletSound(tS3_outlet_ptr pOutlet);

int __cdecl DRS3StopAllOutletSounds();

void __cdecl ToggleSoundEnable();

void __cdecl SoundService();

void __cdecl InitSoundSources();

void __cdecl DisposeSoundSources();

tS3_sound_tag __cdecl DRS3StartSound3D(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, br_vector3 *pInitial_position, br_vector3 *pInitial_velocity, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed);

tS3_sound_tag __cdecl DRS3StartSoundFromSource3(tS3_sound_source_ptr pSource, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed);

tS3_sound_tag __cdecl DRS3StartSoundFromSource(tS3_sound_source_ptr pSource, tS3_sound_id pSound);

void __cdecl MungeEngineNoise();

void __cdecl SetSoundVolumes();

tS3_outlet_ptr __cdecl GetOutletFromIndex(int pIndex);

int __cdecl GetIndexFromOutlet(tS3_outlet_ptr pOutlet);

int __cdecl DRS3StartCDA(tS3_sound_id pCDA_id);

int __cdecl DRS3StopCDA();

void __cdecl StartMusic();

void __cdecl StopMusic();

#endif
