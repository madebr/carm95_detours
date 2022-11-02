#include "objectc.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrObjectListAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrObjectListAllocate)
static void *(__cdecl*original_BrObjectListAllocate)(void *) = (void *(__cdecl*)(void *))0x004e63a0;
CARM95_HOOK_FUNCTION(original_BrObjectListAllocate, BrObjectListAllocate)
void* __cdecl BrObjectListAllocate(void *res) {
    struct object_list *hl;
    LOG_TRACE("(%p)", res);

    (void)res;
    (void)hl;

    if (function_hook_state_BrObjectListAllocate == HOOK_ENABLED) {
        assert(0 && "BrObjectListAllocate not implemented.");
        abort();
    } else {
        return original_BrObjectListAllocate(res);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_addFront = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_addFront)
static br_error(__cdecl*original__M_br_object_container_addFront)(struct br_object_container *, struct br_object *) = (br_error(__cdecl*)(struct br_object_container *, struct br_object *))0x004e63d0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_addFront, _M_br_object_container_addFront)
br_error __cdecl _M_br_object_container_addFront(struct br_object_container *self, struct br_object *ph) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, ph);

    (void)self;
    (void)ph;
    (void)hl;
    (void)he;

    if (function_hook_state__M_br_object_container_addFront == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_addFront not implemented.");
        abort();
    } else {
        return original__M_br_object_container_addFront(self, ph);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_remove = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_remove)
static br_error(__cdecl*original__M_br_object_container_remove)(struct br_object_container *, struct br_object *) = (br_error(__cdecl*)(struct br_object_container *, struct br_object *))0x004e6420;
CARM95_HOOK_FUNCTION(original__M_br_object_container_remove, _M_br_object_container_remove)
br_error __cdecl _M_br_object_container_remove(struct br_object_container *self, struct br_object *h) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, h);

    (void)self;
    (void)h;
    (void)hl;
    (void)he;

    if (function_hook_state__M_br_object_container_remove == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_remove not implemented.");
        abort();
    } else {
        return original__M_br_object_container_remove(self, h);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_removeFront = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_removeFront)
static br_error(__cdecl*original__M_br_object_container_removeFront)(struct br_object_container *, struct br_object **) = (br_error(__cdecl*)(struct br_object_container *, struct br_object **))0x004e6480;
CARM95_HOOK_FUNCTION(original__M_br_object_container_removeFront, _M_br_object_container_removeFront)
br_error __cdecl _M_br_object_container_removeFront(struct br_object_container *self, struct br_object **ph) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, ph);

    (void)self;
    (void)ph;
    (void)hl;
    (void)he;

    if (function_hook_state__M_br_object_container_removeFront == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_removeFront not implemented.");
        abort();
    } else {
        return original__M_br_object_container_removeFront(self, ph);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_find = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_find)
static br_error(__cdecl*original__M_br_object_container_find)(br_object_container *, br_object **, br_token, char *, br_token_value *) = (br_error(__cdecl*)(br_object_container *, br_object **, br_token, char *, br_token_value *))0x004e64d0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_find, _M_br_object_container_find)
br_error __cdecl _M_br_object_container_find(br_object_container *self, br_object **ph, br_token type, char *pattern, br_token_value *tv) {
    struct object_list *hl;
    struct object_list_entry *he;
    void *tvarg;
    br_error r;
    LOG_TRACE("(%p, %p, %d, \"%s\", %p)", self, ph, type, pattern, tv);

    (void)self;
    (void)ph;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)hl;
    (void)he;
    (void)tvarg;
    (void)r;

    if (function_hook_state__M_br_object_container_find == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_find not implemented.");
        abort();
    } else {
        return original__M_br_object_container_find(self, ph, type, pattern, tv);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_findMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_findMany)
static br_error(__cdecl*original__M_br_object_container_findMany)(br_object_container *, br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *) = (br_error(__cdecl*)(br_object_container *, br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *))0x004e65b0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_findMany, _M_br_object_container_findMany)
br_error __cdecl _M_br_object_container_findMany(br_object_container *self, br_object **objects, br_int_32 max_objects, br_int_32 *num_objects, br_token type, char *pattern, br_token_value *tv) {
    struct object_list *hl;
    struct object_list_entry *he;
    void *tvarg;
    int n;
    LOG_TRACE("(%p, %p, %d, %p, %d, \"%s\", %p)", self, objects, max_objects, num_objects, type, pattern, tv);

    (void)self;
    (void)objects;
    (void)max_objects;
    (void)num_objects;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)hl;
    (void)he;
    (void)tvarg;
    (void)n;

    if (function_hook_state__M_br_object_container_findMany == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_findMany not implemented.");
        abort();
    } else {
        return original__M_br_object_container_findMany(self, objects, max_objects, num_objects, type, pattern, tv);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_count = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_count)
