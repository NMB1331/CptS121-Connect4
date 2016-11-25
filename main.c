#include "connect4_functions.h"
#include "connect4_functions.c"

int main(void)
{
  //Variables declared
  char board[6][7];

  //Functions being tested
  init_board(board);
  print_board(board);

  return 0;
}
