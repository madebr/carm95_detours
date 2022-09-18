#include "register.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void *(__stdcall*original_BrRegistryNew)(br_registry *) = (void *(__stdcall*)(br_registry *))0x004e5930;
CARM95_HOOK_FUNCTION(original_BrRegistryNew, BrRegistryNew)
void* __stdcall BrRegistryNew(br_registry *reg) {
    LOG_TRACE("(%p)", reg);

    (void)reg;

    return original_BrRegistryNew(reg);
}

static void *(__stdcall*original_BrRegistryClear)(br_registry *) = (void *(__stdcall*)(br_registry *))0x004e5950;
CARM95_HOOK_FUNCTION(original_BrRegistryClear, BrRegistryClear)
void* __stdcall BrRegistryClear(br_registry *reg) {
    br_registry_entry *e;
    LOG_TRACE("(%p)", reg);

    (void)reg;
    (void)e;

    return original_BrRegistryClear(reg);
}

static void *(__stdcall*original_BrRegistryAdd)(br_registry *, void *) = (void *(__stdcall*)(br_registry *, void *))0x004e5990;
CARM95_HOOK_FUNCTION(original_BrRegistryAdd, BrRegistryAdd)
void* __stdcall BrRegistryAdd(br_registry *reg, void *item) {
    br_registry_entry *e;
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;
    (void)e;

    return original_BrRegistryAdd(reg, item);
}

static int(__stdcall*original_BrRegistryAddMany)(br_registry *, void **, int) = (int(__stdcall*)(br_registry *, void **, int))0x004e59d0;
CARM95_HOOK_FUNCTION(original_BrRegistryAddMany, BrRegistryAddMany)
int __stdcall BrRegistryAddMany(br_registry *reg, void **items, int n) {
    int i;
    LOG_TRACE("(%p, %p, %d)", reg, items, n);

    (void)reg;
    (void)items;
    (void)n;
    (void)i;

    return original_BrRegistryAddMany(reg, items, n);
}

static void *(__stdcall*original_BrRegistryRemove)(br_registry *, void *) = (void *(__stdcall*)(br_registry *, void *))0x004e5a30;
CARM95_HOOK_FUNCTION(original_BrRegistryRemove, BrRegistryRemove)
void* __stdcall BrRegistryRemove(br_registry *reg, void *item) {
    br_registry_entry *e;
    void *r;
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;
    (void)e;
    (void)r;

    return original_BrRegistryRemove(reg, item);
}

static int(__stdcall*original_BrRegistryRemoveMany)(br_registry *, void **, int) = (int(__stdcall*)(br_registry *, void **, int))0x004e5a90;
CARM95_HOOK_FUNCTION(original_BrRegistryRemoveMany, BrRegistryRemoveMany)
int __stdcall BrRegistryRemoveMany(br_registry *reg, void **items, int n) {
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

static void *(__stdcall*original_BrRegistryFind)(br_registry *, char *) = (void *(__stdcall*)(br_registry *, char *))0x004e5b20;
CARM95_HOOK_FUNCTION(original_BrRegistryFind, BrRegistryFind)
void* __stdcall BrRegistryFind(br_registry *reg, char *pattern) {
    br_registry_entry *e;
    LOG_TRACE("(%p, \"%s\")", reg, pattern);

    (void)reg;
    (void)pattern;
    (void)e;

    return original_BrRegistryFind(reg, pattern);
}

static int(__stdcall*original_BrRegistryFindMany)(br_registry *, char *, void **, int) = (int(__stdcall*)(br_registry *, char *, void **, int))0x004e5b80;
CARM95_HOOK_FUNCTION(original_BrRegistryFindMany, BrRegistryFindMany)
int __stdcall BrRegistryFindMany(br_registry *reg, char *pattern, void **items, int max) {
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

static int(__stdcall*original_BrRegistryCount)(br_registry *, char *) = (int(__stdcall*)(br_registry *, char *))0x004e5be0;
CARM95_HOOK_FUNCTION(original_BrRegistryCount, BrRegistryCount)
int __stdcall BrRegistryCount(br_registry *reg, char *pattern) {
    br_registry_entry *e;
    int n;
    LOG_TRACE("(%p, \"%s\")", reg, pattern);

    (void)reg;
    (void)pattern;
    (void)e;
    (void)n;

    return original_BrRegistryCount(reg, pattern);
}

static int(__stdcall*original_BrRegistryEnum)(br_registry *, char *, br_enum_cbfn *, void *) = (int(__stdcall*)(br_registry *, char *, br_enum_cbfn *, void *))0x004e5c30;
CARM95_HOOK_FUNCTION(original_BrRegistryEnum, BrRegistryEnum)
int __stdcall BrRegistryEnum(br_registry *reg, char *pattern, br_enum_cbfn *callback, void *arg) {
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

void *(__stdcall*BrRegistryNewStatic)(br_registry *, br_registry_entry *, int) = (void *(__stdcall*)(br_registry *, br_registry_entry *, int))0x004e5cc0;
void* BrRegistryNewStatic_do_not_use(br_registry *reg, br_registry_entry *base, int limit) {
    LOG_TRACE("(%p, %p, %d)", reg, base, limit);

    (void)reg;
    (void)base;
    (void)limit;

    NOT_IMPLEMENTED();
}

void *(__stdcall*BrRegistryAddStatic)(br_registry *, br_registry_entry *, void *) = (void *(__stdcall*)(br_registry *, br_registry_entry *, void *))0x004e5cd0;
void* BrRegistryAddStatic_do_not_use(br_registry *reg, br_registry_entry *base, void *item) {
    LOG_TRACE("(%p, %p, %p)", reg, base, item);

    (void)reg;
    (void)base;
    (void)item;

    NOT_IMPLEMENTED();
}

void *(__stdcall*BrRegistryRemoveStatic)(br_registry *, void *) = (void *(__stdcall*)(br_registry *, void *))0x004e5ce0;
void* BrRegistryRemoveStatic_do_not_use(br_registry *reg, void *item) {
    LOG_TRACE("(%p, %p)", reg, item);

    (void)reg;
    (void)item;

    NOT_IMPLEMENTED();
}

