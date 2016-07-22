/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

#include "header.h"

void flatten(TreeNode* root, TreeNode*& head, TreeNode*& tail){
    if(!root){
        head = tail = NULL;
        return;
    }
    TreeNode* l_head = NULL, *l_tail=NULL, *r_head=NULL, *r_tail=NULL;
    flatten(root->left, l_head, l_tail);
    flatten(root->right, r_head, r_tail);
    root->left = NULL;
    root->right = l_head?l_head:r_head;
    if(l_head) l_tail->right=r_head;
    head=root;
    tail=r_tail?r_tail:l_tail?l_tail:head;
    tail->right = NULL;
}

void flatten(TreeNode* root){
    TreeNode* head = NULL, *tail=NULL;
    flatten(root, head, tail);
}

int main(){
    TreeNode* root = create_tree("12534#6");
    flatten(root);
    TreeNode* curr = root;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->right;
    }
    printf("\n");
    return 0;
}
