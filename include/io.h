/*
 * File:    io.h
 * Author:  Andrew Werchan
 * Prologue:
 */
#ifndef IO_H
#define IO_H
#include<stdio.h>
#include "state.h"

// print the info graphic to the 8-puzzle solver
void startMsg(void);

// print the directions to the user
void printInstructions(void);

// fill the initial puzzle state from the input from user
void fillState(State *state);

// print the board to stdout
void printState(char const board[3][3]);

#endif
