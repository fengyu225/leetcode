/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include "header.h"

//quick sort

void addToList(ListNode*& res, ListNode*& res_tail, ListNode* curr){
    if(!curr) return;
    curr->next = NULL;
    if(!res) res = curr;
    else res_tail->next = curr;
    res_tail = curr;
}

ListNode* sortList(ListNode* head, ListNode*& tail) {
    if(!head) return NULL;
    int h_val = head->val;
    ListNode* curr = head->next, *left_head = NULL, *left_tail = NULL,
        *right_head = NULL, *right_tail = NULL;
    head->next = NULL;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val<=h_val) addToList(left_head, left_tail, curr);
        else addToList(right_head, right_tail, curr);
        curr = temp;
    }
    left_head = sortList(left_head, left_tail);
    right_head = sortList(right_head, right_tail);
    if(left_head) left_tail->next = head;
    head->next = right_head;
    tail = right_tail?right_tail:head;
    return left_head?left_head:head;
}

ListNode* sortList(ListNode* head) {
    ListNode* tail = NULL;
    return sortList(head, tail);
}

int main(){
    int arr[] = {10, 9, 8, 1, 2, 3};
    ListNode* root = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    ListNode* curr = sortList(root);
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
