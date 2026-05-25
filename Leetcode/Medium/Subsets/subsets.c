// 78. Subsets
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void search(int index, int* nums, int numsSize, int* atual, int atualSize, int** result, int* returnSize, int* returnColumnSizes) {
    
    if (index == numsSize) {
        result[*returnSize] = (int*)malloc(atualSize * sizeof(int));
        
        for (int i = 0; i < atualSize; i++) {
            result[*returnSize][i] = atual[i];
        }
        
        returnColumnSizes[*returnSize] = atualSize;
        
        (*returnSize)++;
        return;
    }

    atual[atualSize] = nums[index];
    search(index + 1, nums, numsSize, atual, atualSize + 1, result, returnSize, returnColumnSizes);

    search(index + 1, nums, numsSize, atual, atualSize, result, returnSize, returnColumnSizes);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    int** result = (int**)malloc(totalSubsets * sizeof(int*));

    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    *returnSize = 0;
    
    int* atual = (int*)malloc(numsSize * sizeof(int));

    search(0, nums, numsSize, atual, 0, result, returnSize, *returnColumnSizes);
    
    return result;
}