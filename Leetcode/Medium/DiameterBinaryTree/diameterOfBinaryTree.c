/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int aux( struct TreeNode* root, int* best ) {
    if( root == NULL ) return 0;

    int left = aux(root->left, best);
    int right = aux(root->right, best);

    *best = *best > left + right ? *best : left + right;

    return 1 + ( left > right ? left : right );
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    aux(root, &diameter);
    return diameter;
}