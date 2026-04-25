#include <stdio.h>

int main(){
    int A, *B, **C, ***D;
    printf("Valor: ");
    scanf("%d", &A);

    B = &A;
    C = &B;
    D = &C;
    
    printf("Dobro: %d\n", (*B) *2);
    printf("Triplo: %d\n", (**C) *3);
    printf("Quadruplo: %d\n", (***D) *4);
}

/*Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um programa que leia a
variável a e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quádruplo.*/