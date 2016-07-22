/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include "header.h"

ListNode *deleteDuplicates(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* curr = head->next, *curr_tail = head;
    while(curr){
        if(curr->val == curr_tail->val) curr = curr->next;
        else{
            curr_tail->next = curr;
            curr_tail = curr;
            curr = curr->next;
        }
    }
    if(curr_tail) curr_tail->next = NULL;
    return head;
}

int main(){
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
//    int arr[] = {1, 2, 2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    l = deleteDuplicates(l);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
