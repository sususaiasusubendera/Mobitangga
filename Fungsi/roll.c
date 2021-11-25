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
#include "roll.h"

int rollDadu(int buff, int MaxRoll){
	srand((unsigned)time(0));
	int MinRoll, Roll;
	MinRoll = 1;
	Roll = (rand() % MaxRoll) + MinRoll;
	if (buff == 3){
		MinRoll = MaxRoll/2;
		if (Roll <= MinRoll){
			Roll += MinRoll;
		}
	}
	else if (buff == 4){
		MaxRoll = MaxRoll/2;
		if (Roll > MaxRoll){
			Roll -= MaxRoll;
		}
	}
	return Roll;
}
