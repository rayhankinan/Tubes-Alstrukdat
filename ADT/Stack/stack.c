/* ADT Stack*/

#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    /* KAMUS */

    /* ALGORITMA */
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
    return (IDX_TOP_STACK(s) == CAPACITY_STACK - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, ElTypeStack val)
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    /* KAMUS */

    /* ALGORITMA */

    if (isEmptyStack(*s)) {
        IDX_TOP_STACK(*s) = 0;
        TOP_STACK(*s) = val;
    } else {
        IDX_TOP_STACK(*s)++;
        TOP_STACK(*s) = val;
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