#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

int main(){
	List gemink;
	int a, i, b, c;
	CreateEmpty(&gemink);
	a = Rskill(&gemink);
	PrintForward(gemink);
	printf("\n");
	scanf("%d", &b);
	BuangSkill(&gemink, b);
	PrintForward(gemink);
	printf("\n");
	PrintSkill(gemink);
	scanf("%d", &c);
	getSkill(gemink, c);
	BuangSkill(&gemink, c);
	PrintForward(gemink);
	printf("\n");
	PrintSkill(gemink);
}