static br_error(__cdecl*original__M_br_object_container_count)(br_object_container *, br_uint_32 *, br_token, char *, br_token_value *) = (br_error(__cdecl*)(br_object_container *, br_uint_32 *, br_token, char *, br_token_value *))0x004e66b0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_count, _M_br_object_container_count)
br_error __cdecl _M_br_object_container_count(br_object_container *self, br_uint_32 *pcount, br_token type, char *pattern, br_token_value *tv) {
    struct object_list *hl;
    struct object_list_entry *he;
    void *tvarg;
    int n;
    LOG_TRACE("(%p, %p, %d, \"%s\", %p)", self, pcount, type, pattern, tv);

    (void)self;
    (void)pcount;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)hl;
    (void)he;
    (void)tvarg;
    (void)n;

    if (function_hook_state__M_br_object_container_count == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_count not implemented.");
        abort();
    } else {
        return original__M_br_object_container_count(self, pcount, type, pattern, tv);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_tokensMatchBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_tokensMatchBegin)
static void *(__cdecl*original__M_br_object_container_tokensMatchBegin)(struct br_object_container *, br_token, br_token_value *) = (void *(__cdecl*)(struct br_object_container *, br_token, br_token_value *))0x004e6790;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatchBegin, _M_br_object_container_tokensMatchBegin)
void* __cdecl _M_br_object_container_tokensMatchBegin(struct br_object_container *self, br_token t, br_token_value *tv) {
    struct token_match *tm;
    br_int_32 i;
    LOG_TRACE("(%p, %d, %p)", self, t, tv);

    (void)self;
    (void)t;
    (void)tv;
    (void)tm;
    (void)i;

    if (function_hook_state__M_br_object_container_tokensMatchBegin == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_tokensMatchBegin not implemented.");
        abort();
    } else {
        return original__M_br_object_container_tokensMatchBegin(self, t, tv);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_tokensMatch = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_tokensMatch)
static br_boolean(__cdecl*original__M_br_object_container_tokensMatch)(struct br_object_container *, br_object *, void *) = (br_boolean(__cdecl*)(struct br_object_container *, br_object *, void *))0x004e6800;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatch, _M_br_object_container_tokensMatch)
br_boolean __cdecl _M_br_object_container_tokensMatch(struct br_object_container *self, br_object *h, void *arg) {
    struct token_match *tm;
    br_size_t s;
    br_int_32 n;
    LOG_TRACE("(%p, %p, %p)", self, h, arg);

    (void)self;
    (void)h;
    (void)arg;
    (void)tm;
    (void)s;
    (void)n;

    if (function_hook_state__M_br_object_container_tokensMatch == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_tokensMatch not implemented.");
        abort();
    } else {
        return original__M_br_object_container_tokensMatch(self, h, arg);
    }
}

function_hook_state_t function_hook_state__M_br_object_container_tokensMatchEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_container_tokensMatchEnd)
static void(__cdecl*original__M_br_object_container_tokensMatchEnd)(struct br_object_container *, void *) = (void(__cdecl*)(struct br_object_container *, void *))0x004e68a0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatchEnd, _M_br_object_container_tokensMatchEnd)
void __cdecl _M_br_object_container_tokensMatchEnd(struct br_object_container *self, void *arg) {
    LOG_TRACE("(%p, %p)", self, arg);

    (void)self;
    (void)arg;

    if (function_hook_state__M_br_object_container_tokensMatchEnd == HOOK_ENABLED) {
        assert(0 && "_M_br_object_container_tokensMatchEnd not implemented.");
        abort();
    } else {
        original__M_br_object_container_tokensMatchEnd(self, arg);
    }
}

function_hook_state_t function_hook_state_BrObjectContainerFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrObjectContainerFree)
static br_error(__cdecl*original_BrObjectContainerFree)(br_object_container *, br_token, char *, br_token_value *) = (br_error(__cdecl*)(br_object_container *, br_token, char *, br_token_value *))0x004e68c0;
CARM95_HOOK_FUNCTION(original_BrObjectContainerFree, BrObjectContainerFree)
br_error __cdecl BrObjectContainerFree(br_object_container *self, br_token type, char *pattern, br_token_value *tv) {
    br_error r;
    br_object **handles;
    br_int_32 count;
    br_int_32 n;
    br_int_32 i;
    LOG_TRACE("(%p, %d, \"%s\", %p)", self, type, pattern, tv);

    (void)self;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)r;
    (void)handles;
    (void)count;
    (void)n;
    (void)i;

    if (function_hook_state_BrObjectContainerFree == HOOK_ENABLED) {
        assert(0 && "BrObjectContainerFree not implemented.");
        abort();
    } else {
        return original_BrObjectContainerFree(self, type, pattern, tv);
    }
}

