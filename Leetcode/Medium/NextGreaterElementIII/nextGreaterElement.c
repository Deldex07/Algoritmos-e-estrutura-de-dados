int nextGreaterElement(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int len = strlen(s);

    int i = len-2;
    while( i >= 0 && s[i] >= s[i + 1] ) {
        i--;
    }

    if( i < 0 ) return -1;

    int j = len - 1;
    while( s[j] <= s[i] ) {
        j--;
    }

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    int left = i + 1;
    int right = len - 1;
    while( left < right ) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    long long result = atoll(s);
    if( result > INT_MAX ) {
        return -1;
    }

    return (int)result;
}