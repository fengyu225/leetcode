/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include "header.h"

void expand(ListNode*& head, ListNode*& curr_tail, ListNode* curr){
    if(!head) head = curr;
    else curr_tail->next = curr;
    curr_tail = curr;
    curr_tail->next = NULL;
}

ListNode *partition(ListNode *head, int x) {
    ListNode* small = NULL, *large = NULL, *curr = head;
    ListNode* small_tail = NULL, *large_tail = NULL;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val<x) expand(small, small_tail, curr);
        else expand(large, large_tail, curr);
        curr = temp;
    }
    ListNode* res;
    if(small_tail){small_tail->next = large; res=small;}
    else {res=large;}
    return res;
}

int main(){
    int arr[] = {1, 4, 3, 2, 5, 2};
    //int arr[] = {2,1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = partition(l,3);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
