#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Point/point.h"


int main() {
    /* KAMUS */
    POINT p1, p2, p3;

    /* ALGORITMA */
    // Membuat point
    p1 = MakePOINT(3,4);
    p2 = MakePOINT(12,5);
    p3 = MakePOINT(3,4);

    // Display point
    printf("Point 1: ");
    TulisPOINT(p1); printf("\n");
    printf("Point 2: ");
    TulisPOINT(p2); printf("\n");
    printf("Point 3: ");
    TulisPOINT(p3); printf("\n");

    // selektor
    printf("\n");
    printf("Absis p1: %d\n", Absis_POINT(p1));
    printf("Ordinat p1: %d\n", Ordinat_POINT(p1));

    // EQPoint
    printf("\n");
    if(EQPOINT(p1, p2)){
        printf("Point 1 sama dengan Point 2");
    }
    if(EQPOINT(p1, p3)){
        printf("Point 1 sama dengan Point 3");
    }
    if(!EQPOINT(p1,p2) && !EQPOINT(p1,p3)){
        printf("Point 1 tidak sama denga Point 2 dan 3");
    }
    return 0;
}