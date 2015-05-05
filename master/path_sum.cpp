#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum){
    if(!root)
        return false;
    if(!root->left && !root->right)
        return root->val == sum;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    n1.left = &n2;
    //n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n5.right = &n6;
    bool r = hasPathSum(&n1, 1);
    printf("%s\n", r?"true":"false");
    return 0;
}
