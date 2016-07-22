/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7


return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

#include "header.h"

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root) return res;
    queue<TreeNode*> qs[2];
    qs[0].push(root);
    int curr = 0;
    vector<int> temp;
    while(!qs[curr%2].empty()){
        TreeNode* t = qs[curr%2].front();
        qs[curr%2].pop();
        temp.push_back(t->val);
        if(t->left) qs[(curr+1)%2].push(t->left);
        if(t->right) qs[(curr+1)%2].push(t->right);
        if(qs[curr%2].empty()){
            curr++;
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main(){
    vector<string> arr = {"3","9","20","#","#","15","7"};
    TreeNode* root = create_tree(arr);
    vector<vector<int> > res = levelOrder(root);
    for(auto i:res) print_vector<int>(i);
    return 0;
}