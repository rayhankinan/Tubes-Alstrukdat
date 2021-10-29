/* ADT Mesin Kata untuk File */

#include "wordmachinefile.h"

boolean endWordFile;
Word currentWordFile;

void ignoreBlankWordFile()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    /* KAMUS */

    /* ALGORITMA */
    while (currentCharFile == BLANK_WORDMACHINE && currentCharFile != MARK_CHARMACHINE) {
        advCharFile();
    }
}

void startWordFile(char namaFile[])
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    /* KAMUS */

    /* ALGORITMA */
    startCharFile(namaFile);
    ignoreBlankWordFile();

    if (currentCharFile == MARK_CHARMACHINE) {
        endWordFile = true;
    } else {
        endWordFile = false;
        copyWordFile();
    }
}

void advWordFile()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
    /* KAMUS */

    /* ALGORITMA */
    ignoreBlankWordFile();
    
    if (currentCharFile == MARK_CHARMACHINE) {
        endWordFile = true;
    } else {
        copyWordFile();
    }
}

void copyWordFile()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    i = 0;

    while (currentCharFile != MARK_CHARMACHINE && currentCharFile != BLANK_WORDMACHINE) {
        if (i < CAPACITY_WORDMACHINE) {
            currentWordFile.contents[i] = currentCharFile;
        }
        advCharFile();
        i++;
    }

    if (i < CAPACITY_WORDMACHINE) {
        currentWordFile.length = i;
    } else {
        currentWordFile.length = CAPACITY_WORDMACHINE;
    }
}

void stopWordFile()
/* Memberhentikan pembacaan Mesin Kata. Pita tidak bisa lagi dibaca
   I.S. : Mesin Kata sedang dijalankan
   F.S. : Mesin Kata berhenti */
{
    /* KAMUS */

    /* ALGORITMA */
    endCharFile();
}