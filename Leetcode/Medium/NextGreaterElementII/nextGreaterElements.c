// 503. Next Greater Element II
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* ans = ( int * )malloc( numsSize * sizeof( int ) );
    int* stack = ( int* )malloc( numsSize * sizeof( int ) );
    int top = -1;
    *returnSize = numsSize;

    for( int i = 0; i < numsSize; i++ ){
        ans[ i ] = -1;
    }
    for( int i = 0; i < 2* numsSize; i++ ){
        int num = nums[ i % numsSize ];

        while( top != -1 && nums[ stack[ top ] ] < num ){
            ans[ stack[ top ] ] = num;
            top --;
        }
        if( i < numsSize ){
            stack[ ++top ] = i;
        }
    }
    return ans;
}