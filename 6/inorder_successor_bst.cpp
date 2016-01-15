/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

#include "header.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

}

int main(){
    TreeNode* root = create_tree("42513#6");
    TreeNode* p = root->left->right;
    TreeNode* res = inorderSuccessor(root, p);
    if(!res) cout<<"NULL"<<endl;
    else cout<<res->val<<endl;
    return 0;
}