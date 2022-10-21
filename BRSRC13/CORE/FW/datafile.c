#include "datafile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_DatafileStackTop  = (void*)0x00527c80;
char *(* hookvar_member_type_names )[32] = (void*)0x00527c88;
char *(* hookvar_ChunkNames )[61] = (void*)0x00527d08;
br_file_primitives * hookvar__BrFilePrimsNull  = (void*)0x00527e00;
br_file_primitives * hookvar__BrFilePrimsReadBinary  = (void*)0x00527e40;
br_file_primitives * hookvar__BrFilePrimsWriteBinary  = (void*)0x00527e80;
br_file_primitives * hookvar__BrFilePrimsReadText  = (void*)0x00527ec0;
br_file_primitives * hookvar__BrFilePrimsWriteText  = (void*)0x00527f00;
#if 0
struct {		// size: 0xc
    int type;		// @0x0
    void *value;		// @0x4
    int count;		// @0x8
}(* hookvar_DatafileStack )[1024];
#endif

function_hook_state_t function_hook_state_DfPush = HOOK_UNAVAILABLE;
static void(__stdcall*original_DfPush)(int, void *, int) = (void(__stdcall*)(int, void *, int))0x004e0aa0;
CARM95_HOOK_FUNCTION(original_DfPush, DfPush)
void __stdcall DfPush(int type, void *value, int count) {
    LOG_TRACE("(%d, %p, %d)", type, value, count);

    (void)type;
    (void)value;
    (void)count;

    if (function_hook_state_DfPush == HOOK_ENABLED) {
        assert(0 && "DfPush not implemented.");
        abort();
    } else {
        original_DfPush(type, value, count);
    }
}

function_hook_state_t function_hook_state_DfPop = HOOK_UNAVAILABLE;
static void *(__stdcall*original_DfPop)(int, int *) = (void *(__stdcall*)(int, int *))0x004e0b00;
CARM95_HOOK_FUNCTION(original_DfPop, DfPop)
void* __stdcall DfPop(int type, int *countp) {
    LOG_TRACE("(%d, %p)", type, countp);

    (void)type;
    (void)countp;

    if (function_hook_state_DfPop == HOOK_ENABLED) {
        assert(0 && "DfPop not implemented.");
        abort();
    } else {
        return original_DfPop(type, countp);
    }
}

function_hook_state_t function_hook_state_DfTop = HOOK_UNAVAILABLE;
static void *(__stdcall*original_DfTop)(int, int *) = (void *(__stdcall*)(int, int *))0x004e0b70;
CARM95_HOOK_FUNCTION(original_DfTop, DfTop)
void* __stdcall DfTop(int type, int *countp) {
    LOG_TRACE("(%d, %p)", type, countp);

    (void)type;
    (void)countp;

    if (function_hook_state_DfTop == HOOK_ENABLED) {
        assert(0 && "DfTop not implemented.");
        abort();
    } else {
        return original_DfTop(type, countp);
    }
}

function_hook_state_t function_hook_state_DfTopType = HOOK_UNAVAILABLE;
static int(__cdecl*original_DfTopType)() = (int(__cdecl*)())0x004e0be0;
CARM95_HOOK_FUNCTION(original_DfTopType, DfTopType)
int __cdecl DfTopType() {
    LOG_TRACE("()");


    if (function_hook_state_DfTopType == HOOK_ENABLED) {
        assert(0 && "DfTopType not implemented.");
        abort();
    } else {
        return original_DfTopType();
    }
}

function_hook_state_t function_hook_state_TextReadLine = HOOK_UNAVAILABLE;
static int(__stdcall*original_TextReadLine)(br_datafile *, char **, char **) = (int(__stdcall*)(br_datafile *, char **, char **))0x004e1f80;
CARM95_HOOK_FUNCTION(original_TextReadLine, TextReadLine)
int __stdcall TextReadLine(br_datafile *df, char **ident, char **data) {
    char *cp;
    LOG_TRACE("(%p, %p, %p)", df, ident, data);

    (void)df;
    (void)ident;
    (void)data;
    (void)cp;

    if (function_hook_state_TextReadLine == HOOK_ENABLED) {
        assert(0 && "TextReadLine not implemented.");
        abort();
    } else {
        return original_TextReadLine(df, ident, data);
    }
}

