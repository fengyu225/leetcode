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
    //using stack
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
            if(st.empty()) continue;
            TreeNode* x = st.top();
            st.pop();
            st.push(x->right);
            res.push_back(x->val);
        }
    }
    return res;
}

//vector<int> inorderTraversal(TreeNode *root) {
//     // morris traversal
//    vector<int> res;
//    if(!root) return res;
//    TreeNode* curr = root;
//    while(curr){
//        if(curr->left){
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
//        else{
//            res.push_back(curr->val);
//            curr = curr->right;
//        }
//    }
//    return res;
//}

int main(){
    //TreeNode* root = create_tree("12");
    TreeNode* root = create_tree("1");
    vector<int> res = inorderTraversal(root);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
