/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

#include "header.h"

int find_longest_consecutive(TreeNode* root, int& res){
    if(!root) return 0;
    int l = find_longest_consecutive(root->left, res);
    int r = find_longest_consecutive(root->right, res);
    l = root->left && root->val+1 == root->left->val?l:0;
    r = root->right && root->val+1 == root->right->val?r:0;
    int temp = max(l, r)+1;
    res = max(res, temp);
    return temp;
}

int longestConsecutive(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    find_longest_consecutive(root, res);
    return res;
}

int main(){
    //TreeNode* root = create_tree("1#324###5");
    TreeNode* root = create_tree("2#32#1");
    cout<<longestConsecutive(root)<<endl;
    return 0;
}