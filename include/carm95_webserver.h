
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HOOK_UNAVAILABLE = -1,
    HOOK_DISABLED = 0,
    HOOK_ENABLED = 1,
} function_hook_state_t;

typedef struct {
    function_hook_state_t *hook_state;
    const char *name;
    const char *location;
} function_hook_data_t;

int start_hook_webserver(int port);
void stop_hook_webserver(void);

#ifdef __cplusplus
}
#endif
