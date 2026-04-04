#include <stdio.h>

int main(){
    char string[5] = "Hello";

    for(int i=0; i<4 &&string[i]!='\0'; i++){
        printf("%c", string[i]);
    }
    return 0;
}