/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include "header.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
    return head;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* l = create_list(arr,sizeof(arr)/sizeof(arr[0]));
    l = reverseBetween(l,1,5);
    while(l){
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
    return 0;
}
