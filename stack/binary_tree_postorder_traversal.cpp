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
    TreeNode* curr_level = root;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        if(curr_level == curr){
            if(curr->left || curr->right){
                TreeNode* n = curr->left?curr->left:curr->right;
                st.push(n);
                curr_level = n;
            }
            else{
                res.push_back(curr->val);
                st.pop();
                curr_level = curr;
            }
        }
        else{
            if(curr_level == curr->left && curr->right){
                st.push(curr->right);
                curr_level = curr->right;
            }
            else{
                res.push_back(curr->val);
                st.pop();
                curr_level = curr;
            }
        }
    }
    return res;
}

int main(){
    //TreeNode* root = create_tree("1#23");
    TreeNode* root = create_tree("312");
    vector<int> res = postorderTraversal(root);
    print_vector<int>(res);
    return 0;
}