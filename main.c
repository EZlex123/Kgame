#include "k.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	struct game game = {
    .board = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    },
    .score = 0
};

	add_random_tile(&game);
	print_board(game);
	while (!is_game_won(game)){
		if(is_game_won(game) == 1){
			printf("YOU WON");
			return 0;
		} else {
			printf("enter dy (-1(up), 0(none), 1(down)) , enter dx (-1(left), 0(none), 1(right)): ");
			int dy;
			scanf("%d", &dy);
			int dx;
			scanf("%d", &dx);
			if(is_move_possible(game) == 1){
				if(update(&game, dy, dx) == 1){
					add_random_tile(&game);
					print_board(game);
				} else{
					printf("INCORRECT INPUT\n");
				}
			} else {
				printf("YOU LOSE\n");
				return 0;
			}
		}
	}

return 0;
}