/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include "header.h"

void check_and_update(TreeNode* prev, TreeNode* curr, TreeNode*& left, TreeNode*& right){
    if(prev && curr && prev->val>curr->val){
        if(!left){
            left=prev;
            right = curr;
        }
        else if(right) right = curr;
    }
}

void recoverTree(TreeNode* root) {
    if(!root) return;
    TreeNode* prev = NULL, *curr = root, *left = NULL, *right = NULL;
    while(curr){
        if(curr->left){
            TreeNode* temp = curr->left;
            while(temp->right && temp->right != curr) temp = temp->right;
            if(temp->right == curr){
                check_and_update(prev,curr,left,right);
                temp->right = NULL;
                prev = curr;
                curr = curr->right;
            }
            else{
                temp->right = curr;
                curr = curr->left;
            }
        }
        else{
            check_and_update(prev,curr,left,right);
            prev = curr;
            curr = curr->right;
        }
    }
    if(left && right){
        int x = left->val;
        left->val = right->val;
        right->val = x;
    }
}

int main(){
    TreeNode* root = create_tree("231");
    recoverTree(root);
    in_order(root);
    cout<<endl;
    return 0;
}
