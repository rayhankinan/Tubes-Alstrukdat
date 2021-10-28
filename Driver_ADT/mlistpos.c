/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 7 September 2021
Topik Praktikum     : ADT List
Deskripsi           : Driver ADT ListPos untuk mengecek semua fungsi dan prosedur
*/

#include <stdio.h>
#include "../ADT/ListStatis/listpos.h"

int main() {
    /* KAMUS */
    int i, lenl1, lenl2;
    ElTypeListPos min, max, temp;
    ListPos l1, l2;

    /* ALGORITMA */
    printf("Masukkan list pertama:\n");
    readListPos(&l1);
    printf("List pertama: ");
    displayListPos(l1);
    printf("\n");
    extremesListPos(l1, &max, &min);
    printf("Range list : %d - %d\n", min, max);
    lenl1 = lengthListPos(l1);
    printf("Panjang list : %d\n", lenl1);
    if (isAllEvenListPos(l1)) {
        printf("Semua elemen pada list pertama adalah genap\n");
    }
    printf("\n");

    printf("Masukkan list kedua:\n");
    readListPos(&l2);
    printf("List kedua: ");
    displayListPos(l2);
    printf("\n");
    extremesListPos(l1, &max, &min);
    printf("Range list : %d - %d\n", min, max);
    lenl2 = lengthListPos(l2);
    printf("Panjang list : %d\n", lenl2);
    if (isAllEvenListPos(l2)) {
        printf("Semua elemen pada list kedua adalah genap\n");
    }
    printf("\n");

    if (isListPosEqual(l1, l2)) {
        printf("Kedua list memiliki elemen yang sama!\n");
        printf("\n");
    }

    if (lengthListPos(l1) == lengthListPos(l2)) {
        printf("Operasi penambahan antara list pertama dengan list kedua: ");
        displayListPos(plusMinusTabListPos(l1, l2, true));
        printf("\n");
        printf("Operasi pengurangan antara list pertama dengan list kedua: ");
        displayListPos(plusMinusTabListPos(l1, l2, false));
        printf("\n");
        printf("\n");
    }

    printf("Gabungkan elemen list kedua (sudah terurut) ke list pertama (sudah terurut) secara terurut:\n");
    sortListPos(&l1, true);
    displayListPos(l1);
    printf(" ");
    sortListPos(&l2, true);
    displayListPos(l2);
    printf("\n");
    while (!isFullListPos(l1) && !isEmptyListPos(l2)) {
        deleteLastListPos(&l2, &temp);
        insertLastListPos(&l1, temp);
        sortListPos(&l1, true);
        displayListPos(l1);
        printf(" ");
        displayListPos(l2);
        printf("\n");
    }

    printf("\n");
}