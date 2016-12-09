#include "connect4_functions.h"

//Function that initializes the game board (one extra space to avoid 0 based cols)
void init_board(Cell board[][BOARD_ROWS])
{
  for (int i=0; i<BOARD_ROWS; i++)
  {
    for (int j=0; j<BOARD_COLS; j++)
    {
      board[i][j].token = '_';
      board[i][j].place.row = j;
      board[i][j].place.col = i;
    }

  }

}

//Function that prints the game board
void print_board(Cell board[][BOARD_ROWS])
{
  for (int i=0; i<BOARD_ROWS; i++)
  {
    for (int j=0; j<BOARD_COLS; j++)
    {
      printf("%c ", board[i][j].token);
    }
    printf("\n");
  }
  printf("\n");
}

//Function that determines if a column is available
//Returns 1 for open, 0 for full
int check_col(Cell board[][BOARD_ROWS], int column)
{
  for (int i=BOARD_ROWS; i>=0; i--)
  {
    if (board[i][column].token == '_')
    {
      return 1;
    }

  }
  return 0;
}

//Function that allows a player to make a move
void play_turn(Cell board[][BOARD_ROWS], int player_number)
{
  //Gets column choice from the user
  int col_choice = 9;
  printf("PLAYER %d\n", player_number);
  do
  {
    printf("Enter a choice of column: ");
    scanf("%d", &col_choice);
  } while(col_choice < 0 || col_choice > 6 || !check_col(board, col_choice));

  //Drops player one token (X)
  if (player_number == PLAYER_ONE)
  {
    for (int i=BOARD_ROWS-1; i>=0; i--)
    {
      if (board[i][col_choice].token == '_')
      {
        board[i][col_choice].token = 'X';
        break;
      }

    }

  }
  //Drops player two token (O)
  else if (player_number == PLAYER_TWO)
  {
    for (int i=BOARD_ROWS-1; i>=0; i--)
    {
      if (board[i][col_choice].token == '_')
      {
        board[i][col_choice].token = 'O';
        break;
      }

    }

  }
  print_board(board);
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
