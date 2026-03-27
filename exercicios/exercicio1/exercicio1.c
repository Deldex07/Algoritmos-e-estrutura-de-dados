#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nomes = NULL;
int dinamico_len = 0;

void ler_string(char *str, int max_len);
void adicionar_nome();
void remover_nome();
void listar();
void menu();

int main(){
    int op;
    for(;;){
        menu();
        printf("Escolha uma opção: ");
        if(scanf("%d", &op)!=1){
            printf("Entrada inválida. Tente novamente.\n");
            while(getchar()!='\n');
            continue;
        }
        getchar();

        switch(op){
            case 1:
                adicionar_nome();
                break;
            case 2:
                remover_nome();
                break;
            case 3:
                listar();
                break;
            case 4:
                free(nomes);
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void menu(){
    printf("1 - Adicionar nome\n");
    printf("2 - Remover nome\n");
    printf("3 - Listar nomes\n");
    printf("4 - Sair\n");
}

void ler_string(char *str, int max_len){
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void adicionar_nome(){
    char novo[100];
    printf("Digite o nome a ser adicionado: ");
    ler_string(novo, 100);

    int len = strlen(novo);
    char *temp = realloc(nomes, dinamico_len + len + 2);
    if(!temp){
        printf("Erro de alocalçao de memoria.\n");
        return;
    }

    nomes = temp;
    strcpy(nomes+dinamico_len, novo);

    dinamico_len += len;

    nomes[dinamico_len] = '\n';

    dinamico_len++;

    nomes[dinamico_len] = '\0';
}

void remover_nome(){
    if(!nomes || dinamico_len == 0){
        printf("Nenhum nome para remover.\n");
        return;
    }

    char nome_remover[100];
    printf("Digite o nome a ser removido: ");
    ler_string(nome_remover, 100);

    char *pos = strstr(nomes, nome_remover);

    while(pos){
        int len = strlen(nome_remover);

        if((pos == nomes || *(pos - 1) == '\n') &&
           (pos[len] == '\n' || pos[len] == '\0')){

            memmove(pos, pos + len + 1, strlen(pos + len + 1) + 1);
            dinamico_len -= (len + 1);

            char *temp = realloc(nomes, dinamico_len + 1);
            if(temp || dinamico_len == 0){
                nomes = temp;
            }

            printf("Nome removido.\n");
            return;
        }

        pos = strstr(pos + 1, nome_remover);
    }

    printf("Nome não encontrado.\n");
}

void listar(){
    if(!nomes || dinamico_len == 0){
        printf("Nenhum nome para listar.\n");
        return;
    }
    printf("Nomes:\n%s", nomes);
}