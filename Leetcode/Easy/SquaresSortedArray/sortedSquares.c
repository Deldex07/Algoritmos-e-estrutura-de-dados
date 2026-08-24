/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc( numsSize * sizeof( int ) );
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize-1;
    int pos = numsSize -1;

    while( left <= right ) {
        int Square_l = nums[left] * nums[left];
        int Square_r = nums[right] * nums[right];

        if( Square_l > Square_r ) {
            ans[pos] = Square_l;
            left++;
        } else {
            ans[pos] = Square_r;
            right--;
        }

        pos--;
    }
    return ans;
}