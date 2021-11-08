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
ListPos inventory, hargaGadget;
Stack tas;
ListLinked toDoList;

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

    CreateListDin(&daftarBangunan, 1);
    NAMA_LOKASI(HQ) = '8';
    BacaPOINT(&KOORDINAT_LOKASI(HQ));
    insertLastListDin(&daftarBangunan, HQ);

    readListDin(&daftarBangunan);

    readMatrix(&adjacencyMatrix, lengthListDin(daftarBangunan), lengthListDin(daftarBangunan));

    readQueue(&daftarPesanan, daftarBangunan);

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
    Word dirFile, input, namaFile;
    FILE *tempFile;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigNewGame/", 14);
    printf("ENTER FILE NAME: ");
    readQuery(&input);
    namaFile = concatQuery(dirFile, input);

    /* Janlup buat handling kalau nama filenya tidak ada di directory */
    tempFile = fopen(namaFile.contents, "r");
    if (tempFile == NULL) {
        printf("Name file tidak ada.\n");
        mainMenu();
    } else {
        readFileConfigNewGame(namaFile.contents);
    }
}

void readLoadGame()
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfidLoadGame kemudian melakukan pembacaan file */
{
    /* KAMUS */
    Word dirFile, input, namaFile;
    FILE *tempFile;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigLoadGame/", 15);
    printf("ENTER FILE NAME: ");
    readQuery(&input);
    namaFile = concatQuery(dirFile, input);

    /* Janlup buat handling kalau nama filenya tidak ada di directory */
    tempFile = fopen(namaFile.contents, "r");
    if (tempFile == NULL) {
        printf("Name file tidak ada.\n");
        mainMenu();
    } else {
        readFileConfigLoadGame(namaFile.contents);
    }
}

void updatePesanan()
/* Memasukkan pesanan dari daftar pesanan ke dalam to do list sesuai dengan waktu pesanan */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Pesanan masuk dari daftar pesanan ke dalam to do list */
{
    /* KAMUS */
    Item I;

    /* ALGORITMA */
    while (WAKTU_PLAYER(Mobita) >= WAKTU_PICK_UP_ITEM(HEAD_QUEUE(daftarPesanan))) {
        dequeue(&daftarPesanan, &I);
        insertLastListLinked(&toDoList, I);
    }
}

void updateTas()
/* Mengurangi waktu Perishable Item pada Stack tas */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Waktu Perishable Item pada Stack Tas berkurang */
{
    /* KAMUS */
    Item I;
    int i;

    /* ALGORITMA */
    for (i = 0; i < CAPACITY_STACK(tas); i++) {
        I = tas.buffer[i];
        if ((JENIS_ITEM(I) == 'P') && (WAKTU_HANGUS_ITEM(I) - WAKTU_PLAYER(Mobita) <= 0)) {
            deleteAtStack(&tas, i, &I);
        }
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

    if (EQLokasi(LOKASI_PLAYER(Mobita), HQ)) {
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
                printf("\nENTER COMMAND: ");
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
            } else {
                printf("Exiting INVENTORY . . .\n");
                printf("Returning to main menu.\n");
            }
        }
    } else {
        printf("Mobita tidak berada di Headquarters!\n");
    }
}

void activateEffect(int id)
/* Mengaktifkan efek gadget */
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
        printf("\nENTER COMMAND: ");
        readQuery(&input);
        N = wordToInt(input);
        if (N < 0 || N > 5) {
            printf("Try Again!\n");
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
    } else {
        printf("Exiting INVENTORY . . .\n");
        printf("Returning to main menu.\n");
    }
}

