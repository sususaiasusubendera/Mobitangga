#include "player.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
	TabPlayer gaming;
	int n, i;
	scanf("%d", &n);
	MakeTabPlayer(&gaming, n);
	for (i = 1; i < n ; i++){
		printf("Player %d adalah %s\n", n, gaming.TI[i].Nama);
	}
	return 0;
}

