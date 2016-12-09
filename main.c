#include "connect4_functions.h"
#include "connect4_functions.c"

int main(void)
{
  Cell board[BOARD_COLS][BOARD_ROWS];
  init_board(board);
  print_board(board);
  play_turn(board, PLAYER_ONE);
  play_turn(board, PLAYER_TWO);
  play_turn(board, PLAYER_ONE);
  play_turn(board, PLAYER_TWO);
  play_turn(board, PLAYER_ONE);
  play_turn(board, PLAYER_TWO);
  play_turn(board, PLAYER_ONE);
  play_turn(board, PLAYER_TWO);
}
