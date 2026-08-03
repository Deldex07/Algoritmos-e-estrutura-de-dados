/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while( slow ) {
        if(fast == NULL || fast->next == NULL || fast->next->next == NULL) return false;
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }
    return false;
}