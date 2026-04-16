#include <stdio.h>

int main(){
    float M[3][3];
    float *p;
    p = M;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            printf("Elemento M[%d][%d] - Endereço: %p/n", i,j,p);
            p++;
        }
    }
    return 0;
}

/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereço de cada posição dessa matriz.*/