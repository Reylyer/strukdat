#include "tqueue1.h"
#include <stdio.h>
/* Program   : tqueue1.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 26/09/2022*/
/***********************************/


/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan '#' }*/ 
void createQueue(tqueue *Q){
	// Kamus lokal
	int i;
	
	// Algoritma
	
	for( i = 0; i < MAX_QUEUE; i++){
		Q->wadah[i] = '#';
	}
	Q->head = 0;
	Q->tail = 0;
  
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    return Q.wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    return Q.wadah[tail(Q)];
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    // Kamus lokal
    int i;
	
	// Algoritma
	
	for( i = 1; i < MAX_QUEUE - 1; i++){
		printf("%c;", Q.wadah[i]);
	}
	printf("%c\n", Q.wadah[i]);
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}*/
void viewQueue(tqueue Q){
    // Kamus lokal
	int i;
	
	// Algoritma
	if( ! isEmptyQueue(Q)){
        for( i = 1; i < Q.tail; i++){
            printf("%c;", Q.wadah[i]);
        }
        printf("%c\n", Q.wadah[i]);
    }
    else {
        printf("Queue kosong!\n");
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    
    return head(Q) == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    
    return tail(Q) == MAX_QUEUE - 1;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    // Kamus lokal
    
    
    // Algoritma
    
    return tail(Q) == 1 && head(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: Q,E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
    // Kamus lokal
    
    
    // Algoritma

    if ( ! isFullQueue(*Q)){
        if ( isEmptyQueue(*Q)) Q->head = 1;

        Q->tail++;

        Q->wadah[Q->tail] = E;
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: Q terdefinisi}
{F.S.: E=infohead(Q) atau E='#' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    // Kamus lokal
    int i;
    
    // Algoritma
    if( ! isEmptyQueue(*Q)){
        *E = infoHead(*Q);

        for( i = Q->head; i < Q->tail; i++)
            Q->wadah[i] = Q->wadah[i+1];
        Q->wadah[Q->tail] = '#';

        if( isOneElement(*Q)) Q->head = 0;

        Q->tail--;
    }
    else *E = '#';
}

/*********************************************************************/
/*tambahan tidak wajib, hanya dikerjakan bila luang */

/*function longer(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int longer(tqueue Q1, tqueue Q2){
    // Kamus lokal
    
    
    // Algoritma
    return sizeQueue(Q1) > sizeQueue(Q2) ? sizeQueue(Q1) : sizeQueue(Q2);
}

/*procedure enqueueShort( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek (salah satu, Q1 atau Q2)} */
void enqueueShort(tqueue *Q1, tqueue *Q2, char E){
    // Kamus lokal
    
    
    // Algoritma
    longer(*Q1, *Q2) == sizeQueue(*Q1) ? enqueue(Q2, E) : enqueue(Q1, E);
}

/*procedure deQueueLong( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2, atau E='#' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeueLong(tqueue *Q1, tqueue *Q2, char *E){
    // Kamus lokal
    
    
    // Algoritma
    longer(*Q1, *Q2) == sizeQueue(*Q1) ? dequeue(Q1, E) : dequeue(Q2, E);
}

