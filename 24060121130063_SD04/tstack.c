/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 19/09/2022*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#define MAX_STACK 11

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
	// Kamus lokal
	int i;
	
	// Algoritma
	
	for( i = 1; i < MAX_STACK; i++){
		T->wadah[i] = '#';
	}
	T->top = 0;
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
	// Kamus lokal
	
	
	// Algoritma
	
	return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
	// Kamus lokal
	
	
	// Algoritma
	
	return T.top == MAX_STACK - 1;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
	// Kamus lokal
	
	
	// Algoritma
	if( isFullStack(*T)){
		printf("Stack penuh!\n");
	} else {
		T->top++;
		T->wadah[T->top] = E;
	}
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
	// Kamus lokal
	
	
	// Algoritma
	if( isEmptyStack(*T)){
		printf("Stack Kosong!\n");
		*X = '#';
	} else {
		*X = T->wadah[T->top];
		T->wadah[T->top] = '#';
		T->top--;
	}
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
	// Kamus lokal
	int i;
	
	// Algoritma
	
	for( i = 1; i < MAX_STACK - 1; i++){
		printf("%c;", T.wadah[i]);
	}
	printf("%c\n", T.wadah[i]);
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
	// Kamus lokal
	int i;
	
	// Algoritma
	
	for( i = 1; i < T.top; i++){
		printf("%c;", T.wadah[i]);
	}
	printf("%c\n", T.wadah[i]);
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali, bila belum penuh }*/
void pushN (Tstack *T, int N){
	// Kamus lokal
	int i;
	char buffer;
	
	// Algoritma
	if( T->top + N > MAX_STACK)
		printf("Terlalu banyak, akan menyebabkan stack overflow!\n");
	else {
		i = T->top + 1;
		while( i <= N){
			printf("Masukkan stack ke-%d: ", i);
			if(scanf(" %c", &buffer)){
				push(T, buffer);
				i++;
			}
			else
				printf("Masukkan tidak valid\n");
		}
	}
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){

}
/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
