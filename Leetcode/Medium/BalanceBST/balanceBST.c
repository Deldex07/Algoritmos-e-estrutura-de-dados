// 1382. Balance a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void aux(struct TreeNode* root, int* result, int* index){
    if(root == NULL) return;
    aux(root->left, result, index);
    result[*index] = root->val;
    (*index)++;
    aux(root->right , result, index);
}

struct TreeNode* build(int *arr, int left, int right){
    if(left > right) return NULL;

    int mid = (left + right) / 2;

    struct TreeNode* node = malloc(sizeof(struct TreeNode));

    node->val = arr[mid];
    node->left = build(arr, left, mid - 1);
    node->right = build(arr, mid + 1, right);

    return node;
}

int nodeCount(struct TreeNode* root){
    if(root == NULL) return 0;
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int total = nodeCount(root);
    int *arr = malloc(sizeof(int) * total);
    int index = 0;
    aux(root, arr, &index);

    return build (arr, 0, total -1);
}