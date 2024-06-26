#include <stdlib.h>
#include <stdio.h>
#include "k.h"

// void add_random_tile(struct game *game){
//     int row, col;
//     // find random, but empty tile
//     do{
//         row = rand() % SIZE;
//         col = rand() % SIZE;
//     }while(game->board[row][col] != ' ');

//     // place to the random position 'A' or 'B' tile
//     if(rand() % 2 == 0){
//         game->board[row][col] = 'A';
//     }else{
//         game->board[row][col] = 'B';
//     }
// }


// bool is_game_won(const struct game game){
//     for (int i = 0; i < SIZE; i++){
//         for(int j = 0; j < SIZE; j++){
//             if (game.board[i][j] == 'K'){
//                 return true;
//             } 
//         }
//     }
//     return false;
// }

// bool is_move_possible(const struct game game){

//     for (int i = 0; i < SIZE - 1; i++){
//         for (int j = 0; j < SIZE - 1; j++){

//             if(game.board[i][j] == game.board[i][j + 1] || game.board[i][j] == game.board[i + 1][j]){
//                 return true;
//             }

//             if(game.board[i][j] == ' '){
//                 return true;
//             }
//         }
//     }
//     return false;
// }


bool update(struct game *game, int dy, int dx){

    if(dx == 0){

    if (dy == 1){ //vverx

    } else if (dy == -1){ // vniz

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
