/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxIndex(int* arr, int left, int right) {
    int maxIndex = left;
    for( int i = left ; i <= right ; i++ ) {
        if( arr[i] > arr[maxIndex] ) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

struct TreeNode* aux ( int *arr, int left, int right) {
    if(left > right) return NULL;
    
    int max = maxIndex(arr, left, right);

    struct TreeNode* root = malloc( sizeof( struct TreeNode ) );
    root->val = arr[max];

    root->left = aux(arr, left, max-1);
    root->right = aux(arr, max+1, right);

    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return aux(nums, 0, numsSize-1);
}