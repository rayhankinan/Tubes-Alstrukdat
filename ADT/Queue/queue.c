/* ADT Queue*/

#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    IDX_HEAD_QUEUE(*q) = IDX_UNDEF_QUEUE;
    IDX_TAIL_QUEUE(*q) = IDX_UNDEF_QUEUE;
}

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((IDX_HEAD_QUEUE(q) == IDX_UNDEF_QUEUE) && (IDX_TAIL_QUEUE(q) == IDX_UNDEF_QUEUE));
}
boolean isFullQueue(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((IDX_HEAD_QUEUE(q) == 0) && (IDX_TAIL_QUEUE(q) == CAPACITY_QUEUE - 1));
}
int lengthQueue(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    /* KAMUS */
    int N;

    /* ALGORITMA */
    if (isEmptyQueue(q)) {
        N = 0;
    } else {
        N = IDX_TAIL_QUEUE(q) - IDX_HEAD_QUEUE(q) + 1;
    }

    return N;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElTypeQueue val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    /* KAMUS */
    int i;
    ElTypeQueue temp;

    /* ALGORITMA */
    if (isEmptyQueue(*q)) {
        IDX_HEAD_QUEUE(*q) = 0;
        IDX_TAIL_QUEUE(*q) = 0;
    } else {
        if ((IDX_TAIL_QUEUE(*q) == CAPACITY_QUEUE - 1)) {
            for (i = IDX_HEAD_QUEUE(*q); i <= IDX_TAIL_QUEUE(*q); i++) {
                q->buffer[i - IDX_HEAD_QUEUE(*q)] = q->buffer[i];
            }
            IDX_TAIL_QUEUE(*q) -= IDX_HEAD_QUEUE(*q);
            IDX_HEAD_QUEUE(*q) = 0;
        }
        IDX_TAIL_QUEUE(*q)++;
    }
    TAIL_QUEUE(*q) = val;

    i = IDX_TAIL_QUEUE(*q);
    while ((i > 0) && (WAKTU_PICK_UP_ITEM(q->buffer[i - 1]) > WAKTU_PICK_UP_ITEM(q->buffer[i]))) {
        temp = q->buffer[i - 1];
        q->buffer[i - 1] = q->buffer[i];
        q->buffer[i] = temp;
        i--;
    }
}

void dequeue(Queue *q, ElTypeQueue *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    *val = HEAD_QUEUE(*q);

    if (IDX_HEAD_QUEUE(*q) == IDX_TAIL_QUEUE(*q)) {
        IDX_HEAD_QUEUE(*q) = IDX_UNDEF_QUEUE;
        IDX_TAIL_QUEUE(*q) = IDX_UNDEF_QUEUE;
    } else {
        IDX_HEAD_QUEUE(*q)++;
    }
}

/* *** I/O Queue *** */
void readQueue(Queue* q, ListDin daftarBangunan)
/* I.S. q sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Queue q terdefinisi */
/* Proses : membaca banyaknya elemen q dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    /* KAMUS */
    int i, P;
    ElTypeQueue tempItem;

    /* ALGORITMA */
    CreateQueue(q);

    advWordFile();
    P = wordToInt(currentWordFile);
    advCharFile(); /* Membaca baris berikutnya */

    for (i = 0; i < P; i++) {
        BacaItem(&tempItem, daftarBangunan);
        enqueue(q, tempItem);
    }
}
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal dengan menggunakan fungsi tulis item*/
/* I.S. q terisi, apabila kosong, tidak akan mendisplay apa-apa */
/* F.S. Jika q tidak kosong: <lokasi_pickup> -> <lokasi dropoff> (<jenis_item>) untuk item biasa,
dan menampilkan sisa waktu untuk item perishable */
{
    /* KAMUS */
    ElTypeQueue val;

    /* ALGORITMA */
    while (!isEmptyQueue(q)) {
        dequeue(&q, &val);
        TulisItem(val);
        printf("\n");
    }
}
void writeQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal dengan menggunakan fungsi tulis item*/
/* I.S. q terisi, apabila kosong, tidak akan mendisplay apa-apa */
/* F.S. Jika q tidak kosong: <waktu_pickup> <lokasi_pickup> <lokasi dropoff> <jenis_item> untuk item biasa,
dan menampilkan sisa waktu untuk item perishable */
{
    /* KAMUS */
    ElTypeQueue val;

    /* ALGORITMA */
    printfFile("%d\n", lengthQueue(q));
    while (!isEmptyQueue(q)) {
        dequeue(&q, &val);
        WriteItem(val);
        printfFile("\n");
    }
}