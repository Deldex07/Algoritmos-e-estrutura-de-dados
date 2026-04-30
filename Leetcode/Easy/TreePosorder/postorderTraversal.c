//145. Binary Tree Postorder Traversal
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
void aux(struct TreeNode* root, int* result, int* index){
    if(root == NULL) return;
    aux(root->left, result, index);
    aux(root->right , result, index);

    result[*index] = root->val;
    (*index)++;
}

int nodeCount(struct TreeNode* root){
    if(root == NULL) return 0;
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
    *returnSize = 0;
    return NULL;
}
    int total = nodeCount(root);
    int* result = malloc(total*sizeof(int));
    int index = 0;

    aux(root, result, &index);

    *returnSize = index;
    return result;
}