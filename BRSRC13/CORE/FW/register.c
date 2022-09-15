#include "register.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void *(*original_BrRegistryNew)(br_registry *, ...) = (void *(*)(br_registry *, ...))0x004e5930;
CARM95_HOOK_FUNCTION(original_BrRegistryNew, BrRegistryNew)
void* BrRegistryNew(br_registry *reg) {
    LOG_TRACE("(%p)", reg);

    (void)reg;

    return original_BrRegistryNew(reg);
}

static void *(*original_BrRegistryClear)(br_registry *, ...) = (void *(*)(br_registry *, ...))0x004e5950;
CARM95_HOOK_FUNCTION(original_BrRegistryClear, BrRegistryClear)
void* BrRegistryClear(br_registry *reg) {
    br_registry_entry *e;
    LOG_TRACE("(%p)", reg);

    (void)reg;
    (void)e;

    return original_BrRegistryClear(reg);
}

static void *(*original_BrRegistryAdd)(br_registry *, void *, ...) = (void *(*)(br_registry *, void *, ...))0x004e5990;
CARM95_HOOK_FUNCTION(original_BrRegistryAdd, BrRegistryAdd)
void* BrRegistryAdd(br_registry *reg, void *item) {
    br_registry_entry *e;
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;
    (void)e;

    return original_BrRegistryAdd(reg, item);
}

static int(*original_BrRegistryAddMany)(br_registry *, void **, int, ...) = (int(*)(br_registry *, void **, int, ...))0x004e59d0;
CARM95_HOOK_FUNCTION(original_BrRegistryAddMany, BrRegistryAddMany)
int BrRegistryAddMany(br_registry *reg, void **items, int n) {
    int i;
    LOG_TRACE("(%p, %p, %d)", reg, items, n);

    (void)reg;
    (void)items;
    (void)n;
    (void)i;

    return original_BrRegistryAddMany(reg, items, n);
}

static void *(*original_BrRegistryRemove)(br_registry *, void *, ...) = (void *(*)(br_registry *, void *, ...))0x004e5a30;
CARM95_HOOK_FUNCTION(original_BrRegistryRemove, BrRegistryRemove)
void* BrRegistryRemove(br_registry *reg, void *item) {
    br_registry_entry *e;
    void *r;
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;
    (void)e;
    (void)r;

    return original_BrRegistryRemove(reg, item);
}

static int(*original_BrRegistryRemoveMany)(br_registry *, void **, int, ...) = (int(*)(br_registry *, void **, int, ...))0x004e5a90;
CARM95_HOOK_FUNCTION(original_BrRegistryRemoveMany, BrRegistryRemoveMany)
int BrRegistryRemoveMany(br_registry *reg, void **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %p, %d)", reg, items, n);

    (void)reg;
    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrRegistryRemoveMany(reg, items, n);
}

static void *(*original_BrRegistryFind)(br_registry *, char *, ...) = (void *(*)(br_registry *, char *, ...))0x004e5b20;
CARM95_HOOK_FUNCTION(original_BrRegistryFind, BrRegistryFind)
void* BrRegistryFind(br_registry *reg, char *pattern) {
    br_registry_entry *e;
    LOG_TRACE("(%p, \"%s\")", reg, pattern);

    (void)reg;
    (void)pattern;
    (void)e;

    return original_BrRegistryFind(reg, pattern);
}

static int(*original_BrRegistryFindMany)(br_registry *, char *, void **, int, ...) = (int(*)(br_registry *, char *, void **, int, ...))0x004e5b80;
CARM95_HOOK_FUNCTION(original_BrRegistryFindMany, BrRegistryFindMany)
int BrRegistryFindMany(br_registry *reg, char *pattern, void **items, int max) {
    br_registry_entry *e;
    int n;
    LOG_TRACE("(%p, \"%s\", %p, %d)", reg, pattern, items, max);

    (void)reg;
    (void)pattern;
    (void)items;
    (void)max;
    (void)e;
    (void)n;

    return original_BrRegistryFindMany(reg, pattern, items, max);
}

static int(*original_BrRegistryCount)(br_registry *, char *, ...) = (int(*)(br_registry *, char *, ...))0x004e5be0;
CARM95_HOOK_FUNCTION(original_BrRegistryCount, BrRegistryCount)
int BrRegistryCount(br_registry *reg, char *pattern) {
    br_registry_entry *e;
    int n;
    LOG_TRACE("(%p, \"%s\")", reg, pattern);

    (void)reg;
    (void)pattern;
    (void)e;
    (void)n;

    return original_BrRegistryCount(reg, pattern);
}

static int(*original_BrRegistryEnum)(br_registry *, char *, br_enum_cbfn *, void *, ...) = (int(*)(br_registry *, char *, br_enum_cbfn *, void *, ...))0x004e5c30;
CARM95_HOOK_FUNCTION(original_BrRegistryEnum, BrRegistryEnum)
int BrRegistryEnum(br_registry *reg, char *pattern, br_enum_cbfn *callback, void *arg) {
    br_registry_entry *e;
    int r;
    LOG_TRACE("(%p, \"%s\", %p, %p)", reg, pattern, callback, arg);

    (void)reg;
    (void)pattern;
    (void)callback;
    (void)arg;
    (void)e;
    (void)r;

    return original_BrRegistryEnum(reg, pattern, callback, arg);
}

static void *(*original_BrRegistryNewStatic)(br_registry *, br_registry_entry *, int, ...) = (void *(*)(br_registry *, br_registry_entry *, int, ...))0x004e5cc0;
CARM95_HOOK_FUNCTION(original_BrRegistryNewStatic, BrRegistryNewStatic)
void* BrRegistryNewStatic(br_registry *reg, br_registry_entry *base, int limit) {
    LOG_TRACE("(%p, %p, %d)", reg, base, limit);

    (void)reg;
    (void)base;
    (void)limit;

    return original_BrRegistryNewStatic(reg, base, limit);
}

static void *(*original_BrRegistryAddStatic)(br_registry *, br_registry_entry *, void *, ...) = (void *(*)(br_registry *, br_registry_entry *, void *, ...))0x004e5cd0;
CARM95_HOOK_FUNCTION(original_BrRegistryAddStatic, BrRegistryAddStatic)
void* BrRegistryAddStatic(br_registry *reg, br_registry_entry *base, void *item) {
    LOG_TRACE("(%p, %p, %p)", reg, base, item);

    (void)reg;
    (void)base;
    (void)item;

    return original_BrRegistryAddStatic(reg, base, item);
}

static void *(*original_BrRegistryRemoveStatic)(br_registry *, void *, ...) = (void *(*)(br_registry *, void *, ...))0x004e5ce0;
CARM95_HOOK_FUNCTION(original_BrRegistryRemoveStatic, BrRegistryRemoveStatic)
void* BrRegistryRemoveStatic(br_registry *reg, void *item) {
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;

    return original_BrRegistryRemoveStatic(reg, item);
}

