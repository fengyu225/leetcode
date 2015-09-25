/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#include "header.h"

int minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left) return minDepth(root->right);
    else if(!root->right) return minDepth(root->left);
    else return min(minDepth(root->left), minDepth(root->right));
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
