/* File: writemachine.h */
/* Definisi Write Machine */

#ifndef WRITE_MACHINE_H
#define WRITE_MACHINE_H

#include "wordmachine.h"

#define MARK_WRITEMACHINE '\n'
#define BLANK_WRITEMACHINE ' '

void startFile(char namaFile[]);
/* Membuka File Tape */
/* I.S. : File Tape sembarang */
/* F.S. : File Tape terdefinisi dan bisa ditulis */

void writeLineFile(Word arrOfQuery[], int N);
/* Menulis satu baris pada File Tape */
/* I.S. : File Tape sudah terdefinisi */
/* F.S. : Menambah satu baris pada File Tape */

void endFile();
/* Menutup File Tape */
/* I.S. : File Tape terdefinisi */
/* F.S. : FIle Tape ditutup dan tidak bisa lagi ditulis */

#endif