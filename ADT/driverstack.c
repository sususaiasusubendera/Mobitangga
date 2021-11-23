#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack s;
    int positionA, positionB, skillA, skillB;

    NewGame (&s);

    printf("Apakah Stack kosong? \n");
    if(IsNewGame(s)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    printf("Apakah Stack penuh? \n");
    if(IsEndGame(s)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    /* Mencoba mengisi stack dengan 2 round */

    AddRound (&s, 3, 5, 1, 1);
    AddRound (&s, 6, 7, 2, 2);
    AddRound (&s, 9, 11, 3, 2);
    UndoRound(&s, &positionA, &positionB, &skillA, &skillB );

    printf("Setelah undo, posisi para player menjadi : \n");
    printf("Posisi Player 1: %d\n", positionA);
    printf("Posisi Player 2: %d\n", positionB);
    printf("Skill Player 1: %d\n", skillA);
    printf("Skill Player 2: %d\n", skillB);

    UndoRound(&s, &positionA, &positionB, &skillA, &skillB );

    printf("Setelah undo, posisi para player menjadi : \n");
    printf("Posisi Player 1: %d\n", positionA);
    printf("Posisi Player 2: %d\n", positionB);
    printf("Skill Player 1: %d\n", skillA);
    printf("Skill Player 2: %d\n", skillB);

    return 0;
}