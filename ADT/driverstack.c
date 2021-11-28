/* Driver Stack */
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main(){
    Stack S;
    TabPlayer playerstate[MaxEl+1];
    Player TI[5];
    int Neff;
    char Nama[100];
    int CPosition;
    List Skill;

    CreateStack (&S);

    printf("Apakah Stack kosong? \n");
    if(IsStackEmpty(S)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    printf("Apakah Stack penuh? \n");
    if(IsStackFull(S)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    round(S) = 1;

    (S).playerstate[1].TI[1].CPosition = 5; //input posisi

    Push(&S, playerstate[1]);

    round(S) += 1;

    (S).playerstate[2].TI[1].CPosition = 9; //input posisi kedua

    Push(&S, playerstate[2]);
    Pop(&S, &playerstate);

    printf("Posisi saat ini:\n");
    printf ("%d", (S).playerstate[2].TI[1].CPosition);

    Pop(&S, &playerstate);

    printf("\nPosisi saat ini lagi:\n");
    printf ("%d", (S).playerstate[1].TI[1].CPosition);

    return 0;
}

