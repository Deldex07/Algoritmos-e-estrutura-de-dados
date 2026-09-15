/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = nums[numsSize - 1] - nums[0];
    int* ans = (int*)malloc(cap * sizeof(int));
    int c = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
            ans[c++] = j;
        }
    }

    *returnSize = c;
    return ans;
}