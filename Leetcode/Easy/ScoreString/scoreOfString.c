//3110. Score of a String
int scoreOfString(char* s) {   
    int total = 0;
    int n = strlen(s);
    for(int i = 0; i<n-1; i++){
        int diff = s[i] - s[i+1];
        total += abs(diff);
    }

    return total;
}