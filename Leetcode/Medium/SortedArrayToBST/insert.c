// 108. Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode* insert(int *arr, int left, int right){
    if(left>right)
    {
        return NULL;
    }
    int mid= left+(right-left)/2;
    struct TreeNode *root= (struct TreeNode*)(malloc(sizeof(struct TreeNode)));
    root->val= arr[mid];
    root->left=insert(arr, left, mid-1);
    root->right= insert(arr, mid+1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return insert(nums, 0, numsSize-1);
}