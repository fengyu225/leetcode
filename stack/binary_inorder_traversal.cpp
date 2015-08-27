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

//vector<int> inorderTraversal(TreeNode* root) {
//    // Morris traversal
//    vector<int> res;
//    if(!root) return res;
//    TreeNode* curr = root;
//    while(curr){
//        if(curr->left){
//            TreeNode* temp = curr->left;
//            while(temp->right && temp->right != curr) temp = temp->right;
//            if(!temp->right){
//                temp->right = curr;
//                curr = curr->left;
//            }
//            else{
//                temp->right = NULL;
//                res.push_back(curr->val);
//                curr = curr->right;
//            }
//        }
//        else{
//            res.push_back(curr->val);
//            curr = curr->right;
//        }
//    }
//    return res;
//}

vector<int> inorderTraversal(TreeNode* root) {
    //using stack
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    st.push(curr);
    while(!st.empty()){
        TreeNode* temp = st.top();
        if(temp->left) st.push(temp->left);
        else{
            while(!st.empty() && st.top()->right == NULL){
                res.push_back(st.top()->val);
                st.pop();
            }
            if(!st.empty()){
                temp = st.top();
                res.push_back(temp->val);
                st.pop();
                st.push(temp->right);
            }
        }
    }
    return res;
}

int main(){
    TreeNode* root = create_tree("1#23");
    vector<int> res = inorderTraversal(root);
    for(int c:res) cout<<c<<" ";
    cout<<endl;
    return 0;
}