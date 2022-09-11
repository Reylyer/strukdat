#ifndef   tabel_c
#define   tabel_c

#include "stdlib.h"
#include "tabel.h"
/*Deskripsi : File realisasi dari tabel.h*/
/*Pembuat   : Givandra Haikal Adjie*/
/*Tanggal   : 5, September 2022*/

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){  // x
    // Kamus Lokal
    int i;
    
    // Algortima
    (*T).size = 0;
    for( i = 0; i < TABEL_SIZE; i++){
        (*T).wadah[i] = -999;
    }
}


/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){ // x
    // Kamus Lokal
    int i;

    // Algortima
    for( i = 0; i < TABEL_SIZE; i++){
        printf("%d", T.wadah[i]);
        if( i == TABEL_SIZE - 1) printf("\n");
        else printf(" ");
    }

}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){ // x
    // Kamus Lokal
    int i;

    // Algortima
    if(isEmptyTable(T))
        printf("Tabel Kosong\n");
    else{
        for( i = 0; i < T.size; i++){
            printf("%d", T.wadah[i]);
            if( i == T.size - 1) printf("\n");
            else printf(" ");
        }

    }
}

/*function getSize( T: (*Tabel).-> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){ // x
   // Kamus Lokal

    // Algortima
    return T.size;
}

/*function countEmpty( T: (*Tabel).-> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){ // x
     // Kamus Lokal
    
     // Algortima
    return TABEL_SIZE - getSize(T);
}

/*function isEmptyTable( T: (*Tabel).-> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){ // x
     // Kamus Lokal
    
     // Algortima
    return getSize(T) == 0;
}

/*function isFullTable( T: (*Tabel).-> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){ // x
     // Kamus Lokal
    
     // Algortima
    return getSize(T) == TABEL_SIZE;
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){ // x
    // Kamus Lokal
    int i, temp;
    
    // Algortima
    if( N < 0 || N > TABEL_SIZE)
        printf("N tidak valid");
    else {
        i = 0;
        printf("Masukkan nilai tabel ke-%d: ", i);
        scanf("%d", &temp);
        while( i < N){
            if( temp > 0){
                (*T).wadah[i] = temp;
                i++;
            } else
                printf("Masukkan tidak valid, value harus positif\n");
            printf("Masukkan nilai tabel ke-%d: ", i);
            scanf("%d", &temp);
        }
        (*T).size = N;
    }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){ // x
    // Kamus Lokal
    
    // Algortima
    *Pos = 0;
    while( *Pos != TABEL_SIZE && T.wadah[*Pos] != X)
        (*Pos)++;
    
    if(*Pos == TABEL_SIZE) *Pos = -999;
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){ // x
    // Kamus Lokal
    int i;
    
    // Algortima
    *Byk = 0;
    for( i = 0; i < getSize(T); i++){
        if( T.wadah[i] == X){
            (*Byk)++;
        }
    }
}

/*function SumEl ( T:(*Tabel )).> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){ // x
    // Kamus lokal
    int i, sum;
    
    // Algoritma
    sum = 0;
    for( i = 0; i < getSize(T); i++){
        sum += T.wadah[i];
    }
    return sum;
}

/*function AverageEl ( T:(*Tabel )).> real 
	{mengembalikan nilai rata-rata elemen pengisi T } */
float AverageEl (Tabel T){ // x
    // Kamus lokal
    float avg;
    
    // Algoritma
    avg = SumEl(T) / (float)getSize(T);
    return avg;
}

/*function getMaxEl ( T: (*Tabel).-> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){ // x
    // Kamus lokal
    int i, max;
    
    // Algoritma
    if(isEmptyTable(T)){
        printf("Tabel kosong\n");
    } else {
        max = T.wadah[0];
        for( i = 1; i < getSize(T); i++){
            if(max < T.wadah[i])
                max = T.wadah[i];
        }
    }
    
    return max;
}

/*function getMinEl ( T: (*Tabel).-> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){ // x
    // Kamus lokal
    int i, min;
    
    // Algoritma
    if(isEmptyTable(T)){
        printf("Tabel kosong\n");
    } else {
        min = T.wadah[0];
        for( i = 1; i < getSize(T); i++){
            if(min > T.wadah[i])
                min = T.wadah[i];
        }
    }
    
    return min;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){ // x
    // Kamus Lokal
    int i, temp;
    
    // Algortima
    i = 0;
    printf("Masukkan nilai tabel ke-%d: ", i);
    scanf("%d", &temp);

    while( i < TABEL_SIZE && temp > 0){
        (*T).wadah[i] = temp;
        i++;
        printf("Masukkan nilai tabel ke-%d: ", i);
        scanf("%d", &temp);
    }
    printf("Memberhentikan input\n");

    (*T).size = i;
    
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){ // x
    // Kamus lokal
    int posisi;
    
    // Algoritma
    if( !isFullTable(*T)){
        if( X > 0){
            posisi = getSize(*T);
            (*T).wadah[posisi] = X;
            (*T).size++;
        } else {
            printf("X tidak valid!\n");   
        }
    } else {
        printf("Tabel penuh!\n");
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){ // x
    // Kamus lokal
    int i, j;
    
    // Algoritma
    i = 0;
    while( (*T).wadah[i] != X && i != TABEL_SIZE)  i++;
    for( j = i; j < TABEL_SIZE; j++){
        (*T).wadah[j] = (*T).wadah[j + 1];
    }

    if( i != TABEL_SIZE) {
        (*T).wadah[TABEL_SIZE - 1] = -999;
        (*T).size--;
    }
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){ // x
    // Kamus lokal
    int i, pos;
    
    // Algoritma
    searchX1(*T, X, &pos);
    while(pos != -999){
        delXTable(T, X);
        searchX1(*T, X, &pos);
    }
}

/*function Modus ( T:(*Tabel )).> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
    // Kamus lokal
    Tabel Tt;
    int i, byk, modId;
    
    // Algoritma
    createTable(&Tt);
    Tt.size = getSize(T);
    for( i = 0; i < getSize(T); i++){
        countX(T, T.wadah[i], &byk);
        Tt.wadah[i] = byk;
    }

    searchX1(Tt, getMaxEl(Tt), &modId);

    return T.wadah[modId];
}

#endif