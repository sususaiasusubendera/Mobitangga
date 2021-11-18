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
	int MaxRoll, MinRoll, Roll;
	MaxRoll = 10;
	MinRoll = 1;
	if (buff == 3){
		MaxRoll *= 2;
		MinRoll *= 10;
	}
	else if (buff == 4){
		MaxRoll /= 2;
	}
	srand(time(0));
	Roll = (rand() % (MaxRoll - MinRoll + 1)) + MinRoll;
	return Roll;
}
