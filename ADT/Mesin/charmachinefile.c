/* ADT Mesin Karakter untuk File */

#include "charmachinefile.h"

char currentCharFile;
boolean eotFile;

static FILE *tapeFile;
static int retvalFile;

void startCharFile(char namaFile[])
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
  /* KAMUS */

  /* ALGORITMA */
  tapeFile = fopen(namaFile, "r");
  advCharFile();
}

void advCharFile()
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
  /* KAMUS */

  /* ALGORITMA */
  retvalFile = fscanf(tapeFile, "%c", &currentCharFile);
  eotFile = (currentCharFile == MARK_CHARMACHINE);
}

void endCharFile()
/* Memberhentikan pembacaan Mesin Karakter. Pita tidak bisa lagi dibaca
   I.S. : Mesin Karakter sedang dijalankan
   F.S. : Mesin Karakter berhenti */
{
  /* KAMUS */

  /* ALGORITMA */
  fclose(tapeFile);
}