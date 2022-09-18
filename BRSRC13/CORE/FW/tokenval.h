#ifndef _TOKENVAL_H_
#define _TOKENVAL_H_

#include "br_types.h"


br_tv_template* __cdecl BrTVTemplateAllocate(void *res, br_tv_template_entry *entries, int n_entries);

void __cdecl BrTVTemplateFree(br_tv_template *t);

void templateResolveNames(br_tv_template *template);

void __stdcall templateMakeMap(br_tv_template *template);

br_fixed_ls* ConvertFloatToFixed(br_fixed_ls **pextra, br_float *src, br_int_32 count, br_size_t *pextra_space);

br_float* ConvertFixedToFloat(br_float **pextra, br_fixed_ls *src, br_int_32 count, br_size_t *pextra_space);

br_uint_32* ConvertLongCopy(br_uint_32 **pextra, br_uint_32 *src, br_int_32 count, br_size_t *pextra_space);

br_error ValueQuery(br_token_value *tv, void **pextra, br_size_t *pextra_size, void *block, br_tv_template_entry *tep);

br_error __stdcall ValueSet(void *block, br_token_value *tv, br_tv_template_entry *tep);

br_size_t __stdcall ValueExtraSize(void *block, br_tv_template_entry *tep);

br_error __cdecl BrTokenValueQuery(br_uint_32 *pvalue, br_uint_32 *extra, br_size_t extra_size, br_token t, void *block, br_tv_template *template);

br_error __cdecl BrTokenValueQueryMany(br_token_value *tv, void *extra, br_size_t extra_size, br_int_32 *pcount, void *block, br_tv_template *template);

br_error __cdecl BrTokenValueQueryManySize(br_size_t *psize, br_token_value *tv, void *block, br_tv_template *template);

br_error __cdecl BrTokenValueQueryAll(br_token_value *buffer, br_size_t buffer_size, void *block, br_tv_template *template);

br_error __cdecl BrTokenValueQueryAllSize(br_size_t *psize, void *block, br_tv_template *template);

br_error __cdecl BrTokenValueSet(void *mem, br_uint_32 *pcombined_mask, br_token t, br_uint_32 value, br_tv_template *template);

br_error __cdecl BrTokenValueSetMany(void *mem, br_int_32 *pcount, br_uint_32 *pcombined_mask, br_token_value *tv, br_tv_template *template);

void DumpMatrixInteger(br_int_32 *ip, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg);

void DumpMatrixFixed(br_fixed_ls *xp, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg);

void DumpMatrixFloat(br_float *fp, int rows, int cols, char *prefix, char *info_0, char *info_n, br_putline_cbfn *putline, void *arg);

void DumpObject(br_object *h, char *prefix, char *info, br_putline_cbfn *putline, void *arg);

#if 0
void BrTokenValueDump_do_not_use(br_token_value *tv, char *prefix, br_putline_cbfn *putline, void *arg);
#endif

br_error __cdecl BrStringToTokenValue(br_token_value *buffer, br_size_t buffer_size, char *str);

br_error parseTokenValue(br_lexer *l, br_token_value *tv, br_size_t size);

br_boolean __cdecl BrTokenValueCompare(br_token_value *tv1, br_token_value *tv2);

br_error __stdcall BrTokenValueDup(br_token_value **dstp, br_token_value *src);

#endif
