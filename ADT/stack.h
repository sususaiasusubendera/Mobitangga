/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../boolean.h"


#define Nil 0
#define MaxEl 20
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri round : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
    infotype p1position[MaxEl+1]; /* tabel penyimpan posisi pemain pertama */
    infotype p2position[MaxEl+1]; /* tabel penyimpan posisi pemain kedua */
    address round;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.round = Nil */
/* Elemen yang dipakai menyimpan nilai Stack p1position[1]..p1position[MaxEl] */
/* Elemen yang dipakai menyimpan nilai Stack p2position[1]..p2position[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.player[(S.round)] untuk mengakses elemen round */
   /* S.round adalah alamat elemen round */

/* Definisi akses dengan Selektor : Set dan Get */
#define round(S) (S).round
#define p1position(S) (S).p1position[(S).round]
#define p2position(S) (S).p2position[(S).round]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void NewGame (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : round bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsNewGame (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsEndGame (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void AddRound (Stack * S, infotype X, infotype Y);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X dan Y menjadi p1position dan p2position yang baru, round bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void UndoRound (Stack * S, infotype* X, infotype* Y);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X dan Y adalah nilai elemen p1position dan p2position yang lama, round berkurang 1 */

#endif
