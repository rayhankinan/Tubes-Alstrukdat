#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Lokasi/lokasi.h"
#include "../ADT/Point/point.h"

int main(){
    /* KAMUS LOKAL */
    POINT p1, p2;
    Lokasi l1, l2, l3, l4;

    /* ALGORITMA */
    // Membuat point
    p1 = MakePOINT(3,4);
    p2 = MakePOINT(5,6);

    // Membuat lokasi
    l1 = CreateLokasi('A', p1);
    l2 = CreateLokasi('B', p1);
    l3 = CreateLokasi('A', p2);
    l4 = CreateLokasi('A', p1);

    // Display lokasi
    printf("Lokasi l1: ");
    TulisLokasi(l1); printf("\n");
    printf("Lokasi l2: ");
    TulisLokasi(l2); printf("\n");
    printf("Lokasi l3: ");
    TulisLokasi(l3); printf("\n");
    printf("Lokasi l4: ");
    TulisLokasi(l4); printf("\n");

    // EQ Lokasi
    printf("--------------------------\n");
    if(EQLokasi(l1,l2)){
        printf("Lokasi l1 dan l2 sama\n");    // beda karena nama lokasi berbeda
    }
    if(EQLokasi(l1,l3)){
        printf("Lokasi l1 dan l3 sama\n");    // beda karena Point berbeda
    }
    if(EQLokasi(l1,l4)){
        printf("Lokasi l1 dan l4 sama\n");    // sama karena nama lokasi dan point sama
    }

    // selektor
    printf("--------------------------\n");
    printf("Nama lokasi l1: %c\n", NAMA_LOKASI(l1));
    printf("Koordinat lokasi l1: ");
    TulisPOINT(KOORDINAT_LOKASI(l1));

    return 0;
}