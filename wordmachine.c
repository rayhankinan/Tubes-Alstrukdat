/* File: charmachine.c */
/* Implementasi Word Engine */

#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlankWord()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    /* KAMUS */

    /* ALGORITMA */
    while (currentChar == BLANK_WORDMACHINE && currentChar != MARK_CHARMACHINE) {
        advChar();
    }
}

void startWord()
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    /* KAMUS */

    /* ALGORITMA */
    startChar();
    ignoreBlankWord();

    if (currentChar == MARK_CHARMACHINE) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
}

void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
    /* KAMUS */

    /* ALGORITMA */
    ignoreBlankWord();
    
    if (currentChar == MARK_CHARMACHINE) {
        endWord = true;
    } else {
        copyWord();
        ignoreBlankWord();
    }
}

void copyWord()
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

    while (currentChar != MARK_CHARMACHINE && currentChar != BLANK_WORDMACHINE) {
        if (i < CAPACITY_WORDMACHINE) {
            currentWord.contents[i] = currentChar;
        }
        advChar();
        i++;
    }

    if (i < CAPACITY_WORDMACHINE) {
        currentWord.length = i;
    } else {
        currentWord.length = CAPACITY_WORDMACHINE;
    }
}