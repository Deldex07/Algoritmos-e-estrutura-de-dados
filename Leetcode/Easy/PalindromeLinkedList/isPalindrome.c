/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if( head == NULL || head->next == NULL ) return true;

    //middle
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while( fast != NULL && fast->next != NULL ) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow;
    struct ListNode* next;

    
    while( curr != NULL ) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //compare
    struct ListNode* p1 = head;
    struct ListNode* p2 = prev;

    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}