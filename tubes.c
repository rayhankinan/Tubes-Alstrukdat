/* File: tubes.c */
/* Implementasi fungsi dan prosedur pada main program */

#include "tubes.h"

/* State awal pada main program (sudah terdefinisi dari pembacaan file) */
int N, M, L;
Lokasi HQ;
ListDin daftarBangunan;
Matrix adjacencyMatrix;
Queue daftarPesanan;

/* State berjalan pada main program (didefinisikan seiring berjalannya program) */
boolean hasWon;
Player Mobita;
ListPos inventory;
ListPos hargaGadget;

void printWord(Word kata)
/* Menuliskan string ke dalam main program */
/* I.S. kata terdefinisi */
/* F.S. kata ditulis ke dalam main program */
{
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < kata.length; i++) {
        printf("%c", kata.contents[i]);
    }
}

void readQuery(Word *ptrQuery)
/* Membaca input string dari user */
/* I.S. Query bebas */
/* F.S. Query berisi string input user */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */

    startWord();

    if (eot) {
        writeQuery(ptrQuery, currentWord.contents, currentWord.length);
    } else {
        writeQuery(ptrQuery, "", 0);
        while (!eot) {
            advWord();
        }
    }
}

void writeQuery(Word *ptrQuery, char input[], int length)
/* Menuliskan string input ke dalam query */
/* I.S. : Query bebas */
/* F.S. : Query.contents berisi string input dengan query.length berisi integer length */
{
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < length; i++) {
        ptrQuery->contents[i] = input[i];
    }
    ptrQuery->contents[length] = '\0';
    ptrQuery->length = length;
}

boolean compareQuery(Word query, Word value)
/* Mencari tahu apakah dua Word bernilai sama */
{
    /* KAMUS */
    boolean hasil;
    int i;

    /* ALGORITMA */
    hasil = query.length == value.length;

    i = 0;
    while (i < query.length && hasil) {
        hasil = query.contents[i] == value.contents[i];
        i++;
    }

    return hasil;
}

Word concatQuery(Word query1, Word query2)
/* Menggabungkan dua Word */
{
    /* KAMUS */
    Word queryHasil;
    int i;

    /* ALGORITMA */
    for (i = 0; i < query1.length; i++) {
        queryHasil.contents[i] = query1.contents[i];
    }
    for (i = 0; i < query2.length; i++) {
        queryHasil.contents[query1.length + i] = query2.contents[i];
    }
    queryHasil.contents[query1.length + query2.length] = '\0';
    queryHasil.length = query1.length + query2.length;

    return queryHasil;
}

void printGadgetName(int id)
/* Menampilkan nama gadget sesuai dengan id gadget */
/* I.S. : id gadget terdefinisi */
/* I.F. : nama gadget tertulis ke dalam main program */
{
    switch (id) {
    case 1:
        printf("Kain Pembungkus Waktu");
        break;
    case 2:
        printf("Senter Pembesar");
        break;
    case 3:
        printf("Pintu Kemana Saja");
        break;
    case 4:
        printf("Mesin Waktu");
    }
}

