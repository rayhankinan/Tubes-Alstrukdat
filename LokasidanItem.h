/* Definisi ADT Lain */

#ifndef LOKASIITEM_H
#define LOKASIITEM_H

#include "point.h"
#define UNDEF -999 /* dipasangkan ke waktu jika bukan perishable item */

typedef struct
{
  char karakter;   /* karakter lokasi */
  POINT koordinat; /* koordinat lokasi */
} Lokasi;

typedef struct
{
  char jenis;    /* jenis item */
  char pick_up;  /* lokasi pick up */
  char drop_off; /* lokasi drop off */
  int waktu;     /* waktu item hangus (khusus perishable item) */
} Item;

#endif