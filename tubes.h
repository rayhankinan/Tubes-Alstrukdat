/* File: tubes.h */
/* Definisi fungsi dan prosedur pada main program */

#include <stdio.h>
#include <stdlib.h>
#include "ADT/Boolean/boolean.h"
#include "ADT/Point/point.h"
#include "ADT/ListStatis/listpos.h"
#include "ADT/ListDinamis/listdin.h"
#include "ADT/Matrix/matrix.h"
#include "ADT/Mesin/wordmachine.h"
#include "ADT/Stack/stack.h"
#include "ADT/Queue/queue.h"
#include "ADT/LinkedList/list_linked.h"
#include "ADT/Mesin/wordmachinefile.h"
#include "ADT/Lokasi/lokasi.h"
#include "ADT/Item/item.h"
#include "ADT/Player/player.h"

/* Konstanta pada main program */
#define CAPACITY_INPUT 50

/* State awal pada main program (sudah terdefinisi dari pembacaan file) */
extern int N, M, L;
extern Lokasi HQ;
extern ListDin daftarBangunan;
extern Matrix adjacencyMatrix;
extern Queue daftarPesanan;

/* State berjalan pada main program (didefinisikan seiring berjalannya program) */
extern boolean hasWon;
extern Player Mobita;

void readQuery(Word *ptrQuery);
/* Membaca input string dari user */
/* I.S. Query bebas */
/* F.S. Query berisi string input user */

void writeQuery(Word *ptrQuery, char input[], int length);
/* Menuliskan string input ke dalam query */
/* I.S. : Query bebas */
/* F.S. : Query.contents berisi string input dengan query.length berisi integer length */

boolean compareQuery(Word query, Word value);
/* Mencari tahu apakah dua Word bernilai sama */

Word concatQuery(Word query1, Word query2);
/* Menggabungkan dua Word */

void mainMenu();
/* Menampilkan main menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada layar */

void readFileConfigNewGame(char namaFile[]);
/* Membaca file configuration  new game*/
/* I.S. : State pada main program bebas dan namaFile terdefinisi */
/* F.S. : State pada main program diisi dengan nilai sesuai dengan isi namaFile */

void readFileConfigLoadGame(char namaFile[]);
/* Membaca file configuration load game */
/* I.S. : State pada main program bebas dan namaFile terdefinisi */
/* F.S. : State pada main program diisi dengan nilai sesuai dengan isi namaFile */

void readNewGame();
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigNewGame kemudian melakukan pembacaan file */

void readLoadGame();
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfidLoadGame kemudian melakukan pembacaan file */

void gameMenu();
/* Menampikan game menu pada main program */
/* I.S. : Main menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output game menu pada layar */

void move();
/* Meminta lokasi tujuan player yang bisa diakses dari lokasi player, kemudian menggerakannya */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Lokasi player berubah sesuai input pengguna */