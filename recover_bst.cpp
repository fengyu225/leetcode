#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode* root){
    TreeNode* pre = NULL;
    TreeNode* curr = root;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    while(curr){
        TreeNode* curr_left = curr->left;
        if(curr_left){
            TreeNode* t = curr_left;
            while(t->right && t->right!=curr)
                t = t->right;
            if(!t->right){
                t->right = curr;
                curr = curr->left;
            }
            else{
                t->right = NULL;
                if(pre){
                    if(pre->val>curr->val){
                        if(!first)
                            first = pre;
                        second = curr;
                    }
                }
                pre = curr;
                curr = curr->right;
            }
        }
        else{
            if(pre){
                if(pre->val>curr->val){
                    if(!first)
                        first = pre;
                    second = curr;
                }
            }
            pre = curr;
            curr = curr->right;
        }
    }
    if(first && second){
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


int main(){
//    TreeNode n0(3);
//    TreeNode n1(6);
//    TreeNode n2(5);
//    TreeNode n3(0);
//    TreeNode n4(2);
//    TreeNode n5(4);
//    TreeNode n6(1);
//    n0.left = &n1;
//    n0.right = &n2;
//    n1.left = &n3;
//    n1.right = &n4;
//    n2.left = &n5;
//    n2.right = &n6;
    TreeNode n0(0);
    TreeNode n1(1);
    n0.left = &n1;
    inorder(&n0);
    printf("\n");
    recoverTree(&n0);
    inorder(&n0);
    printf("\n");
    return 0;
}
