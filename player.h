/* ADT Player */

#ifndef PLAYER_H
#define PLAYER_H

#include "lokasi.h"

typedef struct
{
  char nama;       /* nama karakter lokasi */
  POINT koordinat; /* koordinat lokasi */
} Lo;

/* SELEKTOR */
#define NAMA(x) (x).nama
#define KOORDINAT(x) (x).koordinat

#endif
