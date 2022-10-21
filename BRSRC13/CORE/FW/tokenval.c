#include "tokenval.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrTVTemplateAllocate = HOOK_UNAVAILABLE;
static br_tv_template *(__cdecl*original_BrTVTemplateAllocate)(void *, br_tv_template_entry *, int) = (br_tv_template *(__cdecl*)(void *, br_tv_template_entry *, int))0x004e3760;
CARM95_HOOK_FUNCTION(original_BrTVTemplateAllocate, BrTVTemplateAllocate)
br_tv_template* __cdecl BrTVTemplateAllocate(void *res, br_tv_template_entry *entries, int n_entries) {
    br_tv_template *t;
    LOG_TRACE("(%p, %p, %d)", res, entries, n_entries);

    (void)res;
    (void)entries;
    (void)n_entries;
    (void)t;

    if (function_hook_state_BrTVTemplateAllocate == HOOK_ENABLED) {
        assert(0 && "BrTVTemplateAllocate not implemented.");
        abort();
    } else {
        return original_BrTVTemplateAllocate(res, entries, n_entries);
    }
}

function_hook_state_t function_hook_state_BrTVTemplateFree = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrTVTemplateFree)(br_tv_template *) = (void(__cdecl*)(br_tv_template *))0x004e3790;
CARM95_HOOK_FUNCTION(original_BrTVTemplateFree, BrTVTemplateFree)
void __cdecl BrTVTemplateFree(br_tv_template *t) {
    LOG_TRACE("(%p)", t);

    (void)t;

    if (function_hook_state_BrTVTemplateFree == HOOK_ENABLED) {
        assert(0 && "BrTVTemplateFree not implemented.");
        abort();
    } else {
        original_BrTVTemplateFree(t);
    }
}

