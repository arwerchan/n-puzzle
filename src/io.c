/*
 * File: io.c
 * Author: Andrew Werchan
 * Function:
 */

#include "../include/io.h"

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

void printInstructions(void){
  printf("\n\
  *----------------------------------------------------------------------------------------*\n\
  * Instructions: Select the type of algorithm to solve the puzzle from the list. You will *\n\
  *               then need to fill out a legal puzzle state to be solved. Once the puzzle *\n\
  *               state is complete you must select the algorithm used to solve it.        *\n\
  *                                                                                        *\n\
  *----------------------------------------------------------------------------------------*\n\n");
}



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
      printf("Puzzle state to solve is:\n\n");
      printState(s->board);
    }
  }
}


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
