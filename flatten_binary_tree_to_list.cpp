#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* convert(TreeNode* root){
    if(!root) return NULL;
    TreeNode* l_tail = convert(root->left);
    TreeNode* r_tail = convert(root->right);
    TreeNode* l_child = root->left;
    TreeNode* r_child = root->right;
    root->right = root->left?root->left:root->right;
    root->left = NULL;
    if(l_tail)
        l_tail->right = r_child;
    TreeNode* tail = r_tail?r_tail:l_tail?l_tail:root;
    tail->right = NULL;
    return tail;
}

void flatten(TreeNode* root){
    if(!root) return;
    convert(root);
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    n1.left = &n2;
    TreeNode n3(3);
    n1.right = &n3;
//    TreeNode n4(4);
//    TreeNode n5(5);
//    TreeNode n6(6);
//    n1.left = &n2;
//    n1.right = &n5;
//    n2.left = &n3;
//    n2.right = &n4;
//    n5.right = &n6;
    flatten(&n1);
    TreeNode* curr = &n1;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->right;
    }
    printf("\n");
    return 0;
}
