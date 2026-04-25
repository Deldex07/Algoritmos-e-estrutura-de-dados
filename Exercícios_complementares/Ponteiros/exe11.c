#include <stdio.h>

int main(){
    int A[5];
    int *p = A;
    for(int i = 0; i<5; i++){
        printf("Digite o elemento número %d: ", i+1);
        scanf("%d", p+i);
    }
    for(int i = 0; i<5; i++){
        if(*(p+i) %2 == 0){
            printf("%d\n", *(p+1));
        }
    }
    return 0;
}

/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares.*/