/*
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9

to 

     4
   /   \
  7     2
 / \   / \
9   6 3   1

This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

#include "header.h"

TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

int main(){
    TreeNode* root = create_tree("4271369");
    pre_order(invertTree(root));
    cout<<endl;
    return 0;
}