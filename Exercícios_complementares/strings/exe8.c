#include <stdio.h>

int main(){
    char string[5] = "11111";
    int tam = 0;

    for(int i=0; string[i]!='\0'; i++){
        if(string[i]== '1'){
            tam ++;
        }
    }
    printf("%d", tam);
    return 0;
}