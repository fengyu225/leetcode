#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool is_valid_bst(TreeNode* root, int smallest, int largest){
    if(!root) return true;
    if(root->val<largest && root->val>smallest)
        return 
            is_valid_bst(root->left, smallest, root->val)
            && is_valid_bst(root->right, root->val, largest);
    return false;
}

bool isValidBST(TreeNode *root) {
    return is_valid_bst(root, INT_MIN, INT_MAX);
}

int main(){
    TreeNode n0(10);
    TreeNode n1(5);
    TreeNode n2(15);
    TreeNode n3(6);
    TreeNode n4(20);
    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    bool res = isValidBST(&n0);
    printf("%s\n", res?"true":"false");
    return 0;
}
