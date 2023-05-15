#include <stdio.h>
#include <stdlib.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *beg = head;
    struct ListNode *end = head;
    struct ListNode *out = head;

    int len = 1;
    while(head->next != NULL){
        len++;
        head = head->next;
    }

    int k1 = k;
    while(k1 > 1){
        beg = beg->next;
        k1--;
    }
    int k2 = len - k;
    while(k2 > 0){
        end = end->next;
        k2--;
    }

    int temp = beg->val;
    beg->val = end->val;
    end->val = temp;

    return out;
}

/*
Best Solution
struct ListNode* swapNodes(struct ListNode* head, int k)
{
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;

    int listSize = 0;
    int p1Jumps = 0;
    int p2Jumps = 0;
    int temp = 0;

    while (head)
    {
        ++listSize;
        head = head->next;
    }

    head = p1;
    p1Jumps = k - 1;
    p2Jumps = listSize - k;

    while (p1Jumps > 0)
    {
        p1 = p1->next;
        --p1Jumps;
    }

    while (p2Jumps > 0)
    {
        p2 = p2->next;
        --p2Jumps;
    }

    temp = p1->val;
    p1->val = p2->val;
    p2->val = temp;

    return head;
}
*/