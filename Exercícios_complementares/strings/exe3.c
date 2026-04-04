#include <stdio.h>

int main(){
    char string[5];
    scanf("%s", string);
    if(string[0] == 'a' || string[0]=='A'){
        printf("%s", string);
    }
    return 0;
}