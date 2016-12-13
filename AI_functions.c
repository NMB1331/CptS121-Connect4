/*
NATHANIEL BURLEY
WASHINGTON STATE UNIVERSITY
COMPUTER SCIENCE 121
*/

#include "AI_functions.h"

//Function that checks for three X's in a row vertically
//Returns the column if three in a row, 0 otherwise
int three_in_row_vert(Cell board[][8])
{
  for (int col=1; col<8; col++)
  {
    int counter = 0;
    for (int row=6; row>0; row--)
    {
      if (counter == 2)
      {
        if (board[row][col].token == 'O')
        {
          counter = 0;
        }
        else if (board[row][col].token == '_')
        {
          //printf("Blocking 4 in a row vertically!\n");
          return col;
        }
        else
        {
          //printf("3 in a row, but spot above not open\n");
          return 0;
        }
      }
      else if (board[row][col].token == 'X')
      {
        counter += 1;
      }
    }
    //printf("COUNTER: %d\n",counter);
  }
  return 0;
}

//Function that checks for three X's in a row horizontally
//Returns the column open if three in a row with space open, 0 otherwise
int three_in_row_horiz(Cell board[][8])
{
  //Checks...going right?
  for (int row=6; row>0; row--)
  {
    int counter = 0;
    for (int col=1; col<8; col++)
    {
      if (counter == 2)
      {
        if (board[row][col].token == 'O')
        {
          counter = 0;
        }
        else if (board[row][col].token == '_')
        {
          //printf("Blocking 4 in a row horizontally right!\n");
          return col;
        }
        else
        {
          //printf("3 in a row, but spot right not open\n");
          return 0;
        }
      }
      else if (board[row][col].token == 'X')
      {
        counter += 1;
      }
    }
    //printf("COUNTER: %d\n",counter);

  }

  //Checks going left
  for (int row=6; row>0; row--)
  {
    int counter = 0;
    for (int col=7; col>0; col--)
    {
      if (counter == 2)
      {
        if (board[row][col].token == 'O')
        {
          counter = 0;
        }
        else if (board[row][col].token == '_')
        {
          //printf("Blocking 4 in a row horizontally left!\n");
          return col;
        }
        else
        {
          //printf("3 in a row, but spot left not open\n");
          return 0;
        }
      }
      else if (board[row][col].token == 'X')
      {
        counter += 1;
      }
    }
    //printf("COUNTER: %d\n",counter);

  }
  return 0;
}

//Function that plays a turn for the computer
void play_computer_turn(Cell board[][8], int player_number, int *row, int *col)
{
  int comp_col = 0;
  //Randomly selects a column
  if (three_in_row_vert(board))
  {
    printf("Blocking you vertically!\n");
    comp_col = three_in_row_vert(board);
  }
  else if (three_in_row_horiz(board))
  {
    printf("Blocking you horizontally!\n");
    comp_col = three_in_row_horiz(board);
  }
  else
  {
    do
    {
      comp_col = rand() % 8 + 1;
    } while(!check_col(board, comp_col));
  }
  printf("COMPUTER CHOOSES %d\n", comp_col);

  //Simulates token drop on board
  for (int i=6; i>=1; i--)//-1
  {
    if (board[i][comp_col].token == '_')
    {
      *row = i;
      *col = comp_col;
      board[i][comp_col].token = 'O';
      break;
    }
  }
  print_board(board);
}
