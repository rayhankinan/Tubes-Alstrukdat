#include <stdio.h>
#include "../ADT/ListDinamis/listdin.h"

int main() {
    /* KAMUS */
    int NMax, NExtra;
    ListDin l1, l2, sortedL1, sortedL2;
    ElTypeListDin maxL1, minL1, maxL2, minL2, temp;
    IdxTypeListDin i;

    /* ALGORITMA */
    printf("Masukkan jumlah maksimal elemen ListDin: ");
    scanf("%d", &NMax);

    CreateListDin(&l1, NMax);
    CreateListDin(&l2, NMax);

    printf("Masukkan ListDin pertama:\n");
    readListDin(&l1);

    printf("\n");
    printf("ListDin pertama: ");displayListDin(l1);printf("\n");

    if (!isEmptyListDin(l1)){
        extremesListDin(l1, &maxL1, &minL1);
        printf("Range ListDin pertama: (%d - %d)\n", minL1, maxL1);
        printf("Jumlah semua elemen pada ListDin pertama: %d\n", sumListDin(l1));
        printf("Frequency table ListDin pertama: \n");
        for (i = 0; i <= getLastIdxListDin(l1); i++) {
            if (i == indexOfListDin(l1, ELMT_LISTDIN(l1, i))) {
                printf("%d : %d\n", ELMT_LISTDIN(l1, i), countValListDin(l1, ELMT_LISTDIN(l1, i)));
            }
        }
        if (isAllEvenListDin(l1)) {
            printf("Semua elemen ListDin pertama genap!\n");
        }
        if (isFullListDin(l1)) {
            printf("ListDin pertama penuh!\n");
        }
        copyListDin(l1, &sortedL1);
        sortListDin(&sortedL1, true);
        printf("ListDin pertama sorted: ");displayListDin(sortedL1);printf("\n");
    } else {
        printf("ListDin pertama kosong!\n");
    }
    printf("\n");

    compactListDin(&l1);

    printf("Masukkan ListDin kedua:\n");
    readListDin(&l2);

    printf("\n");
    printf("ListDin kedua: ");displayListDin(l2);printf("\n");

    if (!isEmptyListDin(l2)){
        extremesListDin(l2, &maxL2, &minL2);
        printf("Range ListDin kedua: (%d - %d)\n", minL2, maxL2);
        printf("Jumlah semua elemen pada ListDin kedua: %d\n", sumListDin(l2));
        printf("Frequency table ListDin kedua: \n");
        for (i = 0; i <= getLastIdxListDin(l2); i++) {
            if (i == indexOfListDin(l2, ELMT_LISTDIN(l2, i))) {
                printf("%d : %d\n", ELMT_LISTDIN(l2, i), countValListDin(l2, ELMT_LISTDIN(l2, i)));
            }
        }
        if (isAllEvenListDin(l2)) {
            printf("Semua elemen ListDin kedua genap!\n");
        }
        if (isFullListDin(l2)) {
            printf("ListDin kedua penuh!\n");
        }
        copyListDin(l2, &sortedL2);
        sortListDin(&sortedL2, true);
        printf("ListDin kedua sorted: ");displayListDin(sortedL2);printf("\n");
    } else {
        printf("ListDin kedua kosong!\n");
    }
    printf("\n");
    
    compactListDin(&l2);

    if (lengthListDin(l1) == lengthListDin(l2)) {
        printf("ListDin pertama + ListDin kedua = ");displayListDin(plusMinusListDin(l1, l2, true));printf("\n");
        printf("ListDin pertama - ListDin kedua = ");displayListDin(plusMinusListDin(l1, l2, false));printf("\n");
    }
    if (isListDinEqual(l1, l2)) {
        printf("ListDin pertama = ListDin kedua\n");
    }

    growListDin(&l1, lengthListDin(l2));

    NExtra = lengthListDin(l2);

    for (i = 0; i < NExtra; i++) {
        deleteLastListDin(&l2, &temp);
        insertLastListDin(&l1, temp);
    }

    sortListDin(&l1, true);

    printf("Concat kedua ListDin secara terurut: ");displayListDin(l1);printf("\n");

    dealocateListDin(&l1);
    dealocateListDin(&l2);
}