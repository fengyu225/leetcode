/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

#include "header.h"

void addToList(ListNode*& res, ListNode*& res_tail, ListNode* curr){
    curr->next = NULL;
    if(!res) res = curr;
    else res_tail->next = curr;
    res_tail = curr;
}
    
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return NULL;
    ListNode* res = NULL, *res_tail = NULL;
    while(head){
        ListNode* temp = head->next;
        if(head->val != val)
            addToList(res, res_tail, head);
        head = temp;
    }
    return res;
}

int main(){
    int arr[] = {1,2,6,3,4,5,6};
    ListNode* head = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    print_list(removeElements(head, 6));
    return 0;
}