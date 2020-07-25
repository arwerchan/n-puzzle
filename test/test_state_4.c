/**
 * @author      : Andrew Werchan (arwerchan@gmail.com)
 * @file        : test_state_4
 * @created     : Saturday Jul 25, 2020 15:33:05 MST
 */

#include "../include/state.h"

#ifndef TEST_FAILED
#define TEST_FAILED 1
#endif
#ifndef TEST_PASSED
#define TEST_PASSED 0
#endif

bool testSolvable() {
  char not_solvable_board[3][3] = {{'1','2','3'},
                                   {'4','5','6'},
                                   {' ','8','7'}};

  char solvable_board[3][3] = {{'5','2','8'},
                               {'4','1','7'},
                               {' ','3','6'}};

  // if return is true for unsolvable state, fail test
  if (isSolvable(not_solvable_board) == true) {
    return false;
  }
  // if return is false for a solvable state, fail test
  if (isSolvable(solvable_board) == false) {
    return false;
  }
  return true;
}

int main() {
  if (testSolvable() == false) {
    return TEST_FAILED;
  }
  else {
    return TEST_PASSED;
  }
}
