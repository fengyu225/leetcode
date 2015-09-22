/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

#include "header.h"

void deleteNode(ListNode* node) {
    if(!node) return;
    ListNode* curr = node, *pre = NULL;
    while(curr->next){
        curr->val = curr->next->val;
        pre = curr;
        curr = curr->next;
    }
    if(pre) pre->next = NULL;
}

int main(){
    int arr[] = {1, 2, 3, 4};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    deleteNode(head->next->next);
    print_list(head);
    return 0;
}