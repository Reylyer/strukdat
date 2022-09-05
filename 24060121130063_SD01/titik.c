/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060121130063/Givandra Haikal Adjie*/
/* Tanggal   : 29 Agustus 2022*/
/***********************************/
#include <stdio.h>
#include <math.h>
#include "titik.h"

void makeTitik(Titik *T){
    (*T).absis = 0;
    (*T).ordinat = 0;
}

int getAbsis(Titik T){
    return T.absis;
}

int getOrdinat(Titik T){
    return T.ordinat;
}

void setAbsis(Titik *T, int xx){
    (*T).absis = xx;
}

void setOrdinat(Titik *T, int yy){
    (*T).ordinat = yy;
}

boolean isOrigin(Titik T){
    return T.absis == 0 && T.ordinat == 0;
}

void geserXY(Titik *T, int dx, int dy){
    (*T).absis += dx;
    (*T).ordinat += dy;
}

void refleksiSumbuX(Titik *T){
    (*T).ordinat *= -1;
}

void refleksiSumbuY(Titik *T){
    (*T).absis *= -1;
}

int Kuadran(Titik T){

    if (getAbsis(T) >= 0){
        if (getOrdinat(T) >= 0) return 1;
        else return 4;
    }
    else {
        if (getOrdinat(T) >= 0) return 2;
        else return 3;
    }
}

float Jarak(Titik T1, Titik T2){
    return sqrt( (getAbsis(T2) - getAbsis(T1)) * (getAbsis(T2) - getAbsis(T1)) + 
                 (getOrdinat(T2) - getOrdinat(T1)) * (getOrdinat(T2) - getOrdinat(T1)));
}

