// 114. Flatten Binary Tree to Linked List
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root == NULL) return;

    flatten(root->left);
    flatten(root->right);
    struct TreeNode* tempRight = root->right;
    root->right = root->left;
    root->left = NULL;

    struct TreeNode* curr = root;
    while(curr->right != NULL){
        curr = curr->right;
    }
    curr->right = tempRight;
}