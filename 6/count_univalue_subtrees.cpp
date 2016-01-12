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

bool search(TreeNode* root, int& count){
    if(!root){
        count = 0;
        return true;
    }
    int l_cnt = 0, r_cnt = 0;
    bool l_res = search(root->left, l_cnt);
    bool r_res = search(root->right, r_cnt);
    bool t = (!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val);
    count = l_cnt+r_cnt+(l_res && r_res && t);
    return l_res && r_res && t;
}

int countUnivalSubtrees(TreeNode* root) {
    if(!root) return 0;
    int count = 0;
    search(root, count);
    return count;
}

int main(){
    TreeNode* root = create_tree("51555#5");
    cout<<countUnivalSubtrees(root)<<endl;
    return 0;
}