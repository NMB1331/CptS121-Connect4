#include "connect4_functions.h"

//Function that initializes the game board (one extra space to avoid 0 based cols)
void init_board(Cell board[][8])
{
  for (int i=0; i<7; i++)
  {
    for (int j=0; j<8; j++)
    {
      board[i][j].token = '_';
      board[i][j].place.row = j;
      board[i][j].place.col = i;
    }

  }

}

//Function that prints the game board
void print_board(Cell board[][8])
{
  for (int i=1; i<7; i++)
  {
    for (int j=1; j<8; j++)
    {
      printf("%c ", board[i][j].token);
    }
    printf("\n");
  }
  printf("\n");
}

//Function that determines if a column is available
//Returns 1 for open, 0 for full
int check_col(Cell board[][8], int column)
{
  for (int i=7; i>=1; i--)
  {
    if (board[i][column].token == '_')
    {
      return 1;
    }

  }
  return 0;
}

//Function that determines if a column is available
//Returns 0 for open, 1 for full
int is_full(Cell board[][8])
{
  int counter = 0;
  for (int i=1; i<8; i++)
  {
    if (!check_col(board, i))
    {
      counter += 1;
    }

  }

  if (counter == 7)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Function that allows a player to make a move
void play_turn(Cell board[][8], int player_number)
{
  //Gets column choice from the user
  int col_choice = 9;
  printf("PLAYER %d\n", player_number);
  do
  {
    printf("Enter a choice of column: ");
    scanf("%d", &col_choice);
  } while(col_choice < 1 || col_choice > 7 || !check_col(board, col_choice));

  //Drops player one token (X)
  if (player_number == PLAYER_ONE)
  {
    for (int i=6; i>=1; i--)//-1
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
    for (int i=6; i>=1; i--)//-1
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
