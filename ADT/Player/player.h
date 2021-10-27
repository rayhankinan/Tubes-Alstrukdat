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
} Player;

/* SELEKTOR */
#define LOKASI_PLAYER(x) (x).loc
#define UANG(x) (x).uang
#define BERAT(x) (x).berat
#define EFFECT(x) (x).effect

#endif
