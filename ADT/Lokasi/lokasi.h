/* ADT Lokasi */

#ifndef LOKASI_H
#define LOKASI_H

#include "../Boolean/boolean.h"
#include "../Mesin/wordmachinefile.h"
#include "../Point/point.h"
#include "../Mesin/writemachine.h"

typedef struct
{
  char nama; /* nama karakter lokasi */
  POINT koordinat; /* koordinat lokasi */
} Lokasi;

/* SELEKTOR */
#define NAMA_LOKASI(x) (x).nama
#define KOORDINAT_LOKASI(x) (x).koordinat

/* KONSTRUKTOR */
Lokasi CreateLokasi(char nama, POINT koordinat);
/* Membentuk lokasi dari char nama dan POINT koordinat */

/* BACA/TULIS */
void BacaLokasi(Lokasi *L);
/* Membaca nama dan koordinat dari keyboard dan membentuk
   Lokasi L berdasarkan dari nama tersebut */
/* Komponen nama dan koordinat dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: A 1 2
      akan membentuk Lokasi <A, <1, 2>> */
/* I.S. L Sembarang */
/* F.S. L terdefinisi */
void TulisLokasi(Lokasi L);
/* Nilai L dituliskan ke layar dengan format "<nama> (<absis point>, <ordinat point>)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "<nama> (<absis point>, <ordinat point>)" */
void WriteLokasi(Lokasi L);
/* Nilai L dituliskan ke file config dengan format "<nama_lokasi> <absis_lokasi> <ordinat_lokasi>"
   tanpa spasi, enter, atau karakter lain di depan, belakang.
   atau di antaranya */
/* I.S. L terdefinisi */
/* F.S. L tertulis di file config dengan format "<nama_lokasi> <absis_lokasi> <ordinat_lokasi>" */

/* OPERASI RELASIONAL */
boolean EQLokasi(Lokasi L1, Lokasi L2);
/* Mengirimkan true jika L1 = L2 : nama dan koordinatnya sama */

#endif
