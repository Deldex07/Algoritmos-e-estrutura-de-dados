#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc(void *pont, size_t Nsize);

int main(){
    int nLinhas;
    printf("Digite numero de linhas: ");
    scanf("%d", &nLinhas);

    int nNovo = nLinhas + 10;
    int **p = (int **)malloc(sizeof(int *) * nLinhas);
    p = realloc(p, nNovo*sizeof(int *));

    printf("Endereço antigo: %p\n", (void *)p);
    p = realloc(p, nNovo * sizeof(int *));
    printf("Endereço novo:   %p\n", (void *)p);
    free(p);
    return 0;
}

void *realloc(void *pont, size_t Nsize){
    if(pont ==NULL){
        return malloc(Nsize);
    }
    void *dest = (int *)malloc(Nsize);
    if(!dest){
        printf("Erro ao alocar memoria.");
        return NULL;
    }
    memcpy(dest, pont, Nsize);

    free(pont);
    return dest;
}

//void *calloc(size_t num,size_t size)
/*Reserva espaço na mem[oria para um vetor de num intens do programa.
Cada intem tem tamnho size e todos os bits do espaço são inicializados com 0.
A função retorna um ponteiro de topi void para o espaço reservado ou NULL no caso de algum erro ocorrer.*/

//void *realloc(void*pont,size_t size)
/*A função altera o tamanho do objeto na memória apontado por pont para o tamanho especificado por size.
O contúdo do objeto será mantindo até um tamanho igual ao menor dos dois tamanhos, novo e antigo.
Se o novo tamanho requerer movimento, o espaço reservado anteriormente é liberado.
Caso o novo tamanho for maior, o conteúdo da porção de memória reservada a mais ficará com um valor sem especificação.

Se o tamanho size for igual a 0 e pont não é um ponteiro nulo o objeto previamente reservado é liberado*/