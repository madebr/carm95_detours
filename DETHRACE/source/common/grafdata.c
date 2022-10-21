#include "grafdata.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tGraf_data(* hookvar_gGraf_data )[2] = (void*)0x0050bcf0;
tGraf_data ** hookvar_gCurrent_graf_data  = (void*)0x00551d88;
int * hookvar_gGraf_data_index  = (void*)0x00551d84;

function_hook_state_t function_hook_state_CalcGrafDataIndex = HOOK_UNAVAILABLE;
static void(__cdecl*original_CalcGrafDataIndex)() = (void(__cdecl*)())0x0042f200;
CARM95_HOOK_FUNCTION(original_CalcGrafDataIndex, CalcGrafDataIndex)
void __cdecl CalcGrafDataIndex() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_CalcGrafDataIndex == HOOK_ENABLED) {
        assert(0 && "CalcGrafDataIndex not implemented.");
        abort();
    } else {
        original_CalcGrafDataIndex();
    }
}

