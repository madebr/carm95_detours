#include "demo.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gLast_demo  = (void*)0x00512080;

function_hook_state_t function_hook_state_DoDemo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoDemo, function_hook_state_DoDemo)
static void(__cdecl*original_DoDemo)() = (void(__cdecl*)())0x00461110;
CARM95_HOOK_FUNCTION(original_DoDemo, DoDemo)
void __cdecl DoDemo() {
    tS32 start_time;
    tS32 frame_time;
    FILE *f;
    tPath_name the_path;
    int i;
    int count;
    char s[256];
    char *str;
    tS3_sound_tag song_tag;
    LOG_TRACE("()");

    (void)start_time;
    (void)frame_time;
    (void)f;
    (void)the_path;
    (void)i;
    (void)count;
    (void)s;
    (void)str;
    (void)song_tag;

    if (function_hook_state_DoDemo == HOOK_ENABLED) {
        assert(0 && "DoDemo not implemented.");
        abort();
    } else {
        original_DoDemo();
    }
}

