/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
*/

#include "header.h"

TreeNode* upsideDownBinaryTree(TreeNode* root){
    return root;
}

int main(){
    TreeNode* root = create_tree("12345");
    TreeNode* new_root = upsideDownBinaryTree(root);
    pre_order(new_root);
    cout<<endl;
    return 0;
}