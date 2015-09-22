/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

#include "header.h"

ListNode *detectCycle(ListNode *head) {
}


int main(){
   // int arr[] = {0, 1, 2, 3};
    int arr[] = {1,2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), -1);
    ListNode* r = detectCycle(l);
    if(r)
        printf("%d\n", r->val);
    return 0;
}
