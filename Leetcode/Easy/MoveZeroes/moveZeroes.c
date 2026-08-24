void moveZeroes(int* nums, int numsSize) {
    int k = 0;

    for( int i = 0; i < numsSize; i++ ) {
        if( nums[i] != 0 ) {
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;

            k++;
        }
    }
}