#include <stdio.h>
#include "lokasi.h"

/* KONSTRUKTOR */
Lokasi CreateLokasi(char nama, POINT koordinat)
/* Membentuk lokasi dari char nama dan POINT koordinat */
{
  /* KAMUS */
  Lokasi L;

  /* ALGORITMA */
  NAMA_LOKASI(L) = nama;
  KOORDINAT_LOKASI(L) = koordinat;

  return L;
}

/* BACA/TULIS */
void BacaLokasi(Lokasi *L)
/* Membaca nama dan koordinat dari keyboard dan membentuk 
   Lokasi L berdasarkan dari nama tersebut */
/* Komponen nama dan koordinat dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: A 1 2 
   akan membentuk Lokasi <A, <1, 2>> */
/* I.S. L Sembarang */
/* F.S. L terdefinisi */
{
  /* KAMUS */

  /* ALGORITMA */
  advWordFile();
  NAMA_LOKASI(*L) = currentWordFile.contents[0];
  BacaPOINT(&KOORDINAT_LOKASI(*L));
}
void TulisLokasi(Lokasi L)
/* Nilai L dituliskan ke layar dengan format "<nama> (<absis point>, <ordinat point>)"
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "<nama> (<absis point>, <ordinat point>)" */
{
  /* KAMUS */

  /* ALGORITMA */
  printf("%c ", NAMA_LOKASI(L));
  TulisPOINT(KOORDINAT_LOKASI(L));
}

/* OPERASI RELASIONAL */
boolean EQLokasi(Lokasi L1, Lokasi L2)
/* Mengirimkan true jika L1 = L2 : nama dan koordinatnya sama */
{
  /* KAMUS */

  /* ALGORITMA */
  return ((NAMA_LOKASI(L1) == NAMA_LOKASI(L2)) && EQPOINT(KOORDINAT_LOKASI(L1), KOORDINAT_LOKASI(L2)));
}