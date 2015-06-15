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

void upsideDown(TreeNode* root, TreeNode*& new_root, TreeNode*& tail){
    if(!root || !root->left){
        new_root = root;
        tail = root;
        return;
    }
    TreeNode* l_new_root = NULL, *l_tail = NULL;
    upsideDown(root->left, l_new_root, l_tail);
    TreeNode* temp = root->right;
    root->left = root->right = NULL;
    l_tail->left = temp;
    l_tail->right = root;
    new_root = l_new_root;
    tail = root;
}

TreeNode* upsideDownBinaryTree(TreeNode* root){
    if(!root || !root->left) return root;
    TreeNode* new_root = NULL, *tail=NULL;
    upsideDown(root, new_root, tail);
    return new_root;
}

int main(){
    TreeNode* root = create_tree("12#45");
    TreeNode* new_root = upsideDownBinaryTree(root);
    pre_order(new_root);
    cout<<endl;
    in_order(new_root);
    cout<<endl;
    return 0;
}