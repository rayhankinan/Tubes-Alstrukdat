/* ADT Player */

#ifndef PLAYER_H
#define PLAYER_H

#include "../Lokasi/lokasi.h"
#include "../Boolean/boolean.h"
#include <stdio.h>

typedef struct
{
  Lokasi loc; /* lokasi player */
  int uang;   /* uang player */
  int berat;  /* berat efek heavy item */
  boolean senterPengecil; /* apakah Player memiliki efek senter pengecil */
  boolean isSpeedBoost; /* apakah Player mendapat ability speed boost */
  int speedMove; /* jumlah pergerakan saat mendapat efek speedMove */
  int jumlahReturn; /* jumlah effect return item yang dimiliki */
  int waktu;  /* waktu berlalu setelah Player terdefinisi */
  int waktuTambah; /* waktu pengurangan perishable*/
  int jumlahAntar; /* jumlah item yang sudah diantarkan Player */
} Player;

/* SELEKTOR */
#define LOKASI_PLAYER(x) (x).loc
#define UANG_PLAYER(x) (x).uang
#define BERAT_PLAYER(x) (x).berat
#define SENTER_PENGECIL_PLAYER(x) (x).senterPengecil
#define SPEED_BOOST_PLAYER(x) (x).isSpeedBoost
#define SPEED_MOVE_PLAYER(x) (x).speedMove
#define JUMLAH_RETURN_PLAYER(x) (x).jumlahReturn
#define WAKTU_PLAYER(x) (x).waktu
#define WAKTU_TAMBAH_PLAYER(x) (x).waktuTambah
#define JUMLAH_ANTAR_PLAYER(x) (x).jumlahAntar

/* KONSTRUKTOR */
void CreatePlayer(Player* p, Lokasi lAwal);
/* Menghasilkan data player yang terdefinisi */
/* I.S. : p sembarang dan lAwal terdefinisi */
/* F.S. : p terdefinisi */

void movePlayer(Player* p, Lokasi l);
/* Mengubah koordinat lokasi Player sesuai input lokasi */
/* I.S. : p dan l terdefinisi */
/* F.S. : lokasi p berubah menjadi l */

void BacaPlayer(Player* p);
/* Membaca data karakteristik Player dari File Config */
/* I.S. : p sembarang */
/* F.S. : p terdefinisi dengan data File Config */

void WritePlayer(Player P);
/* Menulis data karakteristik Player dari File Config */
/* I.S. : p terdefinisi */
/* F.S. : p ditulis ke dalam File Config */

#endif
