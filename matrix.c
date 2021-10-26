/* ADT Matrix */

#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    /* KAMUS */

    /* ALGORITMA*/
    ROWS_MATRIX(*m) = nRow;
    COLS_MATRIX(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMatrix(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROW_CAP_MATRIX && j >= 0 && j < COL_CAP_MATRIX);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IndexMatrix getLastIdxRowMatrix(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IndexMatrix) (ROWS_MATRIX(m) - 1);
}
IndexMatrix getLastIdxColMatrix(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IndexMatrix) (COLS_MATRIX(m) - 1);
}
boolean isIdxEffMatrix(Matrix m, IndexMatrix i, IndexMatrix j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i <= getLastIdxRowMatrix(m) && j >= 0 && j <= getLastIdxColMatrix(m));
}
ElTypeMatrix getElmtDiagonalMatrix(Matrix m, IndexMatrix i)
/* Mengirimkan elemen m(i,i) */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ELMT_MATRIX(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    /* KAMUS */
    IndexMatrix i, j;

    /* ALGORITMA */
    CreateMatrix(ROWS_MATRIX(mIn), COLS_MATRIX(mIn), mRes);

    for (i = 0; i <= getLastIdxRowMatrix(mIn); i++) {
        for (j = 0; j <= getLastIdxColMatrix(mIn); j++){
            ELMT_MATRIX(*mRes, i, j) = ELMT_MATRIX(mIn, i, j); 
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    /* KAMUS */
    IndexMatrix i, j;

    /* ALGORITMA */
    CreateMatrix(nRow, nCol, m);

    for (i = 0; i <= getLastIdxRowMatrix(*m); i++) {
        for (j = 0; j <= getLastIdxColMatrix(*m); j++) {
            scanf("%d", &ELMT_MATRIX(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS */
    IndexMatrix i, j;

    /* ALGORITMA */
    for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            if (j < getLastIdxColMatrix(m)) {
                printf("%d ", ELMT_MATRIX(m, i, j));
            } else {
                printf("%d", ELMT_MATRIX(m, i, j));
            }
        }
        if (i < getLastIdxRowMatrix(m)){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    /* KAMUS */
    IndexMatrix i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS_MATRIX(m1), COLS_MATRIX(m1), &m);

    for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            ELMT_MATRIX(m, i, j) = ELMT_MATRIX(m1, i, j) + ELMT_MATRIX(m2, i, j);
        }
    }
    
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    /* KAMUS */
    IndexMatrix i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS_MATRIX(m1), COLS_MATRIX(m1), &m);

    for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            ELMT_MATRIX(m, i, j) = ELMT_MATRIX(m1, i, j) - ELMT_MATRIX(m2, i, j);
        }
    }
    
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    /* KAMUS */
    IndexMatrix i, j, k;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS_MATRIX(m1), COLS_MATRIX(m2), &m);

    for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            ELMT_MATRIX(m, i, j) = 0;
            for (k = 0; k <= getLastIdxColMatrix(m1); k++) {
                ELMT_MATRIX(m, i, j) += ELMT_MATRIX(m1, i, k) * ELMT_MATRIX(m2, k, j);
            }
        }
    }

    return m;
}
Matrix multiplyConstMatrix(Matrix m, ElTypeMatrix x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    /* KAMUS */
    IndexMatrix i, j;
    Matrix mHasil;

    /* ALGORITMA */
    CreateMatrix(ROWS_MATRIX(m), COLS_MATRIX(m), &mHasil);

    for (i = 0; i <= getLastIdxRowMatrix(mHasil); i++) {
        for (j = 0; j <= getLastIdxColMatrix(mHasil); j++) {
            ELMT_MATRIX(mHasil, i, j) = x * ELMT_MATRIX(m, i, j);
        }
    }

    return mHasil;
}
void pMultiplyConstMatrix(Matrix *m, ElTypeMatrix k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    /* KAMUS */

    /* ALGORITMA */
    copyMatrix(multiplyConstMatrix(*m, k), m);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMatrix(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    /* KAMUS */
    IndexMatrix i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSizeEqualMatrix(m1, m2)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRowMatrix(m1)) && hasil) {
            j = 0;
            while ((j <= getLastIdxColMatrix(m1)) && hasil) {
                hasil = (ELMT_MATRIX(m1, i, j) == ELMT_MATRIX(m2, i, j));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isNotEqualMatrix(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isEqualMatrix(m1, m2));
}
boolean isSizeEqualMatrix(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((getLastIdxRowMatrix(m1) == getLastIdxRowMatrix(m2)) && (getLastIdxColMatrix(m1) == getLastIdxColMatrix(m2)));
}

/* ********** Operasi lain ********** */
int countMatrix(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS_MATRIX(m) * COLS_MATRIX(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquareMatrix(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return (ROWS_MATRIX(m) == COLS_MATRIX(m));
}
boolean isSymmetricMatrix(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    /* KAMUS */
    IndexMatrix i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSquareMatrix(m)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRowMatrix(m)) && hasil) {
            j = 0;
            while ((j <= getLastIdxColMatrix(m)) && hasil) {
                hasil = (ELMT_MATRIX(m, i, j) == ELMT_MATRIX(m, j, i));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isIdentityMatrix(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    /* KAMUS */
    IndexMatrix i, j;
    boolean hasil;

    /* ALGORITMA */
    hasil = true;

    if (!isSquareMatrix(m)) {
        hasil = false;
    } else {
        i = 0;
        while ((i <= getLastIdxRowMatrix(m)) && hasil) {
            j = 0;
            while ((j <= getLastIdxColMatrix(m)) && hasil) {
                hasil = ((i != j || ELMT_MATRIX(m, i, j) == 1) && (i == j || ELMT_MATRIX(m, i, j) == 0));
                j++;
            }
            i++;
        }
    }

    return hasil;
}
boolean isSparseMatrix(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /* KAMUS */
    IndexMatrix i, j;
    double maksMemory, curMemory;

    /* ALGORITMA */
    maksMemory = ((double) countMatrix(m)) * 0.05;
    curMemory = 0;

    i = 0;
    while ((i <= getLastIdxRowMatrix(m)) && (curMemory <= maksMemory)) {
        j = 0;
        while ((j <= getLastIdxColMatrix(m)) && (curMemory <= maksMemory)) {
            if (ELMT_MATRIX(m, i, j) != 0) {
                curMemory += 1;
            }
            j++;
        }
        i++;
    }

    return (curMemory <= maksMemory);
}
Matrix inverse1Matrix(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    /* KAMUS */

    /* ALGORITMA */
    return multiplyConstMatrix(m, -1);
}
void pInverse1Matrix(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    /* KAMUS */

    /* ALGORITMA */
    pMultiplyConstMatrix(m, -1);
}
float cofactorMatrix(Matrix m, IndexMatrix a, IndexMatrix b)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai kofaktor m pada baris i dan kolom j */
{
    /* KAMUS */
    IndexMatrix i, j, iHasil, jHasil;
    Matrix mHasil;
    float hasil;

    /* ALGORITMA */
    hasil = 0;
    CreateMatrix(ROWS_MATRIX(m) - 1, COLS_MATRIX(m) - 1, &mHasil);

    iHasil = 0;
    for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
        jHasil = 0;
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            if (i == a) {
                iHasil = i - 1;
            } else if (j == b) {
                jHasil = j - 1;
            } else {
                ELMT_MATRIX(mHasil, iHasil, jHasil) = ELMT_MATRIX(m, i, j);
            }
            jHasil++;
        }
        iHasil++;
    }

    if ((a + b) % 2 == 0) {
        hasil = determinantMatrix(mHasil);
    } else {
        hasil = -1 * determinantMatrix(mHasil);
    }

    return hasil;
}
float determinantMatrix(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    /* KAMUS */
    IndexMatrix i, j;
    float hasil;

    /* ALGORITMA */
    hasil = 0;

    if (countMatrix(m) == 1) { /* Dikarenakan matriks persegi maka tidak perlu membuat matriks baru */
        hasil = (float) ELMT_MATRIX(m, 0, 0);
    } else {
        i = 0;
        for (j = 0; j <= getLastIdxColMatrix(m); j++) {
            hasil += ((float) ELMT_MATRIX(m, i, j)) * cofactorMatrix(m, i, j);
        }
    }

    return hasil;
}
void transposeMatrix(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    /* KAMUS */
    IndexMatrix i, j;
    ElTypeMatrix temp;

    /* ALGORITMA */

    for (i = 0; i <= getLastIdxRowMatrix(*m); i++) { /* Dikarenakan matriks persegi maka tidak perlu membuat matriks baru */
        for (j = i; j <= getLastIdxColMatrix(*m); j++) {
            temp = ELMT_MATRIX(*m, i, j);
            ELMT_MATRIX(*m, i, j) = ELMT_MATRIX(*m, j, i);
            ELMT_MATRIX(*m, j, i) = temp;
        }
    }
}