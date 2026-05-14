// 110. Balanced Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int altura(struct TreeNode* root){
    if(!root) return 0;

    int left = altura(root->left);
    int right = altura(root->right);
    if(left == -1 || right == -1) return -1;
    if(abs(left - right) > 1){
        return -1;
    }
    abs(left - right);

    return 1 + (left > right ? left : right );
}
bool isBalanced(struct TreeNode* root) {
    return altura(root) != -1;
}