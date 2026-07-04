#include <stdio.h>

int main() {
    int Matriz[3][3];
    int somaAcimaDiagonalPrincipal = 0;
    int somaAbaixoDiagonalPrincipal = 0;
    int somaNaDiagonalPrincipal = 0;
    int somaNaDiagonalSecundaria = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o elemento da linha %d e coluna %d: ", i + 1, j + 1);
            scanf("%d", &Matriz[i][j]);
        }
    }

    //soma dos elementos acima da diagonal principal
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j <3; j++) {
            if(i < j) {
                somaAcimaDiagonalPrincipal += Matriz[i][j];
            }
        }
    }
    //soma dos elementos abaixo da diagonal principal
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j <3; j++) {
            if(i > j) {
                somaAbaixoDiagonalPrincipal += Matriz[i][j];
            }
        }
    }
    //soma dos elementos na diagonal principal
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j <3; j++) {
            if(i == j) {
                somaNaDiagonalPrincipal += Matriz[i][j];
            }
        }
    }
    //soma dos elementos na diagonal secundaria
    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j <3; j++) {
            if(i + j == 2) {
                somaNaDiagonalSecundaria += Matriz[i][j];
            }
        }
    }
    printf("Soma dos elementos acima da diagonal principal: %d\n", somaAcimaDiagonalPrincipal);
    printf("Soma dos elementos abaixo da diagonal principal: %d\n", somaAbaixoDiagonalPrincipal);
    printf("Soma dos elementos na diagonal principal: %d\n", somaNaDiagonalPrincipal);
    printf("Soma dos elementos na diagonal secundaria: %d\n", somaNaDiagonalSecundaria);
    return 0;
}