/* ADT Lokasi */

#ifndef LOKASI_H
#define LOKASI_H

#include "point.h"

typedef struct
{
  char nama;       /* nama karakter lokasi */
  POINT koordinat; /* koordinat lokasi */
} Lokasi;

/* SELEKTOR */
#define NAMA(x) (x).nama
#define KOORDINAT(x) (x).koordinat

#endif
