/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../Boolean/boolean.h"
#include "../Item/item.h"
#include "../Mesin/wordmachinefile.h"
#include "../ListDinamis/listdin.h"
#include <stdio.h>

#define IDX_UNDEF_QUEUE -1
#define CAPACITY_QUEUE 100

/* Definisi elemen dan address */
typedef Item ElTypeQueue;
typedef struct {
        ElTypeQueue buffer[CAPACITY_QUEUE];
        int idxHead;
        int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD_QUEUE(q) (q).idxHead
#define IDX_TAIL_QUEUE(q) (q).idxTail
#define     HEAD_QUEUE(q) (q).buffer[(q).idxHead]
#define     TAIL_QUEUE(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue* q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int lengthQueue(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue* q, ElTypeQueue val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue* q, ElTypeQueue* val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
        q mungkin kosong */

        /* *** I/O Queue *** */
void readQueue(Queue* q, ListDin daftarBangunan);
/* I.S. q sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Queue q terdefinisi */
/* Proses : membaca banyaknya elemen q dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
      /*    Jika N = 0; hanya terbentuk l kosong */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal dengan menggunakan fungsi tulis item*/
/* I.S. q terisi, apabila kosong, tidak akan mendisplay apa-apa */
/* F.S. Jika q tidak kosong: <lokasi_pickup> -> <lokasi dropoff> (<jenis_item>) untuk item biasa,
dan menampilkan sisa waktu untuk item perishable */
void writeQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal dengan menggunakan fungsi tulis item*/
/* I.S. q terisi, apabila kosong, tidak akan mendisplay apa-apa */
/* F.S. Jika q tidak kosong: <waktu_pickup> <lokasi_pickup> <lokasi dropoff> <jenis_item> untuk item biasa,
dan menampilkan sisa waktu untuk item perishable */

#endif