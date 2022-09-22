/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 19/09/2022*/
/***********************************/

#include <stdio.h>
#include "tstack.h"

// merubah boolean bentuk angka 0 | 1 menjadi false | true
char* b2s(boolean b){
	return b ? "true" : "false";
}

boolean isPalindrom( Tstack T){
	// Kamus lokal
	int i;
	int panjang;
	Tstack pal;
	boolean assumsi;
	char e, f;
	
	// Algoritma
	panjang = T.top;
	createStack(&pal);
	for( i = 1; i <= panjang/2; i++){
		pop(&T, &e);
		push(&pal, e);
	}

	assumsi = true;
	while( assumsi && !isEmptyStack(pal)){
		pop(&T, &e);
		pop(&pal, &f);
		assumsi &= e == f;		
	}

	return assumsi;
}

int main() 
{	
	/* kamus main */
	Tstack A, P; // variabel A bertipe tStack
	int n; // tinggi(banyak) elemen stack
	char e;

	/* algoritma */
	createStack( &A );
	printStack(A);
	printf("Apakah stack A kosong ? %s\n", b2s(isEmptyStack(A)));
	printf("Apakah stack A penuh  ? %s\n", b2s(isFullStack(A)));

	printf("Mengisi stack dengan huruf...\n");
	printf("Tinggi stack (1 - 10) ? ");
	scanf("%d", &n);
	pushN(&A, n);
	printf("Stack sekarang(%d):\n", A.top);
	viewStack(A);
	printf("Apakah stack A kosong ? %s\n", b2s(isEmptyStack(A)));
	printf("Apakah stack A penuh  ? %s\n", b2s(isFullStack(A)));
	printf("\n");
	printf("Melakukan pop terhadap stack A...\n");
	pop(&A, &e);
	printf("Elemen yang di pop: %c\n", e);
	printf("Stack sekarang(%d):\n", A.top);
	viewStack(A);

	// algoritma palindrom
	createStack( &P );
	printf("Menmbuat stack baru untuk di cek apakah palindrom...\n");
	printf("Mengisi stack dengan huruf...\n");
	printf("Tinggi stack (1 - 10) ? ");
	scanf("%d", &n);
	pushN(&P, n);
	printf("Apakah stack P palindrom ? %s\n", b2s(isPalindrom(P)));


	
	
	
	return 0;
}
