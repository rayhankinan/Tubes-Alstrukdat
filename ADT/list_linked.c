/* ADT Linked List */

#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinked(ListLinked* l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  /* ALGORITMA */
  FIRST_LIST_LINKED(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyListLinked(ListLinked l)
/* Mengirim true jika list kosong */
{
  /* ALGORITMA */
  return FIRST_LIST_LINKED(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElTypeNode getElmtListLinked(ListLinked l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
  /* KAMUS LOKAL */
  Address p;
  int ctr;

  /* ALGORITMA */
  ctr = 0;
  p = FIRST_LIST_LINKED(l);
  while (ctr < idx) {
    ctr++;
    p = NEXT_NODE(p);
  }
  return INFO_NODE(p);
}

void setElmtListLinked(ListLinked* l, int idx, ElTypeNode val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
  /* KAMUS LOKAL */
  Address p;
  int ctr;

  /* ALGORITMA */
  ctr = 0;
  p = *l;
  while (ctr < idx) {
    ctr++;
    p = NEXT_NODE(p);
  }
  INFO_NODE(p) = val;
}

int indexOfListLinked(ListLinked l, ElTypeNode val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
  /* KAMUS LOKAL */
  int idx;
  Address p;
  boolean found;

  /* ALGORITMA */
  p = l;
  found = false;
  idx = 0;
  while (p != NULL && !found) {
    if (INFO_NODE(p) == val) {
      found = true;
    }
    else {
      idx++;
      p = NEXT_NODE(p);
    }
  }
  if (found) {
    return idx;
  }
  else {
    return IDX_UNDEF_LIST_LINKED;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLinked(ListLinked* l, ElTypeNode val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
  /* KAMUS LOKAL */
  Address p;

  /* ALGORITMA */
  p = newNode(val);
  NEXT_NODE(p) = FIRST_LIST_LINKED(*l);
  *l = p;
}

void insertLastListLinked(ListLinked* l, ElTypeNode val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  /* KAMUS LOKAL */
  Address p;
  Address last;

  /* ALGORITMA */
  if (isEmptyListLinked(*l)) {
    insertFirstListLinked(l, val);
  }
  else
  {
    p = newNode(val);
    if (p != NULL) {
      last = *l;
      while (NEXT_NODE(last) != NULL) {
        last = NEXT_NODE(last);
      }
    }
    NEXT_NODE(last) = p;
  }
}

void insertAtListLinked(ListLinked* l, ElTypeNode val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  /* KAMUS LOKAL */
  int ctr;
  Address p;
  Address loc;

  /* ALGORITMA */
  if (idx == 0) {
    insertFirstListLinked(l, val);
  }
  else {
    p = newNode(val);
    if (p != NULL) {
      ctr = 0;
      loc = FIRST_LIST_LINKED(*l);
      while (ctr < idx - 1) {
        ctr++;
        loc = NEXT_NODE(loc);
      }
      NEXT_NODE(p) = NEXT_NODE(loc);
      NEXT_NODE(loc) = p;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLinked(ListLinked* l, ElTypeNode* val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
  /* KAMUS LOKAL */
  Address p;

  /* ALGORITMA */
  p = FIRST_LIST_LINKED(*l);
  *val = INFO_NODE(p);
  FIRST_LIST_LINKED(*l) = NEXT_NODE(p);
  free(p);
}

void deleteLastListLinked(ListLinked* l, ElTypeNode* val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
  /* KAMUS LOKAL */
  Address loc;
  Address p;

  /* ALGORITMA */
  p = FIRST_LIST_LINKED(*l);
  loc = NULL;
  while (NEXT_NODE(p) != NULL) {
    loc = p;
    p = NEXT_NODE(p);
  }
  if (loc == NULL) {
    FIRST_LIST_LINKED(*l) = NULL;
  }
  else {
    NEXT_NODE(loc) = NULL;
  }
  *val = INFO_NODE(p);
  free(p);
}

void deleteAtListLinked(ListLinked* l, int idx, ElTypeNode* val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
  /* KAMUS LOKAL */
  int ctr;
  Address p;
  Address loc;

  /* ALGORITMA */
  if (idx == 0) {
    deleteFirstListLinked(l, val);
  }
  else {
    ctr = 0;
    loc = FIRST_LIST_LINKED(*l);
    while (ctr < idx - 1) {
      ctr++;
      loc = NEXT_NODE(loc);
    }
    p = NEXT_NODE(loc);
    *val = INFO_NODE(p);
    NEXT_NODE(loc) = NEXT_NODE(p);
    free(p);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLinked(ListLinked l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  /* KAMUS LOKAL */
  Address p;

  /* ALGORITMA */
  printf("[");
  if (!isEmptyListLinked(l)) {
    p = l;
    while (p != NULL) {
      printf("%d", INFO_NODE(p));
      if (NEXT_NODE(p) != NULL) {
        printf(",");
      }
      p = NEXT_NODE(p);
    }
  }
  printf("]");
}

int lengthListLinked(ListLinked l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  /* KAMUS LOKAL */
  Address p;
  int ctr;

  /* ALGORITMA */
  p = FIRST_LIST_LINKED(l);
  ctr = 0;
  while (p != NULL) {
    ctr++;
    p = NEXT_NODE(p);
  }
  return ctr;
}

/****************** PROSES TERHADAP LIST ******************/
ListLinked concatListLinked(ListLinked l1, ListLinked l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  /* KAMUS LOKAL */
  Address p;
  ListLinked l3;

  /* ALGORITMA */
  CreateListLinked(&l3);
  p = l1;
  while (p != NULL) {
    insertLastListLinked(&l3, INFO_NODE(p));
    p = NEXT_NODE(p);
  }

  p = l2;
  while (p != NULL) {
    insertLastListLinked(&l3, INFO_NODE(p));
    p = NEXT_NODE(p);
  }
  return l3;
}