#include <stdio.h>

int main(){
    int A[5];
    int *p = A;
    for(int i = 0; i<5; i++){
        printf("Digite o elemento número %d: ", i+1);
        scanf("%d", p+i);
    }
    for(int i = 0; i<5; i++){
        int dobro = *(p+1)*2;
        printf("Dobro %d\n", dobro);
    }
    return 0;
}

/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.*/