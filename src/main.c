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

// main code entry. Allocate a initial and goal state, print the info and
// instructional messages then call the A* search solver function.
int main(void) {
  
  startMsg();
  printInstructions();

  // get a state struct for the initial and goal states
  State *initial_state = NULL;
  initial_state = (State*)malloc(sizeof(State));

  // get user to fill in puzzle state if the state is non NULL
  if (initial_state) {
    fillState(initial_state);
  }

  return EXIT_SUCCESS;
}
