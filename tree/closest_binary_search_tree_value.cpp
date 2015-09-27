/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

#include "header.h"

int closestValue(TreeNode* root, double target) {
    TreeNode* curr = root, *candidate = root;
    while(curr){
        if(target == curr->val) return curr->val;
        if(fabs((double)candidate->val - target)>fabs((double)curr->val - target))
            candidate = curr;
        else if(target>curr->val) curr = curr->right;
        else curr = curr->left;
    }
    return candidate->val;
}

int main(){
    vector<string> v = {"5","3","10","1","2","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
    cout<<closestValue(root, 7.8)<<endl;
    return 0;
}