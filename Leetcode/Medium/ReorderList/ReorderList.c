/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while( fast != NULL && fast->next != NULL ) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    slow->next = NULL;

    while( curr != NULL ) {
        struct ListNode* aux = curr->next;
        curr->next = prev;
        prev = curr;
        curr = aux;
    }

    struct ListNode* first = head;
    struct ListNode* second = prev;

    while( second != NULL ) {
        struct ListNode* temp1 = first->next;
        struct ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}