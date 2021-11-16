/* ADT Mesin Tulis untuk File */

#include "writemachine.h"
#include <stdio.h>
#include <stdarg.h>

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

void printfFile(char format[], ...)
/* Menulis format pada file layaknya printf */
/* I.S. : File Tape sudah terdefinisi */
/* F.S. : Menulis string format pada File Tape */
{
    /* KAMUS */
    va_list args;

    /* ALGORITMA */
    va_start(args, format);
    vfprintf(tapeFile, format, args);
    va_end(args);
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