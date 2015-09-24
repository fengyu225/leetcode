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

void push_nodes(TreeNode* from, TreeNode* to, vector<int>& res){
    stack<TreeNode*> st;
    TreeNode* temp = from;
    while(temp != to){
        st.push(temp);
        temp = temp->right;
    }
    for(;!st.empty();res.push_back(st.top()->val), st.pop());
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    TreeNode* from = NULL, *to = NULL;
    TreeNode* new_root = new TreeNode(0);
    new_root->left = root;
    TreeNode* curr = new_root;
    while(curr){
        if(curr->left){
            TreeNode* temp = curr->left;
            from = temp;
            while(temp->right && temp->right != curr) temp = temp->right;
            to = temp->right;
            if(temp->right == curr){
                push_nodes(from, to, res);
                temp->right = NULL;
                curr = curr->right;
            }
            else{
                temp->right = curr;
                curr = curr->left;
            }
        }
        else{
            curr = curr->right;
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
