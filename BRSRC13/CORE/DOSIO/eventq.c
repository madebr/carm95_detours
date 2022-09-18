#include "eventq.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#if 0
int * hookvar__DOSEventQEnabled ;
#endif
#if 0
host_real_memory * hookvar__DOSEventMemory ;
#endif

br_error DOSEventBegin() {
    host_info hi;
    int s;
    LOG_TRACE("()");

    (void)hi;
    (void)s;

    NOT_IMPLEMENTED();
}

void DOSEventEnd() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

br_boolean DOSEventWait(dosio_event *event, br_boolean block) {
    int t;
    LOG_TRACE("(%p, %d)", event, block);

    (void)event;
    (void)block;
    (void)t;

    NOT_IMPLEMENTED();
}

