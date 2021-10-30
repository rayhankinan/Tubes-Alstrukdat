/* ADT Item */

#include "item.h"
#include <stdio.h>

/* KONSTRUKTOR */
Item CreateItem(char jenis, char pick_up, char drop_off, int waktu)
/* Membentuk sebuah Item dari komponen-komponennya */
{
    /* KAMUS */
    Item I;

    /* ALGORITMA */
    JENIS_ITEM(I) = jenis;
    PICK_UP_ITEM(I) = pick_up;
    DROP_OFF_ITEM(I) = drop_off;
    WAKTU_HANGUS_ITEM(I) = waktu;

    return I;
}

/* BACA/TULIS */
void BacaItem(Item *I)
/* Membaca jenis, lokasi pick up, lokasi drop off, serta waktu hangus item (khusus perishable item)
   dan membentuk Item I berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : I sembarang */
/* F.S. : I terdefinisi */
{
    /* KAMUS */

    /* ALGORITMA */
    advWordFile();
    WAKTU_PICK_UP_ITEM(*I) = wordToInt(currentWordFile);
    advWordFile();
    JENIS_ITEM(*I) = currentWordFile.contents[0];
    advWordFile();
    PICK_UP_ITEM(*I) = currentWordFile.contents[0];
    advWordFile();
    DROP_OFF_ITEM(*I) = currentWordFile.contents[0];

    if (eotFile) {
        WAKTU_HANGUS_ITEM(*I) = UNDEF_WAKTU;
        printf("%d %c %c %c\n", WAKTU_PICK_UP_ITEM(*I), JENIS_ITEM(*I), PICK_UP_ITEM(*I), DROP_OFF_ITEM(*I)); /* TEST */
    } else {
        advWordFile();
        WAKTU_HANGUS_ITEM(*I) = wordToInt(currentWordFile);
        printf("%d %c %c %c %d\n", WAKTU_PICK_UP_ITEM(*I), JENIS_ITEM(*I), PICK_UP_ITEM(*I), DROP_OFF_ITEM(*I), WAKTU_HANGUS_ITEM(*I)); /* TEST */
    }

    advCharFile(); /* Membaca baris berikutnya */
}
void TulisItem(Item I)
/* Nilai I tertulis di layar dengan format <pick_up> -> <drop_off> (<jenis_item_translated>, <waktu_hangus jika perishable>) */
/* I.S. : I dan currentWaktu terdefinisi */
/* F.S. : I tertulis di layar sesuai dengan format */
{
    /* KAMUS */

    /* ALGORITMA */
    switch (JENIS_ITEM(I)) {
    case 'N':
        printf("%c -> %c (%s)", PICK_UP_ITEM(I), DROP_OFF_ITEM(I), "Normal Item");
        break;
    case 'H':
        printf("%c -> %c (%s)", PICK_UP_ITEM(I), DROP_OFF_ITEM(I), "Heavy Item");
        break;
    case 'P':
        printf("%c -> %c (%s, sisa waktu %d)", PICK_UP_ITEM(I), DROP_OFF_ITEM(I), "Heavy Item", WAKTU_HANGUS_ITEM(I));
        break;
    case 'V':
        printf("%c -> %c (%s)", PICK_UP_ITEM(I), DROP_OFF_ITEM(I), "VIP Item");
        break;
    }
}

/* Operasi Relasional */
boolean EQItem(Item I1, Item I2)
/* Mengirimkan true jika I1 = I2 : komponennya sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((WAKTU_PICK_UP_ITEM(I1) == WAKTU_PICK_UP_ITEM(I2)) && (JENIS_ITEM(I1) == JENIS_ITEM(I2)) && (PICK_UP_ITEM(I1) == PICK_UP_ITEM(I2)) && (DROP_OFF_ITEM(I1) == DROP_OFF_ITEM(I2)) && (WAKTU_HANGUS_ITEM(I1) == WAKTU_HANGUS_ITEM(I2)));
}