function_hook_state_t function_hook_state_templateResolveNames = HOOK_UNAVAILABLE;
void templateResolveNames(br_tv_template *template) {
    br_tv_template_entry *tp;
    int n;
    LOG_TRACE("(%p)", template);

    (void)template;
    (void)tp;
    (void)n;

    if (function_hook_state_templateResolveNames == HOOK_ENABLED) {
        assert(0 && "templateResolveNames not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_templateMakeMap = HOOK_UNAVAILABLE;
static void(__stdcall*original_templateMakeMap)(br_tv_template *) = (void(__stdcall*)(br_tv_template *))0x004e3810;
CARM95_HOOK_FUNCTION(original_templateMakeMap, templateMakeMap)
void __stdcall templateMakeMap(br_tv_template *template) {
    br_tv_template_entry *tp;
    char *map;
    br_int_32 min;
    br_int_32 max;
    int i;
    int n;
    int e;
    LOG_TRACE("(%p)", template);

    (void)template;
    (void)tp;
    (void)map;
    (void)min;
    (void)max;
    (void)i;
    (void)n;
    (void)e;

    if (function_hook_state_templateMakeMap == HOOK_ENABLED) {
        assert(0 && "templateMakeMap not implemented.");
        abort();
    } else {
        original_templateMakeMap(template);
    }
}

function_hook_state_t function_hook_state_ConvertFloatToFixed = HOOK_UNAVAILABLE;
br_fixed_ls* ConvertFloatToFixed(br_fixed_ls **pextra, br_float *src, br_int_32 count, br_size_t *pextra_space) {
    br_fixed_ls *ret;
    LOG_TRACE("(%p, %p, %d, %p)", pextra, src, count, pextra_space);

    (void)pextra;
    (void)src;
    (void)count;
    (void)pextra_space;
    (void)ret;

    if (function_hook_state_ConvertFloatToFixed == HOOK_ENABLED) {
        assert(0 && "ConvertFloatToFixed not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ConvertFixedToFloat = HOOK_UNAVAILABLE;
br_float* ConvertFixedToFloat(br_float **pextra, br_fixed_ls *src, br_int_32 count, br_size_t *pextra_space) {
    br_float *ret;
    LOG_TRACE("(%p, %p, %d, %p)", pextra, src, count, pextra_space);

    (void)pextra;
    (void)src;
    (void)count;
    (void)pextra_space;
    (void)ret;

    if (function_hook_state_ConvertFixedToFloat == HOOK_ENABLED) {
        assert(0 && "ConvertFixedToFloat not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ConvertLongCopy = HOOK_UNAVAILABLE;
br_uint_32* ConvertLongCopy(br_uint_32 **pextra, br_uint_32 *src, br_int_32 count, br_size_t *pextra_space) {
    br_uint_32 *ret;
    LOG_TRACE("(%p, %p, %d, %p)", pextra, src, count, pextra_space);

    (void)pextra;
    (void)src;
    (void)count;
    (void)pextra_space;
    (void)ret;

    if (function_hook_state_ConvertLongCopy == HOOK_ENABLED) {
        assert(0 && "ConvertLongCopy not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ValueQuery = HOOK_UNAVAILABLE;
br_error ValueQuery(br_token_value *tv, void **pextra, br_size_t *pextra_size, void *block, br_tv_template_entry *tep) {
    void *mem;
    br_uint_32 *lp;
    int t;
    br_tv_custom *custp;
    LOG_TRACE("(%p, %p, %p, %p, %p)", tv, pextra, pextra_size, block, tep);

    (void)tv;
    (void)pextra;
    (void)pextra_size;
    (void)block;
    (void)tep;
    (void)mem;
    (void)lp;
    (void)t;
    (void)custp;

    if (function_hook_state_ValueQuery == HOOK_ENABLED) {
        assert(0 && "ValueQuery not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ValueSet = HOOK_UNAVAILABLE;
static br_error(__stdcall*original_ValueSet)(void *, br_token_value *, br_tv_template_entry *) = (br_error(__stdcall*)(void *, br_token_value *, br_tv_template_entry *))0x004e48d0;
CARM95_HOOK_FUNCTION(original_ValueSet, ValueSet)
br_error __stdcall ValueSet(void *block, br_token_value *tv, br_tv_template_entry *tep) {
    void *mem;
    int i;
    int t;
    br_tv_custom *custp;
    LOG_TRACE("(%p, %p, %p)", block, tv, tep);

    (void)block;
    (void)tv;
    (void)tep;
    (void)mem;
    (void)i;
    (void)t;
    (void)custp;

    if (function_hook_state_ValueSet == HOOK_ENABLED) {
        assert(0 && "ValueSet not implemented.");
        abort();
    } else {
        return original_ValueSet(block, tv, tep);
    }
}

function_hook_state_t function_hook_state_ValueExtraSize = HOOK_UNAVAILABLE;
static br_size_t(__stdcall*original_ValueExtraSize)(void *, br_tv_template_entry *) = (br_size_t(__stdcall*)(void *, br_tv_template_entry *))0x004e4590;
CARM95_HOOK_FUNCTION(original_ValueExtraSize, ValueExtraSize)
br_size_t __stdcall ValueExtraSize(void *block, br_tv_template_entry *tep) {
    void *mem;
    br_uint_32 *lp;
    int t;
    br_tv_custom *custp;
    LOG_TRACE("(%p, %p)", block, tep);

    (void)block;
    (void)tep;
    (void)mem;
    (void)lp;
    (void)t;
    (void)custp;

    if (function_hook_state_ValueExtraSize == HOOK_ENABLED) {
        assert(0 && "ValueExtraSize not implemented.");
        abort();
    } else {
        return original_ValueExtraSize(block, tep);
    }
}

function_hook_state_t function_hook_state_BrTokenValueQuery = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueQuery)(br_uint_32 *, br_uint_32 *, br_size_t, br_token, void *, br_tv_template *) = (br_error(__cdecl*)(br_uint_32 *, br_uint_32 *, br_size_t, br_token, void *, br_tv_template *))0x004e37a0;
CARM95_HOOK_FUNCTION(original_BrTokenValueQuery, BrTokenValueQuery)
br_error __cdecl BrTokenValueQuery(br_uint_32 *pvalue, br_uint_32 *extra, br_size_t extra_size, br_token t, void *block, br_tv_template *template) {
    br_int_32 o;
    br_tv_template_entry *tep;
    br_token_value tv;
    br_error r;
    LOG_TRACE("(%p, %p, %u, %d, %p, %p)", pvalue, extra, extra_size, t, block, template);

    (void)pvalue;
    (void)extra;
    (void)extra_size;
    (void)t;
    (void)block;
    (void)template;
    (void)o;
    (void)tep;
    (void)tv;
    (void)r;

    if (function_hook_state_BrTokenValueQuery == HOOK_ENABLED) {
        assert(0 && "BrTokenValueQuery not implemented.");
        abort();
    } else {
        return original_BrTokenValueQuery(pvalue, extra, extra_size, t, block, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueQueryMany = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueQueryMany)(br_token_value *, void *, br_size_t, br_int_32 *, void *, br_tv_template *) = (br_error(__cdecl*)(br_token_value *, void *, br_size_t, br_int_32 *, void *, br_tv_template *))0x004e44c0;
CARM95_HOOK_FUNCTION(original_BrTokenValueQueryMany, BrTokenValueQueryMany)
br_error __cdecl BrTokenValueQueryMany(br_token_value *tv, void *extra, br_size_t extra_size, br_int_32 *pcount, void *block, br_tv_template *template) {
    br_int_32 o;
    br_tv_template_entry *tep;
    br_error r;
    LOG_TRACE("(%p, %p, %u, %p, %p, %p)", tv, extra, extra_size, pcount, block, template);

    (void)tv;
    (void)extra;
    (void)extra_size;
    (void)pcount;
    (void)block;
    (void)template;
    (void)o;
    (void)tep;
    (void)r;

    if (function_hook_state_BrTokenValueQueryMany == HOOK_ENABLED) {
        assert(0 && "BrTokenValueQueryMany not implemented.");
        abort();
    } else {
        return original_BrTokenValueQueryMany(tv, extra, extra_size, pcount, block, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueQueryManySize = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueQueryManySize)(br_size_t *, br_token_value *, void *, br_tv_template *) = (br_error(__cdecl*)(br_size_t *, br_token_value *, void *, br_tv_template *))0x004e4530;
CARM95_HOOK_FUNCTION(original_BrTokenValueQueryManySize, BrTokenValueQueryManySize)
br_error __cdecl BrTokenValueQueryManySize(br_size_t *psize, br_token_value *tv, void *block, br_tv_template *template) {
    br_int_32 o;
    br_size_t extra_size;
    LOG_TRACE("(%p, %p, %p, %p)", psize, tv, block, template);

    (void)psize;
    (void)tv;
    (void)block;
    (void)template;
    (void)o;
    (void)extra_size;

    if (function_hook_state_BrTokenValueQueryManySize == HOOK_ENABLED) {
        assert(0 && "BrTokenValueQueryManySize not implemented.");
        abort();
    } else {
        return original_BrTokenValueQueryManySize(psize, tv, block, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueQueryAll = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueQueryAll)(br_token_value *, br_size_t, void *, br_tv_template *) = (br_error(__cdecl*)(br_token_value *, br_size_t, void *, br_tv_template *))0x004e46d0;
CARM95_HOOK_FUNCTION(original_BrTokenValueQueryAll, BrTokenValueQueryAll)
br_error __cdecl BrTokenValueQueryAll(br_token_value *buffer, br_size_t buffer_size, void *block, br_tv_template *template) {
    br_tv_template_entry *tp;
    int n;
    int e;
    br_token_value *tv;
    char *extra;
    br_size_t extra_size;
    br_error r;
    LOG_TRACE("(%p, %u, %p, %p)", buffer, buffer_size, block, template);

    (void)buffer;
    (void)buffer_size;
    (void)block;
    (void)template;
    (void)tp;
    (void)n;
    (void)e;
    (void)tv;
    (void)extra;
    (void)extra_size;
    (void)r;

    if (function_hook_state_BrTokenValueQueryAll == HOOK_ENABLED) {
        assert(0 && "BrTokenValueQueryAll not implemented.");
        abort();
    } else {
        return original_BrTokenValueQueryAll(buffer, buffer_size, block, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueQueryAllSize = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueQueryAllSize)(br_size_t *, void *, br_tv_template *) = (br_error(__cdecl*)(br_size_t *, void *, br_tv_template *))0x004e47b0;
CARM95_HOOK_FUNCTION(original_BrTokenValueQueryAllSize, BrTokenValueQueryAllSize)
br_error __cdecl BrTokenValueQueryAllSize(br_size_t *psize, void *block, br_tv_template *template) {
    br_tv_template_entry *tp;
    int e;
    int n;
    br_size_t extra_size;
    LOG_TRACE("(%p, %p, %p)", psize, block, template);

    (void)psize;
    (void)block;
    (void)template;
    (void)tp;
    (void)e;
    (void)n;
    (void)extra_size;

    if (function_hook_state_BrTokenValueQueryAllSize == HOOK_ENABLED) {
        assert(0 && "BrTokenValueQueryAllSize not implemented.");
        abort();
    } else {
        return original_BrTokenValueQueryAllSize(psize, block, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueSet = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueSet)(void *, br_uint_32 *, br_token, br_uint_32, br_tv_template *) = (br_error(__cdecl*)(void *, br_uint_32 *, br_token, br_uint_32, br_tv_template *))0x004e4840;
CARM95_HOOK_FUNCTION(original_BrTokenValueSet, BrTokenValueSet)
br_error __cdecl BrTokenValueSet(void *mem, br_uint_32 *pcombined_mask, br_token t, br_uint_32 value, br_tv_template *template) {
    br_int_32 o;
    br_error r;
    br_token_value tv;
    LOG_TRACE("(%p, %p, %d, %u, %p)", mem, pcombined_mask, t, value, template);

    (void)mem;
    (void)pcombined_mask;
    (void)t;
    (void)value;
    (void)template;
    (void)o;
    (void)r;
    (void)tv;

    if (function_hook_state_BrTokenValueSet == HOOK_ENABLED) {
        assert(0 && "BrTokenValueSet not implemented.");
        abort();
    } else {
        return original_BrTokenValueSet(mem, pcombined_mask, t, value, template);
    }
}

function_hook_state_t function_hook_state_BrTokenValueSetMany = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrTokenValueSetMany)(void *, br_int_32 *, br_uint_32 *, br_token_value *, br_tv_template *) = (br_error(__cdecl*)(void *, br_int_32 *, br_uint_32 *, br_token_value *, br_tv_template *))0x004e4c40;
CARM95_HOOK_FUNCTION(original_BrTokenValueSetMany, BrTokenValueSetMany)
br_error __cdecl BrTokenValueSetMany(void *mem, br_int_32 *pcount, br_uint_32 *pcombined_mask, br_token_value *tv, br_tv_template *template) {
    br_int_32 o;
    br_int_32 n;
    br_error r;
    br_uint_32 cm;
    LOG_TRACE("(%p, %p, %p, %p, %p)", mem, pcount, pcombined_mask, tv, template);

    (void)mem;
    (void)pcount;
    (void)pcombined_mask;
    (void)tv;
    (void)template;
    (void)o;
    (void)n;
    (void)r;
    (void)cm;

    if (function_hook_state_BrTokenValueSetMany == HOOK_ENABLED) {
        assert(0 && "BrTokenValueSetMany not implemented.");
        abort();
    } else {
        return original_BrTokenValueSetMany(mem, pcount, pcombined_mask, tv, template);
    }
}

function_hook_state_t function_hook_state_DumpMatrixInteger = HOOK_UNAVAILABLE;
void DumpMatrixInteger(br_int_32 *ip, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg) {
    int i;
    int j;
    char *cp;
    char value[128];
    LOG_TRACE("(%p, %d, %d, \"%s\", \"%s\", \"%s\", %p, %p)", ip, rows, cols, prefix, info_0, info_n, putline, arg);

    (void)ip;
    (void)rows;
    (void)cols;
    (void)prefix;
    (void)info_0;
    (void)info_n;
    (void)putline;
    (void)arg;
    (void)i;
    (void)j;
    (void)cp;
    (void)value;

    if (function_hook_state_DumpMatrixInteger == HOOK_ENABLED) {
        assert(0 && "DumpMatrixInteger not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DumpMatrixFixed = HOOK_UNAVAILABLE;
void DumpMatrixFixed(br_fixed_ls *xp, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg) {
    int i;
    int j;
    char *cp;
    char value[128];
    LOG_TRACE("(%p, %d, %d, \"%s\", \"%s\", \"%s\", %p, %p)", xp, rows, cols, prefix, info_0, info_n, putline, arg);

    (void)xp;
    (void)rows;
    (void)cols;
    (void)prefix;
    (void)info_0;
    (void)info_n;
    (void)putline;
    (void)arg;
    (void)i;
    (void)j;
    (void)cp;
    (void)value;

    if (function_hook_state_DumpMatrixFixed == HOOK_ENABLED) {
        assert(0 && "DumpMatrixFixed not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DumpMatrixFloat = HOOK_UNAVAILABLE;
void DumpMatrixFloat(br_float *fp, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg) {
    int i;
    int j;
    char *cp;
    char value[128];
    LOG_TRACE("(%p, %d, %d, \"%s\", \"%s\", \"%s\", %p, %p)", fp, rows, cols, prefix, info_0, info_n, putline, arg);

    (void)fp;
    (void)rows;
    (void)cols;
    (void)prefix;
    (void)info_0;
    (void)info_n;
    (void)putline;
    (void)arg;
    (void)i;
    (void)j;
    (void)cp;
    (void)value;

    if (function_hook_state_DumpMatrixFloat == HOOK_ENABLED) {
        assert(0 && "DumpMatrixFloat not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DumpObject = HOOK_UNAVAILABLE;
void DumpObject(br_object *h, char *prefix, char *info, br_putline_cbfn *putline, void *arg) {
    char value[128];
    char *dev_ident;
    char *h_ident;
    br_object *dev;
    LOG_TRACE("(%p, \"%s\", \"%s\", %p, %p)", h, prefix, info, putline, arg);

    (void)h;
    (void)prefix;
    (void)info;
    (void)putline;
    (void)arg;
    (void)value;
    (void)dev_ident;
    (void)h_ident;
    (void)dev;

    if (function_hook_state_DumpObject == HOOK_ENABLED) {
        assert(0 && "DumpObject not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrTokenValueDump = HOOK_UNAVAILABLE;
void(__cdecl*BrTokenValueDump)(br_token_value *, char *, br_putline_cbfn *, void *) = (void(__cdecl*)(br_token_value *, char *, br_putline_cbfn *, void *))0x004e4ce0;
void BrTokenValueDump_do_not_use(br_token_value *tv, char *prefix, br_putline_cbfn *putline, void *arg) {
    char *id;
    char value[128];
    char tmp[128];
    char info_0[64];
    char *info_n;
    char *pvalue;
    int n;
    int i;
    br_object **pph;
    void **ppp;
    br_token *pt;
    LOG_TRACE("(%p, \"%s\", %p, %p)", tv, prefix, putline, arg);

    (void)tv;
    (void)prefix;
    (void)putline;
    (void)arg;
    (void)id;
    (void)value;
    (void)tmp;
    (void)info_0;
    (void)info_n;
    (void)pvalue;
    (void)n;
    (void)i;
    (void)pph;
    (void)ppp;
    (void)pt;

    if (function_hook_state_BrTokenValueDump == HOOK_ENABLED) {
        assert(0 && "BrTokenValueDump_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrStringToTokenValue = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrStringToTokenValue)(br_token_value *, br_size_t, char *) = (br_error(__cdecl*)(br_token_value *, br_size_t, char *))0x004e4cf0;
CARM95_HOOK_FUNCTION(original_BrStringToTokenValue, BrStringToTokenValue)
br_error __cdecl BrStringToTokenValue(br_token_value *buffer, br_size_t buffer_size, char *str) {
    br_lexer *l;
    br_error r;
    static br_lexer_keyword keywords[4];
    LOG_TRACE("(%p, %u, \"%s\")", buffer, buffer_size, str);

    (void)buffer;
    (void)buffer_size;
    (void)str;
    (void)l;
    (void)r;
    (void)keywords;

    if (function_hook_state_BrStringToTokenValue == HOOK_ENABLED) {
        assert(0 && "BrStringToTokenValue not implemented.");
        abort();
    } else {
        return original_BrStringToTokenValue(buffer, buffer_size, str);
    }
}

function_hook_state_t function_hook_state_parseTokenValue = HOOK_UNAVAILABLE;
br_error parseTokenValue(br_lexer *l, br_token_value *tv, br_size_t size) {
    int len;
    char name[40];
    br_token type;
    static br_token real_types[2];
    br_error r;
    static br_token __block0__real_types[2];
    static br_token __block1__pos_int_types[9];
    static br_token __block1__neg_int_types[6];
    static br_token __block2__ident_types[1];
    static br_token __block3__bool_types[1];
    static br_token __block4__string_types[2];
    static br_token __block5__none_types[2];
    LOG_TRACE("(%p, %p, %u)", l, tv, size);

    (void)l;
    (void)tv;
    (void)size;
    (void)len;
    (void)name;
    (void)type;
    (void)real_types;
    (void)r;
    (void)__block0__real_types;
    (void)__block1__pos_int_types;
    (void)__block1__neg_int_types;
    (void)__block2__ident_types;
    (void)__block3__bool_types;
    (void)__block4__string_types;
    (void)__block5__none_types;

    if (function_hook_state_parseTokenValue == HOOK_ENABLED) {
        assert(0 && "parseTokenValue not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrTokenValueCompare = HOOK_UNAVAILABLE;
static br_boolean(__cdecl*original_BrTokenValueCompare)(br_token_value *, br_token_value *) = (br_boolean(__cdecl*)(br_token_value *, br_token_value *))0x004e5130;
CARM95_HOOK_FUNCTION(original_BrTokenValueCompare, BrTokenValueCompare)
br_boolean __cdecl BrTokenValueCompare(br_token_value *tv1, br_token_value *tv2) {
    int i;
    LOG_TRACE("(%p, %p)", tv1, tv2);

    (void)tv1;
    (void)tv2;
    (void)i;

    if (function_hook_state_BrTokenValueCompare == HOOK_ENABLED) {
        assert(0 && "BrTokenValueCompare not implemented.");
        abort();
    } else {
        return original_BrTokenValueCompare(tv1, tv2);
    }
}

function_hook_state_t function_hook_state_BrTokenValueDup = HOOK_UNAVAILABLE;
static br_error(__stdcall*original_BrTokenValueDup)(br_token_value **, br_token_value *) = (br_error(__stdcall*)(br_token_value **, br_token_value *))0x004e5390;
CARM95_HOOK_FUNCTION(original_BrTokenValueDup, BrTokenValueDup)
br_error __stdcall BrTokenValueDup(br_token_value **dstp, br_token_value *src) {
    int i;
    int c;
    br_token_value *tv;
    LOG_TRACE("(%p, %p)", dstp, src);

    (void)dstp;
    (void)src;
    (void)i;
    (void)c;
    (void)tv;

    if (function_hook_state_BrTokenValueDup == HOOK_ENABLED) {
        assert(0 && "BrTokenValueDup not implemented.");
        abort();
    } else {
        return original_BrTokenValueDup(dstp, src);
    }
}

