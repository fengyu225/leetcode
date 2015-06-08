/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include "header.h"

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void check(stack<TreeNode*>& s, TreeNode* pre, TreeNode* curr, TreeNode*& left, TreeNode*& right){
    if(pre){
        if(pre->val>curr->val){
            if(!left) left=pre;
            right = curr;
        } 
    }
}

void recoverTree(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* left = NULL, *right = NULL;
    TreeNode* pre = NULL;
    while(!s.empty()){
        TreeNode* t = s.top();
        if(t->left) s.push(t->left);
        else{
            while(!s.empty() && !s.top()->right){
                check(s,pre,s.top(),left,right);
                pre = s.top();
                s.pop();
            }
            if(!s.empty()){
                check(s,pre,s.top(),left,right);
                pre = s.top();
                s.pop();
                s.push(pre->right);
            }
        }
    }
    if(left) swap(left->val, right->val);
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
//    TreeNode n0(2);
//    TreeNode n1(1);
//    n0.right = &n1;
//    recoverTree(&n0);
//    inorder(&n0);
//    cout<<endl;
    TreeNode* root = create_tree("01");
    recoverTree(root);
    inorder(root);
    cout<<endl;
    return 0;
}
