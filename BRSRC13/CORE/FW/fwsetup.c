#include "fwsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

 // Suffix added to avoid duplicate symbol
#if 0
br_resource_class(* hookvar_resourceClasses__fwsetup )[25];
#endif
char *(* hookvar_namePointers_BRCORE1 )[185] = (void*)0x005261b8;
#if 0
br_uint_16(* hookvar_nameOrdinals_BRCORE1 )[185];
#endif
void *(* hookvar_functionPointers_BRCORE1 )[185] = (void*)0x00526618;
br_image * hookvar_Image_BRCORE1  = (void*)0x00526900;
br_framework_state * hookvar_fw  = (void*)0x00552610;

static br_error(__stdcall*original_BrFwBegin)() = (br_error(__stdcall*)())0x004dfc20;
CARM95_HOOK_FUNCTION(original_BrFwBegin, BrFwBegin)
br_error __stdcall BrFwBegin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    return original_BrFwBegin();
}

static br_error(__stdcall*original_BrFwEnd)() = (br_error(__stdcall*)())0x004dfd20;
CARM95_HOOK_FUNCTION(original_BrFwEnd, BrFwEnd)
br_error __stdcall BrFwEnd() {
    LOG_TRACE("()");


    return original_BrFwEnd();
}

static br_diaghandler *(__cdecl*original_BrDiagHandlerSet)(br_diaghandler *) = (br_diaghandler *(__cdecl*)(br_diaghandler *))0x004dfd70;
CARM95_HOOK_FUNCTION(original_BrDiagHandlerSet, BrDiagHandlerSet)
br_diaghandler* __cdecl BrDiagHandlerSet(br_diaghandler *newdh) {
    br_diaghandler *old;
    LOG_TRACE("(%p)", newdh);

    (void)newdh;
    (void)old;

    return original_BrDiagHandlerSet(newdh);
}

static br_filesystem *(__cdecl*original_BrFilesystemSet)(br_filesystem *) = (br_filesystem *(__cdecl*)(br_filesystem *))0x004dfda0;
CARM95_HOOK_FUNCTION(original_BrFilesystemSet, BrFilesystemSet)
br_filesystem* __cdecl BrFilesystemSet(br_filesystem *newfs) {
    br_filesystem *old;
    LOG_TRACE("(%p)", newfs);

    (void)newfs;
    (void)old;

    return original_BrFilesystemSet(newfs);
}

static br_allocator *(__cdecl*original_BrAllocatorSet)(br_allocator *) = (br_allocator *(__cdecl*)(br_allocator *))0x004dfdd0;
CARM95_HOOK_FUNCTION(original_BrAllocatorSet, BrAllocatorSet)
br_allocator* __cdecl BrAllocatorSet(br_allocator *newal) {
    br_allocator *old;
    LOG_TRACE("(%p)", newal);

    (void)newal;
    (void)old;

    return original_BrAllocatorSet(newal);
}

