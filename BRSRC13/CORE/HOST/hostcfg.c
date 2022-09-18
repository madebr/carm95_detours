#include "hostcfg.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static char *(__stdcall*original_HostDefaultDevice)() = (char *(__stdcall*)())0x005013c0;
CARM95_HOOK_FUNCTION(original_HostDefaultDevice, HostDefaultDevice)
char* __stdcall HostDefaultDevice() {
    LOG_TRACE("()");


    return original_HostDefaultDevice();
}

static br_boolean(__cdecl*original_HostIniSectionExists)(char *, char *) = (br_boolean(__cdecl*)(char *, char *))0x005013d0;
CARM95_HOOK_FUNCTION(original_HostIniSectionExists, HostIniSectionExists)
br_boolean __cdecl HostIniSectionExists(char *ini_file, char *section_name) {
    LOG_TRACE("(\"%s\", \"%s\")", ini_file, section_name);

    (void)ini_file;
    (void)section_name;

    return original_HostIniSectionExists(ini_file, section_name);
}

static br_error(__cdecl*original_HostIniQuery)(char *, char *, char *, char *, int, br_uint_16 *) = (br_error(__cdecl*)(char *, char *, char *, char *, int, br_uint_16 *))0x00501400;
CARM95_HOOK_FUNCTION(original_HostIniQuery, HostIniQuery)
br_error __cdecl HostIniQuery(char *ini_file, char *section_name, char *entry, char *Buffer, int max, br_uint_16 *size) {
    LOG_TRACE("(\"%s\", \"%s\", \"%s\", \"%s\", %d, %p)", ini_file, section_name, entry, Buffer, max, size);

    (void)ini_file;
    (void)section_name;
    (void)entry;
    (void)Buffer;
    (void)max;
    (void)size;

    return original_HostIniQuery(ini_file, section_name, entry, Buffer, max, size);
}

static br_error(__cdecl*original_HostRegistryQuery)(void *, char *, char *, char *, br_uint_16, br_uint_16 *) = (br_error(__cdecl*)(void *, char *, char *, char *, br_uint_16, br_uint_16 *))0x00501430;
CARM95_HOOK_FUNCTION(original_HostRegistryQuery, HostRegistryQuery)
br_error __cdecl HostRegistryQuery(void *hKey, char *Path, char *entry, char *Buffer, br_uint_16 max, br_uint_16 *size) {
    LOG_TRACE("(%p, \"%s\", \"%s\", \"%s\", %u, %p)", hKey, Path, entry, Buffer, max, size);

    (void)hKey;
    (void)Path;
    (void)entry;
    (void)Buffer;
    (void)max;
    (void)size;

    return original_HostRegistryQuery(hKey, Path, entry, Buffer, max, size);
}

