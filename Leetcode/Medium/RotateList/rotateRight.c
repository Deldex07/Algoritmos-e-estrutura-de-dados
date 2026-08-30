/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if( head == NULL || head->next == NULL || k == 0 ) return head;
    
    struct ListNode* tail = head;
    int N_count = 1;

    while( tail->next != NULL ) {
        tail = tail->next;
        N_count++;
    }

    k = k % N_count;
    if ( k == 0 ) return head;

    tail->next = head;

    struct ListNode* new_tail = head;
    for ( int i = 0; i < N_count - k - 1; i++ ) {
        new_tail = new_tail->next;
    }
    struct ListNode* newHead = new_tail->next;
    new_tail->next = NULL;

    return newHead;
}