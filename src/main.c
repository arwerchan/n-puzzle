/*
 * File:    main.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */

#include<stdlib.h>
#include<stdio.h>

#include "../include/io.h"
#include "../include/node.h"
#include "../include/list.h"
#include "../include/solver.h"

// main code entry. Allocate a initial and goal state, print the info and
// instructional messages then call the A* search solver function.
int main(void) {
  
  startMsg();
  printInstructions();

  // get a state struct for the initial state
  State *initial_state;
  initial_state = (State*)malloc(sizeof(State));

  // get a state struct for the goal state
  State *goal_state;
  goal_state = (State*)malloc(sizeof(State));

  // initialize the goal state
  int i, j;
  int k = 1;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      goal_state->board[i][j] = k + '0';   
      k++;
    }
  }
  // set the blank tile to lower right corner.
  goal_state->board[2][2] = ' ';
  printState(goal_state->board);


  // get user to fill in puzzle state if the state is non NULL
  if (initial_state) {
    fillState(initial_state);
  }

  aStar(initial_state, goal_state);

  return EXIT_SUCCESS;
}
