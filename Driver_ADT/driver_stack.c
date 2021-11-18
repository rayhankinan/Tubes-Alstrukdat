// driver ADT stack

#include<stdio.h>
#include "../ADT/Stack/stack.h"

int main(){
    /* KAMUS */
    Stack s;
    ElTypeStack items, trash;
    int idx, i;
    char initpickup, dropoff, tampung;
    int waktuawal, waktuhangus, xp, yp, xd, yd, tempnum;
    POINT tempp, tempd;
    Lokasi templokawal, templokakhir;
    /* ALGORITMA */

    // Membuat Stack
    CreateStack(&s);
    if(isEmptyStack(s)){
        printf("Stack kosong\n");
    }else{
        printf("Stack tidak kosong\n");
    }

    printf("index TOP:%d\n", IDX_TOP_STACK(s));

    // Membuat Item dan mengisi Stack
    initpickup = 'A';
    dropoff = 'B';
    waktuawal = 1;
    waktuhangus = 0;
    xp=0;
    yp=0;
    xd=0;
    yd=0;
    for (int i=0 ; i < 3; i++){
     
        if (i == 0) tampung = 'H';
        if (i == 1) tampung = 'N';
        if (i == 2) tampung = 'P';
        initpickup += 2; //bergeser 2 char di ascii
        dropoff += 2; //bergeser 2 char di ascii
        xp +=1; //mengisi koordinat sendiri
        yp +=2;
        xd +=3;
        yd +=4;

        tempp = MakePOINT(xp,yp);
        tempd = MakePOINT(xd,yd);
        templokawal = CreateLokasi(initpickup, tempp);
        templokakhir = CreateLokasi(dropoff, tempd);

        tempnum = 5;
        items = CreateItem(tampung, templokawal, templokakhir, tempnum);
        WAKTU_LEWAT_ITEM(items) = 0;
        pushStack(&s, items);
        printf("\nnama lokasi pickup: %c\n", NAMA_LOKASI(PICK_UP_ITEM(items)));

        displayStack(s);
        TulisLokasi(templokawal);printf("\n");
        TulisLokasi(templokakhir); printf("\n");
    }

    // Mengecek jika stack penuh
    if(isFullStack(s)){
        printf("\nStack penuh\n");
    }else{
        printf("Stack tidak penuh\n");
    }
    // Memainkan capacity stack
    printf("stack capacity initial: %d\n", CAPACITY_STACK(s));
    growStack(&s);
    printf("stack after capacity added: %d\n", CAPACITY_STACK(s));
    growDoubleStack(&s);
    printf("stack after capacity doubled: %d\n", CAPACITY_STACK(s));
    
    // Delete item di indeks tertentu
    printf("\nMasukkan idx stack yang mau dihapuskan(pasti valid): 1\n");
    deleteAtStack(&s, 1, &trash);
    printf("Item yang didelete: ");
    TulisItem(trash);printf("\n");

    displayStack(s);

    // tes update waktu di stack
    updateWaktuTimeTas(&s, 4);
    printf("\nmengurangkan waktu item semua perishable\n");
    displayStack(s);

    // tes update waktu pertama kalli ketemu perishble item stack
    printf("\nmengembalikan waktu perishable item teratas\n");
    kembalikanWaktuItemTas(&s);
    displayStack(s);
    return 0;
}