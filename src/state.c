/*
 * file: state.c
 * Author: Andrew Werchan
 * Function: The state will function as the puzzle state while solving.
 */
#include "../include/state.h"

// compare two states to see if their board arrays match. If at any time the
// tile at [i][j] for s_1 does not match the corresponding tile for s_2 the
// function will exit false
bool compareStates(State const *s_1, State const *s_2) {
  int i, j;
  for (i=0; i<3; i++){
    for (j=0; j<3; j++){
      if (s_1->board[i][j] != s_2->board[i][j]) {
        return false;
      }
    }
  }
  return true;
}
