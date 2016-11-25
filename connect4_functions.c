#include "connect4_functions.h"

//Function that initializes the game board
void init_board(char board[][7])
{
  for (int i=0; i<BOARD_ROWS; i++)
  {
    for (int j=0; j<BOARD_COLS; j++)
    {
      board[i][j] = '_';
    }
  }
}

//Function that prints the game board
void print_board(char board[][7])
{
  for (int i=0; i<BOARD_ROWS; i++)
  {
    for (int j=0; j<BOARD_COLS; j++)
    {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}
