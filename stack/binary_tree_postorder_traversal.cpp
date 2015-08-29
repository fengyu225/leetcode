/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "header.h"

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    
}

int main(){
    TreeNode* root = create_tree("1#23");
    vector<int> res = postorderTraversal(root);
    print_vector<int>(res);
    return 0;
}