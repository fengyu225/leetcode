/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include "header.h"

TreeNode* build(vector<int>& nums, int l, int r){
    if(l>r) return NULL;
    int m = (l+r+1)/2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left=build(nums, l, m-1);
    root->right = build(nums, m+1, r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    return build(nums, 0, nums.size()-1);
}

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}

int main(){
    //int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int arr[] = {1,3};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = sortedArrayToBST(num);
    pre_order(root);
    printf("\n");
    return 0;
}
