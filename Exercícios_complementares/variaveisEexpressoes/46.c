#include <stdio.h>

int main () {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    while(n < 100 || n > 999) {
        printf("Número inválido. Digite um número de 3 dígitos.\n");
        scanf("%d", &n);
    }

    printf("Numero reverso: %d%d%d\n", n%10, (n/10)%10, n/100);
}