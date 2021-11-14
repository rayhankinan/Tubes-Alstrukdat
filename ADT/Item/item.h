/* ADT Item */

#ifndef ITEM_H
#define ITEM_H

#include "../Boolean/boolean.h"
#include "../Mesin/wordmachinefile.h"
#include "../Lokasi/lokasi.h"
#include "../ListDinamis/listdin.h"
#include "../Player/player.h"

#define UNDEF_WAKTU -1
/* dipasangkan ke waktu jika bukan perishable item */

typedef struct item {
  int waktu_pick_up;  /* waktu item bisa di pick up */
  char jenis;    /* jenis item */
  Lokasi pick_up;  /* lokasi pick up */
  Lokasi drop_off; /* lokasi drop off */
  int waktu_hangus;     /* waktu item hangus (khusus perishable item) */
  int waktu_lewat; /* waktu yang diperlukan saat berkurang waktu perishable item */
} Item;

/* SELEKTOR */
#define WAKTU_PICK_UP_ITEM(x) (x).waktu_pick_up
#define JENIS_ITEM(x) (x).jenis
#define PICK_UP_ITEM(x) (x).pick_up
#define DROP_OFF_ITEM(x) (x).drop_off
#define WAKTU_HANGUS_ITEM(x) (x).waktu_hangus
#define WAKTU_LEWAT_ITEM(x) (x).waktu_lewat

/* KONSTRUKTOR */
Item CreateItem(char jenis, Lokasi pick_up, Lokasi drop_off, int waktu);
/* Membentuk sebuah Item dari komponen-komponennya */

/* BACA/TULIS */
void BacaItem(Item *I, ListDin daftarBangunan);
/* Membaca jenis, lokasi pick up, lokasi drop off, serta waktu hangus item (khusus perishable item)
   dan membentuk Item I berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : I sembarang */
/* F.S. : I terdefinisi */
void TulisItem(Item I, Player P);
/* Nilai I tertulis di layar dengan format <pick_up> -> <drop_off> (<jenis_item_translated>, <waktu_hangus jika perishable>) */
/* I.S. : I dan currentWaktu terdefinisi */
/* F.S. : I tertulis di layar sesuai dengan format */

/* Operasi Relasional */
boolean EQItem(Item I1, Item I2);
/* Mengirimkan true jika I1 = I2 : komponennya sama */

#endif