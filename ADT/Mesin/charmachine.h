/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "../Boolean/boolean.h"
#include <stdio.h>

#define MARK_CHARMACHINE '\n'
/* Char Engine State */
extern char currentChar;
extern boolean eot;

void startChar();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void advChar();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void endChar();
/* Memberhentikan pembacaan Mesin Karakter. Pita tidak bisa lagi dibaca
   I.S. : Mesin Karakter sedang dijalankan
   F.S. : Mesin Karakter berhenti */

#endif