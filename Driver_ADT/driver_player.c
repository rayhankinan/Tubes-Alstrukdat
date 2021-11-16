#include <stdio.h>
#include "../ADT/Player/player.h"

int main(){
    /*KAMUS LOKAL*/
    Lokasi locPlayer, locMove;
    POINT pointPlayer, pointMove;
    Player player1;

    /*ALGORITMA*/
    // Membuat player
    pointPlayer = MakePOINT(3,4);
    locPlayer = CreateLokasi('A', pointPlayer);
    CreatePlayer(&player1, locPlayer);

    pointMove = MakePOINT(5,6);
    locMove = CreateLokasi('B', pointMove);

    // Display data player
    printf("Lokasi Player1: "); 
    TulisLokasi(LOKASI_PLAYER(player1));
    printf("\n");
    printf("Uang player: %d\n", UANG_PLAYER(player1));
    printf("Berat efek heavy item: %d\n", BERAT_PLAYER(player1));
    if(SPEED_BOOST_PLAYER(player1)){
        printf("Player mendapatkan ability ability speed boost\n");
    }else{
        printf("Player tidak mendapatkan ability ability speed boost\n");
    }
    printf("Jumlah pergerakan saat mendapat efek speedMove: %d\n", SPEED_MOVE_PLAYER(player1));
    printf("Jumlah efek return item: %d\n",JUMLAH_RETURN_PLAYER(player1));
    printf("Waktu Player: %d\n", WAKTU_PLAYER(player1));
    printf("Waktu Pengurangan Perishable Item: %d\n", WAKTU_TAMBAH_PLAYER(player1));

    // Edit player
    printf("---------------------------\n");
    printf("Memindahkan player ke lokasi B (5,6)\n");
    movePlayer(&player1, locMove);
    printf("Mengubah uang player menjadi 500\n");
    UANG_PLAYER(player1) = 500;

    // Display data player
    printf("---------------------------\n");
    printf("Lokasi Player1: "); 
    TulisLokasi(LOKASI_PLAYER(player1));
    printf("\n");
    printf("Uang player: %d\n", UANG_PLAYER(player1));
    printf("Berat efek heavy item: %d\n", BERAT_PLAYER(player1));
    if(SPEED_BOOST_PLAYER(player1)){
        printf("Player mendapatkan ability ability speed boost\n");
    }else{
        printf("Player tidak mendapatkan ability ability speed boost\n");
    }
    printf("Jumlah pergerakan saat mendapat efek speedMove: %d\n", SPEED_MOVE_PLAYER(player1));
    printf("Jumlah efek return item: %d\n",JUMLAH_RETURN_PLAYER(player1));
    printf("Waktu Player: %d\n", WAKTU_PLAYER(player1));
    printf("Waktu Pengurangan Perishable Item: %d\n", WAKTU_TAMBAH_PLAYER(player1));

    return 0;
}