/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include "header.h"

ListNode *deleteDuplicates(ListNode *head) {
    if(!head) return head;
    ListNode* res = NULL, *res_tail = NULL, *curr = head;
    while(curr){
        ListNode* temp = curr->next;
        if(!res_tail || res_tail->val != curr->val)
            addToList(res, res_tail, curr);
        curr = temp;
    }
    return res;
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
