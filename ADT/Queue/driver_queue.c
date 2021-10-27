#include<stdio.h>
#include"queue.h"

int main(){
    Queue q;
    int val, i, bany, hasilPop;
    CreateQueue(&q);

    if(isEmptyQueue(q)){
        printf("Queue kosong\n");
    }

    if(isFullQueue(q)){
        printf("Queue penuh\n");
    }else{
        printf("Queue tidak penuh\n");
    }

    printf("banyak elemen: %d\n", lengthQueue(q));
    printf("isi queue: ");
    displayQueue(q); printf("\n");
    printf("indeks head & tail: %d & %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    printf("Head & Tail Queue: %d & %d\n", HEAD_QUEUE(q), TAIL_QUEUE(q));

    printf("-------------------\n");
    printf("Jumlah elemen yang ingin di enqueue:");
    scanf("%d", &bany);
    for(i=0; i<bany; i++){
        printf("nilai val : ");
        scanf("%d", &val);
        enqueue(&q, val);
    }
    printf("Isi queue: ");
    displayQueue(q); printf("\n");
    printf("banyak elemen: %d\n", lengthQueue(q));
    printf("indeks head & tail: %d & %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    printf("Head & Tail Queue: %d & %d\n", HEAD_QUEUE(q), TAIL_QUEUE(q));
    
    printf("-------------------\n"); printf("dequeue 1 elemen\n");
    dequeue(&q, &hasilPop);
    printf("Isi queue: ");
    displayQueue(q); printf("\n");
    printf("banyak elemen: %d\n", lengthQueue(q));
    printf("elemen yang dihapus: %d\n", hasilPop);
    printf("indeks head & tail: %d & %d\n", IDX_HEAD_QUEUE(q), IDX_TAIL_QUEUE(q));
    printf("Head & Tail Queue: %d & %d\n", HEAD_QUEUE(q), TAIL_QUEUE(q));

    return 0;
}