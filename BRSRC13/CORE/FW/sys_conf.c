#include "sys_conf.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_token(* hookvar_valid_system_config_tokens )[5] = (void*)0x0052ce20;

br_boolean Is_Valid_Sys_Config_Token(br_token t) {
    br_boolean bOK;
    int i;
    LOG_TRACE("(%d)", t);

    (void)t;
    (void)bOK;
    (void)i;

    NOT_IMPLEMENTED();
}

static br_boolean(__stdcall*original_LoadIniEntry)(char *, char *, br_token, char *) = (br_boolean(__stdcall*)(char *, char *, br_token, char *))0x004e85d0;
CARM95_HOOK_FUNCTION(original_LoadIniEntry, LoadIniEntry)
br_boolean __stdcall LoadIniEntry(char *ini_file, char *section_name, br_token t, char *Entry) {
    char Temp[255];
    br_uint_16 size;
    br_value v;
    br_error r;
    LOG_TRACE("(\"%s\", \"%s\", %d, \"%s\")", ini_file, section_name, t, Entry);

    (void)ini_file;
    (void)section_name;
    (void)t;
    (void)Entry;
    (void)Temp;
    (void)size;
    (void)v;
    (void)r;

    return original_LoadIniEntry(ini_file, section_name, t, Entry);
}

br_error LoadIniConfig(char *ini_file, char *section_name) {
    LOG_TRACE("(\"%s\", \"%s\")", ini_file, section_name);

    (void)ini_file;
    (void)section_name;

    NOT_IMPLEMENTED();
}

static br_boolean(__stdcall*original_LoadRegistryEntry)(char *, void *, br_token, char *) = (br_boolean(__stdcall*)(char *, void *, br_token, char *))0x004e8640;
CARM95_HOOK_FUNCTION(original_LoadRegistryEntry, LoadRegistryEntry)
br_boolean __stdcall LoadRegistryEntry(char *Reg_Path, void *hKey, br_token t, char *Entry) {
    char Temp[255];
    br_uint_16 size;
    br_value v;
    br_error r;
    LOG_TRACE("(\"%s\", %p, %d, \"%s\")", Reg_Path, hKey, t, Entry);

    (void)Reg_Path;
    (void)hKey;
    (void)t;
    (void)Entry;
    (void)Temp;
    (void)size;
    (void)v;
    (void)r;

    return original_LoadRegistryEntry(Reg_Path, hKey, t, Entry);
}

br_error LoadRegistryConfig(char *Reg_Path, void *hKey) {
    LOG_TRACE("(\"%s\", %p)", Reg_Path, hKey);

    (void)Reg_Path;
    (void)hKey;

    NOT_IMPLEMENTED();
}

static br_error(__stdcall*original_BrSetDefaultConfig)(br_token, char *) = (br_error(__stdcall*)(br_token, char *))0x004e86b0;
CARM95_HOOK_FUNCTION(original_BrSetDefaultConfig, BrSetDefaultConfig)
br_error __stdcall BrSetDefaultConfig(br_token t, char *Entry) {
    char Reg_Path[255];
    int v0;
    int v1;
    int v2;
    br_value v;
    char __block0__Buffer[255];
    LOG_TRACE("(%d, \"%s\")", t, Entry);

    (void)t;
    (void)Entry;
    (void)Reg_Path;
    (void)v0;
    (void)v1;
    (void)v2;
    (void)v;
    (void)__block0__Buffer;

    return original_BrSetDefaultConfig(t, Entry);
}

static br_error(__stdcall*original_BrSystemConfigBegin)() = (br_error(__stdcall*)())0x004e8180;
CARM95_HOOK_FUNCTION(original_BrSystemConfigBegin, BrSystemConfigBegin)
br_error __stdcall BrSystemConfigBegin() {
    char temp[255];
    br_value v;
    LOG_TRACE("()");

    (void)temp;
    (void)v;

    return original_BrSystemConfigBegin();
}

static br_error(__cdecl*original_BrSystemConfigLoad)(br_token, char *, void *) = (br_error(__cdecl*)(br_token, char *, void *))0x004e8770;
CARM95_HOOK_FUNCTION(original_BrSystemConfigLoad, BrSystemConfigLoad)
br_error __cdecl BrSystemConfigLoad(br_token t, char *Param1, void *Param2) {
    br_error r;
    LOG_TRACE("(%d, \"%s\", %p)", t, Param1, Param2);

    (void)t;
    (void)Param1;
    (void)Param2;
    (void)r;

    return original_BrSystemConfigLoad(t, Param1, Param2);
}

static br_error(__cdecl*original_BrSystemConfigSetString)(br_token, char *) = (br_error(__cdecl*)(br_token, char *))0x004e8a8c;
CARM95_HOOK_FUNCTION(original_BrSystemConfigSetString, BrSystemConfigSetString)
br_error __cdecl BrSystemConfigSetString(br_token t, char *string) {
    br_value v;
    LOG_TRACE("(%d, \"%s\")", t, string);

    (void)t;
    (void)string;
    (void)v;

    return original_BrSystemConfigSetString(t, string);
}

static br_error(__cdecl*original_BrSystemConfigQueryString)(br_token, char *, int) = (br_error(__cdecl*)(br_token, char *, int))0x004e8b00;
CARM95_HOOK_FUNCTION(original_BrSystemConfigQueryString, BrSystemConfigQueryString)
br_error __cdecl BrSystemConfigQueryString(br_token t, char *string, int max_size) {
    br_error r;
    br_value v;
    LOG_TRACE("(%d, \"%s\", %d)", t, string, max_size);

    (void)t;
    (void)string;
    (void)max_size;
    (void)r;
    (void)v;

    return original_BrSystemConfigQueryString(t, string, max_size);
}

