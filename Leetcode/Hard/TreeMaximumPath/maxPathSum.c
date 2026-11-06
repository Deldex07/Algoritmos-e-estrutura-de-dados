/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int aux( struct TreeNode* root, int *best ) {
    if( root == NULL ) return 0;
    int a = aux(root->left, best);
    int b = aux(root->right, best);

    a = a > 0 ? a : 0;
    b = b > 0 ? b : 0;

    *best = *best > a + b + root->val ? *best : a + b + root->val;

    return root->val + ( a > b ? a : b );
}
int maxPathSum(struct TreeNode* root) {
    int best = INT_MIN;
    aux(root, &best);
    return best;
}