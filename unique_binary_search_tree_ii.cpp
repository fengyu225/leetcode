/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include "header.h"

void generate(int l, int r, vector<TreeNode*>& res){
    if(l>r){
        res.push_back(NULL);
        return;
    }
    for(int i=l; i<=r; i++){
        vector<TreeNode*> left_res;
        vector<TreeNode*> right_res;
        generate(l, i-1, left_res);
        generate(i+1, r, right_res);
        for(int a=0; a<left_res.size(); a++)
            for(int b=0; b<right_res.size(); b++){
                TreeNode* r = new TreeNode(i);
                r->left = left_res[a];
                r->right = right_res[b];
                res.push_back(r);
            }
    }
}

vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> res;
    generate(1,n,res);
    return res;
}

void dfs(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    dfs(root->left);
    dfs(root->right);
}

int main(){
    vector<TreeNode*> res = generateTrees(15);
    for(int i=0;i<res.size();i++){
        dfs(res[i]);
        printf("\n");
    }
    return 0;
}
