#include "brexcept.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_exception_handler ** hookvar__BrExceptionHandler  = (void*)0x0053005c;
void ** hookvar_exceptionValue  = (void*)0x00544d84;

static br_exception_handler *(__cdecl*original__BrExceptionBegin)() = (br_exception_handler *(__cdecl*)())0x00502b90;
CARM95_HOOK_FUNCTION(original__BrExceptionBegin, _BrExceptionBegin)
br_exception_handler* __cdecl _BrExceptionBegin() {
    br_exception_handler *h;
    LOG_TRACE("()");

    (void)h;

    return original__BrExceptionBegin();
}

static void(__cdecl*original__BrExceptionEnd)() = (void(__cdecl*)())0x00502bb0;
CARM95_HOOK_FUNCTION(original__BrExceptionEnd, _BrExceptionEnd)
void __cdecl _BrExceptionEnd() {
    br_exception_handler *old;
    LOG_TRACE("()");

    (void)old;

    original__BrExceptionEnd();
}

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

    original__BrExceptionThrow(type, value);
}

static br_exception(__cdecl*original__BrExceptionValueFetch)(br_exception, void **) = (br_exception(__cdecl*)(br_exception, void **))0x00502c50;
CARM95_HOOK_FUNCTION(original__BrExceptionValueFetch, _BrExceptionValueFetch)
br_exception __cdecl _BrExceptionValueFetch(br_exception type, void **evp) {
    LOG_TRACE("(%u, %p)", type, evp);

    (void)type;
    (void)evp;

    return original__BrExceptionValueFetch(type, evp);
}

static void *(__cdecl*original__BrExceptionResource)() = (void *(__cdecl*)())0x00502c70;
CARM95_HOOK_FUNCTION(original__BrExceptionResource, _BrExceptionResource)
void* __cdecl _BrExceptionResource() {
    LOG_TRACE("()");


    return original__BrExceptionResource();
}

