/*
Sort a linked list using insertion sort.
*/

#include "header.h"

void addToSorted(ListNode*& head, ListNode*& tail, ListNode* curr){
    if(!head) head=tail=curr;
    else if(head->val>curr->val){
        curr->next = head;
        head = curr;
    }
    else{
        ListNode* temp = head;
        while(temp->next && temp->next->val<=curr->val) temp = temp->next;
        ListNode* x = temp->next;
        temp->next = curr;
        curr->next=x;
        if(!x) tail = curr;
    }
} 

ListNode* insertionSortList(ListNode* head){
    ListNode* curr = head, *new_head = NULL, *new_tail = NULL;
    while(curr){
        ListNode* new_curr = curr->next;
        curr->next = NULL;
        addToSorted(new_head, new_tail, curr);
        curr = new_curr;
    }
    return new_head;
}

int main(){
    int arr[] = {9, 8, 7, 1, 2, 3};
//    int arr[] = {0, 0, 0};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = insertionSortList(l);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