function_hook_state_t function_hook_state_scalarTypeConvert = HOOK_UNAVAILABLE;
br_uint_16 scalarTypeConvert(br_datafile *df, br_uint_16 t) {
    LOG_TRACE("(%p, %u)", df, t);

    (void)df;
    (void)t;

    if (function_hook_state_scalarTypeConvert == HOOK_ENABLED) {
        assert(0 && "scalarTypeConvert not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DfStructWriteBinary = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfStructWriteBinary)(br_datafile *, br_file_struct *, void *) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *))0x004e0c00;
CARM95_HOOK_FUNCTION(original_DfStructWriteBinary, DfStructWriteBinary)
br_uint_32 __stdcall DfStructWriteBinary(br_datafile *df, br_file_struct *str, void *base) {
    unsigned int m;
    int i;
    int n;
    unsigned char *mp;
    br_file_struct_member *sm;
    union {		// size: 0x8
        unsigned char b[8];		// @0x0
        float f;		// @0x0
    } conv;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)m;
    (void)i;
    (void)n;
    (void)mp;
    (void)sm;
    (void)conv;

    if (function_hook_state_DfStructWriteBinary == HOOK_ENABLED) {
        assert(0 && "DfStructWriteBinary not implemented.");
        abort();
    } else {
        return original_DfStructWriteBinary(df, str, base);
    }
}

function_hook_state_t function_hook_state_DfStructReadBinary = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfStructReadBinary)(br_datafile *, br_file_struct *, void *) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *))0x004e1050;
CARM95_HOOK_FUNCTION(original_DfStructReadBinary, DfStructReadBinary)
br_uint_32 __stdcall DfStructReadBinary(br_datafile *df, br_file_struct *str, void *base) {
    char tmp_string[256];
    unsigned int m;
    int i;
    int c;
    int n;
    unsigned char *mp;
    br_file_struct_member *sm;
    union {		// size: 0x8
        unsigned char b[8];		// @0x0
        float f;		// @0x0
    } conv;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)tmp_string;
    (void)m;
    (void)i;
    (void)c;
    (void)n;
    (void)mp;
    (void)sm;
    (void)conv;

    if (function_hook_state_DfStructReadBinary == HOOK_ENABLED) {
        assert(0 && "DfStructReadBinary not implemented.");
        abort();
    } else {
        return original_DfStructReadBinary(df, str, base);
    }
}

function_hook_state_t function_hook_state_DfStructSizeBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfStructSizeBinary)(br_datafile *, br_file_struct *, void *) = (int(__stdcall*)(br_datafile *, br_file_struct *, void *))0x004e1500;
CARM95_HOOK_FUNCTION(original_DfStructSizeBinary, DfStructSizeBinary)
int __stdcall DfStructSizeBinary(br_datafile *df, br_file_struct *str, void *base) {
    unsigned char *mp;
    unsigned int m;
    br_file_struct_member *sm;
    int bytes;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)mp;
    (void)m;
    (void)sm;
    (void)bytes;

    if (function_hook_state_DfStructSizeBinary == HOOK_ENABLED) {
        assert(0 && "DfStructSizeBinary not implemented.");
        abort();
    } else {
        return original_DfStructSizeBinary(df, str, base);
    }
}

