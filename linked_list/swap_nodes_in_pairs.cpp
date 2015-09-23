/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

#include "header.h"

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* curr = head, *next = head->next, *temp = NULL;
    ListNode* res = NULL, *res_tail = NULL;
    while(1){
        if(!curr || !next) break; 
        temp = next->next;
        addToList(res, res_tail, next);
        addToList(res, res_tail, curr);
        curr = temp;
        if(!temp) break;
        next = temp->next;
    }
    if(curr) addToList(res, res_tail, curr);
    return res;
}

int main(){
    //int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {1, 2};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = swapPairs(l);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
