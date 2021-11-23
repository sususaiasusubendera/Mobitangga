#include "player.h"
#include <stdio.h>

void MakePlayer (Player *P){
	printf("\nMasukkan nama player: ");
    scanf("%s", (*P).Nama);
    printf("\nSelamat Datang di Game MobiTangga ");
    printf("%s\n", ((*P).Nama));
    (*P).CPosition = 1;
    CreateEmpty(&((*P).Skill));
};

void MakeTabPlayer (TabPlayer *TPlayer, int neff){
    int j;
    (*TPlayer).Neff = neff;
    for (j = 1; j <= neff; j++){
        MakePlayer(&((*TPlayer).TI[j]));
        printf("Kamu adalah player ");
        printf("%d\n", j);
    }
}
