/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

#include "header.h"

int getHeight(TreeNode* root){
    int res = 0;
    for(TreeNode* curr = root; curr; curr = curr->left, res++);
    return res;
}

int countNodes(TreeNode* root) {
    TreeNode* curr = root;
    int res = 0;
    while(curr){
        int l_h = getHeight(curr->left);
        int r_h = getHeight(curr->right);
        if(l_h == r_h){
            res += l_h>0?2<<(l_h-1):1;
            curr = curr->right;
        }
        else{
            res += r_h>0?2<<(r_h-1):1;
            curr = curr->left;
        }
    }
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