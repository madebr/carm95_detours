#ifndef _BRLISTS_H_
#define _BRLISTS_H_

#include "br_types.h"


void BrNewList(struct br_list *list);

void BrAddHead(struct br_list *list, struct br_node *node);

void BrAddTail(struct br_list *list, struct br_node *node);

struct br_node* BrRemHead(struct br_list *list);

struct br_node* BrRemTail(struct br_list *list);

void BrInsert(struct br_list *list, struct br_node *here, struct br_node *node);

struct br_node* BrRemove(struct br_node *node);

void BrSimpleNewList(struct br_simple_list *list);

void BrSimpleAddHead(struct br_simple_list *list, struct br_simple_node *node);

struct br_simple_node* BrSimpleRemHead(struct br_simple_list *list);

void BrSimpleInsert(struct br_simple_list *list, struct br_simple_node *here, struct br_simple_node *node);

struct br_simple_node* BrSimpleRemove(struct br_simple_node *node);

#endif
