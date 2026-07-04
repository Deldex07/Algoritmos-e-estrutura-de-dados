#include <stdio.h>

int main() {
    int A[10], B[10], C[10], i;
    for(i = 0; i < 10; i++) {
        printf("Digite o %dº elemento do vetor A: ", i + 1);
        scanf("%d", &A[i]);
    }

    for(i = 0; i < 10; i++) {
        printf("Digite o %dº elemento do vetor B: ", i + 1);
        scanf("%d", &B[i]);
    }

    for(i = 0; i < 10; i++) {
        C[i] = A[i] - B[i];
    }
    printf("Vetor C (diferença de A e B):\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", C[i]);
    }
    return 0;
}