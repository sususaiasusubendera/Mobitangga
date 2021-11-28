# **Mobitangga**

## Deskripsi Program

	Program ini merupakan sebuah permainan berbasis CLI (command-line interface) yang dibuat dalam bahasa C dengan menggunakan implementasi dari beberapa struktur data, diantaranya ADT Array, ADT List, ADT Stack, ADT Map, ADT Mesin Karakter, ADT Mesin Kata dan lainnya. 
	Permainan ini merupakan sebuah permainan yang serupa dengan ular tangga, namun dalam bentuk satu dimensi dengan jumlah pemain sebanyak dua sampai empat orang. mereka akan berlomba untuk mencapai garis finish yaitu petak N dengan menggunakan dadu. Pemain juga mendapatkan berbagai skill yang dapat digunakan untuk menjadi buff selama permainan berlangsung. Skill diperoleh secara random setiap awal permainan dimulai dan setiap satu ronde permainan selesai. Ronde permainan dihitung setelah tiap pemain menyelesaikan masing-masing turn-nya. Di map permainan juga terdapat beberapa teleporter yang diletakkan secara acak sehingga player dapat berpindah ke bagian tertentu pada map.
	 Program ini dibuat menggunakan bahasa C dengan memanfaatkan ADT yang sudah dipelajari pada mata kuliah IF2110 Algoritma dan Struktur Data. Game ini dimulai dengan menampilkan main menu yang memberikan pilihan pada pemain untuk start game atau quit. Setelah permainan dimulai, para pemain dapat memainkan permainan secara bergantian. Command yang valid pada game ini adalah SKILL, MAP, BUFF, INSPECT, ROLL, ENDTURN, dan UNDO. Pemain yang menyentuh petak terakhir terlebih dahulu akan menjadi pemenangnya.

## Kelompok 20 :
- 18220043 Amelia Wahyu Dewanti
- 18220051 Natanael Dias
- 18220055 Rahadyanino Maheswara
- 18220056 Khafifanisa
- 18220098 Ray Clement Juwanda

## Cara kompilasi program :
Untuk pake make file, buka cmd di folder utama mobitangga, ketik :
```sh
make
```
lalu ketik :
```sh
Mobitangga
```

Kalau mau pake gcc, di terminal folder Mobitangga ketik :
```sh
gcc main_driver.c ./ADT/game_flow.c ./ADT/listdp.c ./ADT/map.c ./ADT/mesinkar.c ./ADT/mesinkata.c ./ADT/player.c ./ADT/stack.c ./Fungsi/pre.c ./Fungsi/post.c ./Fungsi/roll.c boolean.h -o Mobitangga
```
lalu ketik :
```sh
Mobitangga
```
