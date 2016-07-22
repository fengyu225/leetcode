/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "header.h"

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* curr_level = root;
    while(!s.empty()){
        TreeNode* temp = s.top();
        if(curr_level == temp){
            if(temp->left || temp->right){
                TreeNode* n = temp->left?temp->left:temp->right;
                s.push(n);
                curr_level = n;
            }
            else{
                res.push_back(temp->val);
                s.pop();
                curr_level = temp;
            }
        }
        else{
            if(curr_level == temp->left && temp->right){
                s.push(temp->right);
                curr_level = temp->right;
            }
            else{
                res.push_back(temp->val);
                s.pop();
                curr_level = temp;
            }
        }
    }
    return res;
}

int main(){
    TreeNode* root = create_tree("1#23");
    vector<int> res = postorderTraversal(root);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
