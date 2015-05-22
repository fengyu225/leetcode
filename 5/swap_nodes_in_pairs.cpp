/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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

ListNode* swapPairs(ListNode *head) {
    //1 2 3 4 5 6 7
    //2 1 4 3 6 5 7
    if(!head || !head->next) return head;
    ListNode* first=NULL, *second=NULL, *curr_tail=NULL, *res=head->next, *new_head=head;
    while(new_head){
        first = new_head;
        second = new_head->next;
        ListNode* temp = NULL;
        if(!second){
            new_head = second;
        }
        else{
            new_head = second->next;
            first->next = NULL;
            second->next = first;
        }
        temp = first; 
        temp->next = NULL;
        if(curr_tail)
            curr_tail->next = second?second:first;
        curr_tail = temp;
    } 
    return res;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = swapPairs(l);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
