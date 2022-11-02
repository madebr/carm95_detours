#include "brlists.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrNewList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrNewList)
static void(__cdecl*original_BrNewList)(struct br_list *) = (void(__cdecl*)(struct br_list *))0x004e5df0;
CARM95_HOOK_FUNCTION(original_BrNewList, BrNewList)
void __cdecl BrNewList(struct br_list *list) {
    LOG_TRACE("(%p)", list);

    (void)list;

    if (function_hook_state_BrNewList == HOOK_ENABLED) {
        assert(0 && "BrNewList not implemented.");
        abort();
    } else {
        original_BrNewList(list);
    }
}

function_hook_state_t function_hook_state_BrAddHead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrAddHead)
static void(__cdecl*original_BrAddHead)(struct br_list *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *))0x004e5e10;
CARM95_HOOK_FUNCTION(original_BrAddHead, BrAddHead)
void __cdecl BrAddHead(struct br_list *list, struct br_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    if (function_hook_state_BrAddHead == HOOK_ENABLED) {
        assert(0 && "BrAddHead not implemented.");
        abort();
    } else {
        original_BrAddHead(list, node);
    }
}

function_hook_state_t function_hook_state_BrAddTail = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrAddTail)
static void(__cdecl*original_BrAddTail)(struct br_list *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *))0x004e5e30;
CARM95_HOOK_FUNCTION(original_BrAddTail, BrAddTail)
void __cdecl BrAddTail(struct br_list *list, struct br_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    if (function_hook_state_BrAddTail == HOOK_ENABLED) {
        assert(0 && "BrAddTail not implemented.");
        abort();
    } else {
        original_BrAddTail(list, node);
    }
}

function_hook_state_t function_hook_state_BrRemHead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrRemHead)
static struct br_node *(__cdecl*original_BrRemHead)(struct br_list *) = (struct br_node *(__cdecl*)(struct br_list *))0x004e5e50;
CARM95_HOOK_FUNCTION(original_BrRemHead, BrRemHead)
struct br_node* __cdecl BrRemHead(struct br_list *list) {
    struct br_node *n;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)n;

    if (function_hook_state_BrRemHead == HOOK_ENABLED) {
        assert(0 && "BrRemHead not implemented.");
        abort();
    } else {
        return original_BrRemHead(list);
    }
}

function_hook_state_t function_hook_state_BrRemTail = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrRemTail)
static struct br_node *(__cdecl*original_BrRemTail)(struct br_list *) = (struct br_node *(__cdecl*)(struct br_list *))0x004e5e70;
CARM95_HOOK_FUNCTION(original_BrRemTail, BrRemTail)
struct br_node* __cdecl BrRemTail(struct br_list *list) {
    struct br_node *n;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)n;

    if (function_hook_state_BrRemTail == HOOK_ENABLED) {
        assert(0 && "BrRemTail not implemented.");
        abort();
    } else {
        return original_BrRemTail(list);
    }
}

function_hook_state_t function_hook_state_BrInsert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrInsert)
static void(__cdecl*original_BrInsert)(struct br_list *, struct br_node *, struct br_node *) = (void(__cdecl*)(struct br_list *, struct br_node *, struct br_node *))0x004e5e90;
CARM95_HOOK_FUNCTION(original_BrInsert, BrInsert)
void __cdecl BrInsert(struct br_list *list, struct br_node *here, struct br_node *node) {
    LOG_TRACE("(%p, %p, %p)", list, here, node);

    (void)list;
    (void)here;
    (void)node;

    if (function_hook_state_BrInsert == HOOK_ENABLED) {
        assert(0 && "BrInsert not implemented.");
        abort();
    } else {
        original_BrInsert(list, here, node);
    }
}

function_hook_state_t function_hook_state_BrRemove = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrRemove)
static struct br_node *(__cdecl*original_BrRemove)(struct br_node *) = (struct br_node *(__cdecl*)(struct br_node *))0x004e5eb0;
CARM95_HOOK_FUNCTION(original_BrRemove, BrRemove)
struct br_node* __cdecl BrRemove(struct br_node *node) {
    LOG_TRACE("(%p)", node);

    (void)node;

