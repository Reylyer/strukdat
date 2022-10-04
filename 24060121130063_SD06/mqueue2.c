/* Program   : mqueue2.c */
/* Deskripsi : file DRIVER modul Queue karakter */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 03/10/2022*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"

// merubah boolean bentuk angka 0 | 1 menjadi false | true
char* b2s(boolean b){
    return b ? "true" : "false";
}

int main() 
{	
    /* kamus main */
    tqueue2 A, B; // variabel A bertipe queue
    int n; // panjang(banyak) elemen queue
    char e;
    int i;

    /* algoritma */
    createQueue2( &A );
    printQueue2(A);
    printf("Apakah Queue A kosong ? %s\n", b2s(isEmptyQueue2(A)));
    printf("Apakah Queue A penuh  ? %s\n", b2s(isFullQueue2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isOneElement2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isTailStop(A)));

    printf("Mengisi Queue A dengan huruf...\n");
    printf("Panjang Queue (1 - 5) ? ");

    scanf("%d", &n);
    enqueue2N( &A, n);

    printf("Queue sekarang(%d):\n", sizeQueue2(A));
    viewQueue2(A);
    printQueue2(A);
    printf("Apakah Queue A kosong ? %s\n", b2s(isEmptyQueue2(A)));
    printf("Apakah Queue A penuh  ? %s\n", b2s(isFullQueue2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isOneElement2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isTailStop(A)));

    printf("\n");
    printf("Melakukan dequeue terhadap Queue A...\n");
    dequeue2(&A, &e);
    printf("Elemen yang di dequeue: %c\n", e);
    printf("Queue A sekarang(%d):\n", sizeQueue2(A));
    viewQueue2(A);
    printQueue2(A);

    dequeue2(&A, &e);
    printf("Elemen yang di dequeue: %c\n", e);
    printf("Queue A sekarang(%d):\n", sizeQueue2(A));
    viewQueue2(A);
    printQueue2(A);


    printf("Mengisi Queue A dengan huruf.. lagi...\n");
    printf("Panjang Queue (0 - %d) ? ", MAX_QUEUE - sizeQueue2(A) - 1);

    scanf("%d", &n);
    enqueue2N( &A, n);

    printf("Queue A sekarang(%d):\n", sizeQueue2(A));
    viewQueue2(A);
    printQueue2(A);


    printf("Apakah Queue A kosong ? %s\n", b2s(isEmptyQueue2(A)));
    printf("Apakah Queue A penuh  ? %s\n", b2s(isFullQueue2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isOneElement2(A)));
    printf("Apakah Queue A 1 elemen ? %s\n", b2s(isTailStop(A)));  
    
    return 0;
}
