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

int countUnivalSubtrees(TreeNode* root) {

}

int main(){
    TreeNode* root = create_tree("51555#5");
    cout<<countUnivalSubtrees(root)<<endl;
    return 0;
}