#include <stdio.h>
#include "../ADT/Matrix/matrix.h"

int main() {
    /* KAMUS */
    int m, n;
    Matrix m1, m2, temp;

    /* ALGORITMA */
    scanf("%d %d", &m, &n);
    readMatrix(&m1, m, n);
    printf("\n");

    scanf("%d %d", &m, &n);
    readMatrix(&m2, m, n);
    printf("\n");

    if (isEqualMatrix(m1, m2)) {
        printf("M1 = M2\n");
        printf("\n");
    }

    if (isIdentityMatrix(m1)) {
        printf("M1 adalah matriks identitas\n");
        printf("\n");
    }

    if (isIdentityMatrix(m2)) {
        printf("M2 adalah matriks identitas\n");
        printf("\n");
    }

    if (isSparseMatrix(m1)) {
        printf("M1 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSparseMatrix(m2)) {
        printf("M2 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSymmetricMatrix(m1)) {
        printf("M1 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSymmetricMatrix(m2)) {
        printf("M2 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSquareMatrix(m1)) {
        printf("Transpose M1 =\n");
        copyMatrix(m1, &temp);
        transposeMatrix(&temp);
        displayMatrix(temp);
        printf("\n\n");

        printf("Determinan M1 = %.2f\n", determinantMatrix(m1));
        printf("\n");
    }

    if (isSquareMatrix(m2)) {
        printf("Transpose M2 =\n");
        copyMatrix(m2, &temp);
        transposeMatrix(&temp);
        displayMatrix(temp);
        printf("\n\n");

        printf("Determinan M2 = %.2f\n", determinantMatrix(m2));
        printf("\n");
    }

    if (isEqualMatrix(m1, m2)) {
        printf("M1 + M2 =\n");
        displayMatrix(addMatrix(m1, m2));
        printf("\n\n");

        printf("M1 - M2 =\n");
        displayMatrix(subtractMatrix(m1, m2));
        printf("\n\n");
    }

    if (COLS_MATRIX(m1) == ROWS_MATRIX(m2)) {
        printf("M1 x M2 =\n");
        displayMatrix(multiplyMatrix(m1, m2));
        printf("\n\n");
    }
}