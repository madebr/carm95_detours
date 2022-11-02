#include "object.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state__M_br_object_query = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_query)
static br_error(__cdecl*original__M_br_object_query)(br_object *, br_uint_32 *, br_token) = (br_error(__cdecl*)(br_object *, br_uint_32 *, br_token))0x004e3630;
CARM95_HOOK_FUNCTION(original__M_br_object_query, _M_br_object_query)
br_error __cdecl _M_br_object_query(br_object *self, br_uint_32 *pvalue, br_token t) {
    LOG_TRACE("(%p, %p, %d)", self, pvalue, t);

    (void)self;
    (void)pvalue;
    (void)t;

    if (function_hook_state__M_br_object_query == HOOK_ENABLED) {
        assert(0 && "_M_br_object_query not implemented.");
        abort();
    } else {
        return original__M_br_object_query(self, pvalue, t);
    }
}

function_hook_state_t function_hook_state__M_br_object_queryBuffer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_queryBuffer)
static br_error(__cdecl*original__M_br_object_queryBuffer)(br_object *, br_uint_32 *, br_uint_32 *, br_size_t, br_token) = (br_error(__cdecl*)(br_object *, br_uint_32 *, br_uint_32 *, br_size_t, br_token))0x004e3660;
CARM95_HOOK_FUNCTION(original__M_br_object_queryBuffer, _M_br_object_queryBuffer)
br_error __cdecl _M_br_object_queryBuffer(br_object *self, br_uint_32 *pvalue, br_uint_32 *buffer, br_size_t buffer_size, br_token t) {
    LOG_TRACE("(%p, %p, %p, %u, %d)", self, pvalue, buffer, buffer_size, t);

    (void)self;
    (void)pvalue;
    (void)buffer;
    (void)buffer_size;
    (void)t;

    if (function_hook_state__M_br_object_queryBuffer == HOOK_ENABLED) {
        assert(0 && "_M_br_object_queryBuffer not implemented.");
        abort();
    } else {
        return original__M_br_object_queryBuffer(self, pvalue, buffer, buffer_size, t);
    }
}

function_hook_state_t function_hook_state__M_br_object_queryMany = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_queryMany)
static br_error(__cdecl*original__M_br_object_queryMany)(br_object *, br_token_value *, void *, br_size_t, br_int_32 *) = (br_error(__cdecl*)(br_object *, br_token_value *, void *, br_size_t, br_int_32 *))0x004e3690;
CARM95_HOOK_FUNCTION(original__M_br_object_queryMany, _M_br_object_queryMany)
br_error __cdecl _M_br_object_queryMany(br_object *self, br_token_value *tv, void *extra, br_size_t extra_size, br_int_32 *pcount) {
    LOG_TRACE("(%p, %p, %p, %u, %p)", self, tv, extra, extra_size, pcount);

    (void)self;
    (void)tv;
    (void)extra;
    (void)extra_size;
    (void)pcount;

    if (function_hook_state__M_br_object_queryMany == HOOK_ENABLED) {
        assert(0 && "_M_br_object_queryMany not implemented.");
        abort();
    } else {
        return original__M_br_object_queryMany(self, tv, extra, extra_size, pcount);
    }
}

function_hook_state_t function_hook_state__M_br_object_queryManySize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_queryManySize)
static br_error(__cdecl*original__M_br_object_queryManySize)(br_object *, br_size_t *, br_token_value *) = (br_error(__cdecl*)(br_object *, br_size_t *, br_token_value *))0x004e36c0;
CARM95_HOOK_FUNCTION(original__M_br_object_queryManySize, _M_br_object_queryManySize)
br_error __cdecl _M_br_object_queryManySize(br_object *self, br_size_t *pextra_size, br_token_value *tv) {
    LOG_TRACE("(%p, %p, %p)", self, pextra_size, tv);

    (void)self;
    (void)pextra_size;
    (void)tv;

    if (function_hook_state__M_br_object_queryManySize == HOOK_ENABLED) {
        assert(0 && "_M_br_object_queryManySize not implemented.");
        abort();
    } else {
        return original__M_br_object_queryManySize(self, pextra_size, tv);
    }
}

function_hook_state_t function_hook_state__M_br_object_queryAll = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_queryAll)
static br_error(__cdecl*original__M_br_object_queryAll)(br_object *, br_token_value *, br_size_t) = (br_error(__cdecl*)(br_object *, br_token_value *, br_size_t))0x004e36f0;
CARM95_HOOK_FUNCTION(original__M_br_object_queryAll, _M_br_object_queryAll)
br_error __cdecl _M_br_object_queryAll(br_object *self, br_token_value *buffer, br_size_t buffer_size) {
    LOG_TRACE("(%p, %p, %u)", self, buffer, buffer_size);

    (void)self;
    (void)buffer;
    (void)buffer_size;

    if (function_hook_state__M_br_object_queryAll == HOOK_ENABLED) {
        assert(0 && "_M_br_object_queryAll not implemented.");
        abort();
    } else {
        return original__M_br_object_queryAll(self, buffer, buffer_size);
    }
}

function_hook_state_t function_hook_state__M_br_object_queryAllSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_object_queryAllSize)
static br_error(__cdecl*original__M_br_object_queryAllSize)(br_object *, br_size_t *) = (br_error(__cdecl*)(br_object *, br_size_t *))0x004e3720;
CARM95_HOOK_FUNCTION(original__M_br_object_queryAllSize, _M_br_object_queryAllSize)
br_error __cdecl _M_br_object_queryAllSize(br_object *self, br_size_t *psize) {
    LOG_TRACE("(%p, %p)", self, psize);

    (void)self;
    (void)psize;

    if (function_hook_state__M_br_object_queryAllSize == HOOK_ENABLED) {
        assert(0 && "_M_br_object_queryAllSize not implemented.");
        abort();
    } else {
        return original__M_br_object_queryAllSize(self, psize);
    }
}

function_hook_state_t function_hook_state__BrObjectFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrObjectFree)
static void(__cdecl*original__BrObjectFree)(void *, br_uint_8, br_size_t) = (void(__cdecl*)(void *, br_uint_8, br_size_t))0x004e3740;
CARM95_HOOK_FUNCTION(original__BrObjectFree, _BrObjectFree)
void __cdecl _BrObjectFree(void *res, br_uint_8 res_class, br_size_t size) {
    br_object *o;
    LOG_TRACE("(%p, %u, %u)", res, res_class, size);

    (void)res;
    (void)res_class;
    (void)size;
    (void)o;

    if (function_hook_state__BrObjectFree == HOOK_ENABLED) {
        assert(0 && "_BrObjectFree not implemented.");
        abort();
    } else {
        original__BrObjectFree(res, res_class, size);
    }
}

