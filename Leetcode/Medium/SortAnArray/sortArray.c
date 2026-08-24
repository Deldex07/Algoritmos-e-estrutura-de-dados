/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge( int* nums, int left, int mid, int right, int* aux ) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while ( i <= mid && j <= right ) {
        if (nums[i] <= nums[j]) {
            aux[k++] = nums[i++];
        } else {
            aux[k++] = nums[j++];
        }
    }

    while ( i <= mid ) {
        aux[k++] = nums[i++];
    }

    while ( j <= right ) {
        aux[k++] = nums[j++];
    }

    for ( i = left; i <= right; i++ ) {
        nums[i] = aux[i];
    }
}

void mergeSort( int* nums, int left, int right, int* aux ) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid, aux);
        mergeSort(nums, mid + 1, right, aux);

        merge(nums, left, mid, right, aux);
    }
}

int* sortArray( int* nums, int numsSize, int* returnSize ) {
    *returnSize = numsSize;

    int* aux = ( int* )malloc( numsSize * sizeof( int ) );

    mergeSort( nums, 0, numsSize - 1, aux );

    free( aux );

    return nums;
}