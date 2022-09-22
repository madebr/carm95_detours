#ifndef _BRLISTS_H_
#define _BRLISTS_H_

#include "br_types.h"


void __cdecl BrNewList(struct br_list *list);

void __cdecl BrAddHead(struct br_list *list, struct br_node *node);

void __cdecl BrAddTail(struct br_list *list, struct br_node *node);

struct br_node* __cdecl BrRemHead(struct br_list *list);

struct br_node* __cdecl BrRemTail(struct br_list *list);

void __cdecl BrInsert(struct br_list *list, struct br_node *here, struct br_node *node);

struct br_node* __cdecl BrRemove(struct br_node *node);

void __cdecl BrSimpleNewList(struct br_simple_list *list);

void __cdecl BrSimpleAddHead(struct br_simple_list *list, struct br_simple_node *node);

struct br_simple_node* __cdecl BrSimpleRemHead(struct br_simple_list *list);

void __cdecl BrSimpleInsert(struct br_simple_list *list, struct br_simple_node *here, struct br_simple_node *node);

struct br_simple_node* __cdecl BrSimpleRemove(struct br_simple_node *node);

#endif
