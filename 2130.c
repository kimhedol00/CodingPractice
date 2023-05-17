#include <stdio.h>
#include <stdlib.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head){
    struct ListNode *out = head;
    struct ListNode *half = head;
    int size = 0;
    int ans = 0;

    while(out != NULL)
    {
        out = out->next;
        size++; 
    }
    int* d = (int*)malloc(sizeof(int) * (size / 2));
    int i = 0;
    for(i = 0; i < size / 2; ++i)
    {
        d[i] = half->val;
        half = half->next;
    }
    for(i = size / 2 - 1; i >= 0; --i)
    {
        d[i] += half->val;
        half = half->next;
    }
    ans = d[0];
    for(i = 1; i < size / 2; ++i)
    {
        ans = ans > d[i] ? ans : d[i];
    }
    return ans;        
}

/*
Best Solution
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middle(struct ListNode *head){
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    
    while(fast!=NULL&&fast->next!=NULL){
        
        fast=fast->next->next;
        slow=slow->next;
        
    }
    
    return slow;
}


struct ListNode* reverse(struct ListNode *head){
    
    if(head==NULL||head->next==NULL){
        
        return head;
    }
    
    struct ListNode *curr=head,*prev=NULL,*next=NULL;
    
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    head=prev;
    
    return head;
} 


int pairSum(struct ListNode* head){
    
    if(head==NULL){
        
        return -1;
        
    }
    
    struct ListNode *first=head;
    struct ListNode *tmp=middle(head);
    struct ListNode *second=reverse(tmp);

    int sum=INT_MIN;
    
    while(second!=NULL){
        
        if((first->val+second->val)>sum){
            
            sum=(first->val+second->val);
        }
        
        first=first->next;
        second=second->next;
    }
    
    return sum;
    
}
*/