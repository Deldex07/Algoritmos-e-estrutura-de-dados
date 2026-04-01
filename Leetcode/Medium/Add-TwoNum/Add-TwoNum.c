//2. Add Two Numbers - Medium

/*You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;  

    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode *current = &dummy;

    while(l1 != NULL || l2 != NULL || carry != 0){

        int val1 = (l1) ? l1->val : 0;
        int val2 = (l2) ? l2->val : 0;

        int soma = val1 + val2 + carry;
        carry = soma / 10;
        int digit = soma % 10;

        struct ListNode *novo = malloc(sizeof(struct ListNode));
        if(!novo){
            printf("Memory allocation failed!\n");
            exit(1);
        }

        novo->val = digit;
        novo->next = NULL;

        current->next = novo;
        current = novo;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    return dummy.next;
}