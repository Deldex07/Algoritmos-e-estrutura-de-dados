void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int i = 0, write = 0;
    int n = strlen(s);

    while (i < n) {
        while (i < n && s[i] == ' ') i++;

        if (i < n) {
            if (write > 0) s[write++] = ' ';
            while (i < n && s[i] != ' ') {
                s[write++] = s[i++];
            }
        }
    }
    s[write] = '\0';

    reverse(s, 0, write - 1);

    int start_word = 0;
    for (int end_word = 0; end_word <= write; end_word++) {
        if (s[end_word] == ' ' || s[end_word] == '\0') {
            reverse(s, start_word, end_word - 1);
            start_word = end_word + 1; 
        }
    }

    return s;
}