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
    queue<TreeNode*> qs[2];
    int curr;
    qs[0].push(root);
    while(!qs[curr%2].empty()){
        TreeNode* t = qs[curr%2].front();
        qs[curr%2].pop();
        if(t->left) qs[(curr+1)%2].push(t->left);
        if(t->right) qs[(curr+1)%2].push(t->right);
        if(qs[curr%2].empty()){
            res.push_back(t->val);
            curr++;
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