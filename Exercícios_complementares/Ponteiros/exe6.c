#include <stdio.h>

int sobro(int *A, int *B);
int main(){
    int A=20, B=10;
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    int soma = sobro(&A,&B);
    printf("A: %d", A);
    printf("B: %d", B);
    printf("AB: %d", soma);
}
int sobro(int *A, int *B){
    int da = *A*2;
    int db = *B*2;
    *A = da;
    *B = db;
    return da+db;
}


/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida fac¸a uma func¸ ˜ao
que retorne a soma do dobro dos dois n ´umeros lidos. A func¸ ˜ao dever ´a armazenar o dobro
de A na pr ´opria vari ´avel A e o dobro de B na pr ´opria vari ´avel B.
*/