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

void generate(vector<TreeNode*>& res, int l, int r){
    if(l >= r){
        res.push_back(l == r?new TreeNode(l):NULL);
        return;
    }
    for(int i=l; i<=r; i++){
        vector<TreeNode*> l_res;
        vector<TreeNode*> r_res;
        generate(l_res, l, i-1);
        generate(r_res, i+1, r);
        for(TreeNode* l_c:l_res){
            for(TreeNode* r_c:r_res){
                TreeNode* root = new TreeNode(i);
                root->left = l_c;
                root->right = r_c;
                res.push_back(root);
            }
        }
    }
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0) return vector<TreeNode*>(1, NULL);
    vector<TreeNode*> res;
    generate(res, 1, n);
    return res;
}

int main(){
    vector<TreeNode*> res = generateTrees(15);
    for(int i=0;i<(int)res.size();i++){
        pre_order(res[i]);
        printf("\n");
    }
    return 0;
}
