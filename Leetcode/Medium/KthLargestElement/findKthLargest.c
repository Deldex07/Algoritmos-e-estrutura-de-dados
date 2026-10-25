int findKthLargest(int* nums, int numsSize, int k) {
    int c[20001] = {0};

    for( int i = 0; i < numsSize; i++ ) {
        c[nums[i] + 10000]++;
    }

    for( int i = 20000; i >= 0; i-- ) {
        if( c[i] > 0 ) {
            k -=c[i];
        }
        if(k <= 0) {
            return i - 10000;
        }
    }
    return 0;
}