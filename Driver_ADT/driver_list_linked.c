//Driver Linked list

#include"../ADT/LinkedList/list_linked.h"
#include<stdio.h>

int main(){
	/*KAMUS*/
	ListLinked l;
	ListLinked add;
	ListLinked hasil;
	ElTypeNode oneOfaKind,twoOfaKind, threeOfaKind, trash; // elemen type item
	POINT tempp,tempd;
	Lokasi templokawal, templokakhir;

	/*ALGORITMA*/
	CreateListLinked(&l);
	CreateListLinked(&add);
	CreateListLinked(&hasil);
	//Mengecek list jika empty atau tidak
	if (isEmptyListLinked(l)){
		printf("Linked list is empty\n");
	}

	// Membuat tiga jenis item
	tempp = MakePOINT(2,3);
	tempd = MakePOINT(5,6);
	templokawal = CreateLokasi('A', tempp);
	templokakhir = CreateLokasi('B', tempd);
	oneOfaKind = CreateItem('N',templokawal, templokakhir, 10);

	tempp = MakePOINT(5,9);
	tempd = MakePOINT(2,1);
	templokawal = CreateLokasi('C', tempp);
	templokakhir = CreateLokasi('D', tempd);
	twoOfaKind = CreateItem('P',templokawal, templokakhir, 10);
	WAKTU_LEWAT_ITEM(twoOfaKind) = 0;

	tempp = MakePOINT(8,10);
	tempd = MakePOINT(1,1);
	templokawal = CreateLokasi('E', tempp);
	templokakhir = CreateLokasi('F', tempd);
	threeOfaKind = CreateItem('H',templokawal, templokakhir, 6);

	/* Penggunaan primitif */
	insertFirstListLinked(&l, oneOfaKind);
	printf("display isi list setelah insert elemen pertama: \n");
	displayListLinked(l);

	insertLastListLinked(&l, twoOfaKind);
	printf("display isi list setelah insert elemen terakhir: \n");
	displayListLinked(l);

	// Mengisi linked list

	for (int i = 0; i < 5; i++){
		insertFirstListLinked(&l, twoOfaKind);
		insertLastListLinked(&l,oneOfaKind);
		insertAtListLinked(&l, threeOfaKind, 3);
	}
	printf("\nIsi list sekarang setelah diinsert berulang-ulang:\n");
	displayListLinked(l);

	// Mengambil elemen index 4, kemudian didisplay
	printf("\nElemen index ke 4 linked list:\n");
	TulisItem(getElmtListLinked(l, 4));

	// Mengubah elemen ke 4, menjadi item lain
	setElmtListLinked(&l, 4, oneOfaKind);
	printf("\n\nHasil perubahan linked list pd idx ke-4:\n");
	displayListLinked(l);

	printf("\nindex linked list yang mengandung oneofakind di %d\n\n", indexOfListLinked(l, oneOfaKind));

	// Deleting elements
	deleteFirstListLinked(&l, &trash);
	printf("item elemen pertama yang didelete: ");
	TulisItem(trash);printf("\n");

	deleteLastListLinked(&l, &trash);
	printf("item elemen terakhir yang didelete: ");
	TulisItem(trash);printf("\n");

	printf("\ndisplay isi listlinked yang berisi %d\n", lengthListLinked(l));
	displayListLinked(l);

	for (int i = 0; i < 3 ; i++){
		deleteFirstListLinked(&l, &trash);
		deleteLastListLinked(&l, &trash);
	}
	printf("\nhasil delete first dan last sekaligus secaara berulang.\n");
	displayListLinked(l);

	//Menambah list baru

	insertFirstListLinked(&add, oneOfaKind);printf("\n");
	insertFirstListLinked(&add, twoOfaKind);printf("\n");

	printf("linked list baru ukuran %d\n", lengthListLinked(add));
	displayListLinked(add);

	// menggabungkan list l dengan yang baru
	hasil = concatListLinked(l,add);
	printf("setelah digabung atau di concat menjadi list baru ukuran %d\n", lengthListLinked(hasil));
	displayListLinked(hasil);

	printf("\nketika waktu melewati 4 satuan, waktu item menjadi\n");
	updateWaktuItem(&l,4);
	displayListLinked(l);

	printf("\nKemudian mengembalikan waktu perishible item teratas ialah\n");
	kembalikanWaktuItem(&l);
	displayListLinked(l);
}