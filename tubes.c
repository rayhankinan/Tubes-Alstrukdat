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
    displayListDin(daftarBangunan);

    readMatrix(&adjacencyMatrix, lengthListDin(daftarBangunan) + 1, lengthListDin(daftarBangunan) + 1);
    displayMatrix(adjacencyMatrix);

    readQueue(&daftarPesanan);
    displayQueue(daftarPesanan);
    
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
    
    readFileConfigNewGame(concatQuery(dirFile, input).contents); /* Janlup buat handling kalau nama filenya tidak ada di directory */
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
    Word input, moveFromLoc, pickUp, dropOff, mapLokasi, toDoList, inProgress, buyGadget, inventoryGadget, helpCommand, saveGame, returnItem;

    /* ALGORITMA */
    hasWon = false;

    CreatePlayer(&Mobita, HQ);

    printf("\nMobita berada di posisi ");
    TulisLokasi(LOKASI_PLAYER(Mobita));
    printf("\n");
    printf("Waktu: %d\n", WAKTU_PLAYER(Mobita));
    printf("Uang yang dimiliki: %d Yen\n\n", UANG_PLAYER(Mobita));

    writeQuery(&moveFromLoc, "MOVE", 4);
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

        if (compareQuery(input, moveFromLoc)) {
            move();
        } else if (compareQuery(input, pickUp)) {

        } else if (compareQuery(input, dropOff)) {

        } else if (compareQuery(input, mapLokasi)) {

        } else if (compareQuery(input, toDoList)) {

        } else if (compareQuery(input, inProgress)) {

        } else if (compareQuery(input, buyGadget)) {

        } else if (compareQuery(input, inventoryGadget)) {

        } else if (compareQuery(input, helpCommand)) {

        } else if (compareQuery(input, saveGame)) {

            stopWord();
        } else if (compareQuery(input, returnItem)) {

        } else {
            printf("Try Again!\n");
        }
    } while (!hasWon || !compareQuery(input, saveGame));
}

void move()
/* Meminta lokasi tujuan player yang bisa diakses dari lokasi player, kemudian menggerakannya */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Lokasi player berubah sesuai input pengguna */
{
    /* KAMUS */
    int i, j, count;

    /* ALGORITMA */

    count = 0;
    i = indexOfListDin(daftarBangunan, LOKASI_PLAYER(Mobita));

    for (j = 0; j < lengthListDin(daftarBangunan); j++) {
        if (ELMT_MATRIX(adjacencyMatrix, i, j)) {
            printf("%d. ", count + 1);
            TulisLokasi(ELMT_LISTDIN(daftarBangunan, j));
            printf("\n");
            count++;
        }
    }
}