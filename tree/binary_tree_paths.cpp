/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
*/

#include "header.h"

void binaryTreePaths(TreeNode* root, vector<string>& res, string& temp){
    if(!root->left && !root->right){
        string x = temp;
        temp += to_string(root->val);
        res.push_back(temp);
        temp = x;
        return;
    }
    string x = temp;
    temp += to_string(root->val)+"->";
    if(root->left) binaryTreePaths(root->left, res, temp);
    if(root->right) binaryTreePaths(root->right, res, temp);
    temp = x;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(!root) return res;
    string temp = "";
    binaryTreePaths(root, res, temp);
    return res;
}

int main(){
    TreeNode* root = create_tree("123#5");
    vector<string> res = binaryTreePaths(root);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}