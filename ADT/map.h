
#include "boolean.h"

#ifndef MAP_H
#define MAP_H


/* Panjang maksimum peta Mobitangga */
#define Max_Length 100

typedef char ElTypeMap;
typedef struck {
    ElTypeMap contents [Max_Length];
    int Neff;
} Map;

/* Selektor Map */
#define Lenght(M) (M).Neff

/* ***** KONSTRUKTOR UNTUK MAP ***** */
/* Konstruktor : create peta kosong */
void MakeEmptyMap (Map *M);
/* I.S. terdapat nilai n yang valid sebagai memori dari Map */
/* F.S. terbentuk sebuah array Map M dengan ukuran Neff = 0 */


/* ***** TES PETA KOSONG ***** */
boolean IsEmptyMap (Map M);
/* Mengirimkan true jika Map kosong */

/* ***** PROSES SEMUA ELEMEN ARRAY MAP ***** */
void SalinMap (Map Mx, Map My);
/* I.S. array Map Mx terdefisini */
/* F.S. array Map My berisikan elemen yang sama persis dengan Map Mx */


void ShowMap (Map M);
/* I.S. sebuah array Map M terdefinisi */
/* F.S. menuliskan elemen array Map M ke layar */


#endif // MAP_H
