#include <stdlib.h>
#include <stdio.h>
#include "k.h"

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}


bool is_game_won(const struct game game){
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if (game.board[i][j] == 'K'){
                return true;
            } 
        }
    }
    return false;
}

bool is_move_possible(const struct game game){

    for (int i = 0; i < SIZE - 1; i++){
        for (int j = 0; j < SIZE - 1; j++){

            if(game.board[i][j] == game.board[i][j + 1] || game.board[i][j] == game.board[i + 1][j]){
                return true;
            }

            if(game.board[i][j] == ' '){
                return true;
            }
        }
    }
    return false;
}


bool update(struct game *game, int dy, int dx){

    if(dx == 0){

    if (dy == 1){ //vniz

        for(int j = 0; j < SIZE; j++){
            for (int i = SIZE - 1; i >= 0; i--){
                int intI = i;
                while (intI < SIZE-1){
                    if (intI != SIZE - 1){
                        if (game->board[intI+1][j] == ' '){
                            game->board[intI+1][j] = game->board[intI][j];
                            game->board[intI][j] = ' ';
                        }
                    }
                    intI++;
                }
            }

            int intI = SIZE-1;
            while (intI >= 0){
                if(intI != SIZE - 1){
                    if(game->board[intI][j] != ' '){
                        if (game->board[intI][j] == game->board[intI+1][j]){
                            game->board[intI+1][j]++;
                            game->board[intI][j] = ' ';
                        }
                    }
                }
                intI--;
            }
            for (int i = SIZE - 1; i >= 0; i--){
                int intI = i;
                while (intI < SIZE-1){
                    if (intI != SIZE - 1){
                        if (game->board[intI+1][j] == ' '){
                            game->board[intI+1][j] = game->board[intI][j];
                            game->board[intI][j] = ' ';
                        }
                    }
                    intI++;
                }
            }
        }
        return true;
    } else if (dy == -1){ // vverx
        for(int j = 0; j < SIZE; j++){
                for (int i = 0; i < SIZE; i++){
                    int intI = i;
                    while (intI > 0){
                        if (intI != 0){
                            if (game->board[intI-1][j] == ' '){
                                game->board[intI-1][j] = game->board[intI][j];
                                game->board[intI][j] = ' ';
                            }
                        }
                        intI--;
                    }
                }
                int intI = 0;
                while (intI < SIZE - 1){
                    if(intI != 0){
                        if(game->board[intI][j] != ' '){
                            if (game->board[intI][j] == game->board[intI-1][j]){
                                game->board[intI-1][j]++;
                                game->board[intI][j] = ' ';
                            }
                        }
                    }
                    intI++;
                }
                for (int i = 0; i < SIZE; i++){
                    int intI = i;
                    while (intI > 0){
                        if (intI != 0){
                            if (game->board[intI-1][j] == ' '){
                                game->board[intI-1][j] = game->board[intI][j];
                                game->board[intI][j] = ' ';
                            }
                        }
                        intI--;
                    }
                }
            }
            return true;
        }
    }

    if(dy == 0){
        if(dx == 1){  //vpravo
            for(int i = 0; i < SIZE; i++){
                for (int j = SIZE - 1; j >= 0; j--){
                    int intJ = j;
                    while (intJ < SIZE-1){
                        if (intJ != SIZE - 1){
                            if (game->board[i][intJ+1] == ' '){
                                game->board[i][intJ+1] = game->board[i][intJ];
                                game->board[i][intJ] = ' ';
                            }
                        }
                        intJ++;
                    }
                }
                int intJ = SIZE-1;
                while (intJ >= 0){
                    if(intJ != SIZE - 1){
                        if(game->board[i][intJ] != ' '){
                            if (game->board[i][intJ] == game->board[i][intJ+1]){
                                game->board[i][intJ+1]++;
                                game->board[i][intJ] = ' ';
                            }
                        }
                    }
                    intJ--;
                }
                for (int j = SIZE - 1; j >= 0; j--){
                    int intJ = j;
                    while (intJ < SIZE-1){
                        if (intJ != SIZE - 1){
                            if (game->board[i][intJ+1] == ' '){
                                game->board[i][intJ+1] = game->board[i][intJ];
                                game->board[i][intJ] = ' ';
                            }
                        }
                        intJ++;
                    }
                }
            }
            return true;

            
        } else if (dx == -1){ //vlevo
            for(int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++){
                    int intJ = j;
                    while (intJ > 0){
                        if (intJ != 0){
                            if (game->board[i][intJ-1] == ' '){
                                game->board[i][intJ-1] = game->board[i][intJ];
                                game->board[i][intJ] = ' ';
                            }
                        }
                        intJ--;
                    }
                }
                int intJ = 0;
                while (intJ < SIZE - 1){
                    if(intJ != 0){
                        if(game->board[i][intJ] != ' '){
                            if (game->board[i][intJ] == game->board[i][intJ-1]){
                                game->board[i][intJ-1]++;
                                game->board[i][intJ] = ' ';
                            }
                        }
                    }
                    intJ++;
                }
                for (int j = 0; j < SIZE; j++){
                    int intJ = j;
                    while (intJ > 0){
                        if (intJ != 0){
                            if (game->board[i][intJ-1] == ' '){
                                game->board[i][intJ-1] = game->board[i][intJ];
                                game->board[i][intJ] = ' ';
                            }
                        }
                        intJ--;
                    }
                }
            }
            return true;
        }
    }

    return false;
}

void print_board(struct game game){
    for (int i = 0; i < SIZE; i++){
		for(int num = 0; num < SIZE; num++){
			printf("+-------");
		}
		printf("+\n\n");
		for (int num1 = 0; num1 < SIZE; num1++){
			printf("|   %c   ", game.board[i][num1]);
		}
		printf("|");
		printf("\n\n");
	}
	for(int num = 0; num < SIZE; num++){
		printf("+-------");
	}
	printf("+\n");
}
