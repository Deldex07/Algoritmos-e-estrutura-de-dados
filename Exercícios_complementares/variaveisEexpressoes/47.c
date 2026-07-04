#include <stdio.h>

int main () {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    while(n < 1000 || n > 9999) {
        printf("Número inválido. Digite um número de 4 dígitos.\n");
        scanf("%d", &n);
    }
    printf("Digito 1: %d\n", n/1000);
    printf("Digito 2: %d\n", (n/100)%10);
    printf("Digito 3: %d\n", (n/10)%10);
    printf("Digito 4: %d\n", n%10);

}