/*
 *
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

*/

#include  "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool balanced(TreeNode* root, int& height){
    if(!root){
        height = 0;
        return true;
    }
    int l_height,r_height;
    bool l = balanced(root->left,l_height);
    bool r = balanced(root->right,r_height);
    if(!l || !r) return false;
    height = std::max(l_height,r_height)+1;
    return abs(l_height-r_height)<=1;
}

bool isBalanced(TreeNode *root) {
    int height = 0;
    return balanced(root,height);
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(1);
    n1.left = &n2;
//    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    printf("%d\n", isBalanced(&n1));
    return 0;
}
