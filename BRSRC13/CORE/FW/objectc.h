#ifndef _OBJECTC_H_
#define _OBJECTC_H_

#include "br_types.h"


void* __cdecl BrObjectListAllocate(void *res);

br_error __cdecl _M_br_object_container_addFront(struct br_object_container *self, struct br_object *ph);

br_error __cdecl _M_br_object_container_remove(struct br_object_container *self, struct br_object *h);

br_error __cdecl _M_br_object_container_removeFront(struct br_object_container *self, struct br_object **ph);

br_error __cdecl _M_br_object_container_find(br_object_container *self, br_object **ph, br_token type, char *pattern, br_token_value *tv);

br_error __cdecl _M_br_object_container_findMany(br_object_container *self, br_object **objects, br_int_32 max_objects, br_int_32 *num_objects, br_token type, char *pattern, br_token_value *tv);

br_error __cdecl _M_br_object_container_count(br_object_container *self, br_uint_32 *pcount, br_token type, char *pattern, br_token_value *tv);

void* __cdecl _M_br_object_container_tokensMatchBegin(struct br_object_container *self, br_token t, br_token_value *tv);

br_boolean __cdecl _M_br_object_container_tokensMatch(struct br_object_container *self, br_object *h, void *arg);

void __cdecl _M_br_object_container_tokensMatchEnd(struct br_object_container *self, void *arg);

br_error __cdecl BrObjectContainerFree(br_object_container *self, br_token type, char *pattern, br_token_value *tv);

#endif
