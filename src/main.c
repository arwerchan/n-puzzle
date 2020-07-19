/*
 * File: main.c
 * Author: Andrew Werchan
 * Function: main function entry.
 */

#include<stdlib.h>
#include<stdio.h>

#include "../include/io.h"
#include "../include/node.h"

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
