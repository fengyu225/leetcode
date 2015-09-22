/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include "header.h"

int getLen(ListNode* l){
    int res = 0;
    for(;l;res++, l = l->next);
    return res;
}

void reorderList(ListNode*& curr, ListNode*& head, int l, int r){
    if(l>r){
        head = NULL;
        return;
    }
    if(l == r){
        head = curr;
        curr = curr->next;
        head->next = NULL;
        return;
    }
    ListNode* x_head = NULL;
    head = curr;
    curr = curr->next;
    reorderList(curr, x_head, l+1, r-1);
    head->next = curr;
    curr = curr->next;
    head->next->next = x_head;
}

void reorderList(ListNode* head) {
    int len = getLen(head);
    ListNode* new_head = NULL, *new_tail = NULL;
    reorderList(head, new_head, 0, len-1);
    head = new_head;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
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
