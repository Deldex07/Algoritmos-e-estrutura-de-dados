int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int c = 0;
    int prev_c = 0;
    for(int i = 0; i < numsSize; i++) {

        if( nums[i] == 1) {
            c++;
            if( prev_c < c ) {

            prev_c = c;

            }
        } else {
            c = 0;
        }
    }
    return prev_c;
}