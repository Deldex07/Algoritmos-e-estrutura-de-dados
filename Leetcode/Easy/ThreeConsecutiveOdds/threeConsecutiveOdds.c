bool threeConsecutiveOdds(int* arr, int arrSize) {
    int odds = 0;

    for( int i = 0; i < arrSize; i++ ) {
        if( arr[i] % 2 == 1 ) {
            odds++;
        } else {
            odds = 0;
        }

        if( odds == 3 ) return true;
    }
    return false;
}