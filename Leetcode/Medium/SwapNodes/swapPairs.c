//24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode** pp = &head;
    while((*pp) != NULL && (*pp)->next != NULL){
        struct ListNode* a = *pp;
        struct ListNode* b = a->next;
        struct ListNode* c = b->next;

        b->next = a;
        a->next = c;
        *pp = b;
        pp = &a->next;
    }
    return head;
}