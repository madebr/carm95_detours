#include "brexcept.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_exception_handler ** hookvar__BrExceptionHandler  = (void*)0x0053005c;
void ** hookvar_exceptionValue  = (void*)0x00544d84;

function_hook_state_t function_hook_state__BrExceptionBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrExceptionBegin)
static br_exception_handler *(__cdecl*original__BrExceptionBegin)() = (br_exception_handler *(__cdecl*)())0x00502b90;
CARM95_HOOK_FUNCTION(original__BrExceptionBegin, _BrExceptionBegin)
br_exception_handler* __cdecl _BrExceptionBegin() {
    br_exception_handler *h;
    LOG_TRACE("()");

    (void)h;

    if (function_hook_state__BrExceptionBegin == HOOK_ENABLED) {
        assert(0 && "_BrExceptionBegin not implemented.");
        abort();
    } else {
        return original__BrExceptionBegin();
    }
}

function_hook_state_t function_hook_state__BrExceptionEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrExceptionEnd)
static void(__cdecl*original__BrExceptionEnd)() = (void(__cdecl*)())0x00502bb0;
CARM95_HOOK_FUNCTION(original__BrExceptionEnd, _BrExceptionEnd)
void __cdecl _BrExceptionEnd() {
    br_exception_handler *old;
    LOG_TRACE("()");

    (void)old;

    if (function_hook_state__BrExceptionEnd == HOOK_ENABLED) {
        assert(0 && "_BrExceptionEnd not implemented.");
        abort();
    } else {
        original__BrExceptionEnd();
    }
}

function_hook_state_t function_hook_state__BrExceptionThrow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrExceptionThrow)
static void(__cdecl*original__BrExceptionThrow)(br_int_32, void *) = (void(__cdecl*)(br_int_32, void *))0x00502be0;
CARM95_HOOK_FUNCTION(original__BrExceptionThrow, _BrExceptionThrow)
void __cdecl _BrExceptionThrow(br_int_32 type, void *value) {
    br_exception_handler h;
    br_exception_handler *old;
    LOG_TRACE("(%d, %p)", type, value);

    (void)type;
    (void)value;
    (void)h;
    (void)old;

    if (function_hook_state__BrExceptionThrow == HOOK_ENABLED) {
        assert(0 && "_BrExceptionThrow not implemented.");
        abort();
    } else {
        original__BrExceptionThrow(type, value);
    }
}

function_hook_state_t function_hook_state__BrExceptionValueFetch = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrExceptionValueFetch)
static br_exception(__cdecl*original__BrExceptionValueFetch)(br_exception, void **) = (br_exception(__cdecl*)(br_exception, void **))0x00502c50;
CARM95_HOOK_FUNCTION(original__BrExceptionValueFetch, _BrExceptionValueFetch)
br_exception __cdecl _BrExceptionValueFetch(br_exception type, void **evp) {
    LOG_TRACE("(%u, %p)", type, evp);

    (void)type;
    (void)evp;

    if (function_hook_state__BrExceptionValueFetch == HOOK_ENABLED) {
        assert(0 && "_BrExceptionValueFetch not implemented.");
        abort();
    } else {
        return original__BrExceptionValueFetch(type, evp);
    }
}

function_hook_state_t function_hook_state__BrExceptionResource = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrExceptionResource)
static void *(__cdecl*original__BrExceptionResource)() = (void *(__cdecl*)())0x00502c70;
CARM95_HOOK_FUNCTION(original__BrExceptionResource, _BrExceptionResource)
void* __cdecl _BrExceptionResource() {
    LOG_TRACE("()");


    if (function_hook_state__BrExceptionResource == HOOK_ENABLED) {
        assert(0 && "_BrExceptionResource not implemented.");
        abort();
    } else {
        return original__BrExceptionResource();
    }
}

