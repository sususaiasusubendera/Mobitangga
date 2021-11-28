#ifndef __MAP_H__
#define __MAP_H__

#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

typedef struct {
    int Alamat;
    char IsiPetak;
    int Teleporter;
} Petak;

typedef struct {
    int PanjangMap;
    int MaxRoll;
    int JumlahTeleporter;
    Petak TabMap[100 + 1];
} Map;

int ArrayOfCharToInt (Kata CKata, int *result);

void KonfigurasiToMap (Map *Map, char* locate);

void SalinMap (Map *Mx, Map *My);

#endif
