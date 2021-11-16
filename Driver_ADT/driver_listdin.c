//Driver ListDinamis elemen type lokasi

#include <stdio.h>
#include "../ADT/ListDinamis/listdin.h"

int main() {
    /* KAMUS */
    int NMax,x,y;
    ListDin l1,l2;
    ElTypeListDin templok, trash;
    IdxTypeListDin i,catch;
    POINT tempp;
    char bangunan;

    /* ALGORITMA */

    CreateListDin(&l2,4);

    // Pengecekan jika kosong atau tidak
    if (isEmptyListDin(l2)){
        printf("yes, listdin 2 kosong");
    }
    else{
        printf("listdin tidak kosong");
    }

    // Mengisi list dinamis baru
    printf("\nMasukkan jumlah maksimal elemen ListDin 1: ");
    scanf("%d", &NMax);
    CreateListDin(&l1, NMax);
    // Membuat lokasi
    x = 1;
    y = 2;
    bangunan = 'A';

    // insert jumlah elemen capacity listdin dari depan dan belakang
    for (int i = 0; i < NMax; i++){
        tempp = MakePOINT(x,y);
        templok = CreateLokasi(bangunan, tempp);
        insertLastListDin(&l1, templok);
        x+=1;
        y+=1;
        bangunan += 1;
        if (bangunan > 90){
            bangunan -= 26;
            x = 1;
            y = 2;
        }
    }

    printf("Masukkan ListDin pertama ada %d elemen:\n", lengthListDin(l1));
    displayListDin(l1);printf("\n\n");
    printf("index terakhir listdinamis adalah %d \n", getLastIdxListDin(l1));

    // Pengecekan index jika valid ata tidak
    printf("masukkan index yang valid: ");
    scanf("%d", &catch);
    if (isIdxValidListDin(l1, catch)){
        if (isIdxEffListDin(l1, catch)){
            printf("index is valid and effective\n");
        }
    } else {
        printf("index not valid\n");
    }

    // Pengecekan jika list full atau tidak
    if (isFullListDin(l1)){
        printf("list is full\n");
    } else {
        printf("list isn't full\n");
    }

    // Searching elemen tertentu dan mengembalikan indexnya
    printf("isi dari lokasi yang ingin dicari: "); TulisLokasi(templok);printf("\n");
    printf("lokasi templok berada di index: %d\n\n", indexOfListDin(l1, templok));

    // Deleting 
    printf("masukkan jumlah elemen yang  ingin dihapuskan: ");
    scanf("%d", &catch);
    for (int j = 0; j < catch ; j++){
        deleteLastListDin(&l1, &trash);
    }
    printf("\nelemen terakhir yang didelete adalah: ");
    TulisLokasi(trash);printf("\n");
    printf("\nisi list sekarang\n");
    displayListDin(l1);

    // Memainkan ukuran capacity list dinamis
    printf("\ncapacity listdin: %d", CAPACITY_LISTDIN(l1));
    growListDin(&l1, 4);
    printf("\ncapacity listdin setelah ditambah 4 ruang: %d\n", CAPACITY_LISTDIN(l1));
    shrinkListDin(&l1, 2);
    printf("capacity listdin setelah dikurang 2 ruang: %d\n", CAPACITY_LISTDIN(l1));
    compactListDin(&l1);
    printf("Capasitas list dinamis sekarang  setelah dicompact menjadi %d\n", CAPACITY_LISTDIN(l1));
    if (isFullListDin(l1)) printf("And it is full.\n");

    // Dealokasi list dinamis
    dealocateListDin(&l1);
    dealocateListDin(&l2);
}