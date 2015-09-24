/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include "header.h"

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if(n == 0) return res;
}

int main(){
    vector<TreeNode*> res = generateTrees(15);
    for(int i=0;i<(int)res.size();i++){
        pre_order(res[i]);
        printf("\n");
    }
    return 0;
}
