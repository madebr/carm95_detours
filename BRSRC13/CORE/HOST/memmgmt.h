#ifndef _MEMMGMT_H_
#define _MEMMGMT_H_

#include "br_types.h"

// extern host_regs * hookvar_regs__memmgmt ; // suffix added to avoid duplicate symbol

br_error __stdcall HostLock(br_uint_32 offset, br_uint_16 sel, br_size_t size);

br_error __stdcall HostUnlock(br_uint_32 offset, br_uint_16 sel, br_size_t size);

br_error __stdcall HostSelectorAllocate(br_uint_16 *selp);

#if 0
br_error HostSelectorAllocateLinear_do_not_use(br_uint_16 *selp, br_uint_32 base, br_size_t size);
#endif

br_error __stdcall HostSelectorAllocateAlias(br_uint_16 *aliasp, br_uint_16 sel);

br_error __stdcall HostSelectorAllocatePhysical(br_uint_16 *selp, br_uint_32 phys_addr, br_size_t size);

br_error __cdecl HostSelectorFree(br_uint_16 sel);

br_error __stdcall HostSelectorBaseSet(br_uint_16 sel, br_uint_32 base);

br_error __stdcall HostSelectorLimitSet(br_uint_16 sel, br_size_t limit);

br_error __stdcall HostSelectorBaseQuery(br_uint_32 *basep, br_uint_16 sel);

br_error __stdcall HostSelectorLimitQuery(br_uint_32 *limitp, br_uint_16 sel);

#endif
