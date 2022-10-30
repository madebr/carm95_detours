#include "errors.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

void(__cdecl*FatalError)(int, ...) = (void*)0x00461390;
function_hook_state_t function_hook_state_FatalError = HOOK_UNAVAILABLE;
#if 0
void(__cdecl*FatalError)(int) = (void(__cdecl*)(int))0x00461390;
void FatalError_do_not_use(int pStr_index, ...) {
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

    if (function_hook_state_FatalError == HOOK_ENABLED) {
        assert(0 && "FatalError_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}
#endif

void(__cdecl*NonFatalError)(int, ...) = (void*)0x004614f1;
function_hook_state_t function_hook_state_NonFatalError = HOOK_UNAVAILABLE;
#if 0
void(__cdecl*NonFatalError)(int) = (void(__cdecl*)(int))0x004614f1;
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

    if (function_hook_state_NonFatalError == HOOK_ENABLED) {
        assert(0 && "NonFatalError_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}
#endif

function_hook_state_t function_hook_state_CloseDiagnostics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CloseDiagnostics)
static void(__cdecl*original_CloseDiagnostics)() = (void(__cdecl*)())0x0046162f;
CARM95_HOOK_FUNCTION(original_CloseDiagnostics, CloseDiagnostics)
void __cdecl CloseDiagnostics() {
    LOG_TRACE("()");


    if (function_hook_state_CloseDiagnostics == HOOK_ENABLED) {
        assert(0 && "CloseDiagnostics not implemented.");
        abort();
    } else {
        original_CloseDiagnostics();
    }
}

function_hook_state_t function_hook_state_OpenDiagnostics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_OpenDiagnostics)
static void(__cdecl*original_OpenDiagnostics)() = (void(__cdecl*)())0x0046163a;
CARM95_HOOK_FUNCTION(original_OpenDiagnostics, OpenDiagnostics)
void __cdecl OpenDiagnostics() {
    LOG_TRACE("()");


    if (function_hook_state_OpenDiagnostics == HOOK_ENABLED) {
        assert(0 && "OpenDiagnostics not implemented.");
        abort();
    } else {
        original_OpenDiagnostics();
    }
}

void(__cdecl*dr_dprintf)(char*, ...) = (void*)0x00461645;
function_hook_state_t function_hook_state_dr_dprintf = HOOK_UNAVAILABLE;
#if 0
CARM95_WEBSERVER_STATE(function_hook_state_dr_dprintf)
void dr_dprintf(char *fmt_string) {
    LOG_TRACE("(\"%s\")", fmt_string);

    (void)fmt_string;

    if (function_hook_state_dr_dprintf == HOOK_ENABLED) {
        assert(0 && "dprintf not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}
#endif

function_hook_state_t function_hook_state_DoErrorInterface = HOOK_UNAVAILABLE;
static int(__cdecl*original_DoErrorInterface)(int) = (int(__cdecl*)(int))0x00461650;
CARM95_HOOK_FUNCTION(original_DoErrorInterface, DoErrorInterface)
int __cdecl DoErrorInterface(int pMisc_text_index) {
    LOG_TRACE("(%d)", pMisc_text_index);

    (void)pMisc_text_index;

    if (function_hook_state_DoErrorInterface == HOOK_ENABLED) {
        assert(0 && "DoErrorInterface not implemented.");
        abort();
    } else {
        return original_DoErrorInterface(pMisc_text_index);
    }
}

