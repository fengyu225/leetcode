/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "header.h"

/* recursive
void count(TreeNode* root, int& res){
    if(!root) return;
    int l_res = 0, r_res=0;
    count(root->left, l_res);
    count(root->right, r_res);
    res = max(l_res, r_res)+1;
}

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    count(root, res);
    return res;
}
*/

int maxDepth(TreeNode* root) {
    //using morris traversal
    if(!root) return 0;
}

int main(){
    TreeNode* root = create_tree("1#2");
//    string arr[] = {"0","2","4","1","#","3","-1","5","1","#","6","#","8"};
//    vector<string> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
//    root = create_tree(v);
    int res = maxDepth(root);
    printf("%d\n", res);
    return 0;
}
