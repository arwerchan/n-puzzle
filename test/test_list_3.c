/**
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * File:    test_list_3
 * Prologue:
 */
#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif
#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

#include<stdbool.h>

#include "../include/list.h"

bool testInList() {
  List* list = (List*)malloc(sizeof(List));
  char board_g[3][3] = {{'1','2','3'}, // goal state to test against
                        {'4','5','6'},
                        {'7','8',' '}};
  int i, j;
  State s_1, s_2, s_3, s_4;
  // create 3 boards that are identical to board_g
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_g[i][j];
      s_2.board[i][j] = board_g[i][j];
      s_3.board[i][j] = board_g[i][j];
      s_4.board[i][j] = board_g[i][j];
    }
  }
  // modify s_3 to be different by one piece
  s_4.board[1][1] = '0';
  Node* testNode_1 = createNode(0, 0, &s_1, NULL);
  Node* testNode_2 = createNode(0, 0, &s_2, NULL);
  Node* testNode_3 = createNode(0, 0, &s_3, NULL);
  Node* testNode_4 = createNode(0, 0, &s_4, NULL);

  // insert the 3 nodes and then call to verify nodeInList() 
  pushNode(&list, testNode_1);
  pushNode(&list, testNode_2);
  pushNode(&list, testNode_3);

  // testNode_1 is in list, expect true
  if (nodeInList(&list, testNode_1) == false) {
    free(testNode_1);
    free(testNode_2);
    free(testNode_3);
    free(testNode_4);
    return false;
  }

  // s_4 not pushed to list, expect false
  if (nodeInList(&list, testNode_4) == true) {
    free(testNode_1);
    free(testNode_2);
    free(testNode_3);
    free(testNode_4);
    return false;
  }
  // cleanup and free memory
  free(testNode_1);
  free(testNode_2);
  free(testNode_3);
  free(testNode_4);

  return true;
}

int main() {
  if (testInList() == false) {
    return TEST_FAILED;
  }
  return TEST_PASSED;
}
