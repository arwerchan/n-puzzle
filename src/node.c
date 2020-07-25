/*
 * File:    node.c
 * Author:  Andrew Werchan (arwerchan@gmail.com
 * Prologue:
 */
#include "../include/node.h"

// Create a new Node. Will set the nodes depth equal to d, its hueristic cost
// to h, its state to s, and its parent to p.
Node* createNode(int d, int h, State *s, Node *p) {
  Node* newNode = NULL;
  newNode = (Node*)malloc(sizeof(Node));
  
  if (newNode != NULL) {
    newNode->d_cost = d;
    newNode->h_cost = h;
    newNode->state = s;
    newNode->parent = p;
  }
  return newNode;
}


// return the cost of a Node. Cost is defined as f(n) = g(n) + h(n), where
// h(n) is the huersitic, manhattan distance of puzzle state, and g(n) is the
// cost represented as the nodes depth.
int nodeCost(Node* const n) {
  if (n != NULL) {
    return n->d_cost + n->h_cost;
  }
  else return (int)INFINITY;
}
