/* Program   : mmatriks.c */
/* Deskripsi : driver file modul ADT Matriks tugas praktikum C1*/
/* NIM/Nama  : 24060*/
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include "matriks.h"

int main() {
	// kamus
	Matriks A, B, C, D;
	int NBbar,NBkol;
	int i, j;

	// algoritma
	makeMatriks(&A);
	printf("\n\n");
    printf("===========================================\n");
    printf("=========== SD-3 MATRIKS START ============\n");
	printf("===========================================\n\n");
	printf("======== PRINT MATRIKS [DEFAULT] ==========\n");
	printMatriks(A);
	printf("======== VIEW MATRIKS [DEFAULT] ===========\n");
	viewMatriks(A);
	printf("============ IS EMPTY MATRIKS =============\n");
	printf("Matriks Kosong : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("============= IS FULL MATRIKS =============\n");
	printf("Matriks Full : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("==== SET MATRIKS A [SET NBBAR | NBKOL ] ===\n");

	printf("Masukkan jumlah baris : ");
	scanf("%d",&NBbar);
	setNbbar(&A,NBbar);
	printf("Masukkan jumlah kolom : ");
	scanf("%d",&NBkol);
	setNbkol(&A,NBkol);

	setMatriks(&A,NBbar,NBkol);
	printf("============= PRINT MATRIKS A ==============\n");
	printMatriks(A);
	printf("============= VIEW MATRIKS A ===============\n");
	viewMatriks(A);
	printf("============ IS EMPTY MATRIKS ==============\n");
	printf("Matriks Kosong : %s\n\n",isEmptyMatriks(A)?"True":"False");
	printf("============= IS FULL MATRIKS =============\n");
	printf("Matriks Full : %s\n\n",isFullMatriks(A)?"True":"False");
	printf("============ GET NBBAR MATRIKS ============\n");
	printf("Jumlah Baris : %d\n\n",getNbbar(A));
	printf("============ GET NBKOL MATRIKS ============\n");
	printf("Jumlah Kolom : %d\n\n",getNbkol(A));
	printf("========== GET INFO CELL MATRIKS ==========\n");
	printf("Nilai Cell : %d\n\n",getInfoCell(A,2,3));
	printf("============= SUM CELL MATRIKS ============\n");
	printf("Sum Cell : %d\n\n",sumCellMatriks(A));
	printf("========= AVG CELL MATRIKS MATRIKS ========\n");
	printf("AVG Cell : %.1f\n\n",avgCellMatriks(A));
	printf("========== SEARCH MATRIKS MATRIKS =========\n");
	searchMatriks(A,5);
	printf("============== COUNT A MATRIKS ============\n");
	printf("Kemunculan nilai yang dicari : %d kali\n\n",countA(A,5));
	printf("============== MIN CELL MATRIKS ===========\n");
	printf("Nilai Cell Min : %d\n\n",minCellMatriks(A));
	printf("============== MAX CELL MATRIKS ===========\n");
	printf("Nilai Cell Max : %d\n\n",maxCellMatriks(A));
	printf("========== VIEW MATRIKS [NEW CELL] ========\n");
	setInfoCell(&A,0,0,5);
	viewMatriks(A);
	printf("========== VIEW MATRIKS [TRANSPOSE] =======\n");
	transpose(&A);
	viewMatriks(A);

	// Submission 1
	printf("\n\n\n");
	printf("=============== SUBMISSION 1 ==============\n");
	printf("\n\n");	
	printf("======== MEMBUAT MATRIKS BARU B %dx%d =======\n", NBbar, NBkol);
	setNbbar(&B, NBbar);
	setNbkol(&B, NBkol);
	setMatriks(&B, NBbar, NBkol);
	printf("\n");
	printf("============= VIEW MATRIKS A ===============\n");
	viewMatriks(A);
	printf("============= VIEW MATRIKS B ===============\n");
	viewMatriks(B);
	printf("\n");
	printf("======== MELAKUKAN PERKALIAN A * B =========\n");
	C = MulMatriks(A, B);
	viewMatriks(C);

	printf("========== IS EQUAL MATRIKS A B ============\n");
	printf("A equals B? : %s\n\n", isEqualMatriks(A, B) ? "True" : "False");
	printf("=========== IS SQUARE MATRIKS B ============\n");
	printf("Matriks Square? : %s\n\n", IsSquareMatriks(B) ? "True" : "False");

	printf("================ DETERMINAN ================\n");
	printf("Determinan matrix A: %f\n", DeterminanMatriks(A));
	printf("Determinan matrix B: %f\n", DeterminanMatriks(B));
	printf("Determinan matrix C: %f\n", DeterminanMatriks(C));
	printf("\n");

	printf("============ IS SATUAN MATRIKS B ===========\n");
	printf("Matriks Satuan? : %s\n\n", IsSatuanMatriks(B) ? "True" : "False");
	printf("\n");

	printf("========== MEMBUAT MATRIKS SATUAN ==========\n");
	setNbbar(&D, 9);
	setNbkol(&D, 9);
	for( i = 1; i <= 9; i++){
		for( j = 1; j <= 9; j++){
			if(i == j) {
				setInfoCell(&D, i, j, 1);
			} else {
				setInfoCell(&D, i, j, 0);
			}
		}
	}
	viewMatriks(D);

	printf("============ IS SATUAN MATRIKS D ===========\n");
	printf("Matriks Satuan? : %s\n\n", IsSatuanMatriks(D) ? "True" : "False");
	printf("\n");


	printf("============ IS SPARSE MATRIKS D ===========\n");
	printf("Matriks Sparse? : %s\n\n", IsSparseMatriks(D) ? "True" : "False");
	printf("\n");

	printf("============ IS SPARSE MATRIKS B ===========\n");
	printf("Matriks Sparse? : %s\n\n", IsSparseMatriks(B) ? "True" : "False");
	printf("\n");


	
	return 0;
}