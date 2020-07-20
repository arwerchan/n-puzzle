/*
 * file:    state.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */
#include "../include/state.h"

/* compare two states to see if their board arrays match. If at any time the
 * tile at [i][j] for s_1 does not match the corresponding tile for s_2 the
 * function will exit false */
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

/* iterate through the goal state and set its tiles in ascending value as
 * shown here:
 * 1 2 3
 * 4 5 6
 * 7 8 
 */
void fillGoalState(State *s) {
  int i, j, board_val;
  board_val = 1;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      s->board[i][j] = board_val + '0';
      board_val++;
    }
  }
  s->board[2][2] = ' '; // set the zero to a blank character
  return;
}


// create a puzzle state that is the successor of state s by taking the current
// state in s and moving the blank either UP, DOWN, LEFT, or RIGHT. If the 
// blank can be moved that direction while remaining valid (within the puzzle
// boundaries) then return a pointer to the new state.
State* createPuzzleState(State const *s, Move m) {
  State *newState = NULL;
  newState = (State*)malloc(sizeof(State));
  
  int i, j, i_pos, j_pos;
  i_pos = 0;
  j_pos = 0;
  
  // check that new state is not NULL
  if (newState != NULL) {
    // copy the board from s into board in newState, and get the x/y position
    // of the blank piece. 
    for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
        newState->board[i][j] = s->board[i][j];
        if (newState->board[i][j] == BLANK) {
          i_pos = i; // mark blank position  x position
          j_pos = j; // mark blank location y position
        }
      }
    }
  } 
  else { 
    return NULL;
  }

  /*
   * Check the coordinates would be valid after the swap. The blank needs to 
   * have the square above, below, left, or right of it within the boundaries
   * of the State to be valid. */
  char tmpChar;
  if (m == UP && i_pos - 1 >= 0) {
    tmpChar = newState->board[i_pos - 1][j_pos]; // copy tile where blank goes
    newState->board[i_pos - 1][j_pos] = BLANK; // move in blank
    newState->board[i_pos][j_pos] = tmpChar; // replace the old blank
    return newState;
  } 
  else if (m == DOWN && i_pos + 1 < 3 ) {
    tmpChar = newState->board[i_pos + 1][j_pos]; // copy tile where blank goes
    newState->board[i_pos + 1][j_pos] = BLANK; // move in blank
    newState->board[i_pos][j_pos] = tmpChar; // replace the old blank
    return newState;
  } 
  else if (m == LEFT && j_pos - 1 >= 0) {
    tmpChar = newState->board[i_pos][j_pos - 1]; // copy tile where blank goes
    newState->board[i_pos][j_pos - 1] = BLANK; // move in blank
    newState->board[i_pos][j_pos] = tmpChar; // replace the old blank
    return newState;
  } 
  else if (m == RIGHT && j_pos + 1 < 3) {
    tmpChar = newState->board[i_pos][j_pos + 1]; // copy tile where blank goes
    newState->board[i_pos][j_pos + 1] = BLANK; // move in blank
    newState->board[i_pos][j_pos] = tmpChar; // replace the old blank
    return newState;
  } 
  else {
    free(newState);
    return NULL; 
  }
   
  return newState;
}


// calculate and return the manhattan distance which will be the sum of the 
// difference of the out of place tiles positions.
int calculateManhattan(State const *s, State const *g) {
  int i, j, ii, jj;
  int delta_x, delta_y;
  int manhattanDistance;
  
  // used to hold the sum of difference
  manhattanDistance = 0;

  // for each tile in state s its equal will be found in the goal state g, the
  // difference in their location is added to the sum.
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      // calculate the difference of the tiles' position with respect to the
      // goal state'
      for (ii=0; ii<3; ii++) {
        for (jj=0; jj<3; jj++){
          if (s->board[i][j] == g->board[ii][jj]) {
            delta_x = abs(i - ii);
            delta_y = abs(j - jj);
            manhattanDistance += (delta_x + delta_y);
          }
        }
      }
    }
  }
  return manhattanDistance;
}
