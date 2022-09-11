/* Program   : maintabel.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 5, September 2022*/


#include <stdio.h>
#include "tabel.h"

int main(){
    // Kamus
    Tabel T1, T2;
    int byk, N, pos;
    
    // Algoritma
    
    createTable(&T1);
    printf("Isi tabel T1 mula mula:\n");
    printTable(T1);
    printf("\n");

    printf("is empty? %d\n", isEmptyTable(T1));
    printf("is full?  %d\n", isFullTable(T1));
    printf("size : %d\n", getSize(T1));
    printf("empty: %d\n", countEmpty(T1));
    printf("\n");


    printf("Populating...\n");
    populate2(&T1);
    printf("\n");

    printf("Isi tabel T1:\n");
    viewTable(T1);
    printf("\n");

    printf("size : %d\n", getSize(T1));
    printf("empty: %d\n", countEmpty(T1));
    printf("is empty? %d\n", isEmptyTable(T1));
    printf("is full?  %d\n", isFullTable(T1));
    countX(T1, 1, &byk);
    printf("Banyak elemen 1 dalam T1: %d\n", byk);
    printf("Nilai maks dalam T1     : %d\n", getMaxEl(T1));
    printf("Nilai min  dalam T1     : %d\n", getMinEl(T1));
    printf("Jumlah elemen elemen T1 : %d\n", SumEl(T1));
    printf("Rata rata elemen T1     : %f\n", AverageEl(T1));
    printf("modus T1                : %d", Modus(T1));
    printf("\n");


    printf("Membuat tabel baru(T2)...\n");
    createTable(&T2);
    printf("Panjang tabel (1-10)? : ");
    scanf("%d", &N);
    printf("Populating T2 with %d element...\n", N);
    populate1(&T2, N);
    printf("\n");

    printf("Isi tabel T2:\n");
    viewTable(T2);
    printf("\n");

    printf("Melakukan pencarian elemen 4 dalam T2...\n");
    searchX1(T2, 4, &pos);
    printf("Elemen 4 pertama berada di indexke-%d\n", pos);
    printf("\n");

    printf("Menambahkan elemen 8 ke dalam T2...\n");
    addXTable(&T2, 8);
    printf("\n");

    printf("Isi tabel T2:\n");
    viewTable(T2);
    printf("size : %d\n", getSize(T2));
    printf("\n");

    printf("menghapus satu elemen 8 di T2...\n");
    delXTable(&T2, 8);
    printf("\n");

    printf("Isi tabel T2:\n");
    viewTable(T2);
    printf("size : %d\n", getSize(T2));
    printf("\n");

    printf("menghapus semua elemen 3 di T2...\n");
    delAllXTable(&T2, 3);
    printf("\n");

    printf("Isi tabel T2:\n");
    viewTable(T2);
    printf("size : %d\n", getSize(T2));
    printf("\n");




}