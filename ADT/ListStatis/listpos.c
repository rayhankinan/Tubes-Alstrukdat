/* ADT List Statis */

#include "listpos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  for (i = 0; i < CAPACITY_LISTPOS; i++) {
    ELMT_LISTPOS(*l, i) = VAL_UNDEF_LISTPOS;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  i = 0;
  while ((i < CAPACITY_LISTPOS) && (ELMT_LISTPOS(l, i) != VAL_UNDEF_LISTPOS)) {
    i++;
  }
  return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListPos(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return ((i >= 0) && (i < CAPACITY_LISTPOS));
}

boolean isIdxEffListPos(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return ((i >= 0) && (i < lengthListPos(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListPos(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return (lengthListPos(l) == 0);
}

boolean isFullListPos(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return (lengthListPos(l) == CAPACITY_LISTPOS);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
  /* KAMUS LOKAL */
  int i, N;
  ElTypeListPos X;

  /* ALGORITMA */
  CreateListPos(l);

  advWordFile();
  N = wordToInt(currentWordFile);
  advCharFile(); /* Membaca baris berikutnya */

  if (N > 0) {
    for (i = 0; i < N; i++) {
      advWordFile();
      X = wordToInt(currentWordFile);
      insertLastListPos(l, X);
    }
    advCharFile(); /* Membaca baris berikutnya */
  }
}

void displayListPos(ListPos l)
/* Proses : Menuliskan isi List dengan traversal pada layar, List ditulis tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: e1 e2 ... en */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: 1 20 30 */
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  if (!isEmptyListPos(l)) {
    for (i = 0; i < lengthListPos(l); i++) {
      if (i < lengthListPos(l) - 1) {
        printf("%d ", ELMT_LISTPOS(l, i));
      } else {
        printf("%d", ELMT_LISTPOS(l, i));
      }
    }
  }
}

void writeListPos(ListPos l)
/* Proses : Menuliskan isi List dengan traversal pada file config, List ditulis tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: e1 e2 ... en */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: 1 20 30 */
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  printfFile("%d\n", lengthListPos(l));

  for (i = 0; i < lengthListPos(l); i++) {
    if (i < lengthListPos(l) - 1) {
      printfFile("%d ", ELMT_LISTPOS(l, i));
    } else {
      printfFile("%d\n", ELMT_LISTPOS(l, i));
    }
  }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListPos(ListPos l, ElTypeListPos val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
  /* KAMUS LOKAL */
  int hasil;
  int i;
  boolean found;
  /* ALGORITMA */
  hasil = IDX_UNDEF_LISTPOS;
  i = 0;
  found = false;
  while ((!found) && (i < lengthListPos(l))) {
    if (ELMT_LISTPOS(l, i) == val) {
      hasil = i;
      found = true;
    } else {
      i++;
    }
  }
  return hasil;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen pada slot kosong *** */
void insertFreeSlot(ListPos *l, ElTypeListPos val)
/* Proses: Menambahkan val pada elemen yang kosong */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pada slot kosong l yang baru */
{
  /* KAMUS LOKAL */
  boolean found;
  int i;
  /* ALGORITMA */
  i = 0;
  found = false;
  while (!found) {
    if (ELMT_LISTPOS(*l, i) == VAL_UNDEF_LISTPOS) {
      ELMT_LISTPOS(*l, i) = val;
      found = true;
    } else {
      i++;
    }
  }
}

/* *** Menambahkan elemen terakhir *** */
void insertLastListPos(ListPos *l, ElTypeListPos val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  ELMT_LISTPOS(*l, lengthListPos(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListPos(ListPos *l, ElTypeListPos *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  *val = ELMT_LISTPOS(*l, lengthListPos(*l) - 1);
  ELMT_LISTPOS(*l, lengthListPos(*l) - 1) = VAL_UNDEF_LISTPOS;
}