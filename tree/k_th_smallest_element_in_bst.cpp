/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

#include "header.h"

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    int curr = 0;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();
        if(temp->left) st.push(temp->left);
        else{
            while(!st.empty()){
                TreeNode* temp = st.top();
                st.pop();
                curr++;
                if(curr==k) return temp->val;
                if(temp->right){
                    st.push(temp->right);
                    break;
                }
            }
        }
    }
}

int main(){
    //TreeNode* root = create_tree("53724681#");
    TreeNode* root = create_tree("1#2");
    cout<<kthSmallest(root, 2)<<endl;
    return 0;
}