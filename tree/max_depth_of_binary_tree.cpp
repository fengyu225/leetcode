/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "header.h"

//void search(TreeNode* root, int& res, int curr){
//    if(!root->left && !root->right){
//        res = max(res, curr+1);
//        return;
//    }
//    if(root->left) search(root->left, res, curr+1);
//    if(root->right) search(root->right, res, curr+1);
//}
//
//int maxDepth(TreeNode* root) {
//    if(!root) return 0;
//    int res = 0;
//    search(root, res, 0);
//    return res;
//}

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int res = 0;
    queue<TreeNode*> curr;
    queue<TreeNode*> next;
    curr.push(root);
    queue<TreeNode*> arr[2] = {curr, next};
    int x = 0;
    while(!arr[x%2].empty()){
        TreeNode* temp = arr[x%2].front();
        if(temp->left) arr[(x+1)%2].push(temp->left);
        if(temp->right) arr[(x+1)%2].push(temp->right);
        arr[x%2].pop();
        if(arr[x%2].empty()){
            x++;
            res = max(res, x);
        }
    }
    return res;
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
