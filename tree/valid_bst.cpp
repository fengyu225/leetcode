/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include "header.h"

bool isValidBST(TreeNode* root, long long l_bound, long long r_bound){
    if(!root) return true;
    int l_res = isValidBST(root->left, l_bound, root->val);
    int r_res = isValidBST(root->right, root->val, r_bound);
    return l_res && r_res && root->val<r_bound && root->val>l_bound;
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    return isValidBST(root, (double)(INT_MIN)-1, (double)(INT_MAX)+1);
}

int main(){
    TreeNode* root = create_tree("21");
    bool res = isValidBST(root);
    printf("%s\n", res?"true":"false");
    return 0;
}
