//203. Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;

    struct ListNode *atual=temp;

    while(atual->next!=NULL){
        if(atual->next->val == val) atual->next = atual->next->next;
        else atual = atual->next;
    }
    return temp->next;
}