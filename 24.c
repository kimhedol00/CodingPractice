#include <stdio.h>
#include <stdlib.h>


//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL || head->next==NULL)
    return head;
    struct ListNode*first,*second,*out = NULL;
    first = head;
    second = head->next;
    if(head->next->next!=NULL)
    {
        out = head->next->next;
    }
    head = second;
    while(out != NULL && out->next != NULL)
    {
        second->next = first;
        first->next=out->next;
        first = out;
        second = first->next;
        out = second->next;
    }
    second->next = first;
    first->next = out;
    return head;
}