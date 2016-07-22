/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include "header.h"

void search(TreeNode* root, int sum, vector<int>& temp, vector<vector<int> >& res){
    if(!root) return;
    if(!root->left && !root->right){
        if(root->val == sum){
            temp.push_back(root->val);
            res.push_back(temp);
        }
        return;
    }
    temp.push_back(root->val);
    vector<int> t = temp;
    if(root->left) search(root->left, sum-root->val, temp, res);
    if(root->right) search(root->right, sum-root->val, t, res);
    temp.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum){
    vector<vector<int> > res;
    if(!root) return res;
    vector<int> temp;
    search(root, sum, temp, res);
    return res;
}

int main(){
    string arr[] = {"5","4","8","11","#","13","4","7","2","#","#","5","1"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = create_tree(v);
    vector<vector<int> > r = pathSum(root, 22);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