function_hook_state_t function_hook_state_EnumFromString = HOOK_UNAVAILABLE;
int EnumFromString(br_file_enum *e, char *str) {
    unsigned int m;
    LOG_TRACE("(%p, \"%s\")", e, str);

    (void)e;
    (void)str;
    (void)m;

    if (function_hook_state_EnumFromString == HOOK_ENABLED) {
        assert(0 && "EnumFromString not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_EnumToString = HOOK_UNAVAILABLE;
char* EnumToString(br_file_enum *e, int num) {
    unsigned int m;
    LOG_TRACE("(%p, %d)", e, num);

    (void)e;
    (void)num;
    (void)m;

    if (function_hook_state_EnumToString == HOOK_ENABLED) {
        assert(0 && "EnumToString not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DfStructWriteText = HOOK_UNAVAILABLE;
br_uint_32 DfStructWriteText(br_datafile *df, br_file_struct *str, void *base) {
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;

    if (function_hook_state_DfStructWriteText == HOOK_ENABLED) {
        assert(0 && "DfStructWriteText not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_StructWriteTextSub = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_StructWriteTextSub)(br_datafile *, br_file_struct *, void *, int) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *, int))0x004e1790;
CARM95_HOOK_FUNCTION(original_StructWriteTextSub, StructWriteTextSub)
br_uint_32 __stdcall StructWriteTextSub(br_datafile *df, br_file_struct *str, void *base, int indent) {
    unsigned int m;
    int i;
    int w;
    int add_comment;
    void *mp;
    br_file_struct_member *sm;
    LOG_TRACE("(%p, %p, %p, %d)", df, str, base, indent);

    (void)df;
    (void)str;
    (void)base;
    (void)indent;
    (void)m;
    (void)i;
    (void)w;
    (void)add_comment;
    (void)mp;
    (void)sm;

    if (function_hook_state_StructWriteTextSub == HOOK_ENABLED) {
        assert(0 && "StructWriteTextSub not implemented.");
        abort();
    } else {
        return original_StructWriteTextSub(df, str, base, indent);
    }
}

function_hook_state_t function_hook_state_DfStructReadText = HOOK_UNAVAILABLE;
br_uint_32 DfStructReadText(br_datafile *df, br_file_struct *str, void *base) {
    char *id;
    char *data;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)id;
    (void)data;

    if (function_hook_state_DfStructReadText == HOOK_ENABLED) {
        assert(0 && "DfStructReadText not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_StructReadTextSub = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_StructReadTextSub)(br_datafile *, br_file_struct *, void *) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *))0x004e2050;
CARM95_HOOK_FUNCTION(original_StructReadTextSub, StructReadTextSub)
br_uint_32 __stdcall StructReadTextSub(br_datafile *df, br_file_struct *str, void *base) {
    unsigned int m;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    int i;
    int n;
    void *mp;
    br_file_struct_member *sm;
    char *id;
    char *data;
    char *ep;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)m;
    (void)r;
    (void)g;
    (void)b;
    (void)i;
    (void)n;
    (void)mp;
    (void)sm;
    (void)id;
    (void)data;
    (void)ep;

    if (function_hook_state_StructReadTextSub == HOOK_ENABLED) {
        assert(0 && "StructReadTextSub not implemented.");
        abort();
    } else {
        return original_StructReadTextSub(df, str, base);
    }
}

function_hook_state_t function_hook_state_DfStructSizeText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfStructSizeText)(br_datafile *, br_file_struct *, void *) = (int(__stdcall*)(br_datafile *, br_file_struct *, void *))0x004e27a0;
CARM95_HOOK_FUNCTION(original_DfStructSizeText, DfStructSizeText)
int __stdcall DfStructSizeText(br_datafile *df, br_file_struct *str, void *base) {
    unsigned int m;
    br_file_struct_member *sm;
    int lines;
    LOG_TRACE("(%p, %p, %p)", df, str, base);

    (void)df;
    (void)str;
    (void)base;
    (void)m;
    (void)sm;
    (void)lines;

    if (function_hook_state_DfStructSizeText == HOOK_ENABLED) {
        assert(0 && "DfStructSizeText not implemented.");
        abort();
    } else {
        return original_DfStructSizeText(df, str, base);
    }
}

function_hook_state_t function_hook_state_DfStructWriteArray = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfStructWriteArray)(br_datafile *, br_file_struct *, void *, int) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *, int))0x004e27f0;
CARM95_HOOK_FUNCTION(original_DfStructWriteArray, DfStructWriteArray)
br_uint_32 __stdcall DfStructWriteArray(br_datafile *df, br_file_struct *str, void *base, int n) {
    char *cp;
    int i;
    LOG_TRACE("(%p, %p, %p, %d)", df, str, base, n);

    (void)df;
    (void)str;
    (void)base;
    (void)n;
    (void)cp;
    (void)i;

    if (function_hook_state_DfStructWriteArray == HOOK_ENABLED) {
        assert(0 && "DfStructWriteArray not implemented.");
        abort();
    } else {
        return original_DfStructWriteArray(df, str, base, n);
    }
}

function_hook_state_t function_hook_state_DfStructReadArray = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfStructReadArray)(br_datafile *, br_file_struct *, void *, int) = (br_uint_32(__stdcall*)(br_datafile *, br_file_struct *, void *, int))0x004e2840;
CARM95_HOOK_FUNCTION(original_DfStructReadArray, DfStructReadArray)
br_uint_32 __stdcall DfStructReadArray(br_datafile *df, br_file_struct *str, void *base, int n) {
    char *cp;
    int i;
    LOG_TRACE("(%p, %p, %p, %d)", df, str, base, n);

    (void)df;
    (void)str;
    (void)base;
    (void)n;
    (void)cp;
    (void)i;

    if (function_hook_state_DfStructReadArray == HOOK_ENABLED) {
        assert(0 && "DfStructReadArray not implemented.");
        abort();
    } else {
        return original_DfStructReadArray(df, str, base, n);
    }
}

function_hook_state_t function_hook_state_DfChunkWriteText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfChunkWriteText)(br_datafile *, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32))0x004e2890;
CARM95_HOOK_FUNCTION(original_DfChunkWriteText, DfChunkWriteText)
int __stdcall DfChunkWriteText(br_datafile *df, br_uint_32 id, br_uint_32 length) {
    LOG_TRACE("(%p, %u, %u)", df, id, length);

    (void)df;
    (void)id;
    (void)length;

    if (function_hook_state_DfChunkWriteText == HOOK_ENABLED) {
        assert(0 && "DfChunkWriteText not implemented.");
        abort();
    } else {
        return original_DfChunkWriteText(df, id, length);
    }
}

function_hook_state_t function_hook_state_DfChunkReadText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfChunkReadText)(br_datafile *, br_uint_32 *) = (int(__stdcall*)(br_datafile *, br_uint_32 *))0x004e28e0;
CARM95_HOOK_FUNCTION(original_DfChunkReadText, DfChunkReadText)
int __stdcall DfChunkReadText(br_datafile *df, br_uint_32 *plength) {
    int i;
    char *id;
    char *data;
    LOG_TRACE("(%p, %p)", df, plength);

    (void)df;
    (void)plength;
    (void)i;
    (void)id;
    (void)data;

    if (function_hook_state_DfChunkReadText == HOOK_ENABLED) {
        assert(0 && "DfChunkReadText not implemented.");
        abort();
    } else {
        return original_DfChunkReadText(df, plength);
    }
}

function_hook_state_t function_hook_state_DfChunkWriteBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfChunkWriteBinary)(br_datafile *, br_uint_32, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32, br_uint_32))0x004e29b0;
CARM95_HOOK_FUNCTION(original_DfChunkWriteBinary, DfChunkWriteBinary)
int __stdcall DfChunkWriteBinary(br_datafile *df, br_uint_32 id, br_uint_32 length) {
    br_uint_32 l;
    LOG_TRACE("(%p, %u, %u)", df, id, length);

    (void)df;
    (void)id;
    (void)length;
    (void)l;

    if (function_hook_state_DfChunkWriteBinary == HOOK_ENABLED) {
        assert(0 && "DfChunkWriteBinary not implemented.");
        abort();
    } else {
        return original_DfChunkWriteBinary(df, id, length);
    }
}

