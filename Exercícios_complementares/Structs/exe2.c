#include <stdio.h>

typedef struct pessoa{
    char nome[50], endereco[100];
    int idade;
} pessoa;

int main(){
    pessoa p;

    printf("Digite seu nome: ");
    scanf("%s", p.nome);
    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    printf("Digite seu endereço: ");
    scanf(" %[^\n]s", p.endereco);

    printf("\n--- Dados Cadastrados ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
    printf("Endereço: %s\n", p.endereco);

    return 0;
}