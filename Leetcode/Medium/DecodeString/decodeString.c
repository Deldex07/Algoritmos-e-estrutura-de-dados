char* decodeString(char* s) {
    int numStack[100];
    int numTop = -1;

    char* strStack[100];
    int strTop = -1;

    char* currStr = calloc(10000, sizeof(char));
    int currLen = 0;

    int i = 0;
    while(s[i] != '\0') {
        if(s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numStack[++numTop] = num;
        } 
        else if(s[i] == '[') {
            strStack[++strTop] = currStr;

            currStr = calloc(10000, sizeof(char));
            currLen = 0;
            i++;
        } 
        else if(s[i] == ']') {
            int k = numStack[numTop--];
            char* prevStr = strStack[strTop--];

            char* temp = calloc(10000, sizeof(char));
            for(int j = 0; j < k; j++) {
                strcat(temp, currStr);
            }

            char* combined = calloc(10000, sizeof(char));
            strcpy(combined, prevStr);
            strcat(combined, temp);

            free(currStr);
            free(prevStr);
            free(temp);

            currStr = combined;
            currLen = strlen(currStr);
            i++;
        } 
        else {
            currStr[currLen++] = s[i];
            currStr[currLen] = '\0';
            i++;
        }
    }

    return currStr;
}