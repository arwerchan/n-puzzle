/*
 * File:    state.h
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */
#ifndef STATE_H
#define STATE_H

#ifndef BLANK
#define BLANK ' '
#endif

#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

// structure State will hold the current puzzle state, and will contain a 3x3
// char array holding the piece values.
typedef struct{
  char board[3][3];
} State;

// possible puzzle moves for the blank piece. 
typedef enum {
  UP, DOWN, LEFT, RIGHT
} Move;

// compare two states boards. If they match return true
bool compareStates(State const *state_1, State const *state_2);

// Create the initial state from state_1, will be the goal state
void fillGoalState(State *state_1);

// Create new state from state_p and Move, If valid will return new State ptr.
State* createPuzzleState(State const *state_p, Move);

// get manhattan hueristic disdance of State state_1
int calculateManhattan(State const *state_1, State const *goalState);

#endif  
