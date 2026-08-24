/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if ( head == NULL ) return head;

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while( curr != NULL ) {
        struct ListNode* n_temp = curr->next;
        struct ListNode* prev = &dummy;

        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = n_temp;
    }

    return dummy.next;
}