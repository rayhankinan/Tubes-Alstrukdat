/* File: tubes.h */
/* Definisi fungsi dan prosedur pada main program */

#include <stdio.h>
#include <stdlib.h>
#include "ADT/point.h"
#include "ADT/listpos.h"
#include "ADT/listdin.h"
#include "ADT/matrix.h"
#include "ADT/wordmachine.h"
#include "ADT/stack.h"
#include "ADT/queue.h"
#include "ADT/list_linked.h"
#include "ADT/wordmachinefile.h"

/* Konstanta pada main program */
#define CAPACITY_INPUT 50

void readQuery(char query[]);
/* Membaca input string dari user */
/* I.S. query bebas */
/* F.S. query berisi string input user */

void mainMenu();
/* Menampilkan Main Menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada main program */