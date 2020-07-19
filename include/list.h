/*
 * file: list.h
 * Author: Andrew Werchan
 * Function: definitions of all functions used by the List struct
 */
#ifndef LIST_H
#define LIST_H
#include "node.h"

typedef struct List {
  Node* tail;
} List;

#endif
