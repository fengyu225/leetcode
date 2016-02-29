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
    stack<TreeNode*> st[2];
    st[0].push(root);
    int curr = 0;
    bool left_2_right = true;
    vector<int> temp;
    while(!st[curr%2].empty()){
        TreeNode* t = st[curr%2].top();
        st[curr%2].pop();
        temp.push_back(t->val);
        if(left_2_right){
            if(t->left) st[(curr+1)%2].push(t->left);
            if(t->right) st[(curr+1)%2].push(t->right);
        }
        else{
            if(t->right) st[(curr+1)%2].push(t->right);
            if(t->left) st[(curr+1)%2].push(t->left);
        }
        if(st[curr%2].empty()){
            curr++;
            res.push_back(temp);
            temp.clear();
            left_2_right = !left_2_right;
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
