#ifndef _EVENTQ_H_
#define _EVENTQ_H_

#include "br_types.h"

// extern int * hookvar__DOSEventQEnabled ;
// extern host_real_memory * hookvar__DOSEventMemory ;

br_error DOSEventBegin();

void DOSEventEnd();

br_boolean DOSEventWait(dosio_event *event, br_boolean block);

#endif
