// 101. Symmetric Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool aux (struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return aux(p->left, q->right) && aux(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
    return aux(root, root);
}