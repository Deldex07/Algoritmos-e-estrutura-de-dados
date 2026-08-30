/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode dummyLess;
    struct ListNode dummyGreater;

    struct ListNode* l1 = &dummyLess;
    struct ListNode* l2 = &dummyGreater;

    struct ListNode* curr = head;

    while ( curr != NULL ) {
        if ( curr->val < x ) {
            l1->next = curr;
            l1 = l1->next;
        } else {
            l2->next = curr;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    l2->next = NULL;

    l1->next = dummyGreater.next;

    return dummyLess.next;
}