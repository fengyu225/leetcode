/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

#include "header.h"

int getHeight(TreeNode* root){
    int res = 0;
    for(;root;res++, root=root->left);
    return res;
}

void countNodes(TreeNode* root, int& res){
    if(!root) return;
    int l_h = getHeight(root->left);
    int r_h = getHeight(root->right);
    res += 1;
    if(l_h == r_h){
        res += (1<<l_h)-1;
        countNodes(root->right, res);
    }
    else{
        res += (1<<r_h)-1;
        countNodes(root->left, res);
    }
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    countNodes(root, res);
    return res;
}

int main(){
    TreeNode* root = create_tree("1234567898989");
//    TreeNode* root = create_tree("1234");
    //vector<string> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    //TreeNode* root = create_tree("123456789");
    //TreeNode* root = create_tree(v);
    cout<<countNodes(root)<<endl;
    return 0;
}