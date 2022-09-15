#include "globvrme.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
tCar_spec *(* hookvar_gViewable_car_list )[50] = (void*)0x005508f0;
int * hookvar_gNum_viewable_cars  = (void*)0x005509b8;

