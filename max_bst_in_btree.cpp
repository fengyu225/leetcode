/*
               ___________________15___________________
              /                                        \ 
  ___________10___________                             20
 /                        \ 
 5                   _____7____
                    /          \
                  __2__       __5
                 /     \     / 
                 0      8    3 
*/

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_bst(TreeNode* root, int& max_nodes, TreeNode*& max_root, int l_bound, int h_bound, TreeNode*& child){
    if(!root){
        max_nodes = 0;
        max_root = NULL;
        child = NULL;
        return 0;
    }
    if(root->val>
}

TreeNode* get_max_bst(TreeNode* root){
    if(!root) return NULL;
    int max_nodes = 0;
    TreeNode* max_root = NULL, *child = NULL;
    get_bst(root,max_nodes,max_root,INT_MIN,INT_MAX,child);
    return max_root;
}

void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct TreeNode n0(15);
    struct TreeNode n1(10);
    struct TreeNode n2(20);
    struct TreeNode n3(5);
    struct TreeNode n4(7);
    struct TreeNode n5(2);
    struct TreeNode n6(5);
    struct TreeNode n7(0);
    struct TreeNode n8(8);
    struct TreeNode n9(3);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n4.left = &n5;
    n4.right = &n6;
    n5.left = &n7;
    n5.right = &n8;
    n6.left = &n9;
    TreeNode* res = get_max_bst(&n0);
    preorder(res);
    cout<<endl;
    return 0;
}
