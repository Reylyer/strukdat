/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121130063*/
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include <stdbool.h>
#include "matriks.h"


void makeMatriks(Matriks *M){
	// Kamus lokal
	int i, j;
	
	// Algoritma
	
	(*M).nbbar = 0; 
	M->nbkol = 0; 
	for (i = 0; i < 11; i++)
	{
		for(j=0;j<11;j++){
			(*M).wadah[i][j] = -999;
		}
	}
}



/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
	// Kamus lokal
	
	
	// Algoritma
	
	return M.nbbar;
}

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbkol(Matriks M){
	// Kamus lokal
	
	
	// Algoritma
	
	return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
	// Kamus lokal
	
	
	// Algoritma
	
	return M.wadah[X][Y];
}

/*********MUTATOR*/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X){
	// Kamus lokal
	
	
	// Algoritma
	
	M->nbbar = X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y){
	// Kamus lokal
	
	
	// Algoritma
	
	M->nbkol = Y;
}

/*procedure setInfoCell(input/output M:Matriks, 
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C){
	// Kamus lokal
	
	
	// Algoritma
	
	M->wadah[X][Y] = C;
}

/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
bool isEmptyMatriks(Matriks M){
	// Kamus lokal
	
	
	// Algoritma
	
	return M.nbbar == 0 || M.nbkol == 0;
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
bool isFullMatriks(Matriks M){
	// Kamus lokal
	
	
	// Algoritma
	
	return M.nbbar == 10 && M.nbkol == 10;
}

/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
	// Kamus lokal
	int i, j;
	
	// Algoritma
	
	for (i = 1; i <= 10; i++)
	{
		for(j = 1; j <= 10; j++){
			printf("%d ",(M).wadah[i][j]);
		}
		printf("\n");
	}
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M){
	// Kamus lokal
	int i, j;
	
	// Algoritma
	
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				printf("%d ",(M).wadah[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Matriks Kosong!\n");
	}
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
	// Kamus lokal
	int sum, i, j;
	
	// Algoritma
	
	sum = 0;
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar ; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				sum += M.wadah[i][j];
			}
		}
	}
	return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M){
	return !isEmptyMatriks(M) ? sumCellMatriks(M)/(M.nbbar*M.nbkol) : 0;
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
	// Kamus lokal
	int max, i, j;
	
	// Algoritma
	
	max = M.wadah[1][1];
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				if(max<M.wadah[i][j]){
					max = M.wadah[i][j];
				}
			}
		}
	}
	return max;
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M){
	// Kamus lokal
	int min, i, j;
	
	// Algoritma
	
	min = M.wadah[1][1];
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				if(min > M.wadah[i][j]){
					min = M.wadah[i][j];
				}
			}
		}
	}
	return min;
}


/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A){
	// Kamus lokal
	int count = 0;
	int i, j;
	
	// Algoritma
	
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				if(M.wadah[i][j]==A){
					count++;
				}
			}
		}
	}
	return count;
}

/*procedure searchMatriks(input M:Matriks, input A:integer, 
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A){
	// Kamus lokal
	int X=-999,Y=-999;
	int i, j;
	
	
	// Algoritma
	
	if(!isEmptyMatriks(M)){
		for (i = 1; i <= M.nbbar; i++)
		{
			for(j = 1; j <= M.nbkol; j++){
				if(M.wadah[i][j]==A){
					X=i+1;
					Y=j+1;
				}
			}
		}
		
	}
	printf("Nilai %d ada di baris ke-%d kolom ke-%d\n",A,X,Y);
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks, 
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M){
	// Kamus lokal
	int i, j, buffer;
	
	// Algoritma
	
	if(!isEmptyMatriks(*M)){
		for( i = 1; i <= M->nbbar; i++)
		{
			for ( j = i+1; j <= M->nbkol; j++ ) 
			{
				buffer = M->wadah[i][j];
				M->wadah[i][j] = M->wadah[j][i];
				M->wadah[j][i] = buffer;
			}
		}
		buffer = M->nbbar;
		M->nbbar = M->nbkol;
		M->nbkol = buffer;
	}
}

/*procedure setMatriks(input/output M:Matriks, 
  input X:integer, input Y:integer)*/
/*{I.S.: M,X,Y, terdefinisi}*/
/*{F.S.: M terdefinisi, M.nbbar=X, M.nbkol=Y }*/
/*{proses: membuat matriks dengan baris dan kolom efektif yang diinputkan }*/
void setMatriks(Matriks *M, int X, int Y){
	// Kamus lokal
	int valBar, valKol;
	int i, j;
	
	// Algoritma
	
	for ( i = 1; i <= X; i++)
	{
		for(j = 1; j <= Y; j++){
			printf("Matriks [%d][%d] : ",i,j);
			scanf("%d",&M->wadah[i][j]);
		}
	}
}

