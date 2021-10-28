/* File: tubes.c */
/* Implementasi fungsi dan prosedur pada main program */

#include "tubes.h"

void readQuery(Word *ptrQuery)
/* Membaca input string dari user */
/* I.S. query bebas */
/* F.S. query berisi string input user */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */

    startWord();
    writeQuery(ptrQuery, currentWord.contents, currentWord.length);
}

void writeQuery(Word *ptrQuery, char input[], int length)
/* Menuliskan string input ke dalam query */
/* I.S. : query bebas */
/* F.S. : query.contents berisi string input dengan query.length berisi integer length */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < length; i++) {
        ptrQuery->contents[i] = input[i];
    }
    ptrQuery->contents[length] = '\0';
    ptrQuery->length = length;
}

boolean compareQuery(Word query, Word value)
/* Mencari tahu apakah dua Word bernilai sama */
{
    /* KAMUS */
    boolean hasil;
    int i;

    /* ALGORITMA */
    hasil = query.length == value.length;

    i = 0;
    while (i < query.length && hasil) {
        hasil = query.contents[i] == value.contents[i];
        i++;
    }

    return hasil;
}

void mainMenu()
/* Menampilkan Main Menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada main program */
{
    /* KAMUS */
    Word input, quit;

    /* ALGORITMA */
    writeQuery(&quit, "QUIT", 4);

    do {
        printf("ENTER COMMAND: ");
        readQuery(&input);
        printf("%s\n", input);
    } while (!compareQuery(input, quit));
}