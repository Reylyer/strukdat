#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype info;
    address next;
} ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
typedef struct
{
    address First;
} List;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
bool ListEmpty(List L){
    // Kamus lokal
    
    
    // Algoritma
    return L.First == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
/****************** Manajemen Memori ******************/
address Alokasi(infotype X){
    // Kamus lokal
    address addr_X;

    
    // Algoritma
    addr_X = (address)malloc( sizeof (address));
    if (addr_X != Nil){
        addr_X->info = X;
        addr_X->next = Nil;
    } else {
        addr_X = Nil;
    }
    return addr_X;
    
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi(address *P){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X){
    // Kamus lokal
    address p;
    
    // Algoritma
    p = L.First;
    if (!ListEmpty){
        do {
            if (p->info == X){
                return p;
            }
            p = p->next;
        } while (p->next != L.First);
    }
    return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
bool FSearch(List L, address P){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
address SearchPrec(List L, infotype X, address *Prec){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast(List *L, infotype X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVAfter(List *L, infotype Prec, infotype X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* procedure InsVAfter2 (input/output L: List, input Prec: infotype, input X: infotype)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */
void InsVAfter1(List *L, address Prec, address X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* procedure InsVAfter1 (input/output L: List, input Prec: address, input X: address)*/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen bernilai X setelah elemen bernilai Prec */
/* Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X){
    // Kamus lokal
    address p;
    
    // Algoritma
    if (!ListEmpty(*L)){
        DelFirst(L, &p);
        *X = p->info;
        Dealokasi(p);
    }
}
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotype *X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVAfter2(List *L, address *X, address Y){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* procedure DelVAfter2 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai address Y: nilai address disimpan pada X */
/*      dan alamat elemen X tersebut di-dealokasi */
void DelVAfter(List *L, infotype *X, infotype Y){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* procedure DelVAfter1 (input/output L: List, input/output X: infotype, input Y: infotype)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir setelah elemen dengan nilai info Y: nilai info disimpan pada X */
/*      dan alamat elemen nilsi info Y tersebut di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P){
    // Kamus lokal
    address prec, last;
    
    // Algoritma
    if( !ListEmpty(*L)){
        AdrLast(L, &prec, &last);
        last->next = P;
        P->next = L->First;
        L->First = P;
    } else {
        L->First = P;
        P->next = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter(List *L, address P, address Prec){
    // Kamus lokal
    
    
    // Algoritma
    if (!ListEmpty(*L)){
        P->next = Prec->next;
        Prec->next = P;
    }
    
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast(List *L, address P){
    // Kamus lokal
    address prec, last;
    
    // Algoritma
    if (!ListEmpty(*L)){
        AdrLast(L, &prec, &last);
        last->next = P;
        P->next = L->First;
    }
    
}
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P){
    // Kamus lokal
    address prec, last;
    
    // Algoritma
    // perlu handling 1 elemen
    if (!ListEmpty(*L)){
        AdrLast(L, &prec, &last);
        *P = L->First;
        last->next = L->First->next;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(List *L, infotype X){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast(List *L, address *P){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter(List *L, address *Pdel, address Prec){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void Printinfo(List L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
int NbElmt(List L){
    // Kamus lokal
    int jml;
    address p;
    
    // Algoritma
    p = L.First;
    if (!ListEmpty(L)){
        jml = 1;
        while(p->next != L.First){
            jml++;
            p = p->next;
        }
    } else {
        jml = 0;
    }
    return jml;
    
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

/****************** PROSES TERHADAP LIST ******************/
void DelAll(List *L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */
void InversList(List *L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
List FInversList(List L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
void CopyList(List *L1, List *L2){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
List FCopyList(List L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
void CpAlokList(List Lin, List *Lout){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void AdrLast(List *L, address *Prec, address *Last){
    // Kamus lokal
    
    
    // Algoritma
    
}
/*mencari alamat elemen terakhir dan sebelumnya*/

void Konkat(List L1, List L2, List *L3){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang �baru� */
/* Elemen L3 adalah hasil alokasi elemen yang �baru�. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

void Konkat1(List *L1, List *L2, List *L3){
    // Kamus lokal
    address P, Q;
    
    // Algoritma
    P = First(*L1);
    Q = First(*L2);
    if(P != Nil){
        First(*L3) = P;
        InsertLast(L3, Q);
    }
    else{
        First(*L3) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void Konkat_kedua(List L1, List L2, List *L3){
    // Kamus lokal
    
    
    // Algoritma
    
}

void Konkat1_2(List *L1, List *L2, List *L3){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList(List *L1, List *L2, List L){
    // Kamus lokal
    
    
    // Algoritma
    
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */

#endif // LIST1_H_INCLUDED