#include <stdio.h>
#include "../ADT/Matrix/matrix.h"

int main() {
    /* KAMUS */
    int i, j;
    ElTypeMatrix elmn;
    Matrix m1, m2;

    /* ALGORITMA */
    // Membuat matriks
    CreateMatrix(3, 3, &m1);
    CreateMatrix(4, 3, &m2);

    // Mengisi matriks
    elmn = 1;
    for(i=0; i < 3; i++){
        for(j=0; j < 3; j++){
            ELMT_MATRIX(m1, i, j) = elmn;
            elmn++;
        }
    }
    
    elmn = 9;
    for(i=0; i < 4; i++){
        for(j=0; j < 3; j++){
            ELMT_MATRIX(m2, i, j) = elmn;
            elmn++;
        }
    }

    // Display matriks
    printf("Matriks m1:\n");
    displayMatrix(m1);
    printf("Matriks m2:\n");
    displayMatrix(m2);

    //Indeks Valid Matriks
    printf("\n");
    if(isIdxValidMatrix(101,101)){
        printf("101 x 101 indeks valid untuk semua matriks\n");
    }else{
        printf("101 x 101 bukan indeks valid untuk semua matriks\n");    
    }

    if(isIdxValidMatrix(99,99)){
        printf("100 x 100 indeks valid untuk semua matriks\n");
    }else{
        printf("100 x 100 bukan indeks valid untuk semua matriks\n");    
    }

    // indeks baris dan kolom terbesar matriks
    printf("\n");
    printf("indeks baris terbesar m1: %d\n", getLastIdxRowMatrix(m1));
    printf("indeks kolom terbesar m1: %d\n", getLastIdxColMatrix(m1));
    printf("indeks baris terbesar m2: %d\n", getLastIdxRowMatrix(m2));
    printf("indeks kolom terbesar m2: %d\n", getLastIdxColMatrix(m2));

    // indeks efektif matriks
    printf("\n");
    if(isIdxEffMatrix(m1, 3, 3)){
        printf("3 x 3 indeks valid untuk matriks m1\n");
    }else{
        printf("3 x 3 bukan indeks valid untuk matriks m1\n");    
    }

    if(isIdxEffMatrix(m1, 2, 2)){
        printf("2 x 2 indeks valid untuk untuk matriks m1\n");
    }else{
        printf("2 x 2 bukan indeks valid untuk matriks m1\n");    
    }

    //selektor
    printf("\n");
    printf("banyak ukuran baris m1 yang teredefinisi %d\n", ROWS_MATRIX(m1));
    printf("banyak ukuran kolom m1 yang teredefinisi %d\n", COLS_MATRIX(m1));
    printf("Elemen pada baris 0 kolom 0 m1: %d\n", ELMT_MATRIX(m1, 0, 0));
    return 0;
}