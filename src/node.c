/*
 * File: node.c
 * Author: Andrew Werchan
 * Function: Implementations of all functions operating on Node stucts
 */
#include "../include/node.h"

// Create a new Node.
Node* createNode(int d, int h, State *s, Node *p) {
  Node* newNode = NULL;
  newNode = (Node*)malloc(sizeof(Node));
  
  if (newNode != NULL) {
    newNode->d_cost = d;
    newNode->h_cost = h;
    newNode->s = s;
    newNode->parent = p;
  }

  return newNode;
}
