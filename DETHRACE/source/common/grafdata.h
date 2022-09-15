#ifndef _GRAFDATA_H_
#define _GRAFDATA_H_

#include "br_types.h"
#include "dr_types.h"

extern tGraf_data(* hookvar_gGraf_data )[2]; // addr: 0050BCF0
extern tGraf_data ** hookvar_gCurrent_graf_data ; // addr: 00551D88
extern int * hookvar_gGraf_data_index ; // addr: 00551D84

void CalcGrafDataIndex();

#endif
