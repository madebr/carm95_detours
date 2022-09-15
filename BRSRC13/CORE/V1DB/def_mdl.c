#include "def_mdl.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_vertex(* hookvar_default_model_vertices )[8] = (void*)0x00525b40;
br_face(* hookvar_default_model_faces )[12] = (void*)0x00525c80;
br_model * hookvar__BrDefaultModel  = (void*)0x00525e60;

