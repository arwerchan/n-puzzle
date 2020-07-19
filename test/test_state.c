/*
 * File: test1.c
 * Author: Andrew Werchan
 * Function: Will test the compareStates function. Success will re
 */
#include<stdbool.h>

#include "../include/state.h"

#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif
#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif

bool testCompare() {
  State s_1;
  State s_2;
  int i, j, k;
  k = 0;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = k + '0';
      s_2.board[i][j] = k + '0';
    }
  }
  if (compareStates(&s_1, &s_2)) {
    return true;
  } else {
    return false;
  }
}

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
    return false;
  }
  
  testState = createPuzzleState(&s, DOWN);
  if (testState == NULL || testState->board[2][1] != ' ') {
    return false;
  }

  testState = createPuzzleState(&s, LEFT);
  if (testState == NULL || testState->board[1][0] != ' ') {
    return false;
  }

  testState = createPuzzleState(&s, RIGHT);
  if (testState == NULL || testState->board[1][2] != ' ') {
    return false;
  }
  
  testState = createPuzzleState(&s, -1);
  if (testState != NULL) {
    return false;
  }

  return true;
}

bool testManhattan() {
  State s_1, s_g;
  int i, j;
  char board_g[3][3] = {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8',' '}};

  char board_1[3][3] = {{'1','2','3'}, // manhattan distance = 2
                        {'4','5','6'},
                        {'7',' ','8'}};

  char board_2[3][3] = {{'1','2','3'}, // manhattan distance = 6
                        {' ','5','6'},
                        {'4','7','8'}};
  
  char board_3[3][3] = {{'1','2','3'}, // manhattan distance = 0
                        {'4','5','6'},
                        {'7','8',' '}};
 
  // set the board value in state to board_1
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_1[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_g) != 2) {
    return false;
  }
  
  // set the board value in state to board_1
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_2[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_g) != 6) {
    return false;
  }

  
  // set the board value in state to board_1
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_3[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_1) != 0) {
    return false;
  }

  return true;
}

int  main(void) {
  if (testCompare() == false) {
    return TEST_FAILED;
  }
  if (testMove() == false) {
    return TEST_FAILED;
  }
  if (testManhattan() == false) {
    return TEST_FAILED;
  }

  return TEST_PASSED;
}
