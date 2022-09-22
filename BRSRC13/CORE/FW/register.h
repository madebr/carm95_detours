#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "br_types.h"


void* __stdcall BrRegistryNew(br_registry *reg);

void* __stdcall BrRegistryClear(br_registry *reg);

void* __stdcall BrRegistryAdd(br_registry *reg, void *item);

int __stdcall BrRegistryAddMany(br_registry *reg, void **items, int n);

void* __stdcall BrRegistryRemove(br_registry *reg, void *item);

int __stdcall BrRegistryRemoveMany(br_registry *reg, void **items, int n);

void* __stdcall BrRegistryFind(br_registry *reg, char *pattern);

int __stdcall BrRegistryFindMany(br_registry *reg, char *pattern, void **items, int max);

int __stdcall BrRegistryCount(br_registry *reg, char *pattern);

int __stdcall BrRegistryEnum(br_registry *reg, char *pattern, br_enum_cbfn *callback, void *arg);

#if 0
void* BrRegistryNewStatic_do_not_use(br_registry *reg, br_registry_entry *base, int limit);
#endif

#if 0
void* BrRegistryAddStatic_do_not_use(br_registry *reg, br_registry_entry *base, void *item);
#endif

#if 0
void* BrRegistryRemoveStatic_do_not_use(br_registry *reg, void *item);
#endif

#endif
