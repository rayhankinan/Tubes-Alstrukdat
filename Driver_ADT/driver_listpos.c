#include <stdio.h>
#include "../ADT/ListStatis/listpos.h"

int main() {
    /*KAMUS LOKAL*/
    ListPos l1;
    ElTypeListPos val;
    int indeks;

    /*ALGORITMA*/
    CreateListPos(&l1);

    // indeks valid
    if(isIdxValidListPos(l1, 5)){
        printf("5 adalah indeks valid untuk kapasitas list l1\n");
    }else{
        printf("5 bukan indeks valid untuk kapasitas list l1\n");
    }
    if(isIdxValidListPos(l1, 4)){
        printf("4 adalah indeks valid untuk kapasitas list l1\n");
    }else{
        printf("4 bukan indeks valid untuk kapasitas list l1\n");
    }
    
    //display list statis
    printf("-------------------------------------------\n");
    printf("Isi List: ");
    displayListPos(l1);
    printf("\n");
    printf("banyak elemen efektif l1: %d\n", lengthListPos(l1));
    if(isIdxEffListPos(l1, 0)){
        printf("0 indeks terdefinisi l1\n");
    }
    if(isEmptyListPos(l1)){
        printf("L1 kosong\n");
    }
    if(isFullListPos(l1)){
        printf("L1 penuh\n");
    }

    // Mengisi list
    printf("-------------------------------------------\n");
    printf("MENGISI LIST");
    insertFreeSlot(&l1, 5);
    insertLastListPos(&l1, 4);
    insertLastListPos(&l1, 3);

    //display list statis
    printf("Isi List: ");
    displayListPos(l1);
    printf("\n");
    printf("banyak elemen efektif l1: %d\n", lengthListPos(l1));
    if(isIdxEffListPos(l1, 0)){
        printf("0 indeks terdefinisi l1\n");
    }
    if(isEmptyListPos(l1)){
        printf("L1 kosong\n");
    }
    if(isFullListPos(l1)){
        printf("L1 penuh\n");
    }

    //Menghapus dan mengisi list dengan elemen lain
    printf("-------------------------------------------\n");
    deleteLastListPos(&l1, &val);
    printf("Menghapus elemen %d dari list.\n", val);
    deleteLastListPos(&l1, &val);
    printf("Menghapus elemen %d dari list.\n", val);
    deleteLastListPos(&l1, &val);
    printf("Menghapus elemen %d dari list.\n", val);
    printf("MENGISI LIST DENGAN ELEMEN BARU\n");
    insertLastListPos(&l1, 1);
    insertLastListPos(&l1, 2);
    insertLastListPos(&l1, 3);
    insertLastListPos(&l1, 4);
    insertLastListPos(&l1, 5);

    //display list statis
    printf("Isi List: ");
    displayListPos(l1);
    printf("\n");
    printf("banyak elemen efektif l1: %d\n", lengthListPos(l1));
    if(isIdxEffListPos(l1, 0)){
        printf("0 indeks terdefinisi l1\n");
    }
    if(isEmptyListPos(l1)){
        printf("L1 kosong\n");
    }
    if(isFullListPos(l1)){
        printf("L1 penuh\n");
    }

    // searching
    printf("-------------------------------------------\n");
    printf("Isi List: ");
    displayListPos(l1);
    printf("\n");
    val = 4;
    printf("indeks dari elemen bernilai %d adalah %d\n", val, indexOfListPos(l1, val));

    indeks = indexOfListPos(l1,val);
    printf("elemen list ke %d adalah: %d", indeks, ELMT_LISTPOS(l1,indeks));

    return 0;
}