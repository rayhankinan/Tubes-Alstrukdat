/* File: tubes.h */
/* Definisi fungsi dan prosedur pada main program */

#include <stdio.h>
#include <stdlib.h>
#include "ADT/Point/point.h"
#include "ADT/ListStatis/listpos.h"
#include "ADT/ListDinamis/listdin.h"
#include "ADT/Matrix/matrix.h"
#include "ADT/Mesin/wordmachine.h"
#include "ADT/Stack/stack.h"
#include "ADT/Queue/queue.h"
#include "ADT/LinkedList/list_linked.h"
#include "ADT/Mesin/wordmachinefile.h"

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