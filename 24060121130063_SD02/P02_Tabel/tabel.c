#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/*Deskripsi : File realisasi dari tabel.h*/
/*Pembuat   : Givandra Haikal Adjie*/
/*Tanggal   : 5, September 2022*/

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    // Kamus Lokal
    int i;
    
    // Algortima
    T->size = -999;
    for( i = 0; i < TABEL_SIZE; i++){
        T->wadah[i] = -999;
    }
}


/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
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
void viewTable (Tabel T){
    // Kamus Lokal
    int i;

    // Algortima
    for( i = 0; i < T.size; i++){
        printf("%d", T.wadah[i]);
        if( i == T.size - 1) printf("\n");
        else printf(" ");
    }
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
   // Kamus Lokal

    // Algortima
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
     // Kamus Lokal
    
    
     // Algortima
    return TABEL_SIZE - T.size;
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
     // Kamus Lokal
    
     // Algortima
    return T.size == 0;
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
     // Kamus Lokal
    
     // Algortima
    return T.size == TABEL_SIZE;
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    // Kamus Lokal
    int i;
    
    // Algortima
    if( N < 0 || N > TABEL_SIZE)
        printf("");
    else {
        for( i = 0; i < N; i++){
            printf("Masukkan nilai tabel ke-%d: ", i);
            scanf("%d", T->wadah[i]);
        }
    }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    // Kamus Lokal
    int i;
    
    // Algortima
    *Pos = -999;
    for( i = 0; i < T.size; i++){
        if( T.wadah[i] == X){
            *Pos = i;
            break;
        }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    // Kamus Lokal
    int i;
    
    // Algortima
    *Byk = 0;
    for( i = 0; i < T.size; i++){
        if( T.wadah[i] == X){
            (*Byk)++;
        }
    }
}

/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){

}

/*function AverageEl ( T:Tabel ) -> integer 
	{mengembalikan nilai rata-rata elemen pengisi T } */
int AverageEl (Tabel T){

}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){

}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T){

}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){

}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){

}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){

}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){

}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){

}

#endif