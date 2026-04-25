#include <stdio.h>

void imprimir (int *A);

int main(){
    int A[4] = {1,2,3,4};
    imprimir(A);
}

void imprimir (int *A){
    int *p = A;
    for(int i = 0; i<4; i++){
        printf("%d ", *p);
        p++;
    }
}
/*Crie uma função que receba como parâmetro um array e o imprima. Não utilize índices
para percorrer o array, apenas aritmética de ponteiros.*/