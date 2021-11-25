#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../boolean.h"
#include "game_flow.h"
#include "listdp.h"
#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "player.h"
#include "stack.h"
#include "../Fungsi/roll.h"

boolean game (boolean endGame){
	int i, j, a, b, cekPetak, roll, maxRoll, n, countBuff2, countBuff5, ganda, endTurn, posisi, round;
	char command[MaxCommand];
	boolean immune;
	TabPlayer gemink;
	Stack geminkhistory;
	CreateStack(&geminkhistory);
	printf("Masukan jumlah pemain : ");
	scanf("%d", &n);
	MakeTabPlayer(&gemink, n);
	START();
	Map hayu;
	KonfigurasiToMap(&hayu);
	i = 1;
	printf("\nPermainan dimulai...\n");
	round = 0;
	while (!endGame){
		if (i == 1){
			round += 1;
			if (round == 1){
				Push(&geminkhistory, gemink);
			}
			puts("");
			printf("---------------Ronde %d---------------\n", round);
			puts("");
			CMap(hayu, gemink);
			puts("");
			puts("-------------------------------------");
		}
		int buffRoll, buff, doneRoll, j;
		printf("\nGiliran Kamu %s\n", (gemink.TI[i].Nama));
		printf("Kamu mendapat skill: \n");
		maxRoll = hayu.MaxRoll;
		immune = false;
		buffRoll = 0;
		buff = 0;
		doneRoll = 0;
		b = Rskill(&gemink.TI[i].Skill);
		NambahSkill(&gemink.TI[i].Skill, b);
		buff = 0;
		printf("\nMasukan command : ");
		scanf("%s", command);
		endTurn = 0;
		while (endTurn == 0 || doneRoll == 0){
			if (strcmp(command, "SKILL") == 0){
				puts("");
				if (NbElmt(gemink.TI[i].Skill) != 0){
					if (countBuff2 < 1){
						countBuff2 = 0;
					}
					if (countBuff5 < 1){
						countBuff5 = 0;
					}
					PrintSkill(gemink.TI[i].Skill);
					puts("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
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
										while (NbElmt(gemink.TI[i].Skill) < 10 && ganda < 2){
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
									countBuff5 = 1;
									j = 1;
									for (j = 1; j <= n; j++){
										if (j != i){
											printf("%d. %s\n", j, gemink.TI[j].Nama);
										}
									}
									printf("Masukan pemain: ");
									scanf("%d", &j);
									posisi = gemink.TI[i].CPosition;
									gemink.TI[i].CPosition = gemink.TI[j].CPosition;
									gemink.TI[j].CPosition = posisi;
									printf("%s berhasil menukar posisi dan berada pada %d\n", gemink.TI[i].Nama, gemink.TI[i].CPosition);
									CMap(hayu, gemink);
								}
							}
						}
						else{
							break;
						}
						if (NbElmt(gemink.TI[i].Skill) > 0){
							puts("");
							PrintSkill(gemink.TI[i].Skill);
							puts("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.");
						}
					}
				}
				else{
					puts("Kamu tidak memiliki skill.");
				}
				printf("\nMasukan command : ");
			}
			else if (strcmp(command, "MAP") == 0){
				printf("\n");
				CMap(hayu, gemink);
				printf("\nMasukan command : ");
			}
			else if (strcmp(command, "BUFF") == 0){
				printf("\n");
				CBuff(immune, buffRoll);
				printf("\nMasukan command : ");
			}
			else if (strcmp(command, "INSPECT") == 0){
				printf("\n");
				CInspect(hayu);
				printf("\nMasukan command : ");
			}
			else if (strcmp(command, "ROLL") == 0 && doneRoll == 0){
				printf("\n");
				int prob1, prob2, pilihRoll;
				roll = rollDadu(buffRoll, maxRoll);
				buffRoll = 0;
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
					printf("Ke mana %s mau bergerak:\n", gemink.TI[i].Nama);
					printf("   1. %d\n", prob2);
					printf("   2. %d\n", prob1);
					printf("Masukan pilihan: ");
					scanf("%d", &pilihRoll);
					while (pilihRoll != 1 && pilihRoll != 2){
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
				if (bergerak && gemink.TI[i].CPosition != 20){
					if (hayu.TabMap[gemink.TI[i].CPosition].Teleporter == -1) {
                        printf("%s tidak menemukan teleporter.\n", gemink.TI[i].Nama);
                    }
                    else {
                        printf("%s menemukan teleporter.\n", gemink.TI[i].Nama);
                        if (immune){
                        	char telep;
                            printf("%s memiliki imunitas teleport.\n", gemink.TI[i].Nama);
                            printf("Apakah %s ingin teleport (Y/N)? ", gemink.TI[i].Nama);
                            scanf("%c", &telep);
                            while (telep != 'Y' && telep != 'N'){
                                scanf("%c", &telep);
                        	}
                            if (telep == 'Y'){
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
					puts("");
					printf("Selamat Player %d dengan Nama %s Telah Memenangkan Game Ini!!!\n", i, gemink.TI[i].Nama);
					i -= 1;
					break;
				}
				printf("\nMasukan command : ");
			}
			else if (strcmp(command, "UNDO") == 0){
				if (i == 1) {
                    printf("\n");
                    Pop(&geminkhistory, &gemink);
                    printf("UNDO berhasil dilakukan\n");
                   	round -= 1;
                    char undo;
                    while (round >= 1) {
                    	printf("Apakah ingin melakukan UNDO lagi? (Y/N): ");
			getchar();
                    	scanf("%c", &undo);
                    	if (undo == 'Y'){
                            Pop(&geminkhistory, &gemink);
                            printf("\nUNDO berhasil dilakukan\n");
                            round -= 1;
                        }
                        else if (undo == 'N'){
				Push(&geminkhistory, gemink);
                        	break;
						}
					}
                }  
                else {
                    printf("\n");
                    Pop(&geminkhistory, &gemink);
                    printf("UNDO berhasil dilakukan\n");
                    round -= 1;
                }
				immune = false;
				countBuff2 = 0;
				countBuff5 = 0;
				buffRoll = 0;
				i = 0;
				break;
			}
			else if (strcmp(command, "ENDTURN") == 0 && doneRoll == 1){
				endTurn = 1;
				printf("\nGiliran %s selesai.\n", (gemink.TI[i].Nama));
				break;
			}
			scanf("%s", command);
		}
		i += 1;
		if (i > n){
			Push(&geminkhistory, gemink);
			i = 1;
		}
	}
	int selisih, peringkat, simpenj;
	puts("");
    puts("==================== PERINGKAT ====================");
    printf("1. %s\n", gemink.TI[i].Nama);
    gemink.TI[i].CPosition = 0;
    peringkat = 2;
    while (peringkat <= n){
    	j = 1;
    	selisih = 20;
    	while (j <= n){
    		if (hayu.PanjangMap - gemink.TI[j].CPosition <= selisih){
    			selisih = hayu.PanjangMap - gemink.TI[j].CPosition;
    			simpenj = j;
			}
			j += 1;
		}
		gemink.TI[simpenj].CPosition = 0;
		printf("%d. %s\n", peringkat, gemink.TI[simpenj].Nama);
		peringkat += 1;
	}
    puts("===================================================");
    return endGame;
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
}

void CBuff(boolean immune, int buffRoll){
	if (immune){
		puts("Imunitas Teleport -> Ketika masuk teleporter dan memiliki buff ini, muncul pilihan untuk tidak ke mana-mana.");
	}
	if (buffRoll == 3){
		puts("Senter Pembesar Hoki -> Hasil roll menjadi antara floor(MaxRoll/2) dan MaxRoll.");
	}
	else if (buffRoll == 4){
		puts("Senter Pengecil Hoki -> Hasil roll menjadi antara 1 dan floor(MaxRoll/2).");
	}
}

void CInspect(Map peta){
	int z;
	printf("Masukan petak: ");
	scanf("%d", &z);
	if (peta.TabMap[z].IsiPetak == '#'){
		printf("Petak %d merupakan petak terlarang.\n", z);
	}
	else if (peta.TabMap[z].IsiPetak == '.'){
		if (peta.TabMap[z].Teleporter == -1){
			printf("Petak %d merupakan petak kosong.\n", z);
		}
		else{
			printf("Petak %d memiliki teleporter menuju %d.\n", z, peta.TabMap[z].Teleporter);
		}
	}
}
