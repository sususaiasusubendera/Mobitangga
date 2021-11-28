#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./ADT/game_flow.h"
#include "./Fungsi/pre.h"
#include "./Fungsi/post.h"
#include "boolean.h"

void intro();

boolean game(boolean endGame);

int main(){
	boolean endGame;
	intro();
	char command[MaxCommand];
	puts("1. NEWGAME");
	puts("2. EXIT");
	printf("Masukan command : ");
	scanf("%s", command);
	endGame = false;
	while (strcmp(command, "NEWGAME") != 0 && strcmp(command, "EXIT") != 0){
		printf("Masukan command : ");
		scanf("%s", command);
	}
	if (strcmp(command, "NEWGAME") == 0){
		while (!endGame){
			endGame = game(endGame);
		}
		puts("Terima kasih telah memainkan game ini :)\n");
		outro();
	}
	else{
		puts("Terima kasih telah memainkan game ini :)\n");
		outro();
	}
	return 0;
}
