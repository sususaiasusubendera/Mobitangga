#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "listdp.h"

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L) == Nil && Last(L) == Nil);
};
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
};
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	P = (ElmtList*) malloc (sizeof(ElmtList));
	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
		return P;
	}
	else{
		return Nil;
	}
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
	free (P);
};
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address P;
	P = First(L);
	if (IsEmpty(L)){
		return Nil;
	}
	else{
		while (P != Nil && Info(P) != X){
			P = Next(P);
		}
		return P;
	}
};
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P;
	P = Alokasi(X);
	if (P != Nil){
		InsertFirst(L, P);
	}
};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P;
	P = Alokasi(X);
	if (P != Nil){
		InsertLast(L, P);
	}
};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(P);
};
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	if (IsEmpty(*L)){
		First(*L) = P;
		Last(*L) = P;
		Next(P) = Nil;
		Prev(P) = Nil;
	}
	else{
		Prev(P) = Nil;
		Prev(First(*L)) = P;
		Next(P) = First(*L);
		First(*L) = P;
	}
};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	if (IsEmpty(*L)){
		InsertFirst(L, P);
	}
	else{
		Next(P) = Nil;
		Next(Last(*L)) = P;
		Prev(P) = Last(*L);
		Last(*L) = P;
	}
};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	if (Prec == Last(*L)){
		InsertLast(L, P);
	}
	else{
		Next(P) = Next(Prec);
		Next(Prec) = P;
		Prev(P) = Prec;
		Prev(Next(P)) = P;
	}
};
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
	if (Succ == First(*L)){
		InsertFirst(L, P);
	}
	else{
		Next(Prev(Succ)) = P;
		Next(P) = Succ;
		Prev(P) = Prev(Succ);
		Prev(Succ) = P;
	}
};
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L);
	if (Next(*P) == Nil){
		CreateEmpty(L);
	}
	else{
		First(*L) = Next(*P);
		Prev(Next(*P)) = Nil;
	}
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
	*P = Last(*L);
	if (Prev(*P) == Nil){
		CreateEmpty(L);
	}
	else{
		Last(*L) = Prev(*P);
		Next(Prev(*P)) = Nil;
	}
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
	address P;
	P = Search(*L, X);
	if (P != Nil){
		if (P == First(*L) && P == Last(*L)){
			CreateEmpty(L);
		}
		else if (P == First(*L)){
			DelFirst(L, &P);
		}
		else if (P == Last(*L)){
			DelLast(L, &P);
		}
		else{
			Next(Prev(P)) = Next(P);
			Prev(Next(P)) = Prev(P);
		}
		Dealokasi(P);
	}
};
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if (*Pdel != Nil){
		Next(Prec) = Next(*Pdel);
		if (Next(*Pdel) != Nil){
			Prev(Next(*Pdel)) = Prec;
		}
		else{
			Last(*L) = Prec;
		}
	}
};
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);
	if (*Pdel != Nil){
		Prev(Succ) = Prev(*Pdel);
		if (Prev(*Pdel) != Nil){
			Next(Prev(*Pdel)) = Succ;
		}
		else{
			First(*L) = Succ;
		}
	}
};
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
	address P;
	P = First(L);
	printf("[");
	while (P != Nil){
		printf("%d", Info(P));
		P = Next(P);
		if (P != Nil){
			printf(",");
		}
	}
	printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
	address P;
	P = Last(L);
	printf("[");
	while (P != Nil){
		printf("%d", Info(P));
		P = Prev(P);
		if (P != Nil){
			printf(",");
		}
	}
	printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int Rskill (List *L){
	int a, i, result;
	srand((unsigned) (time(0)));
	for (i = 1; i < 10; i++){
		a = rand() % 10;
	}
	result = (result + a) % 10;
	return result;
};
/* 
1. Pintu Ga Ke Mana Mana 10%, 0
2. Cermin Pengganda 10%, 1
3. Senter Pembesar Hoki 20%, 2 atau 3
4. Senter Pengecil Hoki 20%, 4 atau 5
5. Mesin Penukar Posisi 10%, 6 
6. Teknologi Gagal 30% 7 atau 8 atau 9
*/

int NbElmt (List L){
	address P;
	int count;
	P = First(L);
	count = 0;
	while (P != Nil){
		count += 1;
		P = Next(P);
	}
	return count;
};

