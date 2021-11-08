/* ADT Stack*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY_STACK(*s) = 3;
    BUFFER_STACK(*s) = (ElTypeStack *) malloc(CAPACITY_STACK(*s) * sizeof(ElTypeStack));
    IDX_TOP_STACK(*s) = IDX_UNDEF_STACK;
}

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s)
/* Mengirim true jika s kosong: lihat definisi di atas */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IDX_TOP_STACK(s) == IDX_UNDEF_STACK);
}
boolean isFullStack(Stack s)
/* Mengirim true jika tabel penampung nilai s stack penuh */
{
    /* KAMUS */

    /* ALGORITMA */
    return (IDX_TOP_STACK(s) == CAPACITY_STACK(s) - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, ElTypeStack val)
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    /* KAMUS */
    int i;
    ElTypeStack temp;

    /* ALGORITMA */

    if (isEmptyStack(*s)) {
        IDX_TOP_STACK(*s) = 0;
        TOP_STACK(*s) = val;
    } else {
        IDX_TOP_STACK(*s)++;
        TOP_STACK(*s) = val;

        if (JENIS_ITEM(TOP_STACK(*s)) != 'V') {
            i = IDX_TOP_STACK(*s);
            while ((i > 0) && (JENIS_ITEM(s->buffer[i - 1]) == 'V')) {
                temp = s->buffer[i - 1];
                s->buffer[i - 1] = s->buffer[i];
                s->buffer[i] = temp;
            }
        }
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, ElTypeStack *val)
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    /* KAMUS */

    /* ALGORITMA */
    *val = TOP_STACK(*s);
    IDX_TOP_STACK(*s)--;
}

/* ************ Menghapus elemen ke idx dari Stack ************ */
void deleteAtStack(Stack* s, int idx, ElTypeStack* val)
/* I.S. s tidak mungkin kosong dan idx terdefinisi */
/* F.S. val adalah nilai elemen ke idx yang lama */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    *val = s->buffer[idx];
    
    i = idx;
    while (i < IDX_TOP_STACK(*s)) {
        s->buffer[i] = s->buffer[i + 1];
    }
    IDX_TOP_STACK(*s)--;
}

/* ************ Menambah kapasitas sebuah Stack ************ */
void growStack(Stack *s)
/* Menambah kapasitas Stack s sebanyak satu slot */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s bertambah satu slot */
{
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY_STACK(*s)++;
    BUFFER_STACK(*s) = (ElTypeStack *) realloc(BUFFER_STACK(*s), CAPACITY_STACK(*s) * sizeof(ElTypeStack));
}

/* ************ I/O Stack ************ */
void displayStack(Stack s)
/* Menampilkan isi Stack s pada layar */
/* I.S. Stack s terdefinisi */
/* F.S. isi Item di dalam Stack s ditampilkan pada layar */
{
    /* KAMUS */
    ElTypeStack I;
    int i;

    /* ALGORITMA */
    i = 0;
    while (!isEmptyStack(s)) {
        printf("%d. ", i + 1);
        popStack(&s, &I);
        switch (JENIS_ITEM(I)) {
            case 'N':
                printf("%s (Tujuan: %c)", "Normal Item", NAMA_LOKASI(DROP_OFF_ITEM(I)));
                break;
            case 'H':
                printf("%s (Tujuan: %c)", "Heavy Item", NAMA_LOKASI(DROP_OFF_ITEM(I)));
                break;
            case 'P':
                printf("%s, sisa waktu %d (Tujuan: %c)", "Perishable Item", WAKTU_HANGUS_ITEM(I), NAMA_LOKASI(DROP_OFF_ITEM(I)));
                break;
            case 'V':
                printf("%s (Tujuan: %c)", "VIP Item", NAMA_LOKASI(DROP_OFF_ITEM(I)));
                break;
        }
        printf("\n");
        i++;
    }
}