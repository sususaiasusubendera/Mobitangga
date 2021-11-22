#include "player.h"
#include <stdio.h>

void MakePlayer (Player *P){
	printf("Masukkan nama player: ");
    gets((*P).Nama);
    printf("Selamat Datang di Game MobiTangga ");
    printf("%s\n", ((*P).Nama));
    (*P).CPosition = 1;
    CreateEmpty(&((*P).Buff));
    CreateEmpty(&((*P).Skill));
};

void MakeTabPlayer (TabPlayer *TPlayer, int neff){
    int i;
    (*TPlayer).Neff = neff;
    for (i = 1; i <= neff; i++){
        MakePlayer(&((*TPlayer).TI[i]));
        printf("Kamu adalah player ");
        printf("%d\n", i);
    }
}
