// driver ADT stack

#include<stdio.h>
#include"../ADT/Stack/stack.h"

int main(){
    /* KAMUS */
    Stack s;
    ElTypeStack val1, valPop;
    int jumlahElemen, i;

    /* ALGORITMA */
    CreateStack(&s);
    if(isEmptyStack(s)){
        printf("Stack kosong\n");
    }else{
        printf("Stack tidak kosong\n");
    }

    printf("index TOP:%d\n", IDX_TOP_STACK(s));

    if(isFullStack(s)){
        printf("Stack penuh\n");
    }else{
        printf("Stack tidak penuh\n");
    }
    

    printf("Masukkan jumlah elemen yang ingin di push: ");
    scanf("%d", &jumlahElemen);

    for (i=0; i < jumlahElemen; i++){
        printf("elemen ke %d : ", (i+1));
        scanf("%d", &val1);
        pushStack(&s, val1);
    }

    printf("Elemen TOP dan index TOP: %d & %d\n", TOP_STACK(s), IDX_TOP_STACK(s));

    printf("-------------------------\n");
    printf("Dilakukan Pop sekali: \n");
    popStack(&s, &valPop);
    printf("Elemen TOP dan index TOP: %d & %d\n", TOP_STACK(s), IDX_TOP_STACK(s));
    printf("Elemen TOP yang lama: %d", valPop);
    
















    return 0;
}