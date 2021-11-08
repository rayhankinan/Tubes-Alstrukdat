/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../Boolean/boolean.h"
#include "../Item/item.h"
#include "../Player/player.h"

#define IDX_UNDEF_STACK -1

typedef Item ElTypeStack;
typedef struct {
  ElTypeStack* buffer; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int capacity;            /* kapasitas */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define BUFFER_STACK(s) (s).buffer
#define IDX_TOP_STACK(s) (s).idxTop
#define CAPACITY_STACK(s) (s).capacity
#define TOP_STACK(s) (s).buffer[(s).idxTop]

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack* s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullStack(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack* s, ElTypeStack val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus elemen top Stack ************ */
void popStack(Stack* s, ElTypeStack* val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

/* ************ Menghapus elemen ke idx dari Stack ************ */
void deleteAtStack(Stack* s, int idx, ElTypeStack* val);
/* I.S. s tidak mungkin kosong dan idx terdefinisi */
/* F.S. val adalah nilai elemen ke idx yang lama */

/* ************ Menambah kapasitas sebuah Stack ************ */
void growStack(Stack *s);
/* Menambah kapasitas Stack s sebanyak satu slot */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s bertambah satu slot */

/* ************ I/O Stack ************ */
void displayStack(Stack s, Player P);
/* Menampilkan isi Stack s pada layar */
/* I.S. Stack s terdefinisi */
/* F.S. isi Item di dalam Stack s ditampilkan pada layar */

#endif