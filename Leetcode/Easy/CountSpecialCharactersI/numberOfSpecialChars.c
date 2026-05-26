// 3120. Count the Number of Special Characters I

int numberOfSpecialChars(char* word) {
    int upper[26] = {0};
    int lower[26] = {0};
    int i;
    for(i = 0; word[i] != '\0'; i++){
        if(islower(word[i])){
            lower[word[i] - 'a'] = 1;
        }
        else if( isupper(word[i])){
            upper[word[i] - 'A'] = 1;
        }
    }
    int c = 0;

    for(i = 0; i < 26; i++){
        if(lower[i] && upper[i]){
            c++;
        }
    }
    return c;
}