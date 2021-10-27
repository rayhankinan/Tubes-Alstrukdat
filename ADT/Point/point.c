/* ADT POINT */

#include <stdio.h>
#include <math.h>
#include "point.h"

#define PI acos(-1)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
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
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    /* KAMUS */
    float X, Y;

    /* ALGORITMA */
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */    
{
    /* KAMUS */

    /* ALGORITMA */
    printf("(%.2f,%.2f)", Absis_POINT(P), Ordinat_POINT(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQPOINT (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis_POINT(P1) == Absis_POINT(P2)) && (Ordinat_POINT(P1) == (Ordinat_POINT(P2))));
}
boolean NEQPOINT (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis_POINT(P1) != Absis_POINT(P2)) || (Ordinat_POINT(P1) != Ordinat_POINT(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOriginPOINT (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((Absis_POINT(P) == 0) && (Ordinat_POINT(P) == 0));
}
boolean IsOnSbXPOINT (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Ordinat_POINT(P) == 0);
}
boolean IsOnSbYPOINT (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    return (Absis_POINT(P) == 0);
}
int KuadranPOINT (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    /* KAMUS */
    int Q;

    /* ALGORITMA */
    if ((Absis_POINT(P) > 0) && (Ordinat_POINT(P) > 0)) {
        Q = 1;
    } else if ((Absis_POINT(P) < 0) && (Ordinat_POINT(P) > 0)) {
        Q = 2;
    } else if ((Absis_POINT(P) < 0) && (Ordinat_POINT(P) < 0)) {
        Q = 3;
    } else {
        Q = 4;
    }
    return Q;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextXPOINT (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */   
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis_POINT(P) + 1, Ordinat_POINT(P));
    return P;
}           
POINT NextYPOINT (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis_POINT(P), Ordinat_POINT(P) + 1);
    return P;
}
POINT PlusDeltaPOINT (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    /* KAMUS */

    /* ALGORITMA */
    P = MakePOINT(Absis_POINT(P) + deltaX, Ordinat_POINT(P) + deltaY);
    return P;
}
POINT MirrorOfPOINT (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    if (SbX) {
        P = MakePOINT(Absis_POINT(P), -1 * Ordinat_POINT(P));
    } else {
        P = MakePOINT(-1 * Absis_POINT(P), Ordinat_POINT(P));
    }
    return P;
}
float Jarak0POINT (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    /* KAMUS */

    /* ALGORITMA */
    return sqrt((Absis_POINT(P) * Absis_POINT(P) + (Ordinat_POINT(P) * Ordinat_POINT(P))));
}
float PanjangPOINT (POINT P1, POINT P2)
/* Menghitung jarak dua point, yaitu antara P1 dengan P2 */
{
    /* KAMUS */

    /* ALGORITMA */
    return sqrt((Absis_POINT(P2) - Absis_POINT(P1)) * (Absis_POINT(P2) - Absis_POINT(P1)) + (Ordinat_POINT(P2) - Ordinat_POINT(P1)) * (Ordinat_POINT(P2) - Ordinat_POINT(P1)));
}
void GeserPOINT (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(Absis_POINT(*P) + deltaX, Ordinat_POINT(*P) + deltaY);
}
void GeserKeSbXPOINT (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(Absis_POINT(*P), 0);
}
void GeserKeSbYPOINT (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MakePOINT(0, Ordinat_POINT(*P));
}
void MirrorPOINT (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    /* KAMUS */

    /* ALGORITMA */
    *P = MirrorOfPOINT(*P, SbX);
}
void PutarPOINT (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    /* KAMUS */
    float sudutRadian;

    /* ALGORITMA */
    sudutRadian = -1 * Sudut * PI / 180; /* Jika diputar searah jarum jam, sudut akan menjadi negatif */
    *P = MakePOINT(Absis_POINT(*P) * cos(sudutRadian) - Ordinat_POINT(*P) * sin(sudutRadian), Absis_POINT(*P) * sin(sudutRadian) + Ordinat_POINT(*P) * cos(sudutRadian)); 
}