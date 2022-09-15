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
// extern tS3_outlet_ptr(* hookvar_gIndexed_outlets )[6];
// extern tU32 * hookvar_gLast_sound_service ;
// extern int * hookvar_gCD_is_disabled ;
extern br_vector3 * hookvar_gCamera_left ; // addr: 00550A00
extern br_vector3 * hookvar_gCamera_position ; // addr: 00550A10
extern br_vector3 * hookvar_gOld_camera_position ; // addr: 00550A40
extern br_vector3 * hookvar_gCamera_velocity ; // addr: 00550A50

void UsePathFileToDetermineIfFullInstallation();

void InitSound();

tS3_sound_tag DRS3StartSound(tS3_outlet_ptr pOutlet, tS3_sound_id pSound);

tS3_sound_tag DRS3StartSoundNoPiping(tS3_outlet_ptr pOutlet, tS3_sound_id pSound);

tS3_sound_tag DRS3StartSound2(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pLVolume, tS3_volume pRVolume, tS3_pitch pPitch, tS3_speed pSpeed);

int DRS3ChangeVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_volume);

int DRS3ChangeLRVolume(tS3_sound_tag pSound_tag, tS3_volume pNew_Lvolume, tS3_volume pNew_Rvolume);

int DRS3ChangePitch(tS3_sound_tag pTag, tS3_pitch pNew_pitch);

int DRS3ChangeSpeed(tS3_sound_tag pTag, tS3_pitch pNew_speed);

int DRS3ChangePitchSpeed(tS3_sound_tag pTag, tS3_pitch pNew_pitch);

int DRS3StopSound(tS3_sound_tag pSound_tag);

int DRS3LoadSound(tS3_sound_id pThe_sound);

int DRS3ReleaseSound(tS3_sound_id pThe_sound);

void DRS3Service();

int DRS3OutletSoundsPlaying(tS3_outlet_ptr pOutlet);

int DRS3SoundStillPlaying(tS3_sound_tag pSound_tag);

void DRS3ShutDown();

int DRS3SetOutletVolume(tS3_outlet_ptr pOutlet, tS3_volume pVolume);

int DRS3OverallVolume(tS3_volume pVolume);

int DRS3StopOutletSound(tS3_outlet_ptr pOutlet);

int DRS3StopAllOutletSounds();

void ToggleSoundEnable();

void SoundService();

void InitSoundSources();

void DisposeSoundSources();

tS3_sound_tag DRS3StartSound3D(tS3_outlet_ptr pOutlet, tS3_sound_id pSound, br_vector3 *pInitial_position, br_vector3 *pInitial_velocity, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed);

tS3_sound_tag DRS3StartSoundFromSource3(tS3_sound_source_ptr pSource, tS3_sound_id pSound, tS3_repeats pRepeats, tS3_volume pVolume, tS3_pitch pPitch, tS3_speed pSpeed);

tS3_sound_tag DRS3StartSoundFromSource(tS3_sound_source_ptr pSource, tS3_sound_id pSound);

void MungeEngineNoise();

void SetSoundVolumes();

tS3_outlet_ptr GetOutletFromIndex(int pIndex);

int GetIndexFromOutlet(tS3_outlet_ptr pOutlet);

int DRS3StartCDA(tS3_sound_id pCDA_id);

int DRS3StopCDA();

void StartMusic();

void StopMusic();

#endif
