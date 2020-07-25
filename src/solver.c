/**
 * @author      : Andrew Werchan (arwerchan@gmail.com)
 * @file        : solver
 * @created     : Monday Jul 20, 2020 18:02:58 MST
 */

#include "../include/solver.h"

void aStar(State *initial, State* goal) {

  // create the open list, nodes to be explored go in here
  List* open_list;
  open_list = (List*)malloc(sizeof(List));

  // create the closed list, nodes explored go here.
  List* closed_list;
  closed_list = (List*)malloc(sizeof(List));

  Node* root_node;
  root_node = (Node*)malloc(sizeof(Node));

  // create the root node, has INT_MAX for its cost
  root_node = createNode(0, 0, initial, NULL);
  pushNode(&open_list, root_node);

  do {
    // pop the tail from the open list
    Node* node_to_explore = popNode(&open_list); 
    // check if node contains solution
    if (compareStates(node_to_explore->state, goal)) {
      printf("\nSolved!\n");
      printState(node_to_explore->state->board);
      break;
    }
    pushNode(&closed_list, node_to_explore);
    exploreNode(&open_list, &closed_list,  node_to_explore, goal);
  } while (open_list->tail != NULL);

  return;
}
