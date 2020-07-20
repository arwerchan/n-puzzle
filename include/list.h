/*
 * file:    list.h
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 */
#ifndef LIST_H
#define LIST_H
#include<stdbool.h>

#include "node.h"

typedef struct List {
  Node* tail;
} List;

// return the node with highest priority in list
Node* popNode(List** list);

// push a node into the list and position with respect to priority
void pushNode(List** list, Node* node);

// check if a Nodes state already exists in a list. Returns true if it exists
bool nodeInList (List** list, Node* node);

#endif
