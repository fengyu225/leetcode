/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/

#include "header.h"

void init_small(TreeNode* root, stack<TreeNode*>& small, int target){
    //largest smaller than target
    TreeNode* curr = root;
    while(curr){
        if(curr->val<=target){
            small.push(curr);
            curr = curr->right;
        }
        else curr = curr->left;
    }
}

void init_large(TreeNode* root, stack<TreeNode*>& large, int target){
    //smallest larger than target
    TreeNode* curr = root;
    while(curr){
        if(curr->val>target){
            large.push(curr);
            curr = curr->left;
        }
        else curr = curr->right;
    }
}

void find_next_small(stack<TreeNode*>& small){
    if(small.empty()) return;
    TreeNode* curr = small.top()->left;
    small.pop();
    while(curr){
        small.push(curr);
        curr = curr->right;
    }
}

void find_next_large(stack<TreeNode*>& large){
    if(large.empty()) return;
    TreeNode* curr = large.top()->right;
    large.pop();
    while(curr){
        large.push(curr);
        curr = curr->left;
    }
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    stack<TreeNode*> small, large;
    vector<int> res;
    if(!root) return res;
    init_small(root, small, target);
    init_large(root, large, target);
    for(int i=0; i<k; i++){
        TreeNode* n;
        if(small.empty() || !large.empty() && target-(double)small.top()->val>(double)large.top()->val-target){
            n = large.top();
            find_next_large(large);
            res.push_back(n->val);
        }
        else{
            n = small.top();
            find_next_small(small);
            res.push_back(n->val);
        }
    }
    return res;
}

int main(){
    vector<string> v = {"5","3","10","1","4","7","11","#","#","#","#","6","#","#","12"};
    TreeNode* root = create_tree(v);
    vector<int> res = closestKValues(root, 7.7, 5);
    //TreeNode* root = create_tree("1");
    //vector<int> res = closestKValues(root, 0.0, 1);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}