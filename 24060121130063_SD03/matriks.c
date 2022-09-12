/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121130063*/
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include <stdbool.h>
#include "matriks.h"


void makeMatriks(Matriks *M){
	(*M).nbbar = 0; 
	M->nbkol = 0; 
	for (int i = 0; i < 10; i++)
	{
		for(int j=0;j<10;j++){
			(*M).wadah[i][j] = -999;
		}
	}
}

void printMatriks(Matriks M)
{
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++){
			printf("%d ",(M).wadah[i][j]);
		}
		printf("\n");
	}
}

void viewMatriks(Matriks M)
{
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				printf("%d ",(M).wadah[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Matriks Kosong!\n");
	}
}

int getNbbar(Matriks M){
	return M.nbbar;
}

int getNbkol(Matriks M){
	return M.nbkol;
}

int getInfoCell(Matriks M, int X, int Y){
	return M.wadah[X][Y];
}

void setNbbar(Matriks *M, int X){
	M->nbbar = X;
}

void setNbkol(Matriks *M, int Y){
	M->nbkol = Y;
}

void setInfoCell(Matriks *M, int X, int Y, int C){
	M->wadah[X][Y] = C;
}

bool isEmptyMatriks(Matriks M){
	return M.nbbar == 0 || M.nbkol == 0;
}

bool isFullMatriks(Matriks M){
	return M.nbbar == 10 && M.nbkol == 10;
}

int sumCellMatriks(Matriks M){
	int sum;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar ; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				sum += M.wadah[i][j];
			}
		}
	}
	return sum;
}

float avgCellMatriks(Matriks M){
	return (!isEmptyMatriks(M)?sumCellMatriks(M)/(M.nbbar*M.nbkol) : '\0');
}

int maxCellMatriks(Matriks M){
	int max = M.wadah[0][0];
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(max<M.wadah[i][j]){
					max = M.wadah[i][j];
				}
			}
		}
	}
	return max;
}

int minCellMatriks(Matriks M){
	int min = M.wadah[0][0];
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(min>M.wadah[i][j]){
					min = M.wadah[i][j];
				}
			}
		}
	}
	return min;
}

int countA(Matriks M, int A){
	int count;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(M.wadah[i][j]==A){
					count++;
				}
			}
		}
	}
	return count;
}

void searchMatriks(Matriks M, int A){
	int X=-999,Y=-999;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(M.wadah[i][j]==A){
					X=i+1;
					Y=j+1;
				}
			}
		}
		
	}
	printf("Nilai %d ada di baris ke- %d kolom ke- %d\n",A,X,Y);
}

void transpose(Matriks *M){
	if(!isEmptyMatriks(*M)){
		for( int i = 0; i < M->nbbar; i++)
		{
			for ( int j = i+1; j < M->nbkol; j++ ) 
			{
				int buffer = M->wadah[i][j];
				M->wadah[i][j] = M->wadah[j][i];
				M->wadah[j][i] = buffer;
			}
		}
		int buffer = M->nbbar;
		M->nbbar = M->nbkol;
		M->nbkol = buffer;
	}
}
void setMatriks(Matriks *M, int X, int Y){
	int valBar, valKol;
	for (int i = 0; i < X; i++)
	{
		for(int j=0;j<Y;j++){
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
        for( i = 0; i < getNbbar(res); i++){
            for( j = 0; j < getNbkol(M2); j++){
                local_sum = 0;
                for( k = 0; k < getNbkol(M1); k++)
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
        if( getNbbar(M) == 1) return getInfoCell(M, 0, 0);

        total = 0;
        for( i = 0; i < getNbbar(M); i++){
            // siapin matriks untuk di send ke rekursi selanjutnya
            makeMatriks(&minor);
            setNbbar(&minor, getNbbar(M) - 1);
            setNbkol(&minor, getNbkol(M) - 1);

            // weird things happens here, j adalah kolom
            // bukan baris (untuk menyimpelkan var skip)
            skip = 0;
            for( j = 0; j < getNbbar(M); j++){
                if( j == i) skip++;
                else
                    for( k = 0; k < getNbkol(M); k++)
                        setInfoCell(&minor, k, j - skip, getInfoCell(M, k + 1, j));   
            }

            // kofaktor
            kofaktor  = getInfoCell(M, 0, i);
            kofaktor *= (i%2) ? -1 : 1;

            total += kofaktor * DeterminanMatriks(minor);
        }
        return total;
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
        for( i = 0; i < ordo; i++){
            for( j = 0; j < ordo; j++){
                if((i == j) || (i == ordo - j - 1) || (j == ordo - i - 1)){
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

