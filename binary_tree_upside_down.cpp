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

void search(TreeNode* root, TreeNode*& new_root, TreeNode*& curr){
    if(!root->left){
        curr = new_root = root;
        curr->left = curr->right = NULL;
        return;
    }
    TreeNode* temp = NULL;
    search(root->left, new_root, temp);
    temp->left = root->right;
    temp->right= root;
    curr = root;
    curr->left = curr->right = NULL;
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if(!root) return NULL;
    TreeNode* new_root = NULL, *curr = NULL;
    search(root, new_root, curr);
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