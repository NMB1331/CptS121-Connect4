#include "connect4_functions.h"
#include "connect4_functions.c"

int main(void)
{
  Cell board[7][8];
  init_board(board);
  print_board(board);
  while (!is_full(board))
  {
    play_turn(board, PLAYER_ONE);
    play_turn(board, PLAYER_TWO);
  }

  return 0;
}
