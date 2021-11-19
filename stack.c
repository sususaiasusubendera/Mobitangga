/* File : stack.c */
/* Impelemntasi fungsi dari stack.h */

#include "boolean.h"
#include "stack.h"
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void NewGame (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : round bernilai Nil */
    round(*S) = Nil;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsNewGame (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return round(S) == Nil;
}

boolean IsEndGame (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return round(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void AddRound (Stack * S, infotype X, infotype Y){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X dan Y menjadi p1position dan p2position yang baru, round bertambah 1 */
    round(*S)=round(*S)+1;
    p1position(*S)=X;
    p2position(*S)=X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void UndoRound (Stack * S, infotype* X, infotype* Y){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X dan Y adalah nilai elemen p1position dan p2position yang lama, round berkurang 1 */
    *X = p1position(*S);
    *Y = p2position(*S);
    round(*S)=round(*S)-1;
}