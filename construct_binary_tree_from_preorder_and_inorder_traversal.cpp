#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& preorder, int pre_start, int pre_end){
    if(pre_end<pre_start || in_end<in_start) return NULL;
    TreeNode* r = new TreeNode(preorder[pre_start]);
    int i = in_start;
    while(i<=in_end)
        if(inorder[i] != preorder[pre_start])
            i++;
        else
            break;
    r->left = buildTree(inorder,in_start,i-1,preorder,pre_start+1,i-1-in_start+pre_start+1);
    r->right = buildTree(inorder,i+1,in_end,preorder,i+1-in_end+pre_end,pre_end);
    return r;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
}    

void post_order(TreeNode* root){
    if(!root) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->val);
}
     
int main(){
    int in_arr[] = {1, 0, 3, 2, 4};
    int pre_arr[] = {0, 1, 2, 3, 4};
    vector<int> in(in_arr, in_arr+sizeof(in_arr)/sizeof(in_arr[0]));
    vector<int> pre(pre_arr, pre_arr+sizeof(pre_arr)/sizeof(pre_arr[0]));
    TreeNode* root = buildTree(in,pre);
    post_order(root);
    printf("\n");
    return 0;
}
