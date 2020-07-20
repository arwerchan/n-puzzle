/*
 * File:    list.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 */
#include "../include/list.h"


/* Return the list tail, which is the highest priority Node in the list. if the
 * list is empty then returns a NULL pointer. */
Node* popNode(List **list) {
  if (list == NULL) {
    return NULL;
  } 
  else if ((*list)->tail == NULL) {
    return NULL;
  } 
  else {
    Node* popped_node;
    popped_node = (*list)->tail;
    (*list)->tail = (*list)->tail->parent;
    popped_node->parent = NULL;
    return popped_node;
  }
}

// will push a new Node node into the List list with respect to its priority. 
// Higher priority Nodes will be closer to the list tail. 
void pushNode(List** list, Node* node){
  // if the list is empty, insert node at the tail
  if (list != NULL && (*list)->tail == NULL) {
    (*list)->tail = node;
    return;
  } else {
    return;
  }
  
  int n_cost = 0;
  n_cost = nodeCost(node);
  
  // if current priority is higher (lower cost) than the current list tail then
  // insert the node as the new tail
  if (n_cost <= nodeCost((*list)->tail)) {
    (*list)->tail->parent = node;
    (*list)->tail = node;
  }
 
  // starting with the tail begin iterating though the list to determine where
  // the new node should be inserted based on its priority. 
  Node* iterateNode = (*list)->tail;
  while ((*list)->tail != NULL && n_cost > nodeCost((iterateNode->parent))) {
    iterateNode = iterateNode->parent;
  }
  node->parent = iterateNode->parent;
  iterateNode->parent = node;

  return;
}

// will check the List passed in to determine if the Node node is within. It 
// does this by iterating though each node in the list and comparing the 
// puzzle state within node to the state in the lists node. If they match will
// return true, else it will return false.
bool nodeInList(List** list, Node* node) {
  // if the list pointer is NULL or the list is empty, will return false.
  if (list == NULL) {
    // null list pointer, return false
    return false;
  } 
  else if ((*list)->tail == NULL) {
    // emptry list, return false
    return false;
  }

  // iterate trough list and compare states until a match is found and return 
  // true, or if no match exists will return false.
  Node* iterateNode = (*list)->tail;
  while (iterateNode != NULL) {
    if (compareStates(node->state, iterateNode->state)){
      return true;
    } else {
      iterateNode = iterateNode->parent;
    }
  }
  return false;
}
