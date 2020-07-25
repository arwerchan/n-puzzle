/*
 * File:    list.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */
#include "../include/list.h"


/* Return the list tail, which is the highest priority Node in the list. If the
 * list is empty then returns a NULL pointer. */
Node* popNode(List **list) {
  // if list is empty retrun NULL pointer
  if (list == NULL) {
    return NULL;
  } 
  // if the list tail is NULL return a NULL pointer. Check here in case LIST
  // was NULL which would cause a NULL access exception
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
    node->parent = NULL;
    return;
  } 
  
  // get the cost f(n) of the node to push to list
  int n_cost = 0; 
  n_cost = nodeCost(node);
  
  // if current priority is higher (lower cost) than the current list tail then
  // insert the node as the new tail
  if (n_cost <= nodeCost((*list)->tail)) {
    node->parent = (*list)->tail;
    (*list)->tail = node;
    return;
  }
 
  // starting with the tail begin iterating though the list to determine where
  // the new node should be inserted based on its priority. If the  
  Node* iterateNode = (*list)->tail;
  while (iterateNode->parent != NULL && n_cost > nodeCost((iterateNode->parent))) {
    // advance to next node in the list
    iterateNode = iterateNode->parent;
  }
  // insert node and set its parent to the iterate nodes parent and the iterate
  // nodes parent to the node.
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
    // if the state from node is the same as one in the list, than return true
    if (compareStates(node->state, iterateNode->state)){
      return true;
    } else {
      // go to next node in list
      iterateNode = iterateNode->parent;
    }
  }
  return false;
}

// Explore a node and add discovered nodes to the priority list
void exploreNode(List** open, List** closed, Node* node, State* const goal) {
  
  State* new_state = NULL;
  int h_val, d_val;
  // try move UP
  new_state = createPuzzleState(node->state, UP); 
  if (new_state != NULL) {
    // move was valid, create a new Node to hold the state
    Node* new_node = NULL;
    // calculate this states manhattan distance
    h_val = calculateManhattan(new_state, goal);
    // this nodes depth is its parents depth + 1
    d_val = node->d_cost + 1; 
    // create a new node with new_state and cost of h_val+d_val as a child
    // of node (node will be parent of new_node).
    new_node = createNode(d_val, h_val, new_state, node);
    // if node is not in the closed list, push it into the closed list, 
    // else free it and continue with other moves.
    if (nodeInList(closed, new_node) == false) {
      pushNode(open, new_node);
    } 
    else {
      // free allocated memory if node is not added to open list
      free(new_state); 
      free(new_node);
    }
  }

  // try move DOWN
  new_state = createPuzzleState(node->state, DOWN); // try move DOWN
  if (new_state != NULL) {
    // move was valid, create a new Node to hold the state
    Node* new_node = NULL;
    // calculate this nodes manhattan distance
    h_val = calculateManhattan(new_state, goal);
    // thie nodes depth is its parents depth + 1
    d_val = node->d_cost + 1;
    // create a new node with new_state and cost of h_val+d_val as a child
    // of node (node will be parent of new_node)
    new_node = createNode(d_val, h_val, new_state, node);
    // if node is not in then closed list, push it into the open list, 
    // else free it and continue with other moves
    if (nodeInList(closed, new_node) == false) {
      pushNode(open, new_node);
    }
    else {
      // free allocated memory if node is not added to open list
      free(new_state);
      free(new_node);
    }
  }

  // try move LEFT
  new_state = createPuzzleState(node->state, LEFT);
  if (new_state != NULL) {
    // move was valid, create a new Node to hold the state
    Node* new_node = NULL;
    // calcualte this nodes manhattan distance
    h_val = calculateManhattan(new_state, goal);
    // this nodes depth is its parents depth + 1
    d_val = node->d_cost + 1;
    // create a new node with new_state and cost of h_val+d_val as a child 
    // of node (node will be parent of new_node)
    new_node = createNode(d_val, h_val, new_state, node);
    // if node is not in the closed list, push it into the open list, 
    // else free it and continue with last possible move
    if (nodeInList(closed, new_node) == false) {
      pushNode(open, new_node);
    }
    else {
      // free allocated memory if node is not added to open list
      free(new_state);
      free(new_node);
    }
  }

  // try last move, RIGHT
  new_state = createPuzzleState(node->state, RIGHT);
  if (new_state != NULL) {
    // move was valid, create a new Node to hold the state
    Node* new_node = NULL;
    // calculate thie nodes manhattan distance
    h_val = calculateManhattan(new_state, goal);
    // this nodes depth is its parents depth + 1
    d_val = node->d_cost + 1;
    // create a new node with new_state and cost of h_val+d_val as a child
    // of node (node will be parent of new_node)
    new_node = createNode(d_val, h_val, new_state, node);
    // if node is not in the closed list, push it into the open list, 
    // else free it and return to caller
    if (nodeInList(closed, new_node) == false) {
      pushNode(open, new_node);
    }
    else {
      // free allocated memory if node is not added to open list
      free(new_state);
      free(new_node);
    }
  }

  return;
}
