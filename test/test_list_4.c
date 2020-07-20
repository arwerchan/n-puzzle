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

  /*char board_up[3][3] = {{'1',' ','3'}, // state to test, all moves possible
                         {'4','2','6'}, // h_val is 6
                         {'7','5','8'}};

  char board_down[3][3] = {{'1','2','3'}, // state to test, all moves possible
                           {'4','5','6'}, // h_val is 2 
                           {'7',' ','8'}};

  char board_left[3][3] = {{'1','2','3'}, // state to test, all moves possible
                           {' ','4','6'}, // h_val is 6
                           {'7','5','8'}};

  char board_right[3][3] = {{'1','2','3'}, // state to test, all moves possible
                            {'4','6',' '}, // h_val 4
                            {'7','5','8'}}; */
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
  

  List *tmp_list = (List*)malloc(sizeof(List));
  // call explore node with empty list, expect 4 nodes in list
  exploreNode(&tmp_list, node_p, &goal_s);
  Node* iterate_node = tmp_list->tail;
  for (i=0; i<4; i++) {
    if (iterate_node == NULL) {
      free(state_p);
      free(node_p);
      free(tmp_list);
      return false;
    } 
    else {
      iterate_node = iterate_node->parent;
    }
  }
  free(state_p);
  free(node_p);
  free(tmp_list);
  
  return true;
}

int main() {
  return TEST_PASSED;
}
