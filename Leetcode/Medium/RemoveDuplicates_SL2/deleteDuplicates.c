//82. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **pp = &head;

    while((*pp) != NULL && (*pp)->next != NULL){
        if((*pp)->val == (*pp)->next->val){
            int duplicateVal = (*pp)->val;
            while((*pp) != NULL && (*pp)->val == duplicateVal){
                struct ListNode *tmp = *pp;
                (*pp) = (*pp)->next;
                free(tmp);
            }
        }
        else{
            pp = &(*pp)->next;
        }
    }
    return head;
}