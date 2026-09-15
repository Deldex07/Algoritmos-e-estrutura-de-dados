int search(int* nums, int numsSize, int target) {
    int begin = 0;
    int end = numsSize - 1;
    while( begin <= end ) {
        int mid = begin + ( end - begin ) / 2;

        if ( nums[mid] == target ) { return mid; }

        if ( nums[begin] <= nums[mid] ) {

            if( target >= nums[begin] && target < nums[mid] ) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        } else {
            if ( target <= nums[end] && target > nums[mid] ) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}