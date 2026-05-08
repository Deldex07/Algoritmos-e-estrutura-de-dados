// 450. Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* getMin(struct TreeNode* node) {
    while (node->left) node = node->left;
    return node;
}

struct TreeNode* rebalance(struct TreeNode* root) {
    int hl = (root->left) ? root->left->val : 0;
    int hr = (root->right) ? root->right->val : 0; 

    struct TreeNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (!root) return NULL;


    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {

        if (!root->left || !root->right) {
            struct TreeNode* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        struct TreeNode* temp = getMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}