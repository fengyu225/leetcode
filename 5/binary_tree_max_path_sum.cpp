/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
*/

#include "header.h"

void search(TreeNode* root, int& res, int& m){
    if(!root->left && !root->right){
        res=m=root->val;
        return;
    }
    int l_m, r_m, l_res, r_res;
    l_m=r_m=l_res=r_res=INT_MIN;
    if(root->left) search(root->left, l_res, l_m);
    if(root->right) search(root->right, r_res, r_m);
    int x = max(l_m,r_m);
    m = max(x,x+root->val);
    m = max(m, root->val);
    int child_res=max(l_res,r_res);
    int res_with_curr = max(max(l_m, r_m),(l_m==INT_MIN||r_m==INT_MIN?INT_MIN:l_m+r_m))+root->val;
    res_with_curr = max(res_with_curr,root->val);
    res = max(child_res,res_with_curr);
}

int maxPathSum(TreeNode* root){
    if(!root) return 0;
    int res = 0, m=0;
    search(root, res, m);
    return res;
}

int main(){
    //string arr[] = {"-1","5","#","4","#","#","2","-4","#"};
    string arr[] = {"2","-1"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = create_tree(v);
    cout<<maxPathSum(root)<<endl;
    return 0;
}
