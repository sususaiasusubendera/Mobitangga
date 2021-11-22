#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/game_flow.h"
#include "FUNGSI/pre.h"

int main(){
	boolean endGame;
	intro();
	char command[MaxCommand];
	puts("1. NEW GAME");
	puts("2. EXIT");
	printf("Masukan command : ");
	gets(command);
	endGame = false;
	while (strcmp(command, "NEW GAME") != 0 && strcmp(command, "EXIT") != 0){
		printf("Masukan command : ");
		gets(command);
	}
	if (strcmp(command, "NEW GAME") == 0){
		while (!endGame){
			endGame = game(endGame);
		}
		puts("Terima kasih telah memainkan game ini :)\n");
	}
	else{
		puts("Terima kasih telah memainkan game ini :)\n");
	}
	return 0;
}
