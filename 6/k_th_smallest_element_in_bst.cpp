/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

#include "header.h"

void search(TreeNode* root, int& k, TreeNode*& res){
    if(!root || res) return;
    search(root->left, k, res);
    k--;
    if(k == 0){
        res = root;
        return;
    }
    search(root->right, k, res);
}

int kthSmallest(TreeNode* root, int k) {
    if(!root) return 0;
    TreeNode* res = NULL;
    search(root, k, res);
    return res->val;
}

int main(){
    //TreeNode* root = create_tree("53724681#");
    //TreeNode* root = create_tree("1#2");
    TreeNode* root = create_tree("21");
    cout<<kthSmallest(root, 1)<<endl;
    return 0;
}