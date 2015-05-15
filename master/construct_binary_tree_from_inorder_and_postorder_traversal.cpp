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

TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end){
    if(post_end<post_start || in_end<in_start) return NULL;
    TreeNode* r = new TreeNode(postorder[post_end]);
    int i = in_start;
    while(i<=in_end)
        if(inorder[i] != postorder[post_end])
            i++;
        else
            break;
    r->left = buildTree(inorder,in_start,i-1,postorder,post_start,i-1-in_start+post_start);
    r->right = buildTree(inorder,i+1,in_end,postorder,i+1-in_end+post_end-1,post_end-1);
    return r;
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