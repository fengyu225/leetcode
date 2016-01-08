/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "header.h"

void addToList(ListNode*& head, ListNode*& curr, ListNode* x){
    x->next = NULL;
    if(!curr) head = x;
    else curr->next = x;
    curr = x;
}

ListNode* removeElements(ListNode* head, int val){
    if(!head) return head;
    ListNode* res_head = NULL, *res_curr = NULL, *curr = head;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val != val) addToList(res_head, res_curr, curr);
        curr = temp;
    }
    return res_head;
}

int main(){
    int arr[] = {1,2,6,3,4,5,6};
    ListNode* head = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    print_list(removeElements(head, 6));
    return 0;
}