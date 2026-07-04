#include <stdio.h>

int main () {
    int A[100];

    for (int i = 0; i < 100; i++) {
        printf("Digite o %dº elemento do vetor A: ", i + 1);
        scanf("%d", &A[i]);

        if(A[i] / 7 == 0 || A[i] % 10 == 7) {
            printf("Digite novamente, o número não pode ser múltiplo de 7 ou terminar com 7.\n");
            i--;
            scanf("%d", &A[i]);
        }
    }

    printf("Vetor A:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}