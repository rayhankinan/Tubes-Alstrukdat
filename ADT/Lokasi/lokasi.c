#include <stdio.h>
#include "lokasi.h"

/* KONSTRUKTOR */
Lokasi CreateLokasi(char nama, POINT koordinat)
/* Membentuk lokasi */
{
  Lokasi l;
  NAMA(l) = nama;
  KOORDINAT(l) = koordinat;
  return l;
}