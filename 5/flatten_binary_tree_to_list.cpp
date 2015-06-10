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

void flatten(TreeNode* root){
    
}

int main(){
    TreeNode* root = create_tree("12534#6");
    flatten(root);
    TreeNode* curr = &n1;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->right;
    }
    printf("\n");
    return 0;
}
