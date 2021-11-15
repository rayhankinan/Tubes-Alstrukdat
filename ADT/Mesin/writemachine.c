/* ADT Mesin Tulis untuk File */

#include "writemachine.h"
#include <stdio.h>

static FILE *tapeFile;
static int retValWrite;

void startFile(char namaFile[])
/* Membuka File Tape */
/* I.S. : File Tape sembarang */
/* F.S. : File Tape terdefinisi dan bisa ditulis */
{
    /* KAMUS */

    /* ALGORITMA */
    tapeFile = fopen(namaFile, "w");
}

void writeLineFile(Word arrOfQuery[], int N)
/* Menulis satu baris pada File Tape */
/* I.S. : File Tape sudah terdefinisi */
/* F.S. : Menambah satu baris pada File Tape */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < N; i++) {
        retValWrite = fprintf(tapeFile, "%s", arrOfQuery[i].contents);
        if (i < N - 1) {
            retValWrite = fprintf(tapeFile, "%c", BLANK_WRITEMACHINE);
        } else {
            retValWrite = fprintf(tapeFile, "%c", MARK_WRITEMACHINE);
        }
    }

    if (N == 0) { /* EMPTY LINE */
        retValWrite = fprintf(tapeFile, "%c", MARK_WRITEMACHINE);
    }
}

void endFile()
/* Menutup File Tape */
/* I.S. : File Tape terdefinisi */
/* F.S. : FIle Tape ditutup dan tidak bisa lagi ditulis */
{
    /* KAMUS */

    /* ALGORITMA */
    fclose(tapeFile);
}