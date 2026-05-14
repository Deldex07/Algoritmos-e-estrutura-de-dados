//83. Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode** pp = &head;

    while(*pp != NULL && (*pp)->next != NULL){
        if((*pp)->val == (*pp)->next->val){
            struct ListNode *temp = (*pp)->next;

            (*pp)->next = temp->next;
            free(temp);
        } else {
            pp = &(*pp)->next;
        }
    }

    return head;
}