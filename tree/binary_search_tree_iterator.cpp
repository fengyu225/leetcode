/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "header.h"

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        for(;root->left;st.push(root->left), root = root->left);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* res = st.top();
        st.pop();
        if(res->right){
            st.push(res->right);
            TreeNode* temp = res->right;
            for(;temp->left;st.push(temp->left), temp = temp->left);
        }
        return res->val;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main(){
    TreeNode* root = create_tree("3150246");
    BSTIterator* i = new BSTIterator(root);
    while(i->hasNext()) cout<<i->next()<<" ";
    cout<<endl;
    return 0;    
}