#include <stdio.h>
#include "player.h"

/* KONSTRUKTOR */
void CreatePlayer(Player* p, Lokasi lAwal)
/* Menghasilkan data player yang terdefinisi */
/* I.S. : p sembarang dan lAwal terdefinisi */
/* F.S. : p terdefinisi */
{
  /* KAMUS */

  /* ALGORITMA  */
  UANG_PLAYER(*p) = 0;
  BERAT_PLAYER(*p) = 0;
  SPEED_BOOST_PLAYER(*p) = false;
  JUMLAH_RETURN_PLAYER(*p) = 0;
  WAKTU_PLAYER(*p) = 1;
  LOKASI_PLAYER(*p) = lAwal;
}

void movePlayer(Player *p, Lokasi l)
/* Mengubah koordinat lokasi Player sesuai input lokasi */
/* I.S. : p dan l terdefinisi */
/* F.S. : lokasi p berubah menjadi l */
{
  /* KAMUS */

  /* ALGORITMA */
  LOKASI_PLAYER(*p) = l;
}