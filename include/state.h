/*
 * File:    state.h
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 */
#ifndef STATE_H
#define STATE_H

#ifndef BLANK
#define BLANK ' '
#endif

#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct{
  char board[3][3];
} State;

typedef enum {
  UP, DOWN, LEFT, RIGHT
} Move;

// compare two states boards. If they match return true
bool compareStates(State const *state_1, State const *state_2);

// Create the initial state, will be the goal state
void fillGoalState(State *state);

State* createPuzzleState(State const *state, Move);

int calculateManhattan(State const *state, State const *goalState);

#endif  
