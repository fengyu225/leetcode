/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

#include "header.h"

void closestValue(TreeNode* root, double target, int& res){
    if(!root) return;
    double dist = abs((double)res - target);
    double curr_dist = abs((double)root->val - target);
    if(curr_dist<dist) res = root->val;
    if(target<root->val && root->left) closestValue(root->left, target, res);
    if(target>root->val && root->right) closestValue(root->right, target, res);
}

int closestValue(TreeNode* root, double target) {
    if(!root) return 0;
    int res = root->val;
    closestValue(root, target, res);
    return res;
}

int main(){
    vector<string> v = {"5","3","10","1","2","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
    cout<<closestValue(root, 7.8)<<endl;
    return 0;
}