/*
 * File:    io.c
 * Author:  Andrew Werchan (arwerchan@gmail.com)
 * Prologue:
 */

#include "../include/io.h"

// print ascii art
void startMsg(void){
  printf("\n\
   @@@@@@              @@@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@@  @@@       @@@@@@@@\n\
  @@@@@@@@             @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@  @@@       @@@@@@@@\n\
  @@!  @@@             @@!  @@@  @@!  @@@       @@!       @@!  @@!       @@!\n\
  !@!  @!@             !@!  @!@  !@!  @!@      !@!       !@!   !@!       !@!\n\
   !@!!@!   @!@!@!@!@  @!@@!@!   @!@  !@!     @!!       @!!    @!!       @!!!:!\n\
   !!@!!!   !!!@!@!!!  !!@!!!    !@!  !!!    !!!       !!!     !!!       !!!!!:\n\
  !!:  !!!             !!:       !!:  !!!   !!:       !!:      !!:       !!:\n\
  :!:  !:!             :!:       :!:  !:!  :!:       :!:        :!:      :!:\n\
  ::::: ::              ::       ::::: ::   :: ::::   :: ::::   :: ::::   :: ::::\n\
    : :  :               :         : :  :   : :: : :  : :: : :  : :: : :  : :: :: \n\n");

  printf("\n\n\
  \t       @@@@@@    @@@@@@   @@@       @@@  @@@  @@@@@@@@  @@@@@@@\n\
  \t      @@@@@@@   @@@@@@@@  @@@       @@@  @@@  @@@@@@@@  @@@@@@@@\n\
  \t      !@@       @@!  @@@  @@!       @@!  @@@  @@!       @@!  @@@\n\
  \t      !@!       !@!  @!@  !@!       !@!  @!@  !@!       !@!  @!@\n\
  \t      !!@@!!    @!@  !@!  @!!       @!@  !@!  @!!!:!    @!@!!@!\n\
  \t       !!@!!!   !@!  !!!  !!!       !@!  !!!  !!!!!:    !!@!@!\n\
  \t           !:!  !!:  !!!  !!:       :!:  !!:  !!:       !!: :!!\n\
  \t         !:!   :!:  !:!   :!:       ::!!:!   :!:        :!:  !:!\n\
  \t     :::: ::   ::::: ::   :: ::::    ::::     :: ::::   ::   :::\n\
  \t      :: : :     : :  :   : :: : :     :      : :: ::    :   : : \n\n");
}

// print program instructions to the user. 
void printInstructions(void){
  printf("\n\
  *----------------------------------------------------------------------------------------*\n\
  * Instructions: Select the type of algorithm to solve the puzzle from the list. You will *\n\
  *               then need to fill out a legal puzzle state to be solved. Once the puzzle *\n\
  *               state is complete you must select the algorithm used to solve it.        *\n\
  *                                                                                        *\n\
  *----------------------------------------------------------------------------------------*\n\n");
}


// Have the user fill the initial start puzzle state.
void fillState(State* s){
  int i, j, k;
  char usedVals[9] = { 0 }; // array of flag chars to keep track of input values
  int buffer;
  k = 0;

  // initialize the board to blanks
  char blankVal = '0';
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      s->board[i][j] = blankVal;
    }
  }

  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      k++;
      printf("Enter value for tile number %d . \n", k);
      scanf("%i", &buffer);

      // loop thorugh and fill the puzzle state. Repeat entries or entries that
      // are not between 0 and 8 inclusive will be rejected.
      if (buffer >= 0 && buffer <9){
        if (!usedVals[buffer]) {
          // convert input to ascii char and insert into board
          s->board[i][j] = buffer +'0'; 
          if (s->board[i][j] == '0') {
            s->board[i][j] = ' '; // convert the zero to a blank
          }
          usedVals[buffer] = 1; // turn on flag indicated value is used
        } else {
          printf("Value already entered.\n");
          j--;
          k--;
        }
      } else{
        printf("Invalid input. Must be a number between 1 and 8 inclusive.\n");
        j--;
        k--;
      }
      // print the puzzle state the user selected to solve
      printf("Puzzle state to solve is:\n\n");
      printState(s->board);
    }
  }
}

// print the puzzle state to the console
void printState(char const board[3][3]) {
  int i, j;
  for (i=0; i<3; i++) {
    printf("+---+---+---+\n");
    for(j=0; j<3; j++) {
      printf("| %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("+---+---+---+\n");
}
