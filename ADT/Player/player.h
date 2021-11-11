/* ADT Player */

#ifndef PLAYER_H
#define PLAYER_H

#include "../Lokasi/lokasi.h"
#include "../Boolean/boolean.h"

typedef struct
{
  Lokasi loc; /* lokasi player */
  int uang;   /* uang player */
  int berat;  /* berat efek heavy item */
  boolean isSpeedBoost; /* apakah Player mendapat ability speed boost */
  int jumlahReturn; /* jumlah effect return item yang dimiliki */
  int waktu;  /* waktu berlalu setelah Player terdefinisi */
} Player;

/* SELEKTOR */
#define LOKASI_PLAYER(x) (x).loc
#define UANG_PLAYER(x) (x).uang
#define BERAT_PLAYER(x) (x).berat
#define SPEED_BOOST_PLAYER(x) (x).isSpeedBoost
#define JUMLAH_RETURN_PLAYER(x) (x).jumlahReturn
#define WAKTU_PLAYER(x) (x).waktu
#define PINTU_KEMANA_SAJA_PLAYER(x) (x).isKemanaSaja

/* KONSTRUKTOR */
void CreatePlayer(Player* p, Lokasi lAwal);
/* Menghasilkan data player yang terdefinisi */
/* I.S. : p sembarang dan lAwal terdefinisi */
/* F.S. : p terdefinisi */

void movePlayer(Player* p, Lokasi l);
/* Mengubah koordinat lokasi Player sesuai input lokasi */
/* I.S. : p dan l terdefinisi */
/* F.S. : lokasi p berubah menjadi l */

#endif
