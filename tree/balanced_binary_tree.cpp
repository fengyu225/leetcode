/*
 *
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

*/

#include  "header.h"

bool isBalanced(TreeNode* root, int& depth){
    if(!root){
        depth = 0;
        return true;
    }
    int l_depth = 0, r_depth = 0;
    bool l_res = isBalanced(root->left, l_depth);
    bool r_res = isBalanced(root->right, r_depth);
    depth = max(l_depth, r_depth)+1;
    return l_res && r_res && abs(l_depth-r_depth)<=1;
}

bool isBalanced(TreeNode* root) {
    if(!root) return true;
    int depth = 0;
    return isBalanced(root, depth);
}

int main(){
    //TreeNode* root = create_tree("12534#1");
    TreeNode* root = create_tree("1#2#3");
    printf("%d\n", isBalanced(root));
    return 0;
}
