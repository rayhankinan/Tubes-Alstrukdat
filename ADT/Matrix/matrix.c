/* ADT Matrix */

#include "matrix.h"
#include <stdio.h>

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
  return (IndexMatrix)(ROWS_MATRIX(m) - 1);
}
IndexMatrix getLastIdxColMatrix(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
  /* KAMUS */

  /* ALGORITMA */
  return (IndexMatrix)(COLS_MATRIX(m) - 1);
}
boolean isIdxEffMatrix(Matrix m, IndexMatrix i, IndexMatrix j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
  /* KAMUS */

  /* ALGORITMA */
  return (i >= 0 && i <= getLastIdxRowMatrix(m) && j >= 0 && j <= getLastIdxColMatrix(m));
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
      advWordFile();
      ELMT_MATRIX(*m, i, j) = wordToInt(currentWordFile);
    }
    advCharFile(); /* Membaca baris berikutnya */
  }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
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
    printf("\n");
  }
}

  void writeMatrix(Matrix m){
    /* KAMUS */

  IndexMatrix i, j;

  /* ALGORITMA */
  for (i = 0; i <= getLastIdxRowMatrix(m); i++) {
    for (j = 0; j <= getLastIdxColMatrix(m); j++) {
      if (j < getLastIdxColMatrix(m)) {
        printfFile("%d ", length(ELMT_MATRIX(m, i, j)));
      } else {
        printfFile("%d ", length(ELMT_MATRIX(m, i, j)));
      }
    }
    printf("\n");
  }
}
