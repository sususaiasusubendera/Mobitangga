#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;
char filename [100];

void START(int type){
    if (type == 1){
    /* Baca dari file */
        pita = fopen(filename, "r");
    } else {
    /* Baca dari input-an */
        pita = stdin;
    }
    ADV();
}

void ADV(){
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}
