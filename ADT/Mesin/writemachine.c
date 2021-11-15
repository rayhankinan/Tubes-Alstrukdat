/* ADT Mesin Tulis untuk File */

#include "writemachine.h"
#include <stdio.h>

static FILE *tapeFile;
static int retValWrite;

void startFile(char namaFile[])
{
    /* KAMUS */

    /* ALGORITMA */
    tapeFile = fopen(namaFile, "w");
}

void writeLineFile(Word arrOfQuery[], int N)
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
}

void endFile()
{
    /* KAMUS */

    /* ALGORITMA */
    fclose(tapeFile);
}