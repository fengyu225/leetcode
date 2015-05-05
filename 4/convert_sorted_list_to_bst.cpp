#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode*& head, int l, int r){
    if(l>r) return NULL;
    int m = (l+r)/2;
    TreeNode* l_child = sortedListToBST(head, l, m-1);
    TreeNode* root = new TreeNode(head->val);
    head = head->next;
    root->left  = l_child;
    root->right = sortedListToBST(head, m+1, r);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    int len = 0;
    for(ListNode* curr = head; curr; len++,curr=curr->next);
    return sortedListToBST(head, 0, len-1);
}

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
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
