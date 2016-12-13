#include "connect4_functions.h"
#include "connect4_functions.c"

/*NOTES
-add number guess to determine who is player 1 (get names)
-add an option for single player (either random...or some AI?)
-possibly at some stats?
-clean up comments, remove "magic numbers"
*/

int main(void)
{
  int p1_last_row = 1, p1_last_col = 1, p1_move_counter = 0;
  int p2_last_row = 1, p2_last_col = 1, p2_move_counter = 0;
  Cell board[7][8];
  FILE *game_log = NULL;

  game_log = fopen("game_log.txt", "w");
  init_board(board);

  //Main body of the game
  print_game_rules();
  while (!is_full(board))
  {
    print_board(board);
    play_turn(board, PLAYER_ONE, &p1_last_row, &p1_last_col);
    p1_move_counter++;
    //Writes move to the game log
    fprintf(game_log, "Player 1 Move %d: (%d,%d)\n", p1_move_counter, p1_last_row, p1_last_col);
    if (check_win(board, PLAYER_ONE, p1_last_row, p1_last_col))
    {
      printf("PLAYER 1 WINS!!!\n");
      printf("It took %d moves\n", p1_move_counter);
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
      break;
    }

    play_turn(board, PLAYER_TWO, &p2_last_row, &p2_last_col);
    p2_move_counter++;
    //Writes move to the game log
    fprintf(game_log, "Player 2 Move %d: (%d,%d)\n", p2_move_counter, p2_last_row, p2_last_col);
    if (check_win(board, PLAYER_TWO, p2_last_row, p2_last_col))
    {
      printf("PLAYER 2 WINS!!!\n");
      printf("It took %d moves\n", p2_move_counter);
      system( "read -n 1 -s -p \"Press any key to continue...\"" );
      system("clear");
      break;
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    system("clear");
  }


  fclose(game_log);
  return 0;
}
