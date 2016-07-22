/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/

#include "header.h"

vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> curr_q;
    curr_q.push(root);
    queue<TreeNode*> next_q;
    queue<TreeNode*> q_arr[2] = {curr_q, next_q};
    int x = 0;
    while(!q_arr[x%2].empty()){
        TreeNode* temp = q_arr[x%2].front();
        if(temp->left) q_arr[(x+1)%2].push(temp->left);
        if(temp->right) q_arr[(x+1)%2].push(temp->right);
        q_arr[x%2].pop();
        if(q_arr[x%2].empty()){
            x++;
            res.push_back(temp->val);
        }
    }
    return res;
}

int main(){
    TreeNode* root = create_tree("123#5#4");
    vector<int> res = rightSideView(root);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}