    if (function_hook_state_BrRemove == HOOK_ENABLED) {
        assert(0 && "BrRemove not implemented.");
        abort();
    } else {
        return original_BrRemove(node);
    }
}

function_hook_state_t function_hook_state_BrSimpleNewList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrSimpleNewList)
static void(__cdecl*original_BrSimpleNewList)(struct br_simple_list *) = (void(__cdecl*)(struct br_simple_list *))0x004e5ed0;
CARM95_HOOK_FUNCTION(original_BrSimpleNewList, BrSimpleNewList)
void __cdecl BrSimpleNewList(struct br_simple_list *list) {
    LOG_TRACE("(%p)", list);

    (void)list;

    if (function_hook_state_BrSimpleNewList == HOOK_ENABLED) {
        assert(0 && "BrSimpleNewList not implemented.");
        abort();
    } else {
        original_BrSimpleNewList(list);
    }
}

function_hook_state_t function_hook_state_BrSimpleAddHead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrSimpleAddHead)
static void(__cdecl*original_BrSimpleAddHead)(struct br_simple_list *, struct br_simple_node *) = (void(__cdecl*)(struct br_simple_list *, struct br_simple_node *))0x004e5ee0;
CARM95_HOOK_FUNCTION(original_BrSimpleAddHead, BrSimpleAddHead)
void __cdecl BrSimpleAddHead(struct br_simple_list *list, struct br_simple_node *node) {
    LOG_TRACE("(%p, %p)", list, node);

    (void)list;
    (void)node;

    if (function_hook_state_BrSimpleAddHead == HOOK_ENABLED) {
        assert(0 && "BrSimpleAddHead not implemented.");
        abort();
    } else {
        original_BrSimpleAddHead(list, node);
    }
}

function_hook_state_t function_hook_state_BrSimpleRemHead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrSimpleRemHead)
static struct br_simple_node *(__cdecl*original_BrSimpleRemHead)(struct br_simple_list *) = (struct br_simple_node *(__cdecl*)(struct br_simple_list *))0x004e5f00;
CARM95_HOOK_FUNCTION(original_BrSimpleRemHead, BrSimpleRemHead)
struct br_simple_node* __cdecl BrSimpleRemHead(struct br_simple_list *list) {
    struct br_simple_node *node;
    LOG_TRACE("(%p)", list);

    (void)list;
    (void)node;

    if (function_hook_state_BrSimpleRemHead == HOOK_ENABLED) {
        assert(0 && "BrSimpleRemHead not implemented.");
        abort();
    } else {
        return original_BrSimpleRemHead(list);
    }
}

function_hook_state_t function_hook_state_BrSimpleInsert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrSimpleInsert)
static void(__cdecl*original_BrSimpleInsert)(struct br_simple_list *, struct br_simple_node *, struct br_simple_node *) = (void(__cdecl*)(struct br_simple_list *, struct br_simple_node *, struct br_simple_node *))0x004e5f30;
CARM95_HOOK_FUNCTION(original_BrSimpleInsert, BrSimpleInsert)
void __cdecl BrSimpleInsert(struct br_simple_list *list, struct br_simple_node *here, struct br_simple_node *node) {
    LOG_TRACE("(%p, %p, %p)", list, here, node);

    (void)list;
    (void)here;
    (void)node;

    if (function_hook_state_BrSimpleInsert == HOOK_ENABLED) {
        assert(0 && "BrSimpleInsert not implemented.");
        abort();
    } else {
        original_BrSimpleInsert(list, here, node);
    }
}

function_hook_state_t function_hook_state_BrSimpleRemove = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrSimpleRemove)
static struct br_simple_node *(__cdecl*original_BrSimpleRemove)(struct br_simple_node *) = (struct br_simple_node *(__cdecl*)(struct br_simple_node *))0x004e5f50;
CARM95_HOOK_FUNCTION(original_BrSimpleRemove, BrSimpleRemove)
struct br_simple_node* __cdecl BrSimpleRemove(struct br_simple_node *node) {
    LOG_TRACE("(%p)", node);

    (void)node;

    if (function_hook_state_BrSimpleRemove == HOOK_ENABLED) {
        assert(0 && "BrSimpleRemove not implemented.");
        abort();
    } else {
        return original_BrSimpleRemove(node);
    }
}

