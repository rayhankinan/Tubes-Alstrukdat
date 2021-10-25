/* ADT List Statis */

#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos* l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  for (i = 0; i < CAPACITY; i++) {
    ELMT(*l, i) = VAL_UNDEF;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  i = 0;
  while ((ELMT(l, i) != VAL_UNDEF) && (i < CAPACITY)) {
    i++;
  }
  return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return ((i >= 0) && (i < CAPACITY));
}

boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return((i >= 0) && (i < length(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return(length(l) == 0);
}

boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  return(length(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos* l)
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
  int n, E;
  int i;
  /* ALGORITMA */
  CreateListPos(l);
  do {
    scanf("%d", &n);
  } while ((n < 0) || (n > CAPACITY));

  for (i = 0; i < n; i++) {
    scanf("%d", &E);
    ELMT(*l, i) = E;
  }
}

void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
   /* I.S. l boleh kosong */
   /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
   /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
   /* Jika List kosong : menulis [] */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  printf("[");
  if (!isEmpty(l)) {
    printf("%d", ELMT(l, 0));
    for (i = 1; i < length(l); i++) {
      printf(", %d", ELMT(l, i));
    }
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
       /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
              elemen l2 pada indeks yang sama */
{
  /* KAMUS LOKAL */
  ListPos L;
  int i;
  /* ALGORITMA */
  CreateListPos(&L);
  for (i = 0; i < length(l1); i++) {
    if (plus == true) {
      ELMT(L, i) = ELMT(l1, i) + ELMT(l2, i);
    }
    else {
      ELMT(L, i) = ELMT(l1, i) - ELMT(l2, i);
    }
  }
  return L;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */
{
  /* KAMUS LOKAL */
  boolean flag;
  int i;
  ListPos LI1, LI2;
  /* ALGORITMA */
  flag = true;
  i = 0;
  LI1 = l1;
  LI2 = l2;
  sort(&LI1, true);
  sort(&LI2, true);
  if (length(LI1) == length(LI2)) {
    while ((flag == true) && (i < length(LI1))) {
      if (ELMT(LI1, i) != ELMT(LI2, i)) {
        flag = false;
      }
      i++;
    }
  }
  else { flag = false; }
  return flag;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
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
  hasil = IDX_UNDEF;
  i = 0;
  while ((!found) && (i < length(l))) {
    if (ELMT(l, i) == val) {
      hasil = i;
      found = true;
    }
    else { i++; }
  }
  return hasil;
}

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType* max, ElType* min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  *min = ELMT(l, 0);
  *max = ELMT(l, 0);
  for (i = 0; i < length(l); i++) {
    if (ELMT(l, i) > *max) {
      *max = ELMT(l, i);
    }
    if (ELMT(l, i) < *min) {
      *min = ELMT(l, i);
    }
  }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l)
/* Menghailkan true jika semua elemen l genap */
{
  /* KAMUS LOKAL */
  int i;
  boolean flag;
  /* ALGORITMA */
  i = 0;
  flag = true;
  if (!isEmpty(l)) {
    while ((flag == true) && (i < length(l))) {
      if (ELMT(l, i) % 2 != 0) {
        flag = false;
      }
      i++;
    }
  }
  else { flag = false; }
  return flag;
}

/* ********** SORTING ********** */
void sort(ListPos* l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
  /* KAMUS LOKAL */
  int i, j;
  int temp;

  /* ALGORITMA */
  // Skema bubble sort
  if (length(*l) > 1) {
    for (i = 0; i < length(*l) - 1; i++) {
      for (j = 0; j < length(*l) - 1 - i; j++) {
        if (asc == true) {
          if (ELMT(*l, j) > ELMT(*l, j + 1)) {
            temp = ELMT(*l, j);
            ELMT(*l, j) = ELMT(*l, j + 1);
            ELMT(*l, j + 1) = temp;
          }
        }
        else { //asc == false
          if (ELMT(*l, j) < ELMT(*l, j + 1)) {
            temp = ELMT(*l, j);
            ELMT(*l, j) = ELMT(*l, j + 1);
            ELMT(*l, j + 1) = temp;
          }
        }
      }
    }
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos* l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  ELMT(*l, length(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos* l, ElType* val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  *val = ELMT(*l, length(*l) - 1);
  ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}