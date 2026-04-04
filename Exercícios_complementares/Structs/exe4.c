#include <stdio.h>

typedef struct aluno{
    char nome[50];
    int matricula;
    float n1,n2,n3;
}aluno;

int main(){
    aluno p[5];
    int maiorN1 = 0, maiorMedia = 0, menorMedia = 0;
    float medias[5];
    for(int i=0; i<5; i++){
        printf("nome:");
        scanf("%s", p->nome);

        printf("matricula:");
        scanf("%d", &p->matricula);

        printf("n1: ");
        scanf("%f", &p[i].n1);
        printf("n2: ");
        scanf("%f", &p[i].n2);
        printf("n3: ");
        scanf("%f", &p[i].n3);

        medias[i] = (p[i].n1+p[i].n2+p[i].n3)/3.0;
    }
    for(int i=0; i<5; i++){
        if(medias[i]>medias[maiorMedia])
            maiorMedia=i;
        if(medias[i]<medias[menorMedia])
            menorMedia=i;
        if(p[i].n1>p[maiorN1].n1)
            maiorN1=i;
    }

    printf("Final: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%s: ", p[i].nome);
        if(medias[i]>=6.0){
            printf("aprovado: %.2f", medias[i]);
        }
        else{
            printf("reprovado: %.2f", medias[i]);
        }
    }
    
    return 0;
}