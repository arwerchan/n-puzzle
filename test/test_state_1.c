/*
 * File:    test_state_1.c
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


int  main(void) {
  if (testCompare() == false) {
    return TEST_FAILED;
  }
  return TEST_PASSED;
}
