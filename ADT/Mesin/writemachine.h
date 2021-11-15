/* File: writemachine.h */
/* Definisi Write Machine */

#ifndef WRITE_MACHINE_H
#define WRITE_MACHINE_H

#include "wordmachine.h"

#define MARK_WRITEMACHINE '\n'
#define BLANK_WRITEMACHINE ' '

void startFile(char namaFile[]);

void writeLineFile(Word arrOfQuery[], int N);

void endFile();

#endif