// 700. Search in a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *ptr = root;
    struct TreeNode *result = NULL;
    while(ptr != NULL){
        if(ptr->val == val){
            result = ptr;
            break;
        }

        if(ptr->val > val){
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    return result;
}