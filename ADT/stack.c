/* File : stack.c */
/* Impelemntasi fungsi dari stack.h */

#include "../boolean.h"
#include "stack.h"
#include "player.h"
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateStack (Stack *S){
    round(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S){
    return round(S) == Nil;
}

boolean IsStackFull (Stack S){
    return round(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, TabPlayer P){
    round(*S)=round(*S)+1;
    playerstate(*S)= P;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, TabPlayer* P){
    *P = playerstate(*S);
    round(*S)=round(*S)-1;
}
