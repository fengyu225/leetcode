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

void search(TreeNode* root, string& temp, vector<string>& res){
    if(!root->left && !root->right){
        string x = temp;
        temp += to_string(root->val);
        res.push_back(temp);
        temp = x;
        return;
    }
    string x = temp;
    temp += to_string(root->val)+"->";
    if(root->left) search(root->left, temp, res);
    if(root->right) search(root->right, temp, res);
    temp = x;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(!root) return res;
    string temp = "";
    search(root, temp, res);
    return res;
}

int main(){
    TreeNode* root = create_tree("123#5");
    vector<string> res = binaryTreePaths(root);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}