/* Program   : mqueue.c */
/* Deskripsi : file DRIVER modul Queue karakter */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 26/09/2022*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"

// merubah boolean bentuk angka 0 | 1 menjadi false | true
char* b2s(boolean b){
    return b ? "true" : "false";
}

void enqueueN( tqueue *Q, int N){
    // Kamus lokal
	int i;
	char buffer;
	
	// Algoritma
	if( Q->tail + N >= MAX_QUEUE)
		printf("Terlalu banyak, akan menyebabkan overflow!\n");
	else {
		i = Q->tail + 1;
		while( i <= N){
			printf("Masukkan Queue ke-%d: ", i);
			if(scanf(" %c", &buffer)){
				enqueue(Q, buffer);
				i++;
			}
			else
				printf("Masukkan tidak valid\n");
		}
	}
}

int main() 
{	
    /* kamus main */
    tqueue A, B; // variabel A bertipe queue
    int n; // panjang(banyak) elemen queue
    char e;
    int i;

    /* algoritma */
    createQueue( &A );
    printQueue(A);
    printf("Apakah Queue A kosong ? %s\n", b2s(isEmptyQueue(A)));
    printf("Apakah Queue A penuh  ? %s\n", b2s(isFullQueue(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isOneElement(A)));

    printf("Mengisi Queue A dengan huruf...\n");
    printf("Panjang Queue (1 - 5) ? ");

    scanf("%d", &n);
    enqueueN( &A, n);

    printf("Queue sekarang(%d):\n", sizeQueue(A));
    viewQueue(A);
    printf("Apakah Queue A kosong ? %s\n", b2s(isEmptyQueue(A)));
    printf("Apakah Queue A penuh  ? %s\n", b2s(isFullQueue(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isOneElement(A)));

    printf("\n");
    printf("Melakukan dequeue terhadap Queue A...\n");
    dequeue(&A, &e);
    printf("Elemen yang di dequeue: %c\n", e);
    printf("Queue A sekarang(%d):\n", sizeQueue(A));
    viewQueue(A);

    // queue ke 2
    createQueue( &B );
    printf("Mengisi Queue B dengan huruf...\n");
    printf("Panjang Queue (1 - 5) ? ");
    scanf("%d", &n);
    enqueueN( &B, n);


    printf("Panjang Queue A : %d\n", sizeQueue(A));
    printf("Panjang Queue B : %d\n", sizeQueue(B));
    printf("Queue terpanjang memiliki panjang : %d\n", longer(A, B));
    printf("Melakukan enqueue spesial enqueueShort...\n");
    printf("Masukkan elemen yang akan di enqueue: ");
    scanf(" %c", &e);
    enqueueShort( &A, &B, e);
    printf("Queue A sekarang(%d):\n", sizeQueue(A));
    viewQueue(A);
    printf("Queue B sekarang(%d):\n", sizeQueue(B));
    viewQueue(B);

    printf("Melakukan dequeue spesial dequeueLong...\n");
    dequeueLong( &A, &B, &e);
    printf("Queue A sekarang(%d):\n", sizeQueue(A));
    viewQueue(A);
    printf("Queue B sekarang(%d):\n", sizeQueue(B));
    viewQueue(B);
    printf("elemen yang di dequeue: %c", e);

    

    
    
    return 0;
}
