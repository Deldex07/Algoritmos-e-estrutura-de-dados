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

#define SIZE 10000
int size = 0, maxFreq = 0;
int sums[SIZE], freq[SIZE];

int find (int x){
for(int i = 0; i<size; i++){
    if (sums[i]==x) return i;
}
    return -1;
}

int dfs(struct TreeNode* root) {
    if (!root) return 0;

    int s = root->val + dfs(root->left) + dfs(root->right);

    int i = find(s);

    if (i == -1) {
        sums[size] = s;
        freq[size++] = 1;
    } else {
        freq[i]++;
    }

    if (freq[i == -1 ? size - 1 : i] > maxFreq)
        maxFreq = freq[i == -1 ? size - 1 : i];

    return s;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {

    size = 0;
    maxFreq = 0;

    dfs(root);

    int* ans = (int*)malloc(sizeof(int) * size);
    int k = 0;

    for (int i = 0; i < size; i++) {
        if (freq[i] == maxFreq)
            ans[k++] = sums[i];
    }

    *returnSize = k;

    return ans;
}