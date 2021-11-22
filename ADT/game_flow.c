#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "game_flow.h"
#include "listdp.h"
#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "player.h"
#include "roll.h"

boolean game (boolean endGame){
	int i, j, a, b, cekPetak, roll, maxRoll, n, countBuff2, countBuff5, ganda;
	char command[MaxCommand];
	boolean immune, endTurn;
	TabPlayer gemink;
	printf("Masukan jumlah pemain : ");
	scanf("%d", &n);
	MakeTabPlayer(&gemink, n);
	START();
	Map hayu;
	KonfigurasiToMap(&hayu);
	i = 1;
	while (!endGame){
		int buffRoll, buff, doneRoll;
		printf("Giliran Kamu %s\n", (gemink.TI[i].Nama));
		maxRoll = hayu.MaxRoll;
		immune = false;
		buffRoll = 0;
		buff = 0;
		doneRoll = 0;
		b = Rskill(&gemink.TI[i].Skill);
		NambahSkill(&gemink.TI[i].Skill, b);
		buff = 0;
		printf("Masukan command : ");
		gets(command);
		while (strcmp(command, "ENDTURN") != 0 && doneRoll == 0){
			if (strcmp(command, "SKILL") == 0){
				if (NbElmt(gemink.TI[i].Skill) != 0){
					PrintSkill(gemink.TI[i].Skill);
					puts("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
					countBuff2 = 0;
					countBuff5 = 0;
					while (NbElmt(gemink.TI[i].Skill) > 0){
						printf("Masukkan skill: ");
						scanf("%d", &a);
						if (abs(a) > NbElmt(gemink.TI[i].Skill)){
							break;
						}
						if (a != 0){
							if (a < 0){
								getSkill(gemink.TI[i].Skill, a);
								BuangSkill(&gemink.TI[i].Skill, a);
							}
							else{ // a > 0, skill dipakai dan mendapatkan buff
								buff = getSkill(gemink.TI[i].Skill, a);
								BuangSkill(&gemink.TI[i].Skill, a);
								if (buff == 2 && countBuff2 == 0){
									countBuff2 = 1;
									ganda = 0;
									if (NbElmt(gemink.TI[i].Skill) < 9){
										while (NbElmt(gemink.TI[i].Skill) < 10 || ganda < 2){
											b = Rskill(&gemink.TI[i].Skill);
											NambahSkill(&gemink.TI[i].Skill, b);
											ganda += 1;
										}
									}	
								}
								else if (buff == 1){
									immune = true;
								}
								else if (buff == 3){
									buffRoll = 3;
								}
								else if (buff == 4){
									buffRoll = 4;
								}
								else if (buff == 5 && countBuff5 == 0){
									/* countBuff5 = 1;
									printf("%d. ", j);
									printf("%s\n",(gemink.TI[j].Nama));
									printf("Masukan pemain: ");
									scanf("%d", &nomorPemain);
									while (nomorPemain != j){
										printf("Masukan pemain: ");
										scanf("%d", &nomorPemain);
									} */
								}
							}
						}
						else{
							break;
						}
					}
				}
				else{
					puts("Kamu tidak memiliki skill.");
				}
			}
			else if (strcmp(command, "MAP") == 0){
				CMap(hayu, gemink);
			}
			else if (strcmp(command, "BUFF") == 0){
				CBuff(immune, buffRoll);
			}
			else if (strcmp(command, "INSPECT") == 0){
				// printf("Masukkan petak : ");
				// scanf("%d", &cekPetak);
				// printf("Petak ");
				// printf("%d ", cekPetak);
				
			}
			else if (strcmp(command, "ROLL") == 0 && doneRoll == 0){
				int prob1, prob2, pilihRoll;
				roll = rollDadu(buffRoll, maxRoll);
				printf("%s ", (gemink.TI[i].Nama));
				printf("mendapatkan angka ");
				printf("%d\n", roll);
				prob1 = gemink.TI[i].CPosition + roll;
				prob2 = gemink.TI[i].CPosition - roll;
				boolean bergerak;
				bergerak = false;
				if (hayu.TabMap[prob1].IsiPetak == '.' && prob1 <= hayu.PanjangMap && hayu.TabMap[prob2].IsiPetak == '.' && prob2 >= 1){
					bergerak = true;
					printf("%s dapat maju dan mundur.\n", gemink.TI[i].Nama);
					printf("Ke mana %s mau bergerak:\n"), gemink.TI[i].Nama;
					printf("1. %d", prob2);
					printf("2. %d", prob1);
					printf("Masukan pilihan: ");
					scanf("%d", &pilihRoll);
					while (pilihRoll != 1 || pilihRoll != 2){
						printf("Masukan pilihan: ");
						scanf("%d", &pilihRoll);
					}
					if (pilihRoll == 1){
						gemink.TI[i].CPosition = prob2;
						printf("%s mundur %d langkah.\n", gemink.TI[i].Nama, roll);
                        printf("%s berada di petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
					}
					else{
						gemink.TI[i].CPosition = prob1;
						printf("%s maju %d langkah.\n", gemink.TI[i].Nama, roll);
                        printf("%s berada di petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
					}
				}
				else if (hayu.TabMap[prob1].IsiPetak == '.' && prob1 <= hayu.PanjangMap){
					bergerak = true;
					printf("%s dapat maju.\n", gemink.TI[i].Nama);
					printf("%s maju %d langkah.\n", gemink.TI[i].Nama, roll);
					gemink.TI[i].CPosition = prob1;
					printf("%s berada di petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
				}
				else if (hayu.TabMap[prob2].IsiPetak == '.' && prob2 >= 1){
					bergerak = true;
					printf("%s dapat mundur.\n", gemink.TI[i].Nama);
					printf("%s mundur %d langkah.\n", gemink.TI[i].Nama, roll);
					gemink.TI[i].CPosition = prob2;
					printf("%s berada di petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
				}
				else{
					printf("%s tidak dapat bergerak.\n", gemink.TI[i].Nama);
				}
				if (bergerak){
					if (hayu.TabMap[gemink.TI[i].CPosition].Teleporter == -1) {
                        printf("%s tidak menemukan teleporter.\n", gemink.TI[i].Nama);
                    }
                    else {
                        printf("%s menemukan teleporter.\n", gemink.TI[i].Nama);
                        if (immune){
                        	char telep[5];
                            printf("%s memiliki imunitas teleport.\n", gemink.TI[i].Nama);
                            printf("Apakah %s ingin teleport (Y/N)? ", gemink.TI[i].Nama);
                            gets(telep);
                            while (strcmp(telep, "Y") != 0 || strcmp(telep, "N") != 0){
                                scanf("%c", &telep);
                        	}
                            if (strcmp(telep, "Y") == 0){
                                gemink.TI[i].CPosition = hayu.TabMap[gemink.TI[i].CPosition].Teleporter;
                                printf("%s teleport ke petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
                            }
                            else{
                                printf("%s tidak teleport.\n", gemink.TI[i].Nama);
                                immune = false;
                                printf("Buff imunitas teleport hilang.\n");
                            }
                    	}
            			else{
                            printf("%s tidak memiliki imunitas teleport.\n", gemink.TI[i].Nama);
                            gemink.TI[i].CPosition = hayu.TabMap[gemink.TI[i].CPosition].Teleporter;
                            printf("%s teleport ke petak %d.\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
                        }
                	}
            	}
				doneRoll = 1;
				if (gemink.TI[i].CPosition == hayu.PanjangMap){
					endGame = true;
					break;
				}
			}
			else if (strcmp(command, "UNDO") == 0){
				// Undo();
			}
			printf("Masukan command : ");
			gets(command);
		}
		i += 1;
		if (i > n){
			i = 1;
		}
	}
}

void CMap(Map peta, TabPlayer gemink){
	int imap, jmap;
	for (imap = 1; imap <= gemink.Neff; imap++) {
        printf("%s", (gemink.TI[imap].Nama));
        printf(" : ");
        for (jmap = 1; jmap <= peta.PanjangMap; jmap++) {
            if (gemink.TI[imap].CPosition == jmap) {
                printf("*");
            }
            else {
                printf("%c", peta.TabMap[jmap].IsiPetak);
            }
        }
        printf(" %d", gemink.TI[imap].CPosition);
        printf("\n");
    }
    printf("\n");
}

void CBuff(boolean immune, int buffRoll){
	if (immune){
		puts("Imunitas Teleport : Ketika masuk teleporter dan memiliki buff ini, muncul pilihan untuk tidak ke mana-mana.");
	}
	if (buffRoll == 3){
		puts("Senter Pembesar Hoki : Hasil roll menjadi antara floor(MaxRoll/2) dan MaxRoll.");
	}
	else if (buffRoll == 4){
		puts("Hasil roll menjadi antara 1 dan floor(MaxRoll/2).");
	}
}