#include "brlists.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void(__cdecl*original_BrNewList)(struct br_list *) = (void(__cdecl*)(struct br_list *))0x004e5df0;
CARM95_HOOK_FUNCTION(original_BrNewList, BrNewList)
void __cdecl BrNewList(struct br_list *list) {
    LOG_TRACE("(%p)", list);

    (void)list;

    original_BrNewList(list);
}

static void(__cdecl*original_BrAddHead)(struct br_list *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *))0x004e5e10;
CARM95_HOOK_FUNCTION(original_BrAddHead, BrAddHead)
void __cdecl BrAddHead(struct br_list *list, struct br_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    original_BrAddHead(list, node);
}

static void(__cdecl*original_BrAddTail)(struct br_list *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *))0x004e5e30;
CARM95_HOOK_FUNCTION(original_BrAddTail, BrAddTail)
void __cdecl BrAddTail(struct br_list *list, struct br_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    original_BrAddTail(list, node);
}

static struct br_node *(__cdecl*original_BrRemHead)(struct br_list *) = (struct br_node *(__cdecl*)(struct br_list *))0x004e5e50;
CARM95_HOOK_FUNCTION(original_BrRemHead, BrRemHead)
struct br_node* __cdecl BrRemHead(struct br_list *list) {
    struct br_node *n;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)n;

    return original_BrRemHead(list);
}

static struct br_node *(__cdecl*original_BrRemTail)(struct br_list *) = (struct br_node *(__cdecl*)(struct br_list *))0x004e5e70;
CARM95_HOOK_FUNCTION(original_BrRemTail, BrRemTail)
struct br_node* __cdecl BrRemTail(struct br_list *list) {
    struct br_node *n;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)n;

    return original_BrRemTail(list);
}

static void(__cdecl*original_BrInsert)(struct br_list *, struct br_node *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *, struct br_node *))0x004e5e90;
CARM95_HOOK_FUNCTION(original_BrInsert, BrInsert)
void __cdecl BrInsert(struct br_list *list, struct br_node *here, struct br_node *node) {
    LOG_TRACE("(%p, %p, %p)", list, here, node);

    (void)list;
    (void)here;
    (void)node;

    original_BrInsert(list, here, node);
}

static struct br_node *(__cdecl*original_BrRemove)(struct br_node *) = (struct br_node *(__cdecl*)(struct br_node *))0x004e5eb0;
CARM95_HOOK_FUNCTION(original_BrRemove, BrRemove)
struct br_node* __cdecl BrRemove(struct br_node *node) {
    LOG_TRACE("(%p)", node);

    (void)node;

    return original_BrRemove(node);
}

static void(__cdecl*original_BrSimpleNewList)(struct br_simple_list *) = (void(__cdecl*)(struct br_simple_list *))0x004e5ed0;
CARM95_HOOK_FUNCTION(original_BrSimpleNewList, BrSimpleNewList)
void __cdecl BrSimpleNewList(struct br_simple_list *list) {
    LOG_TRACE("(%p)", list);

    (void)list;

    original_BrSimpleNewList(list);
}

static void(__cdecl*original_BrSimpleAddHead)(struct br_simple_list *, struct br_simple_node *) = (void(__cdecl*)(struct br_simple_list *, struct br_simple_node *))0x004e5ee0;
CARM95_HOOK_FUNCTION(original_BrSimpleAddHead, BrSimpleAddHead)
void __cdecl BrSimpleAddHead(struct br_simple_list *list, struct br_simple_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    original_BrSimpleAddHead(list, node);
}

static struct br_simple_node *(__cdecl*original_BrSimpleRemHead)(struct br_simple_list *) = (struct br_simple_node *(__cdecl*)(struct br_simple_list *))0x004e5f00;
CARM95_HOOK_FUNCTION(original_BrSimpleRemHead, BrSimpleRemHead)
struct br_simple_node* __cdecl BrSimpleRemHead(struct br_simple_list *list) {
    struct br_simple_node *node;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)node;

    return original_BrSimpleRemHead(list);
}

static void(__cdecl*original_BrSimpleInsert)(struct br_simple_list *, struct br_simple_node *, struct br_simple_node *) = (void(__cdecl*)(struct br_simple_list *, struct br_simple_node *, struct br_simple_node *))0x004e5f30;
CARM95_HOOK_FUNCTION(original_BrSimpleInsert, BrSimpleInsert)
void __cdecl BrSimpleInsert(struct br_simple_list *list, struct br_simple_node *here, struct br_simple_node *node) {
    LOG_TRACE("(%p, %p, %p)", list, here, node);

    (void)list;
    (void)here;
    (void)node;

    original_BrSimpleInsert(list, here, node);
}

static struct br_simple_node *(__cdecl*original_BrSimpleRemove)(struct br_simple_node *) = (struct br_simple_node *(__cdecl*)(struct br_simple_node *))0x004e5f50;
CARM95_HOOK_FUNCTION(original_BrSimpleRemove, BrSimpleRemove)
struct br_simple_node* __cdecl BrSimpleRemove(struct br_simple_node *node) {
    LOG_TRACE("(%p)", node);

    (void)node;

    return original_BrSimpleRemove(node);
}

