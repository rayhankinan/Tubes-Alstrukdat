/* File: tubes.c */
/* Implementasi fungsi dan prosedur pada main program */

#include "tubes.h"

/* State awal pada main program (sudah terdefinisi dari pembacaan file) */
int N, M;
Lokasi HQ;
ListDin daftarBangunan;
Matrix adjacencyMatrix;
Queue daftarPesanan;

/* State berjalan pada main program (didefinisikan seiring berjalannya program) */
boolean hasWon;
Player Mobita;
ListPos inventory, hargaGadget;
Stack tas;
ListLinked toDoList, progressList;


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

void readQuery(Word* ptrQuery)
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
    }
    else {
        writeQuery(ptrQuery, "", 0);
        while (!eot) {
            advWord();
        }
    }
}

void writeQuery(Word* ptrQuery, char input[], int length)
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

    BacaPlayer(&Mobita);

    readListPos(&inventory);

    readListPos(&hargaGadget);

    readStack(&tas, daftarBangunan);

    readListLinked(&toDoList, daftarBangunan);

    readListLinked(&progressList, daftarBangunan);

    isiTas(&tas, progressList);

    stopWordFile();
}

void writeFileConfig(char namaFile[])
/* Menuliskan state program pada file configuration */
/* I.S. : State pada main program dan namaFile terdefinisi */
/* F.S. : File configuration diisi dengan nilai state program */
{
    /* KAMUS */

    /* ALGORITMA */
    startFile(namaFile);

    printfFile("%d %d\n", N, M);

    WritePOINT(KOORDINAT_LOKASI(HQ));
    printfFile("\n");

    writeListDin(daftarBangunan);

    writeMatrix(adjacencyMatrix);

    writeQueue(daftarPesanan);

    WritePlayer(Mobita);

    writeListPos(inventory);

    writeListPos(hargaGadget);

    writeStack(tas);

    writeListLinked(toDoList);

    writeListLinked(progressList);

    endFile();
}

