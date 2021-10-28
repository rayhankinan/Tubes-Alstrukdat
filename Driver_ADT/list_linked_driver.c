//Driver Linked list

#include"../ADT/LinkedList/list_linked.h"
#include<stdio.h>

int main(){
	// kamus lokal
	ListLinked l;
	ListLinked add;
	ListLinked hasil;
	int trash;


	// Algoritma
	CreateListLinked(&l);
	CreateListLinked(&add);
	CreateListLinked(&hasil);

	if (isEmptyListLinked(l)){
		printf("yes it's empty\n");
	}

	for (int i = 0; i < 2; i++){
		insertFirstListLinked(&l,1);
		insertLastListLinked(&l, 4);
		insertFirstListLinked(&l,2);
	}
	for (int i = 0; i < 2; i++){
		insertLastListLinked(&add, 3);
		insertFirstListLinked(&add,1);
	}
	printf("hasil list l:\n");
	displayListLinked(l); printf("\n");
	printf("hasil list add:\n");
	displayListLinked(add); printf("\n");
	for (int i = 0; i < 2; i++){
		insertAtListLinked(&l, 3, 1);
	}
	printf("Menambah elemen nilai 3 di index 1 pada list l sebanyak 2 kali:\n");
	displayListLinked(l); printf("\n");

	printf("Panjang list adalah : %d\n", lengthListLinked(l));

	printf("Pembuangan ...\n");
	for (int j = 0; j<2;j++){
		deleteLastListLinked(&l, &trash); // membuang elemen terakhir list
		deleteAtListLinked(&l,2,&trash); // membuang elemen index 2 list
	}
	displayListLinked(l); printf("\n");
	deleteFirstListLinked(&l, &trash);
	printf("Panjang list l sekarang setelah pembuangan barusan: %d\n", lengthListLinked(l));
	printf("elemen yang paling baru dibuang: %d\n", trash);
	displayListLinked(l); printf("\n");

	setElmtListLinked(&add, 3, 1);
	printf("Mengubah elemen index 3 ke 1 pada list add:\n");
	displayListLinked(add); printf("\n");
	printf("Isi dari list hasil:\n");
	displayListLinked(hasil); printf("\n");

	printf("index-2 dari list add adalah: %d\n", getElmtListLinked(add,2));
	printf("Index list add jika ada angka 2: %d\n", indexOfListLinked(add,2));
	printf("Index list add jika ada angka 3: %d\n", indexOfListLinked(add,3));
	printf("Index list add jika ada angka 1: %d\n", indexOfListLinked(add,1));

	hasil = concatListLinked(l,add);
	printf("Gabungan list l dan add adalah:\n");
	displayListLinked(hasil); printf("\n");
}
