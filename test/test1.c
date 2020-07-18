/*
 * File: test1.c
 * Author: Andrew Werchan
 * Function: Will test the compareStates function. Success will re
 */
#include<stdbool.h>

#include "../include/state.h"

int  main(void) {
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
  k = !compareStates(&s_1, &s_2);
  return k;
}
