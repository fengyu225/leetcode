/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

#include "header.h"

vector<int> closestKValues(TreeNode* root, double target, int k) {

}

int main(){
    //vector<string> v = {"5","3","10","1","4","7","11","#","#","#","#","6","#","#","12"};
    //TreeNode* root = create_tree(v);
    TreeNode* root = create_tree("1");
    vector<int> res = closestKValues(root, 0.0, 1);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}