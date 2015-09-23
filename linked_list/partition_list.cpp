/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include "header.h"

void addToList(ListNode*& res, ListNode*& res_tail, ListNode* curr){
    curr->next = NULL;
    if(!res) res = curr;
    else res_tail->next = curr;
    res_tail =  curr;
}

ListNode* partition(ListNode* head, int x) {
    if(!head) return NULL;
    ListNode* l_res = NULL, *l_res_tail = NULL, 
        *r_res = NULL, *r_res_tail = NULL, *curr = head;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val<x) addToList(l_res, l_res_tail, curr);
        else addToList(r_res, r_res_tail, curr);
        curr = temp;
    }
    if(l_res) l_res_tail->next = r_res;
    return l_res_tail?l_res:r_res;
}

int main(){
    int arr[] = {1, 4, 3, 2, 5, 2};
    //int arr[] = {2,1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = partition(l,3);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
