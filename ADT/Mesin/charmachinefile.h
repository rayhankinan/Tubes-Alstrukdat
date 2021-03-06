/* File: charmachinefile.h */
/* Definisi Character Engine untuk File */

#ifndef CHAR_ENGINE_FILE_H
#define CHAR_ENGINE_FILE_H

#include "../Boolean/boolean.h"
#include "charmachine.h"
#include <stdio.h>

/* Char Engine State*/
extern char currentCharFile;
extern boolean eotFile;

void startCharFile(char namaFile[]);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void advCharFile();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void endCharFile();
/* Memberhentikan pembacaan Mesin Karakter. Pita tidak bisa lagi dibaca
   I.S. : Mesin Karakter sedang dijalankan
   F.S. : Mesin Karakter berhenti */

#endif