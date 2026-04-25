#include <stdio.h>

int Ordenado(int *n1, int *n2, int *n3);

int main(){
    int n1, n2, n3;

    printf("Digite 3 valores: \n");
    scanf("%d %d %d", &n1, &n2, &n3);

    int saoIguais = Ordenado(&n1, &n2, &n3);

    if(saoIguais){
        printf("Os tres sao iguais.");
    }
    else{
        printf("Existem valores diferentes");
    }
    printf("Valores ondenados: %d, %d, %d", n1,n2,n3);
}

int Ordenado(int *n1, int *n2, int *n3){
    int temp;

    if (*n1 > *n2) { temp = *n1; *n1 = *n2; *n2 = temp; }
    if (*n1 > *n3) { temp = *n1; *n1 = *n3; *n3 = temp; }
    if (*n2 > *n3) { temp = *n2; *n2 = *n3; *n3 = temp; }

    if (*n1 == *n2 && *n2 == *n3) {
        return 1;
    } else {
        return 0;
    }
}

/*Faça um programa que leia três valores inteiros e chame uma função que receba estes 3
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável,
o segundo menor valor na variável do meio, e o maior valor na última vari ável. A função
deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes.
Exibir os valores ordenados na tela.*/