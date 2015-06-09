/*
 *
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

*/

#include  "header.h"

bool isBalanced(TreeNode* root, int& height){
    if(!root){
        height = 0;
        return true;
    }
    int l_h = 0, r_h=0;
    bool res = isBalanced(root->left, l_h) && isBalanced(root->right, r_h);
    height = max(l_h, r_h)+1;
    return res && abs(l_h-r_h)<=1;
}

bool isBalanced(TreeNode* root){
    if(!root) return true;
    int height = 0;
    return isBalanced(root, height);
}

int main(){
    TreeNode* root = create_tree("12534#1");
    printf("%d\n", isBalanced(root));
    return 0;
}
