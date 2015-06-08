/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
    1
   / \
  2   2
   \   \
   3    3
Bonus points if you could solve it both recursively and iteratively.
*/

#include "header.h"

bool isSymmetric(TreeNode* root){
    return true;
}

int main(){
    string arr_1[] = {"1","2","2","3","4","4","3"};
    vector<string> v_1(arr_1, arr_1+sizeof(arr_1)/sizeof(arr_1[0]));
    string arr_2[] = {"1","2","2","#","3","#","3"};
    vector<string> v_2(arr_2, arr_2+sizeof(arr_2)/sizeof(arr_2[0]));
    TreeNode* t1 = create_tree(v_1);
    TreeNode* t2 = create_tree(v_2);
    return 0;
}