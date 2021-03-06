/*
NATHANIEL BURLEY
WASHINGTON STATE UNIVERSITY
COMPUTER SCIENCE 121
*/

#ifndef AI_H
#define AI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function that checks for three in a row

//Function that plays a turn for the computer
void play_computer_turn(Cell board[][BOARD_COLS], int player_number, int *row, int *col);

//Function that checks for three X's in a row vertically
//Returns the column if three in a row, 0 otherwise
int three_in_row_vert(Cell board[][BOARD_COLS]);

//Function that checks for three X's in a row horizontally
//Returns the column open if three in a row with space open, 0 otherwise
int three_in_row_horiz(Cell board[][BOARD_COLS]);


#endif
