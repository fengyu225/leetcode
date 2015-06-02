/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
    if(!head) return NULL;
    int count = 1;
    ListNode* curr = head;
    while(curr->next){
        count++;
        curr=curr->next; 
    }
    curr->next = head;
    ListNode* res;
    if(k%count)
        for(int i=0; i<count-k%count; i++) curr = curr->next;
    res = curr->next;
    curr->next = NULL;
    return res;
}

int main(){
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    ListNode* curr = &l1;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    ListNode* res = rotateRight(&l1,1);
    while(res){
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}
