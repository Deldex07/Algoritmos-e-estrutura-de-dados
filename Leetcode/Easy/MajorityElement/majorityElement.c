int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int c = 1;

    for (int i = 1; i < numsSize; i++) {
        
        if (c == 0) {
            candidate = nums[i];
            c = 1;
        } 
        
        else if (nums[i] == candidate) {
            c++;
        } 
        
        else {
            c--;
        }
    }

    return candidate;
}