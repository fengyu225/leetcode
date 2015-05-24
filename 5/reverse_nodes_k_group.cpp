/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
    }
    return result;
}

void reverse(ListNode* head, ListNode* tail){
    tail->next = NULL;
    if(head == tail || head->next == NULL) return;
    ListNode* begin = head, *curr = head->next;
    begin->next = NULL;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = begin;
        begin = curr;
        curr = temp;
    }
}

ListNode* reverseKGroup(ListNode* head, int k){
    if(!head || k==1) return head;
    ListNode* res = NULL, *curr_tail = NULL, *begin = head, *end = head;
    while(1){
        for(int i=0; i<k-1; i++){
            end = end->next;
            if(!end){
                if(!res) res=begin;
                else curr_tail->next = begin;
                return res;
            }
        }
        ListNode* new_begin = end->next;
        reverse(begin, end);
        if(res) curr_tail->next = end;
        else res = end;
        curr_tail = begin;
        begin = end = new_begin;
        if(!begin) break;
    }
    return res;
}

int main(){
//    int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {1, 2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = reverseKGroup(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
