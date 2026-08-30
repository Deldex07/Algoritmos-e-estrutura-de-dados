/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if ( head == NULL || left == right ) return head;
    
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    for( int i = 0; i < left - 1; i++ ) {
        prev = prev->next;
    }

    struct ListNode* curr = prev->next;

    for ( int i = 0; i < right - left; i++ ) {

        struct ListNode* prox = curr->next;
        curr->next = prox->next;
        prox->next = prev->next;
        prev->next = prox;

    }
    return dummy.next;
}