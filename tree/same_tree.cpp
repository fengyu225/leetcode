/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

#include "header.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p && q || !q && p) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    TreeNode* p = create_tree("12345");
    TreeNode* q = create_tree("12345");
    cout<<isSameTree(p,q)<<endl;
}