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
  return (IdxTypeListDin) (NEFF_LISTDIN(l) - 1);
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
void readListDin(ListDin* l)
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
  ElTypeListDin x;
  IdxTypeListDin i;
  int N;

  /* ALGORITMA */
  do { scanf("%d", &N); } while (N < 0 || N > CAPACITY_LISTDIN(*l));

  for (i = 0; i < (IdxTypeListDin) N; i++)
  {
    scanf("%d", &x);
    ELMT_LISTDIN(*l, i) = x;
  }
  NEFF_LISTDIN(*l) = N;
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
  printf("[");
  if (!isEmptyListDin(l))
  {
    printf("%d", ELMT_LISTDIN(l, 0));
    for (i = 1; i < (IdxTypeListDin) lengthListDin(l); i++)
    {
      printf(",%d", ELMT_LISTDIN(l, i));
    }
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
  /* KAMUS LOKAL */
  ListDin l3;
  IdxTypeListDin i;

  /* ALGORITMA */
  CreateListDin(&l3, CAPACITY_LISTDIN(l1));
  NEFF_LISTDIN(l3) = lengthListDin(l1);
  for (i = 0; i < (IdxTypeListDin) lengthListDin(l3); i++)
  {
    if (plus) {
      ELMT_LISTDIN(l3, i) = ELMT_LISTDIN(l1, i) + ELMT_LISTDIN(l2, i);
    }
    else {
      ELMT_LISTDIN(l3, i) = ELMT_LISTDIN(l1, i) - ELMT_LISTDIN(l2, i);
    }
  }
  return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListDinEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;
  boolean flag;

  /* ALGORITMA */
  flag = true;
  i = 0;

  if (lengthListDin(l1) == lengthListDin(l2)) {
    while (flag && i < (IdxTypeListDin) lengthListDin(l1))
    {
      if (ELMT_LISTDIN(l1, i) != ELMT_LISTDIN(l2, i))
      {
        flag = false;
      }
      else { i++; }
    }
  }
  else { flag = false; }

  return flag;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
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

  while (!found && i < (IdxTypeListDin) lengthListDin(l))
  {
    if (ELMT_LISTDIN(l, i) == val)
    {
      hasil = i;
      found = true;
    }
    else { i++; }
  }
  return hasil;
}


/* ********** NILAI EKSTREM ********** */
void extremesListDin(ListDin l, ElTypeListDin* max, ElTypeListDin* min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;

  /* ALGORITMA */
  *min = ELMT_LISTDIN(l, 0);
  *max = ELMT_LISTDIN(l, 0);
  for (i = 0; i < (IdxTypeListDin) lengthListDin(l); i++) {
    if (ELMT_LISTDIN(l, i) > *max) {
      *max = ELMT_LISTDIN(l, i);
    }
    if (ELMT_LISTDIN(l, i) < *min) {
      *min = ELMT_LISTDIN(l, i);
    }
  }
}


/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin* lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;

  /* ALGORITMA */
  CreateListDin(lOut, CAPACITY_LISTDIN(lIn));
  NEFF_LISTDIN(*lOut) = lengthListDin(lIn);
  for (i = 0; i < (IdxTypeListDin) lengthListDin(lIn); i++)
  {
    ELMT_LISTDIN(*lOut, i) = ELMT_LISTDIN(lIn, i);
  }
}

ElTypeListDin sumListDin(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;
  ElTypeListDin sum;

  /* ALGORITMA */
  sum = 0;
  if (!isEmptyListDin(l)) {
    for (i = 0; i < (IdxTypeListDin) lengthListDin(l); i++)
    {
      sum += ELMT_LISTDIN(l, i);
    }
  }
  return sum;
}

int countValListDin(ListDin l, ElTypeListDin val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;
  int count;
  /* ALGORITMA */
  count = 0;
  for (i = 0; i < (IdxTypeListDin) lengthListDin(l); i++)
  {
    if (ELMT_LISTDIN(l, i) == val) { count++; }
  }
  return count;
}

boolean isAllEvenListDin(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i;
  boolean flag;

  /* ALGORITMA */
  i = 0;
  flag = true;
  if (!isEmptyListDin(l))
  {
    while (flag && i < (IdxTypeListDin) lengthListDin(l))
    {
      if (ELMT_LISTDIN(l, i) % 2 != 0) { flag = false; }
      else { i++; }
    }
  }
  return flag;
}

/* ********** SORTING ********** */
void sortListDin(ListDin* l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
  /* KAMUS LOKAL */
  IdxTypeListDin i, j;
  ElTypeListDin temp;

  /* ALGORITMA */
  if (lengthListDin(*l) > 1) {
    for (i = 0; i < (IdxTypeListDin) lengthListDin(*l) - 1; i++) {
      for (j = 0; j < (IdxTypeListDin) lengthListDin(*l) - 1 - i; j++) {
        if (asc == true) {
          if (ELMT_LISTDIN(*l, j) > ELMT_LISTDIN(*l, j + 1)) {
            temp = ELMT_LISTDIN(*l, j);
            ELMT_LISTDIN(*l, j) = ELMT_LISTDIN(*l, j + 1);
            ELMT_LISTDIN(*l, j + 1) = temp;
          }
        }
        else {
          if (ELMT_LISTDIN(*l, j) < ELMT_LISTDIN(*l, j + 1)) {
            temp = ELMT_LISTDIN(*l, j);
            ELMT_LISTDIN(*l, j) = ELMT_LISTDIN(*l, j + 1);
            ELMT_LISTDIN(*l, j + 1) = temp;
          }
        }
      }
    }
  }
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