function_hook_state_t function_hook_state_DfChunkReadBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfChunkReadBinary)(br_datafile *, br_uint_32 *) = (int(__stdcall*)(br_datafile *, br_uint_32 *))0x004e2a10;
CARM95_HOOK_FUNCTION(original_DfChunkReadBinary, DfChunkReadBinary)
int __stdcall DfChunkReadBinary(br_datafile *df, br_uint_32 *plength) {
    br_uint_32 id;
    br_uint_32 l;
    LOG_TRACE("(%p, %p)", df, plength);

    (void)df;
    (void)plength;
    (void)id;
    (void)l;

    if (function_hook_state_DfChunkReadBinary == HOOK_ENABLED) {
        assert(0 && "DfChunkReadBinary not implemented.");
        abort();
    } else {
        return original_DfChunkReadBinary(df, plength);
    }
}

function_hook_state_t function_hook_state_DfCountWriteText = HOOK_UNAVAILABLE;
static void(__stdcall*original_DfCountWriteText)(br_datafile *, br_uint_32) = (void(__stdcall*)(br_datafile *, br_uint_32))0x004e2ad0;
CARM95_HOOK_FUNCTION(original_DfCountWriteText, DfCountWriteText)
void __stdcall DfCountWriteText(br_datafile *df, br_uint_32 count) {
    LOG_TRACE("(%p, %u)", df, count);

    (void)df;
    (void)count;

    if (function_hook_state_DfCountWriteText == HOOK_ENABLED) {
        assert(0 && "DfCountWriteText not implemented.");
        abort();
    } else {
        original_DfCountWriteText(df, count);
    }
}

function_hook_state_t function_hook_state_DfCountReadText = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfCountReadText)(br_datafile *) = (br_uint_32(__stdcall*)(br_datafile *))0x004e2af0;
CARM95_HOOK_FUNCTION(original_DfCountReadText, DfCountReadText)
br_uint_32 __stdcall DfCountReadText(br_datafile *df) {
    char *id;
    char *data;
    LOG_TRACE("(%p)", df);

    (void)df;
    (void)id;
    (void)data;

    if (function_hook_state_DfCountReadText == HOOK_ENABLED) {
        assert(0 && "DfCountReadText not implemented.");
        abort();
    } else {
        return original_DfCountReadText(df);
    }
}

