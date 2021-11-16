/* ADT Item */

#include "item.h"
#include <stdio.h>

/* KONSTRUKTOR */
Item CreateItem(char jenis, Lokasi pick_up, Lokasi drop_off, int waktu)
/* Membentuk sebuah Item dari komponen-komponennya */
{
    /* KAMUS */
    Item I;

    /* ALGORITMA */
    WAKTU_PICK_UP_ITEM(I) = UNDEF_WAKTU;
    JENIS_ITEM(I) = jenis;
    PICK_UP_ITEM(I) = pick_up;
    DROP_OFF_ITEM(I) = drop_off;
    WAKTU_HANGUS_ITEM(I) = waktu;
    WAKTU_LEWAT_ITEM(I) = UNDEF_WAKTU;

    return I;
}

/* BACA/TULIS */
void BacaItem(Item *I, ListDin daftarBangunan)
/* Membaca jenis, lokasi pick up, lokasi drop off, serta waktu hangus item (khusus perishable item)
   dan membentuk Item I berdasarkan nilai tersebut */
/* Semua komponen ditulis dalam 1 baris, dipisahkan 1 spasi */
/* I.S. : I sembarang */
/* F.S. : I terdefinisi */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    advWordFile();
    WAKTU_PICK_UP_ITEM(*I) = wordToInt(currentWordFile);

    advWordFile();
    i = 0;
    while ((i < lengthListDin(daftarBangunan)) && (NAMA_LOKASI(ELMT_LISTDIN(daftarBangunan, i)) != currentWordFile.contents[0])) {
        i++;
    }
    PICK_UP_ITEM(*I) = ELMT_LISTDIN(daftarBangunan, i);

    advWordFile();
    i = 0;
    while ((i < lengthListDin(daftarBangunan)) && (NAMA_LOKASI(ELMT_LISTDIN(daftarBangunan, i)) != currentWordFile.contents[0])) {
        i++;
    }
    DROP_OFF_ITEM(*I) = ELMT_LISTDIN(daftarBangunan, i);

    advWordFile();
    JENIS_ITEM(*I) = currentWordFile.contents[0];

    if (eotFile) {
        WAKTU_HANGUS_ITEM(*I) = UNDEF_WAKTU;
        WAKTU_LEWAT_ITEM(*I) = UNDEF_WAKTU;
    } else {
        advWordFile();
        WAKTU_HANGUS_ITEM(*I) = wordToInt(currentWordFile);
        if (eotFile) {
            WAKTU_LEWAT_ITEM(*I) = 0;
        } else {
            WAKTU_LEWAT_ITEM(*I) = wordToInt(currentWordFile);
        }
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
            printf("%c -> %c (%s)", NAMA_LOKASI(PICK_UP_ITEM(I)), NAMA_LOKASI(DROP_OFF_ITEM(I)), "Normal Item");
            break;
        case 'H':
            printf("%c -> %c (%s)", NAMA_LOKASI(PICK_UP_ITEM(I)), NAMA_LOKASI(DROP_OFF_ITEM(I)), "Heavy Item");
            break;
        case 'P':
            printf("%c -> %c (%s, sisa waktu %d)", NAMA_LOKASI(PICK_UP_ITEM(I)), NAMA_LOKASI(DROP_OFF_ITEM(I)), "Perishable Item", WAKTU_HANGUS_ITEM(I));
            break;
        case 'V':
            printf("%c -> %c (%s)", NAMA_LOKASI(PICK_UP_ITEM(I)), NAMA_LOKASI(DROP_OFF_ITEM(I)), "VIP Item");
            break;
    }
}
void WriteItem(Item I)
/* Nilai I tertulis di layar dengan format <pick_up> -> <drop_off> (<jenis_item_translated>, <waktu_hangus jika perishable>) */
/* I.S. : I dan currentWaktu terdefinisi */
/* F.S. : I tertulis di layar sesuai dengan format */
{
    /* KAMUS */

    /* ALGORITMA */
    printfFile("%d %c %c %c %d %d", WAKTU_PICK_UP_ITEM(I), NAMA_LOKASI(PICK_UP_ITEM(I)), NAMA_LOKASI(DROP_OFF_ITEM(I)), JENIS_ITEM(I), WAKTU_HANGUS_ITEM(I), WAKTU_LEWAT_ITEM(I));
}

/* Operasi Relasional */
boolean EQItem(Item I1, Item I2)
/* Mengirimkan true jika I1 = I2 : komponennya sama */
{
    /* KAMUS */

    /* ALGORITMA */
    return ((WAKTU_PICK_UP_ITEM(I1) == WAKTU_PICK_UP_ITEM(I2)) && (JENIS_ITEM(I1) == JENIS_ITEM(I2)) && EQLokasi(PICK_UP_ITEM(I1), PICK_UP_ITEM(I2)) && EQLokasi(DROP_OFF_ITEM(I1), DROP_OFF_ITEM(I2)) && (WAKTU_HANGUS_ITEM(I1) == WAKTU_HANGUS_ITEM(I2)));
}