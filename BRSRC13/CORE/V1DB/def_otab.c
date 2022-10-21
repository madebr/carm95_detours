#include "def_otab.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_order_table * hookvar__BrDefaultOrderTable  = (void*)0x00525ec8;
void *(* hookvar__default_table )[256] = (void*)0x00541688;

