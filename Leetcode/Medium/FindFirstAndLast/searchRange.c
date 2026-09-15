/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findBound(int* nums, int numsSize, int target, bool isFirst) {
    int left = 0, right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            bound = mid;
            if (isFirst) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    result[0] = findBound(nums, numsSize, target, true);  
    result[1] = findBound(nums, numsSize, target, false); 

    return result;
}