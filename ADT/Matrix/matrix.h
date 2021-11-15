/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef Matrix_H
#define Matrix_H

#include "../Boolean/boolean.h"
#include "../Mesin/wordmachinefile.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP_MATRIX 100
#define COL_CAP_MATRIX 100

typedef int IndexMatrix; /* Index baris, kolom */
typedef int ElTypeMatrix;
typedef struct
{
  ElTypeMatrix contents[ROW_CAP_MATRIX][COL_CAP_MATRIX];
  int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
  int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWS_MATRIX(M) (M).rowEff
#define COLS_MATRIX(M) (M).colEff
#define ELMT_MATRIX(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMatrix(int i, int j);
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IndexMatrix getLastIdxRowMatrix(Matrix m);
/* Mengirimkan Index baris terbesar m */
IndexMatrix getLastIdxColMatrix(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMatrix(Matrix m, IndexMatrix i, IndexMatrix j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayMatrix(Matrix m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
   1 2 3
   4 5 6
   8 9 10
   */
void writeMatrix(Matrix M);
#endif