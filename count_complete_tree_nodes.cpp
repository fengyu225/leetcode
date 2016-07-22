/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

#include "header.h"

int getHeight(TreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->left;
    }
    return res;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int res = 1;
    TreeNode* curr = root;
    int height = getHeight(root);
    while(--height){
        res <<= 1;
        int r_height = getHeight(curr->right);
        if(height == r_height){
            res |= 1;
            curr = curr->right;
        }
        else curr=curr->left;
    }
    return res;
}

//int countNodes(TreeNode* root) {
//    //iterative
//    if(!root) return 0;
//    if(!root->left && !root->right) return 1;
//    int leaves = 0, level=1;
//    TreeNode* curr = root;
//    while(curr->left){
//        int l_h = getHeight(curr->left);
//        int r_h = getHeight(curr->right);
//        level = max(level, l_h+1);
//        if(!curr->right){
//            leaves++;
//            break;
//        }
//        if(l_h == r_h){
//            leaves += (1<<(l_h-1));
//            if(l_h == 1) leaves++;
//            curr = curr->right;
//        }
//        else curr=curr->left;
//    }
//    return (1<<(level-1))-1+leaves;
//}

//int getLeftHeight(TreeNode* root){
//    int res = 0;
//    while(root){
//        res++;
//        root = root->left;
//    }
//    return res;
//}
//
//int countNodes(TreeNode* root) {
//    if(!root) return 0;
//    int l_h = getLeftHeight(root->left);
//    int r_h = getLeftHeight(root->right);
//    if(l_h == r_h) return (1<<l_h)+countNodes(root->right);
//    if(l_h>r_h) return (1<<r_h)+countNodes(root->left);
//}

int main(){
    TreeNode* root = create_tree("1234567898989");
//    TreeNode* root = create_tree("1234");
    //vector<string> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    //TreeNode* root = create_tree("123456789");
    //TreeNode* root = create_tree(v);
    cout<<countNodes(root)<<endl;
    return 0;
}