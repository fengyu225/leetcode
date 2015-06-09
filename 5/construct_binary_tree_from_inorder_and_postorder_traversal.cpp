#include "header.h"

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
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
