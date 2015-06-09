/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include "header.h"

int minDepth(TreeNode *root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    int l=INT_MAX, r=INT_MAX;
    if(root->left) l = minDepth(root->left);
    if(root->right) r = minDepth(root->right);
    return min(l,r)+1;
}

int main(){
/*
            1
        /       \
       2         5
    /    \        \
   3     4        6
*/
    TreeNode* root = create_tree("12534#6");
    cout<<minDepth(root)<<endl;
    return 0;
}
