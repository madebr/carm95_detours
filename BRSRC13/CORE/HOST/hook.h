#ifndef _HOOK_H_
#define _HOOK_H_

#include "br_types.h"


br_error __cdecl HostInterruptHook(host_interrupt_hook *h, br_uint_8 vector, br_uint_32 off, br_uint_16 sel);

br_error __cdecl HostInterruptUnhook(host_interrupt_hook *h);

br_error __cdecl HostExceptionHook(host_exception_hook *h, br_uint_8 exception, br_uint_32 off, br_uint_16 sel);

br_error __cdecl HostExceptionUnhook(host_exception_hook *h);

#endif
