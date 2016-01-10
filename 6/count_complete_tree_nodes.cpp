/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

#include "header.h"

int countNodes(TreeNode* root) {

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