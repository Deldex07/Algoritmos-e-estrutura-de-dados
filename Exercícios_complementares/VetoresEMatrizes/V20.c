#include <stdio.h>

int main() {
    int A[10], B[10];
    for(int i = 0; i < 10; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &A[i]);
        if(A[i] < 0 || A[i] > 50) {
            printf("Número inválido. Digite um número entre 0 e 50.\n");
            i--;
            scanf("%d", &A[i]);
        }

        if(A[i] % 2 != 0) {
            B[i] = A[i];
        }
    }

    printf("Números ímpares digitados:\n");
    for(int i = 0; i < 10; i++) {
        if(B[i] != 0) {
            printf("%d %d\n", B[i], B[i+1]);
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("Vetor total: %d\n", A[i]);
    }
    return 0;
}