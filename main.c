#include "connect4_functions.h"
#include "connect4_functions.c"

int main(void)
{
  int p1_last_row = 1, p1_last_col = 1, p1_move_counter = 0;
  int p2_last_row = 1, p2_last_col = 1, p2_move_counter = 0;
  Cell board[7][8];
  init_board(board);

  while (!is_full(board))
  {
    print_board(board);
    play_turn(board, PLAYER_ONE, &p1_last_row, &p1_last_col);
    p1_move_counter++;
    if (check_win(board, PLAYER_ONE, p1_last_row, p1_last_col))
    {
      system("clear");
      printf("PLAYER 1 WINS!!!\n");
      printf("It took %d moves\n", p1_move_counter);
      break;
    }

    play_turn(board, PLAYER_TWO, &p2_last_row, &p2_last_col);
    p2_move_counter++;
    if (check_win(board, PLAYER_TWO, p2_last_row, p2_last_col))
    {
      system("clear");
      printf("PLAYER 2 WINS!!!\n");
      printf("It took %d moves\n", p2_move_counter);
      break;
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    system("clear");
  }

  return 0;
}
