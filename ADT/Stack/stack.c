/* ADT Stack*/

#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack* s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY_STACK(*s) = 3;
    BUFFER_STACK(*s) = (ElTypeStack*)malloc(CAPACITY_STACK(*s) * sizeof(ElTypeStack));
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

int lengthStack(Stack s)
/* Mengirimkan jumlah elemen pada stack */
{
    /* KAMUS LOKAL */
    ElTypeStack temp;
    int length;
    /* ALGORITMA */
    length = 0;
    while (!isEmptyStack(s)) {
        popStack(&s, &temp);
        length++;
    }
    return length;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack* s, ElTypeStack val)
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
    }
    else {
        IDX_TOP_STACK(*s)++;
        TOP_STACK(*s) = val;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack* s, ElTypeStack* val)
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
        i++;
    }
    IDX_TOP_STACK(*s)--;
}

/* ************ Menambah kapasitas sebuah Stack ************ */
void growStack(Stack* s)
/* Menambah kapasitas Stack s sebanyak satu slot */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s bertambah satu slot */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (CAPACITY_STACK(*s) < 100) {
        CAPACITY_STACK(*s)++;
        BUFFER_STACK(*s) = (ElTypeStack*)realloc(BUFFER_STACK(*s), CAPACITY_STACK(*s) * sizeof(ElTypeStack));
    }
}

void growDoubleStack(Stack* s)
/* Mengubah kapasitas Stack s sebesar dua kali lipat  dari kapasitas sebelumnya */
/* I.S. Stack s terdefinisi, boleh kosong */
/* F.S. kapasitas Stack s menjadi dua kali lipat */
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    CAPACITY_STACK(*s) *= 2;
    if (CAPACITY_STACK(*s) > 100) {
        CAPACITY_STACK(*s) = 100;
    }
    BUFFER_STACK(*s) = (ElTypeStack*)realloc(BUFFER_STACK(*s), CAPACITY_STACK(*s) * sizeof(ElTypeStack));
}

/* ************ I/O Stack ************ */
void readStack(Stack* s, ListDin daftarBangunan)
/* Membaca Stack S dari file config kemudian mengisi nilainya */
/* I.S. Stack s sembarang */
/* F.S. Stack s terdefinisi dengan nilai kapasitas dari file config */
{
    /* KAMUS */

    /* ALGORITMA */
    CreateStack(s);

    advWordFile();
    CAPACITY_STACK(*s) = wordToInt(currentWordFile);
    advCharFile(); /* Membaca baris berikutnya */
}
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

void writeStack(Stack s)
/* Menulis isi Stack s pada file config */
/* I.S. Stack s terdefinisi */
/* F.S. Capacity Stack s ditulis di dalam file config */
{
    /* KAMUS */

    /* ALGORITMA */
    printfFile("%d\n", CAPACITY_STACK(s));
}

void isiTas(Stack* s, ListLinked l)
/* Mengisi nilai Item sesuai dengan list linked */
/* I.S. Stack s sembarang dan list linked l terdefinisi */
/* F.S. isi Item di dalam Stack sama dengan list linked l */
{
    /* KAMUS */
    Address p;
    Stack temp;
    ElTypeStack val;

    /* ALGORITMA */
    CreateStack(&temp);

    p = l;
    while (p != NULL) {
        pushStack(&temp, INFO_NODE(p));
        p = NEXT_NODE(p);
    }

    while (!isEmptyStack(temp)) {
        popStack(&temp, &val);
        pushStack(s, val);
    }
}

void updateWaktuTimeTas(Stack* tas, int waktu)
//I.S menerima queue tas bisa empty juga
//F.S Mengupdate waktu item tas
{
    /*KAMUS*/
    int i;
    Item I;
    /*ALGORITMA*/
    for (i = 0; i < (IDX_TOP_STACK(*tas) + 1); i++) {
        I = (*tas).buffer[i];
        if ((JENIS_ITEM(I) == 'P')) {
            WAKTU_HANGUS_ITEM((*tas).buffer[i]) -= waktu;
            WAKTU_LEWAT_ITEM((*tas).buffer[i]) += waktu;
        }
    }
}

void kembalikanWaktuItemTas(Stack* tas)
//I.S Menerima tas yang tidak kosong,
//F.S Mengembalikan waktu semula item perishable teratas
{
    /*KAMUS*/
    int i = IDX_TOP_STACK(*tas);
    boolean flag = false;
    /*ALGORITMA*/
    while (i >= 0 && !flag) {
        if ((JENIS_ITEM((*tas).buffer[i]) == 'P')) {
            WAKTU_HANGUS_ITEM((*tas).buffer[i]) += WAKTU_LEWAT_ITEM((*tas).buffer[i]);
            WAKTU_LEWAT_ITEM((*tas).buffer[i]) = 0;
            flag = true;
        }
        i--;
    }
}