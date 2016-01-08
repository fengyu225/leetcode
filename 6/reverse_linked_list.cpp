/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include "header.h"

//ListNode* reverseList(ListNode* head) {
//    //iterative
//    if(!head) return head;
//    ListNode* curr = head, *next = head->next;
//    head->next = NULL;
//    while(next){
//        ListNode* temp = next->next;
//        next->next = curr;
//        curr = next;
//        next = temp;
//    }
//    return curr;
//}
//

ListNode* _reverse(ListNode* head, ListNode*& end){
    if(!head->next){
        end = head;
        return head;
    }
    ListNode* x = NULL;
    ListNode* res = _reverse(head->next, x);
    x->next = head;
    head->next = NULL;
    end = head;
    return res;
}

ListNode* reverseList(ListNode* head) {
    //recursively
    if(!head) return NULL;
    ListNode* end = NULL;
    return _reverse(head, end);
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* res = reverseList(head);
    print_list(res);
    return 0;
}