function_hook_state_t function_hook_state_DfCountWriteBinary = HOOK_UNAVAILABLE;
static void(__stdcall*original_DfCountWriteBinary)(br_datafile *, br_uint_32) = (void(__stdcall*)(br_datafile *, br_uint_32))0x004e2b40;
CARM95_HOOK_FUNCTION(original_DfCountWriteBinary, DfCountWriteBinary)
void __stdcall DfCountWriteBinary(br_datafile *df, br_uint_32 count) {
    br_uint_32 l;
    LOG_TRACE("(%p, %u)", df, count);

    (void)df;
    (void)count;
    (void)l;

    if (function_hook_state_DfCountWriteBinary == HOOK_ENABLED) {
        assert(0 && "DfCountWriteBinary not implemented.");
        abort();
    } else {
        original_DfCountWriteBinary(df, count);
    }
}

function_hook_state_t function_hook_state_DfCountReadBinary = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_DfCountReadBinary)(br_datafile *) = (br_uint_32(__stdcall*)(br_datafile *))0x004e2b70;
CARM95_HOOK_FUNCTION(original_DfCountReadBinary, DfCountReadBinary)
br_uint_32 __stdcall DfCountReadBinary(br_datafile *df) {
    br_uint_32 l;
    LOG_TRACE("(%p)", df);

    (void)df;
    (void)l;

    if (function_hook_state_DfCountReadBinary == HOOK_ENABLED) {
        assert(0 && "DfCountReadBinary not implemented.");
        abort();
    } else {
        return original_DfCountReadBinary(df);
    }
}

function_hook_state_t function_hook_state_DfCountSizeText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfCountSizeText)(br_datafile *) = (int(__stdcall*)(br_datafile *))0x004e2ba0;
CARM95_HOOK_FUNCTION(original_DfCountSizeText, DfCountSizeText)
int __stdcall DfCountSizeText(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    if (function_hook_state_DfCountSizeText == HOOK_ENABLED) {
        assert(0 && "DfCountSizeText not implemented.");
        abort();
    } else {
        return original_DfCountSizeText(df);
    }
}

function_hook_state_t function_hook_state_DfCountSizeBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfCountSizeBinary)(br_datafile *) = (int(__stdcall*)(br_datafile *))0x004e2bb0;
CARM95_HOOK_FUNCTION(original_DfCountSizeBinary, DfCountSizeBinary)
int __stdcall DfCountSizeBinary(br_datafile *df) {
    LOG_TRACE("(%p)", df);

    (void)df;

    if (function_hook_state_DfCountSizeBinary == HOOK_ENABLED) {
        assert(0 && "DfCountSizeBinary not implemented.");
        abort();
    } else {
        return original_DfCountSizeBinary(df);
    }
}

