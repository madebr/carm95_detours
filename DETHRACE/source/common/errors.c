#include "errors.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
char *(* hookvar_gError_messages )[126] = (void*)0x005120a0;
int * hookvar_gError_code  = (void*)0x0051d424;
 // Suffix added to avoid duplicate symbol
#if 0
char ** hookvar_gPalette_copy__errors ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gPixel_buffer_size__errors ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gMouse_was_started__errors ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
char ** hookvar_gPixels_copy__errors ;
#endif

void FatalError_do_not_use(int pStr_index) {
    char the_str[1024];
    char *sub_str;
    char temp_str[1024];
    char *sub_pt;
    va_list ap;
    LOG_TRACE("(%d)", pStr_index);

    (void)pStr_index;
    (void)the_str;
    (void)sub_str;
    (void)temp_str;
    (void)sub_pt;
    (void)ap;

    NOT_IMPLEMENTED();
}

void NonFatalError_do_not_use(int pStr_index) {
    char the_str[256];
    char *sub_str;
    char temp_str[256];
    char *sub_pt;
    va_list ap;
    LOG_TRACE("(%d)", pStr_index);

    (void)pStr_index;
    (void)the_str;
    (void)sub_str;
    (void)temp_str;
    (void)sub_pt;
    (void)ap;

    NOT_IMPLEMENTED();
}

static void(*original_CloseDiagnostics)() = (void(*)())0x0046162f;
CARM95_HOOK_FUNCTION(original_CloseDiagnostics, CloseDiagnostics)
void CloseDiagnostics() {
    LOG_TRACE("()");


    original_CloseDiagnostics();
}

static void(*original_OpenDiagnostics)() = (void(*)())0x0046163a;
CARM95_HOOK_FUNCTION(original_OpenDiagnostics, OpenDiagnostics)
void OpenDiagnostics() {
    LOG_TRACE("()");


    original_OpenDiagnostics();
}

void dprintf(char *fmt_string) {
    LOG_TRACE("(\"%s\")", fmt_string);

    (void)fmt_string;

    NOT_IMPLEMENTED();
}

static int(*original_DoErrorInterface)(int, ...) = (int(*)(int, ...))0x00461650;
CARM95_HOOK_FUNCTION(original_DoErrorInterface, DoErrorInterface)
int DoErrorInterface(int pMisc_text_index) {
    LOG_TRACE("(%d)", pMisc_text_index);

    (void)pMisc_text_index;

    return original_DoErrorInterface(pMisc_text_index);
}

