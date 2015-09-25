/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "header.h"

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* temp = curr->left;
            while(temp->right && temp->right != curr) temp = temp->right;
            if(temp->right == curr){
                temp->right = NULL;
                curr = curr->right;
//                res.push_back(curr->val);
            }
            else{
                temp->right = curr;
                res.push_back(curr->val);
                curr = curr->left;
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
    TreeNode* root = create_tree("1#23");
    vector<int> res = preorderTraversal(root);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
