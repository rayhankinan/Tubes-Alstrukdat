/* File: tubes.h */
/* Definisi fungsi dan prosedur pada main program */

#include "ADT/Boolean/boolean.h"
#include "ADT/Item/item.h"
#include "ADT/LinkedList/list_linked.h"
#include "ADT/ListDinamis/listdin.h"
#include "ADT/ListStatis/listpos.h"
#include "ADT/Lokasi/lokasi.h"
#include "ADT/Matrix/matrix.h"
#include "ADT/Mesin/wordmachine.h"
#include "ADT/Mesin/wordmachinefile.h"
#include "ADT/Mesin/writemachine.h"
#include "ADT/Player/player.h"
#include "ADT/Point/point.h"
#include "ADT/Queue/queue.h"
#include "ADT/Stack/stack.h"
#include "ADT/PColor/pcolor.h"
#include <stdio.h>
#include <stdlib.h>

/* Konstanta pada main program */
#define CAPACITY_INPUT 50

/* State awal pada main program (sudah terdefinisi dari pembacaan file) */
extern int N, M;
extern Lokasi HQ;
extern ListDin daftarBangunan;
extern Matrix adjacencyMatrix;
extern Queue daftarPesanan;

/* State berjalan pada main program (didefinisikan seiring berjalannya program) */
extern boolean hasWon;
extern Player Mobita;
extern ListPos inventory, hargaGadget;
extern Stack tas;
extern ListLinked toDoList, progressList;

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

void printGadgetName(int id);
/* Menampilkan nama gadget sesuai dengan id gadget */
/* I.S. : id gadget terdefinisi */
/* I.F. : nama gadget tertulis ke dalam main program */

void updatePesanan();
/* Memasukkan pesanan dari daftar pesanan ke dalam to do list sesuai dengan waktu pesanan */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Pesanan masuk dari daftar pesanan ke dalam to do list */

void updateTas();
/* Mengurangi waktu Perishable Item pada Stack tas */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Waktu Perishable Item pada Stack Tas berkurang */

void updateProgressList();
/* Mengurangi waktu perishible item pada progress list */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Waktu Perishable Item pada progress list berkurang */

void shopMenu();
/* Menampilkan gadget yang dapat dibeli pada main program lalu Player membelinya */
/* I.S. : Keadaan awal main program bebas */
/* F.S. : Output player berhasil atau gagal membeli gadget dari toko dan    menyimpan gadget pada list inventory */

void activateEffect(int id);
/* Mengaktifkan efek gadget */

void inventoryMenu();
/* Menampilkan isi list inventory pada main program 
lalu player menggunakan gadget yang diinginkan */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output gadget berhasil atau gagal untuk digunakan lalu menghasilkan
efek gadget tersebut */

void moveMenu();
/* Meminta lokasi tujuan player yang bisa diakses dari lokasi player, kemudian menggerakannya */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Lokasi player berubah sesuai input pengguna */

void pickUpMenu();
/* Mengambil Item yang terletak di lokasi player */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Item ditambahkan ke dalam tas bila tas belum penuh */

void dropOffMenu();
/* Mengantarkan Item dari elemen teratas stack tas ke lokasi drop off */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Elemen teratas stack tas di drop off di lokasi */

void toDoListMenu();
/* Menampilkan Item yang bisa diambil */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output list Item yang bisa diambil pada map */

void inProgressMenu();
/* Menampilkan Item yang ada di dalam tas */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output list Item yang ada di dalam tas */

void returnMenu();
/* Mengecek apabila bisa mengembalikan item, dan restore it menjadi keadaan awal item tersebut lagi */
/*  I.S. : Cek ability player kalau punya ability untuk return, dan jenis item stack teratas bukan VIP Item */
/*  F.S. : Jika true, pesanan teratas kembali ke todo list terakhir (N,H), time limit pesanan reset sebelum dikembalikan ke todo list terakhir(P)  */

int findLoc(int i, int j);
/* Mencari indeks lokasi pada list dinamis berdasarkan koordinat (i,j) */

void map();
/* Menampilkan Map */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output Map berdasarkan file konfigurasi dengan kategori warnanya */

void helpMenu();
/* Menampilkan Help */
/* I.S. : Game menu sudah ditampilkan */
/* F.S. : Output Help Menu pada layar */

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

void writeFileConfig(char namaFile[]);
/* Menuliskan state program pada file configuration */
/* I.S. : State pada main program dan namaFile terdefinisi */
/* F.S. : File configuration diisi dengan nilai state program */

void readNewGame();
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigNewGame kemudian melakukan pembacaan file */

void readLoadGame();
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigLoadGame kemudian melakukan pembacaan file */

void saveGame();
/* Melakukan save state game pada file txt */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigLoadGame kemudian melakukan penulisan file */

void gameMenu();
/* Menampikan game menu pada main program */
/* I.S. : Main menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output game menu pada layar */