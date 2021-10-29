/* ADT Mesin Kata */

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

void stopWord()
/* Memberhentikan pembacaan Mesin Kata. Pita tidak bisa lagi dibaca
   I.S. : Mesin Kata sedang dijalankan
   F.S. : Mesin Kata berhenti */
{
    /* KAMUS */

    /* ALGORITMA */
    endChar();
}

int wordToInt(Word query)
/* Mengubah Word query menjadi integer */
{
    /* KAMUS */
    int i, hasil;

    /* ALGORITMA */
    hasil = 0;

    for (i = 0; i < query.length; i++) {
        hasil = 10 * hasil + (query.contents[i] - '0');
    }

    return hasil;
}

Word intToWord(int N)
/* Mengubah integer N menjadi Word */
{
    /* KAMUS */
    Word hasil;
    int divisor;

    /* ALGORITMA */
    hasil.length = 0;

    divisor = 1;
    while (N >= divisor) {
        divisor = divisor * 10;
    }
    divisor = divisor / 10;

    while (divisor > 0) {
        hasil.contents[hasil.length] = (N / divisor) + '0';
        
        N = N % divisor;
        divisor = divisor / 10;
        hasil.length++;
    }
    hasil.contents[hasil.length] = '\0';

    return hasil;
}