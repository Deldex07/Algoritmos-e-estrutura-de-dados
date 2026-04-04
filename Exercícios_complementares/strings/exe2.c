#include <stdio.h>

int main(){
    char string[5] = "Hello";
    int tam =0;

    for(int i=0; string[i]!='\0'; i++){
        tam ++;
    }
    printf("%d", tam);
    return 0;
}