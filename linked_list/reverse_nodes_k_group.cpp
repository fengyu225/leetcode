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

void add(ListNode*& res, ListNode*& res_tail, ListNode* head, ListNode* tail){
    if(!res) res = head;
    else res_tail->next = head;
    res_tail = tail;
}

void reverse(ListNode* head, ListNode* tail){
    if(!head || head && !head->next) return;
    ListNode* curr = head, *next = head->next;
    head->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
}

ListNode* reverseKGroup(ListNode* head, int k){
    if(!head || k==1) return head;
    ListNode* res = NULL, *res_tail = NULL;
    ListNode* tail = head;
    while(tail){
        for(int i=1; i<k; i++){
            if(tail) tail = tail->next;
            else break;
        }
        if(tail){
            ListNode* temp = tail->next;
            tail->next = NULL;
            reverse(head, tail);
            print_list(tail);
            add(res, res_tail, tail, head);
            head = tail = temp;
        }
        else{
            add(res, res_tail, head, tail);
            break;
        }
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
