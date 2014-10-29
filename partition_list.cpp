/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
*/

#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert_node(ListNode*& head, ListNode*& tail, ListNode* c){
    if(head){
        tail->next = c;
        tail = c;
    }
    else
        head = tail = c;
    tail->next = NULL;
}

ListNode *partition(ListNode *head, int x) {
    ListNode* small_head = NULL, *small_tail = NULL;
    ListNode* large_head = NULL, *large_tail = NULL;
    ListNode* curr = head;
    while(curr){
        ListNode* temp = curr->next;
        if(curr->val<x)
            insert_node(small_head,small_tail,curr);
        else
            insert_node(large_head,large_tail,curr);
        curr = temp;
    }
    if(small_head){
        small_tail->next = large_head;
        return small_head;
    }
    else
        return large_head;
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
    //int arr[] = {1, 4, 3, 2, 5, 2};
    int arr[] = {2,1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = partition(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
