/* implementasi dari map.h */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"


/* ***** KONSTRUKTOR UNTUK MAP ***** */
/* Konstruktor : create peta kosong */
void MakeEmptyMap (Map *M)
{
    /* Kamus Lokal */

    /* Algoritma */
    (*M).Neff = 0;
}


/* ***** TES PETA KOSONG ***** */
boolean IsEmptyMap (Map M)
{
    /* Kamus Lokal */

    /* Algoritma */
    return (M.Neff = 0);
}


/* ***** PROSES SEMUA ELEMEN ARRAY MAP ***** */
void SalinMap (Map Mx, Map My)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    MakeEmptyMap(&My);
    for (i = 0; i<= Length(Mx); i++) {
        My.contents[i] = Mx.contents[i];
    }
}


void ShowMap (Map M)
{
    /* Kamus Lokal */
    int i;

    /* Algoritma */
    for (i = 0; i <= Length(M); i++) {
        printf("%d", M.contents[i]);
    }
}

