#ifndef player_H
#define player_H

#include "../boolean.h"
#include "listdp.h"

typedef struct {
    char Nama[100];
    int CPosition;
    List Skill;
    List Buff;
} Player;

typedef struct {
    Player TI[5];
    int Neff;
} TabPlayer;

void MakePlayer (Player *P);
//membuat player baru

void MakeTabPlayer (TabPlayer *TPlayer, int neff);

#endif
