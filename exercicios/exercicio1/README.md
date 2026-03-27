#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ponteiro global que vai armazenar TODOS os nomes em uma única string dinâmica
char *nomes = NULL;

// Guarda o tamanho atual da string (quantos caracteres estão sendo usados)
int dinamico_len = 0;

// Protótipos das funções
void ler_string(char *str, int max_len);
void adicionar_nome();
void remover_nome();
void listar();
void menu();

int main(){
    int op; // variável para armazenar a opção do usuário

    for(;;){ // loop infinito
        menu(); // mostra o menu

        printf("Escolha uma opção: ");

        // tenta ler um número
        if(scanf("%d", &op)!=1){
            printf("Entrada inválida. Tente novamente.\n");

            // limpa o buffer até o ENTER
            while(getchar()!='\n');

            continue; // volta para o início do loop
        }

        getchar(); // consome o '\n' deixado pelo scanf

        switch(op){
            case 1:
                adicionar_nome(); // adiciona um nome
                break;

            case 2:
                remover_nome(); // remove um nome
                break;

            case 3:
                listar(); // lista todos os nomes
                break;

            case 4:
                free(nomes); // libera a memória
                exit(0);     // encerra o programa

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

// Apenas imprime o menu
void menu(){
    printf("\n1 - Adicionar nome\n");
    printf("2 - Remover nome\n");
    printf("3 - Listar nomes\n");
    printf("4 - Sair\n");
}

// Lê uma string do teclado e remove o '\n'
void ler_string(char *str, int max_len){
    fgets(str, max_len, stdin); // lê até max_len ou ENTER
    str[strcspn(str, "\n")] = '\0'; // substitui '\n' por '\0'
}

// Adiciona um nome na string dinâmica
void adicionar_nome(){
    char novo[100]; // buffer temporário

    printf("Digite o nome a ser adicionado: ");
    ler_string(novo, 100);

    int len = strlen(novo); // tamanho do nome

    // realoca memória:
    // tamanho atual + nome + '\n' + '\0'
    char *temp = realloc(nomes, dinamico_len + len + 2);

    if(!temp){
        printf("Erro de alocação de memória.\n");
        return;
    }

    nomes = temp; // atualiza ponteiro

    // copia o nome para o final da string atual
    strcpy(nomes + dinamico_len, novo);

    dinamico_len += len; // atualiza tamanho usado

    nomes[dinamico_len] = '\n'; // separador entre nomes
    dinamico_len++;

    nomes[dinamico_len] = '\0'; // fim da string
}

// Remove um nome da string dinâmica
void remover_nome(){
    // verifica se está vazio
    if(!nomes || dinamico_len == 0){
        printf("Nenhum nome para remover.\n");
        return;
    }

    char nome_remover[100];

    printf("Digite o nome a ser removido: ");
    ler_string(nome_remover, 100);

    // procura o nome na string
    char *pos = strstr(nomes, nome_remover);

    while(pos){
        int len = strlen(nome_remover);

        // verifica se é um nome completo (não parte de outro)
        // antes deve ser início ou '\n'
        // depois deve ser '\n' ou fim da string
        if((pos == nomes || *(pos - 1) == '\n') &&
           (pos[len] == '\n' || pos[len] == '\0')){

            // remove movendo o restante da string para cima
            memmove(pos, pos + len + 1, strlen(pos + len + 1) + 1);

            dinamico_len -= (len + 1); // atualiza tamanho

            // reduz a memória para evitar desperdício
            char *temp = realloc(nomes, dinamico_len + 1);

            if(temp || dinamico_len == 0){
                nomes = temp;
            }

            printf("Nome removido.\n");
            return;
        }

        // procura próxima ocorrência
        pos = strstr(pos + 1, nome_remover);
    }

    printf("Nome não encontrado.\n");
}

// Lista todos os nomes
void listar(){
    if(!nomes || dinamico_len == 0){
        printf("Nenhum nome para listar.\n");
        return;
    }

    printf("\nNomes:\n%s", nomes);
}

/*
ESTRUTURA INTERNA DA STRING:

Exemplo:
"João\nMaria\nCarlos\n\0"

- Todos os nomes ficam em UMA única string
- Separados por '\n'
- Cresce com realloc ao adicionar
- Diminui com realloc ao remover
- Sem desperdício de memória

FUNÇÕES IMPORTANTES USADAS:

- realloc → aumenta/diminui memória
- strcpy → copia string
- strlen → tamanho da string
- strstr → encontra substring
- memmove → move blocos de memória (usado para remover)