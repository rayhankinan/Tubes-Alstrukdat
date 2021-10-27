/* ADT Lokasi */

#ifndef LOKASI_H
#define LOKASI_H

#include "point.h"

typedef struct
{
  char karakter;   /* karakter lokasi */
  POINT koordinat; /* koordinat lokasi */
} Lokasi;

#endif