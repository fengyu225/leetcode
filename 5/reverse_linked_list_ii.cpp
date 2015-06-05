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

void reverse(ListNode* head, ListNode* tail){
    if(head->next == NULL || head == tail) return;
    ListNode* curr=head, *next = curr->next;
    curr->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* front_head = NULL, *front_tail = NULL;
    ListNode* middle_head = NULL, *middle_tail = NULL;
    ListNode* last_head = NULL;
    ListNode* curr = head;
    int s = 1;
    while(curr){
        if(s == m-1){
            front_head = head;
            front_tail = curr;
        }
        if(s == m) middle_head = curr;
        if(s == n) middle_tail = curr;
        if(s == n+1) last_head = curr;
        s++;
        curr = curr->next;
    }
    middle_tail->next = NULL;
    reverse(middle_head, middle_tail);
    ListNode* res = NULL;
    if(front_head){
        front_tail->next = middle_tail;
        res = front_head;
    }
    else res = middle_tail;
    middle_head->next = last_head;
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {5};
    ListNode* l = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    l = reverseBetween(l,1,1);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
