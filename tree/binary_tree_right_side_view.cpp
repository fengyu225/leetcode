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

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> curr;
    curr.push(root);
    queue<TreeNode*> next;
    queue<TreeNode*> q_arr[2] = {curr, next};
    TreeNode* candidate = NULL;
    int x = 0;
    while(!q_arr[x%2].empty()){
        TreeNode* temp = q_arr[x%2].front();
        candidate = temp;
        if(temp->left) q_arr[(x+1)%2].push(temp->left);
        if(temp->right) q_arr[(x+1)%2].push(temp->right);
        q_arr[x%2].pop();
        if(q_arr[x%2].empty()){
            x++;
            res.push_back(candidate->val);
            candidate = NULL;
        }
    }
    return res;
}

int main(){
    //TreeNode* root = create_tree("123#5#4");
    TreeNode* root = create_tree("1234");
    vector<int> res = rightSideView(root);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}