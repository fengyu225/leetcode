/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "header.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        int res = st.top()->val;
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right){
            TreeNode* temp = curr->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
        }
        return res;
    }
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    TreeNode* root = create_tree("63715#9##4#8#");
    BSTIterator i = BSTIterator(root);
    while(i.hasNext()) cout<<i.next();
    return 0;
}