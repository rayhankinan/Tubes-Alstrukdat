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

/* SELEKTOR */
#define JENIS(x) (x).jenis
#define PICK_UP(x) (x).pick_up
#define DROP_OFF(x) (x).drop_off
#define WAKTU_HANGUS(x) (x).waktu

#endif