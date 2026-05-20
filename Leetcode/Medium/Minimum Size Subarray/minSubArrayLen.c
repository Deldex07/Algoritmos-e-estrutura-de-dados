// 209. Minimum Size Subarray Sum
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int right;
    int curr_sum = 0;
    int min_length = numsSize + 1;
    
    for(right = 0; right < numsSize; right++){
        curr_sum += nums[right];

        while(curr_sum >= target){
            int curr_length = (right - left + 1);
            if(curr_length < min_length){
                min_length = curr_length;
            }
            curr_sum -= nums[left];
            left++;
        }
    }
    return (min_length == numsSize + 1) ? 0 : min_length;
}