/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 29 Agustus 2022*/
/***********************************/
#include <stdio.h>
#include "titik.h"



int main() {
	//kamus main
	Titik A;
	Titik B;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	printf("\n");


	makeTitik(&A);

	printf("absis dari A: %d\n", getAbsis(A));
	printf("ordinat dari A: %d\n", getOrdinat(A));
	printf("\n");

	setAbsis(&A, 6);
	setOrdinat(&A, 9);

	printf("Setelah dilakukan set absis dan ordinat:\n");
	printf("absis dari A: %d\n", getAbsis(A));
	printf("ordinat dari A: %d\n", getOrdinat(A));
	printf("Apakah titik A berada di origin: %d\n", isOrigin(A));
	printf("\n");

	geserXY(&A, -2, -3);

	printf("Setelah dilakukan pergeseran:\n");
	printf("absis dari A: %d\n", getAbsis(A));
	printf("ordinat dari A: %d\n", getOrdinat(A));
	printf("\n");


	refleksiSumbuX(&A);

	printf("Setelah dilakukan refleksi di sumbu X:\n");
	printf("absis dari A: %d\n", getAbsis(A));
	printf("ordinat dari A: %d\n", getOrdinat(A));
	printf("\n");

	refleksiSumbuY(&A);

	printf("Setelah dilakukan refleksi di sumbu Y:\n");
	printf("absis dari A: %d\n", getAbsis(A));
	printf("ordinat dari A: %d\n", getOrdinat(A));
	printf("Titik A berada di kuadaran %d\n", Kuadran(A));
	printf("\n");


	makeTitik(&B);
	setAbsis(&B, 1);
	setOrdinat(&B, 1);

	printf("absis dari B: %d\n", getAbsis(B));
	printf("ordinat dari B: %d\n", getOrdinat(B));
	printf("\n");

	printf("jarak dari euclidian dari titik A ke titik B adalah %f satuan\n", Jarak(A, B));
	

	
	return 0;
}
