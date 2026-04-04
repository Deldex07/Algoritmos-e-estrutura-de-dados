// 26. Remove Duplicates from Sorted Array
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int k=0;
    for(int i=0; i<numsSize; i++){
        if(i==0 || nums[i] != nums[i-1]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}