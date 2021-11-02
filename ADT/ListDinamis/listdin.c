/* ADT List Dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin* l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
  /* ALGORITMA */
  CAPACITY_LISTDIN(*l) = capacity;
  BUFFER_LISTDIN(*l) = (ElTypeListDin*) malloc((capacity * sizeof(ElTypeListDin)));
  NEFF_LISTDIN(*l) = 0;
}

void dealocateListDin(ListDin* l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
  /* ALGORITMA */
  free(BUFFER_LISTDIN(*l));
  CAPACITY_LISTDIN(*l) = 0;
  NEFF_LISTDIN(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListDin(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
  /* ALGORITMA */
  return NEFF_LISTDIN(l);
}

/* *** Selektor INDEKS *** */
IdxTypeListDin getLastIdxListDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
  /* ALGORITMA */
  return (IdxTypeListDin) lengthListDin(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDin(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  /* ALGORITMA */
  return(i >= 0 && i < CAPACITY_LISTDIN(l));
}

boolean isIdxEffListDin(ListDin l, IdxTypeListDin i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
  /* ALGORITMA */
  return(i >= 0 && i < (IdxTypeListDin) lengthListDin(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDin(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
  /* ALGORITMA */
  return(lengthListDin(l) == 0);
}

/* *** Test list penuh *** */
boolean isFullListDin(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
  /* ALGORITMA */
  return(lengthListDin(l) == CAPACITY_LISTDIN(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
  /* KAMUS LOKAL */
  int i, L;
  Lokasi tempLoc;

  /* ALGORITMA */
  advWordFile();
  L = wordToInt(currentWordFile);
  advCharFile(); /* Membaca baris berikutnya */

  for (i = 0; i < L; i++) {
      if (isFullListDin(*l)) {
          growListDin(l, lengthListDin(*l));
      }
      BacaLokasi(&tempLoc);
      insertLastListDin(l, tempLoc);
  }
  compactListDin(l);
}

void displayListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
   /* I.S. l boleh kosong */
   /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
   /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
   /* Jika list kosong : menulis [] */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;
  
  /* ALGORITMA */
  for (i = 0; i < (IdxTypeListDin) lengthListDin(l); i++) {
    TulisLokasi(ELMT_LISTDIN(l, i));
    printf("\n");
  }
}

IdxTypeListDin indexOfListDin(ListDin l, ElTypeListDin val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
  /* KAMUS LOKAL */
  IdxTypeListDin hasil, i;
  boolean found;

  /* ALGORITMA */
  hasil = IDX_UNDEF_LISTDIN;
  found = false;
  i = 0;

  while (!found && i < (IdxTypeListDin) lengthListDin(l)) {
    if (EQLokasi(ELMT_LISTDIN(l, i), val)) {
      hasil = i;
      found = true;
    } else { i++; }
  }
  return hasil;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin* l, ElTypeListDin val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
  /* ALGORITMA */
  ELMT_LISTDIN(*l, (IdxTypeListDin) lengthListDin(*l)) = val;
  NEFF_LISTDIN(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDin(ListDin* l, ElTypeListDin* val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
  /* ALGORITMA */
  *val = ELMT_LISTDIN(*l, getLastIdxListDin(*l));
  NEFF_LISTDIN(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growListDin(ListDin* l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
  /* ALGORITMA */
  CAPACITY_LISTDIN(*l) += num;
  BUFFER_LISTDIN(*l) = (ElTypeListDin*) realloc(BUFFER_LISTDIN(*l), CAPACITY_LISTDIN(*l) * sizeof(ElTypeListDin));
}

void shrinkListDin(ListDin* l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
  /* ALGORITMA */
  CAPACITY_LISTDIN(*l) -= num;
  if (CAPACITY_LISTDIN(*l) < lengthListDin(*l))
  {
    NEFF_LISTDIN(*l) = CAPACITY_LISTDIN(*l);
  }
  BUFFER_LISTDIN(*l) = (ElTypeListDin*) realloc(BUFFER_LISTDIN(*l), CAPACITY_LISTDIN(*l) * sizeof(ElTypeListDin));
}

void compactListDin(ListDin* l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
  /* ALGORITMA */
  CAPACITY_LISTDIN(*l) = NEFF_LISTDIN(*l);
  BUFFER_LISTDIN(*l) = (ElTypeListDin*) realloc(BUFFER_LISTDIN(*l), CAPACITY_LISTDIN(*l) * sizeof(ElTypeListDin));
}