#include <stdio.h>
#include <string.h>

int main() {
    char palavra[50] = "computador";
    char substituto;
    int k = 0;

    printf("Palavra original: %s\n", palavra);
    printf("Digite um caractere para substituir as vogais: ");
    scanf(" %c", &substituto); 
    
    for(int i = 0; palavra[i] != '\0'; i++) {
        
        
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || 
           palavra[i] == 'o' || palavra[i] == 'u') {
            
            k++;                  
            palavra[i] = substituto;
        }
    }

    printf("\nTotal de vogais: %d", k);
    printf("\nNova palavra: %s\n", palavra);

    return 0;
}