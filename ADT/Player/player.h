/* ADT Player */

#ifndef PLAYER_H
#define PLAYER_H

#include "../Lokasi/lokasi.h"

typedef struct
{
  Lokasi loc; /* lokasi player */
  int uang;   /* uang player */
  int berat;  /* berat efek heavy item */
  int effect; /* effect item yang berlangsung */
  int waktu;  /* waktu berlalu setelah Player terdefinisi */
} Player;

/* SELEKTOR */
#define LOKASI_PLAYER(x) (x).loc
#define UANG(x) (x).uang
#define BERAT(x) (x).berat
#define EFFECT(x) (x).effect
#define WAKTU(x) (x).waktu

/* KONSTRUKTOR */
void CreatePlayer(Player *p, int uang, int berat, int effect, int waktu);
/* Menghasilkan data player yang terdefinisi */

void movePlayer(Player *p, Lokasi l);
/* Mengubah koordinat lokasi Player sesuai input lokasi */

#endif
