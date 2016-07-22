/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include "header.h"

TreeNode* sortedListToBST(ListNode*& head, int l, int r){
    if(!head || l>r) return NULL;
    int m = (l+r)/2;
    TreeNode* l_res = sortedListToBST(head, l, m-1);
    TreeNode* res = new TreeNode(head->val);
    head = head->next;
    TreeNode* r_res = sortedListToBST(head, m+1, r);
    res->left = l_res;
    res->right = r_res;
    return res;
}

TreeNode* sortedListToBST(ListNode* head){
    if(!head) return NULL;
    int last = 0;
    for(ListNode* curr=head; curr; curr=curr->next,last++);
    return sortedListToBST(head, 0, last-1);
}

int main(){
    ListNode l0(0);
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    ListNode l7(7);
    ListNode l8(8);
    l0.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    TreeNode* root = sortedListToBST(&l0);
    pre_order(root);
    printf("\n");
    return 0;
}
