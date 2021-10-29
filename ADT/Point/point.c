/* ADT POINT */

#include <stdio.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    /* KAMUS */
    POINT P;

    /* ALGORITMA */
    Absis_POINT(P) = X;
    Ordinat_POINT(P) = Y;

    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */             
{
    /* KAMUS */

    /* ALGORITMA */
    advWordFile();
    Absis_POINT(*P) = wordToInt(currentWordFile);
    advWordFile();
    Ordinat_POINT(*P) = wordToInt(currentWordFile);
    advCharFile(); /* Membaca baris berikutnya */
    printf("%d %d\n", Absis_POINT(*P), Ordinat_POINT(*P)); /* TEST */
}                                    
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */    
{
    /* KAMUS */

    /* ALGORITMA */
    printf("(%d,%d)", Absis_POINT(P), Ordinat_POINT(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPOINT (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis_POINT(P1) == Absis_POINT(P2)) && (Ordinat_POINT(P1) == (Ordinat_POINT(P2))));
}