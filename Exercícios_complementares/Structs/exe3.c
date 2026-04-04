#include <stdio.h>

typedef struct aluno{
    char nome[50], curso[100];
    int matricula;
}aluno;

int main(){
    aluno p[5];

    for(int i=0; i<5; i++){
        printf("nome:");
        scanf("%s", p->nome);

        printf("matricula:");
        scanf("%s", &p->matricula);

        printf("curso:");
        scanf("%s", &p->curso);
    }

    for(int i=0; i<5; i++){
        printf("nome:", p[i].nome);    
        printf("matricula:", p[i].matricula);
        printf("curso:", p[i].curso);
    }
}