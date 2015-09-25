/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.

*/

#include "header.h"

void search(TreeNode* root, int& path_max, int& res){
    if(!root->left && !root->right){
        path_max = root->val;
        res = root->val;
        return;
    }
    int l_path_max = INT_MIN, r_path_max = INT_MIN, l_res = INT_MIN, r_res=INT_MIN;
    path_max = res = root->val;
    if(root->left){
        search(root->left, l_path_max, l_res);
        path_max = max(path_max, l_path_max+root->val);
        res = max(res, max(l_res, l_path_max+root->val));
    }
    if(root->right){
        search(root->right, r_path_max, r_res);
        path_max = max(path_max, r_path_max+root->val);
        res = max(res, max(r_res, r_path_max+root->val));
    }
    if(root->left && root->right){
        res = max(res, l_path_max+r_path_max+root->val);
    }
}

int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    int path_max=0, res = 0;
    search(root, path_max, res);
    return res;
}

int main(){
//    string arr[] = {"-1","5","#","4","#","#","2","-4","#"};
    //string arr[] = {"2","-1"};
    //string arr[] = {"1","2", "3"};
    string arr[] = {"2", "-1"};
    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    TreeNode* root = create_tree(v);
    cout<<maxPathSum(root)<<endl;
    return 0;
}