function_hook_state_t function_hook_state_BlockWriteSetup = HOOK_UNAVAILABLE;
br_uint_8* BlockWriteSetup(void *base, int block_size, int block_stride, int block_count, int size) {
    int b;
    br_uint_8 *block;
    br_uint_8 *sp;
    br_uint_8 *dp;
    LOG_TRACE("(%p, %d, %d, %d, %d)", base, block_size, block_stride, block_count, size);

    (void)base;
    (void)block_size;
    (void)block_stride;
    (void)block_count;
    (void)size;
    (void)b;
    (void)block;
    (void)sp;
    (void)dp;

    if (function_hook_state_BlockWriteSetup == HOOK_ENABLED) {
        assert(0 && "BlockWriteSetup not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DfBlockWriteText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfBlockWriteText)(br_datafile *, void *, int, int, int, int) = (int(__stdcall*)(br_datafile *, void *, int, int, int, int))0x004e2bc0;
CARM95_HOOK_FUNCTION(original_DfBlockWriteText, DfBlockWriteText)
int __stdcall DfBlockWriteText(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size) {
    int i;
    br_uint_8 *cp;
    br_uint_8 *block;
    int count;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", df, base, block_size, block_stride, block_count, size);

    (void)df;
    (void)base;
    (void)block_size;
    (void)block_stride;
    (void)block_count;
    (void)size;
    (void)i;
    (void)cp;
    (void)block;
    (void)count;

    if (function_hook_state_DfBlockWriteText == HOOK_ENABLED) {
        assert(0 && "DfBlockWriteText not implemented.");
        abort();
    } else {
        return original_DfBlockWriteText(df, base, block_size, block_stride, block_count, size);
    }
}

function_hook_state_t function_hook_state_DfBlockReadText = HOOK_UNAVAILABLE;
static void *(__stdcall*original_DfBlockReadText)(br_datafile *, void *, int *, int, int) = (void *(__stdcall*)(br_datafile *, void *, int *, int, int))0x004e2d50;
CARM95_HOOK_FUNCTION(original_DfBlockReadText, DfBlockReadText)
void* __stdcall DfBlockReadText(br_datafile *df, void *base, int *count, int size, int mtype) {
    char *id;
    char *data;
    int l;
    int s;
    int a;
    char b[3];
    LOG_TRACE("(%p, %p, %p, %d, %d)", df, base, count, size, mtype);

    (void)df;
    (void)base;
    (void)count;
    (void)size;
    (void)mtype;
    (void)id;
    (void)data;
    (void)l;
    (void)s;
    (void)a;
    (void)b;

    if (function_hook_state_DfBlockReadText == HOOK_ENABLED) {
        assert(0 && "DfBlockReadText not implemented.");
        abort();
    } else {
        return original_DfBlockReadText(df, base, count, size, mtype);
    }
}

function_hook_state_t function_hook_state_DfBlockWriteBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfBlockWriteBinary)(br_datafile *, void *, int, int, int, int) = (int(__stdcall*)(br_datafile *, void *, int, int, int, int))0x004e2f10;
CARM95_HOOK_FUNCTION(original_DfBlockWriteBinary, DfBlockWriteBinary)
int __stdcall DfBlockWriteBinary(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size) {
    int count;
    br_uint_32 l;
    br_uint_32 s;
    void *block;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", df, base, block_size, block_stride, block_count, size);

    (void)df;
    (void)base;
    (void)block_size;
    (void)block_stride;
    (void)block_count;
    (void)size;
    (void)count;
    (void)l;
    (void)s;
    (void)block;

    if (function_hook_state_DfBlockWriteBinary == HOOK_ENABLED) {
        assert(0 && "DfBlockWriteBinary not implemented.");
        abort();
    } else {
        return original_DfBlockWriteBinary(df, base, block_size, block_stride, block_count, size);
    }
}

function_hook_state_t function_hook_state_DfBlockReadBinary = HOOK_UNAVAILABLE;
static void *(__stdcall*original_DfBlockReadBinary)(br_datafile *, void *, int *, int, int) = (void *(__stdcall*)(br_datafile *, void *, int *, int, int))0x004e3040;
CARM95_HOOK_FUNCTION(original_DfBlockReadBinary, DfBlockReadBinary)
void* __stdcall DfBlockReadBinary(br_datafile *df, void *base, int *count, int size, int mtype) {
    int l;
    int s;
    LOG_TRACE("(%p, %p, %p, %d, %d)", df, base, count, size, mtype);

    (void)df;
    (void)base;
    (void)count;
    (void)size;
    (void)mtype;
    (void)l;
    (void)s;

    if (function_hook_state_DfBlockReadBinary == HOOK_ENABLED) {
        assert(0 && "DfBlockReadBinary not implemented.");
        abort();
    } else {
        return original_DfBlockReadBinary(df, base, count, size, mtype);
    }
}

function_hook_state_t function_hook_state_DfBlockSizeText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfBlockSizeText)(br_datafile *, void *, int, int, int, int) = (int(__stdcall*)(br_datafile *, void *, int, int, int, int))0x004e3130;
CARM95_HOOK_FUNCTION(original_DfBlockSizeText, DfBlockSizeText)
int __stdcall DfBlockSizeText(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size) {
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", df, base, block_size, block_stride, block_count, size);

    (void)df;
    (void)base;
    (void)block_size;
    (void)block_stride;
    (void)block_count;
    (void)size;

    if (function_hook_state_DfBlockSizeText == HOOK_ENABLED) {
        assert(0 && "DfBlockSizeText not implemented.");
        abort();
    } else {
        return original_DfBlockSizeText(df, base, block_size, block_stride, block_count, size);
    }
}

function_hook_state_t function_hook_state_DfBlockSizeBinary = HOOK_UNAVAILABLE;
int DfBlockSizeBinary(br_datafile *df, void *base, int block_size, int block_stride, int block_count, int size) {
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", df, base, block_size, block_stride, block_count, size);

    (void)df;
    (void)base;
    (void)block_size;
    (void)block_stride;
    (void)block_count;
    (void)size;

    if (function_hook_state_DfBlockSizeBinary == HOOK_ENABLED) {
        assert(0 && "DfBlockSizeBinary not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DfNameReadText = HOOK_UNAVAILABLE;
static char *(__stdcall*original_DfNameReadText)(br_datafile *, char *) = (char *(__stdcall*)(br_datafile *, char *))0x004e3170;
CARM95_HOOK_FUNCTION(original_DfNameReadText, DfNameReadText)
char* __stdcall DfNameReadText(br_datafile *df, char *name) {
    char *id;
    char *data;
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;
    (void)id;
    (void)data;

    if (function_hook_state_DfNameReadText == HOOK_ENABLED) {
        assert(0 && "DfNameReadText not implemented.");
        abort();
    } else {
        return original_DfNameReadText(df, name);
    }
}

function_hook_state_t function_hook_state_DfNameWriteText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfNameWriteText)(br_datafile *, char *) = (int(__stdcall*)(br_datafile *, char *))0x004e31f0;
CARM95_HOOK_FUNCTION(original_DfNameWriteText, DfNameWriteText)
int __stdcall DfNameWriteText(br_datafile *df, char *name) {
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;

    if (function_hook_state_DfNameWriteText == HOOK_ENABLED) {
        assert(0 && "DfNameWriteText not implemented.");
        abort();
    } else {
        return original_DfNameWriteText(df, name);
    }
}

function_hook_state_t function_hook_state_DfNameSizeText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfNameSizeText)(br_datafile *, char *) = (int(__stdcall*)(br_datafile *, char *))0x004e3220;
CARM95_HOOK_FUNCTION(original_DfNameSizeText, DfNameSizeText)
int __stdcall DfNameSizeText(br_datafile *df, char *name) {
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;

    if (function_hook_state_DfNameSizeText == HOOK_ENABLED) {
        assert(0 && "DfNameSizeText not implemented.");
        abort();
    } else {
        return original_DfNameSizeText(df, name);
    }
}

function_hook_state_t function_hook_state_DfNameReadBinary = HOOK_UNAVAILABLE;
static char *(__stdcall*original_DfNameReadBinary)(br_datafile *, char *) = (char *(__stdcall*)(br_datafile *, char *))0x004e3230;
CARM95_HOOK_FUNCTION(original_DfNameReadBinary, DfNameReadBinary)
char* __stdcall DfNameReadBinary(br_datafile *df, char *name) {
    int c;
    int i;
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;
    (void)c;
    (void)i;

    if (function_hook_state_DfNameReadBinary == HOOK_ENABLED) {
        assert(0 && "DfNameReadBinary not implemented.");
        abort();
    } else {
        return original_DfNameReadBinary(df, name);
    }
}

function_hook_state_t function_hook_state_DfNameWriteBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfNameWriteBinary)(br_datafile *, char *) = (int(__stdcall*)(br_datafile *, char *))0x004e3270;
CARM95_HOOK_FUNCTION(original_DfNameWriteBinary, DfNameWriteBinary)
int __stdcall DfNameWriteBinary(br_datafile *df, char *name) {
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;

    if (function_hook_state_DfNameWriteBinary == HOOK_ENABLED) {
        assert(0 && "DfNameWriteBinary not implemented.");
        abort();
    } else {
        return original_DfNameWriteBinary(df, name);
    }
}

function_hook_state_t function_hook_state_DfNameSizeBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfNameSizeBinary)(br_datafile *, char *) = (int(__stdcall*)(br_datafile *, char *))0x004e32b0;
CARM95_HOOK_FUNCTION(original_DfNameSizeBinary, DfNameSizeBinary)
int __stdcall DfNameSizeBinary(br_datafile *df, char *name) {
    LOG_TRACE("(%p, \"%s\")", df, name);

    (void)df;
    (void)name;

    if (function_hook_state_DfNameSizeBinary == HOOK_ENABLED) {
        assert(0 && "DfNameSizeBinary not implemented.");
        abort();
    } else {
        return original_DfNameSizeBinary(df, name);
    }
}

