#include "player.h"
#include <stdio.h>

/* KONSTRUKTOR */
void CreatePlayer(Player* p, Lokasi lAwal)
/* Menghasilkan data player yang terdefinisi */
/* I.S. : p sembarang dan lAwal terdefinisi */
/* F.S. : p terdefinisi */
{
  /* KAMUS */
  /* ALGORITMA  */
  LOKASI_PLAYER(*p) = lAwal;
  UANG_PLAYER(*p) = 0;
  BERAT_PLAYER(*p) = 0;
  SENTER_PENGECIL_PLAYER(*p) = false;
  SPEED_BOOST_PLAYER(*p) = false;
  SPEED_MOVE_PLAYER(*p) = 0;
  JUMLAH_RETURN_PLAYER(*p) = 0;
  WAKTU_PLAYER(*p) = 0;
  WAKTU_TAMBAH_PLAYER(*p) = 0;
  JUMLAH_ANTAR_PLAYER(*p) = 0;
}

void movePlayer(Player* p, Lokasi l)
/* Mengubah koordinat lokasi Player sesuai input lokasi */
/* I.S. : p dan l terdefinisi */
/* F.S. : lokasi p berubah menjadi l */
{
  /* KAMUS */

  /* ALGORITMA */
  LOKASI_PLAYER(*p) = l;
}

void BacaPlayer(Player* p)
/* Membaca data karakteristik Player dari File Config */
/* I.S. : p sembarang */
/* F.S. : p terdefinisi dengan data File Config */
{
  /* KAMUS */

  /* ALGORITMA */
  BacaLokasi(&LOKASI_PLAYER(*p));

  advWordFile();
  UANG_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  BERAT_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  SENTER_PENGECIL_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  SPEED_BOOST_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  SPEED_MOVE_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  JUMLAH_RETURN_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  WAKTU_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  WAKTU_TAMBAH_PLAYER(*p) = wordToInt(currentWordFile);

  advWordFile();
  JUMLAH_ANTAR_PLAYER(*p) = wordToInt(currentWordFile);

  advCharFile(); /* Membaca baris berikutnya */
}

void WritePlayer(Player P)
/* Menulis data karakteristik Player dari File Config */
/* I.S. : p terdefinisi */
/* F.S. : p ditulis ke dalam File Config */
{
  /* KAMUS */

  /* ALGORITMA */
  WriteLokasi(LOKASI_PLAYER(P));
  printfFile(" ");

  printfFile("%d %d %d %d %d %d %d %d %d\n", UANG_PLAYER(P), BERAT_PLAYER(P), SENTER_PENGECIL_PLAYER(P), SPEED_BOOST_PLAYER(P), SPEED_MOVE_PLAYER(P), JUMLAH_RETURN_PLAYER(P), WAKTU_PLAYER(P), WAKTU_TAMBAH_PLAYER(P), JUMLAH_ANTAR_PLAYER(P));

}