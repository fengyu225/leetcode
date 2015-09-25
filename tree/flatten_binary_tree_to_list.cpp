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

void addToRes(TreeNode*& res, TreeNode*& res_tail, TreeNode* new_res, TreeNode* new_res_tail){
    if(!res){
        res = new_res;
        res_tail = new_res_tail;
    }
    else{
        res_tail->right = new_res;
        res_tail = new_res_tail?new_res_tail:res_tail;
    }
}

void flatten(TreeNode* root, TreeNode*& res, TreeNode*& res_tail){
    if(!root) return;
    cout<<root->val<<endl;
    res = res_tail = root;
    TreeNode* left = root->left, *right = root->right;
    root->left = NULL;
    root->right = NULL;
    TreeNode* temp = NULL, *temp_tail = NULL;
    flatten(left, temp, temp_tail);
    addToRes(res, res_tail, temp, temp_tail);
    temp = temp_tail = NULL;
    flatten(right, temp, temp_tail);
    addToRes(res, res_tail, temp, temp_tail);
}

void flatten(TreeNode* root) {
    if(!root) return;
    TreeNode* res = NULL, *res_tail = NULL;
    flatten(root, res, res_tail);
    root = res;
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
