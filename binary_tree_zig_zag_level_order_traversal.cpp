/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

#include "header.h"

vector<vector<int> > zigzagLevelOrder(TreeNode* root){
    vector<vector<int> > res;
    if(!root) return res;
    bool left_to_right = true;
    stack<TreeNode*> curr_level;
    stack<TreeNode*> next_level;
    curr_level.push(root);
    stack<TreeNode*> arr[2] = {curr_level, next_level};
    int x = 0;
    vector<int> v;
    while(!arr[x%2].empty()){
        TreeNode* t = arr[x%2].top();
        v.push_back(t->val);
        arr[x%2].pop();
        if(left_to_right){
            if(t->left) arr[(x+1)%2].push(t->left);
            if(t->right) arr[(x+1)%2].push(t->right);
        }
        else{
            if(t->right) arr[(x+1)%2].push(t->right);
            if(t->left) arr[(x+1)%2].push(t->left);
        }
        if(arr[x%2].empty()){
            x++;
            res.push_back(v);
            v.clear();
            left_to_right = !left_to_right;
        }
    }
    return res;
}

int main(){
    string arr[] = {"3","9","20","#","#","15","7"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = create_tree(v); 
    vector<vector<int> > res = zigzagLevelOrder(root);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
