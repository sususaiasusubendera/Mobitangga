/*
buff = 1 -> Pintu Ga Ke Mana Mana
buff = 2 -> Cermin Pengganda
buff = 3 -> Senter Pembesar Hoki
buff = 4 -> Senter Pengecil Hoki
buff = 5 -> Mesin Penukar Posisi
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int rollDadu(int buff){
	int MaxRoll, MinRoll, Roll, i, result;
	MaxRoll = 10;
	MinRoll = 1;
	if (buff == 3){
		MinRoll = floor(MaxRoll/2) ;
	}
	else if (buff == 4){
		MaxRoll = floor(MaxRoll/2);
	}
	srand((unsigned)time(0));
	for (i = 1; i < 2*MaxRoll; i++){
		Roll = (rand() % (MaxRoll - MinRoll + 1)) + MinRoll;
	}
	result = ((result + Roll) % ((MaxRoll - MinRoll + 1)) + MinRoll);
	return result;
}

int main(){
	int buff, roll, i;
	buff = 4;
	for (i = 0; i < 5; i++){
		roll = rollDadu(buff);
		printf("%d\n", roll);
	}
}