void moveMenu()
/* Meminta lokasi tujuan player yang bisa diakses dari lokasi player, kemudian menggerakannya */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Lokasi player berubah sesuai input pengguna */
{
    /* KAMUS */
    int i, j, count, index;
    Word input;
    static int speedMove = 0;

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

    printf("Posisi yang dipilih? (ketik 0 jika mau kembali)\n\n");

    do {
        printf("ENTER COMMAND: ");
        readQuery(&input);
        index = wordToInt(input);

        if (index == 0) {
            printf("Exiting MOVE . . .\n");
        } else if (index > 0 && index <= count) {
            count = 0;

            for (j = 0; j < lengthListDin(daftarBangunan) && index != count; j++) {
                if (ELMT_MATRIX(adjacencyMatrix, i, j)) {
                    TulisLokasi(ELMT_LISTDIN(daftarBangunan, j));
                    printf("\n");
                    count++;
                }
                if (index == count) {
                    movePlayer(&Mobita, ELMT_LISTDIN(daftarBangunan, j));
                }
            }
        } else {
            printf("Try Again!\n");
        }
    } while (index < 0 || index > count);

    if (SPEED_BOOST_PLAYER(Mobita) && index != 0) {
        speedMove++;
        if (speedMove % 2 == 0) {
            WAKTU_PLAYER(Mobita)++;
        }
    } else if (index != 0) {
        speedMove = 0;
        WAKTU_PLAYER(Mobita) += (BERAT_PLAYER(Mobita) + 1);
    } else {
        printf("Returning to main menu.\n");
    }
}

void pickUpMenu()
/* Mengambil Item yang terletak di lokasi player */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Item ditambahkan ke dalam tas bila tas belum penuh */
{
    /* KAMUS */
    Address p;
    Item I;
    int i;

    /* ALGORITMA */
    if (!isFullStack(tas)) {
        p = FIRST_LIST_LINKED(toDoList);
        i = 0;
        while ((p != NULL) && (!EQLokasi(PICK_UP_ITEM(INFO_NODE(p)), LOKASI_PLAYER(Mobita)))) {
            p = NEXT_NODE(p);
            i++;
        }

        if (p == NULL) {
            printf("Pesanan tidak ditemukan!\n");
        } else {
            deleteAtListLinked(&toDoList, i, &I);
            pushStack(&tas, I);

            if (JENIS_ITEM(I) == 'H') {
                SPEED_BOOST_PLAYER(Mobita) = false;
                BERAT_PLAYER(Mobita)++;
            }
        }
    } else {
        printf("Tas sudah penuh!\n");
    }
}

void dropOffMenu()
/* Mengantarkan Item dari elemen teratas stack tas ke lokasi drop off */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Elemen teratas stack tas di drop off di lokasi */
{
    /* KAMUS */
    Item I;

    /* ALGORITMA */
    if (!isEmptyStack(tas)) {
        popStack(&tas, &I);

        switch (JENIS_ITEM(I)) {
            case 'N':
                UANG_PLAYER(Mobita) += 200;
                break;
            case 'H':
                UANG_PLAYER(Mobita) += 400;
                BERAT_PLAYER(Mobita)--;
                SPEED_BOOST_PLAYER(Mobita) = BERAT_PLAYER(Mobita) == 0;
                break;
            case 'P':
                UANG_PLAYER(Mobita) += 400;
                growStack(&tas);
                break;
            case 'V':
                UANG_PLAYER(Mobita) += 600;
                JUMLAH_RETURN_PLAYER(Mobita)++;
                break;
        }

    } else {
        printf("Tas kosong!\n");
    }
}

void toDoListMenu()
/* Menampilkan Item yang bisa diambil */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output list Item yang bisa diambil pada map */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmptyListLinked(toDoList)) {
        printf("Tidak ada pesanan pada To Do List!\n");
    } else {
        printf("Pesanan pada To Do List:\n");
        displayListLinked(toDoList, Mobita);
    }
}

void inProgressMenu()
/* Menampilkan Item yang ada di dalam tas */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output list Item yang ada di dalam tas */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmptyStack(tas)) {
        printf("Tidak ada pesanan yang sedang diantarkan!\n");
    } else {
        printf("Pesanan yang sedang diantarkan:\n");
        displayStack(tas);
    }
}

