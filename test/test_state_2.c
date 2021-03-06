/*
 * File:    test_state_2.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */
#include<stdbool.h>

#include "../include/state.h"

#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif
#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

bool testMove() {
  State s;
  int i, j;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s.board[i][j] = '1';
      if (i == 1 && j == 1) {
        s.board[i][j] = BLANK; // put blank in middle of board
      }
    }
  }
  State *testState = NULL;
  testState = createPuzzleState(&s, UP);
  // if blank is not where expected or returned state is null - test fails
  if (testState == NULL || testState->board[0][1] != ' ') {
    free(testState);
    return false;
  }
  
  testState = createPuzzleState(&s, DOWN);
  if (testState == NULL || testState->board[2][1] != ' ') {
    free(testState);
    return false;
  }

  testState = createPuzzleState(&s, LEFT);
  if (testState == NULL || testState->board[1][0] != ' ') {
    free(testState);
    return false;
  }

  testState = createPuzzleState(&s, RIGHT);
  if (testState == NULL || testState->board[1][2] != ' ') {
    free(testState);
    return false;
  }
  
  testState = createPuzzleState(&s, -1);
  if (testState != NULL) {
    free(testState);
    return false;
  }
  free(testState);
  return true;
}


int  main(void) {
  if (testMove() == false) {
    return TEST_FAILED;
  }
  return TEST_PASSED;
}
