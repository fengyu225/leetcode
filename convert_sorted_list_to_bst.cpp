#include<stdio.h>
#include<stdlib.h>

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

TreeNode* sortedListToBST(ListNode*& head, int start, int end){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    TreeNode* left_sub_tree_root = sortedListToBST(head,start,mid-1);
    TreeNode* root = new TreeNode(head->val);
    head = head->next;
    root->left = left_sub_tree_root;
    root->right = sortedListToBST(head,mid+1,end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int i = 0;
    ListNode* curr = head;
    while(curr){
        i++;
        curr = curr->next;
    }
    return sortedListToBST(head,0,i-1);
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
    return 0;
}