function_hook_state_t function_hook_state_DfSkipText = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfSkipText)(br_datafile *, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32))0x004e32d0;
CARM95_HOOK_FUNCTION(original_DfSkipText, DfSkipText)
int __stdcall DfSkipText(br_datafile *df, br_uint_32 length) {
    char *id;
    char *data;
    LOG_TRACE("(%p, %u)", df, length);

    (void)df;
    (void)length;
    (void)id;
    (void)data;

    if (function_hook_state_DfSkipText == HOOK_ENABLED) {
        assert(0 && "DfSkipText not implemented.");
        abort();
    } else {
        return original_DfSkipText(df, length);
    }
}

function_hook_state_t function_hook_state_DfSkipBinary = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfSkipBinary)(br_datafile *, br_uint_32) = (int(__stdcall*)(br_datafile *, br_uint_32))0x004e3320;
CARM95_HOOK_FUNCTION(original_DfSkipBinary, DfSkipBinary)
int __stdcall DfSkipBinary(br_datafile *df, br_uint_32 length) {
    LOG_TRACE("(%p, %u)", df, length);

    (void)df;
    (void)length;

    if (function_hook_state_DfSkipBinary == HOOK_ENABLED) {
        assert(0 && "DfSkipBinary not implemented.");
        abort();
    } else {
        return original_DfSkipBinary(df, length);
    }
}

