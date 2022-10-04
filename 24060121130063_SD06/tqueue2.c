/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 03/10/2022*/
/***********************************/

#include "tqueue2.h" 
#include <stdio.h>


/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
// x
boolean isEmptyQueue2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    
    return Q.head == 0 && Q.tail == 0;
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
// x
boolean isFullQueue2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    
    return Q.head == 1 && Q.tail == MAX_QUEUE - 1;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
// x
boolean isOneElement2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    
    return Q.head != 0 && Q.head == Q.tail;
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
// x
void createQueue2(tqueue2 *Q){
    // Kamus lokal
	int i;
	
	// Algoritma
	
	for( i = 0; i < MAX_QUEUE; i++){
		Q->wadah[i] = '@';
	}
	Q->head = 0;
	Q->tail = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
// x
int head2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
// x
int tail2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
// x
char infoHead2(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    return Q.wadah[Q.head];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
// x
char infoTail2(tqueue2 Q){
    // Kamus lokal
    
    
    // Algoritma
    return Q.wadah[Q.tail];
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
// x
int sizeQueue2(tqueue2 Q){
    // Kamus lokal
    
    
    // Algoritma
    
    return isEmptyQueue2(Q) ? 0 :  Q.tail - Q.head + 1;
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
// x
void printQueue2(tqueue2 Q){ 
    // Kamus lokal
    int i;
	
	// Algoritma
	
	for( i = 1; i < MAX_QUEUE - 1; i++){
		printf("%c;", Q.wadah[i]);
	}
	printf("%c\n", Q.wadah[i]);
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
// x
void viewQueue2(tqueue2 Q){
    // Kamus lokal
	int i;
	
	// Algoritma
	if( ! isEmptyQueue2(Q)){
        for( i = Q.head; i < Q.tail; i++){
            printf("%c;", Q.wadah[i]);
        }
        printf("%c\n", Q.wadah[i]);
    }
    else {
        printf("Queue kosong!\n");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
// x
boolean isTailStop(tqueue2 Q){ 
    // Kamus lokal
    
    
    // Algoritma
    return Q.tail == MAX_QUEUE - 1;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
// x
void resetHead(tqueue2 *Q){
    // Kamus lokal
    int i;
    
    // Algoritma
    if( isTailStop(*Q) && ! isFullQueue2(*Q)){
        for(i = Q->head; i <= Q->tail; i++){
            Q->wadah[i - Q->head + 1] = Q->wadah[i];
            Q->wadah[i] = '@';
        }
        Q->tail = Q->tail - Q->head + 1;
        Q->head = 1;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    // Kamus lokal
    
    
    // Algoritma
    if( ! isFullQueue2(*Q)){
        if(isTailStop(*Q)) resetHead(Q);
        if(isEmptyQueue2(*Q)) Q->head = 1;
        
        Q->tail++;
        Q->wadah[Q->tail] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
// x
void dequeue2(tqueue2 *Q, char *E){
    // Kamus lokal
    
    
    // Algoritma
    if( ! isEmptyQueue2(*Q)){
        *E = infoHead2(*Q);
        Q->wadah[Q->head] = '@';

        if(isOneElement2(*Q)){
            Q->head = 0;
            Q->tail = 0;
        } else {
            Q->head++;
        }

    } else{
        *E = '@';
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    // Kamus lokal
    int i;
    char buffer;
    
    // Algoritma
    if (sizeQueue2(*Q) + N >= MAX_QUEUE){
		printf("Terlalu banyak, akan menyebabkan overflow!\n");
    } else {
        for( i = 0; i < N; i++){
            printf("Masukkan elemen: ");
			if(scanf(" %c", &buffer)){
				enqueue2(Q, buffer);
			}
			else
				printf("Masukkan tidak valid\n");
        }
    }
}
