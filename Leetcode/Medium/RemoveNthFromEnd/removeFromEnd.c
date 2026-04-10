//19. Remove Nth Node From End of List
//Given the head of a linked list, remove the nth node from the end of the list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode **pp = &head;
    struct ListNode *fast = head;
    for(int i = 0; i<n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        fast = fast->next;
        pp = &(*pp)->next;
    }
    *pp = (*pp)->next;

    return head;
}

//head -> 1 -> 2 -> 3 -> 4 -> 5
//n = 2
// pp ->&head;
// fast ->1

//i = 0 fast -> 2
//i = 1 fast -> 3