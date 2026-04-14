//28. Find the index of the first occurrence in a String
int strStr(char* haystack, char* needle) {
    if(!*needle) return 0;

    int n = strlen(haystack), m = strlen(needle);
    for(int i = 0; i<=n-m; i++){
        if(strncmp(haystack+i, needle, m) == 0){
            return i;
        }
    }
    return -1;
}