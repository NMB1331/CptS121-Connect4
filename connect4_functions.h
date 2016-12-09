#ifndef CONNECT_4_H
#define CONNECT_4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_COLS 7
#define BOARD_ROWS 6
#define PLAYER_ONE 1
#define PLAYER_TWO 2

typedef struct location
{
  int row;
  int col;
}Location;

typedef struct cell
{
  char token;
  Location place;
}Cell;

//Function that initializes the game board
void init_board(Cell board[][8]);

//Function that prints the game board
void print_board(Cell board[][8]);

//Function that determines if a column is available
//Returns 1 for open, 0 for full
int check_col(Cell board[][8], int column);

//Function that checks if the board is full
//Returns 1 for full, 0 for open
int is_full(Cell board[][8]);

//Function that allows a player to make a move
void play_turn(Cell board[][8], int player_number);

#endif
