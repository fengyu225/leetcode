#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recover(TreeNode* root, TreeNode*& last, TreeNode*& first, TreeNode*& second){
    if(!root) return;
    recover(root->left,last,first,second);
    if(last && last->val>root->val){
        if(!first) first = last;
        second = root;
    }
    last = root;
    recover(root->right,last,first,second);
}

void recoverTree(TreeNode* root){
    TreeNode* last = NULL;
    TreeNode* first = NULL, *second = NULL;
    recover(root,last,first,second);
//    cout<<"first: "<<first->val<<" second: "<<second->val<<endl;
    int val = first->val;
    first->val = second->val;
    second->val = val;
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


int main(){
//    TreeNode n0(4);
//    TreeNode n1(3);
//    TreeNode n2(10);
//    TreeNode n3(1);
//    TreeNode n4(6);
//    TreeNode n5(14);
//    TreeNode n6(8);
//    TreeNode n7(7);
//    TreeNode n8(13);
//    n0.left = &n1;
//    n0.right = &n2;
//    n1.left = &n3;
//    n1.right = &n4;
//    n2.right = &n5;
//    n4.left = &n6;
//    n4.right = &n7;
//    n5.left = &n8;
    TreeNode n0(2);
    TreeNode n1(1);
    n0.right = &n1;
    recoverTree(&n0);
    inorder(&n0);
    cout<<endl;
    return 0;
}
