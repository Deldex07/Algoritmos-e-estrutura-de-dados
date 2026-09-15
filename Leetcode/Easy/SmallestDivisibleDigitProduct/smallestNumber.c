bool check (int n, int t) {
    int p = 1;
    while(n > 0) {
        p *= n%10;
        n /= 10;
        if(p == 0) {
            break;
        }
    }
    return p % t == 0;
}

int smallestNumber(int n, int t) {
    while(!check(n,t)) {
        n++;
    }
    return n;
}