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

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        res.push_back(curr->val);
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
    return res;
}

int main(){
    TreeNode* root = create_tree("1#23");
    vector<int> res = preorderTraversal(root);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
