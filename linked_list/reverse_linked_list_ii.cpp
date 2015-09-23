/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include "header.h"

void addToList(ListNode*& res, ListNode*& res_tail, ListNode* curr){
    curr->next = NULL;
    if(!res) res = curr;
    else res_tail->next = curr;
    res_tail = curr;
}

void reverse_list(ListNode* head, ListNode* tail){
    if(head == tail) return;
    ListNode* curr = head, *next = head->next;
    curr->next = NULL;
    while(curr != tail){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head) return head;
    ListNode* res = NULL, *res_tail = NULL;
    ListNode* curr = head;
    for(int i=1; i<m; i++){
        ListNode* temp = curr->next;
        addToList(res, res_tail, curr);
        curr = temp;
    }
    ListNode* tail = curr;
    for(int i=m; i<n; i++) tail = tail->next;
    ListNode* nx = tail->next;
    tail->next = NULL;
    reverse_list(curr, tail);
    if(res) res_tail->next = tail;
    else res = tail;
    curr->next = nx;
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
//    int arr[] = {5};
    ListNode* l = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    l = reverseBetween(l,1,5);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
