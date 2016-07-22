/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include "header.h"

bool isValidBST(TreeNode *root) {
    if(!root) return true;
    TreeNode* pre = NULL;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* t = s.top();
        if(t->left){s.push(t->left);t->left=NULL;}
        else{
            if(pre && t->val<=pre->val) return false;
            pre = t;
            s.pop();
            if(t->right) s.push(t->right);
        }
    }
    return true;
}

//bool isValidBST(TreeNode *root) {
//    TreeNode* curr = root;
//    vector<TreeNode*> s;
//    while(curr){
//        if(curr->left){
//            TreeNode* t = curr->left;
//            while(t->right && t->right != curr) t=t->right;
//            if(t->right == curr){
//                if(!s.empty() && s.back()->val-curr->val>0) return false;
//                s.push_back(curr);
//                t->right = NULL;
//                curr = curr->right;
//            }
//            else{
//                t->right = curr;
//                curr = curr->left;
//            }
//        }
//        else{
//            if(!s.empty() && s.back()->val-curr->val>0) return false;
//            curr = curr->right;
//        }
//    }
//    return true;
//}

int main(){
    TreeNode* root = create_tree("21");
    bool res = isValidBST(root);
    printf("%s\n", res?"true":"false");
    return 0;
}
