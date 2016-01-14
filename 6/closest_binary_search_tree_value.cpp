/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

#include "header.h"

int closestValue(TreeNode* root, double target) {

}

int main(){
    vector<string> v = {"5","3","10","1","2","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
    cout<<closestValue(root, 7.8)<<endl;
    return 0;
}