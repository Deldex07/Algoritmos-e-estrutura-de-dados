/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void aux( struct TreeNode* root, int* returnSize, int* ans, int curr ) {
    if( root == NULL ) {
        return;
    }
    if(curr > *returnSize ) {
        ans[*returnSize] = root->val;
        *returnSize += 1;
    }

    aux(root->right, returnSize, ans, curr+1);
    aux(root->left, returnSize, ans, curr+1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if( !root ) {
        *returnSize = 0;
        return NULL;
    }

    int* ans = malloc( sizeof( int ) * 100 );
    *returnSize = 0;
    aux(root, returnSize, ans, 1);
    return ans;
}