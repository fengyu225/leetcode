/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include "header.h"

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode* slow = head, *fast = head;
    do{
        fast = fast->next;
        if(!fast) return false;
        fast = fast->next;
        if(!fast) return false;
        slow = slow->next;
        if(!slow) return false;
    }while(slow && fast && slow != fast);
    return true;
}

int main(){
    int arr[] = {0, 1, 2, 3};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]), 0);
    bool r = hasCycle(l);
    printf("%s\n", r?"true":"false");
    return 0;
}
