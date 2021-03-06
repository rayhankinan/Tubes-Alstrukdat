/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../Boolean/boolean.h"
#include "../Item/item.h"
#include "../LinkedList/list_linked.h"
#include <stdio.h>
#include <stdlib.h>

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
int lengthStack(Stack s);
/* Mengirimkan jumlah elemen pada stack */

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
void growStack(Stack* s);
/* Menambah kapasitas Stack s sebanyak satu slot */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s bertambah satu slot */
void growDoubleStack(Stack* s);
/* Mengubah kapasitas Stack s sebesar dua kali lipat  dari kapasitas sebelumnya */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s menjadi dua kali lipat */

/* ************ I/O Stack ************ */
void readStack(Stack* s, ListDin daftarBangunan);
/* Membaca Stack S dari file config kemudian mengisi nilainya */
/* I.S. Stack s sembarang */
/* F.S. Stack s terdefinisi dengan nilai kapasitas dari file config */

void displayStack(Stack s);
/* Menampilkan isi Stack s pada layar */
/* I.S. Stack s terdefinisi */
/* F.S. isi Item di dalam Stack s ditampilkan pada layar */

void writeStack(Stack s);
/* Menulis isi Stack s pada file config */
/* I.S. Stack s terdefinisi */
/* F.S. Capacity Stack s ditulis di dalam file config */

void isiTas(Stack* s, ListLinked l);
/* Mengisi nilai Item sesuai dengan list linked */
/* I.S. Stack s terdefinisi dan list linked l terdefinisi */
/* F.S. isi Item di dalam Stack sama dengan list linked l */

void updateWaktuTimeTas(Stack* tas, int waktu);
/* I.S menerima queue tas bisa empty juga */
/* F.S Mengupdate waktu item tas*/

void kembalikanWaktuItemTas(Stack *tas);
//I.S Menerima tas yang tidak kosong, 
//F.S Mengembalikan waktu semula item perishable teratas

#endif