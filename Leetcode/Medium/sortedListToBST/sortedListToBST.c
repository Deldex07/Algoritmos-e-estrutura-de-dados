/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildBalanced(int* arr, int start, int end) {
    
    if (start > end) return NULL;
    
    int mid = (start + end) / 2;

    struct TreeNode* node = malloc(sizeof(struct TreeNode));
node->val = arr[mid];

node->left  = buildBalanced(arr, start, mid - 1);

node->right = buildBalanced(arr, mid + 1, end);

    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int count = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    int* arr = malloc(count * sizeof(int));
    int idx = 0;
    curr = head;
    while (curr != NULL) {
        arr[idx++] = curr->val;
        curr = curr->next;
    }

    struct TreeNode* result = buildBalanced(arr, 0, idx - 1);
    free(arr);
    return result;
}