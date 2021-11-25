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
void Push(Stack * S, TabPlayer P){
    round(*S)=round(*S)+1;
    (*S).playerstate[(*S).round] = P;
    for (int i = 1; i <= (P).Neff; i++) {
        (*S).playerstate[(*S).round].TI[i].Skill.First = Nil ;
        (*S).playerstate[(*S).round].TI[i].Skill.Last = Nil ;
        copySkill(P.TI[i].Skill, &(*S).playerstate[(*S).round].TI[i].Skill) ;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, TabPlayer * P){
    *P = (*S).playerstate[(*S).round];
    round(*S)=round(*S)-1;
}