void readNewGame()
/* Membaca file configuration untuk NEW GAME */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada ConfigNewGame kemudian melakukan pembacaan file */
{
    /* KAMUS */
    Word dirFile, input, namaFile;
    FILE* tempFile;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigNewGame/", 14);
    printf("ENTER FILE NAME: ");
    readQuery(&input);
    namaFile = concatQuery(dirFile, input);

    tempFile = fopen(namaFile.contents, "r");
    if (tempFile == NULL) {
        printf("Name file tidak ada.\n");
        mainMenu();
    }
    else {
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
    FILE* tempFile;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigLoadGame/", 15);
    printf("ENTER FILE NAME: ");
    readQuery(&input);
    namaFile = concatQuery(dirFile, input);

    tempFile = fopen(namaFile.contents, "r");
    if (tempFile == NULL) {
        printf("Name file tidak ada.\n");
        mainMenu();
    }
    else {
        readFileConfigLoadGame(namaFile.contents);
    }
}

void saveGame()
/* Melakukan save state game pada file txt */
/* I.S. : State pada main program terdefinisi */
/* F.S. : Meminta nama file pada <FUNGSI TULIS STATE> kemudian melakukan penulisan file */
{
    /* KAMUS */
    Word dirFile, input, namaFile;
    FILE* tempFile;

    /* ALGORITMA */
    writeQuery(&dirFile, "ConfigLoadGame/", 15);
    printf("ENTER FILE NAME: ");
    readQuery(&input);
    namaFile = concatQuery(dirFile, input);

    tempFile = fopen(namaFile.contents, "w");
    if (tempFile == NULL) {
        printf("Nama file tidak ada.\n");
        mainMenu();
    }
    else {
        writeFileConfig(namaFile.contents);
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
    while ((WAKTU_PLAYER(Mobita) >= WAKTU_PICK_UP_ITEM(HEAD_QUEUE(daftarPesanan))) && (!isEmptyQueue(daftarPesanan))) {
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
    if (!isEmptyStack(tas)) {
        updateWaktuTimeTas(&tas, WAKTU_TAMBAH_PLAYER(Mobita));
        for (i = 0; (i < (IDX_TOP_STACK(tas) + 1)); i++) {
            if ((JENIS_ITEM(tas.buffer[i]) == 'P') && (WAKTU_HANGUS_ITEM(tas.buffer[i]) <= 0)) {
                deleteAtStack(&tas, i, &I);
            }
        }
    }
}

void updateProgressList()
/* Mengurangi waktu perishible item pada progress list */
/* I.S. : State pada main program sudah diisi */
/* F.S. : Waktu Perishable Item pada progress list berkurang */
{
    /* KAMUS LOKAL */
    Address p;
    int idx = 0;
    ElTypeNode trash;

    /* ALGORITMA */
    if (!isEmptyListLinked(progressList)) {
        updateWaktuItem(&progressList, WAKTU_TAMBAH_PLAYER(Mobita));
        p = FIRST_LIST_LINKED(progressList);
        while (p != NULL) {
            if (JENIS_ITEM(INFO_NODE(p)) == 'P' && WAKTU_HANGUS_ITEM(INFO_NODE(p)) <= 0) {
                deleteAtListLinked(&progressList, idx, &trash);
            }
            p = NEXT_NODE(p);
            idx++;
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
    int shop_index, total;

    /* ALGORITMA */
    if (EQLokasi(LOKASI_PLAYER(Mobita), HQ)) {
        if (isFullListPos(inventory)) {
            printf("Maaf, inventory Anda sudah full.\n");
        }
        else {
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
                shop_index = wordToInt(input);
                if (shop_index < 0 || shop_index > 4) {
                    printf("Try Again!\n");
                }
            } while (shop_index < 0 || shop_index > 4);

            if (shop_index != 0) {
                total = UANG_PLAYER(Mobita) - ELMT_LISTPOS(hargaGadget, shop_index - 1);
                if (total < 0) {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
                else {
                    printGadgetName(shop_index);
                    printf(" berhasil dibeli!\n");
                    printf("Uang anda sekarang: %d Yen\n", total);
                    UANG_PLAYER(Mobita) = total;
                    insertFreeSlot(&inventory, shop_index);
                }
            }
            else {
                printf("Exiting BUY . . .\n");
                printf("Returning to main menu.\n");
            }
        }
    }
    else {
        printf("Mobita tidak berada di Headquarters!\n");
    }
}

void pintuKemanaSajaMenu()
/* Menampilkan semua lokasi bangunan, kemudian menggerakkan player ke lokasi
tersebut tanpa menambahkan WAKTU_PLAYER */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Lokasi player berubah sesuai input pengguna */
{
    /* KAMUS LOKAL */
    int i, index, count;
    Word input;

    /* ALGORITMA */
    count = 0;
    for (i = 0; i < lengthListDin(daftarBangunan); i++) {
        if (!EQLokasi(ELMT_LISTDIN(daftarBangunan, i), LOKASI_PLAYER(Mobita))) {
            printf("%d. ", count + 1);
            TulisLokasi(ELMT_LISTDIN(daftarBangunan, i));
            printf("\n");
            count++;
        }
    }
    printf("Posisi yang ingin dipilih? \n\n");
    do {
        printf("ENTER COMMAND: ");
        readQuery(&input);
        index = wordToInt(input);
        if (index < 1 || index > lengthListDin(daftarBangunan)) {
            printf("Try Again!\n");
        }
    } while (index < 1 || index > lengthListDin(daftarBangunan));
    count = 0;
    for (i = 0; i < lengthListDin(daftarBangunan) && index != count; i++) {
        if (!EQLokasi(ELMT_LISTDIN(daftarBangunan, i), LOKASI_PLAYER(Mobita))) {
            count++;
        }
    }
    movePlayer(&Mobita, ELMT_LISTDIN(daftarBangunan, count));
}

void activateEffect(int id)
/* Mengaktifkan efek gadget */
{
    switch (id) {
    case 1:
        if (JENIS_ITEM(TOP_STACK(tas)) == 'P') {
            kembalikanWaktuItem(&progressList);
            kembalikanWaktuItemTas(&tas);
        }
        break;
    case 2:
        if (CAPACITY_STACK(tas) < 1000) {
            growDoubleStack(&tas);
        }
        break;
    case 3:
        pintuKemanaSajaMenu();
        break;
    case 4:
        WAKTU_PLAYER(Mobita) -= 50;
        if (WAKTU_PLAYER(Mobita) < 0) {
            WAKTU_PLAYER(Mobita) = 0;
        }
        break;
    }
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
    int i, index_gadget;
    /* ALGORITMA */
    for (i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        if (ELMT_LISTPOS(inventory, i) == VAL_UNDEF_LISTPOS) {
            printf("-\n");
        }
        else {
            printGadgetName(ELMT_LISTPOS(inventory, i));
            printf("\n");
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    do {
        printf("\nENTER COMMAND: ");
        readQuery(&input);
        index_gadget = wordToInt(input);
        if (index_gadget < 0 || index_gadget > 5) {
            printf("Try Again!\n");
        }
    } while (index_gadget < 0 || index_gadget > 5);

    if (index_gadget != 0) {
        if (ELMT_LISTPOS(inventory, index_gadget - 1) == VAL_UNDEF_LISTPOS) {
            printf("Tidak ada Gadget yang dapat digunakan!\n");
        }
        else {
            printGadgetName(ELMT_LISTPOS(inventory, index_gadget - 1));
            printf(" berhasil digunakan!\n");
            activateEffect(ELMT_LISTPOS(inventory, index_gadget - 1));
            ELMT_LISTPOS(inventory, index_gadget - 1) = VAL_UNDEF_LISTPOS;
        }
    }
    else {
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
        }
        else if (index > 0 && index <= count) {
            count = 0;

            for (j = 0; j < lengthListDin(daftarBangunan) && index != count; j++) {
                if (ELMT_MATRIX(adjacencyMatrix, i, j)) {
                    count++;
                }
                if (index == count) {
                    movePlayer(&Mobita, ELMT_LISTDIN(daftarBangunan, j));
                }
            }
        }
        else {
            printf("Try Again!\n");
        }
    } while (index < 0 || index > count);

    WAKTU_TAMBAH_PLAYER(Mobita) = 0;
    if (SPEED_BOOST_PLAYER(Mobita) && index != 0) {
        SPEED_MOVE_PLAYER(Mobita)++;
        if (SPEED_MOVE_PLAYER(Mobita) % 2 == 0) {
            WAKTU_PLAYER(Mobita)++;
            WAKTU_TAMBAH_PLAYER(Mobita) = 1;
        }
    }
    else if (index != 0) {
        SPEED_MOVE_PLAYER(Mobita) = 0;
        WAKTU_PLAYER(Mobita) += (BERAT_PLAYER(Mobita) + 1);
        WAKTU_TAMBAH_PLAYER(Mobita) = (BERAT_PLAYER(Mobita) + 1);
    }
    else {
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
        }
        else if (JENIS_ITEM(TOP_STACK(tas)) == 'V') {
            printf("Tidak bisa pick up barang dikarenakan membawa barang VIP!\n");
        }
        else {
            deleteAtListLinked(&toDoList, i, &I);
            pushStack(&tas, I);
            insertFirstListLinked(&progressList, I);

            switch (JENIS_ITEM(I)) {
            case 'N':
                printf("Pesanan berupa Normal Item berhasil diambil!\n");
                break;
            case 'H':
                SPEED_BOOST_PLAYER(Mobita) = false;
                BERAT_PLAYER(Mobita)++;
                printf("Pesanan berupa Heavy Item berhasil diambil!\nEfek Heavy Item akan aktif!\n");
                break;
            case 'P':
                printf("Pesanan berupa Perishable Item berhasil diambil!\nItem ini akan hangus dalam %d unit waktu!\n", WAKTU_HANGUS_ITEM(I));
                break;
            case 'V':
                printf("Pesanan berupa VIP Item berhasil diambil!\nMobita tidak akan bisa pick up Item lainnya sampai Item ini di drop off!\n");
                break;
            }
        }
    }
    else {
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
        if (NAMA_LOKASI(DROP_OFF_ITEM(TOP_STACK(tas))) == NAMA_LOKASI(LOKASI_PLAYER(Mobita))) {
            popStack(&tas, &I);
            deleteFirstListLinked(&progressList, &I);

            switch (JENIS_ITEM(I)) {
            case 'N':
                UANG_PLAYER(Mobita) += 200;
                JUMLAH_ANTAR_PLAYER(Mobita)++;
                printf("Pesanan berupa Normal Item berhasil diantarkan!\n");
                printf("Uang yang didapatkan: %d Yen\n", 200);
                break;
            case 'H':
                UANG_PLAYER(Mobita) += 400;
                BERAT_PLAYER(Mobita)--;
                JUMLAH_ANTAR_PLAYER(Mobita)++;
                SPEED_BOOST_PLAYER(Mobita) = BERAT_PLAYER(Mobita) == 0;
                printf("Pesanan berupa Heavy Item berhasil diantarkan!\n");
                printf("Uang yang didapatkan: %d Yen\n", 400);
                break;
            case 'P':
                UANG_PLAYER(Mobita) += 400;
                growStack(&tas);
                JUMLAH_ANTAR_PLAYER(Mobita)++;
                printf("Pesanan berupa Perishable Item berhasil diantarkan!\n");
                printf("Uang yang didapatkan: %d Yen\n", 400);
                break;
            case 'V':
                UANG_PLAYER(Mobita) += 600;
                JUMLAH_RETURN_PLAYER(Mobita)++;
                JUMLAH_ANTAR_PLAYER(Mobita)++;
                printf("Pesanan berupa VIP Item berhasil diantarkan!\n");
                printf("Uang yang didapatkan: %d Yen\n", 600);
                break;
            }
        }
        else {
            printf("Hanya bisa mengantar item teratas bag ke tujuan lokasi yang benar!\n");
        }
    }
    else {
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
    }
    else {
        printf("Pesanan pada To Do List:\n");
        displayListLinked(toDoList);
    }
}

void inProgressMenu()
/* Menampilkan Item yang ada di dalam tas */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output list Item yang ada di dalam tas */
{
    /* KAMUS */

    /* ALGORITMA */
    if (isEmptyListLinked(progressList)) {
        printf("Tidak ada pesanan yang sedang diantarkan!\n");
    }
    else {
        printf("Pesanan yang sedang diantarkan:\n");
        displayprogress(progressList);
    }
}

void returnMenu()
/* Mengecek apabila bisa mengembalikan item, dan restore it menjadi keadaan awal item tersebut lagi */
//  I.S. : Cek ability player kalau punya ability untuk return, dan jenis item stack teratas bukan VIP Item 
//  F.S. : Jika true, pesanan teratas kembali ke todo list terakhir (N,H), time limit pesanan reset sebelum dikembalikan ke todo list terakhir(P)  
{
    Item trash;

    if (JUMLAH_RETURN_PLAYER(Mobita) > 0) {
        if (JENIS_ITEM(TOP_STACK(tas)) == 'V') {
            printf("Maaf, VIP item tidak bisa dikembalikan\n");
        }
        else {
            if (JENIS_ITEM(TOP_STACK(tas)) == 'H') {
                BERAT_PLAYER(Mobita)--;
                popStack(&tas, &trash);
                deleteFirstListLinked(&progressList, &trash);
                insertFirstListLinked(&toDoList, trash);
                printf("Heavy Item berhasil direturn\n");
            }
            else if (JENIS_ITEM(TOP_STACK(tas)) == 'N') {
                popStack(&tas, &trash);
                deleteFirstListLinked(&progressList, &trash);
                insertLastListLinked(&toDoList, trash);
                printf("Normal Item berhasil direturn\n");
            }
            else {
                kembalikanWaktuItem(&progressList);
                popStack(&tas, &trash);
                deleteFirstListLinked(&progressList, &trash);
                insertLastListLinked(&toDoList, trash);
                printf("Perishable Item berhasil direturn\n");
            }
            JUMLAH_RETURN_PLAYER(Mobita)--;
        }
    }
    else {
        printf("Item can't be returned\n");
    }
}

int findLoc(int i, int j) {
    /*KAMUS LOKAL*/
    boolean found;
    int indeks;

    /*ALGORITMA*/
    indeks = 0;
    found = false;

    while (indeks < lengthListDin(daftarBangunan) && found == false) {
        if (Absis_POINT(KOORDINAT_LOKASI(ELMT_LISTDIN(daftarBangunan, indeks))) == i && Ordinat_POINT(KOORDINAT_LOKASI(ELMT_LISTDIN(daftarBangunan, indeks))) == j) {
            found = true;
        }
        else {
            indeks = indeks + 1;
        }
    }
    if (indeks == lengthListDin(daftarBangunan)) {
        return IDX_UNDEF_LISTDIN;
    }
    else {
        return indeks;
    }
}

void map()
/* Menampilkan Map */
/* I.S. : Game menu sudah ditampilkan pada layar dan state pada main program sudah diisi */
/* F.S. : Output Map berdasarkan file konfigurasi dengan kategori warnanya */
{
    /* KAMUS LOKAL */
    int i, j, m;
    int idxBangunan;
    char locationName;
    boolean found;
    Address adrTemp;

    /* ALGORITMA */
    for (i = 0; i <= (M + 1); i++) {
        printf("*");
    }

    printf("\n");
    for (i = 1; i <= N; i++) {
        for (j = 0; j <= (M + 1); j++) {
            idxBangunan = findLoc(i, j);
            locationName = NAMA_LOKASI(ELMT_LISTDIN(daftarBangunan, idxBangunan));

            if (j == 0) {
                printf("*");
            }
            else if (j == (M + 1)) {
                printf("*\n");
            }
            else if (idxBangunan != IDX_UNDEF_LISTDIN) {
                if (locationName == NAMA_LOKASI(LOKASI_PLAYER(Mobita))) {
                    // posisi mobita
                    print_yellow(locationName);
                }
                else {
                    // bukan posisi mobita
                    if (locationName == NAMA_LOKASI(DROP_OFF_ITEM(TOP_STACK(tas)))) {
                        // drop off
                        print_blue(locationName);
                    }
                    else {
                        // bukan drop off
                        found = false;
                        adrTemp = FIRST_LIST_LINKED(toDoList);

                        while (adrTemp != NULL && found == false) {
                            if (locationName == NAMA_LOKASI(PICK_UP_ITEM(INFO_NODE(adrTemp)))) {
                                found = true;
                            }
                            else {
                                adrTemp = NEXT_NODE(adrTemp);
                            }
                        }

                        if (found == true) {
                            // pickup
                            print_red(locationName);
                        }
                        else {
                            // bukan pickup
                            m = indexOfListDin(daftarBangunan, LOKASI_PLAYER(Mobita));

                            if (ELMT_MATRIX(adjacencyMatrix, m, idxBangunan)) {
                                // move
                                print_green(locationName);
                            }
                            else {
                                // bukan move
                                printf("%c", locationName);
                            }
                        }
                    }
                }
            }
            else {
                printf(" ");
            }
        }
    }

    for (i = 0; i <= (M + 1); i++) {
        printf("*");
    }
}

void helpMenu()
/* Menampilkan Help */
/* I.S. : Game menu sudah ditampilkan */
/* F.S. : Output Help Menu pada layar */
{
    printf("1. MOVE -> Berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP -> Mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF -> Mengantarkan item ke lokasi sekarang\n");
    printf("4. MAP -> Memunculkan peta\n");
    printf("5. TO_DO -> Menampilkan pesanan yang masuk ke To Do List\n");
    printf("6. IN_PROGRESS -> Menampilkan pesanan yang sedang dikerjakan\n");
    printf("7. BUY -> Menampilkan gadget yang dapat dibeli (Hanya ketika Mobita dalam lokasi HQ)\n");
    printf("8. INVENTORY -> Menampilkan list isi inventory\n");
    printf("9. HELP -> Mengeluarkan list command dan kegunaannya\n");
    printf("10. SAVE_GAME -> Melakukan save state dari permainan yang sedang dijalankan\n");
    printf("11. RETURN -> Mengembalikan item di tumpukan tas teratas pada tas kembali ke lokasi pick up \n");
    printf("            (Hanya ketika Mobita memiliki ability Return To Sender)\n");
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

            CreatePlayer(&Mobita, HQ);

            CreateListPos(&inventory);

            CreateListPos(&hargaGadget);
            insertLastListPos(&hargaGadget, 800);
            insertLastListPos(&hargaGadget, 1200);
            insertLastListPos(&hargaGadget, 1500);
            insertLastListPos(&hargaGadget, 3000);

            CreateStack(&tas);

            CreateListLinked(&toDoList);

            CreateListLinked(&progressList);

            gameMenu();
        }
        else if (compareQuery(inputQuery, quitQuery)) {
            printf("Quiting the game . . .\n");
            stopWord();
        }
        else if (compareQuery(inputQuery, loadGameQuery)) {
            readLoadGame();
            gameMenu();
        }
        else {
            printf("Try Again!\n");
        }
    } while (!compareQuery(inputQuery, newGameQuery) && !compareQuery(inputQuery, quitQuery) && !compareQuery(inputQuery, loadGameQuery));
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
        printf("Kapasitas Tas: %d/%d\n", lengthStack(tas), CAPACITY_STACK(tas));
        printf("Uang yang dimiliki: %d Yen\n", UANG_PLAYER(Mobita));
        updatePesanan();

        printf("Jumlah pesanan yang harus dikerjakan: %d\n\n", lengthListLinked(toDoList));

        printf("ENTER COMMAND: ");
        readQuery(&inputQuery);

        if (compareQuery(inputQuery, moveFromLocQuery)) {
            moveMenu();
            updateTas();
            updateProgressList();
        }
        else if (compareQuery(inputQuery, pickUpQuery)) {
            pickUpMenu();
        }
        else if (compareQuery(inputQuery, dropOffQuery)) {
            dropOffMenu();
        }
        else if (compareQuery(inputQuery, mapLokasiQuery)) {
            map();
        }
        else if (compareQuery(inputQuery, toDoListQuery)) {
            toDoListMenu();
        }
        else if (compareQuery(inputQuery, inProgressQuery)) {
            inProgressMenu();
        }
        else if (compareQuery(inputQuery, buyGadgetQuery)) {
            shopMenu();
        }
        else if (compareQuery(inputQuery, inventoryGadgetQuery)) {
            inventoryMenu();
        }
        else if (compareQuery(inputQuery, helpCommandQuery)) {
            helpMenu();
        }
        else if (compareQuery(inputQuery, saveGameQuery)) {
            saveGame();
        }
        else if (compareQuery(inputQuery, returnItemQuery)) {
            returnMenu();
        }
        else {
            printf("Try Again!\n");
        }

        hasWon = isEmptyQueue(daftarPesanan) && isEmptyStack(tas) && isEmptyListLinked(toDoList) && (EQLokasi(LOKASI_PLAYER(Mobita), HQ));

    } while (!hasWon && !compareQuery(inputQuery, saveGameQuery));

    if (hasWon) {
        printf("Selamat, Mobita berhasil mengantarkan seluruh Item!\n");
        printf("Jumlah item yang berhasil diantar: %d\n", JUMLAH_ANTAR_PLAYER(Mobita));
        printf("Waktu yang dilampaui: %d\n", WAKTU_PLAYER(Mobita));
    }
    else {
        printf("Saving game . . .\n");
    }

    stopWord();
}
