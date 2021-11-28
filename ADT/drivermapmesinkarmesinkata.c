#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"
#include "map.h"

int main(){
	char locate[50];
	scanf("%s", locate);
    START(locate);
    int i;
    Map map, map1;
    KonfigurasiToMap(&map);
    printf("%d\n", (map.PanjangMap));
    for (i = 1; i <= (map.PanjangMap); i++){
        printf("%c", map.TabMap[i].IsiPetak);
    }
    printf("\n%d\n", map.MaxRoll);
    printf("%d\n", map.JumlahTeleporter);
    i = 1;
    SalinMap(&map, &map1);
    for (i = 1; i <= (map.PanjangMap); i++){
        printf("%c", map1.TabMap[i].IsiPetak);
    }
    printf("\n");
}
