/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "header.h"

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    
}

int main(){
    TreeNode* root = create_tree("1#23");
    vector<int> res = preorderTraversal(root);
    print_vector<int>(res);
    return 0;
}