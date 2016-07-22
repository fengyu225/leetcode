/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
*/

#include "header.h"

bool search(TreeNode* root, int& res){
    if(!root) return true;
    int l_temp = 0, r_temp = 0;
    bool l_res = search(root->left, l_temp);
    bool r_res = search(root->right, r_temp);
    if(l_res && r_res && 
            (!root->left || root->left->val == root->val) && 
            (!root->right || root->right->val == root->val)){
        res = l_temp+r_temp+1;
        return true;
    }
    else{
        res = l_temp+r_temp;
        return false;
    }
}

int countUnivalSubtrees(TreeNode* root){
    if(!root) return 0;
    int res = 0;
    search(root, res);
    return res;
}

int main(){
    TreeNode* root = create_tree("51555#5");
    cout<<countUnivalSubtrees(root)<<endl;
    return 0;
}