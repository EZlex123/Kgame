#include "k.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	struct game game = {
    .board = {
        {'A', ' ', 'C', 'C'},
        {' ', ' ', ' ', ' '},
        {'A', 'C', 'C', 'C'},
        {' ', ' ', ' ', ' '}
    },
    .score = 0
};

	bool result = update(&game, 0, -1);

	printf("%d\n\n", result);

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			printf(" %c |", game.board[i][j]);
		}
		printf("\n");
	}


return 0;
}