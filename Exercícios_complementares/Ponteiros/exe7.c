#include <stdio.h>

void soma(int *A, int *B);
int main(){
    int A=20, B=10;
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    soma(&A,&B);
    printf("A: %d", A);
    printf("B: %d", B);
}
void soma(int *A, int *B){
    int aux = *A+*B;
    *A = aux;
}

/*Crie um programa que contenha uma func¸ ˜ao que permita passar por par ˆametro dois
n ´umeros inteiros A e B. A func¸ ˜ao dever ´a calcular a soma entre estes dois n ´umeros e
armazenar o resultado na vari ´avel A. Esta func¸ ˜ao n ˜ao dever ´a possuir retorno, mas dever ´a
modificar o valor do primeiro par ˜ametro. Imprima os valores de A e B na func¸ ˜ao principal.
*/