/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include "header.h"

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int len = 0;
    for(ListNode* curr=head; curr; curr=curr->next, len++);
    k = k % len;
    if(k == 0) return head;
    ListNode* pre = head, *curr = head;
    for(int i=0; i<k; i++, curr=curr->next);
    for(;curr->next;pre=pre->next,curr=curr->next);
    ListNode* res = pre->next;
    pre->next = NULL;
    curr->next = head;
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    print_list(head);
    ListNode* res = rotateRight(head,1);
    print_list(res);
    return 0;
}
