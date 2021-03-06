/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTPOS_H
#define LISTPOS_H

#include "../Boolean/boolean.h"
#include "../Mesin/wordmachinefile.h"
#include "../Mesin/writemachine.h"
#include <stdio.h>

/*  Kamus Umum */
#define CAPACITY_LISTPOS 5
/* Kapasitas penyimpanan */
#define IDX_UNDEF_LISTPOS -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF_LISTPOS -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElTypeListPos; /* type elemen List */
typedef struct {
  ElTypeListPos contents[CAPACITY_LISTPOS]; /* memori tempat penyimpan elemen (container) */
} ListPos;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListPos */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
      List kosong: semua elemen bernilai VAL_UNDEF
      Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT_LISTPOS(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListPos(ListPos l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListPos(ListPos l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListPos(ListPos l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListPos(ListPos l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListPos(ListPos *l);
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void displayListPos(ListPos l);
/* Proses : Menuliskan isi List dengan traversal pada layar, List ditulis tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: e1 e2 ... en */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: 1 20 30 */

void writeListPos(ListPos l);
/* Proses : Menuliskan isi List dengan traversal pada file config, List ditulis tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: e1 e2 ... en */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: 1 20 30 */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListPos(ListPos l, ElTypeListPos val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen pada slot kosong *** */
void insertFreeSlot(ListPos *l, ElTypeListPos val);
/* Proses: Menambahkan val pada elemen yang kosong */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pada slot kosong l yang baru */
/* *** Menambahkan elemen terakhir *** */
void insertLastListPos(ListPos *l, ElTypeListPos val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListPos(ListPos *l, ElTypeListPos *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

#endif