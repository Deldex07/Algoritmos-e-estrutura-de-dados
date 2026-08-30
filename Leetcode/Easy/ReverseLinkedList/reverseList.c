/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* prox = NULL;
    
    while( curr != NULL ) {
        prox = curr->next;
        curr->next = prev;
        prev = curr;
        curr = prox;
    }

    return prev;
}