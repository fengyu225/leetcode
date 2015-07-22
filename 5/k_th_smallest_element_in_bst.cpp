/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

#include "header.h"

int kthSmallest(TreeNode* root, int k) {
    if(!root) return 0;
    stack<TreeNode*> stack;
    stack.push(root);
    int res = 0;
    while(!stack.empty()){
        TreeNode* temp = stack.top();
        if(temp->left) stack.push(temp->left);
        else{
            while(!stack.empty()){
                temp = stack.top();
                k--;
                if(k == 0) return temp->val;
                stack.pop();
                if(temp->right){
                    stack.push(temp->right);
                    break;
                }
            }
            if(stack.empty()) break;
        }
    }
    return res;
}

//int kthSmallest(TreeNode* root, int k) {
//    if(!root) return 0;
//    TreeNode* curr = root;
//    int res = 0;
//    while(curr){
//        if(curr->left){
//            TreeNode* temp = curr->left;
//            while(temp->right && temp->right != curr){
//                temp = temp->right;
//            }
//            if(temp->right == curr){
//                temp->right = NULL;
//                k--;
//                if(k == 0){
//                    res = curr->val;
//                    break;
//                }
//                curr = curr->right;
//            }
//            else{
//                temp->right = curr;
//                curr = curr->left;
//            }
//        } 
//        else{
//            k--;
//            if(k == 0){
//                res = curr->val;
//                break;
//            }
//            curr = curr->right;
//        }
//    }
//    return res;
//}

int main(){
    //TreeNode* root = create_tree("53724681#");
    TreeNode* root = create_tree("1#2");
    cout<<kthSmallest(root, 2)<<endl;
    return 0;
}