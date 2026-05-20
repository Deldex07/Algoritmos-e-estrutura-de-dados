// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s) {
    int left = 0;
    int right = 0;
    int i;
    int max_len = 0;
    int visitados[128] = {0};
    while(s[right] != '\0'){
        while(visitados[s[right]] == 1){
            visitados[s[left]] = 0;
            left++; 
        }
        visitados[s[right]] = 1;
        if((right - left + 1) > max_len){
            max_len = (right - left + 1);
        }
        right++;
    }
    return max_len;
}