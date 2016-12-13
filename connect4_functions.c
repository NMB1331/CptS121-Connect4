#include "connect4_functions.h"

//Function that prints the game rules
void print_game_rules(void)
{
  //Prints the directions to the screen
  printf("Welcome to Connect Four!\n");
  printf("This is a simple game, so...yay\n");
  printf("All you gotta do is pick column to drop a token in and the game will\n");
  printf("simulate it falling to the bottom of the board.\n");
  printf("You just need to get four pieces in a row vertically, horizontally, or\n");
  printf("diagonally before your opponent does. \n\nLike I said. Simple.\n\n");
  printf("Have no friends? Not a problem! You have the option to play with a bud,\n");
  printf("or play against the...genius AI.\n");
  printf("Okay, the AI isn't a genius. It's more like a UW grad...which, suffice\n");
  printf("to say, is not very smart. But hey, it's not my fault you're all alone.\n");
  printf("Okay! Bullshitting complete. Lets play the game!\n");

  //Clears the screen
  system( "read -n 1 -s -p \"Press any key to continue...\"" );
  system("clear");
}

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
  puts("1 2 3 4 5 6 7");
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

//Function that prompts the user for how many players
int friend_or_AI(void)
{
  char answer[20];
  do
  {
    //system("clear");
    printf("Want to play with a friend, or a digital Husky?\n");
    printf("Enter 'friend' for a buddy, or  'computer' for the Husky: ");
    scanf("%s", answer); //I was having problems with fgets...alas, no time to debug
    printf("ANSWER: %s\n", answer);
    printf("STRCMP 'computer': %d\n", strcmp(answer, "computer"));
    printf("STRCMP 'friend': %d\n", strcmp(answer, "computer"));

  } while((strcmp(answer, "friend") != 0 )&& (strcmp(answer, "computer") != 0));
  if (strcmp("computer", answer) == 0)
  {
    printf("Ah, the Husky! Good luck...\n");
    return PLAYER_THREE;
  }
  else
  {
    printf("A friend! Excellent! Good luck...\n");
    return PLAYER_TWO;
  }
}

//Function that determines if a column is available
//Returns 1 for open, 0 for full
int check_col(Cell board[][8], int column)
{
  if (column > 7 || column < 1) //Ensures choice is on the board
  {
    return 0;
  }

  for (int i=7; i>=1; i--) //Makes sure there's a space open
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
void play_turn(Cell board[][8], int player_number, int *row, int *col)
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
        *row = i;
        *col = col_choice;
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
        *row = i;
        *col = col_choice;
        board[i][col_choice].token = 'O';
        break;
      }

    }

  }
  print_board(board);
}

