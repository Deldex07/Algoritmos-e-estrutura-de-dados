/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* root, int currSum) {
    if( root == NULL ) return 0;

    currSum = currSum * 10 + root->val;

    if( !root->left && !root->right ) {
        return currSum;
    }

    return helper(root->left, currSum) + helper(root->right, currSum);
}
int sumNumbers(struct TreeNode* root) {
    return helper(root, 0);
}