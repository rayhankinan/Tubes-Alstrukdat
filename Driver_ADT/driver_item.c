#include <stdio.h>
#include "../ADT/Item/item.h"
#include "../ADT/Point/point.h"

int main(){
    
    // KAMUS
    Lokasi currentlok, dropoff, latterlok;
    POINT currentpoint, droppoint, latterdroppoint;
    Item current, latter;

    // ALGORITMA
    // Membuat point untuk lokasi 
    currentpoint = MakePOINT(4,5);
    droppoint = MakePOINT(9,3);
    latterdroppoint = MakePOINT(10,2);

    // Mengisi Lokasi 
    currentlok  = CreateLokasi('A', currentpoint);
    dropoff = CreateLokasi('D', droppoint);
    latterlok = CreateLokasi('B', latterdroppoint);

    // Membuat Item
    current = CreateItem('P', currentlok,  dropoff,3);
    latter = CreateItem('N', currentlok, latterlok,4);

    // Mendisplay Item
    TulisItem(current);printf("\n");
    TulisItem(latter);printf("\n");
    /* Hasil yg benar: A -> D (Perishable Item, sisa waktu 3)
                       A -> B (Normal Item) */
    if (EQItem(current, current)){
        printf("Item current dan current sama\n");
    }
    if (EQItem(current, latter)){
        printf("Item current dan latter sama\n");
    }
    else{
        printf("Item current dan latter different\n");
    }
}