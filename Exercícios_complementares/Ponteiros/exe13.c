#include <stdio.h>
#include <stdlib.h>

int encapsulado(char *str, char *rts);

int main(){
    char str[20] = "Hello World", rts[20] = "World Hello";
    if(encapsulado(str, rts)){
        printf("%s, ocorre dentro de %s", rts, str);
    }else{
        printf("%s Nao ocorre dentro de %s", rts, str);
    }
    char str2[20] = "Hello World", rts2[20] = "World";
    if(encapsulado(str2,rts2)){
        printf("%s ocorre em %s", rts2, str2);
    }else{
        printf("%s não ocorre em %s", rts2, str2);
    }
    return 0;
}

int encapsulado(char *str, char *rts){
    if(*rts == '\0') return 1;

    char *p = str;

    while(*p!='\0'){
        char *p_str = p;
        char *p_rts = rts;

        while( *p_str !='\0' && *p_rts != '\0' && *p_str == *p_rts){
            p_str++;
            p_rts++;
        }

        if(*p_rts == '\0'){
            return 1;
        }
        p++;
   }
   return 0;
}

/*labore uma func¸ ˜ao que receba duas strings 
como par ˆametros e verifique se a segunda
string ocorre dentro da primeira. Use aritm 
´etica de ponteiros para acessar os caracteres
das strings*/