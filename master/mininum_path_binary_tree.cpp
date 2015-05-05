#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
    if(!root)
        return 0;
    int l = INT_MAX;
    int r = INT_MAX;
    if(root->left)
        l = minDepth(root->left);
    if(root->right)
        r = minDepth(root->right);
    if(l == INT_MAX && r==INT_MAX) return 1;
    return 1+(l<r?l:r);
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(1);
    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    printf("%d\n", minDepth(&n1));
    return 0;
}