void shopMenu()
/* Menampilkan gadget yang dapat dibeli pada main program lalu Player membelinya */
/* I.S. : Keadaan awal main program bebas */
/* F.S. : Output player berhasil atau gagal membeli gadget dari toko dan    menyimpan gadget pada list inventory */
{
    /* KAMUS LOKAL */
    Word input;
    int N, total;

    /* ALGORITMA */
    //UANG_PLAYER(Mobita) = 5000; (TEST)

    if (isFullListPos(inventory)) {
        printf("Maaf, inventory Anda sudah full.\n");
    } else {
        printf("Uang Anda sekarang: %d Yen\n", UANG_PLAYER(Mobita));
        printf("Gadget yang tersedia:\n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

        do {
            printf("\nSHOP COMMAND: ");
            readQuery(&input);
            N = wordToInt(input);
            if (N < 0 || N > 4) {
                printf("Try Again!");
            }
        } while (N < 0 || N > 4);

        if (N != 0) {
            total = UANG_PLAYER(Mobita) - ELMT_LISTPOS(hargaGadget, N - 1);
            if (total < 0) {
                printf("Uang tidak cukup untuk membeli gadget!\n");
            } else {
                printGadgetName(N);
                printf(" berhasil dibeli!\n");
                printf("Uang anda sekarang: %d Yen\n", total);
                UANG_PLAYER(Mobita) = total;
                insertFreeSlot(&inventory, N);
            }
        }
    }
}

void activateEffect(int id)
/* Mengaktifkan effek gadget */
{
    printf("[Placeholder]\n");
}

void inventoryMenu()
/* Menampilkan isi list inventory pada main program 
lalu player menggunakan gadget yang diinginkan */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output gadget berhasil atau gagal untuk digunakan lalu menghasilkan
efek gadget tersebut */
{
    /* KAMUS LOKAL */
    Word input;
    int id_gadget;
    int i;
    /* ALGORITMA */
    for (i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        if (ELMT_LISTPOS(inventory, i) == VAL_UNDEF_LISTPOS) {
            printf("-\n");
        } else {
            printGadgetName(ELMT_LISTPOS(inventory, i));
            printf("\n");
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    do {
        printf("\nINVENTORY COMMAND: ");
        readQuery(&input);
        N = wordToInt(input);
        if (N < 0 || N > 5) {
            printf("Try Again!");
        }
    } while (N < 0 || N > 5);
    if (N != 0) {
        if (ELMT_LISTPOS(inventory, N - 1) == VAL_UNDEF_LISTPOS) {
            printf("Tidak ada Gadget yang dapat digunakan!\n");
        } else {
            activateEffect(ELMT_LISTPOS(inventory, N - 1));
            printGadgetName(ELMT_LISTPOS(inventory, N - 1));
            printf(" berhasil digunakan!\n");
            ELMT_LISTPOS(inventory, N - 1) = VAL_UNDEF_LISTPOS;
        }
    }
}

void mainMenu()
/* Menampilkan main menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada layar */
{
    /* KAMUS */
    Word input, quit, newGame, loadGame;

    /* ALGORITMA */
    writeQuery(&newGame, "NEW_GAME", 8);
    writeQuery(&quit, "QUIT", 4);
    writeQuery(&loadGame, "LOAD_GAME", 9);

    do {
        printf("ENTER COMMAND: ");
        readQuery(&input);

        if (compareQuery(input, newGame)) {
            readNewGame();
            gameMenu();
        } else if (compareQuery(input, quit)) {
            printf("Quiting the game . . .");
            stopWord();
        } else if (compareQuery(input, loadGame)) {
            readLoadGame();
            gameMenu();
        } else {
            printf("Try Again!\n");
        }
    } while (!compareQuery(input, newGame) || !compareQuery(input, quit) || !compareQuery(input, loadGame));
}

void readFileConfigNewGame(char namaFile[])
/* Membaca file configuration new game */
/* I.S. : State pada main program bebas dan namaFile terdefinisi */
/* F.S. : State pada main program diisi dengan nilai sesuai dengan isi namaFile */
{
    /* KAMUS */
    int i, j;
    Lokasi tempLoc;

    /* ALGORITMA */
    startWordFile(namaFile);
    N = wordToInt(currentWordFile);
    advWordFile();
    M = wordToInt(currentWordFile);
    advCharFile(); /* Membaca baris berikutnya */

    NAMA_LOKASI(HQ) = '8';
    BacaPOINT(&KOORDINAT_LOKASI(HQ));

    readListDin(&daftarBangunan);

    readMatrix(&adjacencyMatrix, lengthListDin(daftarBangunan) + 1, lengthListDin(daftarBangunan) + 1);

    readQueue(&daftarPesanan);

    stopWordFile();
}

void readFileConfigLoadGame(char namaFile[])
/* Membaca file configuration load game */
/* I.S. : State pada main program bebas dan namaFile terdefinisi */
/* F.S. : State pada main program diisi dengan nilai sesuai dengan isi namaFile */
{
    /* KAMUS */

    /* ALGORITMA */
}

void readNewGame()
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigNewGame kemudian melakukan pembacaan file */
{
    /* KAMUS */
    Word dirFile, input;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigNewGame/", 14);
    printf("ENTER FILE NAME: ");
    readQuery(&input);

    readFileConfigNewGame(concatQuery(dirFile, input).contents);

    /* Janlup buat handling kalau nama filenya tidak ada di directory */
}

void readLoadGame()
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfidLoadGame kemudian melakukan pembacaan file */
{
    /* KAMUS */
    Word dirFile, input;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigLoadGame/", 15);
    printf("ENTER FILE NAME: ");
    readQuery(&input);

    readFileConfigLoadGame(concatQuery(dirFile, input).contents); /* Janlup buat handling kalau nama filenya tidak ada di directory */
}

void gameMenu()
/* Menampikan game menu pada main program */
/* I.S. : Main menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output game menu pada layar */
{
    /* KAMUS */
    Word input, move, pickUp, dropOff, mapLokasi, toDoList, inProgress, buyGadget, inventoryGadget, helpCommand, saveGame, returnItem;

    /* ALGORITMA */
    hasWon = false;

    CreatePlayer(&Mobita, HQ);
    CreateListPos(&inventory);

    CreateListPos(&hargaGadget);
    ELMT_LISTPOS(hargaGadget, 0) = 800;
    ELMT_LISTPOS(hargaGadget, 1) = 1200;
    ELMT_LISTPOS(hargaGadget, 2) = 1500;
    ELMT_LISTPOS(hargaGadget, 3) = 3000;

    writeQuery(&move, "MOVE", 4);
    writeQuery(&pickUp, "PICK_UP", 7);
    writeQuery(&dropOff, "DROP_OFF", 8);
    writeQuery(&mapLokasi, "MAP", 3);
    writeQuery(&toDoList, "TO_DO", 5);
    writeQuery(&inProgress, "IN_PROGRESS", 11);
    writeQuery(&buyGadget, "BUY", 3);
    writeQuery(&inventoryGadget, "INVENTORY", 9);
    writeQuery(&helpCommand, "HELP", 4);
    writeQuery(&saveGame, "SAVE_GAME", 9);
    writeQuery(&returnItem, "RETURN", 6);

    do {
        printf("ENTER COMMAND: ");
        readQuery(&input);

        if (compareQuery(input, move)) {

        } else if (compareQuery(input, pickUp)) {

        } else if (compareQuery(input, dropOff)) {

        } else if (compareQuery(input, mapLokasi)) {

        } else if (compareQuery(input, toDoList)) {

        } else if (compareQuery(input, inProgress)) {

        } else if (compareQuery(input, buyGadget)) {
            shopMenu();
        } else if (compareQuery(input, inventoryGadget)) {
            inventoryMenu();
        } else if (compareQuery(input, helpCommand)) {

        } else if (compareQuery(input, saveGame)) {

            stopWord();
        } else if (compareQuery(input, returnItem)) {

        } else {
            printf("Try Again!\n");
        }
    } while (!hasWon || !compareQuery(input, saveGame));
}
