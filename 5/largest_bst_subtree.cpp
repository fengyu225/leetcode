/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

    10
    / \
   5  15
  / \   \ 
 1   8   7

The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Show Hint 
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

#include "header.h"

bool find(TreeNode* root, int& min_val, int& max_val, int& cnt, int& res){
    if(!root){
        cnt = 0;
        return true;
    }
    int l_min = INT_MAX, l_max = INT_MIN, r_min = INT_MAX, r_max = INT_MIN;
    int l_cnt = 0, r_cnt = 0, l_res = 0, r_res = 0;
    bool l = find(root->left, l_min, l_max, l_cnt, l_res);
    bool r = find(root->right, r_min, r_max, r_cnt, r_res);
    bool temp = (root->left == NULL || l_max<=root->val) && (root->right == NULL || root->val<=r_min);
    cnt = l_cnt+r_cnt+1;
    if(temp && l && r){
        min_val = root->left?l_min:root->val;
        max_val = root->right?r_max:root->val;
        res = cnt;
        return true;
    }
    else{
        res = max(l_res, r_res);
        return false;
    }
}

int largestBSTSubtree(TreeNode* root) {
    if(!root) return 0;    
    int min_val = INT_MAX, max_val = INT_MIN;
    int res = 0, cnt = 0;
    find(root, min_val, max_val, cnt, res);
    return res;
}

int main(){
    vector<string> s = {"10","5","15","1","8","#","7"};
    TreeNode* root = create_tree(s);
    cout<<largestBSTSubtree(root)<<endl;
    return 0;
}
