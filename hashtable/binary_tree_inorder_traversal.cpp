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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        if(temp->left) st.push(temp->left);
        else{
            while(!st.empty() && st.top()->right == NULL){
                res.push_back(st.top()->val);
                st.pop();
            }
            if(!st.empty()){
                res.push_back(st.top()->val);
                TreeNode* x = st.top()->right;
                st.pop();
                st.push(x);
            }
        }
    }
    return res;
}

//vector<int> inorderTraversal(TreeNode* root) {
//    //Morris traversal
//    vector<int> res;
//    if(!root) return res;
//    TreeNode* curr = root;
//    while(curr){
//        if(!curr->left){
//            res.push_back(curr->val);
//            curr = curr->right;
//        }
//        else{
//            TreeNode* temp = curr->left;
//            while(temp->right && temp->right != curr) temp = temp->right;
//            if(temp->right){
//                temp->right = NULL;
//                res.push_back(curr->val);
//                curr = curr->right;
//            }
//            else{
//                temp->right = curr;
//                curr = curr->left;
//            }
//        }
//    }
//    return res;
//}

int main(){
    //TreeNode* root = create_tree("12");
    TreeNode* root = create_tree("1#23");
    vector<int> res = inorderTraversal(root);
    print_vector<int>(res);
    return 0;
}
