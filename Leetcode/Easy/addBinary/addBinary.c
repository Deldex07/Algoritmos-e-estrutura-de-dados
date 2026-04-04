//67. Add Binary

char* addBinary(char* a, char* b) {
    int carry = 0, soma = 0;
    int tam = strlen(a), tom = strlen(b);
    int i = tam-1, j=tom-1;
    int max = (tam>tom) ? tam:tom;
    int k = max;
    char *result = malloc((max+2) *sizeof(char));
    result[max+1] = '\0';
    while(i>=0 || j>=0){
        soma = carry;
        if(i>=0){
            soma+= a[i] - '0';
        }

        if(j>=0){
            soma+= b[j] - '0';
        }
        result[k--] = (soma%2)+'0';
        carry = soma/2;
        if(i>=0) i--;
        if(j>=0) j--; 
    }
    if(carry == 1){
            result[k--] = '1';
    }
    return result + k +1;
}