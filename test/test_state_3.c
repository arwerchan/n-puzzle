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

bool testManhattan() {
  State s_1, s_g;
  int i, j;
  char board_g[3][3] = {{'1','2','3'}, // goal state to test against
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
      s_g.board[i][j] = board_g[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_g) != 2) {
    return false;
  }
  
  // set the board value in state to board_1
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_2[i][j];
      s_g.board[i][j] = board_g[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_g) != 6) {
    return false;
  }

  
  // set the board value in state to board_1
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s_1.board[i][j] = board_3[i][j];
      s_g.board[i][j] = board_g[i][j];
    }
  }

  if (calculateManhattan(&s_1, &s_1) != 0) {
    return false;
  }

  return true;
}

int  main(void) {
  if (testManhattan() == false) {
    return TEST_FAILED;
  }
  return TEST_PASSED;
}
