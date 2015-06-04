/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include "header.h"

ListNode *deleteDuplicates(ListNode *head){
    ListNode* curr_tail = NULL, *curr=head;
    ListNode* res = NULL;
    if(!curr || !curr->next) return head;
    ListNode* next = curr->next;
    bool add=true;
    while(next){
        if(next->val == curr->val){add=false;next=next->next;}
        else{
            if(add){
                if(curr_tail) curr_tail->next=curr;
                else res = curr;
                curr_tail = curr;
            }
            curr=next;
            next=curr->next;
            add=true;
        }
    }
    ListNode* temp;
    if(add) temp = curr;
    else temp = NULL;
    if(curr_tail) curr_tail->next=temp;
    else res=temp;
    return res;
}

int main(){
//    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int arr[] = {1, 2, 2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    l = deleteDuplicates(l);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
