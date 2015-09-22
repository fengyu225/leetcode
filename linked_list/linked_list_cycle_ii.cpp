/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

#include "header.h"

ListNode *detectCycle(ListNode *head) {
    if(!head) return NULL;
    ListNode* slow = head, *fast = head;
    while(fast){
        fast = fast->next;
        if(!fast) return NULL;
        fast = fast->next;
        slow = slow->next;
        if(slow == fast) break;
    }
    if(!fast) return NULL;
    ListNode* x = head;
    while(x != slow){
        x = x->next;
        slow = slow->next;
    }
    return x;
}


int main(){
   // int arr[] = {0, 1, 2, 3};
    int arr[] = {1,2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), 1);
    ListNode* r = detectCycle(l);
    if(r)
        printf("%d\n", r->val);
    return 0;
}
