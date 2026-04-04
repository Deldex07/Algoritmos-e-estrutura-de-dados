//14. longest common prefix
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return " ";
    char *result = (char *)malloc(sizeof(char) * 201);

    int i=0;
    while(strs[0][i] != '\0'){
        char c = strs[0][i];
        for(int j=1; j<strsSize; j++){
            if(strs[j][i] != c){
                result[i] = '\0';
                return result;
            }
        }
        result[i] = c;
        i ++;
    }
    result[i] = '\0';
    return result;
}