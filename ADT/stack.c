/* File : stack.c */
/* Impelemntasi fungsi dari stack.h */

#include "../boolean.h"
#include "stack.h"
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateStack (Stack *S){
    round(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty (Stack S){
    return round(S) == Nill;
}

boolean IsStackFull (Stack S){
    return round(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, TabPlayer playerstate){
    round(*S)=round(*S)+1;
    (*S).playerstate = playerstate;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, TabPlayer* playerstate){
    *playerstate = (*S).playerstate;
    round(*S)=round(*S)-1;
}
