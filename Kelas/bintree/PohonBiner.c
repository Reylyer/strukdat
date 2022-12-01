#include "PohonBiner.h"

/*{ Mengirimkan address hasil alokasi sebuah elemen X }
{ Jika alokasi berhasil, maka address tidak nil, dan misalnya
menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil
{ Jika alokasi gagal, mengirimkan Nil } */
address Alokasi (int X) {
    address P = (address) malloc (sizeof (Node));
    if (P != Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

/*{ I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P }
*/
void Dealokasi (address P) {
    free(P);
}

/*{ Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon kosong (Nil) jika alokasi gagal }
*/
BinTree Tree (infotype Akar, BinTree L, BinTree R) {
    address P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

/*{ I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal }
*/
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Tree(Akar, L, R);
}

/**{*** Predikat-Predikat Penting ***} **/

/*{ Mengirimkan true jika P adalah pohon biner yang kosong } */
boolean isTreeEmpty(BinTree P) {
    return P == Nil;
}

/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1
elemen } */
boolean isOneElmt(BinTree P) {
    return P && Left(P) == Nil && Right(P) == Nil;
}

/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
unerleft: hanya mempunyai subpohon kiri } */
boolean isUnerLeft(BinTree P) {
    return Left(P) != Nil && Right(P) == Nil;
}

/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
unerright: hanya mempunyai subpohon kanan }
*/
boolean isUnerRight(BinTree P) {
    return Left(P) == Nil && Right(P) != Nil;
}

/*{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon
biner: mempunyai subpohon kiri dan subpohon kanan }*/
boolean isBiner(BinTree P) {
    return Left(P) != Nil && Right(P) != Nil;
}

/**{*** Pemrosesan Traversal ***} **/
/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
{ F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
{ Penulisan akar selalu pada baris baru (diakhiri newline) }
*/
void PrintTreeL(BinTree P, int h, int CLevel) {
    if (!isTreeEmpty(P)) {
        for( int i = 0; i < h*(CLevel-1); i++) printf(" ");

        printf("%d\n", Akar(P));
        if (Left(P) != Nil){
            PrintTreeL(Left(P), h, CLevel+1);
        }
        if (Right(P) != Nil){
            PrintTreeL(Right(P), h, CLevel+1);
        }
    }
}

/*{ I.S. P terdefinisi, h adalah jarak indentasi (spasi) }
{ F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) }
{ Penulisan akar selalu pada baris baru (diakhiri newline) }
*/
void PrintTree(BinTree P, int h) {
    PrintTreeL(P, h, 1);
}

/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : Cetak Akar(P); cetak secara Preorder (Left(P)); cetak
secara Preorder (Right(P)) }*/
void PrintPreOrder(BinTree P) {
    PrintTree(P, 2);
}

/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : cetak secara Preorder (Left(P)); Cetak Akar(P); cetak
secara Preorder (Right(P)) } */
void PrintInOrder(BinTree P, int depth) {
    if (!isTreeEmpty(P)) {
        if (Left(P) != Nil){
            PrintInOrder(Left(P), depth+1);
        }
        for( int i = 0; i < depth + 1; i++) printf(" ");
        printf("%d\n", Akar(P));
        if (Right(P) != Nil){
            PrintInOrder(Right(P), depth+1);
        }
    }
}

/*{ I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri,
kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : cetak secara Preorder (Left(P)); cetak secara Preorder
(Right(P)); Cetak Akar(P) }
*/
void PrintPostOrder(BinTree P, int depth) {
    if (!isTreeEmpty(P)) {
        if (Left(P) != Nil){
            PrintPostOrder(Left(P), depth+1);
        }
        if (Right(P) != Nil){
            PrintPostOrder(Right(P), depth+1);
        }
        for( int i = 0; i < depth + 1; i++) printf(" ");
        printf("%d\n", Akar(P));
    }
}

/*{ Mengirimkan true jika ada node dari P yang bernilai X }
*/
boolean SearchTree(BinTree P, infotype X) {
    if (P == Nil) {
        return false;
    } else {
        return (Info(P) == X) || SearchTree(Left(P), X) || SearchTree(Right(P), X);
    }
}

/*{ Mengirimkan banyaknya elemen (node) pohon biner P } */
int NbElmt(BinTree P) {
    if (P == Nil) {
        return 0;
    } else {
        return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
    }
}

/*{ Prekondisi: Pohon Biner tidak mungkin kosong. Mengirimkan banyaknya
daun pohon }
{ Basis: Pohon yang hanya mempunyai akar: 1 }
{ Rekurens: Punya anak kiri dan tidak punya anak kanan:
NBDaun(Left(P)) Tidak Punya anak kiri dan punya anak kanan :
NBDaun(Right(P)) Punya anak kiri dan punya anak kanan :
NBDaun(Left(P)) + NBDaun(Right(P)) } */
int NBDaun(BinTree P) {
    if (isOneElmt(P)) {
        return 1;
    } else {
        if (isUnerLeft(P)) {
            return NBDaun(Left(P));
        } else if (isUnerRight(P)) {
            return NBDaun(Right(P));
        } else {
            return NBDaun(Left(P)) + NBDaun(Right(P));
        }
    }
}

/*{ Mengirimkan true jika P adalah pohon condong kiri } */
boolean isSkewLeft(BinTree P) {
    if (P == Nil) {
        return true;
    } else {
        if (isUnerLeft(P)) {
            return isSkewLeft(Left(P));
        } else {
            return false;
        }
    }
}

/*{ Mengirimkan true jika P adalah pohon condong kanan }*/
boolean isSkewRight(BinTree P) {
    if (P == Nil) {
        return true;
    } else {
        if (isUnerRight(P)) {
            return isSkewRight(Right(P));
        } else {
            return false;
        }
    }
}

/*{ Mengirimkan level dari node X yang merupakan salah satu daun dari
pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }
*/
int Level(BinTree P, infotype X) {
    if (P == Nil) {
        return 0;
    } else {
        if (Info(P) == X) {
            return 1;
        } else {
            int left = Level(Left(P), X);
            int right = Level(Right(P), X);
            if (left > 0) {
                return left + 1;
            } else if (right > 0) {
                return right + 1;
            } else {
                return 0;
            }
        }
    }
}