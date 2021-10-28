#include <stdio.h>
#include "player.h"

/* KONSTRUKTOR */
void CreatePlayer(Player *p, int uang, int berat, int effect, int waktu)
/* Menghasilkan data player yang terdefinisi */
{
  UANG(*p) = uang;
  BERAT(*p) = berat;
  EFFECT(*p) = effect;
  WAKTU(*p) = waktu;
  LOKASI_PLAYER(*p) = CreateLokasi('8', MakePOINT(0, 0));
}

void movePlayer(Player *p, Lokasi l)
/* Mengubah koordinat lokasi Player sesuai input lokasi */
{
  LOKASI_PLAYER(*p) = l;
}