/* 
========================================================================
========================= TUGAS Submission 1 ===========================
========================================================================
*/

/*function MulMatriks(M1:Matriks,M2:Matriks)->Matriks*/
/*{proses: Mengirim hasil perkalian matriks: salinan M1 * M2 }*/
Matriks MulMatriks (Matriks M1, Matriks M2){
    // Kamus lokal
    Matriks res;
    int local_sum;
    int i, j, k;
    
    // Algoritma
    makeMatriks(&res);
    if( getNbkol(M1) != getNbkol(M2)){
        printf("Panjang kolom M1 tidak sama dengan Baris M2\n");
    } else {
        setNbbar(&res, getNbbar(M1));
        setNbkol(&res, getNbkol(M2));
        for( i = 1; i <= getNbbar(res); i++){
            for( j = 1; j <= getNbkol(M2); j++){
                local_sum = 0;
                for( k = 1; k <= getNbkol(M1); k++)
                    local_sum += getInfoCell(M1, i, k) * getInfoCell(M2, k, j);
                setInfoCell(&res, i, j, local_sum);
            }
        }
    }

    return res;
}

/*function isEqualMatriks(input M1:Matriks,M2:Matriks)->boolean*/
/*{proses: Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }*/
bool isEqualMatriks (Matriks M1, Matriks M2){
    // Kamus lokal
    
    
    // Algoritma
    return getNbbar(M1) == getNbbar(M2) && getNbkol(M1) == getNbkol(M2);
}

/*function IsSquareMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks dg ukuran baris dan kolom sama}*/
bool IsSquareMatriks (Matriks M){
    // Kamus lokal
    
    
    // Algoritma
    return getNbbar(M) == getNbkol(M);
}

/*function DeterminanMatriks(M:Matriks)->float*/
/*{proses: Menghitung nilai determinan M}*/
float DeterminanMatriks (Matriks M){ 
    // ekspansi laplace, kompleksitas O(n!) xixixixixixi, tabel kecil doang ndak masalah
    // https://en.wikipedia.org/wiki/Laplace_expansion

    // Kamus lokal
    int i, j, k;
    int skip;
    float total;
    int kofaktor;
    Matriks minor;

    // Algoritma
    if(!IsSquareMatriks(M))
        printf("Bukan matriks persegi!\n");
    else{
        // abis bis bis bis bis pulangkan itu elemen terminate rekursif syuh
        if( getNbbar(M) == 1) return getInfoCell(M, 1, 1);

        total = 0;
        for( i = 1; i <= getNbbar(M); i++){
            // siapin matriks untuk di send ke rekursi selanjutnya
            makeMatriks(&minor);
            setNbbar(&minor, getNbbar(M) - 1);
            setNbkol(&minor, getNbkol(M) - 1);

            // weird things happens here, j adalah kolom
            // bukan baris (untuk menyimpelkan var skip)
            skip = 0;
            for( j = 1; j <= getNbbar(M); j++){
                if( j == i) skip++;
                else for( k = 1; k <= getNbkol(M); k++)
                        setInfoCell(&minor, k, j - skip, getInfoCell(M, k + 1, j));   
            }
			// viewMatriks(minor);

            // kofaktor
            kofaktor  = getInfoCell(M, 1, i);
            kofaktor *= (i%2) ? -1 : 1;

            total += kofaktor * DeterminanMatriks(minor);
        }
        return -total;
    }
    
}

/*function IsSatuanMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks satuan 
dg setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0}*/
bool IsSatuanMatriks (Matriks M){
    // Kamus lokal
    bool assumsi;
    int i, j;
    int ordo;

    // Algoritma
    assumsi = true;
    if(!IsSquareMatriks(M)){
        printf("Bukan matriks persegi!\n");
        assumsi = false;
    }else {
        ordo = getNbbar(M);
        for( i = 1; i <= ordo; i++){
            for( j = 1; j <= ordo; j++){
                if(i == j){
                    assumsi &= getInfoCell(M, i, j) == 1;
                    // printf("1 ");
                } else {
                    assumsi &= getInfoCell(M, i, j) == 0;
                    // printf("0 ");
                }
            }
            // printf("\n");
        }
    }

    return assumsi;
}

/*function IsSparseMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks sparse: matriks “jarang” dengan definisi: 
hanya maksimal 5% dari element matriks yang efektif bukan bernilai kosong(-999)}*/
bool IsSparseMatriks (Matriks M){
    // Kamus lokal
    
    
    // Algoritma
    return isEmptyMatriks ? 0 : countA(M, 0) / (float)(getNbbar(M) * getNbkol(M)) < 0.05;
}

