//69. Sqrt(x)
int mySqrt(int x){
    int odd=1, n=0;
    while(x>0){
        x-=odd;
        odd+=2;
        n++;
    }

    if(x==0){
        return n;
    }

    return n-1;
}

/*int mySqrt(int x) {
    if(x < 0) return -1;
    if(x == 0) return 0;
    double y = x;
    double prev;

    for(int i = 0; i < 5; i++){
        prev = y;
        y = (y + x / y) / 2;
        if((int)y == (int)prev){
            break;
        }
    }
    int result = (int)y;

    while((long long)result * result > x){
        result--;
    }

    return result;
}*/