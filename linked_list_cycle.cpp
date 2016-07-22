/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include "header.h"

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode* slow = head, *fast = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(!fast) return false;
        fast = fast->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    int arr[] = {0, 1, 2, 3};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), 0);
    bool r = hasCycle(l);
    printf("%s\n", r?"true":"false");
    return 0;
}
