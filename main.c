#include "k.h"
#include "hof.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
			struct player list[10];
			int size = load(list);
			struct player player;
			printf("Enter your name: ");
			char name[100];
			fgets(name, 100, stdin);
			while(true){
				int i = 0;
				if (name[i] == '\n'){
					name[i] = '\0';
					break;
				}
				i++;
			}
			player.score = game.score;
			strcpy(player.name, name);
			add_player(list, &size, player);
			save(list, size);
			return 0;
		} else {
			printf("enter UP(1) DOWN(2) LEFT(3) RIGHT(4) QUIT(q): ");
			char rot;
			scanf("%c", &rot);
			int dy;
			int dx;
			
			if(rot == '1'){
				dy = -1;
				dx = 0;
			} else if(rot == '2'){
				dy = 1;
				dx = 0;
			} else if(rot == '3'){
				dy = 0;
				dx = -1;
			}else if(rot == '4'){
				dy = 0;
				dx = 1;
			} else if (rot == 'q'){
				printf("adding to hof\n");
				struct player list[10];
				int size = load(list);
				struct player player;
				printf("Enter your name: ");
				char name[100];
				fgets(name, 100, stdin);
				while(true){
					int i = 0;
					if (name[i] == '\n'){
						name[i] = '\0';
						break;
					}
					i++;
				}
				player.score = game.score;
				strcpy(player.name, name);
				add_player(list, &size, player);
				save(list, size);
			}

			if(is_move_possible(game)){
				if(update(&game, dy, dx)){
					int flag = 0;
					for (int i = 0; i < 4; i++){
						for (int j = 0; j < 4; j++){
							if(game.board[i][j] == ' '){
								flag = 1;
							}
						}
					}
					if (flag == 1){
						add_random_tile(&game);
						flag = 0;
					}
					// add_random_tile(&game);
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