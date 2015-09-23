/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include "header.h"

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || head && !head->next) return head;
    ListNode* res = NULL, *res_tail = NULL;
    ListNode* pre = head, *curr = pre->next;
    while(curr){
        if(curr->val == pre->val){
            while(curr && curr->val == pre->val) curr = curr->next;
            pre = curr;
            if(!curr) break;
            curr = curr->next;
        } 
        else{
            addToList(res, res_tail, pre);
            pre = curr;
            curr = curr->next;
        }
    }
    if(pre) addToList(res, res_tail, pre);
    return res;
}

int main(){
//    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int arr[] = {1, 1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    l = deleteDuplicates(l);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
