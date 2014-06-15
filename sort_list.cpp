#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
    if(!head) return NULL;
    if(!head->next) return head;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* r_begin = slow->next;
    slow->next = NULL;
    ListNode* l = sortList(head);
    ListNode* r = sortList(r_begin);
    ListNode* result=NULL;
    ListNode* curr=NULL;
    ListNode* temp=NULL;
    while(l && r){
        if(l->val>r->val){
            temp = l;
            l = l->next;
        }
        else{
            temp = r;
            r = r->next;
        }
        if(curr) curr->next = temp;
        else curr=temp;
        result = result==NULL?temp:result;
    }
    temp = l?l:r;
    if(temp){
        if(curr) curr->next = temp;
        else curr = temp;
        result = result==NULL?temp:result;
    }
    return result;
}

int main(){
    ListNode l0(0);
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    l0.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    ListNode* curr = sortList(&l0);
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
