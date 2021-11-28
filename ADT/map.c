#include "map.h"
#include "mesinkar.h"
#include "mesinkata.h"

int ArrayOfCharToInt (Kata CKata, int *result){
    int i, temp, multiplier;
    temp = CKata.Length;
    multiplier = 10;
    *result = ((int) CKata.TabKata[temp] - 48);
    for (i = temp - 1; i > 0; i--){
        *result += ((int) CKata.TabKata[i] - 48) * multiplier;
        multiplier = multiplier * 10;
    }
}

void KonfigurasiToMap (Map *Map, char* locate){
    int t, i, j, k;
    STARTKATA(locate);
    ArrayOfCharToInt(CKata, &t);
    (*Map).PanjangMap = t;
    IgnoreBlank();
    for (i = 1; i <= (*Map).PanjangMap; i++){
        (*Map).TabMap[i].Alamat = i;
        (*Map).TabMap[i].IsiPetak = CC;
        ADV();
    }
    ADVKATA();
    ArrayOfCharToInt(CKata, &t);
    (*Map).MaxRoll = t;
    ADVKATA();
    ArrayOfCharToInt(CKata, &t);
    (*Map).JumlahTeleporter = t;
    for (k = 1; k <= (*Map).PanjangMap; k++){
        (*Map).TabMap[k].Teleporter = -1;
    }
    int Lokasi, Tujuan;
    for (j = 1; j <= (*Map).JumlahTeleporter; j++){
        ADVKATA();
        ArrayOfCharToInt(CKata, &Lokasi);
        ADVKATA();
        ArrayOfCharToInt(CKata, &Tujuan);
        (*Map).TabMap[Lokasi].Teleporter = Tujuan;
    }
}

void SalinMap (Map *Mx, Map *My){
    int i;
    for (i = 1; i <= (*Mx).PanjangMap; i++){
    	(*My).TabMap[i].IsiPetak = (*Mx).TabMap[i].IsiPetak;	
    }
}