//Function that plays a turn for the computer
void play_computer_turn(Cell board[][8], int player_number, int *row, int *col)
{
  int comp_col = 0;
  //Randomly selects a column
  do
  {
    comp_col = rand() % 8 + 1;
  } while(!check_col(board, comp_col));
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

//Function that checks if coordinates are on the board
//Returns 1 if on the board, 0 otherwise
int is_on_board(int row, int col)
{
  if (row <= 0 || row >= 7 || col <= 0 || col >= 8)
  {
    //printf("OFF\n");
    return 0;
  }
  else
  {
    //printf("ON\n");
    return 1;
  }
}

//Function that checks for a win diagonally
//Returns 1 if  P1 win, 2 if P2 win, 0 otherwise
int check_diagonal_win(Cell board[][8], int player_number, int row, int col)
{
  //Scores player 1 diagonals
  int r = row, c = col, counter = 0;

  //Checks up and right
  while(is_on_board(r-1, c+1))
  {
    r -= 1;
    c += 1;
    if (player_number == PLAYER_ONE)
    {
      if (board[r][c].token == 'X')
      {
        counter += 1;
      }
    }
    else if (player_number == PLAYER_TWO)
    {
      if (board[r][c].token == 'O')
      {
        counter += 1;
      }
    }
    //printf("UR Row: %d Col: %d\n", r, c);
  }
  //printf("UR counter: %d\n", counter);

  //Checks down and left
  r = row;
  c = col;
  while(is_on_board(r+1, c-1))
  {
    r += 1;
    c -= 1;
    if (player_number == PLAYER_ONE)
    {
      if (board[r][c].token == 'X')
      {
        counter += 1;
      }
    }
    else if (player_number == PLAYER_TWO)
    {
      if (board[r][c].token == 'O')
      {
        counter += 1;
      }
    }
    //printf("DL Row: %d Col: %d\n", r, c);
  }
  //printf("DL counter: %d\n", counter);
  if (counter >= 3)
  {
    return 1;
  }

  //Checks down and right
  r = row;
  c = col;
  counter = 0;
  while(is_on_board(r+1, c+1))
  {
    r += 1;
    c += 1;
    if (player_number == PLAYER_ONE)
    {
      if (board[r][c].token == 'X')
      {
        counter += 1;
      }
    }
    else if (player_number == PLAYER_TWO)
    {
      if (board[r][c].token == 'O')
      {
        counter += 1;
      }
    }
    //printf("DR Row: %d Col: %d\n", r, c);
  }
  //printf("DR counter: %d\n", counter);

  //Checks up and left
  r = row;
  c = col;
  while(is_on_board(r-1, c-1))
  {
    r -= 1;
    c -= 1;
    if (player_number == PLAYER_ONE)
    {
      if (board[r][c].token == 'X')
      {
        counter += 1;
      }
    }
    else if (player_number == PLAYER_TWO)
    {
      if (board[r][c].token == 'O')
      {
        counter += 1;
      }
    }
    //printf("UL Row: %d Col: %d\n", r, c);
  }
  //printf("UL counter: %d\n", counter);

  if (counter >= 3)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Function that checks for horizontal win
//Returns 1 if  P1 win, 2 if P2 win, 0 otherwise
int check_vertical_win(Cell board[][8], int player_number, int col)
{
  int counter = 0;
  for (int i=1; i<7; i++)
  {
    //Checks the row of the last move for player 1
    if (player_number == PLAYER_ONE)
    {
      if (board[i][col].token == 'X') //Counts num X's in a row (vertically)
      {
        counter += 1;
      }
      else                            //Zeroes out if not X
      {
        counter = 0;
      }
    }
    //Checks the row of the last move for player 1
    if (player_number == PLAYER_TWO)
    {
      if (board[i][col].token == 'O') //Counts num O's in a row (vertically)
      {
        counter += 1;
      }
      else                            ////Zeroes out if not O
      {
        counter = 0;
      }
    }

  }
  if (counter >= 4)
  {
    return player_number;
  }
  else
  {
    return 0;
  }
}

//Function that checks for vertical win
//Returns 1 if  P1 win, 2 if P2 win, 0 otherwise
int check_horiz_win(Cell board[][8], int player_number, int row)
{
  int counter = 0;
  for (int i=1; i<8; i++)
  {
    //Checks the column of the last move for player 1
    if (player_number == PLAYER_ONE)
    {
      if (counter == 4)
      {
        break;
      }
      if (board[row][i].token == 'X') //Counts num X's in a row (horizontally)
      {
        counter += 1;
      }
      else                            //Zeroes out if O
      {
        counter = 0;
      }
    }
    //Checks the column of the last move for player 1
    if (player_number == PLAYER_TWO)
    {
      if (counter == 4)
      {
        break;
      }
      if (board[row][i].token == 'O') //Counts num O's in a row (horizontally)
      {
        counter += 1;
      }
      else                            //Zeroes out if X
      {
        counter = 0;
      }
    }
  }
  if (counter >= 3)
  {
    return player_number;
  }
  else
  {
    return 0;
  }
}

//Function that checks for a win
//Returns 1 if P1 wins, 2 if P2 wins, 0 otherwise
int check_win(Cell board[][8], int player_number, int row, int col)
{
  if (check_diagonal_win(board, player_number, row, col) || check_horiz_win(board, player_number, row) || check_vertical_win(board, player_number, col))
  {
    return player_number;
  }
  else
  {
    return 0;
  }
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
