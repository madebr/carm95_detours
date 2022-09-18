#ifndef _CRUSH_H_
#define _CRUSH_H_

#include "br_types.h"
#include "dr_types.h"

extern float(* hookvar_gWobble_spam_y )[8]; // addr: 00521370
extern float(* hookvar_gWobble_spam_z )[8]; // addr: 00521390
extern br_scalar * hookvar_gWheel_circ_to_width ; // addr: 005213B0
extern tU8(* hookvar_gSmoke_damage_step )[12]; // addr: 005213B8
extern int(* hookvar_gSteal_ranks )[5]; // addr: 005213C4

int __cdecl ReadCrushData(FILE *pF, tCrush_data *pCrush_data);

float __cdecl SkipCrushData(FILE *pF);

int __cdecl WriteCrushData(FILE *pF, tCrush_data *pCrush_data);

void __cdecl DisposeCrushData(tCrush_data *pCrush_data);

void __cdecl CrushModelPoint(tCar_spec *pCar, int pModel_index, br_model *pModel, int pCrush_point_index, br_vector3 *pEnergy_vector, br_scalar total_energy, tCrush_data *pCrush_data);

void __cdecl CrushModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, br_vector3 *pImpact_point, br_vector3 *pEnergy_vector, tCrush_data *pCrush_data);

void __cdecl JitModelUpdate(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void __cdecl SetModelForUpdate(br_model *pModel, tCar_spec *pCar, int crush_only);

void __cdecl TotallySpamTheModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, tCrush_data *pCrush_data, br_scalar pMagnitude);

br_scalar __cdecl RepairModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, br_vertex *pUndamaged_vertices, br_scalar pAmount, br_scalar *pTotal_deflection);

float __cdecl RepairCar2(tCar_spec *pCar, tU32 pFrame_period, br_scalar *pTotal_deflection);

float __cdecl RepairCar(tU16 pCar_ID, tU32 pFrame_period, br_scalar *pTotal_deflection);

void __cdecl TotallyRepairACar(tCar_spec *pCar);

void __cdecl TotallyRepairCar();

void __cdecl CheckLastCar();

void __cdecl KnackerThisCar(tCar_spec *pCar);

void SetKnackeredFlag(tCar_spec *pCar);

void __cdecl DamageUnit2(tCar_spec *pCar, int pUnit_type, int pDamage_amount);

void __cdecl RecordLastDamage(tCar_spec *pCar);

void __cdecl DoDamage(tCar_spec *pCar, tDamage_type pDamage_type, float pMagnitude, float pNastiness);

void __cdecl CheckPiledriverBonus(tCar_spec *pCar, br_vector3 *pImpact_point, br_vector3 *pEnergy);

tImpact_location __cdecl CalcModifiedLocation(tCar_spec *pCar);

void __cdecl DoPratcamHit(br_vector3 *pHit_vector);

void __cdecl DamageSystems(tCar_spec *pCar, br_vector3 *pImpact_point, br_vector3 *pEnergy_vector, int pWas_hitting_a_car);

tImpact_location __cdecl GetDirection(br_vector3 *pVelocity);

void __cdecl SetSmokeLastDamageLevel(tCar_spec *pCar);

void __cdecl SortOutSmoke(tCar_spec *pCar);

void __cdecl StealCar(tCar_spec *pCar);

int __cdecl DoCrashEarnings(tCar_spec *pCar1, tCar_spec *pCar2);

void __cdecl DoWheelDamage(tU32 pFrame_period);

void __cdecl CrashEarnings(tCar_spec *pCar1, tCar_spec *pCar2);

#endif
