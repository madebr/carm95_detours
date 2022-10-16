#include "assocarr.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_associative_array *(__cdecl*original_BrAssociativeArrayAllocate)() = (br_associative_array *(__cdecl*)())0x004e9250;
CARM95_HOOK_FUNCTION(original_BrAssociativeArrayAllocate, BrAssociativeArrayAllocate)
br_associative_array* __cdecl BrAssociativeArrayAllocate() {
    br_associative_array *pArray;
    LOG_TRACE("()");

    (void)pArray;

    return original_BrAssociativeArrayAllocate();
}

br_error Set_Associative_Array_Value(br_associative_array *pArray, int index, br_value v) {
    LOG_TRACE("(%p, %d)", pArray, index);

    (void)pArray;
    (void)index;
    (void)v;

    NOT_IMPLEMENTED();
}

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

    return original_BrAssociativeArraySetEntry(pArray, t, v);
}

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

    return original_BrAssociativeArrayRemoveEntry(pArray, t);
}

static br_error(__stdcall*original_BrAssociativeArrayQuery)(br_associative_array *, br_token, br_value *) = (br_error(__stdcall*)(br_associative_array *, br_token, br_value *))0x004e95e0;
CARM95_HOOK_FUNCTION(original_BrAssociativeArrayQuery, BrAssociativeArrayQuery)
br_error __stdcall BrAssociativeArrayQuery(br_associative_array *pArray, br_token t, br_value *pValue) {
    br_uint_16 i;
    LOG_TRACE("(%p, %d, %p)", pArray, t, pValue);

    (void)pArray;
    (void)t;
    (void)pValue;
    (void)i;

    return original_BrAssociativeArrayQuery(pArray, t, pValue);
}

