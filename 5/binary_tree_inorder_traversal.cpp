/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "header.h"

vector<int> inorderTraversal(TreeNode *root) {
    // morris traversal
    vector<int> res;
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* t = curr->left;
            while(t->right && t->right != curr) t=t->right;
            if(t->right == curr){
                t->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                t->right = curr;
                curr=curr->left;
            }
        }
        else{
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    return res;
}

int main(){
    TreeNode* root = create_tree("12");
    vector<int> res = inorderTraversal(root);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
