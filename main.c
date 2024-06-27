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
			printf("enter UP(1) DOWN(2) LEFT(3) RIGHT(4): ");
			int rot;
			scanf("%d", &rot);
			int dy;
			int dx;
			
			if(rot == 1){
				dy = -1;
				dx = 0;
			} else if(rot == 2){
				dy = 1;
				dx = 0;
			} else if(rot == 3){
				dy = 0;
				dx = -1;
			}else if(rot == 4){
				dy = 0;
				dx = 1;
			}

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