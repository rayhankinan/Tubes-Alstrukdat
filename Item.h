/* ADT Item */

#ifndef ITEM_H
#define ITEM_H

#define UNDEF_WAKTU -999
/* dipasangkan ke waktu jika bukan perishable item */

typedef struct
{
  char jenis;    /* jenis item */
  char pick_up;  /* lokasi pick up */
  char drop_off; /* lokasi drop off */
  int waktu;     /* waktu item hangus (khusus perishable item) */
} Item;

#endif