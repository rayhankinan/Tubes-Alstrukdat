#include<stdio.h>
#include<stdio.h>
#include"../ADT/Queue/queue.h"

int main(){
    /* KAMUS */
    Queue q;
    int val, bany;
    ElTypeQueue trash, name;
    int idx, i;
    char initpickup, dropoff, tampung;
    int waktuawal,waktuhangus,xp,yp,xd,yd,tempnum;
    POINT tempp,tempd;
    Lokasi templokawal, templokakhir;   

    /*ALGORITMA*/
    CreateQueue(&q);

    // Mengecek jika empty
    if(isEmptyQueue(q)){
        printf("Queue kosong\n");
    }
    if(isFullQueue(q)){
        printf("Queue penuh\n");
    }else{
        printf("Queue tidak penuh\n");
    }
    printf("banyak elemen: %d\n", lengthQueue(q));

    // Memberikan status awal queue
    printf("indeks head & tail: %d & %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    printf("-------------------\n");
    printf("Jumlah elemen yang ingin di enqueue:");
    scanf("%d", &bany);
    initpickup = 'A';
    dropoff = 'B';
    waktuawal = 1;
    waktuhangus = 0;
    xp=0;
    yp=0;
    xd=0;
    yd=0;
    // enqueue items
    for(i=0; i<bany; i++){
        if (i%3 == 0) tampung = 'P';
        else if (i%4 == 0) tampung = 'V';
        else if (i%2 == 0) tampung = 'H';
        else if (i%1 == 0) tampung = 'N';
        else tampung = 'N';
        
        initpickup += 2; //bergeser 2 char di ascii
        dropoff += 2; //bergeser 2 char di ascii
        xp +=1; //mengisi koordinat sendiri
        yp +=2;
        xd +=3;
        yd +=4;
        if (initpickup>90 || dropoff>90 ){
            initpickup = initpickup-26;
            dropoff = dropoff-26;
        }
        tempp = MakePOINT(xp,yp);
        tempd = MakePOINT(xd,yd);
        templokawal = CreateLokasi(initpickup, tempp);
        templokakhir = CreateLokasi(dropoff, tempd);

        tempnum = 5;
        name = CreateItem(tampung, templokawal, templokakhir, tempnum);
        WAKTU_LEWAT_ITEM(name) = 0;
        enqueue(&q, name);
        printf("enqueue %d elemen:\n", i+1);
        displayQueue(q);printf("\n");

    }
    //Memberi tahu status queue
    printf("banyak elemen: %d\n", lengthQueue(q));
    printf("indeks head & tail: %d & %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
 
    //Deleting Items
    printf("-------------------\n"); printf("dequeue 1 elemen");
    dequeue(&q, &trash);
    printf("\nIsi queue: \n");
    displayQueue(q); printf("\n");
    printf("banyak elemen: %d\n", lengthQueue(q));
    printf("elemen yang dihapus: ");
    TulisItem(trash);printf("\n");
    printf("indeks head & tail: %d & %d yaitu...\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    TulisItem(HEAD_QUEUE(q));printf("\n");
    TulisItem(TAIL_QUEUE(q));printf("\n");
    for (int j = 0; j < 5; j++){
        dequeue(&q,&trash);
    }
    printf("----------------\n5 elemen dequeue dari barisan, \nindex top: %d\nindex tail: %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    return 0;
}