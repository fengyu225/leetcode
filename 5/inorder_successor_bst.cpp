/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

#include "header.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(!p) return NULL;
    if(p->right){
        TreeNode* res = NULL;
        for(res = p->right;res->left;res = res->left);
        return res;
    }
    stack<TreeNode*> s;
    for(TreeNode* temp = root; temp!=p; s.push(temp), temp = p->val<=temp->val?temp->left:temp->right);
    for(TreeNode* curr = p;!s.empty() && s.top()->right == curr;curr=s.top(), s.pop());
    return s.empty()?NULL:s.top();
}


int main(){
    TreeNode* root = create_tree("42513#6##7#");
    TreeNode* p = root->left->right->left;
    TreeNode* res = inorderSuccessor(root, p);
    if(!res) cout<<"NULL"<<endl;
    else cout<<res->val<<endl;
    return 0;
}