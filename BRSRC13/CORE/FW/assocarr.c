#include "assocarr.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrAssociativeArrayAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrAssociativeArrayAllocate, function_hook_state_BrAssociativeArrayAllocate)
static br_associative_array *(__cdecl*original_BrAssociativeArrayAllocate)() = (br_associative_array *(__cdecl*)())0x004e9250;
CARM95_HOOK_FUNCTION(original_BrAssociativeArrayAllocate, BrAssociativeArrayAllocate)
br_associative_array* __cdecl BrAssociativeArrayAllocate() {
    br_associative_array *pArray;
    LOG_TRACE("()");

    (void)pArray;

    if (function_hook_state_BrAssociativeArrayAllocate == HOOK_ENABLED) {
        assert(0 && "BrAssociativeArrayAllocate not implemented.");
        abort();
    } else {
        return original_BrAssociativeArrayAllocate();
    }
}

function_hook_state_t function_hook_state_Set_Associative_Array_Value = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(Set_Associative_Array_Value, function_hook_state_Set_Associative_Array_Value)
br_error Set_Associative_Array_Value(br_associative_array *pArray, int index, br_value v) {
    LOG_TRACE("(%p, %d)", pArray, index);

    (void)pArray;
    (void)index;
    (void)v;

    if (function_hook_state_Set_Associative_Array_Value == HOOK_ENABLED) {
        assert(0 && "Set_Associative_Array_Value not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrAssociativeArraySetEntry = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrAssociativeArraySetEntry, function_hook_state_BrAssociativeArraySetEntry)
static br_error(__stdcall*original_BrAssociativeArraySetEntry)(br_associative_array *, br_token, br_value) = (br_error(__stdcall*)(br_associative_array *, br_token, br_value))0x004e92a0;
CARM95_HOOK_FUNCTION(original_BrAssociativeArraySetEntry, BrAssociativeArraySetEntry)
br_error __stdcall BrAssociativeArraySetEntry(br_associative_array *pArray, br_token t, br_value v) {
    br_uint_16 i;
    br_token_value *temp;
    LOG_TRACE("(%p, %d)", pArray, t);

    (void)pArray;
    (void)t;
    (void)v;
    (void)i;
    (void)temp;

    if (function_hook_state_BrAssociativeArraySetEntry == HOOK_ENABLED) {
        assert(0 && "BrAssociativeArraySetEntry not implemented.");
        abort();
    } else {
        return original_BrAssociativeArraySetEntry(pArray, t, v);
    }
}

function_hook_state_t function_hook_state_BrAssociativeArrayRemoveEntry = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrAssociativeArrayRemoveEntry, function_hook_state_BrAssociativeArrayRemoveEntry)
static br_error(__stdcall*original_BrAssociativeArrayRemoveEntry)(br_associative_array *, br_token) = (br_error(__stdcall*)(br_associative_array *, br_token))0x004e9500;
CARM95_HOOK_FUNCTION(original_BrAssociativeArrayRemoveEntry, BrAssociativeArrayRemoveEntry)
br_error __stdcall BrAssociativeArrayRemoveEntry(br_associative_array *pArray, br_token t) {
    br_uint_16 i;
    br_boolean bFound;
    LOG_TRACE("(%p, %d)", pArray, t);

    (void)pArray;
    (void)t;
    (void)i;
    (void)bFound;

    if (function_hook_state_BrAssociativeArrayRemoveEntry == HOOK_ENABLED) {
        assert(0 && "BrAssociativeArrayRemoveEntry not implemented.");
        abort();
    } else {
        return original_BrAssociativeArrayRemoveEntry(pArray, t);
    }
}

function_hook_state_t function_hook_state_BrAssociativeArrayQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrAssociativeArrayQuery, function_hook_state_BrAssociativeArrayQuery)
static br_error(__stdcall*original_BrAssociativeArrayQuery)(br_associative_array *, br_token, br_value *) = (br_error(__stdcall*)(br_associative_array *, br_token, br_value *))0x004e95e0;
CARM95_HOOK_FUNCTION(original_BrAssociativeArrayQuery, BrAssociativeArrayQuery)
br_error __stdcall BrAssociativeArrayQuery(br_associative_array *pArray, br_token t, br_value *pValue) {
    br_uint_16 i;
    LOG_TRACE("(%p, %d, %p)", pArray, t, pValue);

    (void)pArray;
    (void)t;
    (void)pValue;
    (void)i;

    if (function_hook_state_BrAssociativeArrayQuery == HOOK_ENABLED) {
        assert(0 && "BrAssociativeArrayQuery not implemented.");
        abort();
    } else {
        return original_BrAssociativeArrayQuery(pArray, t, pValue);
    }
}

