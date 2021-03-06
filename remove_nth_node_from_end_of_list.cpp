/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(!head) return head;
    ListNode* curr = head, *next = curr, *pre = NULL;
    for(int i=0; i<n-1; i++){
        if(!next) return NULL;
        next = next->next;
    }
    while(next->next){
        pre = curr;
        curr = curr->next;
        next = next->next;
    }
    if(pre){
        ListNode* t = curr->next;
        pre->next = t;
    }
    else
        head = curr->next;
    return head;
}

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

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* r = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    r = removeNthFromEnd(r,6);
    while(r){
        printf("%d ", r->val);
        r=r->next;
    }
    printf("\n");
    return 0;
}
