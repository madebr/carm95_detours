#include "objectc.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void *(*original_BrObjectListAllocate)(void *, ...) = (void *(*)(void *, ...))0x004e63a0;
CARM95_HOOK_FUNCTION(original_BrObjectListAllocate, BrObjectListAllocate)
void* BrObjectListAllocate(void *res) {
    struct object_list *hl;
    LOG_TRACE("(%p)", res);

    (void)res;
    (void)hl;

    return original_BrObjectListAllocate(res);
}

static br_error(*original__M_br_object_container_addFront)(struct br_object_container *, struct br_object *, ...) = (br_error(*)(struct br_object_container *, struct br_object *, ...))0x004e63d0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_addFront, _M_br_object_container_addFront)
br_error _M_br_object_container_addFront(struct br_object_container *self, struct br_object *ph) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, ph);

    (void)self;
    (void)ph;
    (void)hl;
    (void)he;

    return original__M_br_object_container_addFront(self, ph);
}

static br_error(*original__M_br_object_container_remove)(struct br_object_container *, struct br_object *, ...) = (br_error(*)(struct br_object_container *, struct br_object *, ...))0x004e6420;
CARM95_HOOK_FUNCTION(original__M_br_object_container_remove, _M_br_object_container_remove)
br_error _M_br_object_container_remove(struct br_object_container *self, struct br_object *h) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, h);

    (void)self;
    (void)h;
    (void)hl;
    (void)he;

    return original__M_br_object_container_remove(self, h);
}

static br_error(*original__M_br_object_container_removeFront)(struct br_object_container *, struct br_object **, ...) = (br_error(*)(struct br_object_container *, struct br_object **, ...))0x004e6480;
CARM95_HOOK_FUNCTION(original__M_br_object_container_removeFront, _M_br_object_container_removeFront)
br_error _M_br_object_container_removeFront(struct br_object_container *self, struct br_object **ph) {
    struct object_list *hl;
    struct object_list_entry *he;
    LOG_TRACE("(%p, %p)", self, ph);

    (void)self;
    (void)ph;
    (void)hl;
    (void)he;

    return original__M_br_object_container_removeFront(self, ph);
}

static br_error(*original__M_br_object_container_find)(br_object_container *, br_object **, br_token, char *, br_token_value *, ...) = (br_error(*)(br_object_container *, br_object **, br_token, char *, br_token_value *, ...))0x004e64d0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_find, _M_br_object_container_find)
br_error _M_br_object_container_find(br_object_container *self, br_object **ph, br_token type, char *pattern, br_token_value *tv) {
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

    return original__M_br_object_container_find(self, ph, type, pattern, tv);
}

static br_error(*original__M_br_object_container_findMany)(br_object_container *, br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *, ...) = (br_error(*)(br_object_container *, br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *, ...))0x004e65b0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_findMany, _M_br_object_container_findMany)
br_error _M_br_object_container_findMany(br_object_container *self, br_object **objects, br_int_32 max_objects, br_int_32 *num_objects, br_token type, char *pattern, br_token_value *tv) {
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

    return original__M_br_object_container_findMany(self, objects, max_objects, num_objects, type, pattern, tv);
}

static br_error(*original__M_br_object_container_count)(br_object_container *, br_uint_32 *, br_token, char *, br_token_value *, ...) = (br_error(*)(br_object_container *, br_uint_32 *, br_token, char *, br_token_value *, ...))0x004e66b0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_count, _M_br_object_container_count)
br_error _M_br_object_container_count(br_object_container *self, br_uint_32 *pcount, br_token type, char *pattern, br_token_value *tv) {
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

    return original__M_br_object_container_count(self, pcount, type, pattern, tv);
}

static void *(*original__M_br_object_container_tokensMatchBegin)(struct br_object_container *, br_token, br_token_value *, ...) = (void *(*)(struct br_object_container *, br_token, br_token_value *, ...))0x004e6790;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatchBegin, _M_br_object_container_tokensMatchBegin)
void* _M_br_object_container_tokensMatchBegin(struct br_object_container *self, br_token t, br_token_value *tv) {
    struct token_match *tm;
    br_int_32 i;
    LOG_TRACE("(%p, %d, %p)", self, t, tv);

    (void)self;
    (void)t;
    (void)tv;
    (void)tm;
    (void)i;

    return original__M_br_object_container_tokensMatchBegin(self, t, tv);
}

static br_boolean(*original__M_br_object_container_tokensMatch)(struct br_object_container *, br_object *, void *, ...) = (br_boolean(*)(struct br_object_container *, br_object *, void *, ...))0x004e6800;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatch, _M_br_object_container_tokensMatch)
br_boolean _M_br_object_container_tokensMatch(struct br_object_container *self, br_object *h, void *arg) {
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

    return original__M_br_object_container_tokensMatch(self, h, arg);
}

static void(*original__M_br_object_container_tokensMatchEnd)(struct br_object_container *, void *, ...) = (void(*)(struct br_object_container *, void *, ...))0x004e68a0;
CARM95_HOOK_FUNCTION(original__M_br_object_container_tokensMatchEnd, _M_br_object_container_tokensMatchEnd)
void _M_br_object_container_tokensMatchEnd(struct br_object_container *self, void *arg) {
    LOG_TRACE("(%p, %p)", self, arg);

    (void)self;
    (void)arg;

    original__M_br_object_container_tokensMatchEnd(self, arg);
}

static br_error(*original_BrObjectContainerFree)(br_object_container *, br_token, char *, br_token_value *, ...) = (br_error(*)(br_object_container *, br_token, char *, br_token_value *, ...))0x004e68c0;
CARM95_HOOK_FUNCTION(original_BrObjectContainerFree, BrObjectContainerFree)
br_error BrObjectContainerFree(br_object_container *self, br_token type, char *pattern, br_token_value *tv) {
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

    return original_BrObjectContainerFree(self, type, pattern, tv);
}

