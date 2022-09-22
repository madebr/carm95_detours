#include "brqsort.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void(__cdecl*original_BrQsort)(void *, unsigned int, unsigned int, br_qsort_cbfn *) = (void(__cdecl*)(void *, unsigned int, unsigned int, br_qsort_cbfn *))0x004e5f80;
CARM95_HOOK_FUNCTION(original_BrQsort, BrQsort)
void __cdecl BrQsort(void *basep, unsigned int nelems, unsigned int size, br_qsort_cbfn *comp) {
    char *stack[40];
    char **sp;
    char *i;
    char *j;
    char *limit;
    unsigned int thresh;
    char *base;
    unsigned int width;
    void(**swap_func)(char *, char *, unsigned int);
    LOG_TRACE("(%p, %u, %u, %p)", basep, nelems, size, comp);

    (void)basep;
    (void)nelems;
    (void)size;
    (void)comp;
    (void)stack;
    (void)sp;
    (void)i;
    (void)j;
    (void)limit;
    (void)thresh;
    (void)base;
    (void)width;
    (void)swap_func;

    original_BrQsort(basep, nelems, size, comp);
}

void swap_chars(char *a, char *b, unsigned int nbytes) {
    char tmp;
    LOG_TRACE("(\"%s\", \"%s\", %u)", a, b, nbytes);

    (void)a;
    (void)b;
    (void)nbytes;
    (void)tmp;

    NOT_IMPLEMENTED();
}

void swap_ints(char *ap, char *bp, unsigned int nints) {
    int *a;
    int *b;
    int tmp;
    LOG_TRACE("(\"%s\", \"%s\", %u)", ap, bp, nints);

    (void)ap;
    (void)bp;
    (void)nints;
    (void)a;
    (void)b;
    (void)tmp;

    NOT_IMPLEMENTED();
}

void swap_int_1(char *ap, char *bp, unsigned int nints) {
    int *a;
    int *b;
    int tmp;
    LOG_TRACE("(\"%s\", \"%s\", %u)", ap, bp, nints);

    (void)ap;
    (void)bp;
    (void)nints;
    (void)a;
    (void)b;
    (void)tmp;

    NOT_IMPLEMENTED();
}

