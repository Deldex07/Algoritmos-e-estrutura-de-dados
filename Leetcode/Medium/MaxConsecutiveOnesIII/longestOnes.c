int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int count0 = 0;
    int len = 0;
    for( int right = 0; right < numsSize; right++ ) {
        if( nums[right] == 0 ) {
            count0++;
        }

        while ( count0 > k ) {
            if ( nums[left] == 0 ) {
                count0--;
            }
            left++;
        }
        int curr_len = ( right - left ) + 1;
        if( curr_len > len ) {
            len = curr_len;
        }
    }

    return len;
}