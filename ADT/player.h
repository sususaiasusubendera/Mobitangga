#ifndef PLAYER_H
#define PLAYER_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

typedef int ElType;
#define IdxMax 4
#define IdxMin 1
#define IdxUndef -999
#define MaxPlayerName 35

typedef struct listSkillNode *address;
typedef struct listSkillNode
{
    char Name[25];
    int Identifier;
    /* Setiap jenis skill memiliki identifier tersendiri. */
    address next;
} Skill;

typedef address lSkill;

/* Player menggunakan array */
typedef struct
{
    int Neff;
    char uName[IdxMax - IdxMin + 1][MaxPlayerName];
    ElType pos[IdxMax - IdxMin + 1];
    boolean isTelep[IdxMax - IdxMin + 1];
    boolean isImmu[IdxMax - IdxMin + 1];
    lSkill Skills[IdxMax - IdxMin + 1];
} Player;

void createEmptyListPlayer(Player *P);
/*
 I.S. array P sembarang
 F.S. array P kosong
*/
void addPlayer(Player *P, int n);
/*
 Prosedur untuk membuat list player sebanyak n pemain
 I.S array Player.uName, Player.pos, Player.isTelep,
    Player.isImmu, Player.Skills kosong dan Neff berisi 0
 F.S array Player.uName, Player.pos, Player.isTelep, Player.isImmu, Player.Skills sebanyak n
    terisi inputan dan Neff menjadi n
*/
int getPlayerIdx(Player P, char *name);
/*
 Fungsi untuk mereturn index player dalam array uName dengan uName sebagai parameter input
 Apabila input tidak terdapat di list uName, maka akan mereturn IdxUndef
*/
boolean isPlayerTeleported(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut terkena portal atau tidak
*/
boolean isPlayerImmune(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai apakah player tersebut sedang imun atau tidak
*/
int getPlayerPosition(Player P, char *uName);
/*
 Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter
 mengenai posisi player;
*/

#endif
