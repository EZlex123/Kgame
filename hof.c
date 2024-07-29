#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hof.h"

bool save(const struct player list[], const int size){
	FILE *f = fopen(HOF_FILE, "w");
	if(f == NULL){ 
		return -1;
	}
	for(int i = 0; i < size; i++){
		fprintf(f, "%s %d\n", list[i].name, list[i].score);
	}
	fclose(f);
	return 1;
}

int load(struct player list[]){
	FILE *f = fopen(HOF_FILE, "a");
	if(f == NULL){ 
		return -1;
	}
	fclose(f);
	FILE *file = fopen(HOF_FILE, "r");
	char s = fgetc(file);
	int size = 0;
	if (size < 11 || s == EOF){
		while(s != EOF){
			while(s != '\n' && s != EOF){
				char name1[30] = "";
				int score1 = 0;
				while(s != DELIMITER && s != EOF){
					if(s <= 57 && s >= 48){ //nums
						int num = s - 48;
						score1 = score1 * 10 + num;
						s = fgetc(file);
					}
					else if(s <= 122 && s >= 97){ //Lowercase
						int i = 0;
						name1[i] = s;
						i++;
						s = fgetc(file);
					}
					else if(s <= 90 && s >= 65){ //Upercase
						int i = 0;
						name1[i] = s;
						i++;
						s = fgetc(file);
					}
				}
				strcpy(list[size].name, name1);
				list[size].score = score1;
				size++;
			}
		}
	}
	return size;
}



bool add_player(struct player list[], int* size, const struct player player){
	for (int i = 0; i < *size; i++){
		for(int j = 0; j < *size; j++){
			if(list[i].score < list[j].score){
				int tmpint;
				char tmpstr[100];
				tmpint = list[j].score;
				strcpy(tmpstr, list[j].name);
				list[j].score = list[i].score;
				strcpy(list[j].name,list[i].name);
				list[i].score = tmpint;
				strcpy(list[i].name, tmpstr);
			}	
		}
	}
	int currSIZE = *(size)-1;
	if (player.score < list[currSIZE].score){
		return -1;
	} else{
		if (*size < 10) {   // if do not need to delete player (size < 10)
			int i = 0;
			while(list[i].score > player.score && i < *size){
				i++;
			}
			int j = i;
			for(int SizeTMP = *size; SizeTMP > j; SizeTMP--){
				list[SizeTMP].score = list[SizeTMP-1].score;
				strcpy(list[SizeTMP].name, list[SizeTMP-1].name);
			}
			list[j].score = player.score;
			strcpy(list[j].name, player.name);
			size++;
			return 1;
		}
		if (*size == 10){  // if need to delete player (size == 10)
			int i = 0;
			while(list[i].score > player.score && i < *size){
				i++;
			}
			int j = i;
			for(int SizeTMP = *(size)-1; SizeTMP > j; SizeTMP--){
				list[SizeTMP].score = list[SizeTMP-1].score;
				strcpy(list[SizeTMP].name, list[SizeTMP-1].name);
			}
			list[j].score = player.score;
			strcpy(list[j].name, player.name);
			return 1;
		}
	}
	return -1;
}