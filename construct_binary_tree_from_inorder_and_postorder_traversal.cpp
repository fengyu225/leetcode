#include "header.h"

TreeNode* build(vector<int>& inorder, int i_l, int i_r, vector<int>& postorder, int p_l, int p_r){
    if(i_r-i_l != p_r-p_l) return NULL;
    if(i_r < i_l) return NULL;
    int x = postorder[p_r];
    int i=i_l;
    for(;i<=i_r && inorder[i]!=x;i++);
    TreeNode* root = new TreeNode(x);
    root->left = build(inorder, i_l, i-1, postorder, p_l, i-1-i_l+p_l);
    root->right = build(inorder, i+1, i_r, postorder,p_r-i_r+i ,p_r-1);
    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    int i_l=0, i_r=inorder.size()-1, p_l = 0, p_r=inorder.size()-1;
    return build(inorder, i_l, i_r, postorder, p_l, p_r);
}    

void pre_order(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
}
     
int main(){
    int in_arr[] = {1, 0, 3, 2, 4};
    int post_arr[] = {1, 3, 4, 2, 0};
    vector<int> in(in_arr, in_arr+sizeof(in_arr)/sizeof(in_arr[0]));
    vector<int> post(post_arr, post_arr+sizeof(post_arr)/sizeof(post_arr[0]));
    TreeNode* root = buildTree(in,post);
    pre_order(root);
    printf("\n");
    return 0;
}
