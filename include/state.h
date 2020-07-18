/*
 * File: state.h
 * Author: Andrew Werchan
 * Function: Defines the state and functions that work on it. The state is used
 *           to represent the puzzle state.
 */
#ifndef STATE_H
#define STATE_H
#include<stdbool.h>

typedef struct{
  char board[3][3];
} State;

typedef enum {
  UP, DOWN, LEFT, RIGHT
} MOVE;

// compare two states boards. If they match return true
bool compareStates(State const *s1, State const *s2);

#endif  
