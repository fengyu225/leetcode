/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include "header.h"

void update(TreeNode* prev, TreeNode* curr, TreeNode*& res_l, TreeNode*& res_r){
    if(!prev || prev->val < curr->val) return;
    if(!res_l){
        res_l = prev;
        res_r = curr;
    }
    else res_r = curr;
}

void recoverTree(TreeNode* root) {
    TreeNode* curr = root, *prev = NULL, *res_l = NULL, *res_r = NULL;
    while(curr){
        TreeNode* curr_l = curr->left;
        if(curr_l){
            while(curr_l->right && curr_l->right != curr) curr_l = curr_l->right;
            if(curr_l->right){
                update(curr_l, curr, res_l, res_r);
                prev = curr;
                curr = curr->right;
                curr_l->right = NULL;
            }
            else{
                curr_l->right = curr;
                curr = curr->left;
            }
        }
        else{
            update(prev, curr, res_l, res_r);
            prev = curr;
            curr = curr->right;
        }
    }
    if(res_l && res_r) swap(res_l->val, res_r->val);
}

int main(){
    vector<string> trees = {"0", "1"};
    TreeNode* root = create_tree(trees);
    recoverTree(root);
    in_order(root);
    cout<<endl;
    return 0;
}
