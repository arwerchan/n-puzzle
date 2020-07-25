/**
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * File:    test_list_4
 * Prologue:
 */
#include<stdbool.h>

#include "../include/list.h"

#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif
#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

bool testExplore() {
  char board_m[3][3] = {{'1','2','3'}, // state to test, all moves possible
                        {'4',' ','6'},
                        {'7','5','8'}};

  int i, j;
  Node* node_p = NULL;
  node_p = (Node*)malloc(sizeof(Node));
  State* state_p = NULL;
  state_p = (State*)malloc(sizeof(State)); 
  node_p = createNode(0, 0, state_p, NULL);
  // create 3 boards that are identical to board_g
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      node_p->state->board[i][j] = board_m[i][j];
    }
  }

  char board_g[3][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8',' '}};
  State goal_s;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      goal_s.board[i][j] = board_g[i][j];
    }
  }
  

  List *tmp_open = (List*)malloc(sizeof(List));
  List *tmp_closed = (List*)malloc(sizeof(List));
  // call explore node with empty list, expect 4 nodes in list
  exploreNode(&tmp_open, &tmp_closed, node_p, &goal_s);
  Node* iterate_node = tmp_open->tail;
  for (i=0; i<4; i++) {
    if (iterate_node == NULL) {
      free(state_p);
      free(node_p);
      free(tmp_open);
      free(tmp_closed);
      return false;
    } 
    else {
      iterate_node = iterate_node->parent;
    }
  }
  free(state_p);
  free(node_p);
  free(tmp_open);
  free(tmp_closed);
  
  return true;
}

int main() {
  return TEST_PASSED;
}
