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

bool countUnivalSubtrees(TreeNode* root, int& count){
    if(!root) return true;
    bool l_res = countUnivalSubtrees(root->left, count);
    bool r_res = countUnivalSubtrees(root->right, count);
    int l_v = root->left?root->left->val:root->val;
    int r_v = root->right?root->right->val:root->val;
    if(l_res && r_res && l_v == root->val && r_v == root->val){
        count++;
        return true;
    }
    else return false;
}

int countUnivalSubtrees(TreeNode* root) {
    if(!root) return 0;
    int count = 0;
    countUnivalSubtrees(root, count);
    return count;
}

int main(){
    TreeNode* root = create_tree("51555#5");
    cout<<countUnivalSubtrees(root)<<endl;
    return 0;
}