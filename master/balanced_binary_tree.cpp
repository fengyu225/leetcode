#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int traverse(TreeNode* root){
    if(!root)
        return 0;
    int l = traverse(root->left);
    int r = traverse(root->right);
    if(l<0 || r<0 || l-r>1 || r-l>1)
        return -1;
    return l>r?l+1:r+1;
}

bool isBalanced(TreeNode *root) {
    return traverse(root)>=0?true:false;
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(1);
    n1.left = &n2;
//    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    printf("%d\n", isBalanced(&n1));
    return 0;
}
