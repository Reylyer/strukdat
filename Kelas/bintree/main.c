#include "PohonBiner.h"

int main() {
    BinTree P;
    MakeTree(1, Tree(2, Tree(4, Nil, Nil), Tree(5, Nil, Nil)), Tree(3, Nil, Tree(6, Tree(7, Nil, Nil), Nil)), &P);
    printf("PrintTreeL(P, 2, 1):\n");
    // PrintTreeL(P, 2, 1);
    PrintPostOrder(P, 0);
    printf("\n");
    PrintInOrder(P, 0);
    printf("\n");
    PrintPreOrder(P);
    printf("\n");
    printf("isTreeEmpty(P): %s\n", isTreeEmpty(P) == 1 ? "True" : "False");
    printf("isOneElmt(P): %s\n", isOneElmt(P) == 1 ? "True" : "False");
    printf("isUnerLeft(P): %s\n", isUnerLeft(P) == 1 ? "True" : "False");
    printf("isUnerRight(P): %s\n", isUnerRight(P) == 1 ? "True" : "False");
    printf("isBiner(P): %s\n", isBiner(P) == 1 ? "True" : "False");
    printf("NbElmt(P): %d\n", NbElmt(P));
    printf("NBDaun(P): %d\n", NBDaun(P));
    printf("Level(P, 7): %d\n", Level(P, 1));
    printf("SearchTree(P, 7): %s\n", SearchTree(P, 7) == 1 ? "True" : "False");
    printf("SearchTree(P, 8): %s\n", SearchTree(P, 8) == 1 ? "True" : "False");
    printf("isSkewLeft(P): %s\n", isSkewLeft(P) == 1 ? "True" : "False");
    printf("isSkewRight(P): %s\n", isSkewRight(P) == 1 ? "True" : "False");

    return 0;
}