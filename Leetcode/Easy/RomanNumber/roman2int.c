// 13. Roman to Integer
#include <stdio.h>

int charToInt(char a){
    switch(a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int resul = 0;
    for(int i=0; s[i] !='\0'; i++){
        int atual = charToInt(s[i]), prox = charToInt(s[i+1]);
        if(atual < prox){
            resul -= atual;
        }
        else{
            resul += atual;
        }
    }
    return resul;
}