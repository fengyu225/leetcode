#include "header.h"

TreeNode* build(vector<int>& preorder, int p_l, int p_r, vector<int>& inorder, int i_l, int i_r){
    if(p_r<p_l) return NULL;
    TreeNode* root = new TreeNode(preorder[p_l]);
    int i = i_l;
    for(;i<=i_r && inorder[i]!=preorder[p_l];i++);
    root->left = build(preorder, p_l+1,i-i_l+p_l , inorder, i_l, i-1);
    root->right = build(preorder,i+1-i_r+p_r ,p_r,inorder,i+1,i_r);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    int p_l = 0, p_r=preorder.size()-1, i_l = 0, i_r=inorder.size()-1;
    return build(preorder, p_l, p_r, inorder, i_l, i_r);
}

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}
     
int main(){
    int in_arr[] = {1, 0, 3, 2, 4};
    int pre_arr[] = {0, 1, 2, 3, 4};
    vector<int> in(in_arr, in_arr+sizeof(in_arr)/sizeof(in_arr[0]));
    vector<int> pre(pre_arr, pre_arr+sizeof(pre_arr)/sizeof(pre_arr[0]));
    TreeNode* root = buildTree(in,pre);
    pre_order(root);
    printf("\n");
    return 0;
}
