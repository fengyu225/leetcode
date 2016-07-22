/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include "header.h"

void reverse(ListNode* head, ListNode*& new_head, ListNode*& new_tail){
    if(!head) return;
    ListNode* l = NULL, *r = NULL;
    reverse(head->next, l, r);
    head->next = NULL;
    if(r){
        r->next = head;
        new_tail = head;
        new_head = l;
    }
    else new_tail = new_head = head;
}

ListNode* reverseList(ListNode* head){
    //recursive
    if(!head) return NULL;
    ListNode* new_head = NULL, *new_tail = NULL;
    reverse(head, new_head, new_tail);
    return new_head;
}

//ListNode* reverseList(ListNode* head){
//    //iterative
//    if(!head) return NULL;
//    ListNode* curr = head, *next = head->next;
//    curr->next = NULL;
//    while(next){
//        ListNode* temp = next->next;
//        next->next = curr;
//        curr = next;
//        next = temp;
//    }
//    return curr;
//}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* res = reverseList(head);
    print_list(res);
    return 0;
}