void DelIndex (List *L, int n){
	address P;
	int i;
	P = First(*L);
	i = 0;
	if (n == 1){
		DelFirst(L, &P);
	}
	else if (n == NbElmt(*L)){
		P = Last(*L);
		DelLast(L, &P);
	}
	else {
		while (i < n){
			i += 1;
			P = Next(P);
		}
		P = Prev(P);
		DelAfter(L, &P, Prev(P));
	}
};

void NambahSkill (List *L, int a){
	int skill;
	if (NbElmt(*L) < 10){
		if (a == 0){
			skill = 1;
        	printf("Pintu Ga Ke Mana-Mana\n");
    	}
    	else if (a == 1){ 
        	skill = 2;
        	printf("Cermin Pengganda\n");
    	}
    	else if (a == 2 || a == 3){ 
        	skill = 3;
        	printf("Senter Pembesar Hoki\n");
    	}
    	else if (a == 4 || a == 5){ 
        	skill = 4;
        	printf("Senter Pengecil Hoki\n");
    	}
    	else if (a == 6){ 
        	skill = 5;
        	printf("Mesin Penukar Posisi\n");
    	}  
    	else if (a >= 7){ 
        	skill = 0; // skill 6 tidak masuk ke dalam list
        	printf("Teknologi Gagal\n");
    	}
	}

    if (skill != 0 && NbElmt(*L) < 10){
        InsVLast(L, skill);
        printf("Skill ");
        printf("%d", skill);
        printf(" berhasil dimasukkan\n");
    } 
    else if (skill == 0){
        printf("Yahh ga dapet skill, kacian :(\n");
    }
    else { // NbElmt(*L) > 10
        printf("Jumlah skill yang dimiliki sudah mencapai maksimum\n");
    }
};

void BuangSkill (List *L, int a){
	if (IsEmpty(*L)) {
        printf("Anda tidak mempunyai skill\n");    
    }
    else {
        a = abs(a);
        DelIndex(L, a);
    }
};

void PrintSkill (List L){
	int i;
	address P;
	i = 1;
	P = First(L);
	puts("Kamu memiliki skill:");
	while (P != Nil){
		printf("   %d. ", i);
		if (Info(P) == 1){
            printf("Pintu Ga Ke Mana Mana\n");
        }
        else if (Info(P) == 2){
            printf("Cermin Pengganda\n");
        }
        else if (Info(P) == 3){
            printf("Senter Pembesar Hoki\n");
        }
        else if (Info(P) == 4){
            printf("Senter Pengecil Hoki\n");
        }
        else if (Info(P) == 5){
            printf("Mesin Penukar Posisi\n");
        }
        P = Next(P);
		i += 1;
	}
};

int getSkill (List L, int a){
	address P;
	int i, buff;
	P = First(L);
	if (a > 0){
		for (i = 1; i < a; i++){
			P = Next(P);
		}
		printf("Kamu memakai skill ");
		if (Info(P) == 1){
            printf("Pintu Ga Ke Mana Mana.\n");
    		buff = 1;
    		return buff;
        }
        else if (Info(P) == 2){
            printf("Cermin Pengganda.\n");
            buff = 2;
            return buff;
        }
        else if (Info(P) == 3){
            printf("Senter Pembesar Hoki.\n");
            buff = 3;
            return buff;
        }
        else if (Info(P) == 4){
            printf("Senter Pengecil Hoki.\n");
            buff = 4;
            return buff;
        }
        else if (Info(P) == 5){
            printf("Mesin Penukar Posisi.\n");
            puts("Pilih pemain yang ingin ditukar posisinya\n");
            buff = 5;
            return buff;
        }
	}
	else{
		a = abs(a);
		for (i = 1; i < a; i++){
			P = Next(P);
		}
		printf("Kamu membuang skill ");
		if (Info(P) == 1){
            printf("Pintu Ga Ke Mana Mana.\n");
        }
        else if (Info(P) == 2){
            printf("Cermin Pengganda.\n");
        }
        else if (Info(P) == 3){
            printf("Senter Pembesar Hoki.\n");
        }
        else if (Info(P) == 4){
            printf("Senter Pengecil Hoki.\n");
        }
        else if (Info(P) == 5){
            printf("Mesin Penukar Posisi.\n");
        }
	}
	return 0;
};
