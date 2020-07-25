/*
 * File:    node.h
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */
#ifndef NODE_H
#define NODE_H
#include<stdlib.h>
#include<math.h>

#include "state.h"

// Node will be used for graph vertecies. Each node will have a corresponding
// puzzle state, a depth, a hueristic cost and a parent Node, which it is a
// successor of. 
typedef struct Node {
  int d_cost; // depth
  int h_cost; // hueristic
  State* state; 
  struct Node* parent;
} Node;

/* createNode returns a new Node and takes arguments. d represents the depth of
 * the new node, h represents the heuristic, s will be the state within the new
 * node, and p will be this nodes parent node. */
Node* createNode(int depth, int heuristic, State *state, Node *parent);


// Get the current cost f(n)=h(n)+g(n) of Node node where h(n) is the heuristic
// and g(n) is the nodes depth from the root Node
int nodeCost(Node* const node);

#endif