void mainMenu()
/* Menampilkan main menu pada main program */
/* I.S. Keadaan awal main program bebas */
/* F.S. Output main menu pada layar */
{
    /* KAMUS */
    Word inputQuery, quitQuery, newGameQuery, loadGameQuery;

    /* ALGORITMA */
    writeQuery(&newGameQuery, "NEW_GAME", 8);
    writeQuery(&quitQuery, "QUIT", 4);
    writeQuery(&loadGameQuery, "LOAD_GAME", 9);

    do {
        printf("ENTER COMMAND: ");
        readQuery(&inputQuery);

        if (compareQuery(inputQuery, newGameQuery)) {
            readNewGame();
            gameMenu();
        } else if (compareQuery(inputQuery, quitQuery)) {
            printf("Quiting the game . . .\n");
            stopWord();
        } else if (compareQuery(inputQuery, loadGameQuery)) {
            readLoadGame();
            gameMenu();
        } else {
            printf("Try Again!\n");
        }
    } while (!compareQuery(inputQuery, newGameQuery) || !compareQuery(inputQuery, quitQuery) || !compareQuery(inputQuery, loadGameQuery));
}

void gameMenu()
/* Menampikan game menu pada main program */
/* I.S. : Main menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output game menu pada layar */
{
    /* KAMUS */
    Word inputQuery, moveFromLocQuery, pickUpQuery, dropOffQuery, mapLokasiQuery, toDoListQuery, inProgressQuery, buyGadgetQuery, inventoryGadgetQuery, helpCommandQuery, saveGameQuery, returnItemQuery;

    /* ALGORITMA */
    hasWon = false;

    CreatePlayer(&Mobita, HQ);
    CreateListPos(&inventory);

    CreateListPos(&hargaGadget);
    insertLastListPos(&hargaGadget, 800);
    insertLastListPos(&hargaGadget, 1200);
    insertLastListPos(&hargaGadget, 1500);
    insertLastListPos(&hargaGadget, 3000);

    CreateStack(&tas);

    CreateListLinked(&toDoList);

    writeQuery(&moveFromLocQuery, "MOVE", 4);
    writeQuery(&pickUpQuery, "PICK_UP", 7);
    writeQuery(&dropOffQuery, "DROP_OFF", 8);
    writeQuery(&mapLokasiQuery, "MAP", 3);
    writeQuery(&toDoListQuery, "TO_DO", 5);
    writeQuery(&inProgressQuery, "IN_PROGRESS", 11);
    writeQuery(&buyGadgetQuery, "BUY", 3);
    writeQuery(&inventoryGadgetQuery, "INVENTORY", 9);
    writeQuery(&helpCommandQuery, "HELP", 4);
    writeQuery(&saveGameQuery, "SAVE_GAME", 9);
    writeQuery(&returnItemQuery, "RETURN", 6);

    do {
        printf("\nMobita berada di posisi ");
        TulisLokasi(LOKASI_PLAYER(Mobita));
        printf("\n");
        printf("Waktu: %d\n", WAKTU_PLAYER(Mobita));
        printf("Uang yang dimiliki: %d Yen\n\n", UANG_PLAYER(Mobita));

        updatePesanan();

        updateTas();

        printf("ENTER COMMAND: ");
        readQuery(&inputQuery);

        if (compareQuery(inputQuery, moveFromLocQuery)) {
            moveMenu();
        } else if (compareQuery(inputQuery, pickUpQuery)) {
            pickUpMenu();
        } else if (compareQuery(inputQuery, dropOffQuery)) {
            dropOffMenu();
        } else if (compareQuery(inputQuery, mapLokasiQuery)) {

        } else if (compareQuery(inputQuery, toDoListQuery)) {
            toDoListMenu();
        } else if (compareQuery(inputQuery, inProgressQuery)) {
            inProgressMenu();
        } else if (compareQuery(inputQuery, buyGadgetQuery)) {
            shopMenu();
        } else if (compareQuery(inputQuery, inventoryGadgetQuery)) {
            inventoryMenu();
        } else if (compareQuery(inputQuery, helpCommandQuery)) {

        } else if (compareQuery(inputQuery, saveGameQuery)) {

            stopWord();
        } else if (compareQuery(inputQuery, returnItemQuery)) {

        } else {
            printf("Try Again!\n");
        }
    } while (!hasWon || !compareQuery(inputQuery, saveGameQuery));
}
