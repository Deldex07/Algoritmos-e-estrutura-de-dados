// 9. Palindrome Number
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int invert = 0;

    while (x > invert) {
        int digit = x % 10;
        invert = invert * 10 + digit;
        x /= 10;
    }

    return (x == invert) || (x == invert / 10);
}