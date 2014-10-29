#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end){
    if(in_start>in_end || post_start > post_end) return NULL;
    TreeNode* root = new TreeNode(postorder[post_end]);
    int i = in_start;
    while(i<=in_end && inorder[i]!=root->val) i++;
    root->left = buildTree(inorder,in_start,i-1,postorder,post_start,i-1-in_start+post_start);
    root->right = buildTree(inorder,i+1,in_end,postorder,i+1-in_end+post_end-1,post_end-1);
    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
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
