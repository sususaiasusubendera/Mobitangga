#include "player.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void createEmptyListPlayer(Player *P)
{
    (*P).Neff = 0;
}

void addPlayer(Player *P, int n){
	int i;
    for (i = 1; i <= n; i++){
        printf("Masukkan Nama: ");
        gets((*P).uName[i]);
        printf("Selamat Datang di Game MobiTangga ");
        printf("%s\n", ((*P).uName[i]));
        printf("Kamu adalah player ");
        printf("%d\n", i);
        (*P).isTelep[i] = false;
        (*P).pos[i] = 1;
        (*P).isImmu[i] = false;
        (*P).is
        (*P).Skills[i] = Nil;
    }
    (*P).Neff = n;
}

int getPlayerIdx(Player P, char *nameSearch){
    int i = IdxMin;
    int idxP = IdxUndef;
    while (i <= IdxMax)
    {
        if (strcmp(nameSearch, P.uName[i]) != 0)
        {
            i++;
        }
        else
        {
            idxP = i;
            break;
        }
    }
    return idxP;
}

boolean isPlayerTeleported(Player P, char *uName){
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.isTelep[idx]);
    }
}

boolean isPlayerImmune(Player P, char *uName){
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.isImmu[idx]);
    }
}

int getPlayerPosition(Player P, char *uName){
    int idx = getPlayerIdx(P, uName);
    if (idx != IdxUndef)
    {
        return (P.pos[idx]);
    }
}
