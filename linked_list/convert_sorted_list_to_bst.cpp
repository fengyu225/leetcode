/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include "header.h"

TreeNode* sortedListToBST(ListNode*& head, int l, int r){
    if(l>r || !head) return NULL;
    int m = (l+r)/2;
    TreeNode* left = sortedListToBST(head, l, m-1);
    TreeNode* root = new TreeNode(head->val);
    head = head->next;
    TreeNode* right = sortedListToBST(head, m+1, r);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    int len = 0;
    for(ListNode* curr = head;curr;curr = curr->next, len++);
    return sortedListToBST(head, 0, len-1);
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = sortedListToBST(head);
    pre_order(root);
    printf("\n");
    return 0;
}
