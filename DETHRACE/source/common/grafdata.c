#include "grafdata.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
tGraf_data(* hookvar_gGraf_data )[2] = (void*)0x0050bcf0;
tGraf_data ** hookvar_gCurrent_graf_data  = (void*)0x00551d88;
int * hookvar_gGraf_data_index  = (void*)0x00551d84;

static void(*original_CalcGrafDataIndex)() = (void(*)())0x0042f200;
CARM95_HOOK_FUNCTION(original_CalcGrafDataIndex, CalcGrafDataIndex)
void CalcGrafDataIndex() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CalcGrafDataIndex();
}

