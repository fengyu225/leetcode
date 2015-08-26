/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

#include "header.h"

void search(TreeNode* root, double target, TreeNode*& curr, double& curr_diff){
    double d = abs(target-(double)root->val);
    if(d<curr_diff){
        curr = root;
        curr_diff = d;
    }
    if(root->left && target<root->val) search(root->left, target, curr, curr_diff);
    if(root->right && target>root->val) search(root->right, target, curr, curr_diff);
}

int closestValue(TreeNode* root, double target) {
    TreeNode* curr = root;
    double curr_diff = abs(target-(double)root->val);
    search(root, target, curr, curr_diff);
    return curr->val;
}

int main(){
    vector<string> v = {"5","3","10","1","2","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
    cout<<closestValue(root, 7.8)<<endl;
    return 0;
}