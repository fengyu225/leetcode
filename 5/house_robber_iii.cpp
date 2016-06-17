/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

#include "header.h"

void rob(TreeNode* root, int& a, int& b){
    //a: max money if rob root
    //b: max money if doesn't rob root
    if(!root){
        a = b = 0;
        return;
    }
    int l_a = 0, l_b = 0;
    int r_a = 0, r_b = 0;
    rob(root->left, l_a, l_b);
    rob(root->right, r_a, r_b);
    a = l_b+r_b+root->val;
    b = l_a+r_a;
}

int rob(TreeNode* root) {
    if(!root) return 0;
    int a = 0, b = 0;
    rob(root, a, b);
    return max(a,b);
}

int main(){
    //vector<string> tree = {"3", "2", "3", "#", "3", "#", "1"};
    vector<string> tree = {"3", "4", "5", "1", "3", "#", "1"};
    TreeNode* root = create_tree(tree);
    cout<<rob(root)<<endl;
    return 0;
}
