//3512. Minimum Operations to Make Array Sum Divisible by K
int minOperations(int* nums, int numsSize, int k) {
    int resto = 0;
    long int total = 0;
    for(int i = 0; i<numsSize; i++){
        total += nums[i];
    }
    resto = total % k;
    return resto;
}