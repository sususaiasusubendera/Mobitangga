#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
   while (CC == BLANK) {
       ADV();
   }
}

void SalinKata(){
    //KAMUS//
    int i;
    //ALGORITMA//
    i = 0;
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
}

void STARTKATA(int type){
    START(type);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = 1;
    } else {
        EndKata = 0;
        SalinKata();
        IgnoreBlank();
    }
}

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = 1;
    } else {
        SalinKata();
        IgnoreBlank();
    }
}

void PrintKata(Kata kata){
    for(int i = 0; i <= kata.Length; i++){
        printf("%c", kata.TabKata[i]);
    }
    printf("\n");
}
