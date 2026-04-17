// 509. Fibonacci Number
int fib(int n){
    if(n <= 1) return n;

    int a = 0, b = 1;
    int *pa = &a, *pb = &b;

    for(int i = 2; i <= n; i++){
        int temp = *pa + *pb;
        *pa = *pb;
        *pb = temp;
    }

    return *pb;
}