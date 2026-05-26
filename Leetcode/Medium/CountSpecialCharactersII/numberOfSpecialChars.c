// 3121. Count the Number of Special Characters II
int numberOfSpecialChars(char* word) {
    int lastLower[26];
    int firstUpper[26];
    int i;
    for (i = 0; i < 26; i++) {
        lastLower[i] = -1;
        firstUpper[i] = -1;
    }

    for (i = 0; word[i] != '\0'; i++) {

        if (islower(word[i])) {
            int idx = word[i] - 'a';

            lastLower[idx] = i;
        }

        else if (isupper(word[i])) {
            int idx = word[i] - 'A';

            if (firstUpper[idx] == -1) {
                firstUpper[idx] = i;
            }
        }
    }

    int count = 0;

    for (i = 0; i < 26; i++) {

        if (lastLower[i] != -1 && firstUpper[i] != -1) {

            if (lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
    }

    return count;
}