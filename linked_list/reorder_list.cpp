/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include "header.h"

void reorderList(ListNode* head) {

}

int main(){
    int arr[] = {1, 2, 3, 4};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    reorderList(head);
    ListNode* curr = head;
    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    return 0;
}
