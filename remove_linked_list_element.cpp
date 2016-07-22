/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "header.h"

void addToList(ListNode*& head, ListNode*& tail, ListNode* temp){
    if(!head) head=temp;
    else tail->next = temp;
    tail = temp;
    tail->next = NULL;
}

ListNode* removeElements(ListNode* head, int val){
    if(!head) return head;
    ListNode* curr = head;
    ListNode* res_head = NULL, *res_tail=NULL;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val != val)
            addToList(res_head, res_tail, curr);
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