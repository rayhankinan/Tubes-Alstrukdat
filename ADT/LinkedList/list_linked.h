/* File : list_linked.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#ifndef LIST_H
#define LIST_H

#include "../Boolean/boolean.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef Address ListLinked;

#define IDX_UNDEF_LIST_LINKED (-1)
#define FIRST_LIST_LINKED(l) (l)

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinked(ListLinked* l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyListLinked(ListLinked l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElTypeNode getElmtListLinked(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtListLinked(ListLinked* l, int idx, ElTypeNode val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfListLinked(ListLinked l, ElTypeNode val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLinked(ListLinked* l, ElTypeNode val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastListLinked(ListLinked* l, ElTypeNode val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtListLinked(ListLinked* l, ElTypeNode val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLinked(ListLinked* l, ElTypeNode* val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastListLinked(ListLinked* l, ElTypeNode* val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtListLinked(ListLinked* l, int idx, ElTypeNode* val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void readListLinked(ListLinked* l, ListDin daftarBangunan);
/* I.S. List sembarang */
/* F.S. List terdefinisi dengan nilai dari file config */
void displayListLinked(ListLinked l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void writeListLinked(ListLinked l);
/* I.S. List terdefinisi */
/* F.S. isi List ditulis ke dalam file config */

int lengthListLinked(ListLinked l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
ListLinked concatListLinked(ListLinked l1, ListLinked l2);
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void updateWaktuItem(ListLinked* l, int waktu);
//I.S Menerima list yang tidak kosong, dan hanya progress list yang diproses
//F.S Menghitung mundur item perishable dan delete item kalau sudah hangus

void kembalikanWaktuItem(ListLinked* l);
//I.S Menerima list yang tidak kosong, 
//F.S Mengembalikan waktu semula item perishable teratas

void displayprogress(ListLinked l);
/* Menampilkan isi progress list pada layar */
/* I.S. Progress list l terdefinisi */
/* F.S. isi Item di dalam list progress ditampilkan pada layar */

boolean containVIP(ListLinked l);
/* Menghasilkan true jika terdapat Item VIP pada List Linked L */

Address nextVIP(Address p);
/* Menghasilkan Address Item VIP pertama dari Address p */
/* Menghasilkan NULL jika tidak terdapat Item VIP lagi */

#endif