function_hook_state_t function_hook_state_DfChunksInterpret = HOOK_UNAVAILABLE;
static int(__stdcall*original_DfChunksInterpret)(br_datafile *, br_chunks_table *) = (int(__stdcall*)(br_datafile *, br_chunks_table *))0x004e3340;
CARM95_HOOK_FUNCTION(original_DfChunksInterpret, DfChunksInterpret)
int __stdcall DfChunksInterpret(br_datafile *df, br_chunks_table *table) {
    br_uint_32 length;
    br_uint_32 count;
    br_uint_32 id;
    int r;
    int i;
    LOG_TRACE("(%p, %p)", df, table);

    (void)df;
    (void)table;
    (void)length;
    (void)count;
    (void)id;
    (void)r;
    (void)i;

    if (function_hook_state_DfChunksInterpret == HOOK_ENABLED) {
        assert(0 && "DfChunksInterpret not implemented.");
        abort();
    } else {
        return original_DfChunksInterpret(df, table);
    }
}

function_hook_state_t function_hook_state_BrNullOther = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrNullOther)() = (void(__cdecl*)())0x004e33e0;
CARM95_HOOK_FUNCTION(original_BrNullOther, BrNullOther)
void __cdecl BrNullOther() {
    LOG_TRACE("()");


    if (function_hook_state_BrNullOther == HOOK_ENABLED) {
        assert(0 && "BrNullOther not implemented.");
        abort();
    } else {
        original_BrNullOther();
    }
}

function_hook_state_t function_hook_state_DfFileIdentify = HOOK_UNAVAILABLE;
static int(__cdecl*original_DfFileIdentify)(br_uint_8 *, br_size_t) = (int(__cdecl*)(br_uint_8 *, br_size_t))0x004e3500;
CARM95_HOOK_FUNCTION(original_DfFileIdentify, DfFileIdentify)
int __cdecl DfFileIdentify(br_uint_8 *magics, br_size_t n_magics) {
    static char text_magics[8];
    static char binary_magics[8];
    LOG_TRACE("(%p, %u)", magics, n_magics);

    (void)magics;
    (void)n_magics;
    (void)text_magics;
    (void)binary_magics;

    if (function_hook_state_DfFileIdentify == HOOK_ENABLED) {
        assert(0 && "DfFileIdentify not implemented.");
        abort();
    } else {
        return original_DfFileIdentify(magics, n_magics);
    }
}

function_hook_state_t function_hook_state_DfOpen = HOOK_UNAVAILABLE;
static br_datafile *(__stdcall*original_DfOpen)(char *, int, br_token) = (br_datafile *(__stdcall*)(char *, int, br_token))0x004e3400;
CARM95_HOOK_FUNCTION(original_DfOpen, DfOpen)
br_datafile* __stdcall DfOpen(char *name, int write, br_token scalar_type) {
    int mode;
    br_datafile *df;
    void *h;
    LOG_TRACE("(\"%s\", %d, %d)", name, write, scalar_type);

    (void)name;
    (void)write;
    (void)scalar_type;
    (void)mode;
    (void)df;
    (void)h;

    if (function_hook_state_DfOpen == HOOK_ENABLED) {
        assert(0 && "DfOpen not implemented.");
        abort();
    } else {
        return original_DfOpen(name, write, scalar_type);
    }
}

function_hook_state_t function_hook_state_DfClose = HOOK_UNAVAILABLE;
static void(__stdcall*original_DfClose)(br_datafile *) = (void(__stdcall*)(br_datafile *))0x004e3540;
CARM95_HOOK_FUNCTION(original_DfClose, DfClose)
void __stdcall DfClose(br_datafile *df) {
    br_datafile *dfp;
    LOG_TRACE("(%p)", df);

    (void)df;
    (void)dfp;

    if (function_hook_state_DfClose == HOOK_ENABLED) {
        assert(0 && "DfClose not implemented.");
        abort();
    } else {
        original_DfClose(df);
    }
}

function_hook_state_t function_hook_state_BrWriteModeSet = HOOK_UNAVAILABLE;
int BrWriteModeSet(int mode) {
    int old;
    LOG_TRACE("(%d)", mode);

    (void)mode;
    (void)old;

    if (function_hook_state_BrWriteModeSet == HOOK_ENABLED) {
        assert(0 && "BrWriteModeSet not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

