/* File: tubes.c */
/* Implementasi fungsi dan prosedur pada main program */

#include "tubes.h"

void readQuery(char query[])
/* Membaca input string dari user */
/* I.S. query bebas */
/* F.S. query berisi string input user */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    startWord();

    for (i = 0; i < currentWord.length; i++) {
        query[i] = currentWord.contents[i];
    }
    query[currentWord.length] = '\0';
}

void mainMenu()
/* Menampilkan Main Menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada main program */
{
    /* KAMUS */
    char input[CAPACITY_INPUT];

    /* ALGORITMA */
    readQuery(input);
    readQuery(input);
    readQuery(input);
    readQuery(input);
}