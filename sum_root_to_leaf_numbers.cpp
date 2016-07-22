/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include "header.h"

void search(TreeNode* root, int& res, int& temp){
    if(!root->left && !root->right){
        temp *= 10;
        temp += root->val;
        res += temp;
        return;
    }
    int l_temp = 10*temp+root->val;
    int r_temp = l_temp;
    if(root->left) search(root->left, res, l_temp);
    if(root->right) search(root->right, res, r_temp);
}

int sumNumbers(TreeNode* root){
    if(!root) return 0;
    int res = 0;
    int temp = 0;
    search(root, res, temp);
    return res;
}

/*

                4
        /               \
        9               0
         \
          1 

*/

int main(){
    TreeNode* root = create_tree("490#1");
    cout<<sumNumbers(root)<<endl;
    return 0;
}
