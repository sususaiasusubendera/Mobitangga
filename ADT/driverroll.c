#include "roll.h"
#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int buff, roll, maxRoll;
	buff = 3;
	maxRoll = 10;
	roll = rollDadu(buffRoll, maxRoll);
	printf("Kamu mendapatkan angka %d\n", roll);
	return 0;
}
