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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(!root) return res;
    stack<TreeNode*> arr[2];
    arr[0].push(root);
    int x = 0;
    bool l2r = true;
    vector<int> temp;
    while(!arr[x%2].empty()){
        TreeNode* curr = arr[x%2].top();
        if(l2r){
            if(curr->left) arr[(x+1)%2].push(curr->left);
            if(curr->right) arr[(x+1)%2].push(curr->right);
        } 
        else{
            if(curr->right) arr[(x+1)%2].push(curr->right);
            if(curr->left) arr[(x+1)%2].push(curr->left);
        }
        temp.push_back(curr->val);
        arr[x%2].pop();
        if(arr[x%2].empty()){
            x++;
            l2r = !l2r;
            res.push_back(temp);
            temp.clear();
        }
    }
    return res;
}

int main(){
    TreeNode* root = create_tree(vector<string>({"3","9","20","#","#","15","7"}));
    vector<vector<int> > res = zigzagLevelOrder(root);
    for(auto v:res){
        for